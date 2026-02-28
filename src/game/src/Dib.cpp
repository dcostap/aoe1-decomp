#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>
#include "../include/common.h"
#include "../include/LINEINFO.h"
#include "../include/TRANSINFO.h"
#include "../include/Res_file.h"
#include "../include/RGE_Base_Game.h"
#include "../include/TDrawSystem.h"
#include "../include/globals.h"
#include "../include/custom_debug.h"

static long SrcXTbl[8192];

// TODO: Move these to a common header if needed elsewhere
void CreateIdentityPalette(void* pal);

// Fully verified. Source of truth: dib.cpp.decomp @ 0x00439060
void GetDibDim(BITMAPINFO256* param_1, long* param_2, long* param_3, long* param_4) {
    *param_2 = ((param_1->bmiHeader).biWidth + 3U) & 0xfffffffc;
    long iVar1 = (param_1->bmiHeader).biHeight;
    *param_3 = iVar1;
    if (iVar1 < 0) {
        *param_3 = -iVar1;
        *param_4 = 1;
        return;
    }
    *param_4 = -1;
}

// Fully verified. Source of truth: dib.cpp.decomp @ 0x00438E80
int ClipDibBlt(BITMAPINFO256* param_1, tagRECT* param_2, long* param_3, long* param_4, long* param_5, long* param_6, long* param_7,
               long* param_8, long* param_9, long* param_10, int param_11, int param_12) {
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    int iVar6;
    int iVar7;

    if (param_2 == (tagRECT*)0x0) {
        iVar6 = 0;
        iVar7 = 0;
        iVar5 = (param_1->bmiHeader).biWidth;
        iVar2 = (param_1->bmiHeader).biHeight;
    } else {
        iVar6 = param_2->left;
        iVar7 = param_2->top;
        iVar5 = param_2->right + 1;
        iVar2 = param_2->bottom + 1;
    }
    if (iVar2 < 0) {
        iVar2 = -iVar2;
    }
    iVar5 = iVar5 + -1;
    iVar2 = iVar2 + -1;
    iVar1 = *param_3;
    if (((((iVar1 <= iVar5) && (*param_4 <= iVar2)) && (iVar3 = *param_5, iVar6 <= iVar3 + -1 + iVar1)) &&
         ((iVar4 = *param_6, iVar7 <= iVar4 + -1 + *param_4 && (0 < iVar3)))) &&
        (0 < iVar4)) {
        iVar3 = (int)((((long long)*param_9) << 8) / *param_5);
        iVar4 = (int)((((long long)*param_10) << 8) / *param_6);
        if (iVar1 < iVar6) {
            *param_3 = iVar6;
            *param_5 = *param_5 - (iVar6 - iVar1);
            long long tmp = ((long long)(iVar6 - iVar1) * 0x100LL * iVar3) >> 0x10;
            iVar6 = (int)tmp;
            if (param_11 == 0) {
                *param_7 = *param_7 + iVar6;
            }
            *param_9 = *param_9 - iVar6;
        }
        iVar6 = *param_4;
        if (iVar6 < iVar7) {
            *param_4 = iVar7;
            iVar7 = iVar7 - iVar6;
            *param_6 = *param_6 - iVar7;
            long long tmp = ((long long)iVar7 * 0x100LL * iVar4) >> 0x10;
            iVar6 = (int)tmp;
            if (param_12 == 0) {
                *param_8 = *param_8 + iVar6;
            }
            *param_10 = *param_10 - iVar6;
        }
        iVar6 = *param_3 + *param_5;
        if (iVar5 < iVar6 + -1) {
            iVar6 = (iVar6 - iVar5) + -1;
            *param_5 = *param_5 - iVar6;
            long long tmp = ((long long)iVar6 * 0x100LL * iVar3) >> 0x10;
            iVar6 = (int)tmp;
            *param_9 = *param_9 - iVar6;
            if (param_11 != 0) {
                *param_7 = *param_7 + iVar6;
            }
        }
        iVar6 = *param_4 + *param_6;
        if (iVar2 < iVar6 + -1) {
            iVar6 = (iVar6 - iVar2) + -1;
            *param_6 = *param_6 - iVar6;
            long long tmp = ((long long)iVar6 * 0x100LL * iVar4) >> 0x10;
            iVar6 = (int)tmp;
            *param_10 = *param_10 - iVar6;
            if (param_12 != 0) {
                *param_8 = *param_8 + iVar6;
            }
        }
        if (((0 < *param_5) && (0 < *param_6)) && ((0 < *param_9 && (0 < *param_10)))) {
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: dib.cpp.decomp @ 0x00438820
void DibBlt(BITMAPINFO256* param_1, uchar* param_2, tagRECT* param_3, long param_4, long param_5, long param_6, long param_7,
            BITMAPINFO256* param_8, uchar* param_9, long param_10, long param_11, long param_12, long param_13, int param_14, int param_15,
            int param_16) {
    long DestTotHgt;
    int local_4;

    int iVar9 = param_16;
    BITMAPINFO256* pBVar2 = param_1;
    if ((param_14 != 0) &&
        (ClipDibBlt(param_1, param_3, &param_4, &param_5, &param_6, &param_7, &param_10, &param_11, &param_12, &param_13, param_15,
                    param_16) == 0)) {
        return;
    }

    long dstStride;
    GetDibDim(pBVar2, &dstStride, (long*)&local_4, &DestTotHgt);

    long srcStride;
    long srcTotHgt;
    long srcOrien;
    GetDibDim(param_8, &srcStride, &srcTotHgt, &srcOrien);
    if (iVar9 != 0) {
        srcOrien = -srcOrien;
    }

    int iVar3 = (int)(((long long)param_12 << 8) / param_6);
    int iVar4 = (int)(((long long)param_13 << 8) / param_7);

    long dstY = param_5;
    if (DestTotHgt != 1) {
        dstY = (local_4 - param_5) + -1;
    }
    uchar* puVar12 = param_2 + dstStride * dstY + param_4;

    if ((iVar3 == 0x100) && (iVar4 == 0x100)) {
        if (param_15 == 0) {
            long srcY = param_11;
            if (srcOrien != 1) {
                srcY = srcTotHgt + (-1 - param_11);
            }
            srcY = srcStride * srcY;
            long dstStep = DestTotHgt * dstStride;
            long srcStep = srcOrien * srcStride;
            uchar* puVar10 = param_9 + srcY + param_10;
            int row = 0;
            if (param_7 < 1) {
                return;
            }
            do {
                memcpy(puVar12, puVar10, (size_t)param_6);
                puVar12 = puVar12 + dstStep;
                puVar10 = puVar10 + srcStep;
                row = row + 1;
            } while (row < param_7);
            return;
        }
    } else if (param_15 == 0) {
        if (0 < param_6) {
            long lVar5 = param_10;
            for (long i = 0; i < param_6; ++i) {
                SrcXTbl[i] = (long)(lVar5 >> 8);
                lVar5 = lVar5 + iVar3;
            }
        }
        goto LAB_00438a00;
    }

    if (-1 < param_6 + -1) {
        long lVar5 = param_10;
        for (long i = param_6 - 1; i >= 0; --i) {
            SrcXTbl[i] = (long)(lVar5 >> 8);
            lVar5 = lVar5 + iVar3;
            if (i == 0) break;
        }
    }

LAB_00438a00:
    long yFixed = param_11 << 8;
    int row = 0;
    if (0 < param_7) {
        do {
            int srcY = (int)(yFixed >> 8);
            if (srcOrien != 1) {
                srcY = (int)srcTotHgt + (-1 - srcY);
            }
            if (0 < param_6) {
                for (int x = 0; x < param_6; ++x) {
                    puVar12[x] = param_9[SrcXTbl[x] + srcY * (int)srcStride + param_10];
                }
            }
            yFixed = yFixed + iVar4;
            puVar12 = puVar12 + DestTotHgt * dstStride;
            row = row + 1;
        } while (row < param_7);
    }
}

// Fully verified. Source of truth: dib.cpp.decomp @ 0x00438AA0
void TransDibBlt(BITMAPINFO256* param_1, uchar* param_2, tagRECT* param_3, long param_4, long param_5, long param_6, long param_7,
                 BITMAPINFO256* param_8, uchar* param_9, TRANSINFO* param_10, long param_11, long param_12, long param_13, long param_14,
                 int param_15, int param_16, int param_17, int param_18) {
    int iVar6 = param_17;
    if ((param_10 != (TRANSINFO*)0x0) && (param_10->AnyTrans == 0)) {
        DibBlt(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_11, param_12, param_13, param_14,
               param_15, param_16, param_17);
        return;
    }
    if (param_18 < 0) {
        param_18 = 0;
    }
    if ((param_15 == 0) ||
        (ClipDibBlt(param_1, param_3, &param_4, &param_5, &param_6, &param_7, &param_11, &param_12, &param_13, &param_14, param_16,
                    param_17) != 0)) {
        int xRatio = (int)(((long long)param_13 << 8) / param_6);
        int DestOrien = (int)(((long long)param_14 << 8) / param_7);

        long dstStride;
        long dstTotHgt;
        long dstOrien;
        GetDibDim(param_1, &dstStride, &dstTotHgt, &dstOrien);

        long srcStride;
        long sySkip;
        long srcOrien;
        GetDibDim(param_8, &srcStride, &sySkip, &srcOrien);

        if (iVar6 != 0) {
            srcOrien = -srcOrien;
        }

        long scale = (long)(((long long)param_6 << 8) / param_13);

        long dstY = param_5;
        if (dstOrien != 1) {
            dstY = (dstTotHgt - param_5) + -1;
        }
        uchar* puVar11 = param_2 + dstStride * dstY + param_4;

        if (param_16 == 0) {
            if (0 < param_6) {
                long lVar5 = param_11;
                for (long i = 0; i < param_6; ++i) {
                    SrcXTbl[i] = (long)(lVar5 >> 8);
                    lVar5 = lVar5 + xRatio;
                }
            }
        } else if (-1 < param_6 + -1) {
            long lVar5 = param_11;
            for (long i = param_6 - 1; i >= 0; --i) {
                SrcXTbl[i] = (long)(lVar5 >> 8);
                lVar5 = lVar5 + xRatio;
                if (i == 0) break;
            }
        }

        if (((param_16 == 0) && (param_10 != (TRANSINFO*)0x0)) && (param_10->LineInfo != (LINEINFO*)0x0)) {
            long dstStep = dstOrien * dstStride;
            long yFixed = param_12 << 8;
            int row = 0;
            if (0 < param_7) {
                do {
                    int srcY = (int)(yFixed >> 8);
                    int lineIdx = srcY;
                    if (srcOrien != 1) {
                        lineIdx = (int)sySkip + (-1 - srcY);
                    }
                    long rowBase = lineIdx * (int)srcStride + param_11;
                    LINEINFO* li = (LINEINFO*)((uchar*)param_10->LineInfo + (srcY << 4));

                    if (li->AllTrans == 0) {
                        int start;
                        if (li->StartX < param_11) {
                            start = 0;
                        } else {
                            start = (int)(((long long)(li->StartX - param_11) * scale) >> 8);
                        }

                        int end = (int)((((long long)(li->EndX - param_11) + 1) * scale) >> 8);
                        if (param_6 < end) {
                            end = (int)param_6;
                        }

                        if (start < end) {
                            if ((scale == 0x100) && (li->MidSolid != 0)) {
                                memcpy(puVar11 + start, param_9 + start + rowBase, (size_t)(end - start));
                            } else {
                                for (int x = start; x < end; ++x) {
                                    uchar bVar1 = param_9[SrcXTbl[x] + rowBase];
                                    if ((uint)bVar1 != (uint)param_18) {
                                        puVar11[x] = bVar1;
                                    }
                                }
                            }
                        }
                    }

                    puVar11 = puVar11 + dstStep;
                    yFixed = yFixed + DestOrien;
                    row = row + 1;
                } while (row < param_7);
                return;
            }
        } else {
            int row = 0;
            long yFixed = param_12 << 8;
            if (0 < param_7) {
                do {
                    int srcY = (int)(yFixed >> 8);
                    if (srcOrien != 1) {
                        srcY = (int)sySkip + (-1 - srcY);
                    }
                    if (0 < param_6) {
                        for (int x = 0; x < param_6; ++x) {
                            uchar b = param_9[SrcXTbl[x] + srcY * (int)srcStride + param_11];
                            if ((uint)b != (uint)param_18) {
                                puVar11[x] = b;
                            }
                        }
                    }
                    puVar11 = puVar11 + dstOrien * dstStride;
                    yFixed = yFixed + DestOrien;
                    row = row + 1;
                } while (row < param_7);
            }
        }
    }
}

// Fully verified. Source of truth: dib.cpp.decomp @ 0x004390A0
long TileDibBlt(BITMAPINFO256* param_1, uchar* param_2, tagRECT* param_3, long param_4, long param_5, long param_6, long param_7,
                long param_8, long param_9, BITMAPINFO256* param_10, uchar* param_11, TRANSINFO* param_12, long param_13, long param_14,
                long param_15, long param_16, int param_17, int param_18, int param_19) {
    int iVar1;
    bool bVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    int iVar6;
    int iVar7;
    int iVar8;
    int iVar9;
    int iVar10;
    int iVar11;
    int iVar12;
    int iVar13;
    int iVar14;
    long lVar15;

    iVar3 = param_19;
    iVar1 = param_18;
    if (param_13 < 0) {
        param_13 = param_13 + param_15;
    }
    if (param_14 < 0) {
        param_14 = param_14 + param_16;
    }
    for (; param_15 <= param_13; param_13 = param_13 - param_15) {
    }
    for (; param_16 <= param_14; param_14 = param_14 - param_16) {
    }
    iVar4 = (int)(param_15 - param_13);
    iVar13 = (int)(param_16 - param_14);
    iVar7 = (int)(param_15 - iVar4);
    iVar9 = (int)(param_13 - iVar7);
    iVar11 = (int)(param_16 - iVar13);
    iVar10 = (int)(param_14 - iVar11);
    iVar12 = (int)((((long long)iVar4 * 0x10000) / (((long long)param_15 << 8) / param_8)) >> 8);
    iVar8 = (int)(param_8 - iVar12);
    iVar14 = (int)((((long long)iVar13 * 0x10000) / (((long long)param_16 << 8) / param_9)) >> 8);
    iVar5 = (int)(param_9 - iVar14);

    if ((param_8 < param_6) || (param_9 < param_7)) {
        iVar6 = (int)(param_6 / param_8);
        bVar2 = iVar6 * param_8 < param_6;
        param_6 = iVar6;
        if (bVar2) {
            param_6 = iVar6 + 1;
        }
        iVar6 = (int)(param_7 / param_9);
        bVar2 = iVar6 * param_9 < param_7;
        param_7 = iVar6;
        if (bVar2) {
            param_7 = iVar6 + 1;
        }
    } else {
        param_7 = 1;
        param_6 = 1;
    }

    if (param_17 == 0) {
        param_12 = (TRANSINFO*)param_5;
        if (0 < param_7) {
            param_17 = (int)param_7;
            do {
                iVar1 = (int)((int)&param_12->AnyTrans + iVar14);
                if (0 < param_6) {
                    param_19 = (int)param_6;
                    lVar15 = param_4;
                    do {
                        if (iVar14 != 0) {
                            if (iVar12 != 0) {
                                DibBlt(param_1, param_2, param_3, lVar15, (long)param_12, iVar12, iVar14, param_10, param_11, param_13,
                                       param_14, iVar4, iVar13, 1, param_18, iVar3);
                            }
                            if (iVar8 != 0) {
                                DibBlt(param_1, param_2, param_3, lVar15 + iVar12, (long)param_12, iVar8, iVar14, param_10, param_11, iVar9,
                                       param_14, iVar7, iVar13, 1, param_18, iVar3);
                            }
                        }
                        if (iVar5 != 0) {
                            if (iVar12 != 0) {
                                DibBlt(param_1, param_2, param_3, lVar15, iVar1, iVar12, iVar5, param_10, param_11, param_13, iVar10, iVar4,
                                       iVar11, 1, param_18, iVar3);
                            }
                            if (iVar8 != 0) {
                                DibBlt(param_1, param_2, param_3, lVar15 + iVar12, iVar1, iVar8, iVar5, param_10, param_11, iVar9, iVar10, iVar7,
                                       iVar11, 1, param_18, iVar3);
                            }
                        }
                        lVar15 = lVar15 + param_8;
                        param_19 = param_19 + -1;
                    } while (param_19 != 0);
                }
                param_12 = (TRANSINFO*)((int)&param_12->AnyTrans + param_9);
                param_17 = param_17 + -1;
            } while (param_17 != 0);
        }
    } else if (0 < param_7) {
        param_17 = (int)param_7;
        do {
            if (0 < param_6) {
                param_18 = (int)param_6;
                lVar15 = param_4;
                do {
                    if (iVar14 != 0) {
                        if (iVar12 != 0) {
                            TransDibBlt(param_1, param_2, param_3, lVar15, param_5, iVar12, iVar14, param_10, param_11, param_12, param_13, param_14,
                                       iVar4, iVar13, 1, iVar1, param_19, 0);
                        }
                        if (iVar8 != 0) {
                            TransDibBlt(param_1, param_2, param_3, lVar15 + iVar12, param_5, iVar8, iVar14, param_10, param_11, param_12, iVar9,
                                       param_14, iVar7, iVar13, 1, iVar1, param_19, 0);
                        }
                    }
                    if (iVar5 != 0) {
                        if (iVar12 != 0) {
                            TransDibBlt(param_1, param_2, param_3, lVar15, param_5 + iVar14, iVar12, iVar5, param_10, param_11, param_12, param_13,
                                       iVar10, iVar4, iVar11, 1, iVar1, param_19, 0);
                        }
                        if (iVar8 != 0) {
                            TransDibBlt(param_1, param_2, param_3, lVar15 + iVar12, param_5 + iVar14, iVar8, iVar5, param_10, param_11, param_12, iVar9,
                                       iVar10, iVar7, iVar11, 1, iVar1, param_19, 0);
                        }
                    }
                    lVar15 = lVar15 + param_8;
                    param_18 = param_18 + -1;
                } while (param_18 != 0);
            }
            param_5 = param_5 + param_9;
            param_17 = param_17 + -1;
        } while (param_17 != 0);
        return param_7 * param_6;
    }
    return param_7 * param_6;
}

// Fully verified. Source of truth: dib.cpp.asm @ 0x0043AA60
static void xlatClut8(uchar* param_1, int param_2, const uchar* param_3) {
    if (param_2 != 0) {
        do {
            param_2 = param_2 + -1;
            *param_1 = param_3[*param_1];
            param_1 = param_1 + 1;
        } while (param_2 != 0);
    }
}

// Fully verified. Source of truth: dib.cpp.asm @ 0x0043AA90
static void xlatClut4(uchar* param_1, int param_2, const uchar* param_3) {
    if (param_2 != 0) {
        do {
            *param_1 = param_3[*param_1 & 0xf] | (uchar)(param_3[*param_1 >> 4] << 4);
            param_1 = param_1 + 1;
            param_2 = param_2 + -1;
        } while (param_2 != 0);
    }
}

// Fully verified. Source of truth: dib.cpp.asm @ 0x0043AAD0
static void xlatRle8(uchar* param_1, int /*param_2*/, const uchar* param_3) {
    // NOTE: `param_2` is ignored; RLE streams terminate via end markers.
    uchar* pbVar2 = param_1;
    while (true) {
        uchar* pbVar3;
        uchar bVar1;
        do {
            while (true) {
                pbVar3 = pbVar2;
                bVar1 = pbVar3[1];
                if (*pbVar3 == 0) break;
                pbVar3[1] = param_3[bVar1];
                pbVar2 = pbVar3 + 2;
            }
            pbVar2 = pbVar3 + 2;
        } while (bVar1 == 0);
        if (bVar1 == 1) break;
        if (bVar1 == 2) {
            pbVar2 = pbVar3 + 4;
        } else {
            pbVar3 = pbVar2;
            if (bVar1 != 0) {
                do {
                    pbVar2 = pbVar3 + 1;
                    bVar1 = (uchar)(bVar1 - 1);
                    *pbVar3 = param_3[*pbVar3];
                    pbVar3 = pbVar2;
                } while (bVar1 != 0);
            }
            if ((pbVar3[-1] & 1) != 0) {
                pbVar2 = pbVar2 + 1;
            }
        }
    }
}

static void xlatRle4(uchar* /*param_1*/, int /*param_2*/, const uchar* /*param_3*/) {
    // Fully verified. Source of truth: dib.cpp.asm @ 0x0043AB40 (function is a RET stub in original)
}

// Fully verified. Source of truth: dib.cpp.asm @ 0x0043A660
void DibMapToPalette(tagBITMAPINFOHEADER* param_1, void* param_2, int param_3, int param_4) {
    if (param_2 == nullptr) return;
    if (param_1 == nullptr) return;

    HPALETTE hPal = (HPALETTE)param_2;

    int nPalEntries = 0;
    GetObjectA(hPal, 4, &nPalEntries);

    int nDibColors = (int)param_1->biClrUsed;
    if (nDibColors == 0 && param_1->biBitCount <= 8) {
        nDibColors = 1 << (param_1->biBitCount & 0x1f);
    }

    int sizeImage = (int)param_1->biSizeImage;
    if (sizeImage == 0) {
        int height = (int)param_1->biHeight;
        if (height < 0) height = -height;
        sizeImage = (int)(((((long long)param_1->biWidth * (uint)param_1->biBitCount) + 0x1f) >> 3) & 0x1ffffffc) * height;
    }

    uchar* bits = (uchar*)param_1 + (int)param_1->biSize +
                  ((param_1->biCompression == BI_BITFIELDS) ? 0xc : (nDibColors * (int)sizeof(RGBQUAD)));

    uchar xlat[256];
    memset(xlat, 0, sizeof(xlat));

    uchar HitEnd = 0;
    uchar TransIndex = 0;

    if (param_3 != 0) {
        if (param_4 == 0) {
            long stride = ((param_1->biWidth + 3U) & 0xfffffffc);
            int height = (int)param_1->biHeight;
            if (height < 0) height = -height;
            if (height > 0) {
                HitEnd = *(uchar*)(bits + (stride * (height - 1)));
            }
        } else {
            HitEnd = 0;
        }

        RGBQUAD* rgb = (RGBQUAD*)((uchar*)param_1 + (int)param_1->biSize);
        int r0 = rgb[0].rgbRed;
        int g0 = rgb[0].rgbGreen;
        int b0 = rgb[0].rgbBlue;
        int r = r0, g = g0, b = b0;
        int delta = 1;
        int reversed = 0;
        while (true) {
            r += delta;
            g += delta;
            b += delta;
            if (r > 0xff || g > 0xff || b > 0xff || r < 0 || g < 0 || b < 0) {
                if (reversed != 0) break;
                reversed = 1;
                delta = -1;
                r = r0;
                g = g0;
                b = b0;
                continue;
            }
            TransIndex = (uchar)GetNearestPaletteIndex(hPal, RGB(r, g, b));
            if (TransIndex != 0) break;
        }
    }

    RGBQUAD* lpRgb = (RGBQUAD*)((uchar*)param_1 + (int)param_1->biSize);
    for (int i = 0; i < nDibColors && i < 256; ++i) {
        if (param_3 != 0) {
            if ((uchar)i == HitEnd) {
                xlat[i] = 0;
                continue;
            }
        }
        uchar idx = (uchar)GetNearestPaletteIndex(hPal, RGB(lpRgb[i].rgbRed, lpRgb[i].rgbGreen, lpRgb[i].rgbBlue));
        if (param_3 != 0 && idx == 0) {
            idx = TransIndex;
        }
        xlat[i] = idx;
    }

    int oldDibColors = nDibColors;
    param_1->biClrUsed = (DWORD)nPalEntries;

    if (nPalEntries != oldDibColors) {
        uchar* oldBits = bits;
        uchar* newBits = (uchar*)param_1 + (int)param_1->biSize +
                         ((param_1->biCompression == BI_BITFIELDS) ? 0xc : (nPalEntries * (int)sizeof(RGBQUAD)));

        if (nPalEntries > oldDibColors) {
            HGLOBAL h = GlobalHandle(param_1);
            if (h != nullptr) {
                GlobalUnlock(h);
                SIZE_T newSize = (SIZE_T)param_1->biSize + (SIZE_T)nPalEntries * sizeof(RGBQUAD) + (SIZE_T)sizeImage;
                h = GlobalReAlloc(h, newSize, 0);
                if (h != nullptr) {
                    param_1 = (tagBITMAPINFOHEADER*)GlobalLock(h);
                    lpRgb = (RGBQUAD*)((uchar*)param_1 + (int)param_1->biSize);
                    oldBits = (uchar*)param_1 + (int)param_1->biSize +
                              ((param_1->biCompression == BI_BITFIELDS) ? 0xc : (oldDibColors * (int)sizeof(RGBQUAD)));
                    newBits = (uchar*)param_1 + (int)param_1->biSize +
                              ((param_1->biCompression == BI_BITFIELDS) ? 0xc : (nPalEntries * (int)sizeof(RGBQUAD)));
                }
            }
            memmove(newBits, oldBits, (size_t)sizeImage);
            bits = newBits;
        } else {
            memcpy(newBits, oldBits, (size_t)sizeImage);
            HGLOBAL h = GlobalHandle(param_1);
            if (h != nullptr) {
                GlobalUnlock(h);
                SIZE_T newSize = (SIZE_T)param_1->biSize + (SIZE_T)nPalEntries * sizeof(RGBQUAD) + (SIZE_T)sizeImage;
                h = GlobalReAlloc(h, newSize, 0);
                if (h != nullptr) {
                    param_1 = (tagBITMAPINFOHEADER*)GlobalLock(h);
                    lpRgb = (RGBQUAD*)((uchar*)param_1 + (int)param_1->biSize);
                    newBits = (uchar*)param_1 + (int)param_1->biSize +
                              ((param_1->biCompression == BI_BITFIELDS) ? 0xc : (nPalEntries * (int)sizeof(RGBQUAD)));
                }
            }
            bits = newBits;
        }
    }

    if (param_1->biCompression == BI_RGB) {
        if (param_1->biBitCount == 8) {
            xlatClut8(bits, sizeImage, xlat);
        } else {
            xlatClut4(bits, sizeImage, xlat);
        }
    } else if (param_1->biCompression == BI_RLE8) {
        xlatRle8(bits, sizeImage, xlat);
    } else if (param_1->biCompression == BI_RLE4) {
        xlatRle4(bits, sizeImage, xlat);
    }

    for (int i = 0; i < nPalEntries; ++i) {
        PALETTEENTRY pe;
        GetPaletteEntries(hPal, i, 1, &pe);
        lpRgb[i].rgbBlue = pe.peBlue;
        lpRgb[i].rgbGreen = pe.peGreen;
        lpRgb[i].rgbRed = pe.peRed;
        lpRgb[i].rgbReserved = 0;
    }
}

int DibCheckTrans(BITMAPINFO256* param_1, TRANSINFO* param_2, uchar* param_3) {
    // Fully verified. Source of truth: dib.cpp.decomp @ 0x004395A0
    long stride = 0;
    long h = 0;
    long orien = 0;
    GetDibDim(param_1, &stride, &h, &orien);
    int width = param_1->bmiHeader.biWidth;
    LINEINFO* lines = (LINEINFO*)malloc((size_t)h * sizeof(LINEINFO));
    param_2->LineInfo = lines;
    if (lines == nullptr) {
        return 1;
    }

    int any_trans = 0;
    for (int y = 0; y < h; ++y) {
        int src_y = (orien == 1) ? y : ((int)h - y - 1);
        int row_base = (int)(stride * src_y);
        int all_trans = 1;
        int start_x = width;
        int end_x = width;
        for (int x = 0; x < width; ++x) {
            if (param_3[row_base + x] == 0) {
                any_trans = 1;
            } else if (all_trans != 0) {
                all_trans = 0;
                start_x = x;
                end_x = x;
            } else {
                end_x = x;
            }
        }

        int mid_solid = 1;
        if (all_trans == 0) {
            for (int x = start_x; x <= end_x; ++x) {
                if (param_3[row_base + x] == 0) {
                    mid_solid = 0;
                    break;
                }
            }
        }

        lines[y].AllTrans = all_trans;
        lines[y].MidSolid = mid_solid;
        lines[y].StartX = start_x;
        lines[y].EndX = end_x;
    }

    param_2->AnyTrans = any_trans;
    if (any_trans == 0) {
        free(param_2->LineInfo);
        param_2->LineInfo = nullptr;
    }
    return any_trans;
}

void* GetPaletteFromDib(char* param_1, int param_2) {
    // Fully verified. Source of truth: dib.cpp.decomp @ 0x00439700
    tagBITMAPINFOHEADER* dib = DibOpenFile(param_1);
    if (dib == nullptr) {
        return nullptr;
    }
    void* pal = DibCreatePalette(dib);
    if (param_2 != 0) {
        CreateIdentityPalette(pal);
    }
    DibFree(dib);
    return pal;
}

void* ReadPalette(char* param_1, long param_2, int param_3) {
    // TODO: Source of truth: dib.cpp.decomp @ 0x00439750 (text/resource parser simplified)
    unsigned char* data = nullptr;
    int size = 0;
    int type = 0;
    int own_mem = 0;

    if (param_1 != nullptr && *param_1 != '\0') {
        int fd = _open(param_1, _O_RDONLY | _O_BINARY);
        if (fd != -1) {
            long end = _lseek(fd, 0, SEEK_END);
            _lseek(fd, 0, SEEK_SET);
            data = (unsigned char*)malloc((size_t)end + 1);
            if (data != nullptr) {
                _read(fd, data, (unsigned int)end);
                data[end] = '\0';
                own_mem = 1;
            }
            _close(fd);
        }
    }

    if (data == nullptr && param_2 != -1) {
        data = RESFILE_load(0x62696e61, param_2, &size, &type);
        if (data != nullptr && type == 0) {
            unsigned char* copy = (unsigned char*)malloc((size_t)size + 1);
            if (copy != nullptr) {
                memcpy(copy, data, (size_t)size);
                copy[size] = '\0';
                data = copy;
                own_mem = 1;
            }
        }
    }

    if (data == nullptr) {
        return nullptr;
    }

    HPALETTE hpal = nullptr;
    if (strncmp((const char*)data, "JASC-PAL", 8) == 0) {
        char sep[4];
        sep[0] = '\t';
        sep[1] = ' ';
        sep[2] = '\r';
        sep[3] = '\n';
        char* ctx = nullptr;
        char* tok = strtok_s((char*)data, sep, &ctx);
        tok = strtok_s(nullptr, sep, &ctx);
        tok = strtok_s(nullptr, sep, &ctx);
        if (tok != nullptr) {
            int colors = atol(tok);
            LOGPALETTE* lp = (LOGPALETTE*)malloc(sizeof(LOGPALETTE) + (size_t)colors * sizeof(PALETTEENTRY));
            if (lp != nullptr) {
                lp->palVersion = 0x300;
                lp->palNumEntries = (WORD)colors;
                for (int i = 0; i < colors; ++i) {
                    char* r = strtok_s(nullptr, sep, &ctx);
                    char* g = strtok_s(nullptr, sep, &ctx);
                    char* b = strtok_s(nullptr, sep, &ctx);
                    if (r == nullptr || g == nullptr || b == nullptr) {
                        break;
                    }
                    lp->palPalEntry[i].peRed = (BYTE)atoi(r);
                    lp->palPalEntry[i].peGreen = (BYTE)atoi(g);
                    lp->palPalEntry[i].peBlue = (BYTE)atoi(b);
                    lp->palPalEntry[i].peFlags = 0;
                }
                hpal = CreatePalette(lp);
                free(lp);
            }
        }
    }

    if (own_mem != 0) {
        free(data);
    }

    if (hpal != nullptr && param_3 != 0 &&
        (rge_base_game->draw_system->DrawType == 1 || rge_base_game->draw_system->ScreenMode == 1)) {
        CreateIdentityPalette(hpal);
    }
    return hpal;
}

tagBITMAPINFOHEADER* DibOpenFile(char* param_1) {
    // TODO: Source of truth: dib.cpp.decomp @ 0x00439A10 (resource bitmap path parity incomplete)
    OFSTRUCT of = {};
    HFILE fh = OpenFile(param_1, &of, OF_READ);
    if (fh == HFILE_ERROR) {
        return nullptr;
    }
    tagBITMAPINFOHEADER* dib = DibReadBitmapInfo((int)fh);
    if (dib == nullptr) {
        _lclose(fh);
        return nullptr;
    }

    DWORD ncolors = dib->biClrUsed;
    if (ncolors == 0 && dib->biBitCount < 9) {
        ncolors = 1u << (dib->biBitCount & 0x1F);
    }

    DWORD read_sz = dib->biSizeImage;
    HGLOBAL hg = GlobalHandle(dib);
    GlobalUnlock(hg);
    hg = GlobalReAlloc(hg, dib->biSize + ncolors * 4 + read_sz, GMEM_MOVEABLE | GMEM_ZEROINIT);
    dib = (tagBITMAPINFOHEADER*)GlobalLock(hg);
    if (dib != nullptr) {
        _hread(fh, (LPSTR)((BYTE*)dib + dib->biSize + ncolors * 4), read_sz);
    }
    _lclose(fh);
    return dib;
}

uchar* ReadDibBits(char* param_1) {
    // Fully verified. Source of truth: dib.cpp.decomp @ 0x00439B50
    OFSTRUCT of = {};
    HFILE fh = OpenFile(param_1, &of, OF_READ);
    if (fh == HFILE_ERROR) {
        return nullptr;
    }

    tagBITMAPINFOHEADER* dib = DibReadBitmapInfo((int)fh);
    uchar* bits = nullptr;
    if (dib != nullptr) {
        DWORD size = dib->biSizeImage;
        DibFree(dib);
        bits = (uchar*)malloc(size);
        if (bits != nullptr) {
            _hread(fh, (LPSTR)bits, size);
        }
    }

    _lclose(fh);
    return bits;
}

int DibWriteClipped(tagBITMAPINFOHEADER* param_1, char* param_2, long param_3, long param_4, long param_5, long param_6) {
    // Fully verified. Source of truth: dib.cpp.decomp @ 0x00439BE0
    BITMAPINFO256* out = (BITMAPINFO256*)DibCreate(8, (int)param_5, (int)param_6);
    if (out == nullptr) {
        return 0;
    }
    DWORD colors = param_1->biClrUsed;
    if (colors == 0 && param_1->biBitCount < 9) {
        colors = 1u << (param_1->biBitCount & 0x1F);
    }
    memcpy((BYTE*)out + out->bmiHeader.biSize, (BYTE*)param_1 + param_1->biSize, colors * 4);

    uchar* srcBits = (uchar*)param_1 + param_1->biSize + colors * 4;
    uchar* dstBits = (uchar*)out + out->bmiHeader.biSize + out->bmiHeader.biClrUsed * 4;
    DibBlt(out, dstBits, nullptr, 0, 0, param_5, param_6, (BITMAPINFO256*)param_1, srcBits, param_3, param_4, param_5, param_6, 1, 0, 0);
    DibWriteFile((tagBITMAPINFOHEADER*)out, param_2);
    DibFree((tagBITMAPINFOHEADER*)out);
    return 1;
}

int DibWriteFile(tagBITMAPINFOHEADER* param_1, char* param_2) {
    // Fully verified. Source of truth: dib.cpp.decomp @ 0x00439CC0
    if (param_1 == nullptr) {
        return 0;
    }
    OFSTRUCT of = {};
    HFILE fh = OpenFile(param_2, &of, OF_CREATE | OF_READWRITE);
    if (fh == HFILE_ERROR) {
        return 0;
    }
    tagBITMAPFILEHEADER hdr = {};
    hdr.bfType = 0x4D42;
    DWORD data_size = param_1->biSize + param_1->biClrUsed * 4 + param_1->biSizeImage;
    hdr.bfSize = data_size + sizeof(tagBITMAPFILEHEADER);
    _lwrite(fh, (LPCSTR)&hdr, sizeof(hdr));
    _hwrite(fh, (LPCSTR)param_1, data_size);
    _lclose(fh);
    return 1;
}

void* DibCreatePalette(tagBITMAPINFOHEADER* param_1) {
    // Fully verified. Source of truth: dib.cpp.decomp @ 0x00439D80
    if (param_1 == nullptr) {
        return nullptr;
    }
    DWORD colors = param_1->biClrUsed;
    if (colors == 0 && param_1->biBitCount < 9) {
        colors = 1u << (param_1->biBitCount & 0x1F);
    }
    if (colors == 3 && param_1->biCompression == BI_BITFIELDS) {
        colors = 0;
    }

    if ((int)colors < 1) {
        HDC hdc = GetDC(nullptr);
        HPALETTE pal = CreateHalftonePalette(hdc);
        ReleaseDC(nullptr, hdc);
        return pal;
    }

    LOGPALETTE* lp = (LOGPALETTE*)LocalAlloc(LPTR, sizeof(LOGPALETTE) + colors * sizeof(PALETTEENTRY));
    if (lp == nullptr) {
        return nullptr;
    }
    lp->palVersion = 0x300;
    lp->palNumEntries = (WORD)colors;
    RGBQUAD* rgb = (RGBQUAD*)((BYTE*)param_1 + param_1->biSize);
    for (DWORD i = 0; i < colors; ++i) {
        lp->palPalEntry[i].peRed = rgb[i].rgbRed;
        lp->palPalEntry[i].peGreen = rgb[i].rgbGreen;
        lp->palPalEntry[i].peBlue = rgb[i].rgbBlue;
        lp->palPalEntry[i].peFlags = 0;
    }
    HPALETTE pal = CreatePalette(lp);
    LocalFree(lp);
    return pal;
}

tagBITMAPINFOHEADER* DibReadBitmapInfo(int param_1) {
    // TODO: Source of truth: dib.cpp.decomp @ 0x00439E50 (BITMAPCOREHEADER conversion path incomplete)
    if (param_1 == -1) {
        return nullptr;
    }
    DWORD pos = _llseek(param_1, 0, FILE_CURRENT);
    tagBITMAPFILEHEADER bf = {};
    if (_lread(param_1, (LPSTR)&bf, sizeof(bf)) != sizeof(bf)) {
        return nullptr;
    }
    if (bf.bfType != 0x4D42) {
        _llseek(param_1, pos, FILE_BEGIN);
    }

    tagBITMAPINFOHEADER bi = {};
    if (_lread(param_1, (LPSTR)&bi, sizeof(bi)) != sizeof(bi)) {
        return nullptr;
    }
    DWORD colors = bi.biClrUsed;
    if (colors == 0 && bi.biBitCount < 9) {
        colors = 1u << (bi.biBitCount & 0x1F);
    }
    if (bi.biSizeImage == 0) {
        bi.biSizeImage = (((bi.biWidth * bi.biBitCount + 31) >> 3) & 0x1FFFFFFC) * abs(bi.biHeight);
    }
    bi.biClrUsed = colors;

    HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE | GMEM_ZEROINIT, bi.biSize + colors * sizeof(RGBQUAD));
    tagBITMAPINFOHEADER* dib = (tagBITMAPINFOHEADER*)GlobalLock(hg);
    if (dib == nullptr) {
        return nullptr;
    }
    memcpy(dib, &bi, sizeof(bi));
    if (colors > 0) {
        _lread(param_1, (LPSTR)((BYTE*)dib + bi.biSize), colors * sizeof(RGBQUAD));
    }
    return dib;
}

tagBITMAPINFOHEADER* DibFromBitmap(void* param_1, ulong param_2, uint param_3, void* param_4, uint param_5) {
    // TODO: Source of truth: dib.cpp.decomp @ 0x0043A070 (compression/bitfields parity incomplete)
    if (param_1 == nullptr) {
        return nullptr;
    }
    HBITMAP hbmp = (HBITMAP)param_1;
    HPALETTE hpal = (HPALETTE)param_4;
    if (hpal == nullptr) {
        hpal = (HPALETTE)GetStockObject(DEFAULT_PALETTE);
    }

    BITMAP bm = {};
    GetObjectA(hbmp, sizeof(bm), &bm);
    if (param_3 == 0) {
        param_3 = bm.bmBitsPixel * bm.bmPlanes;
    }

    tagBITMAPINFOHEADER* dib = DibCreate((int)param_3, bm.bmWidth, bm.bmHeight);
    if (dib == nullptr) {
        return nullptr;
    }
    dib->biCompression = param_2;

    HDC hdc = CreateCompatibleDC(nullptr);
    HPALETTE old = (HPALETTE)SelectPalette(hdc, hpal, FALSE);
    RealizePalette(hdc);

    DWORD colors = dib->biClrUsed;
    BYTE* bits = (BYTE*)dib + dib->biSize + colors * 4;
    int ok = GetDIBits(hdc, hbmp, 0, (UINT)dib->biHeight, bits, (BITMAPINFO*)dib, param_5);
    SelectPalette(hdc, old, FALSE);
    DeleteDC(hdc);
    if (ok == 0) {
        DibFree(dib);
        return nullptr;
    }
    return dib;
}

int DibSetUsage(tagBITMAPINFOHEADER* param_1, void* param_2, uint param_3) {
    // Fully verified. Source of truth: dib.cpp.decomp @ 0x0043A330
    if (param_2 == nullptr) {
        param_2 = GetStockObject(DEFAULT_PALETTE);
    }
    if (param_1 == nullptr) {
        return 0;
    }

    DWORD colors = param_1->biClrUsed;
    if (colors == 0 && param_1->biBitCount < 9) {
        colors = 1u << (param_1->biBitCount & 0x1F);
    }
    if (colors == 3 && param_1->biCompression == BI_BITFIELDS) {
        colors = 0;
    }
    RGBQUAD* rgb = (RGBQUAD*)((BYTE*)param_1 + param_1->biSize);
    if ((int)colors > 0) {
        if (param_3 == 1) {
            for (DWORD i = 0; i < colors; ++i) {
                ((WORD*)rgb)[i] = (WORD)i;
            }
        } else {
            if (colors > 256) colors = 256;
            PALETTEENTRY ape[256];
            GetPaletteEntries((HPALETTE)param_2, 0, colors, ape);
            for (DWORD i = 0; i < colors; ++i) {
                rgb[i].rgbRed = ape[i].peRed;
                rgb[i].rgbGreen = ape[i].peGreen;
                rgb[i].rgbBlue = ape[i].peBlue;
                rgb[i].rgbReserved = 0;
            }
        }
    }
    return 1;
}

int DibDraw(void* param_1, int param_2, int param_3, int param_4, int param_5, tagBITMAPINFOHEADER* param_6, int param_7, int param_8,
            int param_9, int param_10, long param_11, uint param_12) {
    // Fully verified. Source of truth: dib.cpp.decomp @ 0x0043A420
    if (param_6 == nullptr) {
        return 0;
    }
    if (param_9 == -1 && param_10 == -1) {
        param_9 = param_6->biWidth;
        param_10 = param_6->biHeight;
    }
    if (param_4 == -1 && param_5 == -1) {
        param_4 = param_9;
        param_5 = param_10;
    }
    int off = (param_6->biCompression == BI_BITFIELDS) ? (param_6->biSize + 0xC) : (param_6->biSize + param_6->biClrUsed * 4);
    return StretchDIBits((HDC)param_1, param_2, param_3, param_4, param_5, param_7, param_8, param_9, param_10, (BYTE*)param_6 + off,
                         (BITMAPINFO*)param_6, param_12, param_11);
}

tagBITMAPINFOHEADER* DibCopy(tagBITMAPINFOHEADER* param_1) {
    // Fully verified. Source of truth: dib.cpp.decomp @ 0x0043A4B0
    if (param_1 == nullptr) {
        return nullptr;
    }
    HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE | GMEM_ZEROINIT, param_1->biSize + param_1->biClrUsed * 4 + param_1->biSizeImage);
    tagBITMAPINFOHEADER* copy = (tagBITMAPINFOHEADER*)GlobalLock(hg);
    if (copy != nullptr) {
        memcpy(copy, param_1, param_1->biSize + param_1->biClrUsed * 4 + param_1->biSizeImage);
    }
    return copy;
}

tagBITMAPINFOHEADER* DibCreate(int param_1, int param_2, int param_3) {
    // Source of truth: dib.cpp.decomp @ 0x0043A500
    DWORD image_size = (DWORD)((((param_2 * param_1 + 7) >> 3) + 3) & 0xFFFFFFFC) * (DWORD)param_3;
    HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE | GMEM_ZEROINIT | GMEM_SHARE, image_size + 0x428);
    tagBITMAPINFOHEADER* dib = (tagBITMAPINFOHEADER*)GlobalLock(hg);
    if (dib == nullptr) {
        return nullptr;
    }
    dib->biSize = sizeof(tagBITMAPINFOHEADER);
    dib->biWidth = param_2;
    dib->biHeight = param_3;
    dib->biPlanes = 1;
    dib->biBitCount = (WORD)param_1;
    dib->biCompression = BI_RGB;
    dib->biSizeImage = image_size;
    dib->biXPelsPerMeter = 0;
    dib->biYPelsPerMeter = 0;
    dib->biClrUsed = 0;
    dib->biClrImportant = 0;
    if (param_1 == 4) dib->biClrUsed = 16;
    if (param_1 == 8) dib->biClrUsed = 256;

    RGBQUAD* pal = (RGBQUAD*)(dib + 1);
    for (DWORD i = 0; i < dib->biClrUsed; ++i) {
        pal[i].rgbBlue = (BYTE)i;
        pal[i].rgbGreen = (BYTE)i;
        pal[i].rgbRed = (BYTE)i;
        pal[i].rgbReserved = 0;
    }
    return dib;
}

