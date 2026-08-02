// SetAccessOffsets
// VA: 00444990
// Attempt log:
// Baseline reconstruction: natural TDrawArea ownership from Drawarea.cpp and
// the executable offsets; direct CRT allocation and SetFloatOffsets member call.

#include <stdlib.h>

class TDrawArea {
public:
    char gap_00[0x08];
    unsigned char* Bits;          // +0x08
    char gap_0C[0x0C];
    int Width;                    // +0x18
    int Height;                   // +0x1C
    int Pitch;                    // +0x20
    int Orien;                    // +0x24
    char gap_28[0x8C];
    unsigned char* LastBits;      // +0xB4
    char gap_B8[0x04];
    void** DisplayOffsets;        // +0xBC
    void** CurDisplayOffsets;     // +0xC0
    void** FloatOffsets;          // +0xC4
    char gap_C8[0x0C];
    int Float_X_Delta;            // +0xD4
    int Float_Y_Delta;            // +0xD8
    int DisplayOffsetsSz;         // +0xDC
    char gap_E0[0x18];
    void* ExtendedLines;          // +0xF8

    void SetFloatOffsets(int x, int y);
    void SetAccessOffsets();
};

void TDrawArea::SetAccessOffsets()
{
    int size = this->Height << 2;
    if (size != this->DisplayOffsetsSz) {
        if (this->DisplayOffsets != 0)
            free(this->DisplayOffsets);
        this->DisplayOffsets = (void**)malloc(size);
        this->DisplayOffsetsSz = size;
        this->CurDisplayOffsets = this->DisplayOffsets;
    }

    unsigned char* p;
    int delta;
    if (this->Orien == 1 || this->ExtendedLines != 0) {
        if (this->ExtendedLines == 0)
            p = this->Bits;
        else
            p = this->Bits + this->Pitch * 5;

        delta = this->Pitch;
        if (this->ExtendedLines != 0)
            delta = this->Width;
    }
    else {
        p = this->Bits + (this->Height - 1) * this->Pitch;
        delta = -this->Pitch;
    }

    int i = 0;
    if (this->Height > 0) {
        do {
            this->DisplayOffsets[i] = p;
            p += delta;
            ++i;
        } while (i < this->Height);
    }

    if (this->FloatOffsets != 0)
        this->SetFloatOffsets(this->Float_X_Delta, this->Float_Y_Delta);

    this->LastBits = this->Bits;
}
