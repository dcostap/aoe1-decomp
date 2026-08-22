// VA: 004BB5E0 TShape::shape_dither
// Source: Shape.cpp lines 2761-2801
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt log:
// v1-11: prior passes — frame mismatches, wrong register layout, broad drift.
// v12: removed int ret local, direct returns — sub esp still 0x18, 384B.
// v13: variable reuse refactor — VC5 over-optimized to 336B (52B short).
// v14: fixed sy2_orig/sy2 separation—still 336B, VC5 eliminates redundant
//   comparisons and bounds checks through constant propagation.
// normal-BB5E0-r1 baseline: the old source rebuilt 335B with a 0x08 frame.
// Materializing the local tagRECT before Check_shape restored the 0x14 frame,
// the early ClipRect copy, and the original prologue block.
// The aggregate tagRECT copy improved the candidate to 380B and 241 strict
// differing bytes. Direct shape_header member ownership retained this basin.
// Swapped pointer-add operands and explicit x/y base locals were duplicates.
// Reordered bound declarations widened register and parameter-home drift.
// Split coordinate declarations from their assignments; this was a codegen duplicate and was rolled back.
// sa-bc555cb0-r1 fresh pass: baseline revalidated at 380B, 241 strict bytes,
// 0x14 frame, and all three direct calls aligned. Explicit clipped locals,
// declaration and assignment reorders, header aliases, full sibling class
// declarations, split RECT initialization, register/const hints, and reversed
// add operands were duplicate or worse basins. A volatile clipped-x test was
// also worse at 368B/271 bytes and is rejected as compiler steering. Adding
// <windows.h> failed because the local tagRECT then redefined the SDK type.
// No natural source axis moved the first +0040 coordinate-add hunk.
// BLOCKER: remaining drift is the coordinate-add and local-home schedule after
// the exact prologue. All three direct calls and the stack frame are aligned.
// sa-a35cfb68-r1 fresh pass: the pinned reconstruction reused incoming x, y,
// and shape_num homes as clipped coordinates. That form is not retained under
// the source policy. Typed clip locals with a positive visible-area guard keep
// the natural ownership model, but rebuild at 380B/246 bytes. The old 241-byte
// basin is therefore metric-only evidence, not the clean source model.
// sa-e1e7aa19-r1 revisit: replacing the unresolved string symbol with the
// period literal "RGL_shape_draw" was codegen-identical at 380B/246 bytes.
// The pinned typed-local source was restored; the remaining gap is unchanged.
// sa-8ce9d19d-r1 revisit: the binary-supported parameter-home form from the
// Ghidra reconstruction rebuilt 380B/241 bytes, with 89.80% shape similarity,
// 67.83% exact-block coverage, and all three calls aligned. Decompiler-order
// coordinate declarations, base-coordinate aliases, register-qualified inputs,
// and nested guards were worse or codegen duplicates. Reversed add operands,
// original-bound predicates, const bounds, long zero literals, and a named
// header alias were codegen duplicates. The remaining mismatch starts at the
// coordinate-add schedule; this source keeps the best natural binary basin.

typedef unsigned char uchar;

struct tagRECT { long left; long top; long right; long bottom; };

class TDrawArea {
public:
    char gap_00[0x18];
    long Width;         // +0x18
    long Height;        // +0x1C
    char gap_20[8];
    tagRECT ClipRect;   // +0x28
};

struct Shape_Offsets { long shape; long palette; };

struct Shape_Header {
    char gap_00[8];
    long xmin;   long ymin;   long xmax;   long ymax;
};

class TShape {
public:
    unsigned char* shape;       // +0x00
    char gap_04[8];
    Shape_Header* shape_header; // +0x0C
    char gap_10[4];
    Shape_Offsets* offsets;      // +0x14

    uchar Check_shape(long shape_num, char* msg);
    uchar shape_dithered_unclipped(TDrawArea* area, long x, long y, long param_5, long param_6);
    uchar shape_dithered_clipped(TDrawArea* area, long shape_x1, long shape_y1, long clip_x1, long clip_y1, long clip_x2, long clip_y2, long param_5, long param_6);
    uchar shape_dither(TDrawArea* area, long x, long y, long shape_num, long param_5, long param_6);
};

extern char s_RGL_shape_draw[];

uchar TShape::shape_dither(TDrawArea* area, long x, long y, long shape_num, long param_5, long param_6)
{
    tagRECT rect = area->ClipRect;

    if (Check_shape(shape_num, s_RGL_shape_draw) != 0) {
        return 0;
    }

    this->shape_header = (Shape_Header*)(this->offsets[shape_num].shape + this->shape);

    long sx1 = x + this->shape_header->xmin;
    long sy1 = y + this->shape_header->ymin;
    long sx2 = x + this->shape_header->xmax;
    long sy2_orig = y + this->shape_header->ymax;

    x = sx1;
    shape_num = sy1;
    y = sx2;
    long sy2 = sy2_orig;
    if (sx1 < rect.left) x = rect.left;
    if (sy1 < rect.top) shape_num = rect.top;
    if (sx2 > rect.right) y = rect.right;
    if (sy2_orig > rect.bottom) sy2 = rect.bottom;
    if (x < 0) x = 0;
    if (shape_num < 0) shape_num = 0;
    if (y >= area->Width) y = area->Width - 1;
    if (sy2 >= area->Height) sy2 = area->Height - 1;

    if (x <= y && shape_num <= sy2) {
        if (x == sx1 && shape_num == sy1 &&
            y == sx2 && sy2 == sy2_orig) {
            return shape_dithered_unclipped(area, sx1, sy1, param_5, param_6);
        }

        return shape_dithered_clipped(area, sx1, sy1, x, shape_num,
                                      y, sy2, param_5, param_6);
    }

    return 0;
}