void CreateIdentityPalette(void* param_1) {
    // Source of truth: dib.cpp.decomp @ 0x0043AB80
    if (param_1 == nullptr) {
        return;
    }
    HWND hwnd = GetActiveWindow();
    HDC hdc = GetDC(hwnd);
    PALETTEENTRY new_pal[256];
    PALETTEENTRY from_pal[256];
    int got_sys = GetSystemPaletteEntries(hdc, 0, 256, new_pal);
    int got_src = GetPaletteEntries((HPALETTE)param_1, 0, 256, from_pal);
    for (int i = 10; i < 246; ++i) {
        new_pal[i].peRed = from_pal[i].peRed;
        new_pal[i].peGreen = from_pal[i].peGreen;
        new_pal[i].peBlue = from_pal[i].peBlue;
        new_pal[i].peFlags = 1;
    }
    if (got_sys != 0 && got_src != 0) {
        ResizePalette((HPALETTE)param_1, 256);
        SetPaletteEntries((HPALETTE)param_1, 0, 256, new_pal);
    }
    ReleaseDC(hwnd, hdc);
}

void* CopyPalette(void* param_1) {
    // Source of truth: dib.cpp.decomp @ 0x0043ACB0
    if (param_1 == nullptr) {
        return nullptr;
    }
    WORD entries = 0;
    GetObjectA((HPALETTE)param_1, sizeof(WORD), &entries);
    if (entries == 0) {
        return nullptr;
    }
    LOGPALETTE* lp = (LOGPALETTE*)LocalAlloc(LPTR, sizeof(LOGPALETTE) + entries * sizeof(PALETTEENTRY));
    if (lp == nullptr) {
        return nullptr;
    }
    lp->palVersion = 0x300;
    lp->palNumEntries = entries;
    GetPaletteEntries((HPALETTE)param_1, 0, entries, lp->palPalEntry);
    HPALETTE copy = CreatePalette(lp);
    LocalFree(lp);
    return copy;
}

