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
// - continuation baseline revalidated the ordinary source at 283B (18B short).
// - staged dimension declaration/initializer and long-width probes were duplicate
//   or neutral; a separate named map-width/bx1/map-height order only moved one
//   diagnostic byte and worsened block shape.
// - a binary-backed two-int Map_Dims local restored the proven 8B frame and 301B
//   size; combining it with the observed parameter-home output aliases reached
//   189B strict drift / 88.98% shape. The alias/aggregate form remains diagnostic
//   only because it is compiler-steering rather than canonical source.
// - register-qualified view-top, a local map pointer, and aggregate declaration
//   reordering were codegen duplicates. Restored the natural named-dimension and
//   four bounding-output reconstruction; final validated lead is the same-TU
//   register/frame allocation around the early dimension loads.
// - ABI audit: declared the protected bounding helper with four int& outputs
//   and passed named locals by reference. The call now uses the original
//   ?get_tile_bounding_coords@RGE_View@@IAEXHHAAH000@Z relocation; frame and
//   emitted bytes stayed unchanged at 283B, so no lifetime variant was kept.
// - this pass tested natural two-slot dimension aggregates, scalar dimension
//   scratch reuse, declaration/assignment order, array storage, canonical
//   long map fields, and local map/reference aliases. The best diagnostic
//   shape was 301B/frame 8B/155 strict-drift bytes; its early dimension-load
//   register colors and later loop homes still differ. All probes were
//   restored to this ordinary named-dimension source.
// - continuation probes revisited a typed Map_Dims aggregate, natural helper
//   output owners, coordinate-local storage, and positive bound nesting. The
//   aggregate reached 301B/frame 8B/189 strict-drift bytes, but its early
//   divisor and register topology still differed. Policy-compliant exactness
//   was not found; the pinned named-dimension source is restored below.
// - worker pass: canonical tagRECT ownership for the +0x8C/+0x90 geometry,
//   full RGE_Map layout, nested positive bounds, explicit for-loop updates,
//   map-height/map-width output reuse, parameter-home aliases, canonical long
//   widths, and a map pointer local were tested. Geometry and map surfaces
//   were neutral; nested bounds reached size parity but lost block shape.
// - a dead map-width first helper output with split dimension declarations
//   reached 301B/frame 8B/155 strict drift and 56.14% exact blocks. Inline
//   dimension initialization gave the same result. An explicit <= branch
//   reached 153 drift bytes but reversed the observed branch shape, so it is
//   diagnostic only. Full parameter aliases were not better.
// - structured labs tested declaration order, helper output owner, and 512
//   ambient TU contexts. Eight codegen groups resulted; no exact result or
//   early view-top register recovery occurred. Ambient declarations changed
//   only later bytes and are not source evidence. Natural source is restored.
// - shape-priority continuation retained the binary-supported dead map_w first
//   output and the canonical long map dimensions. The natural while CFG is
//   301B with the original 8B frame, 90.68% shape, 56.14% exact blocks, and
//   155 strict drift bytes. The first mismatch is now the early view-top
//   register color at +0015, not the frame or function boundary.
// - explicit second-loop break and do-loop forms reached 151 strict drift and
//   92.24% shape with 116 instructions, but changed CFG from 9/4 to 10/3 and
//   reduced exact blocks to 53.51%. They are rejected as shape-only forms.
// - coordinate declaration/order, register qualification, long parameter
//   casts, canonical geometry ownership, and four local-order lab variants
//   did not recover the early colors. The natural while form remains current.
// - fresh exact-finish probes tested the decompiler-proven helper aliases:
//   map_height and the incoming long parameter homes receive the four bounding
//   outputs, while the found flag reuses col_out. Direct natural C++ casts
//   preserved the call target but emitted 283-287 bytes without the target's
//   8-byte frame. They were restored. The current source keeps the simpler
//   equivalent output locals until authentic source context supplies a better
//   allocation model.
// FLAGS: /nologo /c /O2 /Oy

#ifndef RGE_VIEW_SHARED_CONTEXT
class RGE_Map {
public:
    virtual ~RGE_Map();
    void* map_data;
    long map_width;    // +0x08
    long map_height;   // +0x0C
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

protected:
    void get_tile_bounding_coords(int col, int diff_col,
                                  int& by1, int& row_out,
                                  int& top_out, int& left_out);

public:
    int Pick_Tile(long px, long py, int* col_out, int* row_out);
};
#endif

int RGE_View::Pick_Tile(long px, long py, int* col_out, int* row_out) {
    int map_h;
    int map_w;
    int by1;
    int bx1;
    map_h = map->map_height;
    map_w = map->map_width;
    bx1 = (map_scr_x_offset - view_left) + px;
    by1 = (map_scr_y_offset - view_top) + py;

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
        int bound_row;
        int bound_top;
        int bound_left;
        get_tile_bounding_coords(tcol, diff, map_w,
                                 bound_row, bound_top, bound_left);
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

// Worker pass sa-36bdddaa (2026-08-23):
// - The pinned natural source was restored after each probe.
// - Full TPanel/render_rect context, decompiler output aliases, map-local
//   declaration permutations, transform order, and period header context did
//   not recover the first ESI/ECX color mismatch.
// - Fresh validation remains a mismatch: 155 positional bytes, one direct
//   helper call, matching frame, and preserved loop and output behavior.
// - Anchor rechecks were blocked after another worker moved Add_GDI_Clip_Mask
//   from accepted_drift to matching while the TU resolver still names the old
//   path. No anchor source was changed here.
