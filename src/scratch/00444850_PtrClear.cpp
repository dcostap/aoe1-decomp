// VA: 00444850 TDrawArea::PtrClear (308 B)
// PDB source: Drawarea.cpp, lines 2694-2793
//
// Attempt log:
// - The generated placeholder incorrectly described a span-list clear.  The
//   packet proves this is a clipped row clear through CurDisplayOffsets.
// - Baseline typed reconstruction matched the two Lock/Unlock call sites but
//   stayed 35 bytes short with a 0x08 frame; a saved-this/local reorder was a
//   codegen duplicate.
// - Explicit aligned loops reached the 0x14 frame but expanded badly.  A
//   diagnostic volatile row index moved the row reload toward the packet but
//   remained noncanonical and still mismatched; restored to the clean memset
//   source.  Remaining lead: reproduce the original VC5 generic memset
//   expansion and stack/register basin without fake volatility or raw cursors.
// - This session rechecked explicit memset intrinsic context, a void* cast,
//   a frame aggregate, and long coordinate/count locals; all were duplicate
//   or nonproductive. The clean typed memset source is restored.

#include <string.h>

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawSystem {
public:
    char gap_00[0x478];
    unsigned char DrawType; // +0x478
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;       // +0x00
    char gap_04[0x14];             // +0x04 .. +0x17
    int Width;                     // +0x18
    int Height;                    // +0x1C
    char gap_20[0xA0];             // +0x20 .. +0xBF
    void** CurDisplayOffsets;      // +0xC0

    unsigned char* Lock(char* name, int wait_flag);
    void Unlock(char* name);
    void PtrClear(tagRECT* rect, int color);
};

void TDrawArea::PtrClear(tagRECT* rect, int color)
{
    int x1;
    int y1;
    int x2;
    int y2;
    int nLines;
    int nWidth;
    void** src_p;

    if (rect == 0) {
        x2 = this->Width;
        y2 = this->Height;
        x1 = 0;
        y1 = 0;
    }
    else {
        x1 = rect->left;
        y1 = rect->top;
        x2 = rect->right;
        y2 = rect->bottom;
    }

    if (x2 >= 0 && x1 <= x2 && x1 < this->Width &&
        y2 >= 0 && y1 <= y2 && y1 < this->Height) {
        if (x1 < 0)
            x1 = 0;
        if (this->Width <= x2)
            x2 = this->Width - 1;
        if (y1 < 0)
            y1 = 0;
        if (this->Height <= y2)
            y2 = this->Height - 1;

        nLines = y2 - y1 + 1;
        nWidth = x2 - x1 + 1;

        if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 2) {
            if (this->Lock("PtrClear", 1) == 0)
                return;
        }

        src_p = this->CurDisplayOffsets;
        do {
            unsigned char* dst = (unsigned char*)src_p[y1] + x1;
            memset(dst, color, nWidth);
            ++y1;
        } while (--nLines != 0);

        if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 2)
            this->Unlock("PtrClear");
    }
}
