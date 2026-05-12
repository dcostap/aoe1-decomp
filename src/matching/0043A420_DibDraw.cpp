// VA: 0043A420 DibDraw
// PDB: Dib.cpp lines 1546-1589 (136 bytes, 59 asm lines)
// Default flags. No inline asm/hacks.
// __cdecl, many params. IAT call to StretchDIBits.

#pragma pack(push, 1)
typedef struct {
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} tagBITMAPINFOHEADER;
#pragma pack(pop)

extern "C" int __declspec(dllimport) __stdcall StretchDIBits(
    void* hdc, int xDest, int yDest, int wDest, int hDest,
    int xSrc, int ySrc, int wSrc, int hSrc,
    const void* lpBits, const tagBITMAPINFOHEADER* lpBitsInfo,
    unsigned int iUsage, long dwRop);

extern "C" int __cdecl DibDraw(
    void* a1, int a2, int a3, int a4, int a5,
    tagBITMAPINFOHEADER* a6, int a7, int a8, int a9, int a10,
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
                         bits, a6, a12, a11);
}
