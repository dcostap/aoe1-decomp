// VA: 0043AB80 CreateIdentityPalette
// PDB source: Dib.cpp, lines 1930-1992
// Attempt log:
// - Baseline natural Windows palette reconstruction: typed PALETTEENTRY arrays,
//   separate active-window/DC handles, failure flags, and the system-color
//   fallback table.  The palette arrays intentionally use entry 0 as the
//   window-handle stack home, matching the source-level non-overlap after the
//   APIs receive new_pal + 1/from_pal + 1.
// - A byte-cursor rewrite was rolled back: it changed register/liveness shape
//   and lost structural parity despite using the observed 0x3b0-byte span.
// - Reordering declarations did not move the four-byte array-home drift.
// - A typed union models the proven hwnd/new_pal[0] stack overlap.  The source
//   palette aggregate names the proven one-entry API overrun: GetPaletteEntries
//   writes 0x100 entries through entries + 1, so its final dword occupies the
//   adjacent typed api_overrun home.  This preserves the original 0x808 frame
//   without raw frame offsets or compiler-only volatile scaffolding.
// - Exact baseline after the typed overlay/overrun model: 297/297 bytes,
//   7/7 ordered indirect calls, frame 0x808, 0.0000% positional diff.
// - Main-agent audit corrected System_color_Table to its binary-proven scalar
//   head index; the typed stack-overlap/API-overrun model remains exact.

#include <windows.h>

// Dib.cpp's earlier ReadPalette owner declares this storage as an array of
// 0x8-byte palette records.  This function only reads the first record's
// index, so keep the scalar access without redeclaring the storage as int.
struct PAL_TABLE;
extern PAL_TABLE System_color_Table[];
extern unsigned char DAT_005841e5;

void __cdecl CreateIdentityPalette(void* palette)
{
    union {
        PALETTEENTRY new_pal[256];
        HWND hwnd;
    } palette_locals;
    HDC hdc;
    struct {
        PALETTEENTRY entries[256];
        PALETTEENTRY api_overrun;
    } from_locals;
    int system_palette_failed = 0;
    int source_palette_failed = 0;

    palette_locals.hwnd = GetActiveWindow();
    if (palette_locals.hwnd != 0)
        hdc = GetDC(palette_locals.hwnd);
    else
        hdc = GetDC(0);

    if (GetSystemPaletteEntries(hdc, 0, 0x100, palette_locals.new_pal + 1) == 0)
        system_palette_failed = 1;
    if (GetPaletteEntries((HPALETTE)palette, 0, 0x100, from_locals.entries + 1) == 0)
        source_palette_failed = 1;

    for (int i = 11; i < 247; ++i) {
        palette_locals.new_pal[i].peRed = from_locals.entries[i].peRed;
        palette_locals.new_pal[i].peGreen = from_locals.entries[i].peGreen;
        palette_locals.new_pal[i].peBlue = from_locals.entries[i].peBlue;
        palette_locals.new_pal[i].peFlags = 1;
    }

    if ((system_palette_failed != 0 || source_palette_failed != 0) &&
        *(int*)System_color_Table >= 0) {
        int index = *(int*)System_color_Table;
        unsigned char* colors = &DAT_005841e5;
        do {
            palette_locals.new_pal[index + 1].peRed = colors[-1];
            palette_locals.new_pal[index + 1].peGreen = colors[0];
            palette_locals.new_pal[index + 1].peBlue = colors[1];
            palette_locals.new_pal[index + 1].peFlags = 0;
            index = *(int*)(colors + 3);
            colors += 8;
        } while (index >= 0);
    }

    ReleaseDC(palette_locals.hwnd, hdc);
    ResizePalette((HPALETTE)palette, 0x100);
    SetPaletteEntries((HPALETTE)palette, 0, 0x100, palette_locals.new_pal + 1);
}
