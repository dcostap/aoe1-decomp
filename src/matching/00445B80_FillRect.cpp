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
// - This session tested direct Bits access, pragma removal, full 0x100-byte
//   layout, positive outer guard, pointer-at-join versus branch-local pointer,
//   redundant height guard, running right/bottom locals, and declaration scope.
//   The pointer-at-join form reached 224 bytes/168 differing bytes but has less
//   plausible source topology than the retained branch-local form.
// - This session rechecked an early-return Bits guard, a tagRECT ClipRect
//   aggregate, a captured Bits pointer, and unqualified member spelling;
//   each emitted the same 240-byte/218-difference result. The clean member
//   reconstruction is restored below.
// - This session tested the binary-indicated post-orientation height guard;
//   it moved the prologue into alignment only with an offset-at-join pointer
//   but produced 248 bytes/205 differing bytes. The guard was restored away.
// - The offset-at-join pointer without that guard reproduced the prior best
//   224-byte/168-difference basin, but retained branch-local pointer source is
//   the more plausible Drawarea reconstruction.
// - Fresh pass: the exact Drawarea stdlib/string header context, scalar clip
//   fields, top-declared row locals, and branch-local direct-Pitch pointer
//   shape reduced the clean candidate to 43 differing bytes (240 bytes,
//   94.79% shape, 80.21% exact-block coverage).
// - Explicit clipped-left reuse through x1 worsened the result to 109 bytes;
//   reversing local declaration order was codegen-duplicate. A redundant
//   post-orientation height guard produced a 243-byte function/114-byte diff;
//   it was removed. Best clean source remains the 43-byte candidate.
// - The prior clean candidate's remaining hunk was the width/height
//   register-home split at 00445C04 plus the post-orientation height-test
//   block; it was resolved by the natural top-tested loop below.
// - Final exact probe: a natural top-tested while (height > 0), rather than an
//   explicit if plus do/while, reproduced the post-orientation height guard,
//   width/height stack-home coloring, and loop schedule at 240 exact bytes.
// Main-agent integration restored the canonical tagRECT ClipRect ownership;
// the ordinary clipped row fill remains authoritative.

#include <stdlib.h>
#include <string.h>

extern "C" void* __cdecl memset(void* s, int c, unsigned int n);

#pragma function(memset)

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {
public:
    void* DrawSystem;             // +0x00
    void* Wnd;                    // +0x04
    unsigned char* Bits;          // +0x08
    void* BitmapInfo;             // +0x0C
    void* Bitmap;                 // +0x10
    void* OldBitmap;              // +0x14
    int Width;                    // +0x18
    int Height;                   // +0x1C
    int Pitch;                    // +0x20
    int Orien;                    // +0x24
    tagRECT ClipRect;             // +0x28
    void* DrawDc;                 // +0x38
    void* DrawSurface;            // +0x3C
    char SurfaceDesc[0x6C];       // +0x40..+0xAB
    void* Node;                   // +0xAC
    char* Name;                   // +0xB0
    unsigned char* LastBits;      // +0xB4
    int LastPitch;                // +0xB8
    void** DisplayOffsets;        // +0xBC
    void** CurDisplayOffsets;     // +0xC0
    void** FloatOffsets;          // +0xC4
    void* shadow_color_table;     // +0xC8
    void* SpanList;               // +0xCC
    void* CurSpanList;            // +0xD0
    int Float_X_Delta;            // +0xD4
    int Float_Y_Delta;            // +0xD8
    int DisplayOffsetsSz;         // +0xDC
    int FloatOffsetsSz;           // +0xE0
    int SystemMemOnly;            // +0xE4
    int UsingVidMem;              // +0xE8
    int UseTrans;                 // +0xEC
    int IsPrimarySurface;         // +0xF0
    int Restored;                 // +0xF4
    int ExtendedLines;            // +0xF8
    unsigned char TransColor;     // +0xFC
    unsigned char gap_FD[3];      // +0xFD

    void FillRect(long x1, long y1, long x2, long y2, unsigned char color);
};

void TDrawArea::FillRect(long x1, long y1, long x2, long y2,
                         unsigned char color)
{
    long width;
    long height;
    long delta;
    unsigned char* p;

    if (this->Bits != 0) {
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

        width = x2 - x1 + 1;
        height = y2 - y1 + 1;
        if (width < 1 || height < 1)
            return;

        if (this->Orien == 1) {
            p = this->Bits + (y1 * this->Pitch + x1);
            delta = this->Pitch;
        } else {
            p = this->Bits + ((this->Height - y1 - 1) * this->Pitch + x1);
            delta = -this->Pitch;
        }

        while (height > 0) {
            memset(p, color, width);
            p += delta;
            --height;
        }
    }
}
