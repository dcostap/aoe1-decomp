// 004BAF20 TShape::shape_mirror_color_trans_clipped
// Shape.cpp
// Attempt log:
// try 1: reconstructed from packet and sibling mirror clipped functions: mirrored RLE decoder with horizontal/vertical clipping and color translation table.
// try 2: modeled TDrawArea fields Bits +8, Height +0x1C, Orien +0x24 and AlignedWidth() pitch call.
// try 3: modeled TShape shape_header at +0x0C and RLE source as header +0x18.
// try 4: implemented positive/negative orientation destination formulas from asm (`y * pitch + x + 1` and `(y - Height + 1) * pitch + x + 1`).
// try 5: implemented top clipped-row skip loop with odd literal packets, zero extended packets, even fill/end packets.
// try 6: implemented right-side clipped band (x > max_x) with state values 1/2/3 and partial translated literal copies.
// try 7: implemented middle in-bounds band with mirrored translated copy loops and translated fill packets via memset.
// try 8: implemented left-side drain loop to consume remaining packets after clipping span.
// try 9: first macro/inlined COPY_TRANS version compiled to equal 863B but broad 91.89% positional diff, first mismatch frame size (`sub esp,20h` vs original `sub esp,8`).
// try 10: changed repeated translated-copy macro to helper function to reduce local pressure; still equal 863B but broad 90.03% positional diff, first mismatch frame size (`sub esp,1Ch` vs original `sub esp,8`).
// try 11: restored the translated literal loops inline so the only external
// calls are the two binary-proven memset sites; the helper-call variant had
// four extra direct calls and could not be structurally compared.
// try 12: restored the unused shape-index parameter proven by the caller and
// ret 24h. The clipped mirror ABI is draw-area, full right/top, shape index,
// left/top/right/bottom clip, then the translation table; the prior source
// omitted the index and consequently shifted every stack home.
// probe notes (sa2fb58d3b_r1_004BAF20):
// - Inlined all four translated-literal loops and restored <string.h> plus
//   pragma function(memset): call set became the binary 1 AlignedWidth + 2
//   memset sites, and the best current build is 955B / 848 strict bytes,
//   56.85% shape, versus the 863B / 0x8-frame oracle.
// - Mutating vertical clip/count homes, separating a persistent row base, and
//   sharing one packet-byte local were each tested and rolled back: they gave
//   no exact frame and either broadened the shape or lost the best basin.
// - Remaining blocker is the original two-local VC5 liveness/parameter-home
//   basin (frame 0x8, width/save-buffer homes), not behavior or call identity.
// shardB3-BAF20: sharing command/count/state locals and reusing clip-y
// parameters as skip/row counters worsened the natural candidate to 1064B,
// removed the frame, and added a third memset call; restored the clean source.
// tried following sibling scratch shapes 004BAC00/004BB280; this variant needs original's tight two-local frame and exact EBX/EBP/ESI/EDI RLE state allocation.
// left in scratch: behavior/call surface is broad, but exact VC5 source shape for the clipped RLE state machine is not recovered. No accepted_drift: broad prologue/register/layout drift.
// shardE-4BAF20 bounded pass:
// - Explicit odd-packet comparisons improved block shape but widened strict
//   drift from 848 to 882 bytes and were restored.
// - One function-scope packet byte reduced the frame to 0xC but widened drift
//   to 905 bytes and was restored. The clean typed candidate remains best.
// - left in scratch: original frame is 0x8 with two locals; current source
//   retains the canonical typed decoder and exact three-call surface.
//
// sa-4bfbd14e bounded pass (2026-08-17; 20 meaningful hypotheses):
// - Baseline was 955B, 0x1C frame, and 848 strict bytes. The three direct
//   calls and their order were exact.
// - A save_buffer/dst split with vertical parameter reuse was worse at 980B.
// - One shared packet byte reached 979B, 0xC, and 875 strict bytes. The split
//   source was restored because shape quality fell.
// - Combining that byte with save_buffer reached 1004B and 959 strict bytes.
// - The full eight-word TShape surface was codegen-identical to baseline.
// - Reusing shape_idx as the crossing-literal counter changed only two bytes.
// - Explicit masked parity tests reached 989B and 882 strict bytes. They gave
//   better block shape but worse positional bytes.
// - Assigning shape_y1 directly from clip_y0 changed one byte and was worse.
// - Reusing clip_y0 for all packet counts reached 902B, 0x14, and 804 strict
//   bytes. This was the best early structural basin.
// - Reusing clip_y1 as the row counter changed that basin to 908B and 814
//   strict bytes. A payload pointer spelling was codegen-identical.
// - Removing fill-byte locals reached the exact 863B size, 0xC frame, and 788
//   strict bytes. This is the retained natural source.
// - Hoisting state and hoisting the count local were codegen-identical.
// - A save_buffer/dst split reached 875B and 801 strict bytes. Splitting the
//   width expression reached 811 strict bytes. Both were restored.
// - The final masked-parity variant reached 881B and 808 strict bytes. It was
//   restored because the direct-test source has better natural size and bytes.
// - The remaining blocker is the original 0x8 frame and its EBX state,
//   parameter-home, and row-tail allocation. Behavior and call identity are
//   otherwise broad. No inline assembly or policy-unsafe form was used.

#ifndef AOE1_SHAPE_CONTEXT_H
typedef unsigned char byte;
#include <string.h>
#pragma function(memset)
extern "C" void* __cdecl memset(void*, int, unsigned int);

struct Shape_Header { long bounds, origin, xmin, ymin, xmax, ymax; };

