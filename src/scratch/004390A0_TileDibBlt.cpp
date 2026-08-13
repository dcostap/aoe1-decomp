// 004390A0 TileDibBlt - direct reconstruction from packet/decompiler
// Attempts:
// - Baseline had the right eight-call quadrant family but normalized coordinates
//   before the x/y scale setup, yielding the wrong prologue and 0x18 frame.
// - Restored the original scale-before-wrap line order and native windows.h/C++
//   DibBlt/TransDibBlt declaration context; the clean baseline remained
//   1231/1265 bytes with the 0x18/0x1c frame mismatch.
// - Modeled the shared lVar15 cursor and the named long width/height locals from
//   the DIB packet, and tried the proven utility-header context; VC5 coalesced
//   these to the same emitted code.
// - The binary call layout keeps TransDibBlt handlers before the fallback DibBlt
//   handlers, so the decompiler's reversed source-arm order was rolled back.
// - Recovered the typed saved-dividend ceil-division form from the original
//   store-before-multiply block. This restores the 0x1c frame and gives a
//   72.65% shape match; the source is kept.
// - Spelling wrap predicates with the original operand first improves the
//   current result to 1088 bytes of positional drift and 73.08% shape.
// - Direct parameter-scale overwrites moved arithmetic before the frame and
//   were rolled back. Function-scope src2, long scales, and named tile-size
//   locals produced no further code change.
// - Remaining blocker is broad VC5 stack-home/loop-body scheduling. Calls are
//   aligned 8/8, but the first mismatch is the yscale home and CFG topology
//   still differs. No accepted_drift quality.
// - Separating the saved flip arguments from the param_18/param_19 loop
//   counters, and reusing param_5 for fallback source Y, gives the best
//   structural candidate: 1254/1265 bytes, 75.42% shape, and 8/8 calls.
// - The saved-argument declarations changed the early register carriers, but
//   the binary supports their distinct lifetime from the loop counters.
//   Direct parameter-home and declaration-order probes were rolled back.
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
    long tileWidth = param_15;
    long tileHeight = param_16;
    long xscale = (tileWidth << 8) / param_8;
    long yscale = (tileHeight << 8) / param_9;
    int iVar7;
    int iVar9;
    int iVar11;
    int iVar10;
    int iVar12;
    long lVar15;
    long SrcBotHgt;
    long SrcRtWid;
    long DestBotHgt;
    long SrcTopHgt;
    long SrcLtWid;

    if (param_13 < 0) param_13 += tileWidth;
    if (param_14 < 0) param_14 += tileHeight;
    while (param_13 >= tileWidth) param_13 -= tileWidth;
    while (param_14 >= tileHeight) param_14 -= tileHeight;
    DestBotHgt = tileWidth - param_13;
    SrcLtWid = tileHeight - param_14;
    iVar7 = tileWidth - DestBotHgt;
    iVar9 = param_13 - iVar7;
    iVar11 = tileHeight - SrcLtWid;
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
        int iVar1 = param_18;
        int iVar3 = param_19;
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
        int iVar1 = param_18;
        int iVar3 = param_19;
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
