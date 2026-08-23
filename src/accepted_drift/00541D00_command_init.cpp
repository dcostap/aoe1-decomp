// World.cpp:852-854, 89 bytes
// RGE_Game_World::command_init(int, TCommunications_Handler*)
// FLAGS: config/flags/00541D00_command_init.rsp uses /GX.
//
// === ACCEPTED_DRIFT ===
// Current best approach (baseline pattern, 18% positional diff, 16 bytes):
// The first 68 bytes match exactly. VC5 inserts 4 bytes of redundant
// zero-displacement `test eax,eax; jne +0` at the join point, shifting the remaining
// common store + SEH restore + epilogue into padding. Accepted as the same behavior-
// neutral /GX EH common-store join artifact as sibling init helpers.
//
// BLOCKER: VC5 /GX EH common-store join guard. When a `new` expression with a
// constructor call is followed by a null-normalization if and a common member
// store, VC5 inserts a redundant `test eax,eax; jne +0` at the join point.
// This appears to be a VC5 EH-related scheduling artifact (flag preservation
// after SEH try-level store interfering with the original `test eax,eax` that
// set ZF before the conditional jump).
//
// Attempt log:
// - Attempt 1: `this->command = new RGE_Command(this, param2)` — sinks store
//   to success path only (23.6% diff).
// - Attempt 2: explicit if/else stores in arms — separate-store pattern,
//   null-path store past window (15.7% diff).
// - Attempt 3: ternary `p ? p : 0` — optimized away to sinking (23.6%).
// - Attempt 4: separate cmd variable set in if/else — sunk to sinking (23.6%).
// - Attempt 5: placement new (not available) — compile error.
// - Attempt 6: explicit alloc+ctor via method call — no EH frame (64 bytes).
// - Attempt 7: `if(p){}else{p=0}` — same as baseline (18%).
// - Attempt 8: unconditional store + null-only override — 17% diff.
// - Attempt 9: member pointer alias — sunk to sinking (23.6%).
// - Attempt 10: split alloc+explicit ctor call — no EH frame (64 bytes).
// - Attempt 11: void* member type — sunk to sinking (23.6%).
// - Attempt 12: *(type*)&member cast — duplicate store pattern (17%).
// - Attempt 13: int member type — sunk to sinking (23.6%).
// - Attempt 14: separate q variable set in if/else — sunk to sinking (23.6%).
// - Attempt 15: virtual dtor RGE_Command + baseline — same 18% as baseline.
// - Attempt 16: virtual class + unconditional store + if/else both arms —
//   BEST: 10% diff! Replaced test+jne with duplicate store (3 vs 4 bytes).
//   BUT: missing ret due to 3-byte shift, still not exact.
// - Attempt 17: virtual class + if/else stores (no unconditional pre-store) —
//   14% diff, back to test+jne pattern.
// - Attempt 18: virtual class + store + null-only guard — 17% diff.
// - Attempt 19: virtual class + store + null-only if (no else) — 17% diff.
// - Attempt 20: virtual class + store + empty if-non-null — sunk (23.6%).
// - Attempt 21: operator new + placement new — no EH frame (64 bytes).
// - Attempt 22: virtual class + one-liner store — sinking (23.6% diff).
//
// Key findings:
// - The 10% attempt (16) eliminated test+jne by having both if and else arms
//   store to the member, but added a duplicate 3-byte store, truncating ret.
// - The 18% attempt (15/baseline) keeps the exact original structure but
//   has the 4-byte redundant test+jne at the join.
// - The 4-byte shift from test+jne is the ONLY mismatch after 68 matching bytes.
// - No source variation eliminated the test+jne while keeping the common store.
// - RGE_Command with virtual dtor keeps sizeof at 0x18 (vptr + 0x14 gap).
// - /GX flag is essential for the SEH prologue/epilogue.
//
// Accepted drift: the 4-byte insert is a dead zero-displacement branch; the rest
// of the function matches 68 bytes + 14 shifted bytes, with identical behavior,
// memory effects, register preservation, and stack cleanup once the shifted epilogue
// is considered. No inline asm/hacks.
// Full canonical World.cpp context emits the same reviewed drift bytes.

#include "../../include/world_scenario_context.h"

void RGE_Game_World::command_init(int param1, TCommunications_Handler* param2) {
    RGE_Command* p = new RGE_Command(this, param2);
    if ((void*)p == 0) {
        p = (RGE_Command*)0;
    }
    this->commands = p;
}
