#ifndef AOE1_DIB_H
#define AOE1_DIB_H

#include <windows.h>

typedef unsigned char uchar;

struct BITMAPINFO256 {
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD bmiColors[256];
};

struct LINEINFO {
    union { int AllTrans; int skip; };
    union { int MidSolid; int copy; };
    union { long StartX; long first; };
    union { long EndX; long last; };
};

struct TRANSINFO {
    int AnyTrans;
    long x;
    long y;
    long w;
    long h;
    LINEINFO* LineInfo;
};

typedef char dib_bitmap_info_256_size_check[
    (sizeof(BITMAPINFO256) == 0x428) ? 1 : -1];
typedef char dib_line_info_size_check[
    (sizeof(LINEINFO) == 0x10) ? 1 : -1];
typedef char dib_trans_info_line_offset_check[
    (sizeof(TRANSINFO) == 0x18) ? 1 : -1];

extern long SrcXTbl[];

void __cdecl DibBlt(BITMAPINFO256*, uchar*, RECT*, long, long, long, long,
    BITMAPINFO256*, uchar*, long, long, long, long, int, int, int);
void __cdecl TransDibBlt(BITMAPINFO256*, uchar*, RECT*, long, long, long, long,
    BITMAPINFO256*, uchar*, TRANSINFO*, long, long, long, long, int, int, int,
    int);
int __cdecl ClipDibBlt(BITMAPINFO256*, RECT*, LONG&, LONG&, LONG&, LONG&,
    LONG&, LONG&, LONG&, LONG&, int, int);
void __cdecl GetDibDim(BITMAPINFO256*, long&, long&, long&);
long __cdecl TileDibBlt(BITMAPINFO256*, uchar*, RECT*, long, long, long, long,
    long, long, BITMAPINFO256*, uchar*, TRANSINFO*, long, long, long, long,
    int, int, int);
int __cdecl DibCheckTrans(BITMAPINFO256*, TRANSINFO*, unsigned char*);

void* __cdecl GetPaletteFromDib(char*, int);
void* __cdecl ReadPalette(char*, long, int);
BITMAPINFOHEADER* __cdecl DibOpenFile(char*);
unsigned char* __cdecl ReadDibBits(char*);
int __cdecl DibWriteClipped(BITMAPINFOHEADER*, char*, long, long, long, long);
int __cdecl DibWriteFile(BITMAPINFOHEADER*, char*);
HPALETTE __cdecl DibCreatePalette(BITMAPINFOHEADER*);
LPBITMAPINFOHEADER __cdecl DibReadBitmapInfo(HFILE);
BITMAPINFOHEADER* __cdecl DibFromBitmap(HBITMAP, DWORD, UINT, HPALETTE, UINT);
BOOL __cdecl DibSetUsage(LPBITMAPINFOHEADER, HPALETTE, UINT);
int __cdecl DibDraw(void*, int, int, int, int, BITMAPINFOHEADER*, int, int,
    int, int, long, unsigned int);
BITMAPINFOHEADER* __cdecl DibCopy(BITMAPINFOHEADER*);
LPBITMAPINFOHEADER __cdecl DibCreate(int, int, int);
void __cdecl CreateIdentityPalette(void*);
void* __cdecl CopyPalette(void*);
void __cdecl DibFree(BITMAPINFOHEADER*);

void __cdecl xlatClut4(unsigned char*, unsigned int, unsigned char*);
void __cdecl xlatRle8(unsigned char*, int, unsigned char*);
void __cdecl DibMapToPalette(BITMAPINFOHEADER*, void*, int, int);

extern "C" void* __cdecl memmove(void*, const void*, unsigned int);

#endif
