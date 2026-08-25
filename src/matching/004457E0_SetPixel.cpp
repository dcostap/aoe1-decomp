// first pass: direct clip check and direct pixel store in the packet's orientation order
// if this is sticky, the remaining gap should be only VC5 code-shape around the branch split or address math
#include "..\..\include\game_types.h"

#ifndef DRAWAREA_CANONICAL_TU
class TDrawSystem;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    void* Wnd;
    unsigned char* Bits;
    void* BitmapInfo;
    void* Bitmap;
    void* OldBitmap;
    long Width;
    long Height;
    long Pitch;
    long Orien;
    tagRECT ClipRect;

    void SetPixel(long x, long y, unsigned char color);
};
#endif

void TDrawArea::SetPixel(long x, long y, unsigned char color) {
    if (Bits == 0) {
        return;
    }

    if (x < ClipRect.left || x > ClipRect.right) {
        return;
    }

    if (y < ClipRect.top || y > ClipRect.bottom) {
        return;
    }

    if (Orien == 1) {
        Bits[Pitch * y + x] = color;
    }
    else {
        Bits[((Height - y) - 1) * Pitch + x] = color;
    }
}
