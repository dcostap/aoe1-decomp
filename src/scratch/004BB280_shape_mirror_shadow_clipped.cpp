// 004BB280 TShape::shape_mirror_shadow_clipped
// Shape.cpp
// Attempt log:
// try 1: reconstructed from asm and sibling mirror clipped/shadow unclipped attempts: mirrored RLE decoder with clipping and shadow table.
// try 2: modeled TDrawArea Bits +8, Height +0x1C, Orien +0x24 and AlignedWidth() pitch call.
// try 3: modeled TShape shape_header at +0x0C and RLE source as header + 0x18.
// try 4: implemented negative-orientation destination formula `(y - Height + 1) * pitch + x + 1` and positive `y * pitch + x + 1`.
// try 5: implemented top-row skip loop with odd literal runs, zero extended runs, even skip/end packets.
// try 6: implemented first clipped band (x > max_x) with state values 1/2/3 matching asm's state-style transitions.
// try 7: implemented middle in-bounds band as backward shadow writes `*--dst = table[*dst]`.
// try 8: implemented final off-left drain loop to consume remaining RLE packets after clipped span.
// try 9: used helper function for repeated shadow loop; compiled equal 857B but broad 94.28% diff, first mismatch at frame/prologue (`sub esp,10h` vs `sub esp,8`).
// try 10: replaced helper with macro/inlined shadow loop; still equal 857B but broad 95.33% diff, first mismatch remains prologue/parameter offsets.
// tried preserving sibling source style from 004BAC00 and 004BAAF0; this function needs original's two-local frame and precise ESI/EBX/EDI/EBP roles.
// left in scratch: behavior surface is broad but not exact; no accepted_drift because mismatch is broad from prologue/register allocation and many RLE block layouts.

typedef unsigned char byte;

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
    byte shape_mirror_shadow_clipped(TDrawArea* draw_area, long min_y, long max_y, long min_x, long max_x, long y, long x, byte* table);
};

#define SHADOW_BACK(dst, table, n) do { unsigned int _cnt = (unsigned int)(n); while (_cnt-- != 0) { --(dst); *(dst) = (table)[*(dst)]; } } while (0)
byte TShape::shape_mirror_shadow_clipped(TDrawArea* draw_area, long min_y, long max_y, long min_x, long max_x, long y, long x, byte* table)
{
    long orien = draw_area->Orien;
    long pitch = draw_area->AlignedWidth() * orien;
    Shape_Header* hdr = this->shape_header;
    byte* src = (byte*)(hdr + 1);
    byte* dst;

    if (orien < 1) {
        dst = draw_area->Bits + (y - draw_area->Height + 1) * pitch + x + 1;
    } else {
        dst = draw_area->Bits + y * pitch + x + 1;
    }

    // skip rows above clip
    if (min_y < y) {
        long skip = y - min_y;
        min_y += skip;
        while (skip--) {
            byte done = 0;
            while (!done) {
                byte code = *src++;
                if (code & 1) {
                    code >>= 1;
                    if (code) src += code;
                    else ++src;
                } else {
                    if ((code & 0xfe) == 0) done = 1;
                    else ++src;
                }
            }
        }
    }

    if (min_y > max_y) return 1;
    long rows = max_y - min_y + 1;

    do {
        long xpos = x;
        byte state;

        if (xpos > max_x) {
            state = 0;
            while (!state) {
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
                                SHADOW_BACK(dst, table, cnt);
                                src += min_x - xpos;
                            } else {
                                unsigned int cnt = (unsigned char)(x - xpos);
                                state = 1;
                                src += n - cnt;
                                SHADOW_BACK(dst, table, cnt);
                            }
                        } else src += n;
                    }
                } else {
                    byte n = code >> 1;
                    if (n == 0) state = 3;
                    else {
                        xpos -= n;
                        if (xpos <= max_x) {
                            if (xpos < min_x) {
                                unsigned int cnt = (unsigned char)(max_x - min_x + 1);
                                state = 2;
                                SHADOW_BACK(dst, table, cnt);
                            } else {
                                unsigned int cnt = (unsigned char)(x - xpos);
                                state = 1;
                                SHADOW_BACK(dst, table, cnt);
                            }
                        }
                        ++src;
                    }
                }
            }
        } else {
            state = 1;
        }

        state--;
        if (state == 0) {
            while (!state) {
                byte code = *src++;
                if (code & 1) {
                    byte n = code >> 1;
                    if (n == 0) {
                        n = *src++;
                        xpos -= n;
                        dst -= n;
                        if (xpos < min_x) { state = 1; }
                    } else {
                        xpos -= n;
                        if (xpos < min_x) {
                            unsigned int cnt = (unsigned char)(xpos - min_x + n);
                            state = 1;
                            SHADOW_BACK(dst, table, cnt);
                            src += n;
                        } else {
                            SHADOW_BACK(dst, table, n);
                            src += n;
                        }
                    }
                } else {
                    byte n = code >> 1;
                    if (n == 0) { state = 3; }
                    else {
                        xpos -= n;
                        if (xpos < min_x) {
                            unsigned int cnt = (unsigned char)(xpos - min_x + n);
                            state = 1;
                            SHADOW_BACK(dst, table, cnt);
                        } else {
                            SHADOW_BACK(dst, table, n);
                        }
                        ++src;
                    }
                }
            }
        }

        state--;
        if (state == 0) {
            while (!state) {
                byte code = *src++;
                if (code & 1) {
                    byte n = code >> 1;
                    if (n) src += n;
                    else ++src;
                } else {
                    if ((code & 0xfe) == 0) state = 2;
                    else ++src;
                }
            }
        }

        dst += pitch;
    } while (--rows != 0);

    return 1;
}
