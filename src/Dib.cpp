
#include "../include/dib.h"
#include "../include/drawarea.h"
#include "../include/basegame.h"
#include "../include/Shape.h"
#include "../include/Res_file.h"
#include <windowsx.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

#include "../include/rge_base_game_global.h"

// The target reserves 0x1400 bytes from SrcXTbl to the next global.
static long SrcXTbl[0x500];


extern "C" char* __cdecl strtok(char*, const char*);
extern "C" long __cdecl atol(const char*);
extern "C" int __cdecl atoi(const char*);

#pragma function(memcpy)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);

void __cdecl DibBlt(BITMAPINFO256* dstInfo, uchar* dst, RECT* dstRect,
                    long dx, long dy, long dw, long dh,
                    BITMAPINFO256* srcInfo, uchar* src,
                    long sx, long sy, long sw, long sh,
                    int doClip, int flipX, int flipY)
{
    if (doClip != 0 &&
        ClipDibBlt(dstInfo, dstRect, dx, dy, dw, dh,
                   sx, sy, sw, sh, flipX, flipY) == 0)
        return;

    long dstStride;
    long dstHeight;
    long dstOrientation;
    long srcStride;
    long srcHeight;
    long srcOrientation;

    GetDibDim(dstInfo, dstStride, dstHeight, dstOrientation);
    GetDibDim(srcInfo, srcStride, srcHeight, srcOrientation);
    if (flipY != 0)
        srcOrientation = -srcOrientation;

    long xStep = (sw << 8) / dw;
    long yStep = (sh << 8) / dh;
    long dstRow;
    if (dstOrientation == 1)
        dstRow = dy;
    else
        dstRow = dstHeight - dy - 1;
    uchar* dstLine = dst + dstRow * dstStride + dx;

    if (xStep == 0x100 && yStep == 0x100 && flipX == 0) {
        long srcRow;
        if (srcOrientation == 1)
            srcRow = sy;
        else
            srcRow = srcHeight - sy - 1;

        uchar* srcLine = src + srcRow * srcStride + sx;
        long dstLineStep = dstOrientation * dstStride;
        long srcLineStep = srcOrientation * srcStride;
        long row = 0;
        if (dh > 0) {
            do {
                memcpy(dstLine, srcLine, dw);
                dstLine += dstLineStep;
                srcLine += srcLineStep;
                ++row;
            } while (row < dh);
        }
        return;
    }

    long srcPosition = sx;
    if (flipX == 0) {
        if (dw > 0) {
            long* entry = SrcXTbl;
            long remaining = dw;
            do {
                *entry++ = srcPosition >> 8;
                srcPosition += xStep;
                --remaining;
            } while (remaining != 0);
        }
    } else {
        long remaining = dw - 1;
        if (remaining >= 0) {
            long* entry = SrcXTbl + remaining;
            ++remaining;
            do {
                *entry-- = srcPosition >> 8;
                srcPosition += xStep;
                --remaining;
            } while (remaining != 0);
        }
    }

    long dstLineStep = dstOrientation * dstStride;
    long srcY = sy << 8;
    long row = 0;
    if (dh > 0) {
        do {
            long srcRow;
            if (srcOrientation == 1)
                srcRow = srcY >> 8;
            else
                srcRow = srcHeight - (srcY >> 8) - 1;

            uchar* srcLine = src + srcRow * srcStride + sx;
            long x = 0;
            if (dw > 0) {
                long* entry = SrcXTbl;
                do {
                    dstLine[x] = srcLine[*entry++];
                    ++x;
                } while (x < dw);
            }
            srcY += yStep;
            dstLine += dstLineStep;
            ++row;
        } while (row < dh);
    }
}

void __cdecl TransDibBlt(BITMAPINFO256* dstInfo, uchar* dst, RECT* dstRect,
                         long dx, long dy, long dw, long dh,
                         BITMAPINFO256* srcInfo, uchar* src,
                         TRANSINFO* transInfo,
                         long sx, long sy, long sw, long sh,
                         int doClip, int flipX, int flipY, int transColor)
{
    if (transInfo != 0 && transInfo->AnyTrans == 0) {
        DibBlt(dstInfo, dst, dstRect, dx, dy, dw, dh,
               srcInfo, src, sx, sy, sw, sh, doClip, flipX, flipY);
        return;
    }

    if (transColor < 0)
        transColor = 0;

    if (doClip != 0 &&
        ClipDibBlt(dstInfo, dstRect, dx, dy, dw, dh,
                   sx, sy, sw, sh, flipX, flipY) == 0)
        return;

    long xStep = (sw << 8) / dw;
    long yStep = (sh << 8) / dh;
    long dstStride;
    long dstHeight;
    long dstOrientation;
    long srcStride;
    long srcHeight;
    long srcOrientation;

    GetDibDim(dstInfo, dstStride, dstHeight, dstOrientation);
    GetDibDim(srcInfo, srcStride, srcHeight, srcOrientation);
    if (flipY != 0)
        srcOrientation = -srcOrientation;

    long dstPerSrc = (dw << 8) / sw;
    long dstRow;
    if (dstOrientation == 1)
        dstRow = dy;
    else
        dstRow = dstHeight - dy - 1;
    uchar* dstLine = dst + dstRow * dstStride + dx;

    long srcPosition = sx;
    if (flipX == 0) {
        if (dw > 0) {
            long* entry = SrcXTbl;
            long remaining = dw;
            do {
                *entry++ = srcPosition >> 8;
                srcPosition += xStep;
                --remaining;
            } while (remaining != 0);
        }
    } else {
        long remaining = dw - 1;
        if (remaining >= 0) {
            long* entry = SrcXTbl + remaining;
            ++remaining;
            do {
                *entry-- = srcPosition >> 8;
                srcPosition += xStep;
                --remaining;
            } while (remaining != 0);
        }
    }

    long dstLineStep = dstOrientation * dstStride;
    long srcY = sy << 8;
    long row = 0;

    if (flipX == 0 && transInfo != 0 && transInfo->LineInfo != 0) {
        LINEINFO* lineInfo = transInfo->LineInfo;
        if (dh > 0) {
            do {
                long srcLineNumber = srcY >> 8;
                long srcRow;
                if (srcOrientation == 1)
                    srcRow = srcLineNumber;
                else
                    srcRow = srcHeight - srcLineNumber - 1;
                uchar* srcLine = src + srcRow * srcStride + sx;
                LINEINFO* line = lineInfo + srcLineNumber;

                if (line->AllTrans == 0) {
                    long first;
                    if (line->StartX < sx)
                        first = 0;
                    else
                        first = ((line->StartX - sx) * dstPerSrc) >> 8;

                    long last = ((line->EndX - sx + 1) * dstPerSrc) >> 8;
                    if (last > dw)
                        last = dw;

                    if (first < last) {
                        if (dstPerSrc == 0x100 && line->MidSolid != 0) {
                            memcpy(dstLine + first, srcLine + first,
                                   last - first);
                        } else {
                            long x = first;
                            do {
                                uchar color = srcLine[SrcXTbl[x]];
                                if ((unsigned int)color !=
                                    (unsigned int)transColor)
                                    dstLine[x] = color;
                                ++x;
                            } while (x < last);
                        }
                    }
                }

                dstLine += dstLineStep;
                srcY += yStep;
                ++row;
            } while (row < dh);
        }
        return;
    }

    if (dh > 0) {
        do {
            long srcLineNumber = srcY >> 8;
            long srcRow;
            if (srcOrientation == 1)
                srcRow = srcLineNumber;
            else
                srcRow = srcHeight - srcLineNumber - 1;
            uchar* srcLine = src + srcRow * srcStride + sx;

            long x = 0;
            if (dw > 0) {
                do {
                    uchar color = srcLine[SrcXTbl[x]];
                    if ((unsigned int)color != (unsigned int)transColor)
                        dstLine[x] = color;
                    ++x;
                } while (x < dw);
            }

            dstLine += dstLineStep;
            srcY += yStep;
            ++row;
        } while (row < dh);
    }
}

