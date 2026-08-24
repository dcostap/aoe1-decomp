// VA: 00426D50 TCommunications_Handler::SendPlayerName (Com_hand.cpp:808-826, 105B)
// Retry 2026-05-18/19 (13 honest tries):
// - baseline memset/natural DPNAME exact-sized but broad scheduling mismatch: 60.0000% positional / 53.3333% edit.
// - expanded memset into explicit field zeroes; VC5 moved this into ESI before first zero, compiled size-short (96B) or worse ordering.
// - tried explicit self local to force mov esi after first zero store; no improvement, still size-short/order drift.
// - tried volatile DPNAME; exact-sized but much broader prologue/order mismatch (64.7619% positional / 107.6190% edit).
// - tried aggregate `{0}` initializer; exact-sized with trailing nops but worse prologue/order mismatch (86.6667% positional).
// - tried comma-expression argument evaluation to delay lpszShortName and dwSize until call argument setup; VC5 still scheduled zero/lea too early and compiled size-short.
// - tried /Od briefly; emitted EBP debug frame and broad mismatch, flag removed.
// - 2026-05-19 tried explicit field-zero/source-order with saved DP interface local; worsened prologue (70.4762% positional).
// - 2026-05-19 tried virtual IDirectPlay-style SetPlayerName surface; compiled size-short (96B), same setup-order family.
// - 2026-05-19 retried explicit zeroes with DP interface local; worsened prologue to push/mov-this before xor and 70.4762% diff.
// - 2026-05-19 retried explicit zero/source order without DP local; compiled size-short (96B) and kept the wrong push/mov-this-before-zero family.
// - 2026-05-19 Boss retry: 13 additional source-order/local-dp/late-size/volatile/memset-subrange variants; best remained 56.1905% positional, most were 71.4286%-86.6667% or size-short 96B.
// - 2026-05-20 retry: 20 more probes. Best kept below: memset + lpszLongName before DP global + local DPNAME* + comma dwSize, 40.0000% positional / 31.4286% edit, first mismatch offset 22.
// - Tried explicit first zero before self, brace init, raw char stack buffer, no/with DP local, formal/friendly pointer locals, p-before/after-formal, side-effect argument expressions, flags/player locals, volatile first field, register self; none matched.
// GIVEUP: remaining blocker is exact VC5 scheduling/register coloring of DPNAME setup around right-to-left call argument side effects. Best near-match has correct size/tail but uses ECX not EDX for formal-name LEA, stores long-name too early, loads short-name/dwSize before pushes, and reorders vtable/player loads. No accepted_drift proposal: call/setup instructions are broadly reordered, not localized benign drift.
// 2026-05-21 Boss retry: 10 more honest probes. Tried formal pointer/function-scope locals, volatile formal, explicit zeroes, delaying dwSize into first argument, split virtual-function local, re-reading DP global in function/first arg expressions. Best kept below improves to 33.3333% positional / exact size/tail, but VC5 still schedules short-name LEA/store before formal-name and writes dwSize too early. Leaving in scratch; not accepted_drift because mismatches are non-local call setup/order differences.
// 2026-05-24 Boss retry: 10 more probes focused on DPNAME field/order shaping. Tried moving lpszLong assignment before/into call args, register formal pointer, comma expressions in argument 2/4, swapped local DPNAME field order with compensating source assignments, and volatile dwSize. Best kept below improves first mismatch to offset 41, 30.4762% positional / 29.5238% edit: bytes through the formal-name store now match and memory contents are correct, but VC5 still emits the short-name LEA before the stack-param LEA/push, stores short name and dwSize too early, and loads vtable/player in the wrong order. Not accepted_drift: remaining mismatch is non-local call setup scheduling, not a tiny benign register/encoding drift.
// 2026-05-26 Boss retry: 10 more probes. Tried moving dwSize assignment into the hidden/first argument, swapping player/load-before-shortName with a player local, volatile shortName store, non-register/register formal/dp/p locals, no p local/direct &dpn, and a padded __stdcall virtual DP interface call. None improved on the kept 30.4762% baseline; several regressed first mismatch to offset 22 or kept the same schedule. GIVEUP remains: call argument side-effect scheduling, not acceptable localized drift.
// 2026-08-02 LunaM426D50 session: fresh baseline rebuilt at 105B/0x10 frame/2 calls, 32 positional bytes (30.4762%), first mismatch +0x29.
// - natural typed stdcall DPNAME surface regressed to 107B/66.3551%; reverted.
// - natural DPNAME with short-name/dwSize comma side effects reached 105B/33.3333%, but put the formal-name LEA in the wrong early field band; reverted.
// - separate field assignment, volatile/register/reference pointer aliases, and moving dwSize to arg1 either duplicated the 30.4762% codegen or regressed frame/order; reverted.
// - corrected ShowReturn declaration to the original char* symbol surface; no intended byte-shape change.
// PAUSE: best remains the pre-existing 105B/30.4762% source; ordered calls, frame, size, and tail match, while VC5 still swaps the arg-side-effect/pointer-LEA schedule at +0x29. Remaining drift is non-local call setup scheduling, not accepted_drift.
// Formal review/normalization 2026-08-02: corrected canonical DPNAME field order and replaced
// comma-expression/raw-call plumbing with explicit statements and a period-appropriate typed COM
// interface. The emitted code reads both globals, stores both name pointers, dereferences the
// DirectPlay object, and stores dwSize afterward. Current validation is 105/105 bytes, 31 strict
// differing bytes, with both calls aligned. One post-fix reviewer still considers the different
// placement of argument pushes at an invalid-interface fault observable; retain in scratch pending
// fresh review of this normalized source rather than reintroduce scheduling hacks.
// 2026-08-10 orch-comhand-logic-fresh-03 pass: the exact-match donor 0042F190 ForceNameChange
// shares this identical vtable+0x78/delayed-dwSize tail and reached EXACT by calling the global
// DirectPlay pointer directly through the SDK-shaped IDirectPlay2 __stdcall virtual surface
// ((IDirectPlay2*)DAT_0062c5ec)->SetPlayerName(DAT_0062cf04, &dpn, 2) instead of caching the
// interface/player in locals (locals "destroy the push-interleaving"). Mirrored that surface and
// the direct global-deref call form here; memset zero schedule and field store order unchanged.
// Probe 15: VC5 emits the two name-field stores in REVERSE source order (ForceNameChange source
// short,long emitted long,short; probe 14 source long,short emitted short,long). Original emits
// long-store early / short-store in-pushes, so source order must be short-first, long-second.
// Probe 15 EXACT MATCH (105/105, 0.0000%, 100% shape, calls aligned, relocations 3/3): the SDK
// IDirectPlay2 surface + direct global-deref call + short-first/long-second assignments reproduce
// the oracle's push-2 -> push-&dpn -> vtable-deref -> push-player -> push-dp -> dwSize schedule
// byte-for-byte, including the invalid-interface fault context that blocked logic promotion.
//
#include <string.h>

