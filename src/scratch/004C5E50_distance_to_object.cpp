// VA: 004C5E50 RGE_Static_Object::distance_to_object (stat_obj.cpp)
#include <math.h>
// Retry 2026-05-21: replaced placeholder dx+dy with full decompiled behavior (world delta, abs, subtract radii, clamp, sqrt). Baseline full behavior compiles to 160B, too small vs original 167B; original has push ecx and reuses the incoming parameter stack slot plus one local for FPU temporaries.
// Tried 12 probes: volatile dy local (exact 167B but broad 86.2275% positional mismatch from byte 0, no push-ecx and wrong FPU order), stack-store abs-y temp, double zero comparisons, master-object locals, ternary clamps, x/y return-order swap, zero_float symbol, explicit sqrt extern, interleaved subtract assignments, volatile x/local result, dummy local, and decompiler-style parameter reuse. Most stayed 160B too small; none recovered original stack-slot/FPU scheduling.
// GIVEUP: leaving full behavior source in scratch. No accepted_drift: remaining mismatch is structural FPU stack scheduling/local-slot topology, not localized benign drift.
// Retry 2026-05-24 Boss pass: 20 more probes. Baseline still compiles to 160B vs original 167B.
// Tried parameter-slot reuse via *(float*)&other (exact 167B but 83.8323% positional, first mismatch byte 0), volatile dy (167B but 86.2275% byte-0 mismatch),
// volatile x/y locals, ternary abs/clamps, swapped return term order, named result temp, master-object locals, explicit double cast for sqrt,
// dropping sqrt to inspect inline expression family, and flags /Op /Ob0 /Og /Ot /G5 /GB /O1 /Ox.
// Only /Op and param/volatile-dy variants reached 167B, all with broad wrong prologue/FPU topology; non-worsening natural variants stayed 160B.
// GIVEUP again; no accepted_drift proposal because remaining mismatch is structural stack-slot/FPU scheduling, not a localized equivalent hunk.
// Retry 2026-05-26 Boss pass: 18 probes on VA 004C5E50 only. Revalidated natural full-behavior source: 160B for 167B target. Tried parameter-slot reuse via `*(float*)&other` (167B but 83.8323% positional, first mismatch byte 0), volatile dy (167B / 86.2275%), dy stack pointer, zero_float symbol, explicit double sqrt (167B / 82.0359%), x*x+y*y return order, master-object locals, ternary abs/clamps, result local, y-first subtract order, and a decompiler-style saved `other` reuse attempt (VC5 cast error). Flag probes /Op (167B but 76.0479% positional, first mismatch +18), /G5 /GB /Og /Ob0 /Oy- /O1 /Ox; only /Op reached size and was broad wrong FPU topology. GIVEUP: not accepted_drift quality; size-matching variants change the FPU stack/prologue topology broadly rather than leaving a localized equivalent hunk.
// Luna-4C5E50 2026-08-02: fresh baseline rebuilt 147B (166 differing bytes). Volatile dy plus volatile x recovered the exact 0x00-0x46 prefix and 159B output (89 differing bytes, 53.2934%); removing x volatility, volatile y, x address-taking, dx reuse, and reversed radius operands all regressed or changed only a few bytes. An absolute F_ZERO view expanded global loads. Ordinary x plus an unused volatile saved_x was the best measured state at 169B (86 differing bytes), but it was codegen-only scaffolding and still diverged structurally at +0x47, so the natural source was restored. Next pass should revisit canonical radius/expression ownership rather than retain fake volatility.