int __cdecl ClipDibBlt(BITMAPINFO256* dib, RECT* rect,
    LONG& x, LONG& y, LONG& width, LONG& height,
    LONG& src_x, LONG& src_y, LONG& src_width, LONG& src_height,
    int flip_x, int flip_y)
{
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;

    if (rect != 0) {
        left = rect->left;
        top = rect->top;
        right = rect->right + 1;
        bottom = rect->bottom + 1;
    } else {
        left = 0;
        top = 0;
        right = dib->bmiHeader.biWidth;
        bottom = dib->bmiHeader.biHeight;
    }

    if (bottom < 0)
        bottom = -bottom;
    right--;
    bottom--;

    if (x <= right && y <= bottom &&
        width + x - 1 >= left &&
        height + y - 1 >= top && width >= 1 && height >= 1) {
        LONG x_scale = (src_width << 8) / width;
        LONG y_scale = (src_height << 8) / height;

        if (x < left) {
            LONG delta = left - x;
            x = left;
            width -= delta;
            LONG scaled = (delta << 8) * x_scale >> 16;
            if (flip_x == 0)
                src_x += scaled;
            src_width -= scaled;
        }

        if (y < top) {
            LONG delta = top - y;
            y = top;
            height -= delta;
            LONG scaled = (delta << 8) * y_scale >> 16;
            if (flip_y == 0)
                src_y += scaled;
            src_height -= scaled;
        }

        LONG end = x + width;
        if (end - 1 > right) {
            LONG delta = end - right - 1;
            width -= delta;
            LONG scaled = (delta << 8) * x_scale >> 16;
            src_width -= scaled;
            if (flip_x != 0)
                src_x += scaled;
        }

        end = y + height;
        if (end - 1 > bottom) {
            LONG delta = end - bottom - 1;
            height -= delta;
            LONG scaled = (delta << 8) * y_scale >> 16;
            src_height -= scaled;
            if (flip_y != 0)
                src_y += scaled;
        }

        if (width >= 1 && height >= 1 && src_width >= 1 && src_height >= 1)
            return 1;
    }
    return 0;
}

void __cdecl GetDibDim(BITMAPINFO256* param_1, long& param_2, long& param_3, long& param_4)
{
    param_2 = (param_1->bmiHeader.biWidth + 3) & 0xFFFFFFFC;
    param_3 = param_1->bmiHeader.biHeight;
    if (param_3 < 0) {
        param_3 = -param_3;
        param_4 = 1;
        return;
    }
    param_4 = -1;
}

long __cdecl TileDibBlt(BITMAPINFO256* DestInfo, uchar* DestBits,
    RECT* ClipRect, long DestX, long DestY, long DestWid, long DestHgt,
    long BlockWid, long BlockHgt, BITMAPINFO256* SrcInfo, uchar* SrcBits,
    TRANSINFO* TransInfo, long SrcX, long SrcY, long SrcWid, long SrcHgt,
    int Trans, int Mirror, int Flip)
{
    long xScale = (SrcWid << 8) / BlockWid;
    long yScale = (SrcHgt << 8) / BlockHgt;

    if (SrcX < 0)
        SrcX += SrcWid;
    if (SrcY < 0)
        SrcY += SrcHgt;

    while (SrcX >= SrcWid)
        SrcX -= SrcWid;
    while (SrcY >= SrcHgt)
        SrcY -= SrcHgt;

    long SrcRtWid = SrcWid - SrcX;
    long SrcBotHgt = SrcHgt - SrcY;
    long SrcLtWid = SrcWid - SrcRtWid;
    long sxSkip = SrcX - SrcLtWid;
    long SrcTopHgt = SrcHgt - SrcBotHgt;
    long sySkip = SrcY - SrcTopHgt;

    long DestLtWid = ((SrcRtWid << 16) / xScale) >> 8;
    long DestRtWid = BlockWid - DestLtWid;
    long DestTopHgt = ((SrcBotHgt << 16) / yScale) >> 8;
    long DestBotHgt = BlockHgt - DestTopHgt;

    long xBlocks;
    long yBlocks;
    if (BlockWid >= DestWid && BlockHgt >= DestHgt) {
        xBlocks = 1;
        yBlocks = 1;
    } else {
        xBlocks = DestWid / BlockWid;
        if (xBlocks * BlockWid < DestWid)
            ++xBlocks;
        yBlocks = DestHgt / BlockHgt;
        if (yBlocks * BlockHgt < DestHgt)
            ++yBlocks;
    }

    long yRemaining = yBlocks;
    if (Trans != 0) {
        if (yRemaining > 0) {
            do {
                long DestY1 = DestY + DestTopHgt;
                long xRemaining = xBlocks;
                long x = DestX;
                if (xRemaining > 0) {
                    do {
                        if (DestTopHgt != 0) {
                            if (DestLtWid != 0) {
                                TransDibBlt(DestInfo, DestBits, ClipRect,
                                    x, DestY, DestLtWid, DestTopHgt,
                                    SrcInfo, SrcBits, TransInfo,
                                    SrcX, SrcY, SrcRtWid, SrcBotHgt,
                                    1, Mirror, Flip, 0);
                            }
                            if (DestRtWid != 0) {
                                TransDibBlt(DestInfo, DestBits, ClipRect,
                                    x + DestLtWid, DestY,
                                    DestRtWid, DestTopHgt,
                                    SrcInfo, SrcBits, TransInfo,
                                    sxSkip, SrcY, SrcLtWid, SrcBotHgt,
                                    1, Mirror, Flip, 0);
                            }
                        }
                        if (DestBotHgt != 0) {
                            if (DestLtWid != 0) {
                                TransDibBlt(DestInfo, DestBits, ClipRect,
                                    x, DestY1, DestLtWid, DestBotHgt,
                                    SrcInfo, SrcBits, TransInfo,
                                    SrcX, sySkip, SrcRtWid, SrcTopHgt,
                                    1, Mirror, Flip, 0);
                            }
                            if (DestRtWid != 0) {
                                TransDibBlt(DestInfo, DestBits, ClipRect,
                                    x + DestLtWid, DestY1,
                                    DestRtWid, DestBotHgt,
                                    SrcInfo, SrcBits, TransInfo,
                                    sxSkip, sySkip, SrcLtWid, SrcTopHgt,
                                    1, Mirror, Flip, 0);
                            }
                        }
                        x += BlockWid;
                        --xRemaining;
                    } while (xRemaining != 0);
                }
                DestY += BlockHgt;
                --yRemaining;
            } while (yRemaining != 0);
        }
    } else if (yRemaining > 0) {
        do {
            long DestY1 = DestY + DestTopHgt;
            long xRemaining = xBlocks;
            long x = DestX;
            if (xRemaining > 0) {
                do {
                    if (DestTopHgt != 0) {
                        if (DestLtWid != 0) {
                            DibBlt(DestInfo, DestBits, ClipRect,
                                x, DestY, DestLtWid, DestTopHgt,
                                SrcInfo, SrcBits,
                                SrcX, SrcY, SrcRtWid, SrcBotHgt,
                                1, Mirror, Flip);
                        }
                        if (DestRtWid != 0) {
                            DibBlt(DestInfo, DestBits, ClipRect,
                                x + DestLtWid, DestY,
                                DestRtWid, DestTopHgt,
                                SrcInfo, SrcBits,
                                sxSkip, SrcY, SrcLtWid, SrcBotHgt,
                                1, Mirror, Flip);
                        }
                    }
                    if (DestBotHgt != 0) {
                        if (DestLtWid != 0) {
                            DibBlt(DestInfo, DestBits, ClipRect,
                                x, DestY1, DestLtWid, DestBotHgt,
                                SrcInfo, SrcBits,
                                SrcX, sySkip, SrcRtWid, SrcTopHgt,
                                1, Mirror, Flip);
                        }
                        if (DestRtWid != 0) {
                            DibBlt(DestInfo, DestBits, ClipRect,
                                x + DestLtWid, DestY1,
                                DestRtWid, DestBotHgt,
                                SrcInfo, SrcBits,
                                sxSkip, sySkip, SrcLtWid, SrcTopHgt,
                                1, Mirror, Flip);
                        }
                    }
                    x += BlockWid;
                    --xRemaining;
                } while (xRemaining != 0);
            }
            DestY += BlockHgt;
            --yRemaining;
        } while (yRemaining != 0);
    }

    return yBlocks * xBlocks;
}

