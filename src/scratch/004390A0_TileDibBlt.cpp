// 004390A0 TileDibBlt - direct reconstruction from packet/decompiler
// Attempts:
// - Direct decompiler-shaped implementation compiles to same 0x1c frame once extra param_18/param_19 temps are removed, but code is 1248 bytes vs original 1265.
// - Temporary unreachable DibBlt padding allowed comparison: first mismatch at offset 4 (loads param_6 first instead of original param_15/xscale setup), ~92.7% positional / ~91.5% edit.
// - Tried mutating param_15/param_16 early to force original xscale stores; worsened to first mismatch at offset 0 due pre-frame parameter load.
// - Remaining blocker is broad source-scheduling/loop-shape mismatch for the 4 quadrant calls in transparent and non-transparent paths; not accepted-drift quality.
struct BITMAPINFO256; struct tagRECT; struct TRANSINFO; typedef unsigned char uchar;
extern "C" long __cdecl DibBlt(BITMAPINFO256*, uchar*, tagRECT*, long, long, long, long, BITMAPINFO256*, uchar*, long, long, long, long, int, int, int);
extern "C" long __cdecl TransDibBlt(BITMAPINFO256*, uchar*, tagRECT*, long, long, long, long, BITMAPINFO256*, uchar*, TRANSINFO*, long, long, long, long, int, int, int, int);

long __cdecl TileDibBlt(BITMAPINFO256 *param_1, uchar *param_2, tagRECT *param_3, long param_4, long param_5,
          long param_6, long param_7, long param_8, long param_9, BITMAPINFO256 *param_10,
          uchar *param_11, TRANSINFO *param_12, long param_13, long param_14, long param_15,
          long param_16, int param_17, int param_18, int param_19)
{
    if (param_13 < 0) param_13 += param_15;
    if (param_14 < 0) param_14 += param_16;
    while (param_15 <= param_13) param_13 -= param_15;
    while (param_16 <= param_14) param_14 -= param_16;
    int iVar4 = param_15 - param_13;
    int iVar13 = param_16 - param_14;
    int iVar7 = param_15 - iVar4;
    int iVar9 = param_13 - iVar7;
    int iVar11 = param_16 - iVar13;
    int iVar10 = param_14 - iVar11;
    int xscale = (param_15 << 8) / param_8;
    int yscale = (param_16 << 8) / param_9;
    int iVar12 = ((iVar4 << 16) / xscale) >> 8;
    int iVar8 = param_8 - iVar12;
    int iVar14 = ((iVar13 << 16) / yscale) >> 8;
    int iVar5 = param_9 - iVar14;
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
                    long dx = param_4;
                    do {
                        if (iVar14 != 0) {
                            if (iVar12 != 0) TransDibBlt(param_1,param_2,param_3,dx,param_5,iVar12,iVar14,param_10,param_11,param_12,param_13,param_14,iVar4,iVar13,1,param_18,param_19,0);
                            if (iVar8 != 0) TransDibBlt(param_1,param_2,param_3,dx+iVar12,param_5,iVar8,iVar14,param_10,param_11,param_12,iVar9,param_14,iVar7,iVar13,1,param_18,param_19,0);
                        }
                        if (iVar5 != 0) {
                            if (iVar12 != 0) TransDibBlt(param_1,param_2,param_3,dx,param_5+iVar14,iVar12,iVar5,param_10,param_11,param_12,param_13,iVar10,iVar4,iVar11,1,param_18,param_19,0);
                            if (iVar8 != 0) TransDibBlt(param_1,param_2,param_3,dx+iVar12,param_5+iVar14,iVar8,iVar5,param_10,param_11,param_12,iVar9,iVar10,iVar7,iVar11,1,param_18,param_19,0);
                        }
                        dx += param_8;
                        --param_18;
                    } while (param_18 != 0);
                }
                param_5 += param_9;
                --param_17;
            } while (param_17 != 0);
        }
    } else {
        param_12 = (TRANSINFO*)param_5;
        if (0 < param_7) {
            param_17 = param_7;
            do {
                int src2 = (int)param_12 + iVar14;
                if (0 < param_6) {
                    param_19 = param_6;
                    long dx = param_4;
                    do {
                        if (iVar14 != 0) {
                            if (iVar12 != 0) DibBlt(param_1,param_2,param_3,dx,(long)param_12,iVar12,iVar14,param_10,param_11,param_13,param_14,iVar4,iVar13,1,param_18,param_19);
                            if (iVar8 != 0) DibBlt(param_1,param_2,param_3,dx+iVar12,(long)param_12,iVar8,iVar14,param_10,param_11,iVar9,param_14,iVar7,iVar13,1,param_18,param_19);
                        }
                        if (iVar5 != 0) {
                            if (iVar12 != 0) DibBlt(param_1,param_2,param_3,dx,src2,iVar12,iVar5,param_10,param_11,param_13,iVar10,iVar4,iVar11,1,param_18,param_19);
                            if (iVar8 != 0) DibBlt(param_1,param_2,param_3,dx+iVar12,src2,iVar8,iVar5,param_10,param_11,iVar9,iVar10,iVar7,iVar11,1,param_18,param_19);
                        }
                        dx += param_8;
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
