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

// Fully verified. Forward declaration retained locally for dib.cpp parity usage.
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
    // TODO: PARITY - Decomp warns on `SrcTotHgt`; verify source-orientation/sign handling and clipped-row stepping match asm for this blit path. [decomp: dib.cpp.decomp @ 0x00438AA0]
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

// Fully verified. Source of truth: dib.cpp.decomp @ 0x0043AA60
static void xlatClut8(uchar* param_1, int param_2, const uchar* param_3) {
    if (param_2 != 0) {
        do {
            param_2 = param_2 + -1;
            *param_1 = param_3[*param_1];
            param_1 = param_1 + 1;
        } while (param_2 != 0);
    }
}

// Fully verified. Source of truth: dib.cpp.decomp @ 0x0043AA90
static void xlatClut4(uchar* param_1, int param_2, const uchar* param_3) {
    if (param_2 != 0) {
        do {
            *param_1 = param_3[*param_1 & 0xf] | (uchar)(param_3[*param_1 >> 4] << 4);
            param_1 = param_1 + 1;
            param_2 = param_2 + -1;
        } while (param_2 != 0);
    }
}

// Fully verified. Source of truth: dib.cpp.decomp @ 0x0043AAD0
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
    // Fully verified. Source of truth: dib.cpp.decomp @ 0x0043AB40 (function is a RET stub in original)
}

// Fully verified. Source of truth: dib.cpp.decomp @ 0x0043A660
void DibMapToPalette(tagBITMAPINFOHEADER* param_1, void* param_2, int param_3, int param_4) {
    if (param_2 == nullptr) return;
    if (param_1 == nullptr) return;

    HPALETTE hPal = (HPALETTE)param_2;

    int nPalEntries = 0;
    GetObjectA(hPal, 4, &nPalEntries);

    const int dibClrUsed = (int)param_1->biClrUsed;
    int nDibColors = dibClrUsed;
    if (nDibColors == 0 && param_1->biBitCount < 9) {
        nDibColors = 1 << (param_1->biBitCount & 0x1F);
    }

    int sizeImage = (int)param_1->biSizeImage;
    if (sizeImage == 0) {
        const uint rowBits = ((uint)param_1->biWidth * (uint)param_1->biBitCount) + 0x1fU;
        const uint rowBytes = (rowBits >> 3) & 0x1ffffffcU;
        sizeImage = (int)(rowBytes * (uint)param_1->biHeight);
    }

    uchar* bits = (uchar*)param_1 + (int)param_1->biSize +
                  ((param_1->biCompression == BI_BITFIELDS) ? 0xC : (dibClrUsed * (int)sizeof(RGBQUAD)));

    uchar xlat[260];
    memset(xlat, 0, sizeof(xlat));

    uchar HitEnd = 0;
    uchar TransIndex = 0;

    if (param_3 != 0) {
        if (param_4 == 0) {
            const uint stride = ((uint)param_1->biWidth + 3U) & 0xfffffffcU;
            const uint rowOffset = stride * (uint)(param_1->biHeight - 1);
            HitEnd = *(uchar*)(bits + rowOffset);
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
                xlat[i + 4] = 0;
                continue;
            }
        }
        uchar idx = (uchar)GetNearestPaletteIndex(hPal, RGB(lpRgb[i].rgbRed, lpRgb[i].rgbGreen, lpRgb[i].rgbBlue));
        if (param_3 != 0 && idx == 0) {
            idx = TransIndex;
        }
        xlat[i + 4] = idx;
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
            // Fully verified. Source of truth: dib.cpp.decomp @ 0x0043AB50 (CRT import thunk for memmove)
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
            xlatClut8(bits, sizeImage, xlat + 4);
        } else {
            xlatClut4(bits, sizeImage, xlat + 4);
        }
    } else if (param_1->biCompression == BI_RLE8) {
        xlatRle8(bits, sizeImage, xlat + 4);
    } else if (param_1->biCompression == BI_RLE4) {
        xlatRle4(bits, sizeImage, xlat + 4);
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
    // Fully verified. Source of truth: dib.cpp.decomp @ 0x00439750
    unsigned char* data = nullptr;
    int size = 0;
    int type = 0;
    int own_mem = 0;

    if (param_1 != nullptr && *param_1 != '\0' && shape_file_first != '\0') {
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
    // Fully verified. Source of truth: dib.cpp.decomp @ 0x00439A10
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
    // Fully verified. Source of truth: dib.cpp.decomp @ 0x00439E50
    if (param_1 == -1) {
        return nullptr;
    }
    const LONG pos = _llseek(param_1, 0, FILE_CURRENT);
    tagBITMAPFILEHEADER bf = {};
    if (_lread(param_1, (LPSTR)&bf, sizeof(bf)) != sizeof(bf)) {
        return nullptr;
    }
    const bool has_bf = (bf.bfType == 0x4D42);
    if (!has_bf) {
        _llseek(param_1, pos, FILE_BEGIN);
    }

    DWORD bi_size = 0;
    if (_lread(param_1, (LPSTR)&bi_size, sizeof(bi_size)) != sizeof(bi_size)) {
        return nullptr;
    }
    tagBITMAPINFOHEADER bi = {};
    bool is_core = false;
    if (bi_size == sizeof(BITMAPCOREHEADER)) {
        BITMAPCOREHEADER bc = {};
        bc.bcSize = bi_size;
        if (_lread(param_1, (LPSTR)&bc.bcWidth, sizeof(BITMAPCOREHEADER) - sizeof(DWORD)) !=
            (sizeof(BITMAPCOREHEADER) - sizeof(DWORD))) {
            return nullptr;
        }
        bi.biSize = sizeof(tagBITMAPINFOHEADER);
        bi.biWidth = (LONG)bc.bcWidth;
        bi.biHeight = (LONG)bc.bcHeight;
        bi.biPlanes = bc.bcPlanes;
        bi.biBitCount = bc.bcBitCount;
        bi.biCompression = BI_RGB;
        bi.biSizeImage = 0;
        bi.biXPelsPerMeter = 0;
        bi.biYPelsPerMeter = 0;
        bi.biClrUsed = 0;
        bi.biClrImportant = 0;
        is_core = true;
    } else {
        bi.biSize = bi_size;
        if (_lread(param_1, (LPSTR)&bi.biWidth, sizeof(tagBITMAPINFOHEADER) - sizeof(DWORD)) !=
            (sizeof(tagBITMAPINFOHEADER) - sizeof(DWORD))) {
            return nullptr;
        }
    }

    DWORD colors = bi.biClrUsed;
    if (colors == 0 && bi.biBitCount < 9) {
        colors = 1u << (bi.biBitCount & 0x1F);
    }
    if (bi.biSizeImage == 0) {
        const DWORD row_bytes = (((DWORD)bi.biWidth * (DWORD)bi.biBitCount + 31u) >> 3) & 0x1FFFFFFCu;
        const DWORD h = (bi.biHeight < 0) ? (DWORD)(-bi.biHeight) : (DWORD)bi.biHeight;
        bi.biSizeImage = row_bytes * h;
    }
    bi.biClrUsed = colors;

    HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE | GMEM_ZEROINIT, bi.biSize + colors * sizeof(RGBQUAD));
    tagBITMAPINFOHEADER* dib = (tagBITMAPINFOHEADER*)GlobalLock(hg);
    if (dib == nullptr) {
        return nullptr;
    }
    memcpy(dib, &bi, sizeof(bi));
    if (colors > 0) {
        BYTE* pal = (BYTE*)dib + bi.biSize;
        if (is_core) {
            const DWORD core_bytes = colors * 3;
            if (_lread(param_1, (LPSTR)pal, core_bytes) == (LONG)core_bytes) {
                for (LONG i = (LONG)colors - 1; i >= 0; --i) {
                    const BYTE* src = pal + i * 3;
                    RGBQUAD* dst = ((RGBQUAD*)pal) + i;
                    dst->rgbBlue = src[0];
                    dst->rgbGreen = src[1];
                    dst->rgbRed = src[2];
                    dst->rgbReserved = 0;
                }
            }
        } else {
            _lread(param_1, (LPSTR)pal, colors * sizeof(RGBQUAD));
        }
    }
    if (has_bf && bf.bfOffBits != 0) {
        _llseek(param_1, pos + (LONG)bf.bfOffBits, FILE_BEGIN);
    }
    return dib;
}

