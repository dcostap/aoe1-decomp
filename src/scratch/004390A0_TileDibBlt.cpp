// 004390A0 TileDibBlt - direct reconstruction from packet and decompiler.
// Probe summary:
// - The source restores the binary's eight cdecl blit calls and quadrant order.
// - Scale setup before coordinate wrapping restores the 0x1c frame.
// - Int geometry locals reproduce the best emitted code. Long versions are
//   codegen duplicates.
// - Direct scale expressions, alternate fallback row pointers, register
//   hints, ABI spelling, and loop forms did not improve the result.
// - The fallback pointer split is a behavior hypothesis. Its codegen is worse.
// Clean checkpoint: 1254/1265 bytes, 75.42% shape, 8/8 calls, 0x1c frame.
// Current blocker: VC5 stack-home, register, and loop-body scheduling differs.
// TU captain, 2026-08-26, owner sa-c6a4d383-r1:
// - Delayed scale expressions worsened the result to 1179 bytes.
// - Parameter-home scale caching, split assignments, and narrow scale types
//   gave 1112, 1104, and 1104 bytes. The latter two were codegen duplicates.
// - A decompiler-shaped row-origin split gave 1111 bytes and a 15-byte escape.
// - The clean source remains 1104 bytes different, 1254/1265 bytes, with
//   8/8 ordered calls, a 0x1c frame, and the correct owner symbol.
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <memory.h>
#include "../../include/dib_context.h"

void __cdecl DibBlt(BITMAPINFO256*, uchar*, RECT*, long, long, long, long, BITMAPINFO256*, uchar*, long, long, long, long, int, int, int);
void __cdecl TransDibBlt(BITMAPINFO256*, uchar*, RECT*, long, long, long, long, BITMAPINFO256*, uchar*, TRANSINFO*, long, long, long, long, int, int, int, int);

long __cdecl TileDibBlt(BITMAPINFO256 *param_1, uchar *param_2, RECT *param_3, long param_4, long param_5,
          long param_6, long param_7, long param_8, long param_9, BITMAPINFO256 *param_10,
          uchar *param_11, TRANSINFO *param_12, long param_13, long param_14, long param_15,
          long param_16, int param_17, int param_18, int param_19)
{
    int iVar1;
    int iVar3;
    int iVar7;
    int iVar9;
    int iVar11;
    int iVar10;
    int iVar12;
    long lVar15;
    int SrcBotHgt;
    int SrcRtWid;
    int DestBotHgt;
    int SrcTopHgt;
    int SrcLtWid;
    long xscale = (param_15 << 8) / param_8;
    long yscale = (param_16 << 8) / param_9;

    if (param_13 < 0) param_13 += param_15;
    if (param_14 < 0) param_14 += param_16;
    while (param_13 >= param_15) param_13 -= param_15;
    while (param_14 >= param_16) param_14 -= param_16;
    DestBotHgt = param_15 - param_13;
    SrcLtWid = param_16 - param_14;
    iVar7 = param_15 - DestBotHgt;
    iVar9 = param_13 - iVar7;
    iVar11 = param_16 - SrcLtWid;
    iVar10 = param_14 - iVar11;
    iVar12 = ((DestBotHgt << 16) / xscale) >> 8;
    SrcRtWid = param_8 - iVar12;
    SrcBotHgt = ((SrcLtWid << 16) / yscale) >> 8;
    SrcTopHgt = param_9 - SrcBotHgt;
    if ((param_8 < param_6) || (param_9 < param_7)) {
        int q = param_6;
        param_6 = q / param_8;
        if (param_6 * param_8 < q) ++param_6;
        q = param_7;
        param_7 = q / param_9;
        if (param_7 * param_9 < q) ++param_7;
    } else {
        param_7 = 1;
        param_6 = 1;
    }
    if (param_17) {
        iVar1 = param_18;
        iVar3 = param_19;
        if (0 < param_7) {
            param_17 = param_7;
            do {
                if (0 < param_6) {
                    param_18 = param_6;
                    lVar15 = param_4;
                    do {
                        if (SrcBotHgt != 0) {
                            if (iVar12 != 0) TransDibBlt(param_1,param_2,param_3,lVar15,param_5,iVar12,SrcBotHgt,param_10,param_11,param_12,param_13,param_14,DestBotHgt,SrcLtWid,1,iVar1,iVar3,0);
                            if (SrcRtWid != 0) TransDibBlt(param_1,param_2,param_3,lVar15+iVar12,param_5,SrcRtWid,SrcBotHgt,param_10,param_11,param_12,iVar9,param_14,iVar7,SrcLtWid,1,iVar1,iVar3,0);
                        }
                        if (SrcTopHgt != 0) {
                            if (iVar12 != 0) TransDibBlt(param_1,param_2,param_3,lVar15,param_5+SrcBotHgt,iVar12,SrcTopHgt,param_10,param_11,param_12,param_13,iVar10,DestBotHgt,iVar11,1,iVar1,iVar3,0);
                            if (SrcRtWid != 0) TransDibBlt(param_1,param_2,param_3,lVar15+iVar12,param_5+SrcBotHgt,SrcRtWid,SrcTopHgt,param_10,param_11,param_12,iVar9,iVar10,iVar7,iVar11,1,iVar1,iVar3,0);
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
        iVar1 = param_18;
        iVar3 = param_19;
        param_12 = (TRANSINFO*)param_5;
        if (0 < param_7) {
            param_17 = param_7;
            do {
                param_5 = (long)param_12 + SrcBotHgt;
                if (0 < param_6) {
                    param_19 = param_6;
                    lVar15 = param_4;
                    do {
                        if (SrcBotHgt != 0) {
                            if (iVar12 != 0) DibBlt(param_1,param_2,param_3,lVar15,param_5,iVar12,SrcBotHgt,param_10,param_11,param_13,param_14,DestBotHgt,SrcLtWid,1,iVar1,iVar3);
                            if (SrcRtWid != 0) DibBlt(param_1,param_2,param_3,lVar15+iVar12, param_5,SrcRtWid,SrcBotHgt,param_10,param_11,iVar9,param_14,iVar7,SrcLtWid,1,iVar1,iVar3);
                        }
                        if (SrcTopHgt != 0) {
                            if (iVar12 != 0) DibBlt(param_1,param_2,param_3,lVar15,param_5,iVar12,SrcTopHgt,param_10,param_11,param_13,iVar10,DestBotHgt,iVar11,1,iVar1,iVar3);
                            if (SrcRtWid != 0) DibBlt(param_1,param_2,param_3,lVar15+iVar12,param_5,SrcRtWid,SrcTopHgt,param_10,param_11,iVar9,iVar10,iVar7,iVar11,1,iVar1,iVar3);
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