struct DPNAME {
    unsigned long dwSize;
    unsigned long dwFlags;
    union {
        unsigned short* lpszShortName;
        char* lpszShortNameA;
    };
    union {
        unsigned short* lpszLongName;
        char* lpszLongNameA;
    };
};

#if !defined(COM_HAND_TU_CONTEXT)
class IDirectPlay2 {
public:
    virtual long __stdcall QueryInterface(void* riid, void** object) = 0;
    virtual unsigned long __stdcall AddRef(void) = 0;
    virtual unsigned long __stdcall Release(void) = 0;
    virtual long __stdcall AddPlayerToGroup(unsigned long group, unsigned long player) = 0;
    virtual long __stdcall Close(void) = 0;
    virtual long __stdcall CreateGroup(void* id, DPNAME* name, void* data, unsigned long size, unsigned long flags) = 0;
    virtual long __stdcall CreatePlayer(void* id, DPNAME* name, void* event, void* data, unsigned long size, unsigned long flags) = 0;
    virtual long __stdcall DeletePlayerFromGroup(unsigned long group, unsigned long player) = 0;
    virtual long __stdcall DestroyGroup(unsigned long group) = 0;
    virtual long __stdcall DestroyPlayer(unsigned long player) = 0;
    virtual long __stdcall EnumGroupPlayers(unsigned long group, void* guid, void* callback, void* context, unsigned long flags) = 0;
    virtual long __stdcall EnumGroups(void* guid, void* callback, void* context, unsigned long flags) = 0;
    virtual long __stdcall EnumPlayers(void* guid, void* callback, void* context, unsigned long flags) = 0;
    virtual long __stdcall EnumSessions(void* desc, unsigned long flags, void* callback, void* context, unsigned long timeout) = 0;
    virtual long __stdcall GetCaps(void* caps, unsigned long flags) = 0;
    virtual long __stdcall GetGroupData(unsigned long group, void* data, unsigned long* size, unsigned long flags) = 0;
    virtual long __stdcall GetGroupName(unsigned long group, void* data, unsigned long* size) = 0;
    virtual long __stdcall GetMessageCount(unsigned long player, unsigned long* count) = 0;
    virtual long __stdcall GetPlayerAddress(unsigned long player, void* data, unsigned long* size) = 0;
    virtual long __stdcall GetPlayerCaps(unsigned long player, void* caps, unsigned long flags) = 0;
    virtual long __stdcall GetPlayerData(unsigned long player, void* data, unsigned long* size, unsigned long flags) = 0;
    virtual long __stdcall GetPlayerName(unsigned long player, void* data, unsigned long* size) = 0;
    virtual long __stdcall GetSessionDesc(void* data, unsigned long* size) = 0;
    virtual long __stdcall Initialize(void* guid) = 0;
    virtual long __stdcall Open(void* desc, unsigned long flags) = 0;
    virtual long __stdcall Receive(unsigned long* from, unsigned long* to, unsigned long flags, void* data, unsigned long* size) = 0;
    virtual long __stdcall Send(unsigned long from, unsigned long to, unsigned long flags, void* data, unsigned long size) = 0;
    virtual long __stdcall SetGroupData(unsigned long group, void* data, unsigned long size, unsigned long flags) = 0;
    virtual long __stdcall SetGroupName(unsigned long group, DPNAME* name, unsigned long flags) = 0;
    virtual long __stdcall SetPlayerData(unsigned long player, void* data, unsigned long size, unsigned long flags) = 0;
    virtual long __stdcall SetPlayerName(unsigned long player, DPNAME* name, unsigned long flags) = 0;
};
#endif // COM_HAND_TU_CONTEXT

class RGE_Comm_Error;

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char pad_000[0x10F8];
    char MyFriendlyName[0x81];
    char MyFormalName[0x81];
    char pad_11FA[0x2E6];
    RGE_Comm_Error* Err;

    long SendPlayerName();
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Comm_Error {
public:
    void ShowReturn(long result, char* msg);
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
extern unsigned int DAT_0062c5ec;
#endif // COM_HAND_TU_CONTEXT
#if !defined(COM_HAND_TU_CONTEXT)
extern unsigned int DAT_0062cf04;
#endif // COM_HAND_TU_CONTEXT

long TCommunications_Handler::SendPlayerName()
{
    DPNAME dpnSetName;
    memset(&dpnSetName, 0, sizeof(dpnSetName));
    dpnSetName.lpszShortNameA = this->MyFriendlyName;
    dpnSetName.lpszLongNameA = this->MyFormalName;
    dpnSetName.dwSize = sizeof(dpnSetName);
    long result = ((IDirectPlay2*)DAT_0062c5ec)->SetPlayerName(DAT_0062cf04, &dpnSetName, 2);
    this->Err->ShowReturn(result, (char*)0x580EB4);
    return result;
}
