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
// 13: Initializing DestTotHgt changed the prologue and worsened the diff to 892;
// rolled back.  Mirroring the decompiler's dead dstRect y-scale home changed
// the first block and worsened the diff to 912; rolled back.
// 14: Removing the post-table trans alias and matching the decompiler local
// declaration order were emitted-code duplicates.  A volatile DestTotHgt moved
// the size gap from -21 to -13 but worsened positional diff to 649; rolled back.
// 15: Reusing the dead dst parameter as the byte temporary collapsed the frame
// to 0x0C and worsened the diff to 668; rolled back.
// 16: Matched the same-TU DibBlt donor's int fixed-point step locals for xStep
//     and yStep; the emitted code was unchanged, so the clean long-typed source
//     remains the best period-plausible reconstruction.
// Current pass, 2026-08-17, owner sa-3e20849d:
// - Baseline: 619 differing bytes, 956/977 bytes, 0x10 frame, and 5/5 calls.
// - Thirty-two focused probes tested local types, declaration order, parameter
//   homes, loop lifetimes, redundant predicates, ABI casts, headers, and
//   ambient VC5 declarations. No probe reached an exact result.
// - The best current build differs by 603 bytes. It has 958/977 bytes, a 0x10
//   frame, 5/5 ordered calls, and the original owner symbol.
// - Binary evidence supports the dstRect y-step home, the srcInfo LineInfo
//   overwrite, and the repeated first<last test. Keep these forms.
// - The remaining gap starts at the GetDibDim output homes. VC5 assigns the
//   three long outputs to a different rotation. Later table and loop register
//   colors also differ.
// - Ambient declarations produced two code groups and no exact result. This
//   weakens a front-end declaration-state explanation.
// - No ORIGINAL BUG is proved. No accepted_drift source is justified.
// PAUSE: preserve this clean, typed reconstruction until new period source or
// translation-unit evidence resolves the GetDibDim home rotation.

#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <memory.h>

typedef unsigned char uchar;
struct BITMAPINFO256 {
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD bmiColors[256];
};
struct LINEINFO { int skip; int copy; int first; int last; };
struct TRANSINFO {
    int AnyTrans;
    long x;
    long y;
    long w;
    long h;
    LINEINFO* LineInfo;
};

extern long SrcXTbl[];
#pragma function(memcpy)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
void __cdecl DibBlt(BITMAPINFO256*, uchar*, RECT*, long,long,long,long, BITMAPINFO256*, uchar*, long,long,long,long,int,int,int);
int __cdecl ClipDibBlt(BITMAPINFO256*, RECT*, long&, long&, long&, long&, long&, long&, long&, long&, int, int);
void __cdecl GetDibDim(BITMAPINFO256*, long&, long&, long&);

void __cdecl TransDibBlt(BITMAPINFO256* dstInfo, uchar* dst, RECT* dstRect,
                         long dx, long dy, long dw, long dh,
                         BITMAPINFO256* srcInfo, uchar* src, TRANSINFO* trans,
                         long sx, long sy, long sw, long sh,
                         int doClip, int flipX, int flipY, int transparent)
{
    long SrcTotHgt;
    long DestTotHgt;
    long DestOrien;
    long sySkip;
    int local_4;
    long* p;
    long n;
    long acc;

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
    int xStep = (sw << 8) / dw;
    DestOrien = (sh << 8) / dh;

    GetDibDim(clipInfo, (long&)doClip, (long&)local_4, DestTotHgt);
    GetDibDim(srcInfo, (long&)dstInfo, sySkip, (long&)flipY);
    if (clipFlipY)
        flipY = -flipY;

    dstRect = (RECT*)((dw << 8) / sw);
    if (DestTotHgt == 1)
        flipX = doClip * dy;
    else
        flipX = (local_4 - dy - 1) * doClip;

    uchar* destLine = dst + flipX + dx;

    acc = sx;
    if (!flipX) {
        if (dw > 0) {
            p = SrcXTbl;
            n = dw;
            do {
                *p++ = acc >> 8;
                acc += xStep;
            } while (--n);
        }
    } else {
        n = dw - 1;
        if (n > -1) {
            p = SrcXTbl + n;
            ++n;
            do {
                *p-- = acc >> 8;
                acc += xStep;
            } while (--n);
        }
    }

    if (!flipX && trans != 0 &&
        (srcInfo = (BITMAPINFO256*)trans->LineInfo, srcInfo != 0)) {
        LINEINFO* lineInfo = (LINEINFO*)srcInfo;
        doClip = DestTotHgt * doClip;
        trans = (TRANSINFO*)(sy << 8);
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

                LINEINFO* li = &lineInfo[syi];
                if (li->skip == 0) {
                    long first;
                    if (li->first < sx)
                        first = 0;
                    else
                        first = ((li->first - sx) * (long)dstRect) >> 8;
                    long last = (((li->last - sx) + 1) * (long)dstRect) >> 8;
                    if (last > dw)
                        last = dw;
                    if (last > first) {
                        if ((long)dstRect == 0x100 && li->copy != 0) {
                            memcpy(destLine + first, src + first + srcOff, last - first);
                        } else if (first < last) {
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
                trans = (TRANSINFO*)((long)trans + DestOrien);
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
