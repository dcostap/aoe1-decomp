// VA 00438AA0 TransDibBlt
// Dib.cpp:155-273
// Attempt log:
// 1: Direct C implementation from original asm/decompiler, preserving parameter-slot reuse style where practical.
// 2: Modeled BITMAPINFO256/tagRECT/TRANSINFO/LINEINFO local surfaces and external DibBlt, ClipDibBlt, GetDibDim, SrcXTbl, memcpy.
// 3: Implemented AnyTrans==0 fast path to DibBlt with 16 pushed args and transparent clamp to zero.
// 4: Implemented ClipDibBlt path with address-of dx/dy/dw/dh/sx/sy/sw/sh and early return on failed clip.
// 5: Implemented x/y 8.8 fixed-point steps, GetDibDim calls, flipY sign adjustment, destination base offset for DestTotHgt==1 vs inverted destination.
// 6: Implemented SrcXTbl generation forward/reverse based on flipX.
// 7: Implemented TRANSINFO LineInfo optimized path, including line skip, first/last run clipping, yStep==0x100 copy fast path via memcpy, and transparent-color skip.
// 8: Implemented fallback full-width per-pixel transparent blit path with flipY row mapping and DestTotHgt*stride row advance.
// 9: Default /O2 /Oy build is size-short by 1 byte: configured 977 exceeds .text 976. It also uses an EBP frame / broad different local topology when inspected, unlike original FPO stack-slot reuse.
// 10: Probed /Ob0 and /GX: still 976 bytes. Probed /Og- and /Od: both reached exact 977 bytes but produced very broad mismatch (95.4964% positional, first mismatch offset 0); diagnostic flags removed.
// 11: Remaining blocker is source/stack-frame topology: natural C is behaviorally broad but compiles one byte short and with wrong EBP/local scheduling; exact-size flag variants are worse, not match candidates.
// GIVEUP: left in scratch; no accepted_drift because no default comparable exact-size build and diagnostic exact-size builds are broad from offset 0.

typedef unsigned char uchar;
struct tagRECT { long left, top, right, bottom; };
struct BITMAPINFO256 { int dummy; };
struct LINEINFO_00438AA0 { int skip; int copy; int first; int last; };
struct TRANSINFO_00438AA0 { int AnyTrans; char gap_04[0x10]; LINEINFO_00438AA0* LineInfo; };

extern long SrcXTbl[];
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
void __cdecl DibBlt(BITMAPINFO256*, uchar*, tagRECT*, long,long,long,long, BITMAPINFO256*, uchar*, long,long,long,long,int,int,int);
int __cdecl ClipDibBlt(BITMAPINFO256*, tagRECT*, long*, long*, long*, long*, long*, long*, long*, long*, int, int);
void __cdecl GetDibDim(BITMAPINFO256*, long*, long*, long*);

void __cdecl TransDibBlt(BITMAPINFO256* dstInfo, uchar* dst, tagRECT* dstRect,
                         long dx, long dy, long dw, long dh,
                         BITMAPINFO256* srcInfo, uchar* src, TRANSINFO_00438AA0* trans,
                         long sx, long sy, long sw, long sh,
                         int doClip, int flipX, int flipY, int transparent)
{
    long SrcTotHgt;
    long sySkip;
    long DestOrien;
    long DestTotHgt;
    long local_4;

    if (trans != 0 && trans->AnyTrans == 0) {
        DibBlt(dstInfo, dst, dstRect, dx, dy, dw, dh, srcInfo, src, sx, sy, sw, sh, doClip, flipX, flipY);
        return;
    }

    if (transparent < 0)
        transparent = 0;

    if (doClip) {
        if (!ClipDibBlt(dstInfo, dstRect, &dx, &dy, &dw, &dh, &sx, &sy, &sw, &sh, flipX, flipY))
            return;
    }

    long xStep = (sw << 8) / dw;
    DestOrien = (sh << 8) / dh;

    GetDibDim(dstInfo, (long*)&doClip, &local_4, &DestTotHgt);
    GetDibDim(srcInfo, (long*)&dstInfo, &sySkip, (long*)&flipY);
    if (flipY)
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
