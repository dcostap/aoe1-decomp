// VA: 00439BE0 DibWriteClipped
// PDB source: Dib.cpp, lines 1042-1059
// Attempt log:
// - Baseline: natural BITMAPINFO256 ownership with the palette copy, compression
//   data pointers, and the DibBlt/DibWriteFile/DibFree call family.
// - Added #pragma function(memcpy) because VC5 otherwise expanded the proven
//   direct memcpy call into rep movsd/movsb.
// - Changed the palette fallback guard to biBitCount <= 8, matching the original
//   cmp 8 / ja and restoring exact bytes.

#include <windows.h>

#ifndef DIB_BITMAP_INFO_256_DEFINED
#define DIB_BITMAP_INFO_256_DEFINED
struct BITMAPINFO256 {
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD bmiColors[256];
};
#endif

extern BITMAPINFOHEADER* __cdecl DibCreate(int bits, int width, int height);
extern void __cdecl DibBlt(BITMAPINFO256*, unsigned char*, RECT*,
    long, long, long, long, BITMAPINFO256*, unsigned char*,
    long, long, long, long, int, int, int);
extern int __cdecl DibWriteFile(BITMAPINFOHEADER*, char* name);
extern void __cdecl DibFree(BITMAPINFOHEADER*);
#pragma function(memcpy)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);

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
