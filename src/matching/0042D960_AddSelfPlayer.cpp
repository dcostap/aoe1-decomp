// TCommunications_Handler::AddSelfPlayer (0042D960)
// PDB source: Com_hand.cpp:5717-5759
// Size: 230 bytes
// EXACT MATCH (0.0000%, validated 2026-08-03)

// Attempt log:
// - Probe 1 (DPNAME struct + DPVT abstract class + void return): 208 bytes
//   Issues: void return type (no eax set), wrong vtable dispatch (ecx=this not stack)
// - Probe 2 (int return + manual vtable dispatch): 224 bytes (6 short)
//   Major progress! Fixed return value and COM __stdcall vtable dispatch
//   Remaining: missing xor ecx,ecx (2 bytes), lea [esi+1179h] (6 bytes),
//   temp stores (6 bytes) — all VC5 scheduling choices
// - Probe 3 (added dwFlags=0x10 + scope-based zero init): 224 bytes
//   Schedule unchanged; compiler still uses mov [esp+N],0 instead of xor+mov
// - Probe 4 (int[] array instead of struct + direct derefs): 224 bytes
//   Same result
//
// - Probe 5 (2026-08-03, subagent-ebbcf55a baseline): real class layout + DPNAME.
//   Key fixes over parked state:
//   * names[2] = &MyFriendlyName (this+0x10F8), names[3] = &MyFormalName
//     (this+0x1179) — the parked source only had names[3] = &MyFriendlyName
//     and missed the +0x1179 lpszLongName store entirely (missing 6-byte
//     lea edx,[esi+1179h]).
//   * real field offsets: Err at +0x14E0 (parked had +0x1440), ProgramState
//     via COMMPLAYEROPTIONS at +0x1550+8 (parked had +0x14BC).
//   * DPNAME zero-init via `= {0}` aggregate (parked used per-field int
//     stores which emitted mov [esp+N],0 immediates instead of xor ecx,ecx
//     + register stores).
//   * MyFriendlyName/MyFormalName char[0x81] arrays at +0x10F8/+0x1179 per
//     matched SetMyPlayerName (0042D3E0).
//   Result: size exact 230/230, but VC5 dead-store-eliminated the dwSize=0
//   store of the `= {0}` initializer (missing mov [esp+8],ecx) and shifted
//   the zero-store order — 174-byte diff, first mismatch +001F.
// - Probe 6 (memset): switched to memset(&dpid, 0, sizeof(dpid)); the inlined
//   memset expansion keeps ALL FOUR zero stores (dwSize=0 included), matching
//   sibling SendPlayerName (00426D50) whose best source also used memset.
//   Result: MATCH 0.0000% (230/230 bytes, 100% shape, 8/8 calls aligned).
//   Field assignment order lpszShortName, dwSize, lpszLongName mirrors the
//   original's value-store order (+8, +0, +0xC).

// LESSON: for address-escaped small structs, memset() keeps VC5's per-field
// zero stores that an `= {0}` initializer would dead-store-eliminate; the
// original keeps the dead dwSize=0 store, so memset is the canonical surface.
//   * DPNAME zero-init: memset(&dpid, 0, sizeof(dpid)) instead of `= {0}` —
//     VC5 DSE's the dwSize=0 store of the aggregate initializer (missing
//     mov [esp+8],ecx); memset's inlined 4-store expansion keeps all four
//     zero stores, matching sibling SendPlayerName (00426D50) evidence.

#include <string.h>

#if !defined(COM_HAND_TU_CONTEXT)
extern "C" void __cdecl Log(void* log, char* fmt, ...);
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
extern void* L;                    // TDebuggingLog* at [0x62C4FC]
#endif // COM_HAND_TU_CONTEXT
#if !defined(COM_HAND_TU_CONTEXT)
extern unsigned int DAT_0062c5ec;  // DirectPlay interface pointer [0x62C5EC]
#endif // COM_HAND_TU_CONTEXT
#if !defined(COM_HAND_TU_CONTEXT)
extern unsigned int DAT_0062cf04;  // self DPID [0x62CF04]
#endif // COM_HAND_TU_CONTEXT

#define COMM_STATE_ERROR 1

#if !defined(COM_HAND_TU_CONTEXT)
struct DPNAME {
    unsigned long dwSize;        // +0x00
    unsigned long dwFlags;       // +0x04
    char* lpszShortName;         // +0x08 (ANSI)
    char* lpszLongName;          // +0x0C
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Comm_Error {
public:
    void ShowReturn(long result, char* msg);
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
struct IDirectPlayVtbl {
    char gap_00[0x18];
    long (__stdcall* CreatePlayer)(void* self, unsigned long* dpid,
                                   DPNAME* name, void* data,
                                   unsigned long dataSize, unsigned long flags,
                                   void* playerData);
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
struct IDirectPlay {
    IDirectPlayVtbl* vtbl;
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
struct COMMPLAYEROPTIONS {
    unsigned char NeedsToBeSent;
    unsigned char _pad_0[3];
    unsigned long LastSentTime;
    int ProgramState;            // +0x1558
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x10F8];
    char MyFriendlyName[0x81];
    char MyFormalName[0x81];
    char gap_11FA[0x14E0 - 0x11FA];
    RGE_Comm_Error* Err;         // +0x14E0
    char gap_14E4[0x1550 - 0x14E4];
    COMMPLAYEROPTIONS PlayerOptions;  // +0x1550

    int AddSelfPlayer();
    void CloseSession();
    void ReleaseComm();
    void GetMyMultiPlayerCaps();
};
#endif // COM_HAND_TU_CONTEXT


int TCommunications_Handler::AddSelfPlayer()
{
    Log(L, "Create the player");

    DPNAME dpid;
    memset(&dpid, 0, sizeof(dpid));
    dpid.lpszShortName = (unsigned short*)this->MyFriendlyName;
    dpid.dwSize = sizeof(dpid);
    dpid.lpszLongName = (unsigned short*)this->MyFormalName;

    Log(L, "Adding player [%s]", this->MyFriendlyName);

    IDirectPlay* dp = (IDirectPlay*)DAT_0062c5ec;
    if (dp == 0) {
        return 0;
    }

    long retval = dp->vtbl->CreatePlayer(dp, (unsigned long*)&DAT_0062cf04, &dpid, 0, 0, 0, 0);
    this->Err->ShowReturn(retval, "Add SELF PLAYER");

    if (retval != 0) {
        this->CloseSession();
        this->ReleaseComm();
        this->PlayerOptions.ProgramState = COMM_STATE_ERROR;
        return 0;
    }

    Log(L, "Rcvd DPID of %d", DAT_0062cf04);
    this->GetMyMultiPlayerCaps();
    return 1;
}
