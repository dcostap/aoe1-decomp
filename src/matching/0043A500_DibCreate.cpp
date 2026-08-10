#include <windows.h>

// VA: 0043A500 DibCreate | Dib.cpp:1605-1659
// Attempt log:
// - baseline: typed Win32 BITMAPINFOHEADER/GlobalAlloc/GlobalLock source;
//   calls, frame, and palette-store family are understood, but parameter
//   register coloring and the setup block still differ.
// - natural signed row-byte division, operand/order, and total-size lifetime
//   variants did not move the compiler basin; no raw stack or register-forcing
//   scaffolding retained.
// - restored the period DIBUTILS source shape: `dwSizeImage` from
//   `dy*(DWORD)((dx*bits/8+3)&~3)`, the typed `PDIB`/`DWORD FAR*` surfaces,
//   natural field initialization, and the 16-entry palette fill loop; this
//   produces an exact 341-byte match under the default flags.

typedef LPBITMAPINFOHEADER PDIB;

PDIB __cdecl DibCreate(int bits, int dx, int dy)
{
    LPBITMAPINFOHEADER lpbi;
    DWORD dwSizeImage;
    int i;
    DWORD FAR* pdw;

    dwSizeImage = dy * (DWORD)((dx * bits / 8 + 3) & ~3);

    lpbi = (PDIB)GlobalLock(GlobalAlloc(
        GMEM_MOVEABLE | GMEM_ZEROINIT,
        sizeof(BITMAPINFOHEADER) + dwSizeImage + 1024));

    if (lpbi == NULL)
        return NULL;

    lpbi->biSize = sizeof(BITMAPINFOHEADER);
    lpbi->biWidth = dx;
    lpbi->biHeight = dy;
    lpbi->biPlanes = 1;
    lpbi->biBitCount = bits;
    lpbi->biCompression = BI_RGB;
    lpbi->biSizeImage = dwSizeImage;
    lpbi->biXPelsPerMeter = 0;
    lpbi->biYPelsPerMeter = 0;
    lpbi->biClrUsed = 0;
    lpbi->biClrImportant = 0;

    if (bits == 4) {
        lpbi->biClrUsed = 16;
    }
    else if (bits == 8) {
        lpbi->biClrUsed = 256;
    }

    pdw = (DWORD FAR *)((LPBYTE)lpbi + (int)lpbi->biSize);

    for (i = 0; i < (int)lpbi->biClrUsed / 16; i++) {
        *pdw++ = 0x00000000;
        *pdw++ = 0x00800000;
        *pdw++ = 0x00008000;
        *pdw++ = 0x00808000;
        *pdw++ = 0x00000080;
        *pdw++ = 0x00800080;
        *pdw++ = 0x00008080;
        *pdw++ = 0x00C0C0C0;
        *pdw++ = 0x00808080;
        *pdw++ = 0x00FF0000;
        *pdw++ = 0x0000FF00;
        *pdw++ = 0x00FFFF00;
        *pdw++ = 0x000000FF;
        *pdw++ = 0x00FF00FF;
        *pdw++ = 0x0000FFFF;
        *pdw++ = 0x00FFFFFF;
    }
    return (PDIB)lpbi;
}
