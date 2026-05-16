// VA: 00438820 DibBlt
// Attempt log:
// try 1: direct C reconstruction from original asm control flow, using DibGetInfo/Clip helper surfaces and explicit nearest-neighbor loops.
// try 2: mapped stack parameters from original offsets: dst info/bits/rect/x/y/w/h, src info/bits/x/y/w/h, dst/src orientation, transparent flag.
// try 3: modeled optional ClipDibBitsToRect call with address-taken x/y/w/h parameters before DibGetInfo.
// try 4: modeled destination orientation adjustment by negating dstY when source orientation flag is present.
// try 5: modeled exact-scale/non-transparent fast path with row memcpy loop.
// try 6: modeled non-transparent x-index table generation at 0x62D238 in forward order.
// try 7: modeled transparent x-index table generation in reverse order.
// try 8: modeled scaled nested draw loop with y fixed-point accumulator and per-pixel indexed copy.
// try 9: /GX tested; no useful change, removed.
// try 10: /Od tested; exact-size but wrong debug-basin codegen, removed.
// try 11: leaving in scratch: clean source is 624B vs original 632B and broad stack/register/control-shape drift remains, not accepted_drift-safe.

typedef unsigned char BYTE;
struct BITMAPINFO256 { char data[1]; };
struct RECT { long left; long top; long right; long bottom; };
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern "C" int __cdecl ClipDibBitsToRect(BITMAPINFO256*, BYTE*, long*, long*, long*, long*, BITMAPINFO256*, BYTE*, long*, long*, long*, long*, short, short);
extern "C" void __cdecl DibGetInfo(BITMAPINFO256*, long*, long*, long*);
extern int dib_x_index[1024];

void __cdecl DibBlt(BITMAPINFO256* dstInfo, BYTE* dstBits, RECT* clipRect,
                    long dstX, long dstY, long dstW, long dstH,
                    BITMAPINFO256* srcInfo, BYTE* srcBits,
                    long srcX, long srcY, long srcW, long srcH,
                    short dstOrient, short srcOrient, short transparent)
{
    long DestOrien;
    long DestTotHgt;
    long local_4;
    long SrcOrien;
    long SrcTotHgt;
    long SrcWidth;

    if (srcInfo != 0) {
        if (!ClipDibBitsToRect(dstInfo, dstBits, &dstX, &dstY, &dstW, &dstH,
                               srcInfo, srcBits, &srcX, &srcY, &srcW, &srcH,
                               dstOrient, srcOrient)) {
            return;
        }
    }

    DibGetInfo(dstInfo, &DestOrien, &DestTotHgt, &local_4);
    DibGetInfo(srcInfo, &SrcOrien, &SrcTotHgt, &SrcWidth);
    if (srcOrient != 0) {
        dstY = -dstY;
    }

    long xfrac = (srcW << 8) / dstW;
    long yfrac = (srcH << 8) / dstH;
    BYTE* dst;
    if (DestOrien == 1) {
        dst = dstBits + dstX + dstY * DestTotHgt;
    } else {
        dst = dstBits + dstX + (DestTotHgt - dstY - 1) * DestOrien;
    }

    if (xfrac == 0x100 && yfrac == 0x100 && transparent == 0) {
        BYTE* src;
        if (SrcOrien == 1) {
            src = srcBits + srcX + srcY * SrcTotHgt;
        } else {
            src = srcBits + srcX + (SrcTotHgt - srcY - 1) * SrcOrien;
        }
        long dstStep = DestOrien * DestTotHgt;
        long srcStep = SrcOrien * SrcTotHgt;
        for (long y = 0; y < dstH; y++) {
            memcpy(dst, src, dstW);
            dst += dstStep;
            src += srcStep;
        }
        return;
    }

    if (transparent == 0) {
        long accum = srcX;
        if (dstW > 0) {
            for (long i = 0; i < dstW; i++) {
                dib_x_index[i] = accum >> 8;
                accum += xfrac;
            }
        }
    } else {
        long accum = srcX;
        if (dstW > 0) {
            for (long i = dstW - 1; i >= 0; i--) {
                dib_x_index[i] = accum >> 8;
                accum += xfrac;
            }
        }
    }

    long yacc = srcY << 8;
    for (long y = 0; y < dstH; y++) {
        long sy;
        if (SrcOrien == 1) {
            sy = yacc >> 8;
        } else {
            sy = SrcTotHgt - (yacc >> 8) - 1;
        }
        BYTE* srcrow = srcBits + srcX + sy * SrcWidth;
        for (long x = 0; x < dstW; x++) {
            dst[x] = srcrow[dib_x_index[x]];
        }
        yacc += yfrac;
        dst += DestOrien * DestTotHgt;
    }
}
