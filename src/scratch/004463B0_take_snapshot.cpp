// VA: 004463B0 TDrawArea::take_snapshot
// Attempt log:
// - Replaced the prior unrelated BMP shim with the binary-backed Drawarea.cpp
//   snapshot pipeline: typed Win32 bitmap records, palette conversion, the
//   numbered-open loop, and the Lock/write/unlock row walk.
// - Baseline: natural typed source matched all 14 ordered calls but was 14
//   bytes short (frame 0x878); adding the binary-backed height local restored
//   the exact 0x87C frame and 540-byte effective size.
// - Tried delayed biHeight initialization, commutative product reversal,
//   declaration reordering, and a register product temporary; these were
//   duplicate or worse codegen basins. A 24-variant init/product/open-loop
//   lab likewise found no exact variant; keep the ordinary inline-return
//   loop shape.
// - Diagnostic predecessor-pointer offsets aligned some palette/filename
//   displacements but made the local pointer long-lived, changed register
//   roles, shortened the function, and changed the Unlock call; rolled back.
// - Best clean reconstruction: exact frame/size/call set, remaining drift is
//   VC5 local/register/block scheduling around the header and early returns.

#include <windows.h>
#include <stdio.h>

extern "C" int __cdecl __open(const char* path, int flags, ...);
extern "C" int __cdecl write(int file, void* data, int size);
extern "C" int __cdecl close(int file);
extern "C" void* __cdecl malloc(unsigned int size);
extern "C" void __cdecl free(void* p);

class TDrawArea {
public:
    char gap_00[0x18];
    int Width;                              // +0x18
    int Height;                             // +0x1C
    char gap_20[0xA0];
    unsigned char** CurDisplayOffsets;      // +0xC0

    void GetPalette(PALETTEENTRY* entries);
    unsigned char* Lock(char* name, int flags);
    void Unlock(char* name);
    void take_snapshot(char* name, int& number);
};

void TDrawArea::take_snapshot(char* name, int& number)
{
    int bmWide;
    int bmHeight;
    BITMAPFILEHEADER bmFH;
    BITMAPINFOHEADER bmIH;
    char BMPFile[60];
    RGBQUAD bmPAL[256];
    PALETTEENTRY thePal[256];

    bmIH.biWidth = this->Width;
    bmHeight = this->Height;
    bmIH.biHeight = bmHeight;
    bmWide = (bmIH.biWidth + 3) & 0xfffc;

    bmFH.bfType = 0x4d42;
    bmFH.bfSize = bmWide * bmHeight + 0x436;
    bmFH.bfReserved1 = 0;
    bmFH.bfReserved2 = 0;
    bmFH.bfOffBits = 0x436;

    bmIH.biSize = 0x28;
    bmIH.biPlanes = 1;
    bmIH.biBitCount = 8;
    bmIH.biCompression = 0;
    bmIH.biSizeImage = 0;
    bmIH.biXPelsPerMeter = 0;
    bmIH.biYPelsPerMeter = 0;
    bmIH.biClrUsed = 0;
    bmIH.biClrImportant = 0;

    *(int*)BMPFile = 0;

    this->GetPalette(thePal + 1);
    for (int i = 0; i < 256; ++i) {
        bmPAL[i + 1].rgbBlue = thePal[i + 1].peBlue;
        bmPAL[i + 1].rgbGreen = thePal[i + 1].peGreen;
        bmPAL[i + 1].rgbRed = thePal[i + 1].peRed;
        bmPAL[i + 1].rgbReserved = 0;
    }

    int tries = 0;
    int file;
    while (1) {
        if (name == 0) {
            sprintf(BMPFile + 4, (char*)0x5845e4, number);
        }
        else {
            sprintf(BMPFile + 4, name, number);
        }

        ++tries;
        file = __open(BMPFile + 4, 0);
        if (file == -1)
            break;

        ++number;
        close(file);
        if (tries > 1000)
            return;
    }

    unsigned char* buffer = (unsigned char*)malloc(bmWide);
    file = __open(BMPFile + 4, 0x8301, 0x180);
    if (file != -1) {
        write(file, &bmFH, 0x0e);
        write(file, &bmIH, 0x28);
        write(file, bmPAL + 1, 0x400);

        if (this->Lock("take_snapshot", 1) != 0) {
            int y = bmHeight - 1;
            while (y >= 0) {
                unsigned char* source = this->CurDisplayOffsets[y];
                int x = 0;
                if (this->Width > 0) {
                    do {
                        buffer[x] = *source;
                        ++x;
                        ++source;
                    } while (x < this->Width);
                }
                write(file, buffer, bmWide);
                --y;
            }
            this->Unlock("take_snapshot");
        }
        close(file);
    }
    free(buffer);
}