int __cdecl DibCheckTrans(BITMAPINFO256* DibInfo, TRANSINFO* TransInfo,
    unsigned char* DibBits)
{
    int AnyTrans;
    long orien;
    long y;
    long h;
    long tw;
    long w;

    GetDibDim(DibInfo, tw, h, orien);
    w = DibInfo->bmiHeader.biWidth;
    TransInfo->LineInfo = (LINEINFO*)malloc(h << 4);
    if (TransInfo->LineInfo == 0)
        return 1;

    AnyTrans = 0;
    y = 0;
    if (h > 0) {
        do {
            int all_trans = 1;
            long first = w;
            long row;

            if (orien == 1)
                row = tw * y;
            else
                row = (h - y - 1) * tw;

            unsigned char* scan = DibBits + row;
            long x = 0;
            if (w > 0) {
                do {
                    if (scan[x] != 0) {
                        if (all_trans) {
                            all_trans = 0;
                            first = x;
                        }
                    } else if (AnyTrans == 0) {
                        AnyTrans = 1;
                    }
                    ++x;
                } while (x < w);
            }

            long last = first;
            if (!all_trans) {
                x = first + 1;
                while (x < w) {
                    if (scan[x] != 0)
                        last = x;
                    ++x;
                }
            }

            int solid = 1;
            if (!all_trans) {
                x = first;
                while (x <= last) {
                    if (scan[x] == 0) {
                        solid = 0;
                        break;
                    }
                    ++x;
                }
            }

            TransInfo->LineInfo[y].AllTrans = all_trans;
            TransInfo->LineInfo[y].MidSolid = solid;
            TransInfo->LineInfo[y].StartX = first;
            TransInfo->LineInfo[y].EndX = last;
            ++y;
        } while (y < h);
    }

    TransInfo->AnyTrans = AnyTrans;
    if (AnyTrans == 0)
        free(TransInfo->LineInfo);
    return AnyTrans;
}

void* __cdecl GetPaletteFromDib(char* path, int make_identity)
{
    BITMAPINFOHEADER* dib = DibOpenFile(path);
    if (dib == 0)
        return 0;

    void* palette = DibCreatePalette(dib);
    if (make_identity != 0)
        CreateIdentityPalette(palette);

    DibFree(dib);
    return palette;
}

void* __cdecl ReadPalette(char* filename, long res_id, int do_gamma)
{
    unsigned char* data;
    void* own_mem = 0;
    int owns_memory = -1;
    void* result = 0;
    int data_size;
    char* tok = 0;
    int n = 0;
    struct LOGPAL { unsigned short ver; unsigned short cnt; unsigned char e[1]; };
    LOGPAL* lp = 0;
    int i = 0;
    unsigned char* out = 0;
    if (filename && *filename && shape_file_first) {
        int fd = _open(filename, 0x8000);
        if (fd != -1) {
            _lseek(fd, 0, 2);
            int size = _tell(fd);
            own_mem = malloc(size);
            if (own_mem) {
                _lseek(fd, 0, 0);
                _read(fd, own_mem, size);
                owns_memory = 1;
            }
            _close(fd);
        }
    }
    if (!own_mem && res_id != -1) {
        data = RESFILE_load(0x62696e61, (unsigned long)res_id,
            owns_memory, data_size);
        if (owns_memory == 0) {
            own_mem = malloc(data_size);
            memcpy(own_mem, data, data_size);
            owns_memory = 1;
        } else {
            own_mem = data;
        }
    }
    if (!own_mem) return 0;
    char seps[3] = " \n";
    tok = strtok((char*)own_mem, seps);
    if (tok == 0) goto cleanup;
    tok = strtok(0, seps);
    if (tok == 0) goto cleanup;
    tok = strtok(0, seps);
    if (tok == 0) goto cleanup;
    n = (int)atol(tok);
    lp = (LOGPAL*)malloc(n * 4 + 8);
    res_id = 0;
    if (lp) {
        i = 0;
        lp->cnt = (unsigned short)n;
        lp->ver = 0x300;
        if (n <= 0) goto palette_entries_done;
        out = lp->e + 1;
        while (1) {
            tok = strtok(0, seps); if (!tok) goto palette_entries_done; out[-1] = (unsigned char)atoi(tok);
            tok = strtok(0, seps); if (!tok) goto palette_entries_done; out[0] = (unsigned char)atoi(tok);
            tok = strtok(0, seps); if (!tok) goto palette_entries_done; out[1] = (unsigned char)atoi(tok);
            out[2] = 0;
            if (i == n-1) res_id = 1;
            ++i;
            out += 4;
            if (i >= n) goto palette_entries_done;
        }
palette_entries_done:
        ;
        if (res_id && n == 0x100 && System_color_Table[0].index >= 0) {
            int idx = System_color_Table[0].index;
            PAL_TABLE* g = System_color_Table;
            while (idx >= 0) {
                lp->e[idx*4] = g->red;
                lp->e[idx*4+1] = g->green;
                lp->e[idx*4+2] = g->blue;
                lp->e[idx*4+3] = 0;
                ++g;
                idx = g->index;
            }
        }
        if (res_id) {
            result = CreatePalette((const tagLOGPALETTE*)lp);
            if (do_gamma) {
                if (rge_base_game->draw_system->DrawType == 1 ||
                    rge_base_game->draw_system->ScreenMode == 1)
                    CreateIdentityPalette(result);
            }
        }
        free(lp);
    }
cleanup:
    if (owns_memory == 1) free(own_mem);
    return result;
}

