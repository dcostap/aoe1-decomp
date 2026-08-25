// VA: 0043A420 DibDraw
// PDB: Dib.cpp lines 1546-1589 (136 bytes, 59 asm lines)
// BINARY NOTE: The authentic Dib.cpp context restores exact VC5 codegen.
#include <windows.h>

int __cdecl DibDraw(
    void* a1, int a2, int a3, int a4, int a5,
    BITMAPINFOHEADER* a6, int a7, int a8, int a9, int a10,
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
                         bits, (const BITMAPINFO*)a6, a12, a11);
}
