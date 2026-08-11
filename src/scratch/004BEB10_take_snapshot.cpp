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
// - Final best check: 661 rebuilt bytes vs 673 original, frame 0x888, all 14
//   calls aligned, 359 strict differing bytes, 85.51% shape, 57.21% exact
//   block coverage. Remaining drift starts in bitmap-header scheduling/stack
//   ownership (notably the BMPFile base is +4) and the late open-loop/return
//   topology. This is unresolved scratch work, not accepted drift.

#include <stdio.h>
#include <string.h>

void* __cdecl malloc(unsigned int size);
void __cdecl free(void* p);
int __cdecl open(const char* path, int flags, ...);
int __cdecl close(int fd);
int __cdecl write(int fd, const void* buf, unsigned int count);

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
    int Width;
    int Height;
    int infile;
    int bmWide;
    unsigned char bmFH[0x10];
    unsigned char bmIH[0x28];
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

    *(unsigned short*)(bmFH + 0) = 0x4d42;
    *(unsigned int*)(bmFH + 2) = Width * bmWide + 0x436;
    *(unsigned short*)(bmFH + 6) = 0;
    *(unsigned short*)(bmFH + 8) = 0;
    *(unsigned int*)(bmFH + 10) = 0x436;

    *(unsigned int*)(bmIH + 0) = 0x28;
    *(unsigned int*)(bmIH + 4) = Height;
    *(unsigned int*)(bmIH + 8) = Width;
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
        int fd = open(BMPFile + 4, 0);
        if (fd == -1) break;
        number++;
        close(fd);
        if (tries <= 1000) continue;
        return;
    }

    unsigned char* line = (unsigned char*)malloc(bmWide);
    infile = open(BMPFile + 4, 0x8301, 0x180);
    if (infile != -1) {
        write(infile, bmFH, 0x0e);
        write(infile, bmIH, 0x28);
        write(infile, bmPAL, 0x400);
        int y = Width - 1;
        if (y >= 0) {
            do {
                memset(line, 0, bmWide);
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
                write(infile, line, bmWide);
                y--;
            } while (y >= 0);
        }
        close(infile);
    }
    free(line);
}
