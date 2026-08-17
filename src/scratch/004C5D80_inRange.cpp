// VA: 004C5D80 RGE_Static_Object::inRange
// orch-004C5D80-D fresh pass 2026-08-12 (3 recorded probes + 1 unrecorded compile-fix):
//   - Baseline revalidated: 199B/22-diff clean natural source; the only span is the fused
//     fsubr/fsub fault-order gap at +0062 (y computed after the x branch vs between
//     fcomp/fnstsw/test as the oracle has it).
//   - H1 full-y-ternary (both arms hold complete y expr incl. -other_ry): 90 diff/204B,
//     VC5 sinks the fsub into both arms with a jmp; rolled back. Confirms sibling H1/S8.
//   - H2 ternary-CSE prefix (dy-this_ry in both arms, -other_ry outside): 14 diff/199B,
//     exact through +0068 incl. fused fsubr; only the fsub [ecx+34h] placement differs
//     (oracle: between fnstsw and test; rebuilt: join block). Codegen-best diagnostic.
//   - H3 (y assignment inside the y<0 test condition) failed compile (missing decl);
//     not recorded as a probe; clean source already restored before re-test.
//   - Mechanism confirmed vs sibling 004C5E50/distance_to_position: VC5 hoists only the
//     CSE-common x87 prefix into the fcomp->fnstsw window; the pointer-read suffix fsub
//     never lands between fnstsw and test across natural/ternary/duplication forms or
//     the ~70 sibling shapes + 20+ flag sets. Unreachable gap; clean source retained.

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
// 2026-08-12 follow-C5D80-r1 bounded condition/expression follow-up:
//   - Assignment-in-condition for y compiled to 201B/99 diff and broke the suffix; restored.
//   - Reversed x lower-bound spelling (0.0f > x) compiled to 203B/106 diff and changed the radius prefix; restored.
//   - Assignment-in-condition for x emitted the same 199B/22 code as the clean source; no new lead.
//   - Split ternary-CSE y prefix plus separate other-radius subtraction compiled to 224B/128 diff; restored.
//   - Split ordinary y subtraction into two statements emitted the same 199B/22 code as the clean source.
//   - No new binary-backed condition or expression shape moved the +0062 fsubr/fsub fault-order gap. Clean source retained.

// tu-statobj-C5D80 2026-08-12: reused the prior complete static/master surface
// and stat_obj.cpp-like header evidence. That shared-TU evidence was already
// codegen-neutral. The volatile diagnostic was rejected because it only steers
// scheduling. No natural lead exists for the fsubr/other-Y fault-order gap.

// sa-3d0c180c-r1 fresh pass 2026-08-17:
//   - Revalidated the pinned source after removing all diagnostic volatility.
//     The current natural typed source rebuilds to 202B/198 differing bytes;
//     the earlier 199B/22-diff result required volatile dy and is not retained.
//   - Natural float radius locals, direct master-member expressions, reference
//     aliases, complete-Y-before-X evaluation, predeclared y, and split dy
//     initialization produced no better source model. The direct float radius
//     form fell to 186B and changed the x87 topology.
//   - Restored this typed double-radius reconstruction. It preserves the
//     binary-supported float stores and natural non-volatile behavior. The
//     remaining gap is the original pushed parameter home and fused Y-radius
//     subtraction, which requires compiler-steering volatility to reproduce.

// sa-0e26f47a-r1 revisit 2026-08-17:
//   - Tested natural Y-before-X and split-Y source order, swapped and split
//     declarations, direct float radii, explicit double casts, ternary clamps,
//     ternary absolute values, and the reviewed DAT_00574720 zero symbol.
//   - The zero-symbol variant improved relocation-aware diagnostics but changed
//     the clamp store sequence. No variant recovered the original push/home
//     topology or fused Y subtraction. Restored this pinned typed source.
//
// sa-696cdc9a-r1 revisit 2026-08-17:
//   - Re-read the complete local evidence and checked every strict span in the
//     current 202B/198-diff baseline. The five spans are +0000..+0025,
//     +0026..+0061, +0062..+0090, +0091..+00C0, and +00C1..+00C7.
//   - Span 1 is the missing entry `push ecx` and the different coordinate
//     scratch shape. The target stores dy in the shifted other-parameter home
//     at [esp+8]. The rebuild stores a coordinate value at [esp+4] and has no
//     local push.
//   - Span 2 is the resulting second absolute-value and pointer-load shift.
//     The target reloads and stores the parameter home. The rebuild uses extra
//     x87 swaps and the unshifted parameter home.
//   - Span 3 is the decisive Y-radius schedule. The target emits
//     `fsubr [esp+8]` and then `fnstsw`, followed by `fsub [ecx+34h]`. The
//     rebuild emits `fnstsw`, the X branch and store, then both subtractions.
//     This also changes memory fault and scratch-write order.
//   - Span 4 is the shifted clamp and final FPU setup. The target uses the
//     local at [esp] and range at [esp+0Ch]. The rebuild uses [esp+4] and
//     [esp+8]. Span 5 is the missing `pop ecx` and three-byte boundary overflow.
//   - Tested 20 natural hypotheses in this claim. These covered direct field
//     expressions, float and double radius locals, pointer and reference
//     ownership, declaration and initialization scope, Y-before-X order,
//     ternary and split arithmetic, the proven zero object, const lifetimes,
//     period header context, and return control forms. No source moved the
//     target push/home topology or the fused Y subtraction.
//   - The binary-proven zero object improved the raw result to 203B/194B, but
//     it changed relocations and clamp stores. It is not retained. The earlier
//     199B/22-diff diagnostic used volatile dy; this claim did not use it.
//   - All probes were restored. The clean natural typed source remains
//     202B/198 diff. The blocker is the original pushed parameter-home and
//     pending-x87 schedule. No natural, policy-valid exact lead remains.

// sa-39d1e9fa-r1 revisit 2026-08-17:
//   - Read the complete local lessons, workflow, target history, negative
//     evidence, target assembly, and exact neighboring stat_obj methods.
//   - Tested 20 new context and ownership hypotheses. These used the exact
//     canonical class fields, real neighboring method declarations, partial
//     real virtual surfaces, period standard-header combinations, #line state,
//     stat_obj helper and rdata declarations, declaration order, and natural
//     x87 temporary ownership. No policy-valid variant recovered push ecx,
//     the [esp+8] parameter home, or the fused other-Y subtraction.
//   - A 64-sample ambient declaration lab emitted one unchanged basin. An
//     eight-case standard-header lab emitted three basins, all worse than
//     exact and none closer to the target. Full canonical class context was
//     codegen-neutral. These are negative TU-context results, not source.
//   - The exact decompiler local order remained a 182-byte, 197-diff no-push
//     basin. Acquiring master pointers before coordinates improved the raw
//     diff to 195 but worsened shape and did not create the target home.
//   - Restored the clean natural typed source after every probe. Final
//     validation remains 202B/198 diff with five spans. The prior 199B/22
//     result still required forbidden volatile dy and is not retained.

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
    float dy = other->world_y - this->world_y;

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
