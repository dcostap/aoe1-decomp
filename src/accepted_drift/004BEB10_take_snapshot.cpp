// 004BEB10 TSpan_List_Manager::take_snapshot(char*, int&, TDrawArea*, int, TSpan_List_Manager**, int*, int)
// Source: spanlist.cpp lines 1817-1950
// Attempt log:
// - Initial natural reconstruction used 256-entry palette arrays; the original
//   addresses confirm no extra palette entry is part of this frame.
// - Restored the original direct open/close/write call surfaces and changed the
//   span precheck to a pointer cursor with a redundant i<count guard. This
//   makes the complete call multiset/order and the first 0x38 bytes exact.
// - Replaced hand-written zero loops with memset(line, 0, bmWide), matching the
//   observed variable-size rep stosd/rep stosb sequence and recovering exact
//   palette/zero/decode/write islands.
// - Width-first member initialization is the current best header basin; a
//   typed packed bitmap-header probe moved the header broadly and was rolled
//   back. The inverted attempt-limit spelling was codegen-identical.
// - Reordered the natural BMP file-size assignment before bfType, as shown by
//   the first paired hunk and the spanlist source order; codegen was identical.
// - Final best check: 661 rebuilt bytes vs 673 original, frame 0x888, all 14
//   calls aligned, 359 strict differing bytes, 85.51% shape, 57.21% exact
//   block coverage. Remaining drift starts in bitmap-header scheduling/stack
//   ownership (notably the BMPFile base is +4) and the late open-loop/return
//   topology. This is unresolved scratch work, not accepted drift.
// - Fresh probe: using BMPFile itself for the filename calls moved the pointer
//   to the observed stack address, improving the result to 356 differing
//   bytes, 87.44% shape, and 74.63% exact-block coverage. The packed file
//   header, product operand order, direct Num_Lines product, and a named total
//   were duplicate codegen or did not improve this basin.
// - A bounded filename-search loop reproduced the original jle backedge and
//   near-size, but introduced an extra fd test and broad register drift; it
//   was rolled back. The remaining structural lead is the early header local
//   reuse and the original fallthrough return topology.
// - Restored named bitmap-header fields, the default file-name literal, and
//   parallel spans/colors indexing. Raw stack-buffer stores and cross-array
//   cursor arithmetic were diagnostic scaffolding, not living source.
// - Revisit: removing the untyped BMPFile zero store from the typed source
//   resynchronized the exact palette/open/body islands. Best result is 666
//   bytes, frame 0x888, 202 instructions, 351 strict differing bytes, and
//   91.09% shape. The original final zero is a bitmap-header field, not a
//   filename initialization.
// - Tested 257-entry palettes, a 0x40-byte filename buffer, +1 palette
//   anchors, SDK Windows headers, declaration and field order, named totals,
//   retry-loop forms, and CRT C linkage. No exact result; several were
//   duplicate codegen. The current source keeps the typed period model and
//   extern-C CRT declarations.
// - Accepted drift: all 14 calls and all writable header, palette, filename,
//   and scanline addresses match. Header values, retry limit, file-number
//   updates, row order, decode overlays, writes, cleanup, failures, and returns
//   match. Remaining drift is private header-store scheduling and equivalent
//   retry-tail placement.

#include <stdio.h>
#include <string.h>

extern "C" void* __cdecl malloc(unsigned int size);
extern "C" void __cdecl free(void* p);
extern "C" int __cdecl open(const char* path, int flags, ...);
extern "C" int __cdecl close(int fd);
extern "C" int __cdecl write(int fd, const void* buf, unsigned int count);

#ifndef SPANLIST_SHARED_CONTEXT
struct PALETTEENTRY { unsigned char peRed, peGreen, peBlue, peFlags; };
struct RGBQUAD { unsigned char rgbBlue, rgbGreen, rgbRed, rgbReserved; };
#pragma pack(push, 2)
struct BITMAPFILEHEADER {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
};
#pragma pack(pop)
struct BITMAPINFOHEADER {
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
};
class TDrawArea { public: void GetPalette(PALETTEENTRY* pal); };

class TSpan_List_Manager {
public:
    char gap0[0x50];
    int Num_Lines;
    int Num_Pixels;
    int DecodeLine(unsigned char* dst, int y, unsigned char color, int infile);
    void take_snapshot(char* name, int& number, TDrawArea* area, int color, TSpan_List_Manager** spans, int* colors, int count);
};
#endif

static const char s_default_snapshot_name[] = "C:\\AOE_%03d.BMP";

void TSpan_List_Manager::take_snapshot(char* name, int& number, TDrawArea* area, int color, TSpan_List_Manager** spans, int* colors, int count)
{
    int Width;
    int Height;
    int infile;
    int bmWide;
    BITMAPFILEHEADER bmFH;
    BITMAPINFOHEADER bmIH;
    char BMPFile[0x3C];
    RGBQUAD bmPAL[256];
    PALETTEENTRY thePal[256];

    if (count > 0) {
        int i = 0;
        if (i < count) {
            TSpan_List_Manager** s = spans;
            while (i < count) {
                if (*s == 0) return;
                i++;
                s++;
            }
        }
    }

    Width = this->Num_Lines;
    Height = this->Num_Pixels;
    bmWide = (Height + 3) & 0xfffc;

    bmFH.bfSize = Width * bmWide + 0x436;
    bmFH.bfType = 0x4d42;
    bmFH.bfReserved1 = 0;
    bmFH.bfReserved2 = 0;
    bmFH.bfOffBits = 0x436;

    bmIH.biSize = 0x28;
    bmIH.biWidth = Height;
    bmIH.biHeight = Width;
    bmIH.biPlanes = 1;
    bmIH.biBitCount = 8;
    bmIH.biCompression = 0;
    bmIH.biSizeImage = 0;
    bmIH.biXPelsPerMeter = 0;
    bmIH.biYPelsPerMeter = 0;
    bmIH.biClrUsed = 0;
    bmIH.biClrImportant = 0;
    area->GetPalette(thePal);
    for (int p = 0; p < 0x100; ++p) {
        bmPAL[p].rgbBlue = thePal[p].peBlue;
        bmPAL[p].rgbGreen = thePal[p].peGreen;
        bmPAL[p].rgbRed = thePal[p].peRed;
        bmPAL[p].rgbReserved = 0;
    }

    int tries = 0;
    if (number < 0) number = 0;
    while (1) {
        if (name == 0) sprintf(BMPFile, s_default_snapshot_name, number);
        else sprintf(BMPFile, name, number);
        tries++;
        int fd = open(BMPFile, 0);
        if (fd == -1) break;
        number++;
        close(fd);
        if (tries <= 1000) continue;
        return;
    }

    unsigned char* line = (unsigned char*)malloc(bmWide);
    infile = open(BMPFile, 0x8301, 0x180);
    if (infile != -1) {
        write(infile, &bmFH, 0x0e);
        write(infile, &bmIH, sizeof(bmIH));
        write(infile, bmPAL, 0x400);
        int y = Width - 1;
        if (y >= 0) {
            do {
                memset(line, 0, bmWide);
                this->DecodeLine(line, y, (unsigned char)color, Height);
                if (count > 0) {
                    int i;
                    for (i = 0; i < count; ++i)
                        spans[i]->DecodeLine(line, y,
                            (unsigned char)colors[i], Height);
                }
                write(infile, line, bmWide);
                y--;
            } while (y >= 0);
        }
        close(infile);
    }
    free(line);
}