void DibFree(tagBITMAPINFOHEADER* param_1) {
    // Fully verified. Source of truth: dib.cpp.decomp @ 0x0043AD40
    if (param_1 == nullptr) {
        return;
    }
    HGLOBAL hg = GlobalHandle(param_1);
    GlobalUnlock(hg);
    GlobalFree(hg);
}

#if 0
// TODO: Parity reference block from dib.cpp.decomp for unfinished edge-case equivalence.

// Offset: 0x00439750
void* ReadPalette(char* param_1, long param_2, int param_3) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: data */
    // /* void * __cdecl ReadPalette(char *,long,int) */
    // 
    // void * __cdecl ReadPalette(char *param_1,long param_2,int param_3)
    // 
    // {
    //   undefined1 uVar1;
    //   int iVar2;
    //   undefined4 uVar3;
    //   undefined2 *puVar4;
    //   int iVar5;
    //   PAL_TABLE *pPVar6;
    //   int iVar7;
    //   undefined1 *puVar8;
    //   char *data;
    //   int own_mem;
    //   void *hpal;
    //   int resDataSize;
    //   int local_4;
    //   
    //   iVar7 = 0;
    //   own_mem = 0;
    //   hpal = (void *)0xffffffff;
    //   resDataSize = 0;
    //   if ((((param_1 != (char *)0x0) && (*param_1 != '\0')) && (shape_file_first != '\0')) &&
    //      (iVar2 = __open(param_1,0x8000), iVar2 != -1)) {
    //     lseek(iVar2,0,2);
    //     uVar3 = __tell(iVar2);
    //     own_mem = malloc(uVar3);
    //     if (own_mem != 0) {
    //       lseek(iVar2,0,0);
    //       read(iVar2,own_mem,uVar3);
    //       hpal = (void *)0x1;
    //     }
    //     close(iVar2);
    //   }
    //   if (((own_mem == 0) && (param_2 != -1)) &&
    //      (own_mem = (int)RESFILE_load(0x62696e61,param_2,(int *)&hpal,&local_4), hpal == (void *)0x0)) {
    //     iVar2 = malloc(local_4);
    //     memcpy(iVar2,own_mem,local_4);
    //     hpal = (void *)0x1;
    //     own_mem = iVar2;
    //   }
    //   if (own_mem == 0) {
    //     return (void *)0x0;
    //   }
    //   param_1._0_3_ = CONCAT12(DAT_005837c6,s___);
    //   iVar2 = strtok(own_mem,&param_1);
    //   if (((iVar2 != 0) && (iVar2 = strtok(0,&param_1), iVar2 != 0)) &&
    //      (iVar2 = strtok(0,&param_1), iVar2 != 0)) {
    //     iVar2 = atol(iVar2);
    //     puVar4 = (undefined2 *)malloc(iVar2 * 4 + 8);
    //     param_2 = 0;
    //     if (puVar4 != (undefined2 *)0x0) {
    //       puVar4[1] = (short)iVar2;
    //       *puVar4 = 0x300;
    //       if (0 < iVar2) {
    //         puVar8 = (undefined1 *)((int)puVar4 + 5);
    //         do {
    //           iVar5 = strtok(0,&param_1);
    //           if (iVar5 == 0) break;
    //           uVar1 = atoi(iVar5);
    //           puVar8[-1] = uVar1;
    //           iVar5 = strtok(0,&param_1);
    //           if (iVar5 == 0) break;
    //           uVar1 = atoi(iVar5);
    //           *puVar8 = uVar1;
    //           iVar5 = strtok(0,&param_1);
    //           if (iVar5 == 0) break;
    //           uVar1 = atoi(iVar5);
    //           puVar8[1] = uVar1;
    //           puVar8[2] = 0;
    //           if (iVar7 == iVar2 + -1) {
    //             param_2 = 1;
    //           }
    //           iVar7 = iVar7 + 1;
    //           puVar8 = puVar8 + 4;
    //         } while (iVar7 < iVar2);
    //       }
    //       if (param_2 != 0) {
    //         if ((iVar2 == 0x100) && (-1 < (int)System_color_Table)) {
    //           pPVar6 = System_color_Table;
    //           puVar8 = &DAT_005841e5;
    //           do {
    //             *(undefined1 *)(puVar4 + (int)pPVar6 * 2 + 2) = puVar8[-1];
    //             *(undefined1 *)((int)puVar4 + (int)pPVar6 * 4 + 5) = *puVar8;
    //             *(undefined1 *)(puVar4 + (int)pPVar6 * 2 + 3) = puVar8[1];
    //             *(undefined1 *)((int)puVar4 + (int)pPVar6 * 4 + 7) = 0;
    //             pPVar6 = *(PAL_TABLE **)(puVar8 + 3);
    //             puVar8 = puVar8 + 8;
    //           } while (-1 < (int)pPVar6);
    //         }
    //         if (((param_2 != 0) && (resDataSize = CreatePalette(puVar4), param_3 != 0)) &&
    //            ((rge_base_game->draw_system->DrawType == '\x01' ||
    //             (rge_base_game->draw_system->ScreenMode == '\x01')))) {
    //           CreateIdentityPalette((void *)resDataSize);
    //         }
    //       }
    //       free(puVar4);
    //     }
    //   }
    //   if (hpal == (void *)0x1) {
    //     free(own_mem);
    //   }
    //   return (void *)resDataSize;
    // }
    // 
    // 
}

