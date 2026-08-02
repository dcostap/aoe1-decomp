// VA: 00439D80 DibCreatePalette (203 bytes)
// PDB source: Dib.cpp, lines 1105-1155
//
// Canonical source reconstruction: build a LOGPALETTE from the RGBQUAD table
// immediately following the bitmap header, or ask GDI for a halftone palette
// when the bitmap has no usable color table.
// Attempt log:
// - baseline natural Windows palette reconstruction matched size, calls, and
//   the setup blocks but used the wrong bit-depth threshold and block topology.
// - positive allocation/late fallback source shape plus LPTR fixed the outer
//   block order; the remaining gap was the redundant entry-loop guard and the
//   byte cursor's base.
// - focused variant lab found exact code with `0 < colors` and a cursor at the
//   palette entry's peGreen byte; this preserves the proven +5 destination
//   anchor and RGBQUAD-to-PALETTEENTRY byte mapping.

#include <windows.h>

HPALETTE __cdecl DibCreatePalette(BITMAPINFOHEADER* dib)
{
    HPALETTE hpal = 0;
    int colors;
    LOGPALETTE* log_palette;
    RGBQUAD* rgb;
    HDC dc;

    if (dib == 0)
        return 0;

    colors = dib->biClrUsed;
    if (colors == 0 && dib->biBitCount <= 8)
        colors = 1 << dib->biBitCount;
    if (colors == 3 && dib->biCompression == BI_BITFIELDS)
        colors = 0;

    if (colors > 0) {
        rgb = (RGBQUAD*)((char*)dib + dib->biSize);
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
