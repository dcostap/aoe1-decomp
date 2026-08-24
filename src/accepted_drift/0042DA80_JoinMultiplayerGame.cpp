// 0042DA80 TCommunications_Handler::JoinMultiplayerGame
// Source: Com_hand.cpp lines 5781-5853
// Attempt log:
// 1: natural raw-offset reconstruction from packet, mirroring CreateMultiplayerGame descriptor layout; first mismatch was descriptor GUID offset (+4 vs +8).
// 2: corrected DPSESSIONDESC2 layout to dwSize/dwFlags/guidInstance/guidApplication; improved to one scheduling hunk after descriptor fill.
// 3: changed guidInstance/guidApplication fields to nested GUID_LOCAL aggregate assignments; improved to a tiny single-hunk drift.
// 4: introduced explicit dp local before Open; fixed DirectPlay virtual-call register choice (eax/edx) and left only the log/descriptor-store hunk.
// 5: tried session GUID local before the debug log; no change.
// 6: tried log local loaded before app GUID copy; worsened by interleaving app-copy stores with log argument pushes, reverted.
// 7: tried delaying app.d3 assignment until after the debug log; worsened broadly because descriptor was incomplete across the call, reverted.
// 8: tried direct FIELD_GUID(0x12EC) aggregate without app pointer; same codegen as best.
// 9: tried volatile debug-log global; compile/type mismatch and not useful, reverted.
// 10: tried char* vs const char* log prototype/string macros; no codegen change.
// ACCEPTED_DRIFT suggestion: remaining 16 edit bytes are a localized, behavior-equivalent scheduling difference around storing dSess2.guidApplication.d3 relative to pushing args for the debug Log call. Both versions store the same dword to the same local stack slot before the call; no calls or predicates differ.

typedef unsigned long ulong;

struct GUID_LOCAL {
    ulong d0;
    ulong d1;
    ulong d2;
    ulong d3;
};

#pragma pack(push, 1)
struct DPSESSIONDESC2_LOCAL {
    ulong dwSize;       // +00
    ulong dwFlags;      // +04
    GUID_LOCAL inst;    // +08
    GUID_LOCAL app;     // +18
    unsigned char rest[0x50 - 0x28];
};
#pragma pack(pop)

#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Comm_Error { public: void ShowReturn(long result, const char* msg); };
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class IDirectPlay4A {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual long __stdcall Open(DPSESSIONDESC2_LOCAL* desc, unsigned long flags); // +60
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
extern "C" void __cdecl TDebuggingLog_Log(void* log, char* fmt, ...);
#endif // COM_HAND_TU_CONTEXT

#define g_pDirectPlay (*(IDirectPlay4A**)0x0062C5EC)
#define g_pDebugLog (*(void**)0x0062C4FC)
#define STR_NO_DP ((char*)0x00582AC4)
#define STR_OPEN_JOIN ((char*)0x00582A98)
#define STR_JOIN_MP ((const char*)0x00582A88)

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    int AddSelfPlayer();
    void NotifyWindow(int msg);
    int JoinMultiplayerGame(GUID_LOCAL* guid);
};
#endif // COM_HAND_TU_CONTEXT


#define FIELD_DWORD(off) (*(long*)((char*)this + (off)))
#define FIELD_GUID(off) (*(GUID_LOCAL*)((char*)this + (off)))

int TCommunications_Handler::JoinMultiplayerGame(GUID_LOCAL* guid)
{
    DPSESSIONDESC2_LOCAL dSess2;

    if (g_pDirectPlay == 0) {
        TDebuggingLog_Log(g_pDebugLog, STR_NO_DP);
        return 0;
    }

    { ulong* p = (ulong*)&dSess2; int i; for (i = 0x14; i != 0; --i) *p++ = 0; }

    FIELD_GUID(0x12FC) = *guid;
    FIELD_DWORD(0x1C) = 0;

    dSess2.dwSize = 0x50;
    dSess2.inst = *guid;

    dSess2.app = FIELD_GUID(0x12EC);

    TDebuggingLog_Log(g_pDebugLog, STR_OPEN_JOIN, FIELD_GUID(0x12FC).d0);

    IDirectPlay4A* dp = g_pDirectPlay;
    long result = dp->Open(&dSess2, 1);
    if (result == (long)0x8877015E) {
        ((RGE_Comm_Error*)FIELD_DWORD(0x14E0))->ShowReturn(result, STR_JOIN_MP);
        return 0;
    }
    if (result == (long)0x88770005) {
        ((RGE_Comm_Error*)FIELD_DWORD(0x14E0))->ShowReturn(result, STR_JOIN_MP);
        return 0;
    }
    if (result == (long)0x8877014A) {
        ((RGE_Comm_Error*)FIELD_DWORD(0x14E0))->ShowReturn(result, STR_JOIN_MP);
        this->NotifyWindow(0x17AB);
        return 0;
    }
    if (result != 0) {
        ((RGE_Comm_Error*)FIELD_DWORD(0x14E0))->ShowReturn(result, STR_JOIN_MP);
        FIELD_DWORD(0x1558) = 1;
        return 0;
    }
    if (this->AddSelfPlayer() == 0) {
        return 0;
    }
    FIELD_DWORD(0x1558) = 3;
    return 1;
}
