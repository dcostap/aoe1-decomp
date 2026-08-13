// VA 00438AA0 TransDibBlt
// Dib.cpp:155-273
// Attempt log:
// 1-8: Reconstructed the fast path, positive ClipDibBlt gate, fixed-point scaling,
//      SrcXTbl setup, LineInfo copy/transparent path, and full-width fallback with
//      typed BITMAPINFO256/RECT/TRANSINFO surfaces.
// 9: Forced the proven direct memcpy call using the same-TU windows.h/pragma
//    context; this fixed the call target/count but not the function topology.
// 10: Named destination-info and original flip-Y values across the clip call;
//     this recovered the original pre-guard loads and improved the best build to
//     619 differing bytes (63.3572%), 5/5 calls, 0x10 frame, 956/977 bytes.
// 11: Function-scope alias hoisting made the prologue broadly worse and was
//     rolled back; swapping the two out-local declarations was codegen-neutral.
// 12: ABI evidence for Dib.cpp shows ClipDibBlt/GetDibDim use long-reference
// parameters (AAJ in the original symbols), not long-pointer parameters (PAJ).
// Switched these local declarations and calls to the period reference surface;
// the parameter-home aliases for dstInfo and flipY remain binary-proven.
// GIVEUP: best natural source remains in scratch.  The unresolved gap is VC5
// parameter-home/local-slot scheduling around GetDibDim and the long blit loops;
// no accepted_drift because the remaining positional drift is broad.

#include <windows.h>

typedef unsigned char uchar;
struct BITMAPINFO256 {
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD bmiColors[256];
};
struct LINEINFO_00438AA0 { int skip; int copy; int first; int last; };
struct TRANSINFO_00438AA0 { int AnyTrans; char gap_04[0x10]; LINEINFO_00438AA0* LineInfo; };

extern long SrcXTbl[];
#pragma function(memcpy)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
void __cdecl DibBlt(BITMAPINFO256*, uchar*, RECT*, long,long,long,long, BITMAPINFO256*, uchar*, long,long,long,long,int,int,int);
int __cdecl ClipDibBlt(BITMAPINFO256*, RECT*, long&, long&, long&, long&, long&, long&, long&, long&, int, int);
void __cdecl GetDibDim(BITMAPINFO256*, long&, long&, long&);

void __cdecl TransDibBlt(BITMAPINFO256* dstInfo, uchar* dst, RECT* dstRect,
                         long dx, long dy, long dw, long dh,
                         BITMAPINFO256* srcInfo, uchar* src, TRANSINFO_00438AA0* trans,
                         long sx, long sy, long sw, long sh,
                         int doClip, int flipX, int flipY, int transparent)
{
    long SrcTotHgt;
    long sySkip;
    long DestOrien;
    long local_4;
    long DestTotHgt;

    if (trans != 0 && trans->AnyTrans == 0) {
        DibBlt(dstInfo, dst, dstRect, dx, dy, dw, dh, srcInfo, src, sx, sy, sw, sh, doClip, flipX, flipY);
        return;
    }

    if (transparent < 0)
        transparent = 0;

    int clipFlipY = flipY;
    BITMAPINFO256* clipInfo = dstInfo;
    if (doClip == 0 ||
        ClipDibBlt(clipInfo, dstRect, dx, dy, dw, dh, sx, sy, sw, sh, flipX, clipFlipY)) {
    long xStep = (sw << 8) / dw;
    DestOrien = (sh << 8) / dh;

    GetDibDim(clipInfo, (long&)doClip, local_4, DestTotHgt);
    GetDibDim(srcInfo, (long&)dstInfo, sySkip, (long&)flipY);
    if (clipFlipY)
        flipY = -flipY;

    long yStep = (dw << 8) / sw;
    if (DestTotHgt == 1)
        flipX = doClip * dy;
    else
        flipX = (local_4 - dy - 1) * doClip;

    uchar* destLine = dst + flipX + dx;

    long acc = sx;
    if (!flipX) {
        if (dw > 0) {
            long* p = SrcXTbl;
            long n = dw;
            do {
                *p++ = acc >> 8;
                acc += xStep;
            } while (--n);
        }
    } else {
        long n = dw - 1;
        if (n > -1) {
            long* p = SrcXTbl + n;
            ++n;
            do {
                *p-- = acc >> 8;
                acc += xStep;
            } while (--n);
        }
    }

    TRANSINFO_00438AA0* t = trans;
    if (!flipX && t != 0 && t->LineInfo != 0) {
        LINEINFO_00438AA0* lineInfo = t->LineInfo;
        doClip = DestTotHgt * doClip;
        trans = (TRANSINFO_00438AA0*)(sy << 8);
        flipX = 0;
        if (dh > 0) {
            do {
                long syi = ((long)trans) >> 8;
                long srcOff;
                if (flipY == 1) {
                    srcOff = syi * (long)dstInfo + sx;
                } else {
                    srcOff = (sySkip - syi - 1) * (long)dstInfo + sx;
                }

                LINEINFO_00438AA0* li = &lineInfo[syi];
                if (li->skip == 0) {
                    long first;
                    if (li->first < sx)
                        first = 0;
                    else
                        first = ((li->first - sx) * yStep) >> 8;
                    long last = (((li->last - sx) + 1) * yStep) >> 8;
                    if (last > dw)
                        last = dw;
                    if (last > first) {
                        if (yStep == 0x100 && li->copy != 0) {
                            memcpy(destLine + first, src + first + srcOff, last - first);
                        } else {
                            long i = first;
                            long* tbl = SrcXTbl + first;
                            while (i < last) {
                                uchar c = src[*tbl + srcOff];
                                if ((unsigned)c != (unsigned)transparent)
                                    destLine[i] = c;
                                ++i;
                                ++tbl;
                            }
                        }
                    }
                }
                destLine += doClip;
                trans = (TRANSINFO_00438AA0*)((long)trans + DestOrien);
                ++flipX;
            } while (flipX < dh);
            return;
        }
    } else {
        flipX = 0;
        long yacc = sy << 8;
        if (dh > 0) {
            do {
                long syi;
                if (flipY == 1)
                    syi = yacc >> 8;
                else
                    syi = sySkip - (yacc >> 8) - 1;

                long base = syi * (long)dstInfo + sx;
                long i = 0;
                if (dw > 0) {
                    long* tbl = SrcXTbl;
                    do {
                        uchar c = src[*tbl + base];
                        if ((unsigned)c != (unsigned)transparent)
                            destLine[i] = c;
                        ++i;
                        ++tbl;
                    } while (i < dw);
                }
                destLine += DestTotHgt * doClip;
                yacc += DestOrien;
                ++flipX;
            } while (flipX < dh);
        }
    }
    }
}
