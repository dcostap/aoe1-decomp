// 004453A0 TDrawArea::PtrSurfaceCopy
// PDB: Drawarea.cpp:3464-3594, 470 bytes
// Attempt log:
// - v1: reconstructed bounds/locking and row byte-copy logic from packet/decompiler.
// - v2: added /Oy- flag because original has an EBP frame; this improved prologue but broad copy-loop drift remains.
// BLOCKER: behavior, bounds checks, lock/unlock calls, and dimensions are understood, but source copy loop does not lower to the original hand-shaped REP MOVSB/MOVSD sequence. Rebuilt uses scalar byte/dword loops even with /Oy-, and local/register layout differs (0x0c frame vs original 0x14, different parameter/local reuse). Need source/topology or intrinsic/context that makes VC5 emit the exact alignment check + `rep movsb; rep movsd; rep movsb` sequence without inline asm.

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
        int count = nWidth;
        if ((((int)src ^ (int)dest) & 3) == 0) {
            int lead = (-(int)dest) & 3;
            int main = count - lead;
            if (main > 0) {
                while (lead != 0) { *dest++ = *src++; lead--; }
                count = main;
                int dwords = count >> 2;
                while (dwords != 0) { *(int*)dest = *(int*)src; dest += 4; src += 4; dwords--; }
                count &= 3;
            }
            while (count != 0) { *dest++ = *src++; count--; }
        } else {
            while (count != 0) { *dest++ = *src++; count--; }
        }
        top++;
        yOfD++;
        nLines--;
    } while (nLines != 0);

    if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 2) {
        if (lockSrc != 0) this->Unlock(s_lock1);
        if (lockDst != 0) dst->Unlock(s_lock2);
    }
}
