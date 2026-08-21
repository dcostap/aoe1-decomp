// VA: 00444680 TDrawArea::Clear (458 B)
// PDB source: Drawarea.cpp, lines 2583-2687
// Attempt log:
// - Replaced the generated fill-only shim with the binary-supported Clear
//   member: PtrClear fallback, software row fill, and DirectDraw Blt fallback.
// - The local RECT/DDBLTFX surfaces and Drawarea.cpp layout are reconstructed
//   from the original stack homes and the exact same-TU donors.
// - Final bounded probe: spell upper clipping as coordinate >= dimension,
//   matching the oracle's coordinate-left compare direction instead of the
//   algebraically equivalent member-left form.
// - The ten-probe pass rejected separate stride/offset and RECT-field locals,
//   hoisted or separate width homes, long-vs-int changes, and extra CRT header
//   context; those either duplicated or expanded the frame.  The retained
//   natural source is 465 bytes with all five calls and the 0x78 frame aligned;
//   remaining drift begins in coordinate register/lifetime coloring.
// - Replaced the software reuse of dest.left with block-local width and row
//   count values, while retaining the late top <= bottom guard.  This moved
//   the best check to 439 bytes, 217 differing bytes, and 85.39% shape; the
//   DirectDraw temporary homes still shift, so the target remains unresolved.
// - Rejected right > left / bottom > top guard spelling: it matched the
//   compare direction locally but expanded the frame to 0x7C and worsened the
//   result to 469 bytes and 335 differing bytes. The clean guard stays.
// - Fresh structural pass: moving coordinate and pixel declarations, hoisting
//   the pixel pointer, and modeling function-scope wid did not change codegen.
//   Early-negative and nested guard forms repeated the 469-byte basin.
// - Direct pointer arithmetic before step assignment expanded to 472 bytes.
//   Reusing dest.left for width reached 459 bytes but worsened the diff to 317.
//   The clean block-local width source remains the best reconstruction.
// - Fresh worker pass: the clean source remains 439 bytes with the correct
//   0x78 frame, five ordered calls, and a 217-byte positional diff.  The first
//   mismatch is the equivalent clipped-region guard's compare direction.
// - Tested direct pointer arithmetic, function-scope declaration orders,
//   Ghidra-indicated coordinate declaration order, branch-local DirectDraw
//   records, and a typed width/RECT union.  These duplicated the clean basin
//   or worsened frame, size, and register coloring.  No variant was retained.
// - The remaining DirectDraw homes need a source-supported explanation for
//   the contiguous stack overlay at [esp+10h..24h]; do not use a metric-only
//   union or shifted interior structure pointers as a replacement.
// - Revisit probes: a negated nonpositive clip guard repeated the 469-byte,
//   0x7C-frame basin; reversing the temporary declaration order duplicated
//   the clean 439-byte result; a proven three-field destination record reduced
//   the frame to 0x74 and worsened the diff to 225 bytes.  All were rejected.
// - Accepted drift: canonical branch-local RECT and DDBLTFX objects recover
//   the executable's exact writable stack addresses. All five calls receive
//   equivalent arguments. Clip reads, bounds, orientation, row count, pointer
//   steps, fill state, and returns match. The executable's late y1 <= y2 test
//   is redundant after its earlier y1 < y2 guard. Remaining drift is private
//   register and block lowering.

#include <string.h>

extern int DDSys_CanColorFill;
extern "C" void* __cdecl memset(void* s, int c, unsigned int n);

#pragma function(memset)

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

struct _DDCOLORKEY {
    unsigned long dwColorSpaceLowValue;
    unsigned long dwColorSpaceHighValue;
};

struct _DDBLTFX {
    unsigned long dwSize;
    unsigned long dwDDFX;
    unsigned long dwROP;
    unsigned long dwDDROP;
    unsigned long dwRotationAngle;
    unsigned long dwZBufferOpCode;
    unsigned long dwZBufferLow;
    unsigned long dwZBufferHigh;
    unsigned long dwZBufferBaseDest;
    unsigned long dwZDestConstBitDepth;
    unsigned long dwZDestConst;
    unsigned long dwZSrcConstBitDepth;
    unsigned long dwZSrcConst;
    unsigned long dwAlphaEdgeBlendBitDepth;
    unsigned long dwAlphaEdgeBlend;
    unsigned long dwReserved;
    unsigned long dwAlphaDestConstBitDepth;
    unsigned long dwAlphaDestConst;
    unsigned long dwAlphaSrcConstBitDepth;
    unsigned long dwAlphaSrcConst;
    unsigned long dwFillColor;
    _DDCOLORKEY ddckDestColorkey;
    _DDCOLORKEY ddckSrcColorkey;
};

