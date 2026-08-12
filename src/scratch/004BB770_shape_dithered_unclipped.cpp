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

typedef unsigned char uchar;
struct Shape_Header { long bounds; long origin; long xmin; long ymin; long xmax; long ymax; };
class TDrawArea { public: char gap_00[8]; uchar* Bits; char gap_0C[0x10]; long Height; char gap_20[4]; long Orien; long AlignedWidth(); };
class TShape { public: uchar* shape; int load_type; int load_size; Shape_Header* shape_header; uchar shape_dithered_unclipped(TDrawArea* area, long x, long y, long param_5, long param_6); };

uchar TShape::shape_dithered_unclipped(TDrawArea* area, long x, long y, long param_5, long param_6)
{
    long pitch;
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

    pitch = area->AlignedWidth() * area->Orien;
    sh = this->shape_header;
    height = sh->ymax - sh->ymin + 1;
    src = (uchar*)(sh + 1);

    if (area->Orien < 1) {
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
            dst = save_buffer;
            next_parity = (parity != 1);
            done = 0;
            do {
                cmd = *src++;
                if ((cmd & 1) == 1) {
                    count = (uchar)(cmd >> 1);
                    param_5 = count;
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
                            param_5 = count;
                        }
                        run = (unsigned int)count;
                        end = dst + run;
                        run = ((unsigned int)count) & 1;
                        while (dst < end) { *dst = 0; dst += 2; }
                        if (run != 0) { dst--; }
                        src += (unsigned int)param_5;
                    }
                } else {
                    count = (uchar)(cmd >> 1);
                    if (count == 0) {
                        done = 1;
                    } else {
                        if (parity != 0) {
                            count--;
                            dst++;
                            param_5 = count;
                        } else {
                            param_5 = count;
                        }
                        run = (unsigned int)param_5;
                        end = dst + run;
                        run = ((unsigned int)param_5) & 1;
                        while (dst < end) { *dst = 0; dst += 2; }
                        if (run != 0) { dst--; }
                        src++;
                    }
                }
            } while (!done);
            save_buffer += pitch;
            parity = next_parity;
        } while (--height);
    }
    return 1;
}
