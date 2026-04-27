// first pass: direct clip check and direct pixel store in the packet's orientation order
// if this is sticky, the remaining gap should be only VC5 code-shape around the branch split or address math
#include "..\..\include\game_types.h"

class TDrawArea {
public:
    void* vtable_ptr;
    char pad_04[0x4];
    unsigned char* Bits;
    char pad_0C[0x10];
    long Height;
    long Pitch;
    long Orien;
    long left;
    long top;
    long right;
    long bottom;

    void SetPixel(long x, long y, unsigned char color);
};

void TDrawArea::SetPixel(long x, long y, unsigned char color) {
    if (Bits == 0) {
        return;
    }

    if (x < left || x > right) {
        return;
    }

    if (y < top || y > bottom) {
        return;
    }

    if (Orien == 1) {
        Bits[Pitch * y + x] = color;
    }
    else {
        Bits[((Height - y) - 1) * Pitch + x] = color;
    }
}
