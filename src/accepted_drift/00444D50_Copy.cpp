// VA: 00444D50 TDrawArea::Copy (865 B)
// PDB source: Drawarea.cpp:3021-3220
// Attempt log:
// - Baseline was the generated placeholder (1-byte return, no calls).
// - Reconstructed the period Drawarea.cpp copy surface: the low-memory
//   TransDibBlt/DibBlt arm, the DirectDraw RECT clipping arm, and the two
//   adjacent blit-status dwords at 0062E64C/0062E650.
// - The typed reconstruction reached the correct 0x20 frame, six-call set,
//   and three-return CFG.  Scoped declaration/order and inclusive-RECT probes
//   reproduced the original clipping blocks; sum-left upper-bound spellings
//   leave the best structural build (851 vs. 865 bytes, 91.08% shape).
// - Remaining mismatch is not a call/layout uncertainty: VC5 colors the
//   entry zero/source-top value through EBX instead of the oracle's EBP and
//   emits unresolved global/IAT placeholders in this standalone TU.  Kept the
//   source as ordinary typed Drawarea code rather than retaining register-
//   forcing or unused-local scaffolding.
// - This pass tested top-scope and uninitialized source-y forms, local order,
//   and int-width low-memory locals.  Top-scope forms widened the frame;
//   uninitialized source-y removed the extra xor but worsened the basin.
// - Parenthesized RECT extents, int low-arm locals, and reversed extent
//   operands emitted duplicate code.  The retained forms follow the decompiler
//   arithmetic and period scalar types without codegen steering.
// - This pass initialized source-y before the low-memory RECT split; the
//   first structural hunk moved farther (726 vs. 716 bytes), so it was
//   restored.  A top-scope int source-y matched the earlier 0x24-frame basin
//   (829 bytes) and was also restored.
// - Revisit pass: twenty distinct source hypotheses and two variant labs did
//   not improve the clean basin.  Source-y branch, declaration, and
//   uninitialized forms stayed at 851/853 bytes with the same six calls;
//   32 ambient declaration samples also emitted only the same three groups.
// - RECT aggregate copy, local declaration permutations, explicit unary
//   negatives, truth tests, and branch-scope clip-delta locals all duplicated
//   the clean 851-byte output.  Final validation remains 716 differing bytes,
//   0x20 frame, six ordered calls, and 91.08% shape.
// Accepted-drift review: both low-memory and DirectDraw arms preserve pointer
// checks, all six calls and arguments, inclusive RECT conversion, clipping
// updates, transparent flags, 0062E64C/0062E650 store order, error mapping,
// and returns. Residual drift is the zero register and equivalent integer
// address/subtract lowering for private RECT and extent locals.
// - Fresh context probes: the reviewed full Drawarea declaration surface plus
//   a fallback-first DirectDraw condition reduced the function to 862 bytes
//   and 98.08% shape, with all six calls aligned. The instruction stream still
//   differed at two LEA encodings and two subtraction lowerings; relocation
//   placeholders also remained. Reverted this probe because it was not exact.
// - Final unresolved validation restored the pinned standalone source: 851
//   bytes, 716 differing bytes, 0x20 frame, six ordered calls, and matching
//   owner symbol. DrawShadowBox (00446230) and GetPalette (00446340) stayed
//   exact at 271 and 40 bytes during fresh anchor checks.

#include <ddraw.h>

typedef unsigned char uchar;

struct BITMAPINFO256;
struct TRANSINFO;

extern "C" void __cdecl TransDibBlt(
    BITMAPINFO256*, uchar*, RECT*, long, long, long, long,
    BITMAPINFO256*, uchar*, TRANSINFO*, long, long, long, long,
    int, int, int, int);
extern "C" void __cdecl DibBlt(
    BITMAPINFO256*, uchar*, RECT*, long, long, long, long,
    BITMAPINFO256*, uchar*, long, long, long, long, int, int, int);

extern unsigned int DAT_0062e64c;
extern unsigned int DAT_0062e650;

#ifndef DRAWAREA_CANONICAL_TU
class TDrawSystem {
public:
    char gap_00[0x478];
    unsigned char DrawType;

    int GetBlitErrorNum(long result);
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;             // +0x00
    void* Wnd;                           // +0x04
    uchar* Bits;                         // +0x08
    BITMAPINFO256* BitmapInfo;           // +0x0C
    void* Bitmap;                        // +0x10
    void* OldBitmap;                     // +0x14
    long Width;                          // +0x18
    long Height;                         // +0x1C
    long Pitch;                          // +0x20
    long Orien;                          // +0x24
    tagRECT ClipRect;                    // +0x28
    void* DrawDc;                        // +0x38
    IDirectDrawSurface* DrawSurface;     // +0x3C
    char gap_40[0x90];                   // +0x40 .. +0xCF
    void* CurSpanList;                   // +0xD0
    char gap_D4[0x18];                   // +0xD4 .. +0xEB
    long UseTrans;                       // +0xEC
    char gap_F0[0x0C];                   // +0xF0 .. +0xFB
    uchar TransColor;                    // +0xFC
    char gap_FD[3];

