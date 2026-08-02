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
//    -> exact 224B size, best metrics so far (diff 148B / 66.07%, 170 equal bytes).
// 7: declare x1 before y1 (y1 last) but assign y1 before x1: identical codegen (0 bytes changed).
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
// Next leads: probe explicit param-slot reuse via a long-typed local aliasing the arg5 slot
// (e.g. `*(long*)&range = y1`-style home steering or a union/struct cast), or a variant-lab
// sweep over loop-body pointer shapes (row_base vs *row_ptr) with the while/while baseline.

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

    long row = y0;
    char** row_ptr = &this->tiles[y0];
    while (row <= y1) {
        unsigned char* cell = (unsigned char*)*row_ptr + x0 * 24 + 5;
        long col = x0;
        while (col <= x1) {
            if (terrain == 0xFF
                || (*cell & 0x1F) != terrain
                || (*cell >> 5) < elevation) {
                return 0;
            }
            cell += 24;
            col++;
        }
        row_ptr++;
        row++;
    }
    return 1;
}
