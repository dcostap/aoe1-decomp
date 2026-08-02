// VA: 00439CC0 DibWriteFile
// PDB source: Dib.cpp, lines 1066-1095
// Attempt log:
// - Baseline: reconstructed the period Windows bitmap-file write using the
//   canonical BITMAPINFOHEADER/BITMAPFILEHEADER and OFSTRUCT surfaces; all
//   layout, calls, frame, and code shape matched except the OpenFile mode.
// - Behavior: corrected the source mode to OF_CREATE | OF_READWRITE (0x1002);
//   exact bytes matched.

#include <windows.h>

int __cdecl DibWriteFile(BITMAPINFOHEADER* dib, char* name)
{
    HFILE file;
    int size;
    BITMAPFILEHEADER hdr;
    OFSTRUCT of;
    int colors;

    if (dib == 0)
        return 0;

    file = OpenFile(name, &of, OF_CREATE | OF_READWRITE);
    if (file == (HFILE)-1)
        return 0;

    hdr.bfType = 0x4d42;
    hdr.bfReserved1 = 0;
    size = dib->biSizeImage + dib->biClrUsed * 4 + dib->biSize;
    hdr.bfReserved2 = 0;
    hdr.bfSize = size + sizeof(BITMAPFILEHEADER);

    colors = dib->biClrUsed;
    if (colors == 0 && dib->biBitCount <= 8)
        colors = 1 << dib->biBitCount;

    hdr.bfOffBits = dib->biSize + colors * 4 + sizeof(BITMAPFILEHEADER);
    _lwrite(file, (char*)&hdr, sizeof(BITMAPFILEHEADER));
    _hwrite(file, (char*)dib, size);
    _lclose(file);
    return 1;
}
