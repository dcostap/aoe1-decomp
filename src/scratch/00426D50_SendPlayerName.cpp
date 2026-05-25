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

#include <string.h>

struct DPNAME {
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned short* lpszLongName;
    unsigned short* lpszShortName;
};

class RGE_Comm_Error;

class TCommunications_Handler {
public:
    char pad_000[0x10F8];
    char MyFriendlyName[129];
    char MyFormalName[129];
    char pad_11FA[0x2E6];
    RGE_Comm_Error* Err;

    long SendPlayerName();
};

class RGE_Comm_Error {
public:
    void ShowReturn(long result, const char* msg);
};

long TCommunications_Handler::SendPlayerName()
{
    DPNAME dpnSetName;
    register unsigned short* formal;
    void* dp;
    DPNAME* p;
    memset(&dpnSetName, 0, sizeof(dpnSetName));
    formal = (unsigned short*)(void*)this->MyFriendlyName;
    dp = *(void**)0x62C5EC;
    p = &dpnSetName;
    long result = ((long (__stdcall *)(void*, void*, DPNAME*, int))(*(void***)dp)[0x78 / 4])(dp, (dpnSetName.lpszShortName=(unsigned short*)(void*)this->MyFormalName, *(void**)0x62CF04), (*(volatile unsigned long*)&p->dwSize=16,p), (dpnSetName.lpszLongName = formal, 2));
    this->Err->ShowReturn(result, (const char*)0x580EB4);
    return result;
}
