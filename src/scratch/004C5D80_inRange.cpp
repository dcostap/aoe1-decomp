// VA: 004C5D80 RGE_Static_Object::inRange
// PDB source: stat_obj.cpp
// Attempt log:
// 2026-05-31: Replaced stub with decompiler/natural distance-minus-radii behavior; natural source compiled 192B, too small vs 199B.
// 2026-05-31: Best kept variant uses volatile dy plus volatile x; it reaches exact size and matches the original push/local prefix through offset 71, but volatile x stores too early and the remaining x/y radius subtraction and final range compare FPU stack schedule differs broadly (33.17% positional). Not accepted_drift quality.
// 2026-05-31: Tried parameter-slot reuse and x-clamp-before-y forms; they fell back to 192B/no-push families. /Op produced a broad wrong frame.
// 2026-08-02 sa_eaf547d0_r1: baseline restored the natural typed dx/dy/x/y distance-minus-radii source (182B, 197 differing bytes); the compiler's no-push basin is structurally wrong.
// 2026-08-02 sa_eaf547d0_r1: rechecked the prior volatile-dy/volatile-x diagnostic (199B, 77 differing bytes, exact prefix through +0047); its early volatile x store remains the first structural mismatch at the radius FPU block.
// 2026-08-02 sa_eaf547d0_r1: normal-x, address-taken/array x, target-pointer alias, delayed x materialization, x-before-y, and in-place dx/dy variants all returned no-push or broad structural basins; a 120-case radius-expression/final-expression lab found no exact variant (best size-eligible family remained 66 positional bytes off).
// 2026-08-02 sa_eaf547d0_r1: left in clean natural source after the 10-hypothesis budget; blocker is unresolved VC5 x87 scheduling/stack-home shape from +0047, not calls, layout offsets, or behavior.
// 2026-08-07 orch-w20: sibling distance_to_object (004C5E50) shares the identical original radius section including the fused `fsubr [esp+8]` in the fcomp->fnstsw gap; its research established the mechanism (y at 1-deep after the x fcomp pops x fuses dy into fsubr [mem]; y-before-clamp is 2-deep/eager-fld/homes-overlay; y-after-clamp is 1-deep but after the branch).
// orch-w20 pass (10 probes + 2 labs):
//   - Applied the sibling's best structure (volatile dy home + exact-valued double radius temps + y after the x clamp): 197 -> 38 diff, exact 199B size, first mismatch moved to +98.
//   - Swapped the final range expression to x*x + y*y (original computes x*x first): 38 -> 22 diff, single span at the fcomp->fnstsw gap, shape 97.01%, 70.15% exact-block coverage.
//   - y-before-clamp (natural order per PDB line map 3659=y/3660=x-clamp) is a hard dead end: with plain floats, doubles, or direct members it evaluates y at 2-deep -> eager `fld dy` instead of the fused `fsubr [mem]`, and homes overlay (no push ecx): 186-187 diff.
//   - Duplicating y's assignment in both x-clamp arms (LESSONS duplicate-assignment pattern) DOES hoist the fused fsubr into the gap while keeping both homes, but VC5 sinks the second-step `fsub [ecx+34h]` into both arms with a jmp (+5 bytes, 204B total; 83-90 diff). No spelling (arm order, temp forms, store order) hoists the fsub too.
//   - 20-variant lab (y position x clamp form x temp forms x dy volatility): 0 exact; best family remains y-after-clamp + double this_radius_y declared BEFORE the clamp (declaration position is load-bearing: declaring it after the clamp collapses to 184B).
//   - Final state: 22 diff / 199B exact size / first mismatch +0062 (VA 004C5DE2); the only remaining byte span is the binary-observed fused `fsubr [esp+8]` positioned between the x fcomp and fnstsw (y's dy read before the x<0 branch). Rebuilt emits fnstsw;test;je;mov [esp],0 before fsubr;fsub. This is the same known unreachable VC5 x87 scheduling gap as siblings distance_to_object (22 diff, same gap) and distance_to_position (accepted drift with the same overlay difference). The gap changes fault order (dy home read after the branch vs before) so it is not accepted_drift material.
//   - Next leads: (a) TU-context probe - compile with stat_obj.cpp-like headers/context, since the original's y-before-clamp line map implies the fused schedule came from the real TU; (b) ternary-CSE shape `y = (x < 0 ? (x = 0, dy - this_ry) : dy - this_ry) - other_ry` to CSE-hoist both y steps before the branch; (c) duplicate-in-both-arms with the second subtraction split as a post-if `y -= other_master->radius_y`.
// 2026-08-09 orch-luna-4c5d80-w2 fresh pass (10 meaningful hypotheses):
//   - stat_obj.cpp-like <math.h> context was codegen-neutral; no header/context movement recovered the gap.
//   - The ternary-CSE shape from the prior lead improved 22 -> 14 differing bytes and exact size 199B; it emitted the fused fsubr/fnstsw but left the second `fsub [other+34h]` after the branch. This is the codegen-best diagnostic, not the clean source.
//   - Full-branch/partial/common y forms, y-before-clamp with ternary or explicit homes, and a narrow volatile x reread stayed in no-push/broad 186+ diff basins. A focused radius-type/pointer lab found no exact 199B variant.
//   - The focused risky-flag lab (default, /GX, /Oa, /Og-, /Ot-, /O1, /Ox combinations) left the 14-byte default group or broke structure; no flag lead.
//   - A final comma-sequenced y assignment likewise stayed in the no-push basin. Restored the clean natural y-after-clamp reconstruction; blocker remains the binary-observed x87/fault-order gap, shared by 004C5E50 and 004C5F00.
// 2026-08-10 orch-statobj-fresh-02 fresh pass (6 meaningful probes):
//   - Materializing other radius_y before the x clamp as double (211B/114 diff) or float (205B/104 diff) disrupted the exact radius prefix; both were rolled back.
//   - Combining the x clamp and Y assignment with a comma expression, using a natural ternary x clamp, and predeclaring y were codegen duplicates of the clean 199B/22-diff source.
//   - Reused canonical static/master coordinate and radius ownership; no call, layout, or ABI lead emerged. Clean source retained; remaining gap is the same fused other-Y subtraction/fault-order scheduling hunk at +0062.
// 2026-08-11 sa6d8559ad_inRange fresh bounded pass:
//   - Added a complete donor-era polymorphic declaration; codegen was unchanged (199B/22 diff).
//   - Split Y subtraction into a pre-clamp this-radius step and post-clamp other-radius step; VC5 fell into the no-push 192-diff basin and was rolled back.
//   - Retested the best ternary-CSE diagnostic with a volatile radius_y field; it was an emitted-code duplicate of the prior 14-diff diagnostic, not an exact lead.
//   - Added the complete proven static/master field layouts; codegen remained 199B/22 diff and moved the same localized hunk only, so the clean narrow source was restored.
//   - No call, ABI, layout, or TU-context lead changed the binary-proven fsubr/fsub fault-order gap. Leave the canonical typed 199B/22-diff source in scratch for the next pass.