BITMAPINFOHEADER* __cdecl DibOpenFile(char* name)
{
    int fh;
    OFSTRUCT of;
    BITMAPINFOHEADER* dib;
    DWORD dwBits;

    fh = OpenFile(name, &of, OF_READ);
    if (fh == -1) {
        HRSRC resource = FindResourceA(GetModuleHandleA(0), name,
            MAKEINTRESOURCEA(2));
        if (resource != 0) {
            resource = LoadResource(GetModuleHandleA(0), resource);
            return (BITMAPINFOHEADER*)LockResource(resource);
        }
    }
    if (fh == -1)
        return 0;

    dib = DibReadBitmapInfo(fh);
    if (dib == 0)
        return 0;

    dwBits = dib->biSizeImage;
    DWORD colors = dib->biClrUsed;
    if (colors == 0 && dib->biBitCount <= 8)
        colors = 1 << dib->biBitCount;

    DWORD total_size = dwBits;
    total_size += colors * 4;
    total_size += dib->biSize;
    GlobalUnlock(GlobalHandle(dib));
    BITMAPINFOHEADER* new_dib = (BITMAPINFOHEADER*)GlobalLock(GlobalReAlloc(
        GlobalHandle(dib), total_size, 0));
    if (new_dib == 0) {
        GlobalUnlock(GlobalHandle(dib));
        GlobalFree(GlobalHandle(dib));
        dib = 0;
    } else {
        dib = new_dib;
    }

    if (dib != 0) {
        colors = dib->biClrUsed;
        if (colors == 0 && dib->biBitCount <= 8)
            colors = 1 << dib->biBitCount;
        _hread(fh, (char*)dib + dib->biSize + colors * 4, dwBits);
    }
    _lclose(fh);
    return dib;
}

unsigned char* __cdecl ReadDibBits(char* param_1)
{
    OFSTRUCT of;
    unsigned char* result = 0;

    HFILE hf = OpenFile(param_1, &of, OF_READ);
    if (hf == HFILE_ERROR) return 0;

    BITMAPINFOHEADER* info = DibReadBitmapInfo(hf);
    if (info) {
        DWORD size = info->biSizeImage;
        HGLOBAL handle = GlobalHandle(info);
        GlobalUnlock(handle);
        GlobalFree(GlobalHandle(info));
        result = (unsigned char*)malloc(size);
        if (result)
            _hread(hf, (char*)result, size);
    }
    _lclose(hf);
    return result;
}

int __cdecl DibWriteClipped(BITMAPINFOHEADER* dib, char* name,
    long src_x, long src_y, long width, long height)
{
    BITMAPINFO256* clipped = (BITMAPINFO256*)DibCreate(8, width, height);
    unsigned long colors;
    unsigned char* src_bits;
    unsigned char* dst_bits;

    if (clipped == 0)
        return 0;

    colors = dib->biClrUsed;
    if (colors == 0 && dib->biBitCount <= 8)
        colors = 1 << dib->biBitCount;

    memcpy((char*)clipped + clipped->bmiHeader.biSize,
        (char*)dib + dib->biSize, colors << 2);

    if (dib->biCompression == 3)
        src_bits = (unsigned char*)dib + dib->biSize + 12;
    else
        src_bits = (unsigned char*)dib + dib->biSize + dib->biClrUsed * 4;

    if (clipped->bmiHeader.biCompression == 3)
        dst_bits = (unsigned char*)clipped + clipped->bmiHeader.biSize + 12;
    else
        dst_bits = (unsigned char*)clipped + clipped->bmiHeader.biSize +
            clipped->bmiHeader.biClrUsed * 4;

    DibBlt(clipped, dst_bits, 0, 0, 0, width, height,
        (BITMAPINFO256*)dib, src_bits, src_x, src_y, width, height,
        1, 0, 0);
    DibWriteFile(&clipped->bmiHeader, name);
    DibFree(&clipped->bmiHeader);
    return 1;
}

int __cdecl DibWriteFile(BITMAPINFOHEADER* dib, char* name)
{
    HFILE file;
    int size;
    BITMAPFILEHEADER hdr;
    OFSTRUCT of;
    int colors;

    if (dib == 0)
        return 0;

    file = OpenFile(name, &of, OF_CREATE | OF_READWRITE);
    if (file == (HFILE)-1)
        return 0;

    hdr.bfType = 0x4d42;
    hdr.bfReserved1 = 0;
    size = dib->biSizeImage + dib->biClrUsed * 4 + dib->biSize;
    hdr.bfReserved2 = 0;
    hdr.bfSize = size + sizeof(BITMAPFILEHEADER);

    colors = dib->biClrUsed;
    if (colors == 0 && dib->biBitCount <= 8)
        colors = 1 << dib->biBitCount;

    hdr.bfOffBits = dib->biSize + colors * 4 + sizeof(BITMAPFILEHEADER);
    _lwrite(file, (char*)&hdr, sizeof(BITMAPFILEHEADER));
    _hwrite(file, (char*)dib, size);
    _lclose(file);
    return 1;
}

