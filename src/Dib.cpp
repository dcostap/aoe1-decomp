// Reunified PDB source module: C:\\msdev\\work\\age1_x1\\Dib.cpp.
// Functions follow the original source order from lines 72 through 2031.

#include "../include/dib.h"
#include "../include/Res_file.h"
#include <windowsx.h>
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

#include "../include/rge_base_game_global.h"

// The target reserves 0x1400 bytes from SrcXTbl to the next global.
static long SrcXTbl[0x500];

// This global has no shared declaration yet. Keep the target's C++ linkage.
extern unsigned char shape_file_first;

struct PAL_TABLE {
    int index;
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char reserved;
};

extern PAL_TABLE System_color_Table[];
extern unsigned char DAT_005841e5;

struct DibDrawSystemView {
    char gap_000[0x478];
    unsigned char DrawType;
    unsigned char ScreenMode;
};

struct DibRgeBaseGameView {
    // draw_system is the only field used here. Its offset is 0x48.
    char gap_000[0x48];
    DibDrawSystemView* draw_system;
};

extern "C" char* __cdecl strtok(char*, const char*);
extern "C" long __cdecl atol(const char*);
extern "C" int __cdecl atoi(const char*);

#pragma function(memcpy)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);

// VA: 00438820 DibBlt | Dib.cpp:72-145
void __cdecl DibBlt(BITMAPINFO256* dest_info, BYTE* dest_bits, RECT* dest_rect,
    long dest_x, long dest_y, long dest_width, long dest_height,
    BITMAPINFO256* src_info, BYTE* src_bits,
    long src_x, long src_y, long src_width, long src_height,
    int do_clip, int flip_x, int flip_y)
{
    long dy, DestTotWid, DestTotHgt, DestOrien, SrcOrien;

    if (do_clip != 0) {
        if (!ClipDibBlt(dest_info, dest_rect, dest_x, dest_y,
                dest_width, dest_height, src_x, src_y, src_width, src_height,
                flip_x, flip_y))
            return;
    }
    GetDibDim(dest_info, DestTotWid, DestTotHgt, DestOrien);
    long src_total_height;
    GetDibDim(src_info, dy, src_total_height, SrcOrien);

    if (flip_y != 0)
        SrcOrien = -SrcOrien;

    int x_step = (src_width << 8) / dest_width;
    int y_step = (src_height << 8) / dest_height;
    BYTE* dest;
    if (DestOrien == 1) {
        dest = dest_bits + DestTotWid * dest_y + dest_x;
    } else {
        dest = dest_bits + DestTotWid * (DestTotHgt - dest_y - 1) + dest_x;
    }

    if (x_step == 0x100 && y_step == 0x100 && flip_x == 0) {
        long src_row;
        if (SrcOrien == 1) {
            src_row = src_y * dy;
        } else {
            src_row = (src_total_height - src_y - 1) * dy;
        }
        BYTE* src = src_bits + src_row + src_x;
        DestTotWid = DestOrien * DestTotWid;
        dy = SrcOrien * dy;
        int row = 0;
        if (dest_height < 1)
            return;
        do {
            memcpy(dest, src, dest_width);
            dest += DestTotWid;
            src += dy;
            ++row;
        } while (row < dest_height);
        return;
    }

    if (flip_x == 0) {
        if (dest_width > 0) {
            long* x_entry = SrcXTbl;
            long source_position = src_x;
            long remaining = dest_width;
            do {
                *x_entry++ = source_position >> 8;
                source_position += x_step;
                --remaining;
            } while (remaining != 0);
        }
    } else if (dest_width - 1 >= 0) {
        long* x_entry = SrcXTbl + dest_width - 1;
        long source_position = src_x;
        long remaining = dest_width;
        do {
            *x_entry-- = source_position >> 8;
            source_position += x_step;
            --remaining;
        } while (remaining != 0);
    }

    int source_y = src_y << 8;
    int output_row = 0;
    if (dest_height > 0) {
        do {
            int source_row = source_y >> 8;
            if (SrcOrien != 1)
                source_row = src_total_height - 1 - source_row;

            if (dest_width > 0) {
                int i = 0;
                long* x_entry = SrcXTbl;
                do {
                    dest[i] = src_bits[(int)*x_entry +
                        source_row * dy + src_x];
                    ++i;
                    ++x_entry;
                } while (i < dest_width);
            }
            source_y += y_step;
            dest += DestOrien * DestTotWid;
            ++output_row;
        } while (output_row < dest_height);
    }
}

