// 004BA9E0 TShape::shape_mirror_color_trans_unclipped (Shape.cpp:1878-1939, 265B)
// RLE color-translated mirror shape rendering.
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt notes:
// - Baseline natural reconstruction used the CRT header and a nested goto-shaped
//   decoder; it was 218B and the optimizer inlined memset (259 differing bytes).
// - A donor-shaped reconstruction with one shared offset, rows, destination, and
//   byte-count local, plus a plain external memset declaration, produced the
//   correct two-call surface and 236B/199 differing bytes after the explicit
//   `(command & 1) == 1` predicate probe.
// - Direct destination formation in both orientation arms is period-plausible and
//   follows the original branch topology, but VC5 drops the expected push-ecx
//   local and is a worse 235B/262-byte basin. Reverted to the better shared-offset
//   reconstruction.
// - Remaining drift is structural setup/home placement (original direct orientation
//   arms and width local), plus localized table-index SIB operand order; calls,
//   RLE control flow, stack cleanup, and field ownership are aligned.

void* __cdecl memset(void* dest, int c, unsigned int count);

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
    long pitch = draw_area->AlignedWidth() * draw_area->Orien;
    Shape_Header* sh = this->shape_header;
    long height = sh->ymax - sh->ymin + 1;
    unsigned char* p = (unsigned char*)(sh + 1);
    long m;
    if (draw_area->Orien < 1)
        m = (y - draw_area->Height + 1) * pitch;
    else
        m = y * pitch;
    long rows;
    unsigned char* d;
    d = draw_area->Bits + m + x + 1;
    unsigned char c;

    if (height > 0) {
        rows = height;
        do {
            unsigned char done = 0;
            do {
                unsigned char b = *p++;
                if ((b & 1) == 1) {
                    c = b >> 1;
                    if (c == 0) {
                        d -= *p;
                        p++;
                    } else {
                        while (c > 0) {
                            *--d = table[*p++];
                            c--;
                        }
                    }
                } else {
                    c = b >> 1;
                    if (c == 0) {
                        done = 1;
                    } else {
                        unsigned char t = table[*p];
                        d -= c;
                        memset(d, t, c);
                        p++;
                    }
                }
            } while (!done);
            d += pitch;
        } while (--rows);
    }

    return 1;
}