class TDrawSystem {
public:
    char gap_00[0x478];
    unsigned char DrawType;                 // +0x478
};

class IDirectDrawSurface {
public:
    virtual long __stdcall QueryInterface();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall AddAttachedSurface();
    virtual long __stdcall AddOverlayDirtyRect();
    virtual long __stdcall Blt(void*, void*, void*, unsigned long, void*);
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;                // +0x00
    void* Wnd;                              // +0x04
    unsigned char* Bits;                    // +0x08
    void* BitmapInfo;                       // +0x0C
    void* Bitmap;                           // +0x10
    void* OldBitmap;                        // +0x14
    int Width;                              // +0x18
    int Height;                             // +0x1C
    int Pitch;                              // +0x20
    int Orien;                              // +0x24
    tagRECT ClipRect;                       // +0x28
    void* DrawDc;                           // +0x38
    IDirectDrawSurface* DrawSurface;        // +0x3C
    char SurfaceDesc[0x6C];                 // +0x40..+0xAB
    void* Node;                             // +0xAC
    char* Name;                             // +0xB0
    unsigned char* LastBits;                // +0xB4
    int LastPitch;                          // +0xB8
    void** DisplayOffsets;                  // +0xBC
    void** CurDisplayOffsets;               // +0xC0
    void** FloatOffsets;                    // +0xC4
    void* shadow_color_table;               // +0xC8
    void* SpanList;                         // +0xCC
    void* CurSpanList;                      // +0xD0
    int Float_X_Delta;                      // +0xD4
    int Float_Y_Delta;                      // +0xD8
    int DisplayOffsetsSz;                   // +0xDC
    int FloatOffsetsSz;                     // +0xE0
    int SystemMemOnly;                      // +0xE4
    int UsingVidMem;                        // +0xE8
    int UseTrans;                           // +0xEC
    int IsPrimarySurface;                   // +0xF0
    int Restored;                           // +0xF4
    int ExtendedLines;                      // +0xF8
    unsigned char TransColor;               // +0xFC
    unsigned char gap_FD[3];

    void PtrClear(tagRECT* rect, int color);
    void Clear(tagRECT* rect, int color);
};

void TDrawArea::Clear(tagRECT* rect, int color)
{
    if (DDSys_CanColorFill == 0) {
        this->PtrClear(rect, color);
        return;
    }

    if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 1) {
        unsigned char* p = this->Bits;

        if (p != 0) {
            if (rect == 0) {
                memset(p, color, this->Height * this->Pitch);
                return;
            }

            int x1 = rect->left;
            int y1 = rect->top;
            int x2 = rect->right;
            int y2 = rect->bottom;

            if (x1 < 0) {
                x1 = 0;
            }
            else if (x1 >= this->Width) {
                x1 = this->Width - 1;
            }

            if (y1 < 0) {
                y1 = 0;
            }
            else if (y1 >= this->Height) {
                y1 = this->Height - 1;
            }

            if (x2 < 0) {
                x2 = 0;
            }
            else if (x2 >= this->Width) {
                x2 = this->Width - 1;
            }

            if (y2 < 0) {
                y2 = 0;
            }
            else if (y2 >= this->Height) {
                y2 = this->Height - 1;
            }

            if (x1 < x2 && y1 < y2) {
                int width = x2 - x1 + 1;

                int step;
                int offset;
                if (this->Orien == 1) {
                    step = this->Pitch;
                    offset = y1 * step;
                }
                else {
                    offset = (this->Height - y1 - 1) * this->Pitch;
                    step = -this->Pitch;
                }

                p = p + offset + x1;

                if (y1 <= y2) {
                    int rows = y2 - y1 + 1;
                    do {
                        memset(p, color, width);
                        p += step;
                        --rows;
                    } while (rows != 0);
                }
            }
        }
    }
    else {
        tagRECT dest;
        _DDBLTFX ddbltfx;
        IDirectDrawSurface* surface = this->DrawSurface;

        if (surface != 0) {
            ddbltfx.dwSize = sizeof(ddbltfx);
            ddbltfx.dwFillColor = color;

            if (rect == 0) {
                surface->Blt(0, 0, 0, 0x1000400, &ddbltfx);
                return;
            }

            dest.left = rect->left;
            dest.top = rect->top;
            dest.right = rect->right + 1;
            dest.bottom = rect->bottom + 1;
            surface->Blt(&dest, 0, 0, 0x1000400, &ddbltfx);
        }
    }
}