// Offset: 0x00439A10
tagBITMAPINFOHEADER* DibOpenFile(char* param_1) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: fh */
    // /* struct tagBITMAPINFOHEADER * __cdecl DibOpenFile(char *) */
    // 
    // tagBITMAPINFOHEADER * __cdecl DibOpenFile(char *param_1)
    // 
    // {
    //   ulong uVar1;
    //   int iVar2;
    //   undefined4 uVar3;
    //   tagBITMAPINFOHEADER *ptVar4;
    //   ulong uVar5;
    //   tagBITMAPINFOHEADER *ptVar6;
    //   undefined4 uVar7;
    //   undefined4 uVar8;
    //   int fh;
    //   ulong dwBits;
    //   _OFSTRUCT of;
    //   
    //   iVar2 = OpenFile(param_1,&of.Reserved1,0);
    //   if (iVar2 == -1) {
    //     uVar8 = 2;
    //     uVar3 = GetModuleHandleA(0,param_1,2);
    //     iVar2 = FindResourceA(uVar3,param_1,uVar8);
    //     if (iVar2 != 0) {
    //       uVar3 = GetModuleHandleA(0,iVar2);
    //       uVar3 = LoadResource(uVar3);
    //       ptVar4 = (tagBITMAPINFOHEADER *)LockResource(uVar3);
    //       return ptVar4;
    //     }
    //     return (tagBITMAPINFOHEADER *)0x0;
    //   }
    //   ptVar4 = DibReadBitmapInfo(iVar2);
    //   if (ptVar4 == (tagBITMAPINFOHEADER *)0x0) {
    //     return (tagBITMAPINFOHEADER *)0x0;
    //   }
    //   uVar5 = ptVar4->biClrUsed;
    //   of._0_4_ = ptVar4->biSizeImage;
    //   if ((uVar5 == 0) && (ptVar4->biBitCount < 9)) {
    //     uVar5 = 1 << ((byte)ptVar4->biBitCount & 0x1f);
    //   }
    //   uVar1 = ptVar4->biSize;
    //   iVar2 = of._0_4_ + uVar5 * 4;
    //   uVar3 = GlobalHandle(ptVar4);
    //   GlobalUnlock(uVar3);
    //   uVar7 = 0;
    //   uVar8 = GlobalHandle(ptVar4,iVar2 + uVar1,0);
    //   uVar8 = GlobalReAlloc(uVar8);
    //   ptVar6 = (tagBITMAPINFOHEADER *)GlobalLock(uVar8);
    //   if (ptVar6 == (tagBITMAPINFOHEADER *)0x0) {
    //     uVar8 = GlobalHandle(ptVar4);
    //     GlobalUnlock(uVar8);
    //     uVar8 = GlobalHandle(ptVar4);
    //     GlobalFree(uVar8);
    //     ptVar6 = (tagBITMAPINFOHEADER *)0x0;
    //   }
    //   if (ptVar6 != (tagBITMAPINFOHEADER *)0x0) {
    //     uVar5 = ptVar6->biClrUsed;
    //     if ((uVar5 == 0) && (ptVar6->biBitCount < 9)) {
    //       uVar5 = 1 << ((byte)ptVar6->biBitCount & 0x1f);
    //     }
    //     _hread(uVar7,(int)&ptVar6->biSize + ptVar6->biSize + uVar5 * 4,uVar3);
    //   }
    //   _lclose(uVar7);
    //   return ptVar6;
    // }
    // 
    // 
}

