// 0043A660 DibMapToPalette
// Dib.cpp
// Attempt log:
// try 1: broad reconstruction from packet: DIB color-table extraction, palette index mapping, DIB section resize/update and pixel remap.
// try 2: modeled BITMAPINFOHEADER/RGBQUAD/PALETTEENTRY surfaces and GDI imports as stdcall functions.
// try 3: modeled early null hbm/bih returns and color-count calculation from biClrUsed/biBitCount.
// try 4: modeled biSizeImage fallback calculation from width, bitCount, height and 4-byte alignment.
// try 5: modeled bits pointer as header + color table, with BI_BITFIELDS (+compression 3) offset special case.
// try 6: modeled transparent-color search around first RGB entry using GetNearestPaletteIndex and fallback zeroIndex.
// try 7: modeled color-table remap loop populating 256-byte table and preserving transparent index as 0.
// try 8: modeled compression dispatch to 8/24/4/1-bit remap helpers and final GetPaletteEntries loop rewriting RGBQUADs.
// try 9: current source compiles, but rebuilt .text is 768B vs original 1017B, so no full diff.
// try 10: reviewed original: large missing middle includes DIB section reallocation/update via GetObject/GlobalAlloc/GlobalLock/CreateDIBitmap/SelectObject/DeleteObject/GlobalFree and exact pixel copy/remap helpers; current source skips much of that object-update path.
// left in scratch: broad palette remap intent is modeled, but DIB-section resize/update path and exact helper surfaces are missing. No accepted_drift: rebuilt is size-short/no comparable localized diff.

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef void* HPALETTE;
typedef void* HBITMAP;
struct RGBQUAD { BYTE rgbBlue, rgbGreen, rgbRed, rgbReserved; };
struct PALETTEENTRY { BYTE peRed, peGreen, peBlue, peFlags; };
struct BITMAPINFOHEADER {
    DWORD biSize; long biWidth; long biHeight; WORD biPlanes; WORD biBitCount;
    DWORD biCompression; DWORD biSizeImage; long biXPelsPerMeter; long biYPelsPerMeter; DWORD biClrUsed; DWORD biClrImportant;
};
extern "C" int __stdcall GetObjectA(void*, int, void*);
extern "C" int __stdcall GetNearestPaletteIndex(HPALETTE, unsigned long);
extern "C" unsigned int __stdcall GetPaletteEntries(HPALETTE,unsigned int,unsigned int,PALETTEENTRY*);
extern "C" HBITMAP __stdcall CreateDIBitmap(void*, BITMAPINFOHEADER*, unsigned long, void*, void*, unsigned int);
extern "C" void* __stdcall SelectObject(void*, void*);
extern "C" int __stdcall DeleteObject(void*);
extern "C" int __stdcall GetDIBits(void*, HBITMAP, unsigned int, unsigned int, void*, void*, unsigned int);
extern "C" int __stdcall SetDIBits(void*, HBITMAP, unsigned int, unsigned int, void*, void*, unsigned int);
extern "C" void* __stdcall GlobalAlloc(unsigned int, unsigned long);
extern "C" void* __stdcall GlobalLock(void*);
extern "C" int __stdcall GlobalUnlock(void*);
extern "C" void* __stdcall GlobalFree(void*);

void Map8(BYTE*, DWORD, BYTE*); void Map4(BYTE*, DWORD, BYTE*); void Map1(BYTE*, DWORD, BYTE*); void Map24(BYTE*, DWORD, BYTE*);

void DibMapToPalette(BITMAPINFOHEADER* bih, HBITMAP hbm, HPALETTE pal, int transparent, int zero) {
    int nDibColors=0, nPalColors=0, sizeImage=0;
    BYTE zeroIndex=0, hitEnd=0;
    BYTE transIndex=0;
    PALETTEENTRY pe;
    BYTE table[256];
    RGBQUAD* rgb;
    BYTE* bits=0;
    int i;

    if (!hbm || !bih) return;
    rgb = (RGBQUAD*)((char*)bih + bih->biSize);
    GetObjectA(hbm, 4, &nDibColors);
    if (bih->biClrUsed == 0 && bih->biBitCount <= 8) nDibColors = 1 << bih->biBitCount; else nDibColors = bih->biClrUsed;
    sizeImage = bih->biSizeImage;
    if (!sizeImage) sizeImage = (((bih->biWidth * bih->biBitCount + 31) >> 3) & 0x1ffffffc) * bih->biHeight;
    bits = (BYTE*)bih + bih->biSize + (bih->biCompression == 3 ? 12 : nDibColors * 4);

    if (transparent) {
        if (!zero) transIndex = 0; else transIndex = bits[((bih->biWidth + 3) & ~3) * (bih->biHeight - 1)];
        int r=rgb[0].rgbRed, g=rgb[0].rgbGreen, b=rgb[0].rgbBlue;
        int dir=1, pass=0;
        while (!hitEnd) {
            r += dir; g += dir; b += dir;
            if (r>255||g>255||b>255||r<0||g<0||b<0) {
                if (pass) break;
                dir = -1; r=rgb[0].rgbRed; g=rgb[0].rgbGreen; b=rgb[0].rgbBlue; pass=1;
            } else {
                unsigned long c = ((unsigned)b<<16)|((unsigned)g<<8)|(unsigned)r;
                if (GetNearestPaletteIndex(pal,c)) { zeroIndex=(BYTE)GetNearestPaletteIndex(pal,c); hitEnd=1; }
            }
        }
    }
    for (i=0;i<nDibColors;i++) {
        if (transparent && i == transIndex) table[i]=0;
        else {
            unsigned long c = ((unsigned)rgb[i].rgbRed<<16)|((unsigned)rgb[i].rgbGreen<<8)|rgb[i].rgbBlue;
            BYTE v=(BYTE)GetNearestPaletteIndex(pal,c);
            table[i] = v ? v : zeroIndex;
        }
    }
    bih->biClrUsed = nDibColors;
    switch (bih->biCompression) {
    case 0: if (bih->biBitCount==8) Map8(bits,sizeImage,table); else Map24(bits,sizeImage,table); break;
    case 1: Map4(bits,sizeImage,table); break;
    case 2: Map1(bits,sizeImage,table); break;
    }
    for (i=0;i<nDibColors;i++) {
        GetPaletteEntries(pal,i,1,&pe);
        rgb[i].rgbRed=pe.peRed; rgb[i].rgbGreen=pe.peGreen; rgb[i].rgbBlue=pe.peBlue; rgb[i].rgbReserved=0;
    }
}
