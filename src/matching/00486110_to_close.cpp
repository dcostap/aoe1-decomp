// VA: 00486110 RGE_RMM_Object_Generator::to_close
// PDB: rmm_obj.cpp lines 185-202 (97 bytes, 47 asm lines)
// Default flags: /nologo /c /O2 /Oy /Ob0
//
// MATCH: python tools/check_function.py --va 00486110 => Result: MATCH / 0.0000%.
//
// Key insight: The for-loop header `for (i = 0; i < count; i++)` generates the
// correct `jl` loop bottom matching the original. Computing `p` as
// `&this->lands[0].y + i * 0x10` from the loop inside the body causes VC5 to
// strength-reduce it to a running pointer (`lea edx,[ecx+12CCh]`; `add edx,10h`)
// but NOT hoist the initialization before the count check. This matches the
// original instruction ordering exactly.

#include <stddef.h>

#include "..\..\include\rmm_obj_context.h"

unsigned char RGE_RMM_Object_Generator::to_close(RGE_Object_Info_Line* info_line, long x, long y)
{
    long count = this->info.land_num;
    long i;
    for (i = 0; i < count; i++) {
        long* p = (long*)((char*)&this->info.lands[0].y + i * 0x10);
        long dx = x - *(p - 1);
        if (dx < 0) dx = -dx;

        long dy = y - *p;
        if (dy < 0) dy = -dy;

        if (dx < info_line->land_inner_radius && dy < info_line->land_inner_radius) {
            return 1;
        }
    }

    return 0;
}
