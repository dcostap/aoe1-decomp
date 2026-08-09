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
    char gap_0C[0x10];
    int Height;
    char gap_20[4];
    int Orien;
    long AlignedWidth();
};

// Main-agent audit confirmed canonical non-polymorphic shape/draw-area ownership
// and retained the natural typed RLE decoder.
struct TShape {
    byte* shape;
    int load_type;
    int load_size;
    Shape_Header* shape_header;
    char _gap_10[0xC];

    byte shape_shadow_unclipped(TDrawArea* da, long x, long y, byte* table);
};

byte TShape::shape_shadow_unclipped(TDrawArea* da, long x, long y, byte* table)
{
    Shape_Header* sh = shape_header;
    byte* p = (byte*)(sh + 1);
    long height = sh->ymax - sh->ymin + 1;
    long orien = da->Orien;
    long rows;
    long width;
    byte* save_buffer;

    width = da->AlignedWidth() * orien;

    long tmp;
    if (orien < 1)
        tmp = ((y - da->Height) + 1) * width;
    else
        tmp = y * width;

    save_buffer = da->Bits + tmp + x;
    byte* row = save_buffer;

    if (height > 0) {
        rows = height;
        do {
            save_buffer = row;
            byte done = 0;

            do {
                byte command = *p++;

                if ((command & 1) == 1) {
                    command >>= 1;
                    if (command == 0) {
                        save_buffer += *p++;
                    } else {
                        byte* e = save_buffer + (command & 0xFF);
                        while (save_buffer < e) {
                            *save_buffer = table[*save_buffer];
                            save_buffer++;
                        }
                        p += command;
                    }
                } else {
                    command >>= 1;
                    if (command == 0) {
                        done = 1;
                    } else {
                        byte* e = save_buffer + (command & 0xFF);
                        while (save_buffer < e) {
                            *save_buffer = table[*save_buffer];
                            save_buffer++;
                        }
                        p++;
                    }
                }
            } while (!done);

            row += width;
        } while (--rows);
    }

    return 1;
}
