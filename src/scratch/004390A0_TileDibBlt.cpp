// 004390A0 TileDibBlt - direct reconstruction from packet/decompiler
// Attempts:
// - Baseline had the right eight-call quadrant family but normalized coordinates
//   before the x/y scale setup, yielding the wrong prologue and 0x18 frame.
// - Restored the original scale-before-wrap line order and native windows.h/C++
//   DibBlt/TransDibBlt declaration context; the best build remains 1231/1265
//   bytes with the 0x18/0x1c frame mismatch.
// - Modeled the shared lVar15 cursor and the named long width/height locals from
//   the DIB packet, and tried the proven utility-header context; VC5 coalesced
//   these to the same emitted code.
// - The binary call layout keeps TransDibBlt handlers before the fallback DibBlt
//   handlers, so the decompiler's reversed source-arm order was rolled back.
// - Remaining blocker is broad VC5 stack-home/loop-body scheduling: calls are
//   aligned 8/8 and the source is typed/natural, but frame/CFG/return topology
//   still differs. No accepted_drift quality.
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <memory.h>

struct BITMAPINFO256;
struct TRANSINFO;
typedef unsigned char uchar;
long __cdecl DibBlt(BITMAPINFO256*, uchar*, RECT*, long, long, long, long, BITMAPINFO256*, uchar*, long, long, long, long, int, int, int);
void __cdecl TransDibBlt(BITMAPINFO256*, uchar*, RECT*, long, long, long, long, BITMAPINFO256*, uchar*, TRANSINFO*, long, long, long, long, int, int, int, int);

long __cdecl TileDibBlt(BITMAPINFO256 *param_1, uchar *param_2, RECT *param_3, long param_4, long param_5,
          long param_6, long param_7, long param_8, long param_9, BITMAPINFO256 *param_10,
          uchar *param_11, TRANSINFO *param_12, long param_13, long param_14, long param_15,
          long param_16, int param_17, int param_18, int param_19)
{
    long lVar15;
    long SrcBotHgt;
    long SrcRtWid;
    long DestBotHgt;
    long SrcTopHgt;
    long SrcLtWid;
    int xscale = (param_15 << 8) / param_8;
    int yscale = (param_16 << 8) / param_9;

    if (param_13 < 0) param_13 += param_15;
    if (param_14 < 0) param_14 += param_16;
    while (param_15 <= param_13) param_13 -= param_15;
    while (param_16 <= param_14) param_14 -= param_16;
    DestBotHgt = param_15 - param_13;
    SrcLtWid = param_16 - param_14;
    int iVar7 = param_15 - DestBotHgt;
    int iVar9 = param_13 - iVar7;
    int iVar11 = param_16 - SrcLtWid;
    int iVar10 = param_14 - iVar11;
    int iVar12 = ((DestBotHgt << 16) / xscale) >> 8;
    SrcRtWid = param_8 - iVar12;
    SrcBotHgt = ((SrcLtWid << 16) / yscale) >> 8;
    SrcTopHgt = param_9 - SrcBotHgt;
    if ((param_8 < param_6) || (param_9 < param_7)) {
        int q = param_6 / param_8;
        if (q * param_8 < param_6) ++q;
        param_6 = q;
        q = param_7 / param_9;
        if (q * param_9 < param_7) ++q;
        param_7 = q;
    } else {
        param_7 = 1;
        param_6 = 1;
    }
    if (param_17) {
        if (0 < param_7) {
            param_17 = param_7;
            do {
                if (0 < param_6) {
                    param_18 = param_6;
                    lVar15 = param_4;
                    do {
                        if (SrcBotHgt != 0) {
                            if (iVar12 != 0) TransDibBlt(param_1,param_2,param_3,lVar15,param_5,iVar12,SrcBotHgt,param_10,param_11,param_12,param_13,param_14,DestBotHgt,SrcLtWid,1,param_18,param_19,0);
                            if (SrcRtWid != 0) TransDibBlt(param_1,param_2,param_3,lVar15+iVar12,param_5,SrcRtWid,SrcBotHgt,param_10,param_11,param_12,iVar9,param_14,iVar7,SrcLtWid,1,param_18,param_19,0);
                        }
                        if (SrcTopHgt != 0) {
                            if (iVar12 != 0) TransDibBlt(param_1,param_2,param_3,lVar15,param_5+SrcBotHgt,iVar12,SrcTopHgt,param_10,param_11,param_12,param_13,iVar10,DestBotHgt,iVar11,1,param_18,param_19,0);
                            if (SrcRtWid != 0) TransDibBlt(param_1,param_2,param_3,lVar15+iVar12,param_5+SrcBotHgt,SrcRtWid,SrcTopHgt,param_10,param_11,param_12,iVar9,iVar10,iVar7,iVar11,1,param_18,param_19,0);
                        }
                        lVar15 += param_8;
                        --param_18;
                    } while (param_18 != 0);
                }
                param_5 += param_9;
                --param_17;
            } while (param_17 != 0);
            return param_7 * param_6;
        }
    } else {
        param_12 = (TRANSINFO*)param_5;
        if (0 < param_7) {
            param_17 = param_7;
            do {
                int src2 = (int)param_12 + SrcBotHgt;
                if (0 < param_6) {
                    param_19 = param_6;
                    lVar15 = param_4;
                    do {
                        if (SrcBotHgt != 0) {
                            if (iVar12 != 0) DibBlt(param_1,param_2,param_3,lVar15,(long)param_12,iVar12,SrcBotHgt,param_10,param_11,param_13,param_14,DestBotHgt,SrcLtWid,1,param_18,param_19);
                            if (SrcRtWid != 0) DibBlt(param_1,param_2,param_3,lVar15+iVar12, (long)param_12,SrcRtWid,SrcBotHgt,param_10,param_11,iVar9,param_14,iVar7,SrcLtWid,1,param_18,param_19);
                        }
                        if (SrcTopHgt != 0) {
                            if (iVar12 != 0) DibBlt(param_1,param_2,param_3,lVar15,src2,iVar12,SrcTopHgt,param_10,param_11,param_13,iVar10,DestBotHgt,iVar11,1,param_18,param_19);
                            if (SrcRtWid != 0) DibBlt(param_1,param_2,param_3,lVar15+iVar12,src2,SrcRtWid,SrcTopHgt,param_10,param_11,iVar9,iVar10,iVar7,iVar11,1,param_18,param_19);
                        }
                        lVar15 += param_8;
                        --param_19;
                    } while (param_19 != 0);
                }
                param_12 = (TRANSINFO*)((int)param_12 + param_9);
                --param_17;
            } while (param_17 != 0);
        }
    }
    return param_7 * param_6;
}