// Luna4C5E50 2026-08-03: dossier/donor/ABI review confirmed world/radius ownership and no calls; declaration, local-reuse, class-surface, clamp-order, and parameter-home variants remained broad structural FPU mismatches. Clean source restored after the bounded 10-probe pass; blocker remains radius-expression evaluation/stack topology, not benign drift.
// Luna4C5E50b 2026-08-03: hoisted/top-declared locals, address-taken x, proven zero global, dx reuse, the RGE_Master_Static_Object name, and the full proven object field surface all emitted the clean 147B basin unchanged.
// The focused 10-variant dy/radius lab found no exact candidate; size-matching variants still had the wrong entry home/prologue. A one-field local Distance_Temp wrapper reached 167B/162 differing bytes and 60.71% shape, but still lacked the target push/local prefix and is codegen-only scaffolding, so it was rolled back.
// Final bounded pass exhausted: retain the natural world-coordinate/radius source. Remaining evidence is a broad VC5 FPU stack/local-topology blocker, not localized equivalent drift.
// Main-agent normalization: aligned the radius-owner stub name with the proven
// RGE_Master_Static_Object sibling/type surface; behavior and layout are unchanged.
// Logic-review integration 2026-08-05: the first blind reviewer proved that
// plain VC5 excess precision changed overflow results for dy and that master/
// radius read order changed malformed-pointer fault behavior.
// Round-2 review then found binary32 x rounding, Y-radius fault order, x87 event
// order, and scratch residue differences. A bounded main-agent pass recovered a
// natural 167-byte/22-diff x87 topology by using exact-valued double expression
// temps for other-X, this-X, and this-Y. The emitted object now matches through
// the x store/compare at +0x62, including binary32 dy/x homes and X-radius x87
// event order. Promotion remains blocked: other-Y is still read after the X
// branch rather than between x's fcomp and status test. Attempts to move that
// read earlier either lost the required homes/rounding or loaded it before the
// x comparison; a fresh pass must solve this final fault/exception-order gap.
// Fresh sa-eeb4e55b pass 2026-08-05: reverse-Y, ordinary-dy, delayed-predicate,
// same-line initialization, declaration-lifetime, conditional-clamp, and
// ordinary-dy/volatile-x probes did not preserve the clean basin. A focused
// natural Y-before-clamp lab found that direct Y-before-clamp emits the desired
// pending-x87-status subtraction, but overlays the dy and x homes and loses the
// required push ecx; alternate algebraic forms are broader. Restored the clean
// 167-byte/22-diff source. The remaining source-topology gap is still only the
// binary-observed fsubr [esp+8] between X fcomp and fnstsw, with the other-radius
// Y memory read after fnstsw; no fake volatility or opaque scheduling was kept.
// orch-statobj-logic-01 2026-08-10: fresh bounded pass on the fsubr/other-Y ordering blocker.
// CSE/duplication family (new for this target): duplicating `y = dy - this_radius_y` in both
// x-clamp arms (S3, or S5 with the y-= also duplicated) CSE-hoists the FUSED fsubr [esp+8] into
// the fcomp->fnstsw gap: first 0x68 bytes exact (104 equal incl. dy-home read), 14 diff, 98.18%
// shape, 167B. The other-Y fsub [ecx+34h] is ALWAYS emitted at the if/else join (S3/S5) or sunk
// into both arms with a jmp (H1/S8 full-expr ternaries, 59 diff) - never between fnstsw and test
// as the original has it. Full-expr ternaries CSE only the dy-this_ry prefix. Mini-reproducers
// M1/M2/M3 re-confirmed the y-before-clamp family (eager fld at 2-deep, homes overlay, no push
// ecx). Diagnostic S3/S5 forms are not period-plausible source, so the clean 167B/22-diff
// y-after-clamp reconstruction was restored and revalidated; the other-Y fault-order gap (read
// before the X branch) remains unreachable with this VC5 through source shape.

// sa-62602825-r1 pass 2026-08-06: exhaustive negative result. Mechanism
// established with mini reproducers: VC5 eagerly loads a volatile minuend (fld)
// when the y expression is evaluated at 2-deep before a branch, and fuses it into
// fsubr [mem] only when evaluated at 1-deep (subtrahend on top, after the X
// fcomp pops x). The original fuses dy into the fcomp->fnstsw gap; y-before-clamp
// always evaluates at 2-deep (eager fld, homes overlay, no push ecx), y-after
// evaluates at 1-deep but after the branch. ~70 source shapes tested (y operand
// orders, temp types, clamp orders, dx-reuse/fVar1, volatile-x, cast/copy reads,
// negated/dy-last forms) plus 20+ flag sets (/Op /Oa /Ot /Og /Oi /Ob0/1 /Os
// /Og- /Ot- /Oy- /G1-G6 /GB) and a 56-variant lab: none emit the fused fsubr in
// the gap while keeping both homes. Siblings inRange (004C5D80) and
// distance_to_position (004C5F00) have the identical gap in their originals;
// their reconstructions share the blocker (004C5F00 accepted as drift with the
// same overlay difference). Clean 167B/22-diff source retained; remaining gap is
// the y arithmetic position (fault-order: other-Y read after the X branch).

