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
// Luna-42F190 2026-08-02: baseline rebuilt 152B / 76.9737% positional, first mismatch +0x13.
// Probe 1 absolute-address globals: 152B / 82.2368%, worsened strict bytes despite better edit resync.
// Probe 2 explicit frame overlay at +0x0c: 144B / 62.1622%, frame 0x2c; improved but under-sized.
// Probe 3 padded 0x30 frame overlay: 144B / 61.4865%, frame matched; best fresh structural basin.
// Probe 4 volatile c4/c0 stores: duplicate codegen, no effect.
// Probe 5 DPNAME-before-test locals: duplicate old 152B family.
// Probe 6 &dpn.dwFlags / decompiler values: 156B / 80.1282%, regressed.
// Probe 7 pre-Log dpn string-size assignment: 160B / 87.5000%, regressed.
// Probe 8 typed unsigned-short DPNAME fields: duplicate 152B family.
// Probe 9 casted &dpn.dwFlags with canonical values: duplicate 152B family.
// Best retained below: explicit 0x30 frame with DPNAME at frame base and test at +0x0c;
// it models the binary-proven four-byte local overlap and keeps frame parity, but remains
// 144B with broad stack-write/cleanup drift. No accepted_drift: mismatch is structural.
// Luna42F190 2026-08-02 follow-up (10-probe budget):
// - Baseline confirmed the retained explicit 0x30 frame at 144B/61.4865% positional.
// - Natural DPNAME/&dwFlags, post-Log declaration scope, volatile global reads, and SDK-width
//   pointer fields either duplicated or worsened the structural basin.
// - A temporary test+31 dword-zero probe reached 148B/54.7297%, but moved the store to the
//   wrong pre-cleanup address; moving it after the DPNAME assignment regressed to 144B.
// - A recorded 18-variant source-order lab found no exact match. Its low-to-high/tail-first
//   diagnostic winner validated at 148B/54.0541%, but is opaque and not retained as source.
// - A plausible TemporaryName {pointer,text[28]} aggregate regressed to 152B/76.9737%.
// Main-agent source audit: the explicit raw frame encoded VC5's stack-slot overlap rather than
// plausible original source. Restored the typed TemporaryName + DPNAME reconstruction despite
// its worse byte metrics; compiler artifacts remain diagnostic evidence, not living source.
// Luna42F190b follow-up 2026-08-02 (10-probe pass):
// - Natural literal strcpy with SDK-width DPNAME regressed to 119B/89.1892% positional.
// - TemporaryName aggregate literal initialization regressed to 167B/87.4251%.
// - A standalone name pointer, including post-Log declaration scope, duplicated the 144B/61.4865%
//   structural family; initializing only binary-observed DPNAME fields reached 136B/66.8919%.
// - Zero-initialized char/DPNAME aggregates regressed to 160B/91.2500%.
// - Typed 32-byte/prefix-only TemporaryName forms reached 144B/61.4865% but did not recover the
//   original delayed cdecl cleanup or COM setup; moving lpszLongName before stores reached 144B/75.6757%.
// - Swapping TemporaryName field order reached 152B/77.6316%; all alternatives were rolled back.
// Final pass result: retain the audited typed TemporaryName + DPNAME source; mismatch remains broad
// and structural, so no accepted_drift or promotion is warranted.
//
// orch-w4 2026-08-07 retry (10-probe budget):
// - KEY INSIGHT: VC5 /O2 inlines `char test[32] = "TEMPORARY NAME";` as dword loads from the
//   .rdata literal + zero-fill of the remaining 17 bytes (mov [esp+X],0 reusing xor'd register),
//   exactly matching the original's string-store family. The original's stores sit at PDB line
//   6849 AFTER the Log call at 6845, so the declaration is a MID-FUNCTION C++ declaration after
//   the Log statement. The frame is plain DPNAME(16B)+char[32] = 0x30, no TemporaryName union:
//   dpn@esp+0x00 (dwSize, dwFlags NEVER written, lpszShortName@0x08, lpszLongName@0x0c),
//   test@esp+0x10. Previous "TemporaryName overlap" hypothesis was a misreading of the
//   dpn.lpszLongName/test.shortName slot coincidence.
// - Probe record (labs 55-61 + manual compiles): swept all 6 dpn field orders, strcpy/memset/
//   array-init forms, dp/player/vtbl/function-pointer locals, comma-in-arg side effects, pointer-
//   through stores, &dpn.dwSize argument, call-result local, and 19 flag sets. Best retained:
//   arr-init + (lpszShortName, lpszLongName, dwSize) + direct SetPlayerName call = 148B / 0x30
//   frame / 38 instr / calls aligned / 12 diff bytes (8.1081%), first mismatch at +0x81.
// - REMAINING 12-byte gap: the dwSize store. Original emits `mov [esp+10h],10h` AFTER the final
//   two arg pushes (vtbl load + push player + push dp precede it); VC5 always emits the constant
//   store BEFORE the vtbl load in this code family. Every source shape, local form, and flag set
//   lands at [esp+8] pre-vtbl. SendPlayerName (00426D50) shares the identical original tail
//   (dwSize after pushes, call [ecx+78h]) and is also paused in scratch for the same reason; its
//   dp/player-local source moves the dwSize after the pushes but destroys the push-interleaving.
//   No accepted_drift: the store position changes the memory-write schedule in the call setup.
//
// orch-luna-42f190-w1 fresh pass 2026-08-09:
// - The remaining 12-byte tail gap was caused by the flat function-pointer vtable surface.
// - Replaced it with the SDK-shaped IDirectPlay2 __stdcall virtual surface, whose
//   SetPlayerName slot is exactly 0x78 (30 prior slots); the compiler then emits the
//   binary's vtable load, player/interface pushes, and delayed dwSize store exactly.
// - The natural literal-array/DPNAME reconstruction is retained; default flags only,
//   no inline asm or compiler-steering hacks. Exact 148B result validated before promotion.
// - Main-agent audit restored typed variadic `L->Log(...)` syntax and the SDK DPNAME
//   ANSI union members; both are codegen-identical and preserve the exact result.

#include "../../include/game_globals.h"

class TDebuggingLog {
public:
    void Log(char* text, ...);
};

extern TDebuggingLog* L;

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

class TCommunications_Handler {
public:
    void ForceNameChange(void);
};

void TCommunications_Handler::ForceNameChange(void) {
    DPNAME dpn;

    L->Log("Force Name Change");

    char test[32] = "TEMPORARY NAME";

    dpn.lpszShortNameA = test;
    dpn.lpszLongNameA = test;
    dpn.dwSize = 0x10;

    ((IDirectPlay2*)DAT_0062c5ec)->SetPlayerName(DAT_0062cf04, &dpn, 2);
}
