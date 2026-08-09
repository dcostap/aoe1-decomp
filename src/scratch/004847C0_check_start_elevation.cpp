// VA: 004847C0 RGE_RMM_Elevation_Generator::check_start_elevation (224 bytes)
// Source: rmm_elev.cpp lines 64-95
//
// Checks that every 24-byte cell in the rectangle [x-range..x+range] x
// [y-range..y+range] (clamped to the map) has terrain bits matching `terrain`
// and elevation bits >= `elevation`. Returns 0 on the first mismatch.
//
// Attempt log:
// 1: natural indexed access this->tiles[row][col*24+5]; this spilled to ebp, tiles[row] recomputed per cell (201B).
//    -> switched to per-row cell pointer with 24-byte stride (count_map_tiles idiom).
// 2: pointer idiom; first hunk is y1/x1 compute order (orig computes y1 before x1, reusing edi=y).
// 3: y1-before-x1 fixed; still homes y1 in arg1 (orig: arg5) and loop setup lands after the
//    guard (orig hoists first-row setup before guard, short jg).
// 4: named `long offset = x0*24` local: worse (saved this early to [esp+10h], ecx stolen for x1).
// 5: named `char* row_base` local: shifted all register roles (x0=edi etc.), worse prologue.
// 6: explicit while loops with row_ptr + cell pointer (next-row base loaded at loop bottom).
//    -> exact 224B size, clean natural baseline (diff 148B / 66.07%, 170 equal bytes).
// 7: declare x1 before y1 (y1 last) but assign y1 before x1: identical codegen (0 bytes changed).
// 8: focused loop-shape lab (while/do/direct-row-base/preloaded-cell forms): no exact variant;
//    the best family used an inner nonempty-row guard (diff 144B, 160 equal bytes).
// 9: direct dword access to the proven dead `range` home improved stack-slot coloring but
//    emitted the same 144B family; volatile access added 3 bytes and was rolled back.
// 10: top-declared offset/row/row_ptr plus the natural inner guard reproduced the same 144B
//     family; preloading a named row base is the current natural source (diff 142B / 163 equal).
//
// Left in scratch: remaining drift is localized.
//  - +0025: y1 homed in arg1 [esp+18h]; original homes it in arg5 [esp+28h] (the dead `range`
//    param slot). Same-TU exact donor remove_area_from_lists (00484C80) needed explicit
//    `x = end; radius = start_y;` param reassignment to recover param-slot homes; this
//    function's range param is uchar, so a dword y1 store cannot reuse it via assignment.
//  - +0045..: loop shape: original peels first rowBase load before the outer guard and carries
//    rowBase+offset in eax (loaded via `add eax,[edi]` in the row_inc); rebuilt loads rowBase
//    at the outer-loop top and keeps rowPtr homed in a slot. y1 slot choice drives the other
//    slot rotations (row arg1->arg2, rowPtr arg2->arg5).
// Paused: exact matching budget exhausted. Current source keeps canonical named row-base
// ownership; remaining drift is the y1/row/row_ptr stack-home rotation and first-row setup.

class RGE_RMM_Elevation_Generator {
public:
    char gap_00[0x10];
    char** tiles;    // +0x10
    int width;       // +0x14
    int height;      // +0x18

    unsigned char check_start_elevation(long x, long y, unsigned char terrain, unsigned char elevation, unsigned char range);
};

unsigned char RGE_RMM_Elevation_Generator::check_start_elevation(long x, long y, unsigned char terrain, unsigned char elevation, unsigned char range)
{
    long x0 = x - range;
    long y0 = y - range;
    long offset;
    long row;
    char** row_ptr;
    char* row_base;
    long x1;
    long y1;
    y1 = y + range;
    x1 = x + range;

    if (x0 < 0) {
        x0 = 0;
    }
    if (y0 < 0) {
        y0 = 0;
    }
    if (x1 >= this->width) {
        x1 = this->width - 1;
    }
    if (y1 >= this->height) {
        y1 = this->height - 1;
    }

    offset = x0 * 24;
    row = y0;
    row_ptr = &this->tiles[y0];
    row_base = (char*)*row_ptr + offset;
    while (row <= y1) {
        if (x0 <= x1) {
            unsigned char* cell = (unsigned char*)row_base + 5;
            long col = x0;
            do {
                if (terrain == 0xFF
                    || (*cell & 0x1F) != terrain
                    || (*cell >> 5) < elevation) {
                    return 0;
                }
                cell += 24;
                col++;
            } while (col <= x1);
        }
        row_ptr++;
        row++;
        row_base = (char*)*row_ptr + offset;
    }
    return 1;
}