HPALETTE __cdecl DibCreatePalette(BITMAPINFOHEADER* dib)
{
    HPALETTE hpal = 0;
    int colors;
    LOGPALETTE* log_palette;
    RGBQUAD* rgb;
    HDC dc;

    if (dib == 0)
        return 0;

    colors = dib->biClrUsed;
    if (colors == 0 && dib->biBitCount <= 8)
        colors = 1 << dib->biBitCount;
    if (colors == 3 && dib->biCompression == BI_BITFIELDS)
        colors = 0;

    if (colors > 0) {
        rgb = (RGBQUAD*)((char*)dib + dib->biSize);
        log_palette = (LOGPALETTE*)LocalAlloc(LPTR, colors * 4 + 8);
        if (log_palette != 0) {
            log_palette->palNumEntries = (WORD)colors;
            log_palette->palVersion = 0x300;
            if (0 < colors) {
                unsigned char* entry = &log_palette->palPalEntry[0].peGreen;
                do {
                    entry[-1] = rgb->rgbRed;
                    entry[0] = rgb->rgbGreen;
                    entry[1] = rgb->rgbBlue;
                    entry[2] = 0;
                    entry += 4;
                    ++rgb;
                } while (--colors != 0);
            }
            hpal = CreatePalette(log_palette);
            LocalFree(log_palette);
        }
    } else {
        dc = GetDC(0);
        hpal = CreateHalftonePalette(dc);
        ReleaseDC(0, dc);
    }
    return hpal;
}

#define BFT_BITMAP 0x4d42
#define WIDTHBYTES(i) ((unsigned)((i + 31) & (~31)) / 8)
#define DibNumColors(lpbi) \
    ((lpbi)->biClrUsed == 0 && (lpbi)->biBitCount <= 8 ? \
        (int)(1 << (int)(lpbi)->biBitCount) : (int)(lpbi)->biClrUsed)
#define DibColors(lpbi) \
    ((RGBQUAD FAR *)((LPBYTE)(lpbi) + (int)(lpbi)->biSize))
#define DibWidthBytesN(lpbi, n) \
    (UINT)WIDTHBYTES((UINT)(lpbi)->biWidth * (UINT)(n))
#define DibWidthBytes(lpbi) DibWidthBytesN(lpbi, (lpbi)->biBitCount)
#define DibSizeImage(lpbi) \
    ((lpbi)->biSizeImage == 0 ? \
        ((DWORD)(UINT)DibWidthBytes(lpbi) * \
            (DWORD)(UINT)(lpbi)->biHeight) : (lpbi)->biSizeImage)
#define FixBitmapInfo(lpbi) \
    if ((lpbi)->biSizeImage == 0) \
        (lpbi)->biSizeImage = DibSizeImage(lpbi); \
    if ((lpbi)->biClrUsed == 0) \
        (lpbi)->biClrUsed = DibNumColors(lpbi)
#define GlobalAllocPtr(flags, cb) \
    (GlobalLock(GlobalAlloc((flags), (cb))))

typedef LPBITMAPINFOHEADER PDIB;

PDIB __cdecl DibReadBitmapInfo(HFILE fh)
{
    DWORD off;
    HANDLE hbi = NULL;
    int size;
    int i;
    int nNumColors;

    RGBQUAD FAR *pRgb;
    BITMAPINFOHEADER bi;
    BITMAPCOREHEADER bc;
    BITMAPFILEHEADER bf;
    PDIB pdib;

    if (fh == -1)
        return NULL;

    off = _llseek(fh, 0L, SEEK_CUR);

    if (sizeof(bf) != _lread(fh, (LPSTR)&bf, sizeof(bf)))
        return FALSE;

    if (bf.bfType != BFT_BITMAP)
    {
        bf.bfOffBits = 0L;
        _llseek(fh, off, SEEK_SET);
    }

    if (sizeof(bi) != _lread(fh, (LPSTR)&bi, sizeof(bi)))
        return FALSE;

    switch (size = (int)bi.biSize)
    {
        default:
        case sizeof(BITMAPINFOHEADER):
            break;

        case sizeof(BITMAPCOREHEADER):
            bc = *(BITMAPCOREHEADER*)&bi;
            bi.biSize = sizeof(BITMAPINFOHEADER);
            bi.biWidth = (DWORD)bc.bcWidth;
            bi.biHeight = (DWORD)bc.bcHeight;
            bi.biPlanes = (UINT)bc.bcPlanes;
            bi.biBitCount = (UINT)bc.bcBitCount;
            bi.biCompression = BI_RGB;
            bi.biSizeImage = 0;
            bi.biXPelsPerMeter = 0;
            bi.biYPelsPerMeter = 0;
            bi.biClrUsed = 0;
            bi.biClrImportant = 0;

            _llseek(fh, (LONG)sizeof(BITMAPCOREHEADER) -
                sizeof(BITMAPINFOHEADER), SEEK_CUR);
            break;
    }

    nNumColors = DibNumColors(&bi);

    FixBitmapInfo(&bi);

    pdib = (PDIB)GlobalAllocPtr(GMEM_MOVEABLE,
        (LONG)bi.biSize + nNumColors * sizeof(RGBQUAD));

    if (!pdib)
        return NULL;

    *pdib = bi;

    pRgb = DibColors(pdib);

    if (nNumColors)
    {
        if (size == sizeof(BITMAPCOREHEADER))
        {
            _lread(fh, (LPVOID)pRgb,
                nNumColors * sizeof(RGBTRIPLE));

            for (i = nNumColors - 1; i >= 0; i--)
            {
                RGBQUAD rgb;

                rgb.rgbRed = ((RGBTRIPLE FAR *)pRgb)[i].rgbtRed;
                rgb.rgbBlue = ((RGBTRIPLE FAR *)pRgb)[i].rgbtBlue;
                rgb.rgbGreen = ((RGBTRIPLE FAR *)pRgb)[i].rgbtGreen;
                rgb.rgbReserved = (BYTE)0;

                pRgb[i] = rgb;
            }
        }
        else
        {
            _lread(fh, (LPVOID)pRgb,
                nNumColors * sizeof(RGBQUAD));
        }
    }

    if (bf.bfOffBits != 0L)
        _llseek(fh, off + bf.bfOffBits, SEEK_SET);

    return pdib;
}

#define DibFromBitmapNumColors(lpbi) \
    ((lpbi)->biClrUsed == 0 && (lpbi)->biBitCount <= 8 ? \
        (int)(1 << (int)(lpbi)->biBitCount) : (int)(lpbi)->biClrUsed)

