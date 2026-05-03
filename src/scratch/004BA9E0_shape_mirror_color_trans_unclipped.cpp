// 004BA9E0 TShape::shape_mirror_color_trans_unclipped (Shape.cpp:1878-1939, 265B)
// RLE color-translated mirror shape rendering. Complex RLE state machine.
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt notes:
// - Prologue: push ecx (1 local = stride). My version has sub esp,8 from extra locals.
//   Stack slot reuse: original reuses param_1 slot for height counter,
//   param_2 for dest ptr, param_3 for count temp, bl(ebx) for eol flag.
// - memset inlining: VC5 inlines memset into rep stosd/stosb (~40 bytes setup+fill).
//   #pragma function(memset) ignored by VC5 optimizer.
//   Original has: call memset; add esp,0Ch (~11 bytes).
// - Color-translated multi-pixel loop: original uses ecx for index (direct table lookup),
//   mine uses memory spill for index. Register pressure different.
// - Goto control flow partially matches but block layout differs.
//   The "noInc" (skip in_ptr++) path uses different jump targets.
// - Remaining ~93% positional diff. Candidate for focused variant lab work:
//   * Reduce locals to force push ecx / parameter slot reuse
//   * Fix memset to call via extern function pointer  
//   * Match color-index through ecx (not dumped to [esp+10h])

#include <string.h>

struct TDrawArea {
    char gap_00[0x08];
    /* +0x08 */ unsigned char* Bits;
    char gap_0C[0x1C - 0x0C];
    /* +0x1C */ int Height;
    /* +0x20 */ int Pitch;
    /* +0x24 */ int Orien;

    long AlignedWidth();
};

struct Shape_Header {
    long bounds;
    long origin;
    long xmin;
    long ymin;
    long xmax;
    long ymax;
};

struct TShape {
    char gap_00[0x0C];
    /* +0x0C */ Shape_Header* shape_header;

    unsigned char shape_mirror_color_trans_unclipped(
        TDrawArea* draw_area, long x, long y, long shape_idx,
        unsigned char* table);
};

unsigned char TShape::shape_mirror_color_trans_unclipped(
    TDrawArea* draw_area, long x, long y, long shape_idx,
    unsigned char* table)
{
    long stride = draw_area->AlignedWidth() * draw_area->Orien;
    long height = shape_header->ymax - shape_header->ymin + 1;
    unsigned char* in = (unsigned char*)(shape_header + 1);
    unsigned char* dest;

    if (draw_area->Orien < 1) {
        dest = draw_area->Bits + ((y - draw_area->Height) + 1) * stride + x + 1;
    } else {
        dest = draw_area->Bits + stride * y + x + 1;
    }

    while (height > 0) {
        unsigned char eol = 0;
        do {
            unsigned char cmd = *in;
            in++;
            if (cmd & 1) {
                cmd >>= 1;
                if (cmd == 0) {
                    dest -= *in;
                } else {
                    do {
                        dest--;
                        cmd--;
                        *dest = table[*in];
                        in++;
                    } while (cmd != 0);
                    goto skip_advance;
                }
            } else {
                cmd >>= 1;
                if (cmd == 0) {
                    eol = 1;
                    goto skip_advance;
                }
                dest -= cmd;
                {
                    unsigned char val = table[*in];
                    unsigned int cnt = cmd;
                    unsigned char* dp = dest;
                    do {
                        *dp = val;
                        dp++;
                        cnt--;
                    } while (cnt != 0);
                }
            }
            in++;
skip_advance:;
        } while (eol == 0);
        dest += stride;
        height--;
    }

    return 1;
}
