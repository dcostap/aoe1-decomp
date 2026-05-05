// VA: 00486110 RGE_RMM_Object_Generator::to_close(RGE_Object_Info_Line&, long, long)
// PDB source: rmm_obj.cpp lines 185-202 (97 bytes, 47 asm lines)
// Default flags
//
// __thiscall: this in ecx, 3 stack params. ret 0Ch cleanup.
// Returns 1 if (x,y) is within land_inner_radius of any land point, 0 otherwise.
//
// 96/97 bytes matching. Left in scratch.
//
// Difference: VC5 restructures do-while loop with early return to use
// `jge exit; jmp loop` (4 bytes) instead of `jl loop` (2 bytes). The compiler
// inverts the loop-end condition when a `return 1` exists inside the body.
// The epilogue difference saves ~1 byte.

struct RGE_Object_Info_Line {
    char gap_00[0x24];
    long land_inner_radius;
};

struct RGE_RMM_Object_Generator {
    char gap_000[0x12C8];
    char lands_area[0x18F8 - 0x12C8];
    long land_num;  // +0x18F8

    unsigned char to_close(RGE_Object_Info_Line* info_line, long x, long y);
};

unsigned char RGE_RMM_Object_Generator::to_close(RGE_Object_Info_Line* info_line, long x, long y) {
    long count = this->land_num;
    long i = 0;
    if (count <= 0) return 0;

    long radius = info_line->land_inner_radius;
    long* p_y = (long*)((char*)this + 0x12CC);

    do {
        long dx = x - *(p_y - 1);
        if (dx < 0) dx = -dx;

        long dy = y - *p_y;
        if (dy < 0) dy = -dy;

        if (dx < radius && dy < radius) {
            return 1;
        }

        i++;
        p_y += 4;
    } while (i < count);

    return 0;
}
