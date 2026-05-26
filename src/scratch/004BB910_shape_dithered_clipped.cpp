// VA: 004BB910 TShape::shape_dithered_clipped
// Shape.cpp lines 2902-3243
// Attempt log:
// try 1: adapted shape_dithered_unclipped skeleton with clipping bounds and packet-observed RLE/dither phases; default /O2 too small (.text 656 vs 1321), because helper stayed out-of-line/logic under-modeled.
// try 2: macro-expanded ZERO_DITHER; default /O2 still too small (.text 624), worse due optimization.
// try 3: /Od reached only .text 1179 vs 1321, still too small; rolled back.
// try 4: /O1 much too small (.text 498), rolled back.
// try 5: no /Oy (/O2 only) unchanged at .text 624, rolled back.
// left in scratch: coarse behavior skeleton only. The original is a hand-shaped/large clipped RLE+dither loop with many source-line-shaped cases; current source is not close enough for accepted_drift or comparison.

typedef unsigned char uchar;
struct Shape_Header { long bounds; long origin; long xmin; long ymin; long xmax; long ymax; };
class TDrawArea { public: char gap_00[8]; uchar* Bits; char gap_0C[0x10]; long Height; char gap_20[4]; long Orien; long AlignedWidth(); };
class TShape { public: uchar* shape; int load_type; int load_size; Shape_Header* shape_header; uchar shape_dithered_clipped(TDrawArea* area, long x, long y, long clip_left, long clip_top, long clip_right, long clip_bottom, long p8, long p9); };

#define ZERO_DITHER(DST, N, PAR) do { \
    if (PAR) { --(N); ++(DST); } \
    (PAR) = (uchar)((N) & 1); \
    uchar* zd_end = (DST) + (N); \
    while ((DST) < zd_end) { *(DST) = 0; (DST) += 2; } \
    if (PAR) --(DST); \
} while (0)

uchar TShape::shape_dithered_clipped(TDrawArea* area, long x, long y, long clip_left, long clip_top, long clip_right, long clip_bottom, long p8, long p9)
{
    long pitch = area->AlignedWidth() * area->Orien;
    uchar* src = (uchar*)(this->shape_header + 1);
    long rows = this->shape_header->ymax - this->shape_header->ymin + 1;
    uchar* dst;
    if (area->Orien < 1) dst = area->Bits + x + (y - area->Height + 1) * pitch;
    else dst = area->Bits + x + y * pitch;

    uchar parity = (uchar)((p8 + x) & 1);
    if (((p9 + y) & 1) != 0) parity = (uchar)(parity != 1);

    long row = clip_top;
    if (row < y) {
        long skip = y - row;
        row += skip;
        while (skip--) {
            uchar done = 0;
            while (!done) {
                uchar c = *src++;
                if (c & 1) { c >>= 1; if (c) src += (unsigned int)c; else src += (unsigned int)(*src) + 1; }
                else { c >>= 1; if (!c) done = 1; else ++src; }
            }
        }
    }

    if (row > clip_bottom) return 1;
    long right = clip_right;
    long left = clip_left;
    for (; row <= clip_bottom; ++row) {
        uchar lineParity = (uchar)(parity != 1);
        long col = x;
        uchar done = 0;
        while (!done) {
            uchar cmd = *src++;
            if (cmd & 1) {
                unsigned int count = cmd >> 1;
                if (count == 0) {
                    count = *src++;
                    col += count;
                    dst += count;
                    if (count & 1) parity = (uchar)(parity != 1);
                } else {
                    long endx = col + count;
                    if (endx > left && col <= right) {
                        unsigned int draw = count;
                        if (col < left) { unsigned int d = left - col; dst += d; src += d; draw -= d; col = left; }
                        if (col + (long)draw - 1 > right) draw = right - col + 1;
                        ZERO_DITHER(dst, draw, parity);
                        src += count - (col - (endx - (long)count));
                    } else { src += count; dst += count; }
                    col = endx;
                }
            } else {
                unsigned int count = cmd >> 1;
                if (count == 0) done = 1;
                else {
                    long endx = col + count;
                    if (endx > left && col <= right) {
                        unsigned int draw = count;
                        if (col < left) { unsigned int d = left - col; dst += d; draw -= d; col = left; }
                        if (col + (long)draw - 1 > right) draw = right - col + 1;
                        ZERO_DITHER(dst, draw, parity);
                    } else dst += count;
                    ++src;
                    col = endx;
                }
            }
        }
        dst += pitch;
        parity = lineParity;
    }
    return 1;
}
