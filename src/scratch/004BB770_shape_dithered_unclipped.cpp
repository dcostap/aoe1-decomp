// VA: 004BB770 TShape::shape_dithered_unclipped
// Shape.cpp lines 2805-2898
// Attempt log:
// 1: decompiler-shaped source with explicit locals: too short (384 B), push-ecx one-local frame.
// 2: parameter-slot reuse/lower-local form got two-local sub esp,8 frame but much worse register/order drift (91.6% pos).
// 3: delayed pitch multiply was 400 B but push-ecx frame, still broad drift.
// 4: return to best decompiler shape plus dummy local still 400 B, too short.
// 5: volatile dummy forced comparable 404-byte output but store before AlignedWidth shifts first mismatch to offset 18; broad drift.
// tried flags /O1, no /Oy, /Ox, /Ob0: /O1 too short, others same as /O2.
// left in scratch: behavior modeled, but VC5 register/stack-slot allocation for the RLE+dither loop is still broad; not accepted_drift-safe.
// sa508a60b0_shape4 probes (2026-08-09):
// - Replaced the diagnostic volatile dummy with a binary-supported persistent
//   save_buffer row base and a separate working destination; this preserves the
//   proven row reset behavior and yields a 0x8 frame, 405B output, and 343
//   strict differing bytes (versus 404B/364 for the dummy baseline).
// - A single height counter and delayed save_buffer initialization were tested;
//   the direct orientation/save-buffer candidate remained the best natural
//   source. Split pitch arithmetic and a named row-offset temporary worsened
//   the basin and were discarded. Remaining gap is broad VC5 register/home and
//   RLE block scheduling, not behavior or the AlignedWidth ABI.
// normal-BB770-r1 probes (2026-08-12):
// - The exact mirror-sibling row topology without the current dither local
//   surface lost the call/frame basin (355B, 385 strict bytes); restored.
// - Making the PDB-proven done flag a byte improved shape, but alone reached
//   399B/350 strict bytes. Mapping fill length through x's home also worsened
//   the natural candidate (370B/349); both changes are not retained alone.
// - Removing save_buffer in favor of x as the row base was a 395B/346-byte
//   basin and did not recover the target homes; restored the named row base.
// - Reversing the even-command test to keep the zero terminator inline matched
//   the oracle block layout and exact 404-byte size (320 strict bytes).
// - Combining that CFG with byte done reached 398B/326 strict bytes and is
//   retained because the oracle writes done as a byte. Swapping old/next parity
//   roles improved edit shape but reached 342 strict bytes and was restored.
// - Reordering locals to the same-TU donor family was codegen-identical. The
//   remaining gap is the early VC5 register/home schedule and height/pitch
//   coloring; calls, frame size, CFG count, and RLE effects are aligned.
// sa262083c2-shape probes (2026-08-12):
// - Splitting orientation and AlignedWidth evaluation, reusing pitch for the
//   orientation, and initializing shape_header before pitch all worsened the
//   prologue or frame; restored the clean source.
// - A while outer loop, explicit row-counter copy, signed int height, and
//   local declaration reorder were duplicate or worse basins; restored.
// - Final lead remains the original source's height/pitch register coloring
//   and save_buffer home, with calls, frame, CFG count, and RLE behavior known.
// shardE-4BB770 probes (2026-08-13):
// - Moving the payload cursor before the height expression improved the clean
//   source from 326 to 324 strict bytes; it did not change the broad setup.
// - A long done flag plus that payload order reached the prior 404-byte basin,
//   then improved it to 318 bytes; this diagnostic source was not retained
//   because the oracle's done home is byte-width and the natural source uses
//   the proven byte flag.
// - Splitting aligned width, copying rows, and local declaration reordering
//   were worse or duplicate basins. Reversed pitch terms were duplicate.
// - Restored the natural typed byte-RLE source. Remaining gap is the early
//   pitch/height/source register coloring and save_buffer home allocation.
// orch-4BB770-a probe (2026-08-13):
// - Split the command count from the fill count to test the oracle's distinct
//   byte homes and first structural loop hunk. Exact-block coverage improved
//   from 32.88% to 42.47%, but size fell to 391B and strict diff worsened to
//   349B. Restored the clean source. The next lead remains source/TU context
//   for the early pitch/height and parameter-home schedule.
// sa-d8797fda-r1 probes (2026-08-16):
// - Restored the canonical full TShape/TDrawArea field surfaces and moved the
//   payload cursor before the height expression. These are codegen-neutral.
// - Diagnostic reuse of the x and p5 parameter homes produced 404B, the 0x8
//   frame, the aligned AlignedWidth call, and 305 strict differing bytes.
// - A 64-sample ambient VC5 declaration sweep was codegen-identical. Narrow
//   pitch, orientation, and height types, declaration reordering, and a local
//   row-counter copy were duplicate or worse. Reversed zero/nonzero branches
//   worsened the block layout. The remaining gap is early register/home
//   allocation and parity/destination spill placement.
// sa-127fa25c-r1 probes (2026-08-17):
// - Restored the pinned typed source and rebuilt it: 404B, 0x8 frame, one
//   AlignedWidth call, and 305 strict differing bytes remain.
// - Main review removed parameter-home reuse. The metric-closer 404-byte form
//   was compiler steering. The living source keeps ordinary count locals.
// sa-51969701-r1 probes (2026-08-17):
// - Reordering the row-base declaration was codegen-identical.
// - Scoping skip and nonzero-run count locals was natural but worsened the
//   frame to 0xC and reached 381B/345 strict bytes; restored.
// - Assigning the persistent row base directly in orientation arms reached
//   391B/341 strict bytes and a slightly closer block basin, but remained a
//   broad nonexact source family; restored.
// - Materializing the working cursor once before parity setup returned to the
//   389B/347-byte basin. No policy-valid exact source was found.
// sa-54e2dadc-r1 probes (2026-08-22):
// - A separate row counter inside the positive-height guard removed the 0x8
//   frame and reached 382B/389 strict bytes; restored.
// - Binary-supported x and p5 count-home reuse reproduced the prior 404B/305B
//   diagnostic basin. It was a duplicate compiler-steering form; restored.
// - Explicit terminator continues, shared packet-tail labels, mutable command
//   bytes, and a split payload cursor were duplicate or worse basins.
// - Direct sibling-style setup and row-tail declaration orders were duplicate
//   or worse. Moving row-base initialization before parity kept 347B but added
//   one exact block only; the clean source remains the smallest natural form.
// - Final clean validation: 389B/347 strict bytes, 0x8 frame, one ordered
//   AlignedWidth call, and 32.88% exact-block coverage. The blocker remains
//   early VC5 register/home allocation and parity/destination spill placement.