struct TDrawArea {
    char gap_00[8];
    byte* Bits;
    char gap_0C[0x10];
    long Height;
    char gap_20[4];
    long Orien;
    long AlignedWidth(void);
};

class TShape {
public:
    byte* shape;
    long load_type;
    long load_size;
    Shape_Header* shape_header;
    byte shape_mirror_color_trans_clipped(TDrawArea* draw_area,
                                           long shape_x1, long shape_y1,
                                           long shape_idx, long clip_x0,
                                           long clip_y0, long clip_x1,
                                           long clip_y1, byte* table);
};
#endif

byte TShape::shape_mirror_color_trans_clipped(TDrawArea* draw_area,
                                               long shape_x1, long shape_y1,
                                               long shape_idx, long clip_x0,
                                               long clip_y0, long clip_x1,
                                               long clip_y1, byte* table)
{
    long pitch = draw_area->AlignedWidth() * draw_area->Orien;
    byte* src = (byte*)(this->shape_header + 1);
    byte* dst;

    if (draw_area->Orien < 1) {
        dst = draw_area->Bits + (clip_y0 - draw_area->Height + 1) * pitch + clip_x1 + 1;
    } else {
        dst = draw_area->Bits + clip_y0 * pitch + clip_x1 + 1;
    }

    if (shape_y1 < clip_y0) {
        long skip = clip_y0 - shape_y1;
        shape_y1 += skip;
        do {
            byte done = 0;
            do {
                byte code = *src++;
                if (code & 1) {
                    code >>= 1;
                    if (code != 0) src += code;
                    else ++src;
                } else {
                    if ((code & 0xfe) == 0) done = 1;
                    else ++src;
                }
            } while (!done);
        } while (--skip != 0);
    }

    if (shape_y1 > clip_y1) return 1;
    clip_y1 = clip_y1 - shape_y1 + 1;

    do {
        long xpos = shape_x1;
        byte state;

        if (clip_x1 < xpos) {
            state = 0;
            do {
                byte code = *src++;
                if (code & 1) {
                    clip_y0 = code >> 1;
                    if (clip_y0 == 0) {
                        clip_y0 = *src++;
                        xpos -= clip_y0;
                        if (xpos <= clip_x1) {
                            if (xpos < clip_x0) state = 2;
                            else { dst += xpos - clip_x1; state = 1; }
                        }
                    } else {
                        xpos -= clip_y0;
                        if (xpos <= clip_x1) {
                            if (xpos < clip_x0) {
                                unsigned int cnt = (unsigned char)(clip_x1 - clip_x0 + 1);
                                state = 2;
                                src += xpos - clip_x1 + clip_y0 - 1;
                                while (cnt-- != 0) {
                                    --dst;
                                    *dst = table[*src++];
                                }
                                src += clip_x0 - xpos;
                            } else {
                                unsigned int cnt = (unsigned char)(clip_x1 - xpos);
                                state = 1;
                                src += clip_y0 - cnt;
                                while (cnt-- != 0) {
                                    --dst;
                                    *dst = table[*src++];
                                }
                            }
                        } else src += clip_y0;
                    }
                } else {
                    clip_y0 = code >> 1;
                    if (clip_y0 == 0) state = 3;
                    else {
                        xpos -= clip_y0;
                        if (xpos <= clip_x1) {
                            if (xpos < clip_x0) {
                                unsigned int cnt = (unsigned char)(clip_x1 - clip_x0 + 1);
                                state = 2;
                                dst -= cnt;
                                memset(dst, table[*src], cnt);
                            } else {
                                unsigned int cnt = (unsigned char)(clip_x1 - xpos);
                                state = 1;
                                dst -= cnt;
                                memset(dst, table[*src], cnt);
                            }
                        }
                        ++src;
                    }
                }
            } while (!state);
        } else {
            state = 1;
        }

        state--;
        if (state == 0) {
            do {
                byte code = *src++;
                if (code & 1) {
                    clip_y0 = code >> 1;
                    if (clip_y0 == 0) {
                        clip_y0 = *src++;
                        xpos -= clip_y0;
                        dst -= clip_y0;
                        if (xpos < clip_x0) state = 1;
                    } else {
                        xpos -= clip_y0;
                        if (xpos < clip_x0) {
                            unsigned int cnt = (unsigned char)(xpos - clip_x0 + clip_y0);
                            shape_idx = cnt;
                            state = 1;
                            while (shape_idx-- != 0) {
                                --dst;
                                *dst = table[*src++];
                            }
                            src += clip_y0 - cnt;
                        } else {
                            while (clip_y0-- != 0) {
                                --dst;
                                *dst = table[*src++];
                            }
                        }
                    }
                } else {
                    clip_y0 = code >> 1;
                    if (clip_y0 == 0) state = 3;
                    else {
                        xpos -= clip_y0;
                        if (xpos < clip_x0) {
                            unsigned int cnt = (unsigned char)(xpos - clip_x0 + clip_y0);
                            state = 1;
                            dst -= cnt;
                            memset(dst, table[*src], cnt);
                        } else {
                            dst -= clip_y0;
                            memset(dst, table[*src], clip_y0);
                        }
                        ++src;
                    }
                }
            } while (!state);
        }

        state--;
        if (state == 0) {
            do {
                byte code = *src++;
                if (code & 1) {
                    clip_y0 = code >> 1;
                    if (clip_y0 != 0) src += clip_y0;
                    else ++src;
                } else {
                    if ((code & 0xfe) == 0) state = 2;
                    else ++src;
                }
            } while (!state);
        }

        dst += pitch;
        --clip_y1;
    } while (clip_y1 != 0);

    return 1;
}
