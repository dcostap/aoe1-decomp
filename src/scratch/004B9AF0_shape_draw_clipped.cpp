// 004B9AF0 TShape::shape_draw_clipped
// Attempt log:
// try 1: reconstructed non-mirrored clipped RLE draw from asm, analogous to shape_mirror_clipped but forward destination/copies.
// try 2: modeled TDrawArea fields Bits +8, Height +0x1c, Orien +0x24 and AlignedWidth call; call surface compiles.
// try 3: modeled source start as shape_header +0x18 from asm `mov edi,[this+0xc]; add edi,18h`.
// try 4: modeled destination pointer for positive/negative orientation using x/y and height adjustment; source still allocates too many locals.
// try 5: implemented top-row RLE skip loop with odd literal runs, even fill/end packets, and zero-length extended literal.
// try 6: modeled vertical clip count rewrite `rows = max_y - cur_y + 1` and early `cur_y > max_y` return.
// try 7: implemented left-clipped pre-band using state byte 0/1/2/3 and memcpy/memset calls matching original helper families.
// try 8: implemented middle visible band with literal memcpy and fill memset, including right-edge truncation.
// try 9: implemented right-side skip band after state transition, preserving packet consumption until end-of-line.
// try 10: /GX probe had no effect; removed. Current source reaches exact configured size 813B but prologue/frame/local topology is wrong (0x1c frame vs original 0x08), with broad mismatch from offset 2.
// left in scratch: behavior surface is plausible but over-local/incorrect source topology; not accepted_drift-safe.

typedef unsigned char uchar;
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);

class TDrawArea { public: char pad0[8]; uchar* Bits; char padC[0x10]; long Height; char pad20[4]; long Orien; long AlignedWidth(); };
class TShape { public: void* shape; int load_type; int load_size; uchar* shape_header; unsigned char shape_draw_clipped(TDrawArea*,long,long,long,long,long,long); };

unsigned char TShape::shape_draw_clipped(TDrawArea* area,long min_y,long min_x,long max_x,long y,long x,long rows)
{
    long pitch = area->AlignedWidth() * area->Orien;
    uchar* src = this->shape_header + 0x18;
    uchar* dst;
    if (area->Orien < 1) dst = area->Bits + (y - area->Height + 1) * pitch + x;
    else dst = area->Bits + y * pitch + x;

    long cur_y = min_y;
    if (cur_y < y) {
        long skip = y - cur_y;
        cur_y += skip;
        while (skip--) {
            uchar done = 0;
            while (!done) {
                uchar code = *src++;
                if (code & 1) { uchar n = code >> 1; if (n) src += n; else src++; }
                else { if ((code & 0xfe) == 0) done = 1; else src++; }
            }
        }
    }
    if (cur_y > rows) return 1;
    rows = rows - cur_y + 1;
    while (rows--) {
        long xpos = x;
        uchar state;
        if (min_x >= xpos) state = 1; else state = 0;
        while (state == 0) {
            uchar code = *src++;
            if (code & 1) {
                uchar n = code >> 1;
                if (!n) { n = *src++; xpos += n; if (xpos >= min_x) { if (xpos > max_x) state = 2; else { dst += xpos - min_x; state = 1; } } }
                else {
                    xpos += n;
                    if (xpos >= min_x) {
                        if (xpos > max_x) {
                            long cnt = max_x - min_x + 1;
                            uchar* p = src + min_x - xpos + n;
                            state = 2;
                            memcpy(dst, p, cnt);
                            dst += cnt;
                            src += n;
                        } else {
                            long cnt = xpos - min_x;
                            state = 1;
                            memcpy(dst, src + n - cnt, cnt);
                            dst += cnt;
                            src += n;
                        }
                    } else src += n;
                }
            } else {
                uchar n = code >> 1;
                if (!n) state = 3;
                else { xpos += n; if (xpos >= min_x) { long cnt; state = (xpos > max_x) ? 2 : 1; cnt = (xpos > max_x) ? (max_x - min_x + 1) : (xpos - min_x); memset(dst, *src, cnt); dst += cnt; } src++; }
            }
        }
        state--;
        if (state == 0) {
            while (state == 0) {
                uchar code = *src++;
                if (code & 1) {
                    uchar n = code >> 1;
                    if (!n) { n = *src++; xpos += n; dst += n; if (xpos > max_x) state = 1; }
                    else { xpos += n; if (xpos > max_x) { long cnt = n + max_x - xpos + 1; memcpy(dst, src, cnt); dst += n; src += n; state = 1; } else { memcpy(dst, src, n); dst += n; src += n; } }
                } else {
                    uchar n = code >> 1;
                    if (!n) state = 3;
                    else { xpos += n; if (xpos > max_x) { long cnt = n + max_x - xpos + 1; memset(dst, *src, cnt); dst += n; state = 1; } else { memset(dst, *src, n); dst += n; } src++; }
                }
            }
        }
        state--;
        if (state == 0) {
            while (state == 0) {
                uchar code = *src++;
                if (code & 1) { uchar n = code >> 1; if (n) src += n; else src++; }
                else { if ((code & 0xfe) == 0) state = 2; else src++; }
            }
        }
        dst = (area->Orien < 1) ? (dst - pitch) : (dst + pitch);
    }
    return 1;
}
