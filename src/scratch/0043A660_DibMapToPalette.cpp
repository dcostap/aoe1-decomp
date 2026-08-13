// 0043A660 DibMapToPalette
// Dib.cpp
// Attempt log:
// - Baseline established typed DIB ownership, palette lookup/remap, compression dispatch,
//   and the final palette-entry rewrite; the first build was missing the DIB resize path.
// - Replaced direct stdcall declarations with the IAT function-pointer surface and
//   corrected the packet ABI to four arguments (one handle is both bitmap/palette).
// - Added the binary-proven grow/shrink paths: GlobalHandle/GlobalUnlock,
//   GlobalReAlloc/GlobalLock, and the memmove/memcpy image preservation calls.
// - Restored the original positive null-test order, header color-count ownership, and
//   BI_BITFIELDS/non-BI bits offsets; the current frame/code shape is close but nonexact.
// - Kept the natural one-call transparent search and separate transparent/nontransparent
//   table branches after the executable showed that the raw nearest-index zero is not
//   replaced by zeroIndex on the nontransparent path.
// - Moved the binary-proven grow-branch memmove before compression dispatch; this
//   restores the original ordered 21-call surface and improves the structural diff.
// - Replaced the initial bits-address ternary with the explicit BI_BITFIELDS branch
//   used by the neighboring Dib.cpp donors; this improves the diff from 942 to 911.
// - Typed SizeImage as the packet-proven unsigned DWORD; VC5 emitted the same code,
//   so the source-backed type correction is retained without a metric change.
// - Reversed the palette-flags branch: the original takes the zero-index path
//   when flags are nonzero and reads the bottom-row byte otherwise; diff improved
//   from 911 to 910 bytes and the branch opcode now matches.
// left in scratch: the current reconstruction is 910 differing bytes (56.97% shape,
// 21/21 ordered calls, frame 0x124 vs 0x128, code size 963 vs 1017); remaining drift
// is structural (local-home/lifetime and resize/dispatch block layout), not an
// established behavior gap.

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef void* HPALETTE;
typedef void* HBITMAP;
#include <string.h>
struct RGBQUAD { BYTE rgbBlue, rgbGreen, rgbRed, rgbReserved; };
struct PALETTEENTRY { BYTE peRed, peGreen, peBlue, peFlags; };
struct BITMAPINFOHEADER {
    DWORD biSize; long biWidth; long biHeight; WORD biPlanes; WORD biBitCount;
    DWORD biCompression; DWORD biSizeImage; long biXPelsPerMeter; long biYPelsPerMeter; DWORD biClrUsed; DWORD biClrImportant;
};
extern "C" int (__stdcall* const GetObjectA)(void*, int, void*);
extern "C" unsigned int (__stdcall* const GetNearestPaletteIndex)(HPALETTE, unsigned long);
extern "C" unsigned int (__stdcall* const GetPaletteEntries)(HPALETTE,unsigned int,unsigned int,PALETTEENTRY*);
extern "C" void* (__stdcall* const GlobalHandle)(void*);
extern "C" int (__stdcall* const GlobalUnlock)(void*);
extern "C" void* (__stdcall* const GlobalReAlloc)(void*, unsigned long, unsigned int);
extern "C" void* (__stdcall* const GlobalLock)(void*);

#pragma function(memcpy)
#pragma function(memmove)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern "C" void* __cdecl memmove(void*, const void*, unsigned int);
void __cdecl xlatRle4(BYTE*, DWORD, BYTE*);
void __cdecl xlatRle8(BYTE*, DWORD, BYTE*);
void __cdecl xlatClut8(BYTE*, DWORD, BYTE*);
void __cdecl xlatClut4(BYTE*, DWORD, BYTE*);

