// 004B9E20 TShape::shape_color_trans_clipped
// Attempt log:
// try 1: reconstructed non-mirrored clipped color-translation RLE draw from packet and sibling shape_draw_clipped/shape_mirror_color_trans_clipped scratch.
// try 2: modeled TDrawArea fields Bits +8, Height +0x1c, Orien +0x24 and AlignedWidth() pitch call.
// try 3: modeled TShape shape_header at +0x0c and RLE source as header +0x18.
// try 4: implemented positive/negative orientation destination formulas from original asm.
// try 5: implemented top-clipped row skip loop with odd literal packets, zero extended skip, even fill/end packets.
// try 6: implemented left-side clipped band with state values and partial translated literal/fill handling.
// try 7: implemented middle in-bounds band with translated literal copies and translated fill packets through memset.
// try 8: implemented right-side drain loop after visible span.
// try 9: validation reaches exact configured size 917B, but broad mismatch (93.2388% positional / 150.0545% edit); first mismatch is frame size 0x28 vs original 0x0c.
// try 10: compared with sibling clipped/color/mirror scratch attempts; same family problem: behavior surface plausible, but VC5 original uses very tight 3-local frame and specific EBX/EBP/ESI/EDI allocation while natural C state machine creates too much local pressure.
// try 11: kept helper copy_trans_fwd rather than macro/inlined version because sibling 004BAF20 showed inline translated-copy worsens frame pressure; still broad and not drift-safe.
// try 12: restored the binary-proven inline translated-copy loops and out-of-line
// memset surface; the original has only AlignedWidth plus two memset calls.
// try 13: restored the omitted shape-index parameter from the caller/PDB ABI and
// mapped the seven long arguments to shape origin plus four clip bounds.
// sa-c8968b7c-r1 probe 1 baseline: the prior helper-call source rebuilt 1126B
// with five calls; retained only as history, not as the living reconstruction.
// probe 2: inlined the translated literal loops and forced the two binary-proven
// memset calls; call set became exact and the candidate fell to 932B.
// probe 3: restored the caller-proven nine-stack-argument ABI (shape index plus
// seven longs); semantics and stack cleanup became exact, with a 949B candidate.
// probe 4/restore: reusing clip-y homes for skip/row counts worsened the basin.
// probe 5: one mutable byte command plus direct table indexing reduced the frame
// to 0x10 and the candidate to 882B, but was retained only as evidence.
// probe 6: replacing the orientation-dependent row tail with `dst += pitch`
// recovered the signed-pitch behavior, exact 0x0c frame, 334 instructions,
// 41 conditional signals, and the best 82.04% shape / 800-byte strict diff.
// probe 7/restore: a separate save_buffer/row-destination split worsened the
// prologue and frame; a function-scope command and a post-setup save_buffer alias
// were likewise rolled back. Current best remains the simple signed-pitch form.
// shardB4-B9E20 layout probe: direct typed save_buffer row-base plus per-row
// destination cursor duplicated prior evidence and worsened to 883 bytes with
// a 0x10 frame; restored the clean signed-pitch source.
// GIVEUP blockers: exact clipped RLE source topology, parameter-slot reuse for min/max/x/y counters, state-byte placement at [esp+34], and register allocation for EDI=src/ESI=dst/EBP=xpos/EDX=min_x. No inline asm used; no accepted_drift proposal.
// luna-4B9E20-r2 control-flow probe: spelling all four parity tests as
// `(command & 1) == 1` matched the original masked compare branches and
// improved block coverage (49.40% to 60.48%) and size (866B to 900B), but
// worsened strict diff (800B to 813B); restored the pinned natural source.

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
    byte shape_color_trans_clipped(TDrawArea* draw_area, long shape_x1, long shape_y1, long shape_idx, long clip_x0, long clip_y0, long clip_x1, long clip_y1, byte* table);
};

