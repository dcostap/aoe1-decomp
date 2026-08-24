// 004C8A80 TRIBE_Building_Object::update()
// Source: t_b_obj.cpp lines 402-455
// Size: 241 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Status: EXACT MATCH — default /O2 /Oy; ready for promotion after validation.
//
// Attempt log:
// Earlier scratch probes established the +0x08/+0x10 pointer ownership,
// one 4-byte local, signed-short result bound, and the default flag set.
// Probe 1: full virtual surface + real set_status member fixed the vtable
//          call ABI (243 bytes / 134 diff -> 241 bytes / 10 diff).
// Probe 2: common PriorMap1 assignment after the production dispatch fixed
//          both branch-local EAX stores (10 diff -> 8 diff).
// Probe 3-6: named short/int and typed-field variants were codegen duplicates.
// Probe 7: splitting the natural numerator into `float progress` restored
//          the denominator conversion order; exact 241-byte match.
// Main-agent audit restored the canonical TRIBE_Combat_Object base boundary
// and qualified base calls; emitted code remains exact.
//
// Key findings:
// - Field offsets correct: ptr_10(+0x10), ptr_08(+0x08), field_35(+0x35)
//   status_field(+0x48), build_pts(+0x1DC), PriorMap[123](+0x1EC/0xF0/0xF4)
//   PriorTurn[123](+0x1F8/0xFC/0x200), prior_map_val(+0x1B8)
// - FPU: fild(some_short_int) → fmul build_pts → fidiv max_val → __ftol
// - FPU comparison: fild(max_val) → fcomp build_pts → fnstsw/test ah,41h
// - Use `push ecx` for 1 local = 4 bytes
// - External: world_update_counter at [886C10h]
// - Forward-declared base methods: TRIBE_Combat_Object::update (004CA5F0h),
//   empty_production_queue (004C9D20h), update_production_queue (004C9DA0h)
// - ((short)result < some_short) → cmp cx, di; jge (signed)
//   ((unsigned short)result < some_short) → cmp cx, di; jae (unsigned)
//
// Exact-shape notes:
// - The vtable slot is modeled as a real __thiscall virtual at +0x5c.
// - The common assignment is intentionally outside the dispatch; VC5
//   duplicates it into both return arms with the original register choices.
// - `progress` is a natural intermediate numerator, not compiler-only
//   scheduling scaffolding; it preserves the observed FPU evaluation order.

#include "../../include/t_b_obj_context.h"

unsigned char TRIBE_Building_Object::update()
{
    if (status_field == 0) {
        int build_time = (int)ptr_08->value_15A;
        short max_value = ptr_10->value_60;
        float progress = (float)(int)max_value * build_pts;
        unsigned char result = (unsigned char)((long)(progress / build_time));

        if ((short)result < max_value && result != field_35)
            field_35 = result;

        if ((float)ptr_08->value_15A <= build_pts) {
            this->set_status(2);
        }
    }

    PriorMap3 = PriorMap2;
    PriorMap2 = PriorMap1;
    PriorTurn3 = PriorTurn2;
    PriorTurn2 = PriorTurn1;
    PriorTurn1 = (long)world_update_counter;

    unsigned char base_result = TRIBE_Combat_Object::update();

    if (status_field > 2) {
        TRIBE_Combat_Object::empty_production_queue();
    } else {
        TRIBE_Combat_Object::update_production_queue();
    }

    PriorMap1 = prior_map_val;

    return base_result;
}
