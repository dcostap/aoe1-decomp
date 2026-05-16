// Attempt log for 0043A070 DibFromBitmap
// try 1: natural Win32 reconstruction from packet/decompiler; compiled 688B too small.
// try 2: remove mistaken placeholder realloc and simplify; default now 656B too small.
// try 3: /Oy- flag probe; too small 640B.
// try 4: /O1 flag probe; too small 586B.
// try 5: /GX flag probe; unchanged too small 656B.
// try 6: reviewed allocation/realloc flow vs original; current model missing original GlobalSize/GlobalReAlloc/lock staging.
// try 7: reviewed BITMAP stack layout; initial GetObject/bit-count setup likely close.
// try 8: reviewed BI_BITFIELDS masks; branch family likely close.
// try 9: reviewed DIB bits pointer expression; likely broad mismatch in handle-vs-pointer staging.
// try 10: left in scratch; current source is behavioral scaffold but not exact-size.
// BLOCKER: rebuilt .text 656B vs original 694B with broad unvalidated mismatch; missing exact GlobalAlloc/GlobalSize/GlobalReAlloc/GlobalLock handle choreography and cleanup branch shape. Not accepted_drift-safe.

typedef unsigned long DWORD; typedef unsigned short WORD; typedef unsigned int UINT; typedef void* HANDLE; typedef void* HBITMAP; typedef void* HPALETTE; typedef void* HDC; typedef void* HGLOBAL; typedef unsigned long ULONG;
struct BITMAP { int bmType; int bmWidth; int bmHeight; int bmWidthBytes; WORD bmPlanes; WORD bmBitsPixel; void* bmBits; };
struct BITMAPINFOHEADER { DWORD biSize; int biWidth; int biHeight; WORD biPlanes; WORD biBitCount; DWORD biCompression; DWORD biSizeImage; int biXPelsPerMeter; int biYPelsPerMeter; DWORD biClrUsed; DWORD biClrImportant; };
extern "C" int (__stdcall* const GetObjectA)(void*, int, void*);
extern "C" void* (__stdcall* const GetStockObject)(int);
extern "C" HDC (__stdcall* const CreateCompatibleDC)(HDC);
extern "C" void* (__stdcall* const SelectPalette)(HDC,HPALETTE,int);
extern "C" unsigned int (__stdcall* const RealizePalette)(HDC);
extern "C" int (__stdcall* const SetStretchBltMode)(HDC,int);
extern "C" int (__stdcall* const GetDIBits)(HDC,HBITMAP,UINT,UINT,void*,BITMAPINFOHEADER*,UINT);
extern "C" int (__stdcall* const SelectObject)(HDC,void*);
extern "C" int (__stdcall* const DeleteDC)(HDC);
extern "C" HGLOBAL (__stdcall* const GlobalAlloc)(UINT, DWORD);
extern "C" void* (__stdcall* const GlobalLock)(HGLOBAL);
extern "C" UINT (__stdcall* const GlobalSize)(HGLOBAL);
extern "C" HGLOBAL (__stdcall* const GlobalReAlloc)(HGLOBAL,DWORD,UINT);
extern "C" HGLOBAL (__stdcall* const GlobalFree)(HGLOBAL);
BITMAPINFOHEADER* DibFromBitmap(HBITMAP hbm, DWORD biStyle, UINT biBits, HPALETTE hpal, UINT usage)
{
    int nColors = 0;
    BITMAP bm;
    if (!hbm) return 0;
    if (!hpal) hpal = GetStockObject(15);
    GetObjectA(hbm, 24, &bm);
    GetObjectA(hpal, 4, &nColors);
    if (!biBits) biBits = (bm.bmPlanes & 0xffff) * (bm.bmBitsPixel & 0xffff);
    HGLOBAL h = GlobalAlloc(2, 0x428);
    BITMAPINFOHEADER* lpbi = (BITMAPINFOHEADER*)GlobalLock(h);
    if (!lpbi) return 0;
    lpbi->biSize = 40;
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
    if (biBits <= 8) lpbi->biClrUsed = 1 << biBits; else lpbi->biClrUsed = 0;
    if (biStyle == 3) {
        if (biBits == 16) { ((DWORD*)(lpbi+1))[0]=0xf800; ((DWORD*)(lpbi+1))[1]=0x7e0; ((DWORD*)(lpbi+1))[2]=0x1f; }
        else if (biBits == 24 || biBits == 32) { ((DWORD*)(lpbi+1))[0]=0xff; ((DWORD*)(lpbi+1))[1]=0xff00; ((DWORD*)(lpbi+1))[2]=0xff0000; }
    }
    HDC hdc = CreateCompatibleDC(0);
    void* oldPal = SelectPalette(hdc, hpal, 0);
    RealizePalette(hdc);
    SetStretchBltMode(hdc, 4);
    GetDIBits(hdc, hbm, 0, lpbi->biHeight, 0, lpbi, usage);
    if (!lpbi->biClrUsed && lpbi->biBitCount <= 8) lpbi->biClrUsed = 1 << lpbi->biBitCount;
    if (!lpbi->biSizeImage) {
        lpbi->biSizeImage = (((lpbi->biBitCount * lpbi->biWidth + 31) >> 3) & 0x1ffffffc) * lpbi->biHeight;
    }
    if (!lpbi->biSizeImage) {
        lpbi->biSizeImage = (((lpbi->biBitCount * lpbi->biWidth + 31) >> 3) & 0x1ffffffc) * lpbi->biHeight;
        if (biStyle) lpbi->biSizeImage = lpbi->biSizeImage * 3 / 2;
    }
    DWORD size = lpbi->biSize + lpbi->biClrUsed * 4 + lpbi->biSizeImage;
    h = GlobalReAlloc(h, size, 0);
    BITMAPINFOHEADER* lpbi2 = (BITMAPINFOHEADER*)GlobalLock(h);
    if (!lpbi2) { GlobalFree(h); lpbi = 0; }
    else {
        char* bits = (lpbi2->biCompression == 3) ? ((char*)lpbi2 + lpbi2->biSize + 12) : ((char*)lpbi2 + lpbi2->biSize + lpbi2->biClrUsed * 4);
        GetDIBits(hdc,hbm,0,lpbi2->biHeight,bits,lpbi2,usage);
        if (!lpbi2->biClrUsed && lpbi2->biBitCount <= 8) lpbi2->biClrUsed = 1 << lpbi2->biBitCount;
        if (!lpbi2->biSizeImage) lpbi2->biSizeImage = (((lpbi2->biBitCount * lpbi2->biWidth + 31) >> 3) & 0x1ffffffc) * lpbi2->biHeight;
        if (!bits) { GlobalFree((HGLOBAL)lpbi2); lpbi2 = 0; }
        lpbi = lpbi2;
    }
    SelectPalette(hdc, hpal, 0);
    DeleteDC(hdc);
    return lpbi;
}
