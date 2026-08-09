// VA: 004B98E0, TShape::shape_color_trans_unclipped, 268 bytes
// Source: Shape.cpp lines 841-905
// Status: SCRATCH — behavior and call set are reconstructed; remaining drift is
// the VC5 prologue/local-home/register basin and broad instruction placement.
//
// Known from the executable: TShape+0x0C is the Shape_Header, the payload starts
// at hdr+1, TDrawArea fields are Bits+0x08/Height+0x1C/Orien+0x24, and the RLE
// stream has literal, skip, solid, and end-of-row commands.  The repeat arm is
// a real memset call.  The pretested literal loop is retained because the binary
// has an initial destination/end compare before its copy body.
//
// Attempt log:
// - baseline: natural typed RLE reconstruction, but manual solid fill omitted
//   the binary memset call (193B, 259 differing bytes).
// - restored the external C memset surface with #pragma function(memset): calls
//   became 2/2 aligned and the candidate grew to 245B (254 differing bytes).
// - negative-first orientation dispatch improved setup/CFG (247B, 233 diff).
// - one shared byte count across command arms recovered parameter-slot reuse
//   (same size, 232 diff); typed Shape_Header and row-guard declaration were
//   canonical cleanup/duplicate basins.
// - changed the literal run to a pretested `while (dst < end)` as required by
//   the observed initial `cmp/jae`; current natural candidate is 251B, 234
//   differing bytes, 100% ordered calls, 9/9 conditional CFG signals.
// - setup declaration/order variants were codegen duplicates.  Remaining lead:
//   recover the original 8-byte local frame and early saved-register coloring;
//   do not replace this typed source with raw cursor/volatile scaffolding.
// FLAGS: /nologo /c /O2 /Oy

extern "C" void* __cdecl memset(void*, int, unsigned int);

#pragma function(memset)

typedef unsigned char uchar;

struct Shape_Header {
    long bounds;
    long origin;
    long xmin;
    long ymin;
    long xmax;
    long ymax;
};

struct TDrawArea {
    char _pad_00[0x08];
    uchar* Bits;           // +0x08
    char _pad_0C[0x10];
    int Height;            // +0x1C
    int Pitch;             // +0x20
    int Orien;             // +0x24

    long AlignedWidth();
};

struct TShape {
    char _pad_00[0x0C];
    Shape_Header* shape_header;    // +0x0C

    uchar shape_color_trans_unclipped(TDrawArea* td, long p2, long p3, long p4, uchar* pal);
};

uchar TShape::shape_color_trans_unclipped(TDrawArea* td, long p2, long p3, long p4, uchar* pal)
{
    Shape_Header* hdr = this->shape_header;
    long height = (hdr->ymax - hdr->ymin) + 1;
    uchar* src = (uchar*)(hdr + 1);

    long Orien;
    Orien = td->Orien;
    long alw = td->AlignedWidth();
    long stride = alw * Orien;
    long remaining;

    long dest_off;
    if (Orien < 1) {
        dest_off = (p3 - td->Height + 1) * stride;
    } else {
        dest_off = p3 * stride;
    }
    uchar* dst = td->Bits + p2 + dest_off;

    if (height > 0) {
        remaining = height;
        do {
            uchar done = 0;
            uchar count;
            do {
                uchar b = *src++;
                if ((b & 1) == 1) {
                    count = b >> 1;
                    if (count == 0) {
                        dst += *src;
                        src++;
                    } else {
                        uchar* end = dst + count;
                        while (dst < end) {
                            *dst = pal[*src++];
                            dst++;
                        }
                    }
                } else {
                    count = b >> 1;
                    if (count == 0) {
                        done = 1;
                    } else {
                        memset(dst, pal[*src], count);
                        dst += count;
                        src++;
                    }
                }
            } while (!done);

            dst += stride;
        } while (--remaining);
    }

    return 1;
}
