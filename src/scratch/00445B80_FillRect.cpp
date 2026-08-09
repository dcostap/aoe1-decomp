// VA: 00445B80 TDrawArea::FillRect (240 B)
// PDB source: Drawarea.cpp
// Attempt log:
// - The inherited free-function shim had the right size by accident, but its
//   calling convention and memset relocation were wrong.
// - A real TDrawArea member plus the binary-observed C memset call recovered
//   the correct 240-byte size, thiscall cleanup, and one aligned call.
// - Explicit Bits, running-boundary, register-qualified-parameter, pragma-
//   placement, and redundant positive-guard probes were either duplicate or
//   worse. The retained source is the simplest member reconstruction.
// - Remaining drift is broad VC5 this/register coloring and loop setup; no
//   behavior-equivalent promotion is proposed.

extern "C" void* __cdecl memset(void* s, int c, unsigned int n);

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {
public:
    char gap_00[0x08];
    unsigned char* Bits;       // +0x08
    char gap_0C[0x0C];
    long Width;                // +0x18
    long Height;               // +0x1C
    long Pitch;                // +0x20
    long Orien;                // +0x24
    tagRECT ClipRect;          // +0x28

    void FillRect(long x1, long y1, long x2, long y2, unsigned char color);
};

#pragma function(memset)

void TDrawArea::FillRect(long x1, long y1, long x2, long y2,
                         unsigned char color)
{
    unsigned char* bits = this->Bits;
    if (bits == 0)
        return;

    if (x1 > x2) {
        long temp = x1;
        x1 = x2;
        x2 = temp;
    }

    if (y1 > y2) {
        long temp = y1;
        y1 = y2;
        y2 = temp;
    }

    if (x1 > this->ClipRect.right || x2 < this->ClipRect.left ||
        y1 > this->ClipRect.bottom || y2 < this->ClipRect.top)
        return;

    if (x1 < this->ClipRect.left)
        x1 = this->ClipRect.left;
    if (x2 > this->ClipRect.right)
        x2 = this->ClipRect.right;
    if (y1 < this->ClipRect.top)
        y1 = this->ClipRect.top;
    if (y2 > this->ClipRect.bottom)
        y2 = this->ClipRect.bottom;

    long width = x2 - x1 + 1;
    long height = y2 - y1 + 1;
    if (width < 1 || height < 1)
        return;

    unsigned char* p;
    long delta;
    if (this->Orien == 1) {
        delta = this->Pitch;
        p = bits + y1 * delta + x1;
    }
    else {
        p = bits + (this->Height - y1 - 1) * this->Pitch + x1;
        delta = -this->Pitch;
    }

    do {
        memset(p, color, width);
        p += delta;
        --height;
    } while (height != 0);
}