// VA: 00438AA0 TransDibBlt | Dib.cpp:155-273
void __cdecl TransDibBlt(BITMAPINFO256* dstInfo, uchar* dst, RECT* dstRect,
                         long dx, long dy, long dw, long dh,
                         BITMAPINFO256* srcInfo, uchar* src, TRANSINFO* trans,
                         long sx, long sy, long sw, long sh,
                         int doClip, int flipX, int flipY, int transparent)
{
    if (trans != 0 && trans->AnyTrans == 0) {
        DibBlt(dstInfo, dst, dstRect, dx, dy, dw, dh, srcInfo, src, sx, sy, sw, sh, doClip, flipX, flipY);
        return;
    }

    if (transparent < 0)
        transparent = 0;

    int clipFlipY = flipY;
    if (doClip == 0 ||
        ClipDibBlt(dstInfo, dstRect, dx, dy, dw, dh, sx, sy, sw, sh, flipX, clipFlipY)) {
        int xStep = (sw << 8) / dw;
        long yStep = (sh << 8) / dh;
        long dstStride;
        long dstHeight;
        long dstOrientation;
        long srcStride;
        long srcHeight;
        long srcOrientation;

        GetDibDim(dstInfo, dstStride, dstHeight, dstOrientation);
        GetDibDim(srcInfo, srcStride, srcHeight, srcOrientation);
        if (clipFlipY)
            srcOrientation = -srcOrientation;

        long xScale = (dw << 8) / sw;
        long destY;
        if (dstOrientation == 1)
            destY = dy;
        else
            destY = dstHeight - dy - 1;
        uchar* destLine = dst + dstStride * destY + dx;

        long sourcePosition = sx;
        if (flipX == 0) {
            if (dw > 0) {
                long* xEntry = SrcXTbl;
                long remaining = dw;
                do {
                    *xEntry++ = sourcePosition >> 8;
                    sourcePosition += xStep;
                    --remaining;
                } while (remaining != 0);
            }
        } else {
            long remaining = dw - 1;
            if (remaining >= 0) {
                long* xEntry = SrcXTbl + remaining;
                ++remaining;
                do {
                    *xEntry-- = sourcePosition >> 8;
                    sourcePosition += xStep;
                    --remaining;
                } while (remaining != 0);
            }
        }

        if (flipX == 0 && trans != 0 && trans->LineInfo != 0) {
            long dstStep = dstOrientation * dstStride;
            long sourceY = sy << 8;
            int row = 0;
            if (dh > 0) {
                do {
                    long sourceRow = sourceY >> 8;
                    long sourceOffset;
                    if (srcOrientation == 1)
                        sourceOffset = sourceRow * srcStride + sx;
                    else
                        sourceOffset = (srcHeight - sourceRow - 1) * srcStride + sx;

                    LINEINFO* lineInfo = &trans->LineInfo[sourceRow];
                    if (lineInfo->skip == 0) {
                        long first;
                        if (lineInfo->first < sx)
                            first = 0;
                        else
                            first = ((lineInfo->first - sx) * xScale) >> 8;
                        long last = (((lineInfo->last - sx) + 1) * xScale) >> 8;
                        if (last > dw)
                            last = dw;
                        if (last > first) {
                            if (xScale == 0x100 && lineInfo->copy != 0) {
                                memcpy(destLine + first, src + first + sourceOffset,
                                    last - first);
                            } else {
                                long i = first;
                                long* table = SrcXTbl + first;
                                while (i < last) {
                                    uchar c = src[*table + sourceOffset];
                                    if ((unsigned)c != (unsigned)transparent)
                                        destLine[i] = c;
                                    ++i;
                                    ++table;
                                }
                            }
                        }
                    }
                    destLine += dstStep;
                    sourceY += yStep;
                    ++row;
                } while (row < dh);
            }
            return;
        }

        long sourceY = sy << 8;
        int row = 0;
        if (dh > 0) {
            do {
                long sourceRow;
                if (srcOrientation == 1)
                    sourceRow = sourceY >> 8;
                else
                    sourceRow = srcHeight - (sourceY >> 8) - 1;

                long sourceBase = sourceRow * srcStride + sx;
                long i = 0;
                if (dw > 0) {
                    long* table = SrcXTbl;
                    do {
                        uchar c = src[*table + sourceBase];
                        if ((unsigned)c != (unsigned)transparent)
                            destLine[i] = c;
                        ++i;
                        ++table;
                    } while (i < dw);
                }
                destLine += dstOrientation * dstStride;
                sourceY += yStep;
                ++row;
            } while (row < dh);
        }
    }
}