    void Copy(TDrawArea*, long, long, RECT*, int);
};
#endif

void TDrawArea::Copy(TDrawArea* area, long x, long y, RECT* rect,
                     int transparent)
{
    if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 1) {
        if (this->Bits != 0 && area != 0 && area->Bits != 0) {
            int width;
            int height;
            int source_x;
            int source_y;

            if (rect == 0) {
                width = this->Width;
                height = this->Height;
                source_x = 0;
                source_y = 0;
            }
            else {
                source_x = rect->left;
                source_y = rect->top;
                width = rect->right - source_x + 1;
                height = rect->bottom - source_y + 1;
            }

            if (width + source_x > this->Width) {
                width = this->Width - source_x;
            }
            if (height + source_y > this->Height) {
                height = this->Height - source_y;
            }

            if (this->UseTrans != 0 && transparent != 0) {
                TransDibBlt(area->BitmapInfo, area->Bits, &area->ClipRect,
                            x, y, width, height,
                            this->BitmapInfo, this->Bits, 0,
                            source_x, source_y, width, height,
                            1, 0, 0, this->TransColor);
                DAT_0062e650 = 0;
                return;
            }

            DibBlt(area->BitmapInfo, area->Bits, &area->ClipRect,
                   x, y, width, height,
                   this->BitmapInfo, this->Bits,
                   source_x, source_y, width, height, 1, 0, 0);
            DAT_0062e650 = 0;
            return;
        }
    }
    else if (this->DrawSurface != 0 && area != 0 &&
             area->DrawSurface != 0) {
        RECT src_rect2;
        RECT dest_rect2;

        if (rect == 0) {
            src_rect2.left = 0;
            src_rect2.top = 0;
            src_rect2.right = this->Width - 1;
            src_rect2.bottom = this->Height - 1;
        }
        else {
            src_rect2.left = rect->left;
            src_rect2.top = rect->top;
            src_rect2.right = rect->right;
            src_rect2.bottom = rect->bottom;
        }

        ++src_rect2.right;
        ++src_rect2.bottom;

        SetRect(&dest_rect2, x, y,
                (src_rect2.right - src_rect2.left) + x,
                (src_rect2.bottom - src_rect2.top) + y);

        if (src_rect2.left < 0) {
            dest_rect2.left -= src_rect2.left;
            src_rect2.left = 0;
        }
        if (src_rect2.top < 0) {
            dest_rect2.top -= src_rect2.top;
            src_rect2.top = 0;
        }

        if (src_rect2.right > this->Width) {
            long amount = src_rect2.right - this->Width;
            src_rect2.right -= amount;
            dest_rect2.right -= amount;
        }
        if (src_rect2.bottom > this->Height) {
            long amount = src_rect2.bottom - this->Height;
            src_rect2.bottom -= amount;
            dest_rect2.bottom -= amount;
        }

        if (dest_rect2.left < area->ClipRect.left) {
            long amount = area->ClipRect.left - dest_rect2.left;
            dest_rect2.left += amount;
            src_rect2.left += amount;
        }
        if (dest_rect2.top < area->ClipRect.top) {
            long amount = area->ClipRect.top - dest_rect2.top;
            dest_rect2.top += amount;
            src_rect2.top += amount;
        }
        if (dest_rect2.right > area->ClipRect.right + 1) {
            long amount = dest_rect2.right - area->ClipRect.right - 1;
            dest_rect2.right -= amount;
            src_rect2.right -= amount;
        }
        if (dest_rect2.bottom > area->ClipRect.bottom + 1) {
            long amount = dest_rect2.bottom - area->ClipRect.bottom - 1;
            dest_rect2.bottom -= amount;
            src_rect2.bottom -= amount;
        }

        if (dest_rect2.left < dest_rect2.right &&
            dest_rect2.top < dest_rect2.bottom &&
            src_rect2.left < src_rect2.right &&
            src_rect2.top < src_rect2.bottom) {
            DAT_0062e64c = 1;
            if (this->UseTrans != 0 && transparent != 0) {
                DAT_0062e64c = area->DrawSurface->Blt(
                    &dest_rect2, this->DrawSurface, &src_rect2,
                    0x1008000, 0);
            }
            else {
                DAT_0062e64c = area->DrawSurface->Blt(
                    &dest_rect2, this->DrawSurface, &src_rect2,
                    0x1000000, 0);
            }

            DAT_0062e650 = 0;
            if (DAT_0062e64c != 0) {
                DAT_0062e650 = this->DrawSystem->GetBlitErrorNum(
                    DAT_0062e64c);
            }
            if (DAT_0062e650 == 0) {
                DAT_0062e650 = 0;
            }
        }
    }
}
