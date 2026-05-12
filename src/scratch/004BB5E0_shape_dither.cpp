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
//
// BLOCKER: Multiple mismatch sources compound:
// 1. sub esp, 0x18 vs 0x14 (4B extra locals)
// 2. VC5 zero-initializes a local (xor ebx; mov [esp+1Ch],ebx) not in original
// 3. Return-value extension (mov bl,al; and ebx,0FFh; mov al,bl)
// 4. VC5 over-optimizes bounds checks (shorter code than original)
// 5. Stack-frame slot assignment differs from original param-slot reuse

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

struct Shape_Info { long shape; long flags; };

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
    Shape_Info* offsets;        // +0x14

    uchar Check_shape(long shape_num, char* msg);
    uchar shape_dithered_unclipped(TDrawArea* area, long x, long y, long param_5, long param_6);
    uchar shape_dithered_clipped(TDrawArea* area, long shape_x1, long shape_y1, long clip_x1, long clip_y1, long clip_x2, long clip_y2, long param_5, long param_6);
    uchar shape_dither(TDrawArea* area, long x, long y, long shape_num, long param_5, long param_6);
};

extern char s_RGL_shape_draw[];

uchar TShape::shape_dither(TDrawArea* area, long x, long y, long shape_num, long param_5, long param_6)
{
    if (Check_shape(shape_num, s_RGL_shape_draw) != 0) {
        return 0;
    }

    Shape_Header* header = (Shape_Header*)(this->shape + this->offsets[shape_num].shape);
    this->shape_header = header;

    long sx1 = x + header->xmin;
    long sy1 = y + header->ymin;
    long sx2 = x + header->xmax;
    long sy2_orig = y + header->ymax;

    x = sx1;
    shape_num = sy1;
    y = sx2;
    long sy2 = sy2_orig;
    long clip_left = area->ClipRect.left;
    long clip_top = area->ClipRect.top;
    long clip_right = area->ClipRect.right;
    long clip_bottom = area->ClipRect.bottom;

    if (x < clip_left) x = clip_left;
    if (shape_num < clip_top) shape_num = clip_top;
    if (y > clip_right) y = clip_right;
    if (sy2 > clip_bottom) sy2 = clip_bottom;
    if (x < 0) x = 0;
    if (shape_num < 0) shape_num = 0;
    if (y >= area->Width) y = area->Width - 1;
    if (sy2 >= area->Height) sy2 = area->Height - 1;

    if (x > y || shape_num > sy2) {
        return 0;
    }

    if (x == sx1 && shape_num == sy1 && y == sx2 && sy2 == sy2_orig) {
        return shape_dithered_unclipped(area, sx1, sy1, param_5, param_6);
    }

    return shape_dithered_clipped(area, sx1, sy1, x, shape_num, y, sy2, param_5, param_6);
}