// Offset: 0x00439B50
uchar* ReadDibBits(char* param_1) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: of */
    // /* unsigned char * __cdecl ReadDibBits(char *) */
    // 
    // uchar * __cdecl ReadDibBits(char *param_1)
    // 
    // {
    //   ulong uVar1;
    //   int iVar2;
    //   tagBITMAPINFOHEADER *ptVar3;
    //   undefined4 uVar4;
    //   uchar *puVar5;
    //   _OFSTRUCT of;
    //   
    //   puVar5 = (uchar *)0x0;
    //   iVar2 = OpenFile(param_1,&of.Reserved1,0);
    //   if (iVar2 == -1) {
    //     return (uchar *)0x0;
    //   }
    //   ptVar3 = DibReadBitmapInfo(iVar2);
    //   if (ptVar3 != (tagBITMAPINFOHEADER *)0x0) {
    //     uVar1 = ptVar3->biSizeImage;
    //     uVar4 = GlobalHandle(ptVar3);
    //     GlobalUnlock(uVar4);
    //     uVar4 = GlobalHandle(ptVar3);
    //     GlobalFree(uVar4);
    //     puVar5 = (uchar *)malloc(uVar1);
    //     if (puVar5 != (uchar *)0x0) {
    //       _hread(iVar2,puVar5,uVar1);
    //     }
    //   }
    //   _lclose(iVar2);
    //   return puVar5;
    // }
    // 
    // 
}

