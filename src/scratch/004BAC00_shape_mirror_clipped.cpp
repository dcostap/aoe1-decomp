// 004BAC00 TShape::shape_mirror_clipped
// Attempt log:
// try 1: reconstructed mirrored clipped RLE draw from original asm: compute mirrored dest pointer, skip top rows, process left/right clipping bands and middle rows.
// try 2: modeled TDrawArea fields Bits +8, Height +0x1c, Orien +0x24 and AlignedWidth call; prologue/call surface compile.
// try 3: modeled source start as shape_header +0x18 from asm load of this+0xc then add 0x18.
// try 4: modeled mirrored destination pointer for positive/negative orientation using x+1 and y/height adjustment.
// try 5: implemented top-row RLE skip loop with odd literal runs, even fill/end packets, and zero-length extended literal.
// try 6: implemented vertical clipping count max_y-row+1 and early max_y rejection.
// try 7: implemented left/right horizontal clipping states 1/2/3 corresponding to original bl state transitions.
// try 8: used memcpy-like byte loops for mirrored literal copies (*--dst = *src++), matching behavioral direction.
// try 9: used memset for fill packets to match original memset calls at 0x54DA60.
// try 10: /GX probe had no effect; removed. Current reconstruction compiles 640B vs original 799B, meaning several source branches/loops are still over-factored or behavior missing.
// left in scratch: major behavior surface is reconstructed but code is too compact and not diffable/exact; not accepted_drift-safe.

typedef unsigned char uchar;
extern "C" void* __cdecl memset(void*, int, unsigned int);

class TDrawArea { public: char pad0[8]; uchar* Bits; char padC[0x10]; long Height; char pad20[4]; long Orien; long AlignedWidth(); };
class TShape { public: void* shape; int load_type; int load_size; uchar* shape_header; void shape_mirror_clipped(long,long,long,long,long,long,TDrawArea*); };

void TShape::shape_mirror_clipped(long min_y,long max_y,long min_x,long max_x,long y,long x,TDrawArea* area)
{
    long pitch = area->AlignedWidth() * area->Orien;
    uchar* src = this->shape_header + 0x18;
    uchar* dst;
    if (area->Orien < 1) dst = area->Bits + (y - area->Height + 1) * pitch + x + 1;
    else dst = area->Bits + y * pitch + x + 1;

    long row = min_y;
    if (row < y) {
        long skip = y - row;
        row += skip;
        while (skip--) {
            uchar done = 0;
            while (!done) {
                uchar code = *src++;
                if (code & 1) { uchar n = code >> 1; if (n) src += n; else src++; }
                else { if ((code & 0xfe) == 0) done = 1; else src++; }
            }
        }
    }
    if (row > max_y) return;
    long rows = max_y - row + 1;
    long left = min_x;
    long right = max_x;
    while (rows--) {
        long xpos = x;
        uchar state = 0;
        while (!state) {
            uchar code = *src++;
            if (code & 1) {
                uchar n = code >> 1;
                if (!n) { n = *src++; xpos -= n; if (xpos <= left) { if (xpos < right) state = 2; else { dst += xpos - x; state = 1; } } }
                else {
                    xpos -= n;
                    if (xpos <= left) {
                        if (xpos < right) {
                            long cnt = left - right + 1;
                            long adj = xpos - x + n;
                            state = 2;
                            src += adj - 1;
                            while ((uchar)cnt--) *--dst = *src++;
                            src += right - xpos;
                        } else {
                            long cnt = x - xpos;
                            state = 1;
                            src += n - cnt;
                            while ((uchar)cnt--) *--dst = *src++;
                        }
                    } else src += n;
                }
            } else {
                uchar n = code >> 1;
                if (!n) state = 3;
                else { xpos -= n; if (xpos <= left) { state = (xpos < right) ? 2 : 1; memset(dst - ((xpos < right) ? (left-right+1) : (x-xpos)), *src, (xpos < right) ? (left-right+1) : (x-xpos)); } src++; }
            }
        }
        if (state == 1) {
            while (!state) {}
        }
        if (area->Orien < 1) dst -= pitch; else dst += pitch;
        while (state == 2) {
            uchar code = *src++;
            if (code & 1) { uchar n = code >> 1; if (n) src += n; else src++; }
            else { if ((code & 0xfe) == 0) state = 3; else src++; }
        }
    }
}
