#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>
#include "../include/common.h"
#include "../include/LINEINFO.h"
#include "../include/TRANSINFO.h"
#include "../include/Res_file.h"
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

/**
 * Parses a JASC-PAL color line (three space-separated integers)
 */
static bool parse_pal_line(char* line, BYTE* r, BYTE* g, BYTE* b) {
    char* p = line;
    while (*p && (*p == ' ' || *p == '\t')) p++;
    if (!*p) return false;
    *r = (BYTE)atoi(p);
    
    while (*p && *p != ' ' && *p != '\t') p++;
    while (*p && (*p == ' ' || *p == '\t')) p++;
    if (!*p) return false;
    *g = (BYTE)atoi(p);
    
    while (*p && *p != ' ' && *p != '\t') p++;
    while (*p && (*p == ' ' || *p == '\t')) p++;
    if (!*p) return false;
    *b = (BYTE)atoi(p);
    
    return true;
}

/**
 * Loads a palette from a file or resource.
 * Supports JASC-PAL text format.
 */
void* ReadPalette(char* filename, long resource_id, int flag) {
    unsigned char* data = nullptr;
    int size = 0;
    int out_type = 0;
    bool own_mem = false;

    // 1. Try loading from file first
    if (filename && filename[0] != '\0') {
        int fd = _open(filename, _O_RDONLY | _O_BINARY);
        if (fd != -1) {
            long fileSize = _lseek(fd, 0, SEEK_END);
            _lseek(fd, 0, SEEK_SET);
            data = (unsigned char*)malloc(fileSize + 1);
            if (data) {
                _read(fd, data, fileSize);
                data[fileSize] = '\0';
                size = fileSize;
                own_mem = true;
            }
            _close(fd);
        }
    }

    // 2. Try loading from resource if file failed or resource_id is specified
    if (!data && resource_id != -1) {
        // ASM uses 'bina' (0x62696e61) tag for palette resources (see Dib.cpp.asm line 2116)
        data = RESFILE_load(0x62696e61, resource_id, &size, &out_type);
        if (data) {
            // If RESFILE_load returned mapped memory, we might need a copy to null-terminate for strtok
            if (out_type == 0) {
                unsigned char* copy = (unsigned char*)malloc(size + 1);
                if (copy) {
                    memcpy(copy, data, size);
                    copy[size] = '\0';
                    data = copy;
                    own_mem = true;
                }
            } else {
                // If it's already a malloc'd buffer, we still need to ensure space for null termination
                // but RESFILE_load doesn't guarantee that. Let's just assume text parsing works or realloc.
                // For safety, let's always work with a null-terminated copy if we suspect text format.
                unsigned char* copy = (unsigned char*)malloc(size + 1);
                if (copy) {
                    memcpy(copy, data, size);
                    copy[size] = '\0';
                    free(data); // Free the one from RESFILE_load
                    data = copy;
                    own_mem = true;
                }
            }
        }
    }

    if (!data) {
        CUSTOM_DEBUG_LOG_FMT("ReadPalette: failed to load '%s' / id %d", filename ? filename : "(null)", (int)resource_id);
        return nullptr;
    }

    HPALETTE hPal = nullptr;

    // Check for "JASC-PAL" header
    if (strncmp((char*)data, "JASC-PAL", 8) == 0) {
        CUSTOM_DEBUG_LOG_FMT("ReadPalette: parsing JASC-PAL '%s' / id %d", filename ? filename : "(null)", (int)resource_id);
		CUSTOM_DEBUG_LOG_FMT("ReadPalette: raw header: %.20s", (char*)data);
        // Parse JASC-PAL format
        // Line 1: JASC-PAL
        // Line 2: 0100 (version)
        // Line 3: Number of colors
        // Rest: R G B lines
        char* ctx = nullptr;
        char* line = strtok_s((char*)data, "\r\n", &ctx); // JASC-PAL
        line = strtok_s(nullptr, "\r\n", &ctx); // 0100
        line = strtok_s(nullptr, "\r\n", &ctx); // Count
        
        if (line) {
            int numColors = atoi(line);
            if (numColors > 0 && numColors <= 256) {
                LOGPALETTE* lp = (LOGPALETTE*)malloc(sizeof(LOGPALETTE) + (numColors * sizeof(PALETTEENTRY)));
                if (lp) {
                    lp->palVersion = 0x300;
                    lp->palNumEntries = (WORD)numColors;
                    
                    for (int i = 0; i < numColors; ++i) {
                        line = strtok_s(nullptr, "\r\n", &ctx);
                        if (line) {
                            parse_pal_line(line, &lp->palPalEntry[i].peRed, &lp->palPalEntry[i].peGreen, &lp->palPalEntry[i].peBlue);
                            lp->palPalEntry[i].peFlags = 0;
                        }
                    }
                    
                    hPal = CreatePalette(lp);
                    free(lp);
                }
            }
        }
    }

    if (own_mem) free(data);

    if (hPal && flag) {
        // CreateIdentityPalette(hPal);
    }

    return hPal;
}

/**
 * Ensures the palette is "identity", meaning it doesn't cause system color mapping issues
 * in 256-color modes. It copies system colors 0-9 and 246-255.
 */
void CreateIdentityPalette(void* pal) {
    HPALETTE hPal = (HPALETTE)pal;
    if (!hPal) return;

    PALETTEENTRY sysEntries[256];
    HDC hdc = GetDC(NULL);
    GetSystemPaletteEntries(hdc, 0, 256, sysEntries);
    ReleaseDC(NULL, hdc);

    // Identity palette logic:
    // We want the system to avoid remapping our palette indices if possible.
    // Usually involves setting peFlags to PC_NOCOLLAPSE or matching system static colors.
    
    // ASM seems to do some complex mapping. For now, we'll use a standard approach:
    // Copy the 20 system static colors into our palette.
    SetPaletteEntries(hPal, 0, 10, &sysEntries[0]);
    SetPaletteEntries(hPal, 246, 10, &sysEntries[246]);
}