// VA: 00438E80 ClipDibBlt | Dib.cpp:280-366
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

// VA: 00439060 GetDibDim | Dib.cpp:372-383
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

// VA: 004390A0 TileDibBlt | Dib.cpp:394-628
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
        long dest_y = param_5 + SrcBotHgt;
        if (0 < param_7) {
            param_17 = param_7;
            do {
                if (0 < param_6) {
                    param_19 = param_6;
                    lVar15 = param_4;
                    do {
                        if (SrcBotHgt != 0) {
                            if (iVar12 != 0) DibBlt(param_1,param_2,param_3,lVar15,dest_y,iVar12,SrcBotHgt,param_10,param_11,param_13,param_14,DestBotHgt,SrcLtWid,1,iVar1,iVar3);
                            if (SrcRtWid != 0) DibBlt(param_1,param_2,param_3,lVar15+iVar12,dest_y,SrcRtWid,SrcBotHgt,param_10,param_11,iVar9,param_14,iVar7,SrcLtWid,1,iVar1,iVar3);
                        }
                        if (SrcTopHgt != 0) {
                            if (iVar12 != 0) DibBlt(param_1,param_2,param_3,lVar15,dest_y,iVar12,SrcTopHgt,param_10,param_11,param_13,iVar10,DestBotHgt,iVar11,1,iVar1,iVar3);
                            if (SrcRtWid != 0) DibBlt(param_1,param_2,param_3,lVar15+iVar12,dest_y,SrcRtWid,SrcTopHgt,param_10,param_11,iVar9,iVar10,iVar7,iVar11,1,iVar1,iVar3);
                        }
                        lVar15 += param_8;
                        --param_19;
                    } while (param_19 != 0);
                }
                dest_y += param_9;
                --param_17;
            } while (param_17 != 0);
        }
    }
    return param_7 * param_6;
}

// VA: 004395A0 DibCheckTrans | Dib.cpp:634-714
int __cdecl DibCheckTrans(BITMAPINFO256* dib, TRANSINFO* info,
    unsigned char* bits)
{
    long tw;
    long orientation;
    long y;
    long height;
    long width;
    long raw_width;

    GetDibDim(dib, width, height, orientation);
    raw_width = dib->bmiHeader.biWidth;
    info->LineInfo = (LINEINFO*)malloc(height << 4);
    if (info->LineInfo == 0)
        return 1;

    tw = 0;
    y = 0;
    if (height > 0) {
        do {
            int all_trans = 1;
            long first = raw_width;
            long row;

            if (orientation == 1)
                row = width * y;
            else
                row = (height - y - 1) * width;

            unsigned char* scan = bits + row;
            long x = 0;
            if (raw_width > 0) {
                do {
                    if (scan[x] != 0) {
                        if (all_trans) {
                            all_trans = 0;
                            first = x;
                        }
                    } else if (tw == 0) {
                        tw = 1;
                    }
                    ++x;
                } while (x < raw_width);
            }

            long last = first;
            if (!all_trans) {
                x = first + 1;
                while (x < raw_width) {
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

            info->LineInfo[y].AllTrans = all_trans;
            info->LineInfo[y].MidSolid = solid;
            info->LineInfo[y].StartX = first;
            info->LineInfo[y].EndX = last;
            ++y;
        } while (y < height);
    }

    info->AnyTrans = tw;
    if (tw == 0)
        free(info->LineInfo);
    return tw;
}

// VA: 00439700 GetPaletteFromDib | Dib.cpp:721-732
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

// VA: 00439750 ReadPalette | Dib.cpp:738-899
void* __cdecl ReadPalette(char* filename, long res_id, int do_gamma)
{
    unsigned char* data;
    void* own_mem = 0;
    void* result = 0;
    int load_type = -1;
    int data_size;
    int owns_memory = 0;
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
            load_type, data_size);
        if (load_type == 0) {
            own_mem = malloc(data_size);
            memcpy(own_mem, data, data_size);
            owns_memory = 1;
        } else {
            own_mem = data;
            owns_memory = (load_type == 1);
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
                DibRgeBaseGameView* game =
                    (DibRgeBaseGameView*)rge_base_game;
                if (game->draw_system->DrawType == 1 ||
                    game->draw_system->ScreenMode == 1)
                    CreateIdentityPalette(result);
            }
        }
        free(lp);
    }
