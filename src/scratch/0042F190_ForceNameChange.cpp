// TCommunications_Handler::ForceNameChange
// VA: 0042F190
// Com_hand.cpp:6844-6854
// Attempt log:
// try 1: natural DPNAME + local "TEMPORARY_NAME" buffer with cdecl log and stdcall COM vcall; compiler initialized buffer before log.
// try 2: move Log before local string initialization; optimizer still hoisted local stores before call.
// try 3: make name buffer volatile to pin stores after Log; no change.
// try 4: declare Log variadic like project-local logging surface; no change.
// try 5: add missing DAT_005832bc/c4 globals and read non-const global string chunks after Log; still hoisted.
// try 6: cast name global reads through volatile pointers; still hoisted.
// try 7: put Log in comma expression feeding first name store; optimizer still schedules local name/DPNAME setup before log.
// tried transient /Od flag: body 130 bytes with EBP/debug basin, not useful; removed flag.
// Boss retry 2026-05-19:
// - Added missing DAT_005832bc/c4 declarations so scratch compiles; original comma/volatile source
//   remained 128B text (too short) with initialization hoisted before Log.
// - Rewrote as explicit Log-first then manual overlapped test/DPNAME stores; got exact 148B size
//   and first 19 bytes match, but store scheduling/offsets and COM-call setup still differ broadly
//   (90/148 positional, 87.16% edit).
// - Reordered TEMPORARY_NAME chunk stores c4/c0/bc; no improvement. Kept exact-size Log-first source.
// GIVEUP: behavior surface understood (Log, build DPNAME with TEMPORARY_NAME, DirectPlay SetPlayerName). Remaining blocker is VC5 scheduling/stack-overlap shape: original calls Log first, delays cdecl cleanup, then initializes overlapping local string/DPNAME slots; rebuilt under /O2 keeps same 0x30 frame and final COM call but hoists local initialization before Log and compacts to 128 bytes. Not proposing accepted_drift because call/order and stack-write schedule differ broadly.
// Retry 2026-05-20 assigned pass: 16 more probes. Tried absolute-address macros for globals, late/early TEMPORARY_NAME chunk store order, one-frame struct, Log returning int, COM vtable local, removing dpn flag/short-name zeroing, dpn.longName-as-overlap, union overlap, natural strcpy, memset+copy, explicit Frame{DPNAME; name[]} overlap with and without dummy flag/short stores, and flags /Ob0 /Og /Ot /G5 /GB /O1. Best retained source is still exact-size 148 with first 19 bytes matching, but broad 60.8108% positional / 87.1622% edit mismatch from the post-Log stack-write schedule and COM setup. Frame-overlap forms were either 144B too short or still broad; flags unchanged or bad. GIVEUP, no accepted_drift: write ordering/stack layout/call setup differ broadly, not localized equivalent drift.
// Retry 2026-05-21 Boss pass: 10 more probes. Tried original c4/c0/bc store order with explicit zero/ch locals, volatile zero local, removing DPNAME zero stores (144B too short), moving dpn.longName before tail string stores, Frame{DPNAME,test} aggregate, local IDirectPlay/player temps, raw function-pointer cast, absolute-address string chunk reads, manual literal char stores, and char-pointer byte fill. Best remains existing exact-size source: 148B, first 19 bytes match, 60.8108% positional / 87.1622% edit. None recovered original delayed cdecl cleanup plus overlapped stack-write schedule. Leaving in scratch; no accepted_drift because call cleanup/write ordering/COM setup are broad structural drift.
// Retry 2026-05-24 assigned pass: 10 more probes. Swapped local order to DPNAME-then-test, volatile test array, one Frame aggregate, larger test[36], memcpy chunk copies, Log as stdcall/plain C++/int-return, COM vtable local, and DirectPlay/player locals. Most collapsed to the existing exact-size 60.8108%/first+19 family; Log stdcall, larger local, and player locals worsened. Still no accepted_drift: original's delayed cdecl cleanup and overlapped DPNAME/test stack writes plus COM setup are broad structural scheduling differences, not localized equivalent drift.
// Retry 2026-05-26 Boss pass: 15 more probes. Revalidated baseline exact-size 148B, first 19 bytes match, 60.8108% positional / 87.1622% edit. Tried temp-ordered DAT_005832c4/c0/bc loads, raw 0x30 frame overlay (144B), DPNAME-first local order, vtable local late, natural strcpy (128B), volatile stores, explicit zero local, literal byte stores, partial/no DPNAME zero stores (144B), and several source-order variants around longName/dwSize. Best stayed the existing exact-size family; some variants worsened first mismatch to offset 8 or shrank to 128/144B. GIVEUP: no accepted_drift because remaining drift is still broad delayed-cdecl-cleanup/overlapped stack-write/COM-call setup topology, not localized benign codegen.

#include "../../include/game_globals.h"

extern void* L;
extern "C" void __cdecl Log(void* log, char* text, ...);
extern unsigned int DAT_005832bc;
extern unsigned int DAT_005832c4;

struct DPNAME {
    unsigned long dwSize;
    unsigned long dwFlags;
    char* lpszShortName;
    char* lpszLongName;
};

struct IDirectPlayVtbl {
    void* gap[0x78 / 4];
    long (__stdcall* SetPlayerName)(void* self, void* player, DPNAME* name, unsigned long flags);
};

struct IDirectPlay {
    IDirectPlayVtbl* vtbl;
};

class TCommunications_Handler {
public:
    void ForceNameChange(void);
};

void TCommunications_Handler::ForceNameChange(void) {
    char test[32];
    DPNAME dpn;

    Log(L, "Force Name Change");

    *(int*)&test[12] = DAT_005832c4;
    *(int*)&test[8] = DAT_005832c0;
    *(int*)&test[4] = DAT_005832bc;
    *(int*)&test[19] = 0;
    *(int*)&test[23] = 0;
    test[18] = DAT_005832ca;
    *(int*)&test[27] = 0;
    *(int*)&test[0] = (int)(test + 4);
    *(short*)&test[16] = DAT_005832c8;
    test[31] = 0;

    dpn.dwSize = 0x10;
    dpn.dwFlags = 0;
    dpn.lpszShortName = 0;
    dpn.lpszLongName = test + 4;

    ((IDirectPlay*)DAT_0062c5ec)->vtbl->SetPlayerName((IDirectPlay*)DAT_0062c5ec, (void*)DAT_0062cf04, &dpn, 2);
}
