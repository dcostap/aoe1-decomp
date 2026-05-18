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
// tried following sibling scratch shapes 004BAC00/004BB280; this variant needs original's tight two-local frame and exact EBX/EBP/ESI/EDI RLE state allocation.
// left in scratch: behavior/call surface is broad, but exact VC5 source shape for the clipped RLE state machine is not recovered. No accepted_drift: broad prologue/register/layout drift.

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
    byte shape_mirror_color_trans_clipped(TDrawArea* draw_area, long min_y, long max_y, long min_x, long max_x, long y, long x, byte* table);
};

static void copy_trans(byte*& dst, byte*& src, byte* table, unsigned int n) {
    while (n-- != 0) { --dst; *dst = table[*src++]; }
}

byte TShape::shape_mirror_color_trans_clipped(TDrawArea* draw_area, long min_y, long max_y, long min_x, long max_x, long y, long x, byte* table)
{
    long orien = draw_area->Orien;
    long pitch = draw_area->AlignedWidth() * orien;
    byte* src = (byte*)this->shape_header + 0x18;
    byte* dst;

    if (orien < 1) {
        dst = draw_area->Bits + (y - draw_area->Height + 1) * pitch + x + 1;
    } else {
        dst = draw_area->Bits + y * pitch + x + 1;
    }

    if (min_y < y) {
        long skip = y - min_y;
        min_y += skip;
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

    if (min_y > max_y) return 1;
    long rows = max_y - min_y + 1;

    do {
        long xpos = x;
        byte state;

        if (xpos > max_x) {
            state = 0;
            do {
                byte code = *src++;
                if (code & 1) {
                    byte n = code >> 1;
                    if (n == 0) {
                        n = *src++;
                        xpos -= n;
                        if (xpos <= max_x) {
                            if (xpos < min_x) state = 2;
                            else { dst += xpos - x; state = 1; }
                        }
                    } else {
                        xpos -= n;
                        if (xpos <= max_x) {
                            if (xpos < min_x) {
                                unsigned int cnt = (unsigned char)(max_x - min_x + 1);
                                state = 2;
                                src += xpos - min_x + n - 1;
                                copy_trans(dst, src, table, cnt);
                                src += min_x - xpos;
                            } else {
                                unsigned int cnt = (unsigned char)(x - xpos);
                                state = 1;
                                src += n - cnt;
                                copy_trans(dst, src, table, cnt);
                            }
                        } else src += n;
                    }
                } else {
                    byte n = code >> 1;
                    if (n == 0) state = 3;
                    else {
                        xpos -= n;
                        if (xpos <= max_x) {
                            byte c = table[*src];
                            if (xpos < min_x) {
                                unsigned int cnt = (unsigned char)(max_x - min_x + 1);
                                state = 2;
                                dst -= cnt;
                                memset(dst, c, cnt);
                            } else {
                                unsigned int cnt = (unsigned char)(x - xpos);
                                state = 1;
                                dst -= cnt;
                                memset(dst, c, cnt);
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
                        xpos -= n;
                        dst -= n;
                        if (xpos < min_x) state = 1;
                    } else {
                        xpos -= n;
                        if (xpos < min_x) {
                            unsigned int cnt = (unsigned char)(xpos - min_x + n);
                            state = 1;
                            copy_trans(dst, src, table, cnt);
                            src += n - cnt;
                        } else {
                            copy_trans(dst, src, table, n);
                        }
                    }
                } else {
                    byte n = code >> 1;
                    if (n == 0) state = 3;
                    else {
                        byte c = table[*src];
                        xpos -= n;
                        if (xpos < min_x) {
                            unsigned int cnt = (unsigned char)(xpos - min_x + n);
                            state = 1;
                            dst -= cnt;
                            memset(dst, c, cnt);
                        } else {
                            dst -= n;
                            memset(dst, c, n);
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
                    byte n = code >> 1;
                    if (n != 0) src += n;
                    else ++src;
                } else {
                    if ((code & 0xfe) == 0) state = 2;
                    else ++src;
                }
            } while (!state);
        }

        dst += pitch;
    } while (--rows != 0);

    return 1;
}
