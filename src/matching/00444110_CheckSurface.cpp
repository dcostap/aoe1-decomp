// VA: 00444110 TDrawArea::CheckSurface (338 B)
// PDB source: Drawarea.cpp, lines 1880-1949
//
// Attempt log:
// - Replaced the generated surface shim with the period DirectDraw status,
//   restore/recreate, and clear flow.  The first reconstruction uses typed
//   0x6C DDSURFACEDESC/0x64 DDBLTFX records and SDK-shaped COM slots.
// - The restore-error branch must be positive (`if (hr != 0)`) so the clear/
//   Blt path remains the late fallthrough.  Typed dwRGBBitCount and the two
//   HRESULT-specific release/recreate cases then match exactly under default
//   flags.

#include <string.h>
#pragma function(memset)

#ifndef DRAWAREA_CANONICAL_TU
struct _DDCOLORKEY {
    unsigned long dwColorSpaceLowValue;
    unsigned long dwColorSpaceHighValue;
};

struct _DDPIXELFORMAT {
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwFourCC;
    unsigned long dwRGBBitCount;
    unsigned long dwRBitMask;
    unsigned long dwGBitMask;
    unsigned long dwBBitMask;
    unsigned long dwRGBAlphaBitMask;
};

struct _DDSCAPS {
    unsigned long dwCaps;
};

struct _DDSURFACEDESC {
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwHeight;
    unsigned long dwWidth;
    long lPitch;
    unsigned long dwBackBufferCount;
    unsigned long dwMipMapCount;
    unsigned long dwAlphaBitDepth;
    unsigned long dwReserved;
    void* lpSurface;
    _DDCOLORKEY ddckCKDestOverlay;
    _DDCOLORKEY ddckCKDestBlt;
    _DDCOLORKEY ddckCKSrcOverlay;
    _DDCOLORKEY ddckCKSrcBlt;
    _DDPIXELFORMAT ddpfPixelFormat;
    _DDSCAPS ddsCaps;
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

class IDirectDrawSurface {
public:
    virtual long __stdcall QueryInterface();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall AddAttachedSurface();
    virtual long __stdcall AddOverlayDirtyRect();
    virtual long __stdcall Blt(void*, IDirectDrawSurface*, void*,
                               unsigned long, _DDBLTFX*);
    virtual long __stdcall BltBatch();
    virtual long __stdcall BltFast();
    virtual long __stdcall DeleteAttachedSurface();
    virtual long __stdcall EnumAttachedSurfaces();
    virtual long __stdcall EnumOverlayZOrders();
    virtual long __stdcall Flip();
    virtual long __stdcall GetAttachedSurface();
    virtual long __stdcall GetBltStatus();
    virtual long __stdcall GetCaps();
    virtual long __stdcall GetClipper();
    virtual long __stdcall GetColorKey();
    virtual long __stdcall GetDC();
    virtual long __stdcall GetFlipStatus();
    virtual long __stdcall GetOverlayPosition();
    virtual long __stdcall GetPalette();
    virtual long __stdcall GetPixelFormat();
    virtual long __stdcall GetSurfaceDesc();
    virtual long __stdcall Initialize();
    virtual long __stdcall IsLost();
    virtual long __stdcall Lock();
    virtual long __stdcall ReleaseDC();
    virtual long __stdcall Restore();
    virtual long __stdcall SetClipper();
    virtual long __stdcall SetColorKey();
    virtual long __stdcall SetOverlayPosition();
    virtual long __stdcall SetPalette();
    virtual long __stdcall Unlock();
};

class IDirectDraw {
public:
    virtual long __stdcall QueryInterface();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall Compact();
    virtual long __stdcall CreateClipper();
    virtual long __stdcall CreatePalette();
    virtual long __stdcall CreateSurface();
    virtual long __stdcall DuplicateSurface();
    virtual long __stdcall EnumDisplayModes();
    virtual long __stdcall EnumSurfaces();
    virtual long __stdcall FlipToGDISurface();
    virtual long __stdcall GetCaps();
    virtual long __stdcall GetDisplayMode(_DDSURFACEDESC*);
    virtual long __stdcall GetFourCCCodes();
    virtual long __stdcall GetGDISurface();
    virtual long __stdcall GetMonitorFrequency();
    virtual long __stdcall GetScanLine();
    virtual long __stdcall GetVerticalBlankStatus();
    virtual long __stdcall Initialize();
    virtual long __stdcall RestoreDisplayMode();
    virtual long __stdcall SetCooperativeLevel();
    virtual long __stdcall SetDisplayMode();
};

class TDrawArea;

class TDrawSystem {
public:
    void* Inst;                         // +0x00
    void* Wnd;                          // +0x04
    void* Pal;                          // +0x08
    TDrawArea* DrawArea;                // +0x0C
    TDrawArea* PrimaryArea;             // +0x10
    void* DrawAreaList;                 // +0x14
    IDirectDraw* DirDraw;               // +0x18
    IDirectDrawSurface* PrimarySurface; // +0x1C
    void* Clipper;                      // +0x20
    void* DirDrawPal;                   // +0x24
    unsigned long Flags;                // +0x28
    int ScreenWidth;                    // +0x2C
    int ScreenHeight;                   // +0x30
    int ColorBits;                      // +0x34
    int ErrorCode;                      // +0x38
    char gap_3C[0x43C];                 // +0x3C .. +0x477
    unsigned char DrawType;             // +0x478

    int GetIsLostErrorNum(long hr);
    int GetRestoreErrorNum(long hr);
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;    // +0x00
    char gap_04[0x14];          // +0x04 .. +0x17
    int Width;                  // +0x18
    int Height;                 // +0x1C
    char gap_20[0x1C];          // +0x20 .. +0x3B
    IDirectDrawSurface* DrawSurface; // +0x3C
    char gap_40[0xB4];           // +0x40 .. +0xF3
    int Restored;                // +0xF4

    void SetSize(long width, long height, int flags);
    unsigned char CheckSurface();
};
#endif

unsigned char TDrawArea::CheckSurface()
{
    if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 2) {
        if (this->DrawSurface == 0)
            return 3;

        long hr = this->DrawSurface->IsLost();
        if (hr != 0) {
            this->DrawSystem->GetIsLostErrorNum(hr);

            _DDSURFACEDESC ddsd;
            _DDBLTFX ddbltfx;
            memset(&ddsd, 0, sizeof(ddsd));
            ddsd.dwSize = sizeof(ddsd);

            hr = this->DrawSystem->DirDraw->GetDisplayMode(&ddsd);
            if (hr == 0 &&
                (ddsd.dwWidth != (unsigned long)this->DrawSystem->ScreenWidth ||
                 ddsd.dwHeight != (unsigned long)this->DrawSystem->ScreenHeight ||
                 ddsd.ddpfPixelFormat.dwRGBBitCount != 8))
                return 1;

            hr = this->DrawSurface->Restore();
            if (hr != 0) {
                if (hr == (long)0x8876024B || hr == (long)0x8007000E) {
                    this->DrawSurface->Release();
                    this->DrawSurface = 0;
                    this->SetSize(this->Width, this->Height, 0);
                    if (this->DrawSurface != 0)
                        return 2;
                }

                this->DrawSystem->GetRestoreErrorNum(hr);
                return 3;
            }

            ddbltfx.dwSize = sizeof(ddbltfx);
            ddbltfx.dwFillColor = 0;
            this->DrawSurface->Blt(0, 0, 0, 0x1000400, &ddbltfx);
            this->Restored = 1;
            return 2;
        }
    }
    return 0;
}