byte TShape::shape_color_trans_clipped(TDrawArea* draw_area, long shape_x1, long shape_y1, long shape_idx, long clip_x0, long clip_y0, long clip_x1, long clip_y1, byte* table)
{
    long pitch = draw_area->AlignedWidth() * draw_area->Orien;
    byte* src = (byte*)this->shape_header + 0x18;
    byte* dst;
    if (draw_area->Orien < 1) dst = draw_area->Bits + (clip_y0 - draw_area->Height + 1) * pitch + clip_x0;
    else dst = draw_area->Bits + clip_y0 * pitch + clip_x0;

    if (shape_y1 < clip_y0) {
        long skip = clip_y0 - shape_y1;
        shape_y1 += skip;
        do {
            byte done = 0;
            do {
                byte command = *src++;
                if (command & 1) {
                    command >>= 1;
                    if (command) src += command;
                    else ++src;
                } else {
                    if ((command & 0xfe) == 0) done = 1;
                    else ++src;
                }
            } while (!done);
        } while (--skip != 0);
    }

    if (shape_y1 > clip_y1) return 1;
    long rows = clip_y1 - shape_y1 + 1;

    do {
        long xpos = shape_x1;
        byte state;
        if (xpos < clip_x0) {
            state = 0;
            do {
                byte command = *src++;
                if (command & 1) {
                    command >>= 1;
                    if (command == 0) {
                        command = *src++;
                        xpos += command;
                        if (xpos >= clip_x0) {
                            if (xpos > clip_x1) state = 2;
                            else { dst += xpos - clip_x0; state = 1; }
                        }
                    } else {
                        xpos += command;
                        if (xpos >= clip_x0) {
                            if (xpos > clip_x1) {
                                unsigned int cnt = clip_x1 - clip_x0 + 1;
                                state = 2;
                                src += clip_x0 - xpos + command;
                                byte* end = dst + cnt;
                                while (dst < end) *dst++ = table[*src++];
                                src += command - (clip_x0 - xpos + command) - cnt;
                            } else {
                                unsigned int cnt = xpos - clip_x0;
                                state = 1;
                                src += command - cnt;
                                byte* end = dst + cnt;
                                while (dst < end) *dst++ = table[*src++];
                            }
                        } else src += command;
                    }
                } else {
                    command >>= 1;
                    if (command == 0) state = 3;
                    else {
                        xpos += command;
                        if (xpos >= clip_x0) {
                            if (xpos > clip_x1) {
                                unsigned int cnt = clip_x1 - clip_x0 + 1;
                                state = 2;
                                memset(dst, table[*src], cnt);
                                dst += cnt;
                            } else {
                                unsigned int cnt = xpos - clip_x0;
                                state = 1;
                                memset(dst, table[*src], cnt);
                                dst += cnt;
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
                byte command = *src++;
                if (command & 1) {
                    command >>= 1;
                    if (command == 0) {
                        command = *src++;
                        xpos += command;
                        dst += command;
                        if (xpos > clip_x1) state = 1;
                    } else {
                        xpos += command;
                        if (xpos > clip_x1) {
                            unsigned int cnt = command + clip_x1 - xpos + 1;
                            state = 1;
                            byte* end = dst + cnt;
                            while (dst < end) *dst++ = table[*src++];
                            dst += command - cnt;
                            src += command - cnt;
                        } else {
                            byte* end = dst + command;
                            while (dst < end) *dst++ = table[*src++];
                        }
                    }
                } else {
                    command >>= 1;
                    if (command == 0) state = 3;
                    else {
                        xpos += command;
                        if (xpos > clip_x1) {
                            unsigned int cnt = command + clip_x1 - xpos + 1;
                            state = 1;
                            memset(dst, table[*src], cnt);
                            dst += command;
                        } else {
                            memset(dst, table[*src], command);
                            dst += command;
                        }
                        ++src;
                    }
                }
            } while (!state);
        }

        state--;
        if (state == 0) {
            do {
                byte command = *src++;
                if (command & 1) {
                    command >>= 1;
                    if (command) src += command;
                    else ++src;
                } else {
                    if ((command & 0xfe) == 0) state = 2;
                    else ++src;
                }
            } while (!state);
        }
        dst += pitch;
    } while (--rows != 0);
    return 1;
}
