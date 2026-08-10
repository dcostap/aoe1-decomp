// 00538F00 RGE_View::Pick_Tile (view.cpp:4748-4855, 301B)
// Converts screen-space coordinates to tile coordinates with isometric correction.
//
// Attempt log:
// - baseline: natural typed map/dimension ownership; 301B but VC5 used a 4B
//   push-local frame and a different early register coloring.
// - context/ABI/layout/declaration probes (canonical RGE_View/RGE_Map surface,
//   split declarations, and local ordering) were codegen duplicates.
// - binary stack evidence showed that VC5 homes bounding-coordinate outputs in
//   dead incoming-parameter slots. This is compiler allocation evidence, not a
//   reason to express source-level casts that overwrite parameter objects.
// - a focused 32-case natural-shape lab found only a diagnostic local-struct
//   variant with 301B/frame parity; it still diverged at the early view-top
//   register load and is not retained as source scaffolding.
// - this pass rechecked sum/order, map-pointer, declaration-scope, and six-way
//   local-order variants; they were duplicates or neutral.
// - a direct contiguous Map_Dims aggregate plus binary-observed output aliases
//   reached 301B/frame parity and 189B strict drift (88.98% shape), but the
//   parameter casts were compiler-steering rather than plausible living source;
//   aggregate initializer/order variants did not improve it and were rolled back.
// Main-agent audit restored four ordinary named bounding outputs and removed
// explicit parameter-home alias casts. Remaining gap is broad VC5 register/frame
// coloring, not an unresolved call set or bounding-box behavior.
// FLAGS: /nologo /c /O2 /Oy

class RGE_Map {
public:
    virtual ~RGE_Map();
    void* map_data;
    int map_width;    // +0x08
    int map_height;   // +0x0C
};

class TPanel {
public:
    virtual ~TPanel();
};

class RGE_View : public TPanel {
public:
    char _pad_04[0x88];
    int view_left;             // +0x8C
    int view_top;              // +0x90
    char _pad_94[0x104 - 0x94];
    RGE_Map* map;               // +0x104
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

int RGE_View::Pick_Tile(long px, long py, int* col_out, int* row_out) {
    int map_w;
    int map_h;
    int bx1;
    int by1;
    map_w = map->map_width;
    map_h = map->map_height;
    bx1 = (map_scr_x_offset - view_left) + (int)px;
    by1 = (map_scr_y_offset - view_top) + (int)py;

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
        int bound_first;
        int bound_row;
        int bound_top;
        int bound_left;
        get_tile_bounding_coords(tcol, diff, &bound_first,
                                 &bound_row, &bound_top, &bound_left);
        if (by1 < bound_row) {
            tcol++;
            diff--;
        } else if (by1 > bound_left) {
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