// tu-statobj-C5E50 2026-08-12: reviewed the sibling's complete stat_obj.cpp
// class surface and header-context probe. It was codegen-neutral and supplied no
// new source or ABI lead for the shared fsubr/other-Y fault-order gap. Kept the
// natural typed reconstruction.

// sa26d9938f_distance 2026-08-13: modeled the proven static/master layouts,
// removed volatile dy, double radius temporaries, and saved master aliases,
// then tested the natural stat_obj.cpp shape that computes complete Y before
// the X clamp. This preserves the source-level other-Y evaluation order, but
// VC5 emitted a 151-byte no-push basin (164 differing bytes, first mismatch at
// entry) and did not preserve the oracle's fsubr/fsub x87 status/fault order.
// Retain this readable typed reconstruction; the old 167-byte codegen result
// depended on unsupported scheduling scaffolding.
// sa32c93f25_distance fresh reassessment: restored the prior typed x87
// high-parity candidate (volatile binary32 dy plus ordered double radius
// expressions), which rebuilt at 167B/22 diff with one mismatch span at
// +0062. Natural complete-Y-before-X and split-Y probes fell to 158/163
// differing bytes. Top-declared locals were a codegen duplicate. The clean
// candidate remains the readable source because the high-parity form still
// needs compiler-steering volatility and cannot move the other-Y fsub into
// the pending X-status window. No exact natural lead remains.

// sa-43937d1d fresh pass 2026-08-16: tested a diagnostic high-parity source
// that rebuilt at 167B/22-diff with 96.36% shape. A five-variant radius-expression
// lab reproduced the same 167B/22-diff basin except for the known no-push
// y-before-X family. A seven-variant follow-up with address-taken and volatile
// X copies did not restore push ecx or improve the localized gap. A volatile
// other-Y radius home caused an 8-byte frame and 179B output, so it was rejected.
// The diagnostic source required fake volatility and promoted radius locals,
// so the main-agent review restored the clean direct-float model below. The gap is
// the original fsubr [esp+8], fsub [other+34] sequence between X fcomp and test;
// VC5 emits fnstsw/test and the X clamp store first. This changes fault and
// scratch-write order. No exact natural lead was found; keep the source in scratch.

// sa-54daf59e fresh pass 2026-08-17: revalidated the clean direct-float source
// at 151B/164 diff. A proven DAT_00574720 zero symbol reached 152B with the
// same positional diff and worse edit cost. Natural dx reuse, named master
// pointers, split declarations, split compound subtractions, and unqualified
// own-member reads all rebuilt the same 151B/164-diff basin. Restored the clean
// direct-float source. No exact natural lead was found; the push/home and x87
// scheduling gap remains broad.

// sa-0e0fce4a-r1 fresh pass 2026-08-17: six natural probes did not recover the
// target stack home. Explicit double radius temporaries reached 147B/163 diff
// with better instruction shape but a larger size gap. An explicit other-object
// alias was codegen-neutral. Staging dy through double then float, using the
// register keyword, and declaring dx/dy before assignment all reproduced the
// 151B/164-diff no-push basin. Restored the pinned direct-float source and kept
// the prior high-parity 167B/22-diff form only as diagnostic history; it needs
// volatility and remains wrong in the pre-branch fsubr/fsub order.