// Offset: 0x00439BE0
int DibWriteClipped(tagBITMAPINFOHEADER* param_1, char* param_2, long param_3, long param_4, long param_5, long param_6) {
    // --- Ghidra decompiler output ---
    // 
    // /* int __cdecl DibWriteClipped(struct tagBITMAPINFOHEADER *,char *,long,long,long,long) */
    // 
    // int __cdecl
    // DibWriteClipped(tagBITMAPINFOHEADER *param_1,char *param_2,long param_3,long param_4,long param_5,
    //                long param_6)
    // 
    // {
    //   BITMAPINFO256 *pBVar1;
    //   ulong uVar2;
    //   uchar *puVar3;
    //   uchar *puVar4;
    //   
    //   pBVar1 = (BITMAPINFO256 *)DibCreate(8,param_5,param_6);
    //   if (pBVar1 == (BITMAPINFO256 *)0x0) {
    //     return 0;
    //   }
    //   uVar2 = param_1->biClrUsed;
    //   if ((uVar2 == 0) && (param_1->biBitCount < 9)) {
    //     uVar2 = 1 << ((byte)param_1->biBitCount & 0x1f);
    //   }
    //   memcpy((int)&(((BITMAPINFO256 *)(pBVar1->bmiColors + -10))->bmiHeader).biSize +
    //          (pBVar1->bmiHeader).biSize,(int)&param_1->biSize + param_1->biSize,uVar2 << 2);
    //   if (param_1->biCompression == 3) {
    //     puVar4 = (uchar *)((int)&param_1->biPlanes + param_1->biSize);
    //   }
    //   else {
    //     puVar4 = (uchar *)((int)&param_1->biSize + param_1->biSize + param_1->biClrUsed * 4);
    //   }
    //   if ((pBVar1->bmiHeader).biCompression == 3) {
    //     puVar3 = (uchar *)((int)(pBVar1->bmiColors + -7) + (pBVar1->bmiHeader).biSize);
    //   }
    //   else {
    //     puVar3 = &pBVar1->bmiColors[(pBVar1->bmiHeader).biClrUsed - 10].rgbBlue +
    //              (pBVar1->bmiHeader).biSize;
    //   }
    //   DibBlt(pBVar1,puVar3,(tagRECT *)0x0,0,0,param_5,param_6,(BITMAPINFO256 *)param_1,puVar4,param_3,
    //          param_4,param_5,param_6,1,0,0);
    //   DibWriteFile((tagBITMAPINFOHEADER *)pBVar1,param_2);
    //   DibFree((tagBITMAPINFOHEADER *)pBVar1);
    //   return 1;
    // }
    // 
    // 
}

// Offset: 0x00439CC0
int DibWriteFile(tagBITMAPINFOHEADER* param_1, char* param_2) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: hdr */
    // /* int __cdecl DibWriteFile(struct tagBITMAPINFOHEADER *,char *) */
    // 
    // int __cdecl DibWriteFile(tagBITMAPINFOHEADER *param_1,char *param_2)
    // 
    // {
    //   int iVar1;
    //   int iVar2;
    //   tagBITMAPFILEHEADER hdr;
    //   _OFSTRUCT of;
    //   
    //   if (param_1 == (tagBITMAPINFOHEADER *)0x0) {
    //     return 0;
    //   }
    //   iVar1 = OpenFile(param_2,&of.Reserved1,0x1002);
    //   if (iVar1 != -1) {
    //     hdr.bfSize._2_2_ = 0x4d42;
    //     hdr.bfOffBits._0_2_ = 0;
    //     iVar2 = param_1->biSizeImage + param_1->biClrUsed * 4 + param_1->biSize;
    //     hdr.bfOffBits._2_2_ = 0;
    //     hdr._6_4_ = iVar2 + 0xe;
    //     _lwrite(iVar1,(undefined1 *)((int)&hdr.bfSize + 2),0xe);
    //     _hwrite(iVar1,param_1,iVar2);
    //     _lclose(iVar1);
    //     return 1;
    //   }
    //   return 0;
    // }
    // 
    // 
}

// Offset: 0x00439D80
void* DibCreatePalette(tagBITMAPINFOHEADER* param_1) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: hpal */
    // /* void * __cdecl DibCreatePalette(struct tagBITMAPINFOHEADER *) */
    // 
    // void * __cdecl DibCreatePalette(tagBITMAPINFOHEADER *param_1)
    // 
    // {
    //   ulong uVar1;
    //   undefined2 *puVar2;
    //   undefined1 *puVar3;
    //   undefined4 uVar4;
    //   void *unaff_ESI;
    //   undefined1 *puVar5;
    //   void *unaff_EDI;
    //   ulong uVar6;
    //   void *hpal;
    //   
    //   if (param_1 == (tagBITMAPINFOHEADER *)0x0) {
    //     return (void *)0x0;
    //   }
    //   uVar6 = param_1->biClrUsed;
    //   if ((uVar6 == 0) && (param_1->biBitCount < 9)) {
    //     uVar6 = 1 << ((byte)param_1->biBitCount & 0x1f);
    //   }
    //   if ((uVar6 == 3) && (param_1->biCompression == 3)) {
    //     uVar6 = 0;
    //   }
    //   if ((int)uVar6 < 1) {
    //     uVar4 = GetDC(0);
    //     unaff_ESI = (void *)CreateHalftonePalette(uVar4);
    //     ReleaseDC(0,uVar4);
    //   }
    //   else {
    //     uVar1 = param_1->biSize;
    //     puVar2 = (undefined2 *)LocalAlloc(0x40,uVar6 * 4 + 8);
    //     if (puVar2 != (undefined2 *)0x0) {
    //       puVar2[1] = (short)uVar6;
    //       *puVar2 = 0x300;
    //       if (0 < (int)uVar6) {
    //         puVar3 = (undefined1 *)((int)puVar2 + 5);
    //         puVar5 = (undefined1 *)((int)&param_1->biSize + uVar1);
    //         do {
    //           puVar3[-1] = puVar5[2];
    //           *puVar3 = puVar5[1];
    //           puVar3[1] = *puVar5;
    //           puVar3[2] = 0;
    //           puVar3 = puVar3 + 4;
    //           uVar6 = uVar6 - 1;
    //           puVar5 = puVar5 + 4;
    //         } while (uVar6 != 0);
    //       }
    //       CreatePalette(puVar2);
    //       LocalFree(puVar2);
    //       return unaff_EDI;
    //     }
    //   }
    //                     /* Symbol Ref: {@symbol exit} */
    //   return unaff_ESI;
    // }
    // 
    // 
}

