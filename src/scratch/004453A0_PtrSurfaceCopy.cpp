// 004453A0 TDrawArea::PtrSurfaceCopy
// PDB: Drawarea.cpp:3464-3594, 470 bytes
// Attempt log:
// - v1: reconstructed bounds/locking and row byte-copy logic from packet/decompiler.
// - v2: added /Oy- flag because original has an EBP frame; this improved prologue but broad copy-loop drift remains.
// - v3: replaced the diagnostic scalar alignment loops with the natural typed
//   `memcpy` row operation. This tests whether VC5's library intrinsic emits
//   the original aligned REP family without compiler-steering source. It
//   remained scalar-free but emitted only generic REP MOVSD/MOVSB.
// - v4: restored the natural `memcpy` source after the decompiler-shaped loop
//   emitted scalar code and worsened the frame, CFG, and size.
// - The original CLD, named copy-loop labels, alignment lead calculation, and
//   REP MOVSB/MOVSD phases are a shared hand-shaped copy family with PtrCopy
//   and PtrSpanCopy. Natural VC5 `memcpy` emits generic REP MOVSD/MOVSB, not
//   that alignment topology. Inline asm is forbidden, so this remains scratch
//   with the typed `memcpy` reconstruction as the clean source.

#include <string.h>

typedef unsigned char uchar;
struct tagRECT { long left; long top; long right; long bottom; };

class TDrawSystem { public: char gap[0x478]; unsigned char DrawType; };

class TDrawArea {
public:
    TDrawSystem* DrawSystem;       // +0
    char gap04[0x18 - 0x04];
    int Width;                     // +18
    int Height;                    // +1c
    char gap20[0xc0 - 0x20];
    uchar** CurDisplayOffsets;     // +c0

    uchar* Lock(char* name, int flag);
    void Unlock(char* name);
    void PtrSurfaceCopy(TDrawArea* dst, long xOfD, long yOfD, tagRECT* srcRect, int lockSrc, int lockDst);
};

static char s_lock1[] = "PtrSurfaceCopy1";
static char s_lock2[] = "PtrSurfaceCopy2";

void TDrawArea::PtrSurfaceCopy(TDrawArea* dst, long xOfD, long yOfD, tagRECT* srcRect, int lockSrc, int lockDst)
{
    int nLines;
    int xOfS;
    int nWidth;
    uchar** srcP;
    uchar** destP;

    int left = srcRect->left;
    if (left < 0) return;
    int right = srcRect->right;
    if (left > right) return;
    if (right >= this->Width) return;
    int top = srcRect->top;
    if (top < 0) return;
    int bottom = srcRect->bottom;
    if (top > bottom) return;
    if (bottom >= this->Height) return;

    nLines = bottom - top + 1;
    nWidth = right - left + 1;
    if (xOfD < 0) return;
    if (xOfD >= dst->Width) return;
    if (yOfD < 0) return;
    if (yOfD >= dst->Height) return;

    if (nWidth + xOfD > dst->Width) {
        nWidth = dst->Width - xOfD;
    }
    if (nLines + yOfD > dst->Height) {
        nLines = dst->Height - yOfD;
    }

    if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 2) {
        if (lockSrc != 0) {
            if (this->Lock(s_lock1, 1) == 0) return;
        }
        if (lockDst != 0) {
            if (dst->Lock(s_lock2, 1) == 0) {
                if (lockSrc == 0) return;
                this->Unlock(s_lock1);
                return;
            }
        }
    }

    srcP = this->CurDisplayOffsets;
    xOfS = srcRect->left;
    top = srcRect->top;
    destP = dst->CurDisplayOffsets;
    do {
        uchar* src = srcP[top] + xOfS;
        uchar* dest = destP[yOfD] + xOfD;
        memcpy(dest, src, nWidth);
        top++;
        yOfD++;
        nLines--;
    } while (nLines != 0);

    if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 2) {
        if (lockSrc != 0) this->Unlock(s_lock1);
        if (lockDst != 0) dst->Unlock(s_lock2);
    }
}
