// VA: 0043A4B0 DibCopy
// BINARY NOTE: The authentic preceding Dib.cpp declarations restore the
// original VC5 register allocation for both size calculations.
#include <windows.h>
#include <string.h>

BITMAPINFOHEADER* DibCopy(BITMAPINFOHEADER* dib) {
    tagBITMAPINFOHEADER* copy;

    if (dib == 0) {
        return 0;
    }

    copy = (tagBITMAPINFOHEADER*)GlobalLock(GlobalAlloc(2, dib->biSize + dib->biClrUsed * 4 + dib->biSizeImage));
    if (copy != 0) {
        memcpy(copy, dib, dib->biSize + dib->biClrUsed * 4 + dib->biSizeImage);
    }
    return copy;
}