// sa-e400f46a-r1 revisit 2026-08-17: completed 20 fresh meaningful probes and
// restored the pinned 151B/164-diff natural source. Reproduced the prior
// 167B/22-diff high-parity basin with volatile binary32 dy, ordered master
// aliases, and double radius expression temps. Partial duplicated Y-prefix
// statements improved that diagnostic to 14 diff bytes, but the other-Y
// subtraction still stayed after the X status branch. Tested compare polarity,
// const fields and aliases, zero-global compare operands, ternary and scoped
// control forms, radius and coordinate widths, and grouped radius arithmetic.
// None recovered the original push/home plus pre-branch other-Y ordering.

// sa-b81569dd-r1 fresh direct-scalar audit 2026-08-17: completed 20 natural
// hypotheses and restored this pinned source. Binary behavior is supported as
// direct float deltas: other-X minus this-X, then other-Y minus this-Y. Each
// delta uses a less-than-zero absolute step. The radius terms are two
// separate subtractions. The X term clamps before Y, and the final expression
// squares X first, then Y, before sqrt. The executable has no calls.
//
// The original reads this/other master pointers after coordinate abs. It loads
// other-X radius, this-X radius, this-Y radius, and other-Y radius. It stores X
// in a local stack home, compares X, performs the fused Y subtraction, then
// consumes the X status and tests/clamps Y. The natural direct-float rebuild
// stays in the 151B/164-diff basin: it has no entry push/home, computes all
// radius members before the X clamp, and reads other-Y after that branch.
// Named float or double radius locals improved size and shape but remained
// broad mismatches. Delayed-Y and pointer-hoist forms violate PDB/fault order.
// No parameter-home, duplicated-Y, volatile, or metric-only form is retained.
// Object audit confirms the 167-byte FPO body, one local word, float-return ABI,
// dX/dY PDB locals, x87 event order, and VC5 compiler. The 167-byte diagnostic
// needs volatile and double radius temporaries that PDB and policy reject. No
// hidden local or compiler mismatch supports that form.
// sa-a65dc438-r1 object audit 2026-08-17: canonicalized the master/static declarations using
// same-TU proven fields and virtual-dtor surfaces. The master vptr is accounted for while
// preserving radius offsets; the static id field replaces an opaque word. Codegen was unchanged
// at 151B/164 diff. No inheritance, generic virtual methods, parameter-home alias, duplicated-Y
// form, raw cursor, or diagnostic volatility is supported by this target.

// sa-70edc786-r1 fresh direct-float lifetime/order pass 2026-08-17: ran twelve
// natural, PDB-supported probes after the canonical class audit. Tested dX/dY
// reuse, split declarations, radius pointer and float temporary ownership,
// predeclared Y, top-scoped X/Y, combined declarations, implicit own-member
// reads, compare operand order, split compound subtractions, and ternary clamps.
// The direct source stayed in the 151B/164-diff basin except for equivalent
// radius temporary ownership, which reached 167B/163 diff and 58.06% shape.
// That size-matching form still lacked push ecx, the shifted parameter home,
// and the target fused Y subtraction. It also added broad x87 stack changes.
// The natural source was restored. Volatile, duplicated-Y, parameter-home,
// double-radius, and metric-only diagnostics were not tested or retained.

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x24];
    float los; // +0x28
    char gap_2C[4];
    float radius_x; // +0x30
    float radius_y; // +0x34
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id; // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    char gap_0C[0x2C];
    float world_x; // +0x38
    float world_y; // +0x3C
    
    float distance_to_object(RGE_Static_Object* other);
};

float RGE_Static_Object::distance_to_object(RGE_Static_Object* other) {
    float dx = other->world_x - this->world_x;
    float dy = other->world_y - this->world_y;

    if (dx < 0.0f) dx = -dx;
    if (dy < 0.0f) dy = -dy;

    float x = (dx - this->master_obj->radius_x) - other->master_obj->radius_x;
    float y = (dy - this->master_obj->radius_y) - other->master_obj->radius_y;

    if (x < 0.0f) x = 0.0f;
    if (y < 0.0f) y = 0.0f;

    return (float)sqrt(x * x + y * y);
}
