// VA: 0043A330 DibSetUsage
// PDB source: Dib.cpp, lines 1482-1538
//
// Canonical reconstruction: set a DIB color table either to palette indices
// (DIB_PAL_COLORS) or to RGBQUAD values copied from a GDI palette.
// Attempt log:
// - baseline candidate uses the period Windows BITMAPINFOHEADER,
//   PALETTEENTRY, and RGBQUAD surfaces with the observed local palette array,
//   two GDI calls, and separate indexed/RGB table paths.
// - replaced the first candidate's pointer-walk spelling with the original
//   DIB utility's switch/for/parallel-array shape; the first candidate was
//   structurally short and allocated the wrong callee-save set.
// - restored the period DIB utility macro/type surface (PDIB, FAR pointers,
//   and the NumColors/Compression/Colors helpers), producing exact size,
//   frame, CFG, calls, and all but seven register-encoding bytes.
// - declaration-order, address-expression, ABI-alias, captured-pointer, and
//   predicate-direction probes all stayed in the same seven-byte codegen basin;
//   the declaration-order lab likewise produced one emitted group.
// - best validated reconstruction remains a localized EDX-vs-EBX parameter /
//   color-table register allocation gap at the post-null-check block.
// - adding the period DIBUTILS translation-unit headers (windowsx.h, stdio.h,
//   and memory.h) moved the live parameter/table pointers to the original
//   registers and produced an exact 240-byte match; retain that plausible TU
//   context.

#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <memory.h>

#define DibNumColors(lpbi) \
    ((lpbi)->biClrUsed == 0 && (lpbi)->biBitCount <= 8 ? \
        (int)(1 << (int)(lpbi)->biBitCount) : (int)(lpbi)->biClrUsed)
#define DibCompression(lpbi) \
    (DWORD)(((LPBITMAPINFOHEADER)(lpbi))->biCompression)
#define DibColors(lpbi) \
    ((RGBQUAD FAR *)((LPBYTE)(lpbi) + (int)(lpbi)->biSize))

typedef LPBITMAPINFOHEADER PDIB;

BOOL __cdecl DibSetUsage(PDIB pdib, HPALETTE hpal, UINT wUsage)
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

    colors = DibNumColors(pdib);
    if (colors == 3 && DibCompression(pdib) == BI_BITFIELDS)
        colors = 0;

    if (colors > 0) {
        pRgb = DibColors(pdib);
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
