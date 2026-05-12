// 00541C90 RGE_Game_World::effects_init
// EH-framed allocate and construct RGE_Effects, store at +0x4C.
// FLAGS: config/flags/00541C90_effects_init.rsp uses /GX for original EH frame.
//
// === ACCEPTED_DRIFT ===
// Remaining diff: VC5 inserts dead `test eax,eax; jne +0` (4 bytes) at the
// common-store join point. This is a VC5 new-expression + EH lowering artifact
// that cannot be eliminated by any tried source form, variable/type surface, or
// flag combination. The inserted branch has zero displacement and no behavior.
// Best result: 18.18% positional / 12.5% edit diff, first mismatch offset 67.
// Same accepted drift pattern as 0052E650/0052E530.
//
// Attempt log:
// - 2026-05-12 season (20+ manual variants + 936 variant lab probes):
//   Source forms tried: direct one-liner (sunk-store, 23.86%), decl+store (23.86%),
//     self-assign if (18.18%), empty if (23.86%), not-null-empty-else, if-else-store
//     (15.91%, separate branches), if-else-store-rev, if-store-only, null-store-then-if,
//     switch-form, goto-form, ternary-member-assign (23.86%), assignment-in-condition
//     (bizarre setcc codegen), operator-new+placement-new (same as new-expr),
//     operator-new+explicit-ctor (48 bytes, no EH frame), inline function def (no .text).
//   Variable surfaces tried: simple gap stub, full RGE_Effects with virtual dtor/members,
//     __declspec(nothrow), __declspec(dllimport) operator new.
//   Flags probed (via variant lab vc5-risky preset): /GX, /GX /O1, /GX /Ox, /GX /Og-,
//     /GX /Ot-, /GX /Oa, and all combinations. /O1 moved to EBP frame + different EH
//     pattern (89 bytes), still with test/jne. /Oa had no effect.
//   None eliminated the test/jne at the join.
// - Pre-2026-05-10 passes (HollowSnowdrop, MidnightLily, StarryZephyr): retried 20+
//   focused variants. Same blocker. See earlier comments.
//
// Accepted drift: behavior and EH/call surface are correct; the remaining 16 bytes of
// positional diff are entirely the 4-byte no-op test/jne artifact and its 12-byte
// downstream shift into padding. No inline asm/hacks used. No custom flags beyond /GX
// needed. Same blocker as map_init (00541C20).

void* operator new(unsigned int size);

class RGE_Effects {
public:
    char gap_00[0x0C];
    RGE_Effects(int param_1);
};

class RGE_Game_World {
public:
    char pad_00[0x4C];
    RGE_Effects* effects;

    void effects_init(int param_1);
};

void RGE_Game_World::effects_init(int param_1) {
    RGE_Effects* e = new RGE_Effects(param_1);
    if (e == 0) { e = 0; }
    this->effects = e;
}
