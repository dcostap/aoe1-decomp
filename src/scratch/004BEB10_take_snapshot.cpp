// 004BEB10 TSpan_List_Manager::take_snapshot(char*, int&, TDrawArea*, int, TSpan_List_Manager**, int*, int)
// Source: spanlist.cpp lines 1817-1950
// Attempt log:
// - Initial natural reconstruction from packet/decompiler.
// - First build used bmPAL/thePal as 257-entry arrays because decompiler showed +1 accesses; this made frame 0x890 vs original 0x888.
// - Corrected palette arrays to 256 entries and pass base pointers; frame size now matches original 0x888 and output is same-size 673B.
// - Current best same-size mismatch: positional 75.0371%, edit 58.0981%, first mismatch at offset 16 where original zeroes EBX before pushing EDI, rebuilt pushes EDI and zeroes EDI. Remaining drift is broad register/source-shape through null-span validation, bitmap header stack layout/accesses, palette copy loop, open-name loop, and decode/write loop. Not accepted_drift-safe.

#include <stdio.h>

void* __cdecl malloc(unsigned int size);
void __cdecl free(void* p);
int __cdecl _open(const char* path, int flags, ...);
int __cdecl _close(int fd);
int __cdecl _write(int fd, const void* buf, unsigned int count);

struct PALETTEENTRY { unsigned char peRed, peGreen, peBlue, peFlags; };
struct RGBQUAD { unsigned char rgbBlue, rgbGreen, rgbRed, rgbReserved; };
class TDrawArea { public: void GetPalette(PALETTEENTRY* pal); };

class TSpan_List_Manager {
public:
    char gap0[0x50];
    int Num_Lines;
    int Num_Pixels;
    int DecodeLine(unsigned char* dst, int y, unsigned char color, int infile);
    void take_snapshot(char* name, int& number, TDrawArea* area, int color, TSpan_List_Manager** spans, int* colors, int count);
};

void TSpan_List_Manager::take_snapshot(char* name, int& number, TDrawArea* area, int color, TSpan_List_Manager** spans, int* colors, int count)
{
    int Height;
    int Width;
    int infile;
    int bmWide;
    unsigned char bmFH[0x10];
    unsigned char bmIH[0x28];
    char BMPFile[0x3C];
    RGBQUAD bmPAL[256];
    PALETTEENTRY thePal[256];

    if (count > 0) {
        int i = 0;
        if (count > 0) {
            do {
                if (spans[i] == 0) return;
                i++;
            } while (i < count);
        }
    }

    int pixels = this->Num_Pixels;
    int lines = this->Num_Lines;
    Width = lines;
    unsigned int wide = (pixels + 3) & 0xfffc;
    Height = pixels;
    bmWide = wide;

    *(unsigned short*)(bmFH + 0) = 0x4d42;
    *(unsigned int*)(bmFH + 2) = lines * wide + 0x436;
    *(unsigned short*)(bmFH + 6) = 0;
    *(unsigned short*)(bmFH + 8) = 0;
    *(unsigned int*)(bmFH + 10) = 0x436;

    *(unsigned int*)(bmIH + 0) = 0x28;
    *(unsigned int*)(bmIH + 4) = pixels;
    *(unsigned int*)(bmIH + 8) = lines;
    *(unsigned short*)(bmIH + 12) = 1;
    *(unsigned short*)(bmIH + 14) = 8;
    *(unsigned int*)(bmIH + 16) = 0;
    *(unsigned int*)(bmIH + 20) = 0;
    *(unsigned int*)(bmIH + 24) = 0;
    *(unsigned int*)(bmIH + 28) = 0;
    *(unsigned int*)(bmIH + 32) = 0;
    *(unsigned int*)BMPFile = 0;

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
        if (name == 0) sprintf(BMPFile + 4, (char*)0x5845E4, number);
        else sprintf(BMPFile + 4, name, number);
        tries++;
        int fd = _open(BMPFile + 4, 0);
        if (fd == -1) break;
        number++;
        _close(fd);
        if (tries > 1000) return;
    }

    unsigned char* line = (unsigned char*)malloc(wide);
    infile = _open(BMPFile + 4, 0x8301, 0x180);
    if (infile != -1) {
        _write(infile, bmFH, 0x0e);
        _write(infile, bmIH, 0x28);
        _write(infile, bmPAL, 0x400);
        int y = Width - 1;
        if (y >= 0) {
            do {
                unsigned char* d = line;
                unsigned int c = wide;
                while (c >= 4) { *(unsigned int*)d = 0; d += 4; c -= 4; }
                while (c != 0) { *d++ = 0; c--; }
                this->DecodeLine(line, y, (unsigned char)color, Height);
                if (count > 0) {
                    TSpan_List_Manager** s = spans;
                    int n = count;
                    int delta = (char*)colors - (char*)spans;
                    do {
                        (*s)->DecodeLine(line, y, *(unsigned char*)((char*)s + delta), Height);
                        s++;
                        n--;
                    } while (n != 0);
                }
                _write(infile, line, wide);
                y--;
            } while (y >= 0);
        }
        _close(infile);
    }
    free(line);
}