typedef unsigned char uchar;
struct Shape_Header { long bounds; long origin; long xmin; long ymin; long xmax; long ymax; };
class TDrawArea {
public:
    char gap_00[8];
    uchar* Bits;
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
class TShape {
public:
    uchar* shape;
    int load_type;
    int load_size;
    Shape_Header* shape_header;
    void* head;
    void* offsets;
    void* FShape;
    void* shape_info;
    uchar shape_dithered_unclipped(TDrawArea* area, long x, long y, long param_5, long param_6);
};

uchar TShape::shape_dithered_unclipped(TDrawArea* area, long x, long y, long param_5, long param_6)
{
    long pitch;
    long orientation;
    Shape_Header* sh;
    long height;
    uchar* src;
    uchar* dst;
    uchar* save_buffer;
    long parity;
    long next_parity;
    long run;
    uchar done;
    uchar cmd;
    uchar count;
    uchar* end;

    orientation = area->Orien;
    pitch = area->AlignedWidth() * orientation;
    sh = this->shape_header;
    src = (uchar*)(sh + 1);
    height = sh->ymax - sh->ymin + 1;

    if (orientation < 1) {
        dst = area->Bits + x + (y - area->Height + 1) * pitch;
    } else {
        dst = area->Bits + x + y * pitch;
    }

    parity = (param_5 + x) & 1;
    if (((param_6 + y) & 1) != 0) {
        parity = (parity != 1);
    }

    save_buffer = dst;
    if (height > 0) {
        do {
            next_parity = (parity != 1);
            done = 0;
            do {
                cmd = *src++;
                if ((cmd & 1) == 1) {
                    count = (uchar)(cmd >> 1);
                    if (count == 0) {
                        count = *src;
                        dst += (unsigned int)count;
                        if ((count & 1) != 0) {
                            parity = (parity != 1);
                        }
                        src++;
                    } else {
                        if (parity != 0) {
                            count--;
                            dst++;
                        }
                        run = (unsigned int)count;
                        end = dst + run;
                        run = ((unsigned int)count) & 1;
                        while (dst < end) { *dst = 0; dst += 2; }
                        if (run != 0) { dst--; }
                        src += (unsigned int)count;
                    }
                } else {
                    count = (uchar)(cmd >> 1);
                    if (count == 0) {
                        done = 1;
                    } else {
                        if (parity != 0) {
                            count--;
                            dst++;
                        }
                        run = (unsigned int)count;
                        end = dst + run;
                        run = ((unsigned int)count) & 1;
                        while (dst < end) { *dst = 0; dst += 2; }
                        if (run != 0) { dst--; }
                        src++;
                    }
                }
            } while (!done);
            save_buffer += pitch;
            dst = save_buffer;
            parity = next_parity;
        } while (--height);
    }
    return 1;
}