class RGE_Master_Static_Object {
public:
    char gap_00[0x30];
    float radius_x;  // +0x30
    float radius_y;  // +0x34
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[4];
    RGE_Master_Static_Object* master_obj; // +0x08
    char gap_0C[0x2C];
    float world_x; // +0x38
    float world_y; // +0x3C

    int inRange(RGE_Static_Object* other, float range);
};

int RGE_Static_Object::inRange(RGE_Static_Object* other, float range)
{
    float dx = other->world_x - this->world_x;
    volatile float dy = other->world_y - this->world_y;

    if (dx < 0.0f) {
        dx = -dx;
    }
    if (dy < 0.0f) {
        dy = -dy;
    }

    RGE_Master_Static_Object* this_master = this->master_obj;
    RGE_Master_Static_Object* other_master = other->master_obj;
    double other_radius_x = other_master->radius_x;
    double this_radius_x = this_master->radius_x;
    float x = dx - this_radius_x - other_radius_x;
    double this_radius_y = this_master->radius_y;

    if (x < 0.0f) {
        x = 0.0f;
    }
    float y = dy - this_radius_y - other_master->radius_y;
    if (y < 0.0f) {
        y = 0.0f;
    }

    if (x * x + y * y < range * range) {
        return 1;
    }
    return 0;
}