BITMAPINFOHEADER* __cdecl DibFromBitmap(HBITMAP hbm, DWORD biStyle,
    UINT biBits, HPALETTE hpal, UINT usage)
{
    BITMAP bm;
    int nColors;
    BITMAPINFOHEADER* lpbi;
    BITMAPINFOHEADER* lpbiNew;
    HPALETTE palette;
    HDC hdc;
    DWORD dwSizeImage;
    int result;

    nColors = 0;
    if (!hbm)
        return NULL;

    palette = hpal;
    if (palette == NULL)
        palette = (HPALETTE)GetStockObject(DEFAULT_PALETTE);

    GetObject(hbm, sizeof(bm), (LPSTR)&bm);
    GetObject(palette, sizeof(nColors), (LPSTR)&nColors);

    if (biBits == 0)
        biBits = bm.bmPlanes * bm.bmBitsPixel;

    lpbi = (BITMAPINFOHEADER*)GlobalLock(GlobalAlloc(
        GMEM_MOVEABLE, sizeof(BITMAPINFOHEADER) + 256 * sizeof(RGBQUAD)));
    if (lpbi == NULL)
        return NULL;

    lpbi->biSize = sizeof(BITMAPINFOHEADER);
    lpbi->biWidth = bm.bmWidth;
    lpbi->biHeight = bm.bmHeight;
    lpbi->biPlanes = 1;
    lpbi->biBitCount = (WORD)biBits;
    lpbi->biCompression = biStyle;
    lpbi->biSizeImage = 0;
    lpbi->biXPelsPerMeter = 0;
    lpbi->biYPelsPerMeter = 0;
    lpbi->biClrUsed = 0;
    lpbi->biClrImportant = 0;

    lpbi->biClrUsed = DibFromBitmapNumColors(lpbi);

    if (biStyle == BI_BITFIELDS) {
        if (biBits != 16) {
            if (biBits == 24 || biBits == 32) {
                ((DWORD*)(lpbi + 1))[0] = 0x000000FF;
                ((DWORD*)(lpbi + 1))[1] = 0x0000FF00;
                ((DWORD*)(lpbi + 1))[2] = 0x00FF0000;
            }
        }
        else {
            ((DWORD*)(lpbi + 1))[0] = 0x0000F800;
            ((DWORD*)(lpbi + 1))[1] = 0x000007E0;
            ((DWORD*)(lpbi + 1))[2] = 0x0000001F;
        }
    }

    hdc = CreateCompatibleDC(NULL);
    hpal = (HPALETTE)SelectPalette(hdc, palette, FALSE);
    RealizePalette(hdc);
    SetStretchBltMode(hdc, 4);

    GetDIBits(hdc, hbm, 0, lpbi->biHeight, NULL,
        (LPBITMAPINFO)lpbi, usage);

    lpbi->biClrUsed = DibFromBitmapNumColors(lpbi);

    dwSizeImage = (lpbi->biSizeImage == 0) ?
        ((((DWORD)lpbi->biBitCount * (DWORD)lpbi->biWidth + 31) >> 3) &
            0x1FFFFFFC) * lpbi->biHeight : lpbi->biSizeImage;
    lpbi->biSizeImage = dwSizeImage;

    if (dwSizeImage == 0) {
        dwSizeImage = ((((DWORD)lpbi->biBitCount * (DWORD)lpbi->biWidth + 31) >> 3) &
            0x1FFFFFFC) * lpbi->biHeight;
        lpbi->biSizeImage = dwSizeImage;
        if (biStyle)
            lpbi->biSizeImage = (dwSizeImage * 3) / 2;
    }

    GlobalUnlock(GlobalHandle(lpbi));
    lpbiNew = (BITMAPINFOHEADER*)GlobalLock(GlobalReAlloc(
        GlobalHandle(lpbi), lpbi->biSize + lpbi->biClrUsed * sizeof(RGBQUAD) +
        lpbi->biSizeImage, 0));

    if (lpbiNew != NULL) {
        BYTE* bits;
        if (lpbiNew->biCompression == BI_BITFIELDS)
            bits = (LPBYTE)lpbiNew + lpbiNew->biSize + 3 * sizeof(DWORD);
        else
            bits = (LPBYTE)lpbiNew + lpbiNew->biSize +
                lpbiNew->biClrUsed * sizeof(RGBQUAD);

        result = GetDIBits(hdc, hbm, 0, lpbiNew->biHeight, bits,
            (LPBITMAPINFO)lpbiNew, usage);

        lpbiNew->biClrUsed = DibFromBitmapNumColors(lpbiNew);

        dwSizeImage = (lpbiNew->biSizeImage == 0) ?
            ((((DWORD)lpbiNew->biBitCount * (DWORD)lpbiNew->biWidth + 31) >> 3) &
                0x1FFFFFFC) * lpbiNew->biHeight : lpbiNew->biSizeImage;
        lpbiNew->biSizeImage = dwSizeImage;

        if (result == 0) {
            DibFree(lpbiNew);
            lpbiNew = NULL;
        }
    }
    else {
        GlobalUnlock(GlobalHandle(lpbi));
        GlobalFree(GlobalHandle(lpbi));
        lpbiNew = NULL;
    }

    SelectPalette(hdc, hpal, FALSE);
    DeleteDC(hdc);
    return lpbiNew;
}

#define DibUsageNumColors(lpbi) \
    ((lpbi)->biClrUsed == 0 && (lpbi)->biBitCount <= 8 ? \
        (int)(1 << (int)(lpbi)->biBitCount) : (int)(lpbi)->biClrUsed)
#define DibCompression(lpbi) \
    (DWORD)(((LPBITMAPINFOHEADER)(lpbi))->biCompression)
#define DibUsageColors(lpbi) \
    ((RGBQUAD FAR *)((LPBYTE)(lpbi) + (int)(lpbi)->biSize))

typedef LPBITMAPINFOHEADER UsagePDIB;

BOOL __cdecl DibSetUsage(UsagePDIB pdib, HPALETTE hpal, UINT wUsage)
{
    PALETTEENTRY ape[256];
    RGBQUAD FAR* pRgb;
    WORD FAR* pw;
    int colors;
    int n;

    if (hpal == NULL)
        hpal = (HPALETTE)GetStockObject(DEFAULT_PALETTE);

    if (!pdib)
        return FALSE;

    colors = DibUsageNumColors(pdib);
    if (colors == 3 && DibCompression(pdib) == BI_BITFIELDS)
        colors = 0;

    if (colors > 0) {
        pRgb = DibUsageColors(pdib);
        switch (wUsage) {
        case DIB_PAL_COLORS:
            for (pw = (WORD FAR*)pRgb, n = 0; n < colors; n++, pw++)
                *pw = (WORD)n;
            break;

        default:
        case DIB_RGB_COLORS:
            colors = (colors < 256) ? colors : 256;
            GetPaletteEntries(hpal, 0, colors, ape);
            for (n = 0; n < colors; n++) {
                pRgb[n].rgbRed = ape[n].peRed;
                pRgb[n].rgbGreen = ape[n].peGreen;
                pRgb[n].rgbBlue = ape[n].peBlue;
                pRgb[n].rgbReserved = 0;
            }
            break;
        }
    }
    return TRUE;
}

int __cdecl DibDraw(
    void* a1, int a2, int a3, int a4, int a5,
    BITMAPINFOHEADER* a6, int a7, int a8, int a9, int a10,
    long a11, unsigned int a12)
{
    if (a6 == 0)
        return 0;

    if (a9 == -1 && a10 == -1) {
        a9 = a6->biWidth;
        a10 = a6->biHeight;
    }
    if (a4 == -1 && a5 == -1) {
        a4 = a9;
        a5 = a10;
    }

    void* bits;
    if (a6->biCompression == 3) {
        bits = (char*)a6 + a6->biSize + 12;
    } else {
        bits = (char*)a6 + a6->biSize + a6->biClrUsed * 4;
    }

    return StretchDIBits(a1, a2, a3, a4, a5,
                         a7, a8, a9, a10,
                         bits, (const BITMAPINFO*)a6, a12, a11);
}

