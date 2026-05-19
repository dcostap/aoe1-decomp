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

struct RGE_Land_Point_Info_Line {
    long x;
    long y;
    long pad[2];  // total 16 bytes per entry
};

struct RGE_Object_Info_Line {
    char gap_00[0x24];
    long land_inner_radius;
};

class RGE_RMM_Object_Generator {
public:
    char gap_00[0x34];
    char info_objects[0x1294];
    RGE_Land_Point_Info_Line lands[99];
    long land_num;
    char gap_18C8[0x30];

    unsigned char to_close(RGE_Object_Info_Line* info_line, long x, long y);
};

unsigned char RGE_RMM_Object_Generator::to_close(RGE_Object_Info_Line* info_line, long x, long y)
{
    long count = this->land_num;
    long i;
    for (i = 0; i < count; i++) {
        long* p = (long*)((char*)&this->lands[0].y + i * 0x10);
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
