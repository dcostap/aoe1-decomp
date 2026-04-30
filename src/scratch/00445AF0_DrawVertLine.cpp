// VA: 00445AF0 TDrawArea::DrawVertLine (143 B)
// PDB source: Drawarea.cpp
// Draws a vertical line clipped to the clip rect

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

    void DrawVertLine(long x, long y, long h, unsigned char color);
};

void TDrawArea::DrawVertLine(long x, long y, long h, unsigned char color)
{
    if (this->Bits == 0)
        return;

    if (x < this->ClipRect.left || x > this->ClipRect.right)
        return;

    if (y > this->ClipRect.bottom)
        return;

    if (y < this->ClipRect.top) {
        h += y - this->ClipRect.top;
        y = this->ClipRect.top;
    }

    if (y + h - 1 > this->ClipRect.bottom) {
        h = this->ClipRect.bottom - y + 1;
    }

    if (h < 1)
        return;

    int pitch;
    unsigned char* dest;
    if (this->Orien == 1) {
        pitch = this->Pitch;
        dest = this->Bits + y * pitch + x;
    } else {
        pitch = this->Pitch;
        dest = this->Bits + (this->Height - y - 1) * pitch + x;
        pitch = -pitch;
    }

    while (h > 0) {
        *dest = color;
        dest += pitch;
        h--;
    }
}
