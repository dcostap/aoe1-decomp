// VA: 00445A60 TDrawArea::DrawHorzLine (135 B)
// PDB source: Drawarea.cpp
// Draws a horizontal line clipped to the clip rect

extern "C" void* __cdecl memset(void* dest, int val, unsigned int count);

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
    char gap_0C[0x10];
    int Height;                // +0x1C
    int Pitch;                 // +0x20
    int Orien;                 // +0x24
    tagRECT ClipRect;          // +0x28

    void DrawHorzLine(long x, long y, long w, unsigned char color);
};

extern void* __cdecl memset2(void*, int, unsigned int);

void TDrawArea::DrawHorzLine(long x, long y, long w, unsigned char color)
{
    if (this->Bits == 0)
        return;

    if (x > this->ClipRect.right)
        return;

    if (y < this->ClipRect.top || y > this->ClipRect.bottom)
        return;

    if (x < this->ClipRect.left) {
        w += x - this->ClipRect.left;
        x = this->ClipRect.left;
    }

    if (x + w - 1 > this->ClipRect.right) {
        w = this->ClipRect.right - x + 1;
    }

    if (w < 1)
        return;

    int offset;
    if (this->Orien == 1)
        offset = this->Pitch * y;
    else
        offset = (this->Height - y - 1) * this->Pitch;

    memset2(this->Bits + offset + x, color, w);
}