void DibMapToPalette(BITMAPINFOHEADER* bih, void* hbm, int transparent, int zero) {
    int nDibColors=0, nPalColors=0;
    DWORD sizeImage=0;
    BYTE zeroIndex=0, hitEnd=0;
    BYTE transIndex=0;
    PALETTEENTRY pe;
    BYTE table[256];
    RGBQUAD* rgb;
    BYTE* bits=0;
    int i;

    if (hbm != 0 && bih != 0) {
    rgb = (RGBQUAD*)((char*)bih + bih->biSize);
    GetObjectA(hbm, 4, &nDibColors);
    if (bih->biClrUsed == 0 && bih->biBitCount <= 8) nPalColors = 1 << bih->biBitCount; else nPalColors = bih->biClrUsed;
    sizeImage = bih->biSizeImage;
    if (!sizeImage) sizeImage = (((bih->biWidth * bih->biBitCount + 31) >> 3) & 0x1ffffffc) * bih->biHeight;
    if (bih->biCompression == 3)
        bits = (BYTE*)bih + bih->biSize + 12;
    else
        bits = (BYTE*)bih + bih->biSize + nPalColors * 4;

    if (transparent) {
        if (zero) transIndex = 0; else transIndex = bits[((bih->biWidth + 3) & ~3) * (bih->biHeight - 1)];
        int r=rgb[0].rgbRed, g=rgb[0].rgbGreen, b=rgb[0].rgbBlue;
        int dir=1, pass=0;
        while (!hitEnd) {
            r += dir; g += dir; b += dir;
            if (r>255||g>255||b>255||r<0||g<0||b<0) {
                if (pass) break;
                dir = -1; r=rgb[0].rgbRed; g=rgb[0].rgbGreen; b=rgb[0].rgbBlue; pass=1;
            } else {
                unsigned long c = ((unsigned)b<<16)|((unsigned)g<<8)|(unsigned)r;
                BYTE v = (BYTE)GetNearestPaletteIndex(hbm,c);
                if (v) { zeroIndex=v; hitEnd=1; }
            }
        }
    }
    for (i=0;i<nPalColors;i++) {
        if (!transparent) {
            unsigned long c = ((unsigned)rgb[i].rgbRed<<16)|((unsigned)rgb[i].rgbGreen<<8)|rgb[i].rgbBlue;
            table[i] = (BYTE)GetNearestPaletteIndex(hbm,c);
        } else if (i == transIndex) {
            table[i] = 0;
        } else {
            unsigned long c = ((unsigned)rgb[i].rgbRed<<16)|((unsigned)rgb[i].rgbGreen<<8)|rgb[i].rgbBlue;
            BYTE v=(BYTE)GetNearestPaletteIndex(hbm,c);
            table[i] = v ? v : zeroIndex;
        }
    }
    bih->biClrUsed = nDibColors;
    BYTE* oldBits = bits;
    if (nPalColors < nDibColors) {
        BYTE* newBits;
        GlobalUnlock(GlobalHandle(bih));
        GlobalLock(GlobalReAlloc(GlobalHandle(bih),
            bih->biSize + nDibColors * 4 + sizeImage, 0));
        if (bih->biCompression == 3)
            newBits = (BYTE*)bih + bih->biSize + 12;
        else
            newBits = (BYTE*)bih + bih->biSize + bih->biClrUsed * 4;
        bits = newBits;
        memmove(bits, oldBits, sizeImage);
    } else if (nPalColors > nDibColors) {
        BYTE* newBits;
        if (bih->biCompression == 3)
            newBits = (BYTE*)bih + bih->biSize + 12;
        else
            newBits = (BYTE*)bih + bih->biSize + bih->biClrUsed * 4;
        memcpy(newBits, bits, sizeImage);
        GlobalUnlock(GlobalHandle(bih));
        GlobalLock(GlobalReAlloc(GlobalHandle(bih),
            bih->biSize + nDibColors * 4 + sizeImage, 0));
    }
    if (bih->biCompression == 3)
        bits = (BYTE*)bih + bih->biSize + 12;
    else
        bits = (BYTE*)bih + bih->biSize + bih->biClrUsed * 4;
    switch (bih->biCompression) {
    case 0: if (bih->biBitCount==8) xlatClut8(bits,sizeImage,table); else xlatClut4(bits,sizeImage,table); break;
    case 1: xlatRle8(bits,sizeImage,table); break;
    case 2: xlatRle4(bits,sizeImage,table); break;
    }
    for (i=0;i<nDibColors;i++) {
        GetPaletteEntries(hbm,i,1,&pe);
        rgb[i].rgbRed=pe.peRed; rgb[i].rgbGreen=pe.peGreen; rgb[i].rgbBlue=pe.peBlue; rgb[i].rgbReserved=0;
    }
    }
}
