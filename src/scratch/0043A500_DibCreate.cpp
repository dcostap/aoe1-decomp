#include <windows.h>

// VA: 0043A500 DibCreate | Dib.cpp:1605-1659
// Attempt log:
// - baseline: typed Win32 BITMAPINFOHEADER/GlobalAlloc/GlobalLock source;
//   calls, frame, and palette-store family are understood, but parameter
//   register coloring and the setup block still differ.
// - natural signed row-byte division, operand/order, and total-size lifetime
//   variants did not move the compiler basin; no raw stack or register-forcing
//   scaffolding retained.

BITMAPINFOHEADER* __cdecl DibCreate(int bits, int width, int height)
{
    int total_size;
    BITMAPINFOHEADER* info;
    DWORD* pal;
    int i;

    total_size = (((bits * width) / 8 + 3) & ~3) * height;
    info = (BITMAPINFOHEADER*)GlobalLock(
        GlobalAlloc(GMEM_MOVEABLE | GMEM_ZEROINIT, total_size + 0x428));
    if (info == 0) {
        return 0;
    }

    info->biSize = 0x28;
    info->biWidth = width;
    info->biHeight = height;
    info->biPlanes = 1;
    info->biBitCount = (unsigned short)bits;
    info->biCompression = 0;
    info->biSizeImage = total_size;
    info->biXPelsPerMeter = 0;
    info->biYPelsPerMeter = 0;
    info->biClrUsed = 0;
    info->biClrImportant = 0;
    if (bits == 4) {
        info->biClrUsed = 0x10;
    } else if (bits == 8) {
        info->biClrUsed = 0x100;
    }

    pal = (DWORD*)(info + 1);
    i = 0;
    while (i < (int)((info->biClrUsed + (((int)info->biClrUsed >> 31) & 0xf)) >> 4)) {
        *pal++ = 0;
        *pal++ = 0x800000;
        *pal++ = 0x8000;
        *pal++ = 0x808000;
        *pal++ = 0x80;
        *pal++ = 0x800080;
        *pal++ = 0x8080;
        *pal++ = 0xc0c0c0;
        *pal++ = 0x808080;
        *pal++ = 0xff0000;
        *pal++ = 0xff00;
        *pal++ = 0xffff00;
        *pal++ = 0xff;
        *pal++ = 0xff00ff;
        *pal++ = 0xffff;
        *pal++ = 0xffffff;
        i++;
    }
    return info;
}
