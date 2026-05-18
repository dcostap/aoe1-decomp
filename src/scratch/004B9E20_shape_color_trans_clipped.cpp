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
// GIVEUP blockers: exact clipped RLE source topology, parameter-slot reuse for min/max/x/y counters, state-byte placement at [esp+34], and register allocation for EDI=src/ESI=dst/EBP=xpos/EDX=min_x. No inline asm used; no accepted_drift proposal.

typedef unsigned char byte;
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
    byte shape_color_trans_clipped(TDrawArea* draw_area, long min_y, long min_x, long max_x, long y, long x, long max_y, byte* table);
};

static void copy_trans_fwd(byte*& dst, byte*& src, byte* table, unsigned int n) {
    while (n-- != 0) { *dst++ = table[*src++]; }
}

byte TShape::shape_color_trans_clipped(TDrawArea* draw_area, long min_y, long min_x, long max_x, long y, long x, long max_y, byte* table)
{
    long pitch = draw_area->AlignedWidth() * draw_area->Orien;
    byte* src = (byte*)this->shape_header + 0x18;
    byte* dst;
    if (draw_area->Orien < 1) dst = draw_area->Bits + (y - draw_area->Height + 1) * pitch + x;
    else dst = draw_area->Bits + y * pitch + x;

    if (min_y < y) {
        long skip = y - min_y;
        min_y += skip;
        do {
            byte done = 0;
            do {
                byte code = *src++;
                if (code & 1) {
                    byte n = code >> 1;
                    if (n) src += n;
                    else ++src;
                } else {
                    if ((code & 0xfe) == 0) done = 1;
                    else ++src;
                }
            } while (!done);
        } while (--skip != 0);
    }

    if (min_y > max_y) return 1;
    long rows = max_y - min_y + 1;

    do {
        long xpos = x;
        byte state;
        if (xpos < min_x) {
            state = 0;
            do {
                byte code = *src++;
                if (code & 1) {
                    byte n = code >> 1;
                    if (n == 0) {
                        n = *src++;
                        xpos += n;
                        if (xpos >= min_x) {
                            if (xpos > max_x) state = 2;
                            else { dst += xpos - min_x; state = 1; }
                        }
                    } else {
                        xpos += n;
                        if (xpos >= min_x) {
                            if (xpos > max_x) {
                                unsigned int cnt = max_x - min_x + 1;
                                long skip2 = min_x - xpos + n;
                                state = 2;
                                src += skip2;
                                copy_trans_fwd(dst, src, table, cnt);
                                src += n - skip2 - cnt;
                            } else {
                                unsigned int cnt = xpos - min_x;
                                state = 1;
                                src += n - cnt;
                                copy_trans_fwd(dst, src, table, cnt);
                            }
                        } else src += n;
                    }
                } else {
                    byte n = code >> 1;
                    if (n == 0) state = 3;
                    else {
                        xpos += n;
                        if (xpos >= min_x) {
                            byte c = table[*src];
                            if (xpos > max_x) {
                                unsigned int cnt = max_x - min_x + 1;
                                state = 2;
                                memset(dst, c, cnt);
                                dst += cnt;
                            } else {
                                unsigned int cnt = xpos - min_x;
                                state = 1;
                                memset(dst, c, cnt);
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
                byte code = *src++;
                if (code & 1) {
                    byte n = code >> 1;
                    if (n == 0) {
                        n = *src++;
                        xpos += n;
                        dst += n;
                        if (xpos > max_x) state = 1;
                    } else {
                        xpos += n;
                        if (xpos > max_x) {
                            unsigned int cnt = n + max_x - xpos + 1;
                            state = 1;
                            copy_trans_fwd(dst, src, table, cnt);
                            dst += n - cnt;
                            src += n - cnt;
                        } else {
                            copy_trans_fwd(dst, src, table, n);
                        }
                    }
                } else {
                    byte n = code >> 1;
                    if (n == 0) state = 3;
                    else {
                        byte c = table[*src++];
                        xpos += n;
                        if (xpos > max_x) {
                            unsigned int cnt = n + max_x - xpos + 1;
                            state = 1;
                            memset(dst, c, cnt);
                            dst += n;
                        } else {
                            memset(dst, c, n);
                            dst += n;
                        }
                    }
                }
            } while (!state);
        }

        state--;
        if (state == 0) {
            do {
                byte code = *src++;
                if (code & 1) {
                    byte n = code >> 1;
                    if (n) src += n;
                    else ++src;
                } else {
                    if ((code & 0xfe) == 0) state = 2;
                    else ++src;
                }
            } while (!state);
        }
        if (draw_area->Orien < 1) dst -= pitch;
        else dst += pitch;
    } while (--rows != 0);
    return 1;
}