cleanup:
    if (owns_memory) free(own_mem);
    return result;
}

// VA: 00439A10 DibOpenFile | Dib.cpp:930-1003
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

// VA: 00439B50 ReadDibBits | Dib.cpp:1011-1035
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

// VA: 00439BE0 DibWriteClipped | Dib.cpp:1042-1059
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

// VA: 00439CC0 DibWriteFile | Dib.cpp:1066-1095
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

// VA: 00439D80 DibCreatePalette | Dib.cpp:1105-1155
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

// VA: 00439E50 DibReadBitmapInfo | Dib.cpp:1166-1280
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

// VA: 0043A070 DibFromBitmap | Dib.cpp:1290-1416
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

// VA: 0043A330 DibSetUsage | Dib.cpp:1482-1538
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

// VA: 0043A420 DibDraw | Dib.cpp:1546-1589
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

// VA: 0043A4B0 DibCopy | Dib.cpp:1592-1602
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

// VA: 0043A500 DibCreate | Dib.cpp:1605-1659
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

// VA: 0043AA60 xlatClut8 | Dib.cpp:1691-1700
static void __cdecl xlatClut8(unsigned char* bits, unsigned long count,
    unsigned char* clut)
{
    if (count <= 0) {
        return;
    }
    do {
        *bits = clut[*bits];
        bits++;
        count--;
    } while (count != 0);
}

// VA: 0043AA90 xlatClut4 | Dib.cpp:1703-1712
void __cdecl xlatClut4(unsigned char *buf, unsigned int count,
    unsigned char *clut)
{
    while (count) {
        unsigned int v = *buf;
        unsigned int h = v >> 4;
        *buf = (unsigned char)(clut[h] << 4) | clut[v & 0x0F];
        ++buf;
        --count;
    }
}

// VA: 0043AAD0 xlatRle8 | Dib.cpp:1720-1763
void __cdecl xlatRle8(unsigned char* data, int unused, unsigned char* xlat)
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

// VA: 0043AB40 xlatRle4 | Dib.cpp:1766
static void __cdecl xlatRle4(unsigned char*, unsigned long, unsigned char*) {}

// VA: 0043AB50 memmove | Dib.cpp:1770-1776
extern "C" void* __cdecl memmove(void* dst_arg, const void* src_arg,
    unsigned int n)
{
    unsigned char* dst = (unsigned char*)dst_arg;
    unsigned char* src = (unsigned char*)src_arg;
    int count;

    dst = dst + n - 1;
    count = n;
    src = src + n - 1;
    n = n - 1;
    if (count != 0) {
        count = n + 1;
        do {
            *dst = *src;
            dst = dst - 1;
            src = src - 1;
            count = count - 1;
        } while (count != 0);
    }
    return dst_arg;
}

// VA: 0043A660 DibMapToPalette | Dib.cpp:1782-1923
#define DIB_RGB(r, g, b) \
    ((DWORD)(BYTE)(r) | ((DWORD)(BYTE)(g) << 8) | \
        ((DWORD)(BYTE)(b) << 16))

