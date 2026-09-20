
#include "../include/dib.h"
#include "../include/drawarea.h"
#include "../include/basegame.h"
#include "../include/Shape.h"
#include "../include/Res_file.h"
#include <windowsx.h>
#include <fcntl.h>
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

void __cdecl DibBlt(BITMAPINFO256* DestInfo, uchar* DestBits, RECT* ClipRect,
                    long DestX, long DestY, long DestWid, long DestHgt,
                    BITMAPINFO256* SrcInfo, uchar* SrcBits,
                    long SrcX, long SrcY, long SrcWid, long SrcHgt,
                    int Clip, int Mirror, int Flip) {
    if (Clip != 0 &&
        ClipDibBlt(DestInfo, ClipRect, DestX, DestY, DestWid, DestHgt, SrcX, SrcY, SrcWid, SrcHgt, Mirror, Flip) == 0)
        return;

    long DestTotWid;
    long DestTotHgt;
    long DestOrien;
    long SrcTotWid;
    long SrcTotHgt;
    long SrcOrien;

    GetDibDim(DestInfo, DestTotWid, DestTotHgt, DestOrien);
    GetDibDim(SrcInfo, SrcTotWid, SrcTotHgt, SrcOrien);
    if (Flip != 0)
        SrcOrien = -SrcOrien;

    long xStep = (SrcWid << 8) / DestWid;
    long yStep = (SrcHgt << 8) / DestHgt;
    long dy;
    if (DestOrien == 1)
        dy = DestY;
    else
        dy = DestTotHgt - DestY - 1;
    uchar* dstLine = DestBits + dy * DestTotWid + DestX;

    if (xStep == 256 && yStep == 256 && Mirror == 0) {
        long srcRow;
        if (SrcOrien == 1)
            srcRow = SrcY;
        else
            srcRow = SrcTotHgt - SrcY - 1;

        uchar* srcLine = SrcBits + srcRow * SrcTotWid + SrcX;
        long dstLineStep = DestOrien * DestTotWid;
        long srcLineStep = SrcOrien * SrcTotWid;
        long row = 0;
        if (DestHgt > 0) {
            do {
                memcpy(dstLine, srcLine, DestWid);
                dstLine += dstLineStep;
                srcLine += srcLineStep;
                ++row;
            } while (row < DestHgt);
        }
        return;
    }

    long srcPosition = SrcX;
    if (Mirror == 0) {
        if (DestWid > 0) {
            long* entry = SrcXTbl;
            long remaining = DestWid;
            do {
                *entry++ = srcPosition >> 8;
                srcPosition += xStep;
                --remaining;
            } while (remaining != 0);
        }
    } else {
        long remaining = DestWid - 1;
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

    long dstLineStep = DestOrien * DestTotWid;
    long sySkip = SrcY << 8;
    long row = 0;
    if (DestHgt > 0) {
        do {
            long srcRow;
            if (SrcOrien == 1)
                srcRow = sySkip >> 8;
            else
                srcRow = SrcTotHgt - (sySkip >> 8) - 1;

            uchar* srcLine = SrcBits + srcRow * SrcTotWid + SrcX;
            long x = 0;
            if (DestWid > 0) {
                long* entry = SrcXTbl;
                do {
                    dstLine[x] = srcLine[*entry++];
                    ++x;
                } while (x < DestWid);
            }
            sySkip += yStep;
            dstLine += dstLineStep;
            ++row;
        } while (row < DestHgt);
    }
}

void __cdecl TransDibBlt(BITMAPINFO256* DestInfo, uchar* DestBits, RECT* ClipRect,
                         long DestX, long DestY, long DestWid, long DestHgt,
                         BITMAPINFO256* SrcInfo, uchar* SrcBits,
                         TRANSINFO* TransInfo,
                         long SrcX, long SrcY, long SrcWid, long SrcHgt,
                         int Clip, int Mirror, int Flip, int TransColor) {
    if (TransInfo != 0 && TransInfo->AnyTrans == 0) {
        DibBlt(DestInfo, DestBits, ClipRect, DestX, DestY, DestWid, DestHgt,
               SrcInfo, SrcBits, SrcX, SrcY, SrcWid, SrcHgt, Clip, Mirror, Flip);
        return;
    }

    if (TransColor < 0)
        TransColor = 0;

    if (Clip != 0 &&
        ClipDibBlt(DestInfo, ClipRect, DestX, DestY, DestWid, DestHgt, SrcX, SrcY, SrcWid, SrcHgt, Mirror, Flip) == 0)
        return;

    long xStep = (SrcWid << 8) / DestWid;
    long yStep = (SrcHgt << 8) / DestHgt;
    long DestTotWid;
    long DestTotHgt;
    long DestOrien;
    long SrcTotWid;
    long SrcTotHgt;
    long SrcOrien;

    GetDibDim(DestInfo, DestTotWid, DestTotHgt, DestOrien);
    GetDibDim(SrcInfo, SrcTotWid, SrcTotHgt, SrcOrien);
    if (Flip != 0)
        SrcOrien = -SrcOrien;

    long dstPerSrc = (DestWid << 8) / SrcWid;
    long dy;
    if (DestOrien == 1)
        dy = DestY;
    else
        dy = DestTotHgt - DestY - 1;
    uchar* dstLine = DestBits + dy * DestTotWid + DestX;

    long srcPosition = SrcX;
    if (Mirror == 0) {
        if (DestWid > 0) {
            long* entry = SrcXTbl;
            long remaining = DestWid;
            do {
                *entry++ = srcPosition >> 8;
                srcPosition += xStep;
                --remaining;
            } while (remaining != 0);
        }
    } else {
        long remaining = DestWid - 1;
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

    long dstLineStep = DestOrien * DestTotWid;
    long sy = SrcY << 8;
    long row = 0;

    if (Mirror == 0 && TransInfo != 0 && TransInfo->LineInfo != 0) {
        LINEINFO* lineInfo = TransInfo->LineInfo;
        if (DestHgt > 0) {
            do {
                long srcLineNumber = sy >> 8;
                long srcRow;
                if (SrcOrien == 1)
                    srcRow = srcLineNumber;
                else
                    srcRow = SrcTotHgt - srcLineNumber - 1;
                uchar* srcLine = SrcBits + srcRow * SrcTotWid + SrcX;
                LINEINFO* line = lineInfo + srcLineNumber;

                if (line->AllTrans == 0) {
                    long dxSkip;
                    if (line->StartX < SrcX)
                        dxSkip = 0;
                    else
                        dxSkip = ((line->StartX - SrcX) * dstPerSrc) >> 8;

                    long last = ((line->EndX - SrcX + 1) * dstPerSrc) >> 8;
                    if (last > DestWid)
                        last = DestWid;

                    if (dxSkip < last) {
                        if (dstPerSrc == 256 && line->MidSolid != 0) {
                            memcpy(dstLine + dxSkip, srcLine + dxSkip, last - dxSkip);
                        } else {
                            long x = dxSkip;
                            do {
                                uchar b = srcLine[SrcXTbl[x]];
                                if ((unsigned int)b != (unsigned int)TransColor)
                                    dstLine[x] = b;
                                ++x;
                            } while (x < last);
                        }
                    }
                }

                dstLine += dstLineStep;
                sy += yStep;
                ++row;
            } while (row < DestHgt);
        }
        return;
    }

    if (DestHgt > 0) {
        do {
            long srcLineNumber = sy >> 8;
            long srcRow;
            if (SrcOrien == 1)
                srcRow = srcLineNumber;
            else
                srcRow = SrcTotHgt - srcLineNumber - 1;
            uchar* srcLine = SrcBits + srcRow * SrcTotWid + SrcX;

            long x = 0;
            if (DestWid > 0) {
                do {
                    uchar b = srcLine[SrcXTbl[x]];
                    if ((unsigned int)b != (unsigned int)TransColor)
                        dstLine[x] = b;
                    ++x;
                } while (x < DestWid);
            }

            dstLine += dstLineStep;
            sy += yStep;
            ++row;
        } while (row < DestHgt);
    }
}

int __cdecl ClipDibBlt(BITMAPINFO256* DestInfo, RECT* ClipRect,
    LONG& DestX, LONG& DestY, LONG& DestWid, LONG& DestHgt,
    LONG& SrcX, LONG& SrcY, LONG& SrcWid, LONG& SrcHgt,
    int Mirror, int Flip) {
    LONG left;
    LONG top;
    LONG ex;
    LONG ey;

    if (ClipRect != 0) {
        left = ClipRect->left;
        top = ClipRect->top;
        ex = ClipRect->right + 1;
        ey = ClipRect->bottom + 1;
    } else {
        left = 0;
        top = 0;
        ex = DestInfo->bmiHeader.biWidth;
        ey = DestInfo->bmiHeader.biHeight;
    }

    if (ey < 0)
        ey = -ey;
    ex--;
    ey--;

    if (DestX <= ex && DestY <= ey && DestWid + DestX - 1 >= left &&
        DestHgt + DestY - 1 >= top && DestWid >= 1 && DestHgt >= 1) {
        LONG x_scale = (SrcWid << 8) / DestWid;
        LONG y_scale = (SrcHgt << 8) / DestHgt;

        if (DestX < left) {
            LONG delta = left - DestX;
            DestX = left;
            DestWid -= delta;
            LONG scaled = (delta << 8) * x_scale >> 16;
            if (Mirror == 0)
                SrcX += scaled;
            SrcWid -= scaled;
        }

        if (DestY < top) {
            LONG delta = top - DestY;
            DestY = top;
            DestHgt -= delta;
            LONG scaled = (delta << 8) * y_scale >> 16;
            if (Flip == 0)
                SrcY += scaled;
            SrcHgt -= scaled;
        }

        LONG end = DestX + DestWid;
        if (end - 1 > ex) {
            LONG delta = end - ex - 1;
            DestWid -= delta;
            LONG scaled = (delta << 8) * x_scale >> 16;
            SrcWid -= scaled;
            if (Mirror != 0)
                SrcX += scaled;
        }

        end = DestY + DestHgt;
        if (end - 1 > ey) {
            LONG delta = end - ey - 1;
            DestHgt -= delta;
            LONG scaled = (delta << 8) * y_scale >> 16;
            SrcHgt -= scaled;
            if (Flip != 0)
                SrcY += scaled;
        }

        if (DestWid >= 1 && DestHgt >= 1 && SrcWid >= 1 && SrcHgt >= 1)
            return 1;
    }
    return 0;
}

void __cdecl GetDibDim(BITMAPINFO256* Info, long& TotWid, long& TotHgt, long& Orien) {
    TotWid = (Info->bmiHeader.biWidth + 3) & 0xFFFFFFFC;
    TotHgt = Info->bmiHeader.biHeight;
    if (TotHgt < 0) {
        TotHgt = -TotHgt;
        Orien = 1;
        return;
    }
    Orien = -1;
}

long __cdecl TileDibBlt(BITMAPINFO256* DestInfo, uchar* DestBits,
    RECT* ClipRect, long DestX, long DestY, long DestWid, long DestHgt,
    long BlockWid, long BlockHgt, BITMAPINFO256* SrcInfo, uchar* SrcBits,
    TRANSINFO* TransInfo, long SrcX, long SrcY, long SrcWid, long SrcHgt,
    int Trans, int Mirror, int Flip) {
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
                                TransDibBlt(DestInfo, DestBits, ClipRect, x, DestY, DestLtWid, DestTopHgt,
                                            SrcInfo, SrcBits, TransInfo, SrcX, SrcY, SrcRtWid, SrcBotHgt, 1, Mirror, Flip, 0);
                            }
                            if (DestRtWid != 0) {
                                TransDibBlt(DestInfo, DestBits, ClipRect, x + DestLtWid, DestY, DestRtWid, DestTopHgt,
                                            SrcInfo, SrcBits, TransInfo, sxSkip, SrcY, SrcLtWid, SrcBotHgt, 1, Mirror, Flip, 0);
                            }
                        }
                        if (DestBotHgt != 0) {
                            if (DestLtWid != 0) {
                                TransDibBlt(DestInfo, DestBits, ClipRect, x, DestY1, DestLtWid, DestBotHgt,
                                            SrcInfo, SrcBits, TransInfo, SrcX, sySkip, SrcRtWid, SrcTopHgt, 1, Mirror, Flip, 0);
                            }
                            if (DestRtWid != 0) {
                                TransDibBlt(DestInfo, DestBits, ClipRect, x + DestLtWid, DestY1, DestRtWid, DestBotHgt,
                                            SrcInfo, SrcBits, TransInfo, sxSkip, sySkip, SrcLtWid, SrcTopHgt, 1, Mirror, Flip, 0);
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
                            DibBlt(DestInfo, DestBits, ClipRect, x, DestY, DestLtWid, DestTopHgt, SrcInfo, SrcBits,
                                   SrcX, SrcY, SrcRtWid, SrcBotHgt, 1, Mirror, Flip);
                        }
                        if (DestRtWid != 0) {
                            DibBlt(DestInfo, DestBits, ClipRect, x + DestLtWid, DestY, DestRtWid, DestTopHgt,
                                   SrcInfo, SrcBits, sxSkip, SrcY, SrcLtWid, SrcBotHgt, 1, Mirror, Flip);
                        }
                    }
                    if (DestBotHgt != 0) {
                        if (DestLtWid != 0) {
                            DibBlt(DestInfo, DestBits, ClipRect, x, DestY1, DestLtWid, DestBotHgt, SrcInfo, SrcBits,
                                   SrcX, sySkip, SrcRtWid, SrcTopHgt, 1, Mirror, Flip);
                        }
                        if (DestRtWid != 0) {
                            DibBlt(DestInfo, DestBits, ClipRect, x + DestLtWid, DestY1, DestRtWid, DestBotHgt,
                                   SrcInfo, SrcBits, sxSkip, sySkip, SrcLtWid, SrcTopHgt, 1, Mirror, Flip);
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
    unsigned char* DibBits) {
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

void* __cdecl GetPaletteFromDib(char* FileName, int MakeIdentity) {
    BITMAPINFOHEADER* dib = DibOpenFile(FileName);
    if (dib == 0)
        return 0;

    void* palette = DibCreatePalette(dib);
    if (MakeIdentity != 0)
        CreateIdentityPalette(palette);

    DibFree(dib);
    return palette;
}

void* __cdecl ReadPalette(char* FileName, long ResourceId, int MakeIdentity) {
    unsigned char* data;
    void* own_mem = 0;
    int owns_memory = -1;
    void* hpal = 0;
    int resDataSize;
    char* tok = 0;
    int n = 0;
    struct LOGPAL { unsigned short ver; unsigned short cnt; unsigned char e[1]; };
    LOGPAL* lp = 0;
    int i = 0;
    unsigned char* out = 0;
    if (FileName && *FileName && shape_file_first) {
        int fd = _open(FileName, _O_BINARY);
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
    if (!own_mem && ResourceId != -1) {
        data = RESFILE_load(RES_TYPE_BINARY, (unsigned long)ResourceId, owns_memory, resDataSize);
        if (owns_memory == 0) {
            own_mem = malloc(resDataSize);
            memcpy(own_mem, data, resDataSize);
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
    ResourceId = 0;
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
            if (i == n-1) ResourceId = 1;
            ++i;
            out += 4;
            if (i >= n) goto palette_entries_done;
        }
palette_entries_done:
        ;
        if (ResourceId && n == 256 && System_color_Table[0].index >= 0) {
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
        if (ResourceId) {
            hpal = CreatePalette((const tagLOGPALETTE*)lp);
            if (MakeIdentity) {
                if (rge_base_game->draw_system->DrawType == 1 || rge_base_game->draw_system->ScreenMode == 1)
                    CreateIdentityPalette(hpal);
            }
        }
        free(lp);
    }
cleanup:
    if (owns_memory == 1) free(own_mem);
    return hpal;
}

BITMAPINFOHEADER* __cdecl DibOpenFile(char* szFile) {
    int fh;
    OFSTRUCT of;
    BITMAPINFOHEADER* dib;
    DWORD dwBits;

    fh = OpenFile(szFile, &of, OF_READ);
    if (fh == -1) {
        HRSRC resource = FindResourceA(GetModuleHandleA(0), szFile, RT_BITMAP);
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
    BITMAPINFOHEADER* new_dib = (BITMAPINFOHEADER*)GlobalLock(GlobalReAlloc(GlobalHandle(dib), total_size, 0));
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

unsigned char* __cdecl ReadDibBits(char* szFile) {
    OFSTRUCT of;
    unsigned char* result = 0;

    HFILE hf = OpenFile(szFile, &of, OF_READ);
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

int __cdecl DibWriteClipped(BITMAPINFOHEADER* pDIB, char* szFile,
    long x, long y, long w, long h) {
    BITMAPINFO256* clipped = (BITMAPINFO256*)DibCreate(8, w, h);
    unsigned long colors;
    unsigned char* src_bits;
    unsigned char* dst_bits;

    if (clipped == 0)
        return 0;

    colors = pDIB->biClrUsed;
    if (colors == 0 && pDIB->biBitCount <= 8)
        colors = 1 << pDIB->biBitCount;

    memcpy((char*)clipped + clipped->bmiHeader.biSize, (char*)pDIB + pDIB->biSize, colors << 2);

    if (pDIB->biCompression == 3)
        src_bits = (unsigned char*)pDIB + pDIB->biSize + 12;
    else
        src_bits = (unsigned char*)pDIB + pDIB->biSize + pDIB->biClrUsed * 4;

    if (clipped->bmiHeader.biCompression == 3)
        dst_bits = (unsigned char*)clipped + clipped->bmiHeader.biSize + 12;
    else
        dst_bits = (unsigned char*)clipped + clipped->bmiHeader.biSize +
            clipped->bmiHeader.biClrUsed * 4;

    DibBlt(clipped, dst_bits, 0, 0, 0, w, h, (BITMAPINFO256*)pDIB, src_bits, x, y, w, h, 1, 0, 0);
    DibWriteFile(&clipped->bmiHeader, szFile);
    DibFree(&clipped->bmiHeader);
    return 1;
}

int __cdecl DibWriteFile(BITMAPINFOHEADER* pdib, char* szFile) {
    HFILE file;
    int size;
    BITMAPFILEHEADER hdr;
    OFSTRUCT of;
    int colors;

    if (pdib == 0)
        return 0;

    file = OpenFile(szFile, &of, OF_CREATE | OF_READWRITE);
    if (file == (HFILE)-1)
        return 0;

    hdr.bfType = 0x4d42;
    hdr.bfReserved1 = 0;
    size = pdib->biSizeImage + pdib->biClrUsed * 4 + pdib->biSize;
    hdr.bfReserved2 = 0;
    hdr.bfSize = size + sizeof(BITMAPFILEHEADER);

    colors = pdib->biClrUsed;
    if (colors == 0 && pdib->biBitCount <= 8)
        colors = 1 << pdib->biBitCount;

    hdr.bfOffBits = pdib->biSize + colors * 4 + sizeof(BITMAPFILEHEADER);
    _lwrite(file, (char*)&hdr, sizeof(BITMAPFILEHEADER));
    _hwrite(file, (char*)pdib, size);
    _lclose(file);
    return 1;
}

HPALETTE __cdecl DibCreatePalette(BITMAPINFOHEADER* pdib) {
    HPALETTE hpal = 0;
    int colors;
    LOGPALETTE* log_palette;
    RGBQUAD* rgb;
    HDC dc;

    if (pdib == 0)
        return 0;

    colors = pdib->biClrUsed;
    if (colors == 0 && pdib->biBitCount <= 8)
        colors = 1 << pdib->biBitCount;
    if (colors == 3 && pdib->biCompression == BI_BITFIELDS)
        colors = 0;

    if (colors > 0) {
        rgb = (RGBQUAD*)((char*)pdib + pdib->biSize);
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

PDIB __cdecl DibReadBitmapInfo(HFILE fh) {
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

    if (bf.bfType != BFT_BITMAP) {
        bf.bfOffBits = 0L;
        _llseek(fh, off, SEEK_SET);
    }

    if (sizeof(bi) != _lread(fh, (LPSTR)&bi, sizeof(bi)))
        return FALSE;

    switch (size = (int)bi.biSize) {
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

            _llseek(fh, (LONG)sizeof(BITMAPCOREHEADER) - sizeof(BITMAPINFOHEADER), SEEK_CUR);
            break;
    }

    nNumColors = DibNumColors(&bi);

    FixBitmapInfo(&bi);

    pdib = (PDIB)GlobalAllocPtr(GMEM_MOVEABLE, (LONG)bi.biSize + nNumColors * sizeof(RGBQUAD));

    if (!pdib)
        return NULL;

    *pdib = bi;

    pRgb = DibColors(pdib);

    if (nNumColors) {
        if (size == sizeof(BITMAPCOREHEADER)) {
            _lread(fh, (LPVOID)pRgb, nNumColors * sizeof(RGBTRIPLE));

            for (i = nNumColors - 1; i >= 0; i--) {
                RGBQUAD rgb;

                rgb.rgbRed = ((RGBTRIPLE FAR *)pRgb)[i].rgbtRed;
                rgb.rgbBlue = ((RGBTRIPLE FAR *)pRgb)[i].rgbtBlue;
                rgb.rgbGreen = ((RGBTRIPLE FAR *)pRgb)[i].rgbtGreen;
                rgb.rgbReserved = (BYTE)0;

                pRgb[i] = rgb;
            }
        }
        else {
            _lread(fh, (LPVOID)pRgb, nNumColors * sizeof(RGBQUAD));
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
    UINT biBits, HPALETTE hpal, UINT wUsage) {
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

    lpbi = (BITMAPINFOHEADER*)GlobalLock(GlobalAlloc(GMEM_MOVEABLE, sizeof(BITMAPINFOHEADER) + 256 * sizeof(RGBQUAD)));
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
    SetStretchBltMode(hdc, STRETCH_HALFTONE);

    GetDIBits(hdc, hbm, 0, lpbi->biHeight, NULL, (LPBITMAPINFO)lpbi, wUsage);

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
        GlobalHandle(lpbi), lpbi->biSize + lpbi->biClrUsed * sizeof(RGBQUAD) + lpbi->biSizeImage, 0));

    if (lpbiNew != NULL) {
        BYTE* bits;
        if (lpbiNew->biCompression == BI_BITFIELDS)
            bits = (LPBYTE)lpbiNew + lpbiNew->biSize + 3 * sizeof(DWORD);
        else
            bits = (LPBYTE)lpbiNew + lpbiNew->biSize +
                lpbiNew->biClrUsed * sizeof(RGBQUAD);

        result = GetDIBits(hdc, hbm, 0, lpbiNew->biHeight, bits, (LPBITMAPINFO)lpbiNew, wUsage);

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

BOOL __cdecl DibSetUsage(UsagePDIB pdib, HPALETTE hpal, UINT wUsage) {
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
    void* hdc, int x, int y, int dx, int dy,
    BITMAPINFOHEADER* pdib, int x0, int y0, int dx0, int dy0,
    long rop, unsigned int wUsage) {
    if (pdib == 0)
        return 0;

    if (dx0 == -1 && dy0 == -1) {
        dx0 = pdib->biWidth;
        dy0 = pdib->biHeight;
    }
    if (dx == -1 && dy == -1) {
        dx = dx0;
        dy = dy0;
    }

    void* bits;
    if (pdib->biCompression == 3) {
        bits = (char*)pdib + pdib->biSize + 12;
    } else {
        bits = (char*)pdib + pdib->biSize + pdib->biClrUsed * 4;
    }

    return StretchDIBits(hdc, x, y, dx, dy, x0, y0, dx0, dy0, bits, (const BITMAPINFO*)pdib, wUsage, rop);
}

BITMAPINFOHEADER* __cdecl DibCopy(BITMAPINFOHEADER* pdib) {
    tagBITMAPINFOHEADER* copy;

    if (pdib == 0) {
        return 0;
    }

    copy = (tagBITMAPINFOHEADER*)GlobalLock(GlobalAlloc(GMEM_MOVEABLE,
                                                        pdib->biSize + pdib->biClrUsed * 4 + pdib->biSizeImage));
    if (copy != 0) {
        memcpy(copy, pdib, pdib->biSize + pdib->biClrUsed * 4 + pdib->biSizeImage);
    }
    return copy;
}

typedef LPBITMAPINFOHEADER CreatePDIB;

CreatePDIB __cdecl DibCreate(int bits, int dx, int dy) {
    LPBITMAPINFOHEADER lpbi;
    DWORD dwSizeImage;
    int i;
    DWORD FAR* pdw;

    dwSizeImage = dy * (DWORD)((dx * bits / 8 + 3) & ~3);

    lpbi = (CreatePDIB)GlobalLock(GlobalAlloc(GMEM_MOVEABLE | GMEM_ZEROINIT,
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
    unsigned char* xlat) {
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
    unsigned char *xlat) {
    if (dwSize <= 0)
        return;

    do {
        *pb = xlat[*pb & 0x0f] | (xlat[*pb >> 4] << 4);
        ++pb;
        --dwSize;
    } while (dwSize != 0);
}

static void __cdecl xlatRle8(unsigned char* pb, unsigned long dwSize, unsigned char* xlat) {
    unsigned char* p = pb;
    while (1) {
        unsigned char code = p[0];
        unsigned char b = p[1];
        ++p;
        if (code == 0) {
            ++p;
            switch (b) {
            case 0:
                continue;
            case 1:
                return;
            case 2:
                p += 2;
                continue;
            }
            unsigned int count = b;
            if (b > 0) {
                do {
                    unsigned int c = *p;
                    ++p;
                    --count;
                    p[-1] = xlat[c];
                } while (count != 0);
            }
            if (b & 1) {
                ++p;
            }
        } else {
            unsigned int v = b;
            ++p;
            p[-1] = xlat[v];
        }
    }
}

static void __cdecl xlatRle4(unsigned char* pb, unsigned long dwSize,
    unsigned char* xlat) {}

namespace {

extern "C" static void __cdecl memmove(unsigned char* d, unsigned char* s,
    long len) {
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
    int TransLogic, int ZeroIsTrans) {
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
            if (ZeroRed > 255 || ZeroGreen > 255 || ZeroBlue > 255 || ZeroRed < 0 || ZeroGreen < 0 || ZeroBlue < 0) {
                if (HitEnd)
                    break;
                Increment = -1;
                ZeroRed = lpRgb->rgbRed;
                ZeroGreen = lpRgb->rgbGreen;
                ZeroBlue = lpRgb->rgbBlue;
                HitEnd = 1;
            }
            ZeroIndex = (unsigned char)GetNearestPaletteIndex((HPALETTE)hpal, RGB(ZeroRed, ZeroGreen, ZeroBlue));
        } while (ZeroIndex == 0);
    }

    int i;
    for (i = 0; i < nPalColors; ++i) {
        if (TransLogic) {
            if (i == TransIndex) {
                xlat[i] = 0;
            } else {
                xlat[i] = (unsigned char)GetNearestPaletteIndex((HPALETTE)hpal, RGB(lpRgb[i].rgbRed, lpRgb[i].rgbGreen,
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
        GlobalLock(GlobalReAlloc(GlobalHandle(pdib), pdib->biSize + nDibColors * sizeof(RGBQUAD) + SizeImage, 0));

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
        GlobalLock(GlobalReAlloc(GlobalHandle(pdib), pdib->biSize + nDibColors * sizeof(RGBQUAD) + SizeImage, 0));

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

void __cdecl CreateIdentityPalette(void* hpal) {
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

    if (GetSystemPaletteEntries(hdc, 0, 256, palette_locals.new_pal + 1) == 0)
        system_palette_failed = 1;
    if (GetPaletteEntries((HPALETTE)hpal, 0, 256, from_locals.entries + 1) == 0)
        source_palette_failed = 1;

    for (int i = 11; i < 247; ++i) {
        palette_locals.new_pal[i].peRed = from_locals.entries[i].peRed;
        palette_locals.new_pal[i].peGreen = from_locals.entries[i].peGreen;
        palette_locals.new_pal[i].peBlue = from_locals.entries[i].peBlue;
        palette_locals.new_pal[i].peFlags = 1;
    }

    if ((system_palette_failed != 0 || source_palette_failed != 0) && *(int*)System_color_Table >= 0) {
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
    ResizePalette((HPALETTE)hpal, 256);
    SetPaletteEntries((HPALETTE)hpal, 0, 256, palette_locals.new_pal + 1);
}

void* __cdecl CopyPalette(void* hpal) {
    int nNumEntries = 0;

    if (!hpal) return 0;

    GetObjectA((HGDIOBJ)hpal, 4, &nNumEntries);
    if (!nNumEntries) return 0;

    void* pal = LocalAlloc(LMEM_ZEROINIT, nNumEntries * 4 + 8);
    if (!pal) return 0;

    *(short*)pal = 0x300;
    *(short*)((char*)pal + 2) = (short)nNumEntries;

    GetPaletteEntries((HPALETTE)hpal, 0, nNumEntries, (PALETTEENTRY*)((char*)pal + 4));
    void* result = CreatePalette((const tagLOGPALETTE*)pal);
    LocalFree((HLOCAL)pal);
    return result;
}

void __cdecl DibFree(BITMAPINFOHEADER* pdib) {
    void* handle = GlobalHandle(pdib);
    GlobalUnlock(handle);
    handle = GlobalHandle(pdib);
    GlobalFree(handle);
}
