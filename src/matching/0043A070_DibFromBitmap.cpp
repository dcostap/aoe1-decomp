// Attempt log for 0043A070 DibFromBitmap
// baseline: typed Win32 BITMAP/BITMAPINFOHEADER source with the original
// GlobalHandle/GlobalUnlock/GlobalReAlloc ownership flow.
// probe 2: restored the period DIB utility call order and retained the old
// palette result as the GetDIBits usage argument; call parity reached 23/23.
// probe 3: used assignment expressions for driver-filled color/image defaults
// and success-first realloc cleanup; size reached +9 with ordered calls exact.
// probe 4: used typed header-plus-palette DWORD storage and reversed the
// bitfield gate; size reached 694 and the main code island aligned.
// probes 5-6: explicit nColors initialization and a bitmap-handle local were
// codegen duplicates; no source change was retained for either.
// probes 7-8: a local palette copy removed a 7-byte store but worsened the
// whole-function result; restored direct hpal ownership as the best source.
// probe 10: delaying a bitmap-handle local was a codegen duplicate; removed it.
// probe 11: initializing bm.bmType before the null guard was a natural typed
// local/control reconstruction; it changed one byte and worsened resync, so
// it was rolled back. The clean source remains the best reconstruction.
// probe 12: a local BITMAPINFOHEADER copied into the allocated header changed
// the frame to 44h and worsened the structural result; rolled back.
// probe 13: moving a bitmap alias to the first local declaration was a codegen
// duplicate; rolled back.
// probe 14: using bm.bmType as the palette GetObject destination reduced the
// frame and worsened the local topology; rolled back.
// probe 15: a WORD bit-depth parameter matched the early BX comparisons but
// changed later bitfield compares and size; restored the UINT ABI.
// probe 16: DibNumColors(lpbi) restored the header-field width and improved
// block shape. A local palette handle kept the caller hpal home unchanged.
// probe 17: delaying that palette copy until after the bitmap null guard moved
// the first mismatch to the SelectPalette usage store and is retained.
// probe 18: keeping the local palette for final restoration worsened size;
// probe 19: a separate paletteUsage local did not match the usage home.
// probe 20: assigning the SelectPalette result to hpal, while retaining the
// local palette alias for setup, reproduced the original result-store and
// final restoration ownership. The authoritative check is an exact MATCH.

#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <memory.h>

#define DibNumColors(lpbi) \
    ((lpbi)->biClrUsed == 0 && (lpbi)->biBitCount <= 8 ? \
        (int)(1 << (int)(lpbi)->biBitCount) : (int)(lpbi)->biClrUsed)

extern void __cdecl DibFree(BITMAPINFOHEADER* lpbi);

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

    lpbi->biClrUsed = DibNumColors(lpbi);

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

    lpbi->biClrUsed = DibNumColors(lpbi);

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

        lpbiNew->biClrUsed = DibNumColors(lpbiNew);

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
