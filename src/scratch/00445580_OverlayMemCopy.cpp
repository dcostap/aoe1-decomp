// VA: 00445580 TDrawArea::OverlayMemCopy (385 B)
// PDB source: Drawarea.cpp
//
// LEFT IN SCRATCH: ~78-91% mismatch after 15 attempts.
//
// Summary of attempts:
// 1-5: Various natural C++ forms with clean locals. Frame 14h vs 18h, no rep movsd.
// 6-8: Parameter slot reuse via casts. Frame smaller, wrong slot reuse pattern.
// 9:   Fixed backward DstXStart (srcRect.right -> dstRect.right). Still ~78%.
// 10-11: memcpy approach. Forward path got rep movsd (memcpy intrinsic), backward manual.
// 12-13: Indexed access variants. Frame got worse (8h).
// 14-15: Combined memcpy forward + manual backward. ~91% diff.
//
// Remaining issues:
// - Frame: 0x08-0x14 vs required 0x18 (VC5 allocates fewer locals/uses more registers)
// - Forward copy: memcpy generates alignment-handling code (shr ecx,2; rep movsd; and ecx,3).
//   Original uses plain rep movsd without alignment check.
// - Backward copy: manual dword loop instead of STD+rep movsd (can't get VC5 to emit STD)
// - Parameter slot reuse: original puts step in [ebp+8] (srcRect slot), srcRow in [ebp+0Ch]
//   (dstRect slot), dstRow in [ebp+18h] (xAdd slot), CurDisplayOffsets in [ebp+14h] (yOff slot).
//   Our VC5 version chooses different slot reuse pattern despite same source structure.
// - Register allocation: original saves/preserves ebx/esi/edi for tight copy loop body.
//   Our VC5 version uses different registers without the extra save/restore.
// - Lock/Unlock call pattern matches, string "OverlayMemCopy" matches.
// - Control flow logic (direction setup, early-out, Lock/Unlock guards) is correct.
//
// Custom flag: /Oy- (needed for EBP frame; default /Oy omits it).

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
    unsigned char DrawType;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    char gap_04[0x04];
    unsigned char* Bits;
    char gap_0C[0x2C];
    void* DrawDc;
    void* DrawSurface;
    char gap_40[0x7C];
    void** DisplayOffsets;           // +0xBC
    void** CurDisplayOffsets;        // +0xC0

    unsigned char* Lock(char* name, int waitFlag);
    void Unlock(char* name);
    void OverlayMemCopy(tagRECT& srcRect, tagRECT& dstRect, int xOff, int yOff, int xAdd, int yAdd);
};

void TDrawArea::OverlayMemCopy(
    tagRECT& srcRect,
    tagRECT& dstRect,
    int xOff,
    int yOff,
    int xAdd,
    int yAdd)
{
    if (xOff == 0 && yOff == 0)
        return;

    if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 2) {
        if (this->Lock("OverlayMemCopy", 1) == 0)
            return;
    }

    int lines = srcRect.bottom - srcRect.top + 1;
    int srcXStart = srcRect.left + xAdd;
    int tmp = srcRect.right - srcRect.left + 4;
    int lineLen = tmp >> 2;
    int dstXStart = dstRect.left + xAdd;
    int backCopy = 0;

    if (yOff < 0) {
        xAdd = -1;
        xOff = srcRect.bottom + yAdd;
        yAdd = dstRect.bottom + yAdd;
    } else if (yOff > 0) {
        xAdd = 1;
        xOff = srcRect.top + yAdd;
        yAdd = dstRect.top + yAdd;
    } else {
        xAdd = 1;
        xOff = srcRect.top + yAdd;
        yAdd = dstRect.top + yAdd;
        if (xOff < 0) {
            backCopy = 1;
            srcXStart = xAdd + srcRect.right - 3;
            dstXStart = dstRect.right + xAdd - 3;
        }
    }

    if (backCopy) {
        do {
            int n = lineLen;
            int* s = (int*)((char*)this->CurDisplayOffsets[xOff] + srcXStart);
            int* d = (int*)((char*)this->CurDisplayOffsets[yAdd] + dstXStart);
            do {
                *d-- = *s--;
            } while (--n != 0);
            xOff += xAdd;
            yAdd += xAdd;
        } while (--lines != 0);
    } else {
        do {
            memcpy((char*)this->CurDisplayOffsets[yAdd] + dstXStart,
                   (char*)this->CurDisplayOffsets[xOff] + srcXStart,
                   lineLen * 4);
            xOff += xAdd;
            yAdd += xAdd;
        } while (--lines != 0);
    }

    if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 2) {
        this->Unlock("OverlayMemCopy");
    }
}
