// attempt log:
// first pass: EH-framed factory helper with a direct 0x20 new and the observed push order into the victory ctor
// second pass: use a local pointer with an explicit zero path so the failure case stays visible without changing the ctor push order
// third pass: the ctor push order is right, but the zero-path tail still drifts into a different register/branch basin than the packet
// target shape: allocate TRIBE_Victory_Conditions(0x20), call ctor with (this, param1, param2, param3), store result at +0x34 or 0 on alloc fail
// 2026-05-09 GraniteCub: tried 18 focused variants: direct assignment/local,
// explicit if/goto/common-store forms, two-stage result, param locals, this alias,
// assignment-in-if/comma/volatile local, int temp for param3, void*/int victory member,
// ctor p3/p2 declaration probes, visible vptr surface, and brief /O1+/GX. Same EH
// new-expression blocker as 00471C90 and neighboring init helpers: direct new keeps
// exact EH/new/ctor family but sinks store into success path; artificial
// `if (v == 0) v = 0;` reaches closer common-store basin but inserts redundant
// post-merge test/sete code before store. Left cleaner direct-new source.
// 2026-05-10 SpruceGlow: tried 15 more focused variants. Direct store, ternary, and two-local result stayed in
//   the baseline success-store/null-tail family (edit diff 15, first mismatch 50). Null normalization, goto join,
//   param locals, this alias, self-assign, while/do-break, param-zero reuse, void* member, and explicit this store all
//   reached the better common-store basin but kept the redundant `test eax,eax; jne +0` at the join (edit diff 11,
//   first mismatch 78). If/else store worsened edit diff 17; assignment-in-condition worsened edit diff 26; local int
//   param3 and plain/incomplete ctor surface were worse. Kept the better common-store source below.
// 2026-05-10 StarryZephyr pass: rechecked current common-tail source (16.1616% positional, 11.1111% edit), tried
//   direct member new (success-store/null-tail, first mismatch 50, edit 15), and positive goto common-store (same
//   redundant join-test basin). Restored current best source.
// Left in scratch: behavior/EH/allocation/ctor push order are correct; blocker is the same redundant join-test plus
// tail/epilogue truncation seen in neighboring init helpers. Not proposing accepted_drift. No inline asm/hacks.
// 2026-05-10 current Boss-assigned pass: revalidated baseline and tried unqualified store, direct/local no-if,
// goto-null, if/else-empty, slot reference alias, ternary, param locals/int-param3, if-store-arms, separated
// declaration/zero-init, assignment-in-if, comma, do/while break, raw member store, void* member surface, and
// RGE_Player inheritance surface. No exact. Common-tail family always keeps `test eax,eax; jne +0`; direct/ternary
// forms sink store/epilogue into success path; store-arms lower positional bytes but add real branch/store drift.
class RGE_Player;
class TRIBE_Victory_Conditions;

class TRIBE_Player {
public:
    char gap_00[0x34];
    TRIBE_Victory_Conditions* victory;

    void load_victory(int param_1, long* param_2, unsigned char param_3);
};

class TRIBE_Victory_Conditions {
public:
    char pad_0[0x20];
    TRIBE_Victory_Conditions(RGE_Player* player, int param_1, long* param_2, unsigned char param_3);
};

void TRIBE_Player::load_victory(int param_1, long* param_2, unsigned char param_3) {
    TRIBE_Victory_Conditions* v = new TRIBE_Victory_Conditions((RGE_Player*)this, param_1, param_2, param_3);
    if (v == 0) {
        v = 0;
    }
    victory = v;
}
