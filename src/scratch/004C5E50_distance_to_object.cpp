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

class RGE_Master_Object {
public:
    char gap_00[0x30];
    float radius_x;
    float radius_y;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[4];
    RGE_Master_Object* master_obj; // +0x08
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

    float x = dx - this->master_obj->radius_x - other->master_obj->radius_x;
    float y = dy - this->master_obj->radius_y - other->master_obj->radius_y;

    if (x < 0.0f) x = 0.0f;
    if (y < 0.0f) y = 0.0f;

    return (float)sqrt(y * y + x * x);
}
