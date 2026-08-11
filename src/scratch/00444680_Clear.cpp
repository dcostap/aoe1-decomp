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
    tagRECT dest;
    _DDBLTFX ddbltfx;

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
                dest.left = x2 - x1 + 1;

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
                    y2 = y2 - y1 + 1;
                    do {
                        memset(p, color, dest.left);
                        p += step;
                        --y2;
                    } while (y2 != 0);
                }
            }
        }
    }
    else {
        IDirectDrawSurface* surface = this->DrawSurface;

        if (surface != 0) {
            ddbltfx.dwDDFX = 100;
            ddbltfx.ddckDestColorkey.dwColorSpaceLowValue = color;

            if (rect == 0) {
                surface->Blt(0, 0, 0, 0x1000400, &ddbltfx.dwDDFX);
                return;
            }

            dest.top = rect->left;
            dest.right = rect->top;
            dest.bottom = rect->right + 1;
            ddbltfx.dwSize = rect->bottom + 1;
            surface->Blt(&dest.top, 0, 0, 0x1000400, &ddbltfx.dwDDFX);
        }
    }
}