BITMAPINFOHEADER* __cdecl DibCopy(BITMAPINFOHEADER* dib)
{
    tagBITMAPINFOHEADER* copy;

    if (dib == 0) {
        return 0;
    }

    copy = (tagBITMAPINFOHEADER*)GlobalLock(GlobalAlloc(2,
        dib->biSize + dib->biClrUsed * 4 + dib->biSizeImage));
    if (copy != 0) {
        memcpy(copy, dib,
            dib->biSize + dib->biClrUsed * 4 + dib->biSizeImage);
    }
    return copy;
}

typedef LPBITMAPINFOHEADER CreatePDIB;

CreatePDIB __cdecl DibCreate(int bits, int dx, int dy)
{
    LPBITMAPINFOHEADER lpbi;
    DWORD dwSizeImage;
    int i;
    DWORD FAR* pdw;

    dwSizeImage = dy * (DWORD)((dx * bits / 8 + 3) & ~3);

    lpbi = (CreatePDIB)GlobalLock(GlobalAlloc(
        GMEM_MOVEABLE | GMEM_ZEROINIT,
        sizeof(BITMAPINFOHEADER) + dwSizeImage + 1024));

    if (lpbi == NULL)
        return NULL;

    lpbi->biSize = sizeof(BITMAPINFOHEADER);
    lpbi->biWidth = dx;
    lpbi->biHeight = dy;
    lpbi->biPlanes = 1;
    lpbi->biBitCount = bits;
    lpbi->biCompression = BI_RGB;
    lpbi->biSizeImage = dwSizeImage;
    lpbi->biXPelsPerMeter = 0;
    lpbi->biYPelsPerMeter = 0;
    lpbi->biClrUsed = 0;
    lpbi->biClrImportant = 0;

    if (bits == 4) {
        lpbi->biClrUsed = 16;
    }
    else if (bits == 8) {
        lpbi->biClrUsed = 256;
    }

    pdw = (DWORD FAR *)((LPBYTE)lpbi + (int)lpbi->biSize);

    for (i = 0; i < (int)lpbi->biClrUsed / 16; i++) {
        *pdw++ = 0x00000000;
        *pdw++ = 0x00800000;
        *pdw++ = 0x00008000;
        *pdw++ = 0x00808000;
        *pdw++ = 0x00000080;
        *pdw++ = 0x00800080;
        *pdw++ = 0x00008080;
        *pdw++ = 0x00C0C0C0;
        *pdw++ = 0x00808080;
        *pdw++ = 0x00FF0000;
        *pdw++ = 0x0000FF00;
        *pdw++ = 0x00FFFF00;
        *pdw++ = 0x000000FF;
        *pdw++ = 0x00FF00FF;
        *pdw++ = 0x0000FFFF;
        *pdw++ = 0x00FFFFFF;
    }
    return (CreatePDIB)lpbi;
}

static void __cdecl xlatClut8(unsigned char* pb, unsigned long dwSize,
    unsigned char* xlat)
{
    if (dwSize <= 0) {
        return;
    }
    do {
        *pb = xlat[*pb];
        pb++;
        dwSize--;
    } while (dwSize != 0);
}

static void __cdecl xlatClut4(unsigned char *pb, unsigned long dwSize,
    unsigned char *xlat)
{
    if (dwSize <= 0)
        return;

    do {
        *pb = xlat[*pb & 0x0f] | (xlat[*pb >> 4] << 4);
        ++pb;
        --dwSize;
    } while (dwSize != 0);
}

static void __cdecl xlatRle8(unsigned char* data, unsigned long unused, unsigned char* xlat)
{
    unsigned char* p = data;
    while (1) {
        unsigned char code = p[0];
        unsigned char value = p[1];
        ++p;
        if (code == 0) {
            ++p;
            switch (value) {
            case 0:
                continue;
            case 1:
                return;
            case 2:
                p += 2;
                continue;
            }
            unsigned int count = value;
            if (value > 0) {
                do {
                    unsigned int c = *p;
                    ++p;
                    --count;
                    p[-1] = xlat[c];
                } while (count != 0);
            }
            if (value & 1) {
                ++p;
            }
        } else {
            unsigned int v = value;
            ++p;
            p[-1] = xlat[v];
        }
    }
}

static void __cdecl xlatRle4(unsigned char*, unsigned long, unsigned char*) {}

namespace {

extern "C" static void __cdecl memmove(unsigned char* d, unsigned char* s,
    long len)
{
    int count;

    d = d + len - 1;
    count = len;
    s = s + len - 1;
    len = len - 1;
    if (count != 0) {
        count = len + 1;
        do {
            *d = *s;
            d = d - 1;
            s = s - 1;
            count = count - 1;
        } while (count != 0);
    }
}

}

