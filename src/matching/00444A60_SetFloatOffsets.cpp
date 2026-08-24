// SetFloatOffsets
// VA: 00444A60
// Attempt log:
// Probe 1 existing raw __fastcall got prologue but loop optimized to pointer/countdown and broad tail drift.
// Probe 2 typed member natural indexed loop.
#include <stdlib.h>

#ifndef DRAWAREA_CANONICAL_TU
class TDrawArea {
public:
    char gap_00[0x1C];
    int Height;                 // +1C
    char gap_20[0x9C];
    int* DisplayOffsets;        // +BC
    int* CurDisplayOffsets;     // +C0
    int* FloatOffsets;          // +C4
    char gap_C8[0x0C];
    int Float_X_Delta;          // +D4
    int Float_Y_Delta;          // +D8
    char gap_DC[0x04];
    int FloatOffsetsSz;         // +E0
    char gap_E4[0x14];
    void* ExtendedLines;        // +F8

    void SetFloatOffsets(int x, int y);
};
#endif

void TDrawArea::SetFloatOffsets(int x, int y)
{
    int size = this->Height << 2;
    if (size != 0 && this->ExtendedLines != 0 && x >= 0 && y >= 0) {
        if (size != this->FloatOffsetsSz) {
            if (this->FloatOffsets != 0)
                free(this->FloatOffsets);
            this->FloatOffsets = (void**)malloc(size);
            this->FloatOffsetsSz = size;
        }

        int out = 0;
        int cur = y;
        if (this->Height > 0) {
            do {
                this->FloatOffsets[out] =
                    (void*)((unsigned char*)this->DisplayOffsets[cur] + x);
                cur++;
                if (cur >= this->Height)
                    cur = 0;
                out++;
            } while (out < this->Height);
        }
        this->Float_X_Delta = x;
        this->Float_Y_Delta = y;
        this->CurDisplayOffsets = this->FloatOffsets;
    }
}