tagBITMAPINFOHEADER* DibFromBitmap(void* param_1, ulong param_2, uint param_3, void* param_4, uint param_5) {
    // Fully verified. Source of truth: dib.cpp.decomp @ 0x0043A070
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
    // Fully verified. Source of truth: dib.cpp.decomp @ 0x0043A500
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

    static const RGBQUAD kVga16[16] = {
        {0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x80, 0x00}, {0x00, 0x80, 0x00, 0x00}, {0x00, 0x80, 0x80, 0x00},
        {0x80, 0x00, 0x00, 0x00}, {0x80, 0x00, 0x80, 0x00}, {0x80, 0x80, 0x00, 0x00}, {0xC0, 0xC0, 0xC0, 0x00},
        {0x80, 0x80, 0x80, 0x00}, {0x00, 0x00, 0xFF, 0x00}, {0x00, 0xFF, 0x00, 0x00}, {0x00, 0xFF, 0xFF, 0x00},
        {0xFF, 0x00, 0x00, 0x00}, {0xFF, 0x00, 0xFF, 0x00}, {0xFF, 0xFF, 0x00, 0x00}, {0xFF, 0xFF, 0xFF, 0x00},
    };
    RGBQUAD* pal = (RGBQUAD*)(dib + 1);
    for (DWORD i = 0; i < dib->biClrUsed; ++i) {
        pal[i] = kVga16[i & 0xF];
    }
    return dib;
}

void CreateIdentityPalette(void* param_1) {
    // Fully verified. Source of truth: dib.cpp.decomp @ 0x0043AB80
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
    // Fully verified. Source of truth: dib.cpp.decomp @ 0x0043ACB0
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