void __cdecl DibMapToPalette(BITMAPINFOHEADER* pdib, void* hpal,
    int TransLogic, int ZeroIsTrans)
{
    unsigned long SizeImage;
    PALETTEENTRY pe;
    int nDibColors = 0;
    unsigned char xlat[256];
    int HitEnd;
    int nPalColors;
    unsigned char ZeroIndex = 0;
    unsigned char* lpBits;
    int ZeroBlue;
    unsigned char TransIndex = 0;
    RGBQUAD* lpRgb;

    if (hpal == 0 || pdib == 0)
        return;

    lpRgb = DibColors(pdib);
    GetObjectA((HGDIOBJ)hpal, sizeof(nDibColors), &nDibColors);
    nPalColors = DibNumColors(pdib);
    SizeImage = DibSizeImage(pdib);

    if (pdib->biCompression == BI_BITFIELDS)
        lpBits = (unsigned char*)pdib + pdib->biSize + 3 * sizeof(DWORD);
    else
        lpBits = (unsigned char*)pdib + pdib->biSize + pdib->biClrUsed *
            sizeof(RGBQUAD);

    if (TransLogic) {
        if (ZeroIsTrans)
            TransIndex = 0;
        else
            TransIndex = lpBits[((pdib->biWidth + 3) & ~3) *
                (pdib->biHeight - 1)];

        int ZeroRed = lpRgb->rgbRed;
        int ZeroGreen = lpRgb->rgbGreen;
        ZeroBlue = lpRgb->rgbBlue;
        HitEnd = 0;
        int Increment = 1;

        do {
            ZeroRed += Increment;
            ZeroGreen += Increment;
            ZeroBlue += Increment;
            if (ZeroRed > 255 || ZeroGreen > 255 || ZeroBlue > 255 ||
                ZeroRed < 0 || ZeroGreen < 0 || ZeroBlue < 0) {
                if (HitEnd)
                    break;
                Increment = -1;
                ZeroRed = lpRgb->rgbRed;
                ZeroGreen = lpRgb->rgbGreen;
                ZeroBlue = lpRgb->rgbBlue;
                HitEnd = 1;
            }
            ZeroIndex = (unsigned char)GetNearestPaletteIndex((HPALETTE)hpal,
                RGB(ZeroRed, ZeroGreen, ZeroBlue));
        } while (ZeroIndex == 0);
    }

    int i;
    for (i = 0; i < nPalColors; ++i) {
        if (TransLogic) {
            if (i == TransIndex) {
                xlat[i] = 0;
            } else {
                xlat[i] = (unsigned char)GetNearestPaletteIndex(
                    (HPALETTE)hpal,
                    RGB(lpRgb[i].rgbRed, lpRgb[i].rgbGreen,
                        lpRgb[i].rgbBlue));
                if (xlat[i] == 0)
                    xlat[i] = ZeroIndex;
            }
        } else {
            xlat[i] = (unsigned char)GetNearestPaletteIndex((HPALETTE)hpal,
                RGB(lpRgb[i].rgbRed, lpRgb[i].rgbGreen, lpRgb[i].rgbBlue));
        }
    }

    pdib->biClrUsed = nDibColors;
    if (nDibColors > nPalColors) {
        GlobalUnlock(GlobalHandle(pdib));
        GlobalLock(GlobalReAlloc(GlobalHandle(pdib),
            pdib->biSize + nDibColors * sizeof(RGBQUAD) + SizeImage, 0));

        unsigned char* NewBits;
        if (pdib->biCompression == BI_BITFIELDS)
            NewBits = (unsigned char*)pdib + pdib->biSize + 3 * sizeof(DWORD);
        else
            NewBits = (unsigned char*)pdib + pdib->biSize +
                pdib->biClrUsed * sizeof(RGBQUAD);
        memmove(NewBits, lpBits, SizeImage);

        if (pdib->biCompression == BI_BITFIELDS)
            lpBits = (unsigned char*)pdib + pdib->biSize + 3 * sizeof(DWORD);
        else
            lpBits = (unsigned char*)pdib + pdib->biSize +
                pdib->biClrUsed * sizeof(RGBQUAD);
    } else if (nDibColors < nPalColors) {
        unsigned char* NewBits;
        if (pdib->biCompression == BI_BITFIELDS)
            NewBits = (unsigned char*)pdib + pdib->biSize + 3 * sizeof(DWORD);
        else
            NewBits = (unsigned char*)pdib + pdib->biSize +
                nDibColors * sizeof(RGBQUAD);
        memcpy(NewBits, lpBits, SizeImage);

        GlobalUnlock(GlobalHandle(pdib));
        GlobalLock(GlobalReAlloc(GlobalHandle(pdib),
            pdib->biSize + nDibColors * sizeof(RGBQUAD) + SizeImage, 0));

        if (pdib->biCompression == BI_BITFIELDS)
            lpBits = (unsigned char*)pdib + pdib->biSize + 3 * sizeof(DWORD);
        else
            lpBits = (unsigned char*)pdib + pdib->biSize +
                pdib->biClrUsed * sizeof(RGBQUAD);
    }

    switch (pdib->biCompression) {
    case BI_RGB:
        if (pdib->biBitCount == 8)
            xlatClut8(lpBits, SizeImage, xlat);
        else
            xlatClut4(lpBits, SizeImage, xlat);
        break;
    case BI_RLE8:
        xlatRle8(lpBits, SizeImage, xlat);
        break;
    case BI_RLE4:
        xlatRle4(lpBits, SizeImage, xlat);
        break;
    }

    for (i = 0; i < nDibColors; ++i) {
        GetPaletteEntries((HPALETTE)hpal, i, 1, &pe);
        lpRgb[i].rgbRed = pe.peRed;
        lpRgb[i].rgbGreen = pe.peGreen;
        lpRgb[i].rgbBlue = pe.peBlue;
        lpRgb[i].rgbReserved = 0;
    }
}

void __cdecl CreateIdentityPalette(void* palette)
{
    union {
        PALETTEENTRY new_pal[256];
        HWND hwnd;
    } palette_locals;
    HDC hdc;
    struct {
        PALETTEENTRY entries[256];
        PALETTEENTRY api_overrun;
    } from_locals;
    int system_palette_failed = 0;
    int source_palette_failed = 0;

    palette_locals.hwnd = GetActiveWindow();
    if (palette_locals.hwnd != 0)
        hdc = GetDC(palette_locals.hwnd);
    else
        hdc = GetDC(0);

    if (GetSystemPaletteEntries(hdc, 0, 0x100, palette_locals.new_pal + 1) == 0)
        system_palette_failed = 1;
    if (GetPaletteEntries((HPALETTE)palette, 0, 0x100, from_locals.entries + 1) == 0)
        source_palette_failed = 1;

    for (int i = 11; i < 247; ++i) {
        palette_locals.new_pal[i].peRed = from_locals.entries[i].peRed;
        palette_locals.new_pal[i].peGreen = from_locals.entries[i].peGreen;
        palette_locals.new_pal[i].peBlue = from_locals.entries[i].peBlue;
        palette_locals.new_pal[i].peFlags = 1;
    }

    if ((system_palette_failed != 0 || source_palette_failed != 0) &&
        *(int*)System_color_Table >= 0) {
        int index = *(int*)System_color_Table;
        unsigned char* colors = &System_color_Table[0].green;
        do {
            palette_locals.new_pal[index + 1].peRed = colors[-1];
            palette_locals.new_pal[index + 1].peGreen = colors[0];
            palette_locals.new_pal[index + 1].peBlue = colors[1];
            palette_locals.new_pal[index + 1].peFlags = 0;
            index = *(int*)(colors + 3);
            colors += 8;
        } while (index >= 0);
    }

    ReleaseDC(palette_locals.hwnd, hdc);
    ResizePalette((HPALETTE)palette, 0x100);
    SetPaletteEntries((HPALETTE)palette, 0, 0x100, palette_locals.new_pal + 1);
}

void* __cdecl CopyPalette(void* param_1)
{
    int nNumEntries = 0;

    if (!param_1) return 0;

    GetObjectA((HGDIOBJ)param_1, 4, &nNumEntries);
    if (!nNumEntries) return 0;

    void* pal = LocalAlloc(0x40, nNumEntries * 4 + 8);
    if (!pal) return 0;

    *(short*)pal = 0x300;
    *(short*)((char*)pal + 2) = (short)nNumEntries;

    GetPaletteEntries((HPALETTE)param_1, 0, nNumEntries, (PALETTEENTRY*)((char*)pal + 4));
    void* result = CreatePalette((const tagLOGPALETTE*)pal);
    LocalFree((HLOCAL)pal);
    return result;
}

void __cdecl DibFree(BITMAPINFOHEADER* param_1)
{
    void* handle = GlobalHandle(param_1);
    GlobalUnlock(handle);
    handle = GlobalHandle(param_1);
    GlobalFree(handle);
}