// Offset: 0x00439E50
tagBITMAPINFOHEADER* DibReadBitmapInfo(int param_1) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: pdib */
    // /* struct tagBITMAPINFOHEADER * __cdecl DibReadBitmapInfo(int) */
    // 
    // tagBITMAPINFOHEADER * __cdecl DibReadBitmapInfo(int param_1)
    // 
    // {
    //   int iVar1;
    //   uint uVar2;
    //   undefined4 uVar3;
    //   int iVar4;
    //   tagBITMAPINFOHEADER *ptVar5;
    //   undefined1 *puVar6;
    //   ulong *puVar7;
    //   int unaff_EBX;
    //   undefined4 unaff_EBP;
    //   ushort *puVar8;
    //   ulong uVar9;
    //   tagBITMAPINFOHEADER *ptVar10;
    //   tagBITMAPINFOHEADER *pdib;
    //   ulong off;
    //   tagBITMAPCOREHEADER bc;
    //   tagBITMAPFILEHEADER bf;
    //   tagBITMAPINFOHEADER bi;
    //   
    //   if (param_1 == -1) {
    //     return (tagBITMAPINFOHEADER *)0x0;
    //   }
    //   uVar3 = _llseek(param_1,0,1);
    //   iVar4 = _lread(param_1,(undefined1 *)((int)&bf.bfSize + 2),0xe);
    //   if (iVar4 != 0xe) {
    //     return (tagBITMAPINFOHEADER *)0x0;
    //   }
    //   if (bf.bfSize._2_2_ != 0x4d42) {
    //     _llseek(param_1,uVar3,0);
    //   }
    //   iVar4 = _lread(param_1,&bi.biWidth,0x28);
    //   if (iVar4 != 0x28) {
    //     return (tagBITMAPINFOHEADER *)0x0;
    //   }
    //   if (bi.biWidth == 0xc) {
    //     bf.bfType = bi.biPlanes;
    //     bf.bfSize._0_2_ = bi.biBitCount;
    //     uVar2 = (uint)bi.biHeight >> 0x10;
    //     bi.biHeight = bi.biHeight & 0xffff;
    //     bi.biWidth = 0x28;
    //     bi.biCompression._2_1_ = (byte)bi.biBitCount;
    //     bi.biCompression._3_1_ = bi.biBitCount._1_1_;
    //     bi.biSizeImage._0_2_ = 0;
    //     bi.biSizeImage._2_2_ = 0;
    //     bi.biXPelsPerMeter = 0;
    //     bi.biYPelsPerMeter = 0;
    //     bi.biClrUsed = 0;
    //     bi.biClrImportant = 0;
    //     bi._12_4_ = uVar2;
    //     bi.biCompression._0_2_ = bf.bfType;
    //     _llseek(param_1,0xffffffe4,1);
    //   }
    //   uVar9 = bi.biClrImportant;
    //   if ((bi.biClrImportant == 0) && (CONCAT11(bi.biCompression._3_1_,bi.biCompression._2_1_) < 9)) {
    //     uVar9 = 1 << (bi.biCompression._2_1_ & 0x1f);
    //   }
    //   if (bi.biXPelsPerMeter == 0) {
    //     bi.biXPelsPerMeter =
    //          (bi.biHeight * (uint)CONCAT11(bi.biCompression._3_1_,bi.biCompression._2_1_) + 0x1f >> 3 &
    //          0x1ffffffc) * bi._12_4_;
    //   }
    //   if ((bi.biClrImportant == 0) && (CONCAT11(bi.biCompression._3_1_,bi.biCompression._2_1_) < 9)) {
    //     bi.biClrImportant = 1 << (bi.biCompression._2_1_ & 0x1f);
    //   }
    //   uVar3 = GlobalAlloc(2,bi.biWidth + uVar9 * 4);
    //   ptVar5 = (tagBITMAPINFOHEADER *)GlobalLock(uVar3);
    //   if (ptVar5 != (tagBITMAPINFOHEADER *)0x0) {
    //     puVar8 = &bf.bfReserved2;
    //     ptVar10 = ptVar5;
    //     for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
    //       ptVar10->biSize = *(ulong *)puVar8;
    //       puVar8 = puVar8 + 2;
    //       ptVar10 = (tagBITMAPINFOHEADER *)&ptVar10->biWidth;
    //     }
    //     iVar4 = (int)&ptVar5->biSize + ptVar5->biSize;
    //     if (uVar9 != 0) {
    //       if (bi.biClrImportant == 0xc) {
    //         _lread(param_1,iVar4,uVar9 * 3);
    //         iVar1 = uVar9 - 1;
    //         if (-1 < iVar1) {
    //           puVar7 = (ulong *)(iVar4 + iVar1 * 4);
    //           puVar6 = (undefined1 *)(uVar9 + iVar4 + iVar1 * 2);
    //           do {
    //             bi.biClrImportant._0_2_ = CONCAT11(*puVar6,puVar6[-1]);
    //             bi.biClrImportant = (ulong)CONCAT12(puVar6[1],(undefined2)bi.biClrImportant);
    //             *puVar7 = bi.biClrImportant;
    //             puVar7 = puVar7 + -1;
    //             uVar9 = uVar9 - 1;
    //             puVar6 = puVar6 + -3;
    //           } while (uVar9 != 0);
    //         }
    //       }
    //       else {
    //         _lread(param_1,iVar4,unaff_EBP);
    //       }
    //     }
    //     if (CONCAT22(bf.bfSize._2_2_,(ushort)bf.bfSize) != 0) {
    //       _llseek(param_1,CONCAT22(bf.bfSize._2_2_,(ushort)bf.bfSize) + unaff_EBX,0);
    //     }
    //     return ptVar5;
    //   }
    //   return (tagBITMAPINFOHEADER *)0x0;
    // }
    // 
    // 
}

// Offset: 0x0043A070
tagBITMAPINFOHEADER* DibFromBitmap(void* param_1, ulong param_2, uint param_3, void* param_4, uint param_5) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: nColors */
    // /* struct tagBITMAPINFOHEADER * __cdecl DibFromBitmap(void *,unsigned long,unsigned int,void
    //    *,unsigned int) */
    // 
    // tagBITMAPINFOHEADER * __cdecl
    // DibFromBitmap(void *param_1,ulong param_2,uint param_3,void *param_4,uint param_5)
    // 
    // {
    //   undefined4 uVar1;
    //   int *piVar2;
    //   int iVar3;
    //   undefined4 uVar4;
    //   tagBITMAPINFOHEADER *ptVar5;
    //   ulong uVar6;
    //   ulong uVar7;
    //   int unaff_EBX;
    //   undefined4 unaff_EBP;
    //   int nColors;
    //   tagBITMAP bm;
    //   undefined2 uStack_4;
    //   undefined2 uStack_2;
    //   
    //   bm.bmType = 0;
    //   if (param_1 == (void *)0x0) {
    //     return (tagBITMAPINFOHEADER *)0x0;
    //   }
    //   if (param_4 == (void *)0x0) {
    //     param_4 = (void *)GetStockObject(0xf);
    //   }
    //   GetObjectA(param_1,0x18,&bm.bmWidth);
    //   GetObjectA(param_4,4,&bm);
    //   if (param_3 == 0) {
    //     param_3 = (uint)(ushort)bm.bmBits * (uint)bm.bmBits._2_2_;
    //   }
    //   uVar1 = GlobalAlloc(2,0x428);
    //   piVar2 = (int *)GlobalLock(uVar1);
    //   if (piVar2 == (int *)0x0) {
    //     return (tagBITMAPINFOHEADER *)0x0;
    //   }
    //   *piVar2 = 0x28;
    //   piVar2[1] = unaff_EBX;
    //   piVar2[2] = bm.bmType;
    //   *(undefined2 *)(piVar2 + 3) = 1;
    //   *(ushort *)((int)piVar2 + 0xe) = (ushort)param_3;
    //   piVar2[4] = CONCAT22(uStack_2,uStack_4);
    //   piVar2[5] = 0;
    //   piVar2[6] = 0;
    //   piVar2[7] = 0;
    //   piVar2[8] = 0;
    //   piVar2[9] = 0;
    //   if ((ushort)param_3 < 9) {
    //     iVar3 = 1 << ((byte)param_3 & 0x1f);
    //   }
    //   else {
    //     iVar3 = 0;
    //   }
    //   piVar2[8] = iVar3;
    //   if (CONCAT22(uStack_2,uStack_4) == 3) {
    //     if (param_3 == 0x10) {
    //       piVar2[10] = 0xf800;
    //                     /* language.dll match for 0x7e0: "Age of Empires Expansion requires Age of
    //                        Empires 1.0, 1.0A, or 1.0B to be installed." */
    //       piVar2[0xb] = 0x7e0;
    //       piVar2[0xc] = 0x1f;
    //     }
    //     else if ((param_3 == 0x18) || (param_3 == 0x20)) {
    //       piVar2[10] = 0xff;
    //       piVar2[0xb] = 0xff00;
    //       piVar2[0xc] = 0xff0000;
    //     }
    //   }
    //   uVar1 = CreateCompatibleDC(0);
    //   SelectPalette(uVar1,param_4,0);
    //   RealizePalette(uVar1);
    //   SetStretchBltMode(uVar1,4);
    //   GetDIBits(uVar1,param_1,0,piVar2[2],0,piVar2,param_2);
    //   iVar3 = piVar2[8];
    //   if ((iVar3 == 0) && (*(ushort *)((int)piVar2 + 0xe) < 9)) {
    //     iVar3 = 1 << ((byte)*(ushort *)((int)piVar2 + 0xe) & 0x1f);
    //   }
    //   piVar2[8] = iVar3;
    //   iVar3 = piVar2[5];
    //   if (iVar3 == 0) {
    //     iVar3 = ((uint)*(ushort *)((int)piVar2 + 0xe) * piVar2[1] + 0x1f >> 3 & 0x1ffffffc) * piVar2[2];
    //   }
    //   piVar2[5] = iVar3;
    //   if (iVar3 == 0) {
    //     iVar3 = ((uint)*(ushort *)((int)piVar2 + 0xe) * piVar2[1] + 0x1f >> 3 & 0x1ffffffc) * piVar2[2];
    //     piVar2[5] = iVar3;
    //     if (CONCAT22(uStack_2,uStack_4) != 0) {
    //       piVar2[5] = (uint)(iVar3 * 3) >> 1;
    //     }
    //   }
    //   uVar4 = GlobalHandle(piVar2);
    //   GlobalUnlock(uVar4);
    //   uVar4 = GlobalHandle(piVar2,*piVar2 + piVar2[8] * 4 + piVar2[5],0);
    //   uVar4 = GlobalReAlloc(uVar4);
    //   ptVar5 = (tagBITMAPINFOHEADER *)GlobalLock(uVar4);
    //   if (ptVar5 == (tagBITMAPINFOHEADER *)0x0) {
    //     uVar4 = GlobalHandle(piVar2);
    //     GlobalUnlock(uVar4);
    //     uVar4 = GlobalHandle(piVar2);
    //     GlobalFree(uVar4);
    //   }
    //   else {
    //     if (ptVar5->biCompression == 3) {
    //       iVar3 = ptVar5->biSize + 0xc;
    //     }
    //     else {
    //       iVar3 = ptVar5->biSize + ptVar5->biClrUsed * 4;
    //     }
    //     iVar3 = GetDIBits(uVar1,unaff_EBP,0,ptVar5->biHeight,(int)&ptVar5->biSize + iVar3,ptVar5,
    //                       bm.bmHeight);
    //     uVar7 = ptVar5->biClrUsed;
    //     if ((uVar7 == 0) && (ptVar5->biBitCount < 9)) {
    //       uVar7 = 1 << ((byte)ptVar5->biBitCount & 0x1f);
    //     }
    //     uVar6 = ptVar5->biSizeImage;
    //     ptVar5->biClrUsed = uVar7;
    //     if (uVar6 == 0) {
    //       uVar6 = (ptVar5->biWidth * (uint)ptVar5->biBitCount + 0x1f >> 3 & 0x1ffffffc) *
    //               ptVar5->biHeight;
    //     }
    //     ptVar5->biSizeImage = uVar6;
    //     if (iVar3 != 0) goto LAB_0043a307;
    //     DibFree(ptVar5);
    //   }

