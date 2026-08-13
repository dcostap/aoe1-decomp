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
// sa508a60b0_shape3 probes (2026-08-09):
// - Rechecked the clean typed baseline: 251B/234 strict bytes with both calls
//   and the pretested literal loop aligned, but no local frame.
// - A natural separate `width` row counter assigned after destination setup
//   improved the strict metric to 230B without changing behavior or call set;
//   initializing it earlier instead moved header loads before the save prologue
//   and produced a worse 249B basin. Retained the after-destination form.
// - The remaining structural blocker is the oracle's 8-byte frame and its
//   delayed parameter-home allocation; no ABI or ownership uncertainty remains.
// sa-1a59a700-r1-004B98E0 probes (2026-08-11):
// - Collapsing header height and the post-destination counter into one natural
//   width local recovered the 8-byte frame, but stored width before the call and
//   remained a broad 254-byte mismatch; an area alias and orientation-first
//   spelling were emitted-code duplicates.
// - Split the binary-supported persistent row base from the per-row RLE cursor;
//   this reached exact effective size/frame (268B/8B) with both ordered calls,
//   while the standalone candidate remains 255 differing bytes.  Its remaining
//   mismatch is the setup/home basin: row and byte-count homes are swapped
//   relative to the oracle and literal/table index registers are oppositely
//   colored.  Moving count to setup scope and row declaration order were
//   duplicates.
// - A scoped literal index added 15 bytes and was rolled back; separate cursor
//   increment and period <string.h> context were duplicates/worse (261B).
// - Retained the readable one-width split-row reconstruction.  Calls, RLE CFG,
//   ownership, and effective size/frame are aligned; remaining lead is the
//   original Shape.cpp prologue/local-home/register basin, not behavior.
// orch2-4B98E0-home probes (2026-08-12):
// - Reused td as the persistent row home and p2 as the byte-count home after
//   setup, while capturing td before the delayed header load.  Size/frame and
//   calls stayed aligned, but strict diff stayed 255 and shape fell to 77.78%;
//   rolled back as a worse parameter-reuse basin.
// - A named td capture with delayed header load but natural row/count locals
//   was emitted-code identical to the clean source; rolled back.  The donor
//   home lead is exhausted without a source-quality improvement.
// shardE-4B98E0 probes (2026-08-13):
// - Applied the exact same-TU sibling cursor topology with a persistent typed
//   destination home and byte count.  It improved shape to 92.16% and exact
//   blocks to 73.27%, but remained 255 bytes different; the direct-address
//   variant was 269B/246 diff and retained no canonical source advantage.
// - Reordering pitch/header declarations, palette-index spelling, address
//   terms, and direct-formal aliases produced duplicates or a 283B/263 diff.
//   Restored the clean typed split-row reconstruction; calls and ownership
//   remain exact, while the setup/register basin is unresolved.
// sa7d813de0-r1-shape probes (2026-08-13):
// - Rechecked the paused source and exact Shape.cpp siblings.  Full proven
//   TShape/TDrawArea field surfaces were codegen duplicates; retained them.
// - The natural split statement `*dst = pal[*src]; src++;` and the matching
//   solid-arm cursor order reduce strict drift to 159 bytes at exact size and
//   frame.  Calls, RLE effects, and ownership stay aligned.
// - A diagnostic persistent-row cast through td reached 155 bytes and 91.18%
//   shape, but it is decompiler-shaped parameter-home steering.  The living
//   source keeps the ordinary row pointer instead.
// - Stride-first setup, p2 count reuse, index temporaries, pointer-add table
//   spelling, and redundant area aliases gave duplicates or worse basins.
// - Remaining drift is the original Shape.cpp prologue/register basin and
//   table index/value coloring.  No behavior or call uncertainty remains.
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
    char gap_00[0x08];
    uchar* Bits;           // +0x08
    void* BitmapInfo;      // +0x0C
    void* Bitmap;          // +0x10
    void* OldBitmap;       // +0x14
    int Width;             // +0x18
    int Height;            // +0x1C
    int Pitch;             // +0x20
    int Orien;             // +0x24
    char ClipRect[0x10];   // +0x28
    char _tail_38[0xC8];

    long AlignedWidth();
};

struct TShape {
    uchar* shape;                   // +0x00
    int load_type;                  // +0x04
    int load_size;                  // +0x08
    Shape_Header* shape_header;     // +0x0C
    void* head;                     // +0x10
    void* offsets;                  // +0x14
    void* FShape;                   // +0x18
    void* shape_info;               // +0x1C

    uchar shape_color_trans_unclipped(TDrawArea* td, long p2, long p3, long p4, uchar* pal);
};

uchar TShape::shape_color_trans_unclipped(TDrawArea* td, long p2, long p3, long p4, uchar* pal)
{
    Shape_Header* hdr = this->shape_header;
    long width = (hdr->ymax - hdr->ymin) + 1;
    uchar* src = (uchar*)(hdr + 1);

    long Orien;
    Orien = td->Orien;
    long alw = td->AlignedWidth();
    long stride = alw * Orien;
    uchar count;
    uchar* row;

    long dest_off;
    if (Orien < 1) {
        dest_off = (p3 - td->Height + 1) * stride;
    } else {
        dest_off = p3 * stride;
    }
    row = td->Bits + p2 + dest_off;

    if (width > 0) {
        do {
            uchar done = 0;
            uchar* dst = row;
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
                            *dst = pal[*src];
                            src++;
                            dst++;
                        }
                    }
                } else {
                    count = b >> 1;
                    if (count == 0) {
                        done = 1;
                    } else {
                        memset(dst, pal[*src], count);
                        src++;
                        dst += count;
                    }
                }
            } while (!done);

            row += stride;
        } while (--width);
    }

    return 1;
}
