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
// - Fresh pass: using this->Height for bfSize improved the early liveness
//   basin. Binary pointer evidence then removed decompiler-only +1 palette
//   and +4 filename offsets, improving the result to 326 differing bytes,
//   91.62% shape, and 63.64% exact-block coverage.
// - Tested direct/local product forms, register-qualified height, call
//   placement, and explicit continue-at-limit spelling. They were duplicate
//   or worse. The current typed source keeps the natural zero-based buffers.
// - Best clean reconstruction: exact frame/size/call set, remaining drift is
//   VC5 local/register/block scheduling around the header and early returns;
//   no inline asm or other codegen-only scaffold is retained.
// - Tried named width and height locals for all header and row uses; the
//   natural source changed the frame to 0x880 and lost exact blocks. Rolled
//   back to the prior clean Drawarea form.
// - Fresh claim probes: named-height product/order, register-qualified
//   height/width, delayed rounded-width spill, direct-height header reload,
//   compound total accumulation, and declaration initialization were
//   duplicate or worse. Removing the BMPFile zero also worsened the basin.
//   Keep the clean source; the first paired hunk still needs the original
//   EDI height copy, delayed EDX spill, and header-store schedule.
// - Revisit probes: using bmHeight for the file-size product worsened the
//   result to 496 differing bytes. A bounded while retry changed size and
//   control flow; a do-while form was codegen-duplicate. Restored this clean
//   natural snapshot flow and retained typed CurDisplayOffsets ownership.
// - Accepted drift: GetPalette and all three header writes use identical stack
//   addresses. File calls, retry and number updates, allocation, lock handling,
//   bottom-up rows, uninitialized padding bytes, cleanup, faults, and returns
//   match. Remaining drift is header setup scheduling and retry-tail placement.

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
    bmWide = (bmIH.biWidth + 3) & 0xfffc;

    bmFH.bfType = 0x4d42;
    int total = this->Height * bmWide;
    bmFH.bfSize = total + 0x436;
    bmIH.biHeight = bmHeight;
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

    this->GetPalette(thePal);
    for (int i = 0; i < 256; ++i) {
        bmPAL[i].rgbBlue = thePal[i].peBlue;
        bmPAL[i].rgbGreen = thePal[i].peGreen;
        bmPAL[i].rgbRed = thePal[i].peRed;
        bmPAL[i].rgbReserved = 0;
    }

    int tries = 0;
    int file;
    while (1) {
        if (name == 0) {
            sprintf(BMPFile, (char*)0x5845e4, number);
        }
        else {
            sprintf(BMPFile, name, number);
        }

        ++tries;
        file = __open(BMPFile, 0);
        if (file == -1)
            break;

        ++number;
        close(file);
        if (tries <= 1000)
            continue;
        return;
    }

    unsigned char* buffer = (unsigned char*)malloc(bmWide);
    file = __open(BMPFile, 0x8301, 0x180);
    if (file != -1) {
        write(file, &bmFH, 0x0e);
        write(file, &bmIH, 0x28);
        write(file, bmPAL, 0x400);

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