// TODO: Additional parity reference block from dib.cpp.decomp for palette remap paths.

// Offset: 0x0043A660
void DibMapToPalette(tagBITMAPINFOHEADER* param_1, void* param_2, int param_3, int param_4) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: ZeroIndex */
    // /* void __cdecl DibMapToPalette(struct tagBITMAPINFOHEADER *,void *,int,int) */
    // 
    // void __cdecl DibMapToPalette(tagBITMAPINFOHEADER *param_1,void *param_2,int param_3,int param_4)
    // 
    // {
    //   tagRGBQUAD *ptVar1;
    //   ulong uVar2;
    //   uchar *puVar3;
    //   char cVar4;
    //   uchar uVar5;
    //   undefined4 uVar6;
    //   uint uVar7;
    //   uint uVar8;
    //   undefined1 *puVar9;
    //   tagPALETTEENTRY tVar10;
    //   int iVar11;
    //   uchar ZeroIndex;
    //   uchar *lpBits;
    //   ulong SizeImage;
    //   int nPalColors;
    //   int nDibColors;
    //   tagRGBQUAD *lpRgb;
    //   tagPALETTEENTRY pe;
    //   int ZeroBlue;
    //   uchar TransIndex;
    //   int HitEnd;
    //   uchar xlat [256];
    //   
    //   puVar3 = lpBits;
    //   nDibColors = 0;
    //   lpBits = (uchar *)((uint)lpBits & 0xffffff);
    //   HitEnd = HitEnd & 0xffffff00;
    //   if (param_2 == (void *)0x0) {
    //     return;
    //   }
    //   if (param_1 == (tagBITMAPINFOHEADER *)0x0) {
    //     return;
    //   }
    //   tVar10 = (tagPALETTEENTRY)((int)&param_1->biSize + param_1->biSize);
    //   pe = tVar10;
    //   GetObjectA(param_2,4,&nDibColors);
    //   ptVar1 = (tagRGBQUAD *)param_1->biClrUsed;
    //   lpRgb = ptVar1;
    //   if ((ptVar1 == (tagRGBQUAD *)0x0) && (param_1->biBitCount < 9)) {
    //     lpRgb = (tagRGBQUAD *)(1 << ((byte)param_1->biBitCount & 0x1f));
    //   }
    //   nPalColors = param_1->biSizeImage;
    //   if (nPalColors == 0) {
    //     nPalColors = (param_1->biWidth * (uint)param_1->biBitCount + 0x1f >> 3 & 0x1ffffffc) *
    //                  param_1->biHeight;
    //   }
    //   if (param_1->biCompression == 3) {
    //     iVar11 = param_1->biSize + 0xc;
    //   }
    //   else {
    //     iVar11 = param_1->biSize + (int)ptVar1 * 4;
    //   }
    //   SizeImage = (int)&param_1->biSize + iVar11;
    //   if (param_3 != 0) {
    //     if (param_4 == 0) {
    //       HitEnd = CONCAT31(HitEnd._1_3_,
    //                         *(undefined1 *)
    //                          ((param_1->biWidth + 3U & 0xfffffffc) * (param_1->biHeight + -1) +
    //                          SizeImage));
    //     }
    //     else {
    //       HitEnd = (uint)HitEnd._1_3_ << 8;
    //     }
    //     uVar8 = (uint)*(byte *)((int)tVar10 + 2);
    //     uVar7 = (uint)*(byte *)((int)pe + 1);
    //     lpBits = (uchar *)((uint)puVar3 & 0xffffff);
    //     _TransIndex = (uint)*(byte *)pe;
    //     xlat[0] = '\0';
    //     xlat[1] = '\0';
    //     xlat[2] = '\0';
    //     xlat[3] = '\0';
    //     iVar11 = 1;
    //     do {
    //       uVar8 = uVar8 + iVar11;
    //       uVar7 = uVar7 + iVar11;
    //       _TransIndex = _TransIndex + iVar11;
    //       if ((((0xff < (int)uVar8) || (0xff < (int)uVar7)) || (0xff < (int)_TransIndex)) ||
    //          ((((int)uVar8 < 0 || ((int)uVar7 < 0)) || ((int)_TransIndex < 0)))) {
    //         if (xlat._0_4_ != 0) break;
    //         iVar11 = -1;
    //         uVar8 = (uint)*(byte *)((int)pe + 2);
    //         uVar7 = (uint)*(byte *)((int)pe + 1);
    //         _TransIndex = (uint)*(byte *)pe;
    //         xlat[0] = '\x01';
    //         xlat[1] = '\0';
    //         xlat[2] = '\0';
    //         xlat[3] = '\0';
    //       }
    //       cVar4 = GetNearestPaletteIndex
    //                         (param_2,(uint)CONCAT11((char)_TransIndex,(char)uVar7) << 8 | uVar8 & 0xff);
    //       lpBits = (uchar *)CONCAT13(cVar4,lpBits._0_3_);
    //     } while (cVar4 == '\0');
    //   }
    //   uVar8 = 0;
    //   if (0 < (int)lpRgb) {
    //     puVar9 = (undefined1 *)((int)pe + 2);
    //     do {
    //       if (param_3 == 0) {
    //         uVar5 = GetNearestPaletteIndex
    //                           (param_2,(uint)CONCAT21(CONCAT11(puVar9[-2],puVar9[-1]),*puVar9));
    //         xlat[uVar8 + 4] = uVar5;
    //       }
    //       else if (uVar8 == (HitEnd & 0xffU)) {
    //         xlat[uVar8 + 4] = '\0';
    //       }
    //       else {
    //         uVar5 = GetNearestPaletteIndex
    //                           (param_2,(uint)CONCAT21(CONCAT11(puVar9[-2],puVar9[-1]),*puVar9));
    //         xlat[uVar8 + 4] = uVar5;
    //         if (uVar5 == '\0') {
    //           xlat[uVar8 + 4] = lpBits._3_1_;
    //         }
    //       }
    //       uVar8 = uVar8 + 1;
    //       puVar9 = puVar9 + 4;
    //     } while ((int)uVar8 < (int)lpRgb);
    //   }
    //   param_1->biClrUsed = nDibColors;
    //   if ((int)lpRgb < nDibColors) {
    //     uVar6 = GlobalHandle(param_1);
    //     GlobalUnlock(uVar6);
    //     uVar6 = GlobalHandle(param_1,lpBits + param_1->biSize + SizeImage * 4,0);
    //     uVar6 = GlobalReAlloc(uVar6);
    //     GlobalLock(uVar6);
    //     if (param_1->biCompression == 3) {
    //       iVar11 = param_1->biSize + 0xc;
    //     }
    //     else {
    //       iVar11 = param_1->biSize + param_1->biClrUsed * 4;
    //     }
    //     memmove((int)&param_1->biSize + iVar11,SizeImage,lpBits);
    //     if (param_1->biCompression == 3) {
    //       SizeImage = (int)&param_1->biPlanes + param_1->biSize;
    //       goto LAB_0043a9a9;
    //     }
    //   }
    //   else {
    //     if ((int)lpRgb <= nDibColors) goto LAB_0043a9a9;
    //     if (param_1->biCompression == 3) {
    //       iVar11 = param_1->biSize + 0xc;
    //     }
    //     else {
    //       iVar11 = param_1->biSize + nDibColors * 4;
    //     }
    //     memcpy((int)&param_1->biSize + iVar11,SizeImage,nPalColors);
    //     uVar6 = GlobalHandle(param_1);
    //     GlobalUnlock(uVar6);
    //     uVar6 = GlobalHandle(param_1,lpBits + param_1->biSize + SizeImage * 4,0);
    //     uVar6 = GlobalReAlloc(uVar6);
    //     GlobalLock(uVar6);
    //     if (param_1->biCompression == 3) {
    //       SizeImage = (int)&param_1->biPlanes + param_1->biSize;
    //       goto LAB_0043a9a9;
    //     }
    //   }
    //   SizeImage = (int)&param_1->biSize + param_1->biSize + param_1->biClrUsed * 4;
    // LAB_0043a9a9:
    //   uVar2 = param_1->biCompression;
    //   if (uVar2 == 0) {
    //     if (param_1->biBitCount == 8) {
    //       xlatClut8();
    //     }
    //     else {
    //       xlatClut4(SizeImage,nPalColors,xlat + 4);
    //     }
    //   }
    //   else if (uVar2 == 1) {
    //     xlatRle8(SizeImage,nPalColors,xlat + 4);
    //   }
    //   else if (uVar2 == 2) {
    //     xlatRle4(SizeImage,nPalColors,xlat + 4);
    //   }
    //   iVar11 = 0;
    //   if (0 < nDibColors) {
    //     puVar9 = (undefined1 *)((int)pe + 1);
    //     do {
    //       GetPaletteEntries(param_2,iVar11,1,&ZeroBlue);
    //       iVar11 = iVar11 + 1;
    //       puVar9[1] = (undefined1)ZeroBlue;
    //       *puVar9 = ZeroBlue._1_1_;
    //       puVar9[-1] = ZeroBlue._2_1_;
    //       puVar9[2] = 0;
    //       puVar9 = puVar9 + 4;
    //     } while (iVar11 < nDibColors);
    //   }
    //   return;
    // }
    // 
    // 
}

#endif

