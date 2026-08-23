// VA: 00486180 RGE_RMM_Object_Generator::set_search_area
// PDB: rmm_obj.cpp lines 206-226 (134 bytes, 56 asm lines)
// Default flags. No inline asm/hacks.
// Attempt log:
// 1: Baseline natural nested loop was exact-size but mismatched by 21 edit bytes; main drift was push/mov scheduling, end_y in EAX instead of EBP, and inner-loop guard emitted `cmp/jg; mov eax,edi` instead of original `cmp; mov eax,edi; jg`.
// 2: Tried explicit self local and split `end_y = radius; end_y += y`; no codegen change.
// 3: Declared inner-loop `cx = sx` before the `if (cx <= end_x)` guard instead of inside the if body. This let VC5 schedule `mov eax,edi` between cmp and jg and snapped the whole shifted layout to exact.
// MATCH: python tools/check_function.py --va 00486180 => Result: MATCH / 0.0000%.

#include "..\..\include\rmm_obj_context.h"

void RGE_RMM_Object_Generator::set_search_area(long x, long y, long radius, unsigned char fill)
{
    long sx = x - radius;
    long sy = y - radius;
    long end_x = x + radius;
    long end_y = radius;
    RGE_RMM_Object_Generator* self = this;
    end_y += y;

    if (sx < 0) sx = 0;
    if (sy < 0) sy = 0;
    if (end_x >= self->width) end_x = self->width - 1;
    if (end_y >= self->height) end_y = self->height - 1;

    long y_cur = sy;
    if (y_cur <= end_y) {
        do {
            long cx = sx;
            if (cx <= end_x) {
                do {
                    ++cx;
                    self->rows[y_cur][cx - 1] = fill;
                } while (cx <= end_x);
            }
            ++y_cur;
        } while (y_cur <= end_y);
    }
}
