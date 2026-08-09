// VA: 00442F30 TDrawSystem::CheckSurfaces (318 B)
// PDB source: Drawarea.cpp, lines 927-1012
//
// Attempt log:
// - Replaced the generated surface shim with the period DirectDraw surface
//   status/restore flow and the real 0x6C DDSURFACEDESC plus 0x64 DDBLTFX
//   local records.  First typed reconstruction follows the packet's loop over
//   DrawAreaList and the original COM vtable slots.
// - Removing the persistent primary-surface local restored the exact ESI/EDI
//   register basin and left a single pixel-format displacement mismatch.
// - The binary's +0x60 load is DDSURFACEDESC.ddpfPixelFormat.dwRGBBitCount,
//   not dwFlags.  A direct `return 3` on a child CheckSurface failure preserves
//   the original far failure tail; exact under the default flags.

#include <string.h>
#pragma function(memset)

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

struct DrawAreaNode {
    TDrawArea* DrawArea;
    DrawAreaNode* PrevNode;
    DrawAreaNode* NextNode;
};

class TDrawSystem {
public:
    void* Inst;                         // +0x00
    void* Wnd;                          // +0x04
    void* Pal;                          // +0x08
    TDrawArea* DrawArea;                // +0x0C
    TDrawArea* PrimaryArea;             // +0x10
    DrawAreaNode* DrawAreaList;         // +0x14
    IDirectDraw* DirDraw;               // +0x18
    IDirectDrawSurface* PrimarySurface; // +0x1C
    void* Clipper;                      // +0x20
    void* DirDrawPal;                   // +0x24
    unsigned long Flags;                // +0x28
    int ScreenWidth;                    // +0x2C
    int ScreenHeight;                   // +0x30
    int ColorBits;                      // +0x34
    int ErrorCode;                      // +0x38
    int ChangedMode;                    // +0x3C
    int IsBanked;                       // +0x40
    int CanSrcBlt;                      // +0x44
    int Restored;                       // +0x48
    char gap_4C[0x42C];                 // +0x4C .. +0x477
    unsigned char DrawType;             // +0x478

    int GetIsLostErrorNum(long hr);
    int GetRestoreErrorNum(long hr);
    unsigned char CheckSurfaces();
};

class TDrawArea {
public:
    char gap_00[0x3C];
    IDirectDrawSurface* DrawSurface; // +0x3C

    unsigned char CheckSurface();
};

unsigned char TDrawSystem::CheckSurfaces()
{
    if (this->DrawType != 2)
        return 0;

    if (this->PrimarySurface != 0 && this->DrawArea != 0 &&
        this->DrawArea->DrawSurface != 0) {
        unsigned char result = 0;
        _DDSURFACEDESC ddsd;
        _DDBLTFX ddbltfx;

        long hr = this->PrimarySurface->IsLost();
        if (hr != 0) {
            this->GetIsLostErrorNum(hr);
            memset(&ddsd, 0, sizeof(ddsd));
            ddsd.dwSize = sizeof(ddsd);

            hr = this->DirDraw->GetDisplayMode(&ddsd);
            if (hr == 0 &&
                (ddsd.dwWidth != (unsigned long)this->ScreenWidth ||
                 ddsd.dwHeight != (unsigned long)this->ScreenHeight ||
                 ddsd.ddpfPixelFormat.dwRGBBitCount != 8))
                return 1;

            hr = this->PrimarySurface->Restore();
            if (hr != 0) {
                this->GetRestoreErrorNum(hr);
                return 3;
            }

            this->Restored = 1;
            result = 2;
            ddbltfx.dwSize = sizeof(ddbltfx);
            ddbltfx.dwFillColor = 0;
            this->PrimarySurface->Blt(0, 0, 0, 0x1000400, &ddbltfx);
        }

        DrawAreaNode* node = this->DrawAreaList;
        while (node != 0) {
            if (node->DrawArea != this->PrimaryArea &&
                node->DrawArea->CheckSurface() == 3)
                return 3;
            node = node->NextNode;
        }
        return result;
    }
    return 3;
}
