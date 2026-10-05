#ifndef AOE1_DIB_H
#define AOE1_DIB_H

#include <windows.h>
#include "bitmap_info.h"
#include "picture_types.h"

typedef unsigned char uchar;

struct PAL_TABLE {
    int index;
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char reserved;
};

typedef char dib_palette_table_size_check[(sizeof(PAL_TABLE) == 8) ? 1 : -1];

typedef char dib_bitmap_info_256_size_check[(sizeof(BITMAPINFO256) == 0x428) ? 1 : -1];
typedef char dib_line_info_size_check[(sizeof(LINEINFO) == 0x10) ? 1 : -1];
typedef char dib_trans_info_line_offset_check[(sizeof(TRANSINFO) == 0x18) ? 1 : -1];

void __cdecl DibBlt(
    BITMAPINFO256* DestInfo, uchar* DestBits, RECT* ClipRect, long DestX, long DestY, long DestWid, long DestHgt,
    BITMAPINFO256* SrcInfo, uchar* SrcBits, long SrcX, long SrcY, long SrcWid, long SrcHgt, int Clip, int Mirror,
    int Flip
);
void __cdecl TransDibBlt(
    BITMAPINFO256* DestInfo, uchar* DestBits, RECT* ClipRect, long DestX, long DestY, long DestWid, long DestHgt,
    BITMAPINFO256* SrcInfo, uchar* SrcBits, TRANSINFO* TransInfo, long SrcX, long SrcY, long SrcWid, long SrcHgt,
    int Clip, int Mirror, int Flip, int TransColor
);
int __cdecl ClipDibBlt(
    BITMAPINFO256* DestInfo, RECT* ClipRect, LONG& DestX, LONG& DestY, LONG& DestWid, LONG& DestHgt, LONG& SrcX,
    LONG& SrcY, LONG& SrcWid, LONG& SrcHgt, int Mirror, int Flip
);
void __cdecl GetDibDim(BITMAPINFO256* Info, long& TotWid, long& TotHgt, long& Orien);
long __cdecl TileDibBlt(
    BITMAPINFO256* DestInfo, uchar* DestBits, RECT* ClipRect, long DestX, long DestY, long DestWid, long DestHgt,
    long BlockWid, long BlockHgt, BITMAPINFO256* SrcInfo, uchar* SrcBits, TRANSINFO* TransInfo, long SrcX, long SrcY,
    long SrcWid, long SrcHgt, int Trans, int Mirror, int Flip
);
int __cdecl DibCheckTrans(BITMAPINFO256* DibInfo, TRANSINFO* TransInfo, unsigned char* DibBits);

void* __cdecl GetPaletteFromDib(char* FileName, int MakeIdentity);
void* __cdecl ReadPalette(char* FileName, long ResourceId, int MakeIdentity);
BITMAPINFOHEADER* __cdecl DibOpenFile(char* szFile);
unsigned char* __cdecl ReadDibBits(char* szFile);
int __cdecl DibWriteClipped(BITMAPINFOHEADER* pDIB, char* szFile, long x, long y, long w, long h);
int __cdecl DibWriteFile(BITMAPINFOHEADER* pdib, char* szFile);
HPALETTE __cdecl DibCreatePalette(BITMAPINFOHEADER* pdib);
LPBITMAPINFOHEADER __cdecl DibReadBitmapInfo(HFILE fh);
BITMAPINFOHEADER* __cdecl DibFromBitmap(HBITMAP hbm, DWORD biStyle, UINT biBits, HPALETTE hpal, UINT wUsage);
BOOL __cdecl DibSetUsage(LPBITMAPINFOHEADER pdib, HPALETTE hpal, UINT wUsage);
int __cdecl DibDraw(
    void* hdc, int x, int y, int dx, int dy, BITMAPINFOHEADER* pdib, int x0, int y0, int dx0, int dy0, long rop,
    unsigned int wUsage
);
BITMAPINFOHEADER* __cdecl DibCopy(BITMAPINFOHEADER* pdib);
LPBITMAPINFOHEADER __cdecl DibCreate(int bits, int dx, int dy);
void __cdecl CreateIdentityPalette(void* hpal);
void* __cdecl CopyPalette(void* hpal);
void __cdecl DibFree(BITMAPINFOHEADER* pdib);

void __cdecl DibMapToPalette(BITMAPINFOHEADER* pdib, void* hpal, int TransLogic, int ZeroIsTrans);

extern "C" void* __cdecl memmove(void*, const void*, unsigned int);

#endif
