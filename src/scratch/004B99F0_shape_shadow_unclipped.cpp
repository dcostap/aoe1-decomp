// 004B99F0 TShape::shape_shadow_unclipped
// Shape.cpp:909-972, 254 bytes
//
// uchar __thiscall TShape::shape_shadow_unclipped(TDrawArea* da, long x, long y, unsigned char* table)
// ret 10h cleanup (4 params on stack, this in ecx)
//
// === Attempt log ===
//
// Prior attempts established the RLE ownership and the draw-area layout, but
// left a broad prologue/register mismatch.
//
// sa-8a8d0053-r1 probes:
// - A zero-case-first spelling for both command kinds recovered the original
//   out-of-line copy-loop topology (shape 79.44%, 228 differing bytes).
// - Scoping done inside the natural outer row do/while was codegen-identical;
//   the emitted byte flag remains in AL rather than the original BL.
// - Reordering orientation before the row-count declaration improved the
//   emitted basin to 82.24% shape / 227 differing bytes and preserved the
//   PDB-supported call set; the remaining first hunk is setup register/home
//   allocation (ymax/ymin/orientation and delayed destination spill).
// - PDB local evidence was checked: one packed-byte command local, width, and
//   save_buffer are present. Combining cmd/cnt as command, splitting width
//   declaration from assignment, declaring save_buffer separately, and
//   restoring canonical TShape/TDrawArea names were duplicate codegen basins.
//
// Best retained reconstruction: typed Shape_Header payload plus ordinary
// byte-stream RLE decoding, zero-first branch layout, and named destination.
// Left in scratch: original setup expects ymax->ESI/ymin->EDI/orientation->EBX,
// stores destination through [esp+1Ch], and stores rows through [esp+18h];
// current VC5 standalone output keeps the same behavior/calls but differs in
// that local topology from the Shape.cpp original.
//
// sa-78979d2a-shadow probes (2026-08-09):
// - Separating header height from the post-destination row counter improved
//   the setup to 210 strict bytes; moving orientation after height improved it
//   to 209. These are retained as the clean source direction.
// - Splitting a persistent row base from the per-row working cursor improved
//   the emitted candidate to 255B/188 strict bytes and 89.00% shape; reusing
//   save_buffer for the working cursor was codegen-identical.
// - Direct orientation, declaration-order, and x-home assignment probes did
//   not improve the 188-byte basin. Remaining gap is the original swapped
//   parameter-home/register schedule, not calls or RLE behavior.
// sa-43841f2d-shape-shadow-unclipped probes (2026-08-09):
// - Restored the full proven TShape/TDrawArea header, clip, and tail spans;
//   the natural source stayed 255B/188 diff with the direct long-return
//   TDrawArea::AlignedWidth ABI from donor 00444B40.
// - No new header/span/clip/source-family lead displaced the typed forward
//   shadow RLE source; remaining drift is the documented prologue/home basin.
// orch-shape-fresh-03 probes (2026-08-10):
// - A focused 18-case lab over orientation, destination, and outer-cursor
//   spellings found no exact variant; the best invariant-preserving family
//   was 254B/176 diff but used a duplicated destination expression.
// - The natural direct-orientation/direct-destination form with one persistent
//   base pointer and an inner row cursor reached 254B/176 diff, 90% shape,
//   and exact size; it is retained below as the best readable reconstruction.
// - Reusing the x parameter as a 32-bit destination accumulator reproduced the
//   observed x-home and inner-loop topology (254B/106 diff after declaration
//   ordering), but is decompiler-shaped and was rolled back rather than kept
//   solely for metrics. No call, RLE, or ownership uncertainty remains.
// - Final bounded validation leaves the remaining gap in the standalone VC5
//   prologue/register basin; next lead is original Shape.cpp TU context, not
//   further opaque destination-home steering.

typedef unsigned char byte;

struct Shape_Header {
    long bounds;
    long origin;
    long xmin;
    long ymin;
    long xmax;
    long ymax;
};

struct TDrawArea {
    char gap_00[8];
    byte* Bits;
    void* BitmapInfo;
    void* Bitmap;
    void* OldBitmap;
    int Width;
    int Height;
    int Pitch;
    int Orien;
    char ClipRect[0x10];
    char _tail_38[0xC8];
    long AlignedWidth();
};

// Main-agent audit confirmed canonical non-polymorphic shape/draw-area ownership
// and retained the natural typed RLE decoder.
struct TShape {
    byte* shape;
    int load_type;
    int load_size;
    Shape_Header* shape_header;
    void* head;
    void* offsets;
    void* FShape;
    void* shape_info;

    byte shape_shadow_unclipped(TDrawArea* da, long x, long y, byte* table);
};

byte TShape::shape_shadow_unclipped(TDrawArea* da, long x, long y, byte* table)
{
    Shape_Header* sh = shape_header;
    byte* p = (byte*)(sh + 1);
    long height = sh->ymax - sh->ymin + 1;
    long rows;
    long width;
    byte* save_buffer;

    width = da->AlignedWidth() * da->Orien;

    if (da->Orien < 1)
        save_buffer = da->Bits + ((y - da->Height) + 1) * width + x;
    else
        save_buffer = da->Bits + y * width + x;

    if (height > 0) {
        rows = height;
        do {
            byte* dst = save_buffer;
            byte done = 0;

            do {
                byte command = *p++;

                if ((command & 1) == 1) {
                    command >>= 1;
                    if (command == 0) {
                        dst += *p++;
                    } else {
                        byte* e = dst + (command & 0xFF);
                        while (dst < e) {
                            *dst = table[*dst];
                            dst++;
                        }
                        p += command;
                    }
                } else {
                    command >>= 1;
                    if (command == 0) {
                        done = 1;
                    } else {
                        byte* e = dst + (command & 0xFF);
                        while (dst < e) {
                            *dst = table[*dst];
                            dst++;
                        }
                        p++;
                    }
                }
            } while (!done);

            save_buffer += width;
        } while (--rows);
    }

    return 1;
}
