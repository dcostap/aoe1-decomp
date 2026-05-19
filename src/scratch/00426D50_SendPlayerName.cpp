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
// GIVEUP: remaining blocker is exact VC5 scheduling of DPNAME zero stores around saved-register pushes and right-to-left call argument side effects (load interface global before short-name lea, set dwSize after pushes). No accepted_drift proposal: call/setup instructions are reordered broadly, not a localized benign drift.

#include <string.h>

struct DPNAME {
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned short* lpszShortName;
    unsigned short* lpszLongName;
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
    memset(&dpnSetName, 0, sizeof(dpnSetName));
    dpnSetName.lpszLongName = (unsigned short*)(void*)this->MyFormalName;
    dpnSetName.lpszShortName = (unsigned short*)(void*)this->MyFriendlyName;
    dpnSetName.dwSize = 16;
    long result = ((long (__stdcall *)(void*, void*, DPNAME*, int))(*(void***)*(void**)0x62C5EC)[0x78 / 4])(*(void**)0x62C5EC, *(void**)0x62CF04, &dpnSetName, 2);
    this->Err->ShowReturn(result, "Send Player Name");
    return result;
}