void __cdecl DibMapToPalette(BITMAPINFOHEADER* bih, void* hbm,
    int transparent, int zero)
{
    BYTE* bits;
    int nDibColors = 0;
    BYTE zeroIndex = 0;
    DWORD sizeImage;
    int nPalColors;
    PALETTEENTRY pe;
    RGBQUAD* rgb;
    int zeroBlue;
    BYTE hitEnd = 0;
    int searchState = 0;
    BYTE table[256];
    int i;

    if (hbm != 0 && bih != 0) {
        rgb = (RGBQUAD*)((BYTE*)bih + bih->biSize);
        GetObjectA(hbm, 4, &nDibColors);
        if (bih->biClrUsed == 0 && bih->biBitCount <= 8)
            nPalColors = 1 << bih->biBitCount;
        else
            nPalColors = bih->biClrUsed;
        sizeImage = bih->biSizeImage;
        if (!sizeImage)
            sizeImage = ((((DWORD)bih->biWidth * (DWORD)bih->biBitCount + 31) >> 3) &
                0x1ffffffc) * bih->biHeight;
        if (bih->biCompression == 3)
            bits = (BYTE*)bih + bih->biSize + 12;
        else
            bits = (BYTE*)bih + bih->biSize + nPalColors * 4;

        if (transparent) {
            if (zero)
                hitEnd = 0;
            else
                hitEnd = bits[((bih->biWidth + 3) & ~3) *
                    (bih->biHeight - 1)];

            int r = rgb->rgbRed, g = rgb->rgbGreen;
            zeroBlue = rgb->rgbBlue;
            int dir = 1;
            searchState = 0;
            do {
                r += dir;
                g += dir;
                zeroBlue += dir;
                if (r > 255 || g > 255 || zeroBlue > 255 ||
                    r < 0 || g < 0 || zeroBlue < 0) {
                    if (searchState)
                        break;
                    dir = -1;
                    zeroBlue = rgb->rgbBlue;
                    g = rgb->rgbGreen;
                    r = rgb->rgbRed;
                    searchState = 1;
                }
                zeroIndex = (BYTE)GetNearestPaletteIndex(hbm,
                    DIB_RGB(r, g, zeroBlue));
            } while (zeroIndex == 0);
        }
        if (0 < nPalColors) {
            BYTE* p = (BYTE*)rgb + 2;
            for (i = 0; i < nPalColors; i++, p += 4) {
                if (!transparent) {
                    table[i] = (BYTE)GetNearestPaletteIndex(hbm,
                        DIB_RGB(p[-2], p[-1], p[0]));
                } else if (i == (BYTE)hitEnd) {
                    table[i] = 0;
                } else {
                    BYTE v = (BYTE)GetNearestPaletteIndex(hbm,
                        DIB_RGB(p[-2], p[-1], p[0]));
                    table[i] = v;
                    if (v == 0) table[i] = zeroIndex;
                }
            }
        }
        bih->biClrUsed = nDibColors;
        BYTE* oldBits = bits;
        if (nPalColors < nDibColors) {
            void* (__stdcall *getHandle)(const void*) = GlobalHandle;
            GlobalUnlock(getHandle(bih));
            GlobalLock(GlobalReAlloc(getHandle(bih),
                bih->biSize + nDibColors * 4 + sizeImage, 0));

            if (bih->biCompression == 3) {
                bits = (BYTE*)bih + bih->biSize + 12;
            } else
                bits = (BYTE*)bih + bih->biSize + bih->biClrUsed * 4;
            memmove(bits, oldBits, sizeImage);
            if (bih->biCompression == 3)
                bits = (BYTE*)bih + bih->biSize + 12;
            else
                bits = (BYTE*)bih + bih->biSize + bih->biClrUsed * 4;
        } else if (nPalColors > nDibColors) {
            if (bih->biCompression == 3) {
                bits = (BYTE*)bih + bih->biSize + 12;
            } else
                bits = (BYTE*)bih + bih->biSize + bih->biClrUsed * 4;
            memcpy(bits, oldBits, sizeImage);
            void* (__stdcall *getHandle)(const void*) = GlobalHandle;
            GlobalUnlock(getHandle(bih));
            GlobalLock(GlobalReAlloc(getHandle(bih),
                bih->biSize + nDibColors * 4 + sizeImage, 0));
            if (bih->biCompression == 3)
                bits = (BYTE*)bih + bih->biSize + 12;
            else
                bits = (BYTE*)bih + bih->biSize + bih->biClrUsed * 4;
        }
        switch (bih->biCompression) {
        case 0:
            if (bih->biBitCount == 8)
                xlatClut8(bits, sizeImage, table);
            else
                xlatClut4(bits, sizeImage, table);
            break;
        case 1:
            xlatRle8(bits, sizeImage, table);
            break;
        case 2:
            xlatRle4(bits, sizeImage, table);
            break;
        }
        i = 0;
        if (i < nDibColors) {
            BYTE* p = (BYTE*)rgb + 1;
            do {
                GetPaletteEntries(hbm, i, 1, &pe);
                ++i;
                p[1] = pe.peRed;
                p[0] = pe.peGreen;
                p[-1] = pe.peBlue;
                p[2] = 0;
                p += 4;
            } while (i < nDibColors);
        }
    }
}

// VA: 0043AB80 CreateIdentityPalette | Dib.cpp:1930-1992
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
        unsigned char* colors = &DAT_005841e5;
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

// VA: 0043ACB0 CopyPalette | Dib.cpp:1999-2026
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

// VA: 0043AD40 DibFree | Dib.cpp:2029-2031
void __cdecl DibFree(BITMAPINFOHEADER* param_1)
{
    void* handle = GlobalHandle(param_1);
    GlobalUnlock(handle);
    handle = GlobalHandle(param_1);
    GlobalFree(handle);
}
