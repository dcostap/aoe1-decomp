// 00538F00 RGE_View::Pick_Tile (view.cpp:4748-4855, 301B)
// Converts screen-space coordinates to tile coordinates with isometric correction.
//
// Left in scratch: VC5 register allocation differs fundamentally from original.
// Original uses sub esp,8 (2 locals, map_w/map_h on stack) + pushes ebx/ebp/esi/edi.
// Rebuilt uses push ecx (1 local) + pushes ebx/ebp/esi/edi. This 4-byte frame
// difference shifts all stack offsets. The get_tile_bounding_coords call in
// original reuses param_1/param_2 stack slots as output temps; rebuilt passes
// member addresses (&view_left, &view_top). Register assignments: original
// uses edx=map_w/esi=map_h/edx, rebuilt uses ebp=map_w/edx=map_h. The while
// loops, idiv tile coordinate computation, and iterative bounding-box search
// logic are structurally identical.
// FLAGS: /nologo /c /O2 /Oy

struct RGE_Map3 {
    char _pad_00[8];
    int map_width;    // +0x08
    int map_height;   // +0x0C
};

struct RGE_View7 {
    char _pad_00[0x8C];
    int view_left;             // +0x8C
    int view_top;              // +0x90
    char _pad_94[0x104 - 0x94];
    RGE_Map3* map;             // +0x104
    short tile_wid;            // +0x108
    short tile_hgt;            // +0x10A
    short tile_half_wid;       // +0x10C
    short tile_half_hgt;       // +0x10E
    char _pad_110[0x130 - 0x110];
    int map_scr_x_offset;      // +0x130
    int map_scr_y_offset;      // +0x134

    void get_tile_bounding_coords(int col, int diff_col,
                                  int* by1, int* row_out,
                                  int* top_out, int* left_out);
    int Pick_Tile(long px, long py, int* col_out, int* row_out);
};

int RGE_View7::Pick_Tile(long px, long py, int* col_out, int* row_out) {
    int map_w = map->map_width;
    int map_h = map->map_height;

    int bx1 = (map_scr_x_offset - view_left) + (int)px;
    int by1 = (map_scr_y_offset - view_top) + (int)py;

    if (bx1 < 0) {
        *col_out = -1;
        *row_out = -1;
        return 0;
    }

    if (bx1 >= map_w * tile_wid) {
        *col_out = map_w + 1;
        *row_out = map_h + 1;
        return 0;
    }

    int tcol = bx1 / tile_wid;
    int trow = by1 / tile_hgt;
    int diff = tcol - trow;
    tcol = tcol + trow;

    while (diff < 0 || tcol >= map_w) {
        tcol--;
        diff++;
    }

    while (diff >= map_h || tcol < 0) {
        tcol++;
        diff--;
    }

    int found = 1;
    do {
        int tmp_left, tmp_top;
        get_tile_bounding_coords(tcol, diff, &by1, row_out, &tmp_top, &tmp_left);
        if (by1 < *row_out) {
            tcol++;
            diff--;
        } else if (tmp_left < by1) {
            tcol--;
            diff++;
        } else {
            found = 0;
        }
    } while (found);

    tile_half_hgt = 0;
    tile_half_wid = 0;
    return 0;
}
