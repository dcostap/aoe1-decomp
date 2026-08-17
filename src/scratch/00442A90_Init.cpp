// VA: 00442A90 TDrawSystem::Init
// PDB source: Drawarea.cpp lines 621-839
// Attempt log:
// - Replaced the placeholder parameter/offset shim with the period DirectDraw
//   initialization surface, typed local records, and named TDrawSystem fields.
// - Removing the persistent DirectDraw value local fixed the 0x610 frame to 0x60C;
//   a scoped receiver across the cooperative-level branch preserved the original
//   call set and the closest register/liveness basin.
// - Typed DDSURFACEDESC/DDCAPS/palette ownership and the natural palette loops
//   match all calls and CFG; the remaining drift is the entry scheduling and a
//   small receiver/vtable register basin, so this stays in scratch.
// - Early store-order, register-qualified parameter, top-level receiver, and
//   layout probes did not move the first block; the mode-field layout is now
//   named from the generated TDrawSystem dump rather than an anonymous gap.
// - A focused six-way first-store variant lab preserved size/frame/call-set but
//   found no exact prologue. The best clean source remains the typed form.
// - Moving long-lived DirectDraw declarations to function entry was a codegen
//   duplicate; the first-block preload stayed unchanged.
// - Reverse comma-grouping and Wnd/Inst/Pal order probes reached diff 450 but
//   worsened source order or edit shape; both were rolled back.
// - One-line initial stores, combined register hints, and <stdlib.h> context
//   were codegen duplicates. The first paired hunk remains the ABI/liveness
//   frontier.
// - Follow-up claim probes tested parameter qualifier, pointer-local scope,
//   receiver alias scope, handle typedefs, local declaration order, direct
//   out-parameter use, and initial-store permutations.  These kept the 0x60C
//   frame and all 15 ordered calls; none recovered the entry preload.
// - The original palette loop writes Red, Blue, Green, Flags.  Restoring that
//   proven order changed its LEA/store bytes and improved the full result.
// - A 24-variant source lab and a 3072-variant ambient-declaration/context lab
//   found no exact result.  All variants kept size, frame, and call-set gates.
// - The best clean reconstruction is 802 bytes, 15/15 ordered calls, 0x60C
//   frame, 446 differing bytes, and 91.29% shape similarity.  The first
//   mismatch remains the natural entry parameter-load/store schedule.

#include <string.h>
#include <windows.h>
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

struct _DDCAPS {
    unsigned long dwSize;
    unsigned long dwCaps;
    unsigned long dwCaps2;
    unsigned long dwCKeyCaps;
    unsigned long dwFXCaps;
    unsigned long dwFXAlphaCaps;
    unsigned long dwPalCaps;
    unsigned long dwSVCaps;
    unsigned long dwAlphaBltConstBitDepths;
    unsigned long dwAlphaBltPixelBitDepths;
    unsigned long dwAlphaBltSurfaceBitDepths;
    unsigned long dwAlphaOverlayConstBitDepths;
    unsigned long dwAlphaOverlayPixelBitDepths;
    unsigned long dwAlphaOverlaySurfaceBitDepths;
    unsigned long dwZBufferBitDepths;
    unsigned long dwVidMemTotal;
    unsigned long dwVidMemFree;
    unsigned long dwMaxVisibleOverlays;
    unsigned long dwCurrVisibleOverlays;
    unsigned long dwNumFourCCCodes;
    unsigned long dwAlignBoundarySrc;
    unsigned long dwAlignSizeSrc;
    unsigned long dwAlignBoundaryDest;
    unsigned long dwAlignSizeDest;
    unsigned long dwAlignStrideAlign;
    unsigned long dwRops[8];
    _DDSCAPS ddsCaps;
    unsigned long dwMinOverlayStretch;
    unsigned long dwMaxOverlayStretch;
    unsigned long dwMinLiveVideoStretch;
    unsigned long dwMaxLiveVideoStretch;
    unsigned long dwMinHwCodecStretch;
    unsigned long dwMaxHwCodecStretch;
    unsigned long dwReserved1;
    unsigned long dwReserved2;
    unsigned long dwReserved3;
    unsigned long dwSVBCaps;
    unsigned long dwSVBCKeyCaps;
    unsigned long dwSVBFXCaps;
    unsigned long dwSVBRops[8];
    unsigned long dwVSBCaps;
    unsigned long dwVSBCKeyCaps;
    unsigned long dwVSBFXCaps;
    unsigned long dwVSBRops[8];
    unsigned long dwSSBCaps;
    unsigned long dwSSBCKeyCaps;
    unsigned long dwSSBFXCaps;
    unsigned long dwSSBRops[8];
    unsigned long dwReserved4;
    unsigned long dwReserved5;
    unsigned long dwReserved6;
};

class IDirectDrawSurface {
public:
    virtual long __stdcall QueryInterface();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall AddAttachedSurface();
    virtual long __stdcall AddOverlayDirtyRect();
    virtual long __stdcall Blt(void*, void*, void*, unsigned long, _DDBLTFX*);
};

class IDirectDrawPalette {
public:
    virtual long __stdcall QueryInterface();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall GetCaps();
    virtual long __stdcall GetEntries();
    virtual long __stdcall Initialize();
    virtual long __stdcall SetEntries(unsigned long, unsigned long,
                                      unsigned long, tagPALETTEENTRY*);
};

class IDirectDrawClipper {
public:
    virtual long __stdcall QueryInterface();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall GetClipList();
    virtual long __stdcall GetHWnd();
    virtual long __stdcall Initialize();
    virtual long __stdcall IsClipListChanged();
    virtual long __stdcall SetClipList();
    virtual long __stdcall SetHWnd(unsigned long, void*);
};

class IDirectDraw {
public:
    virtual long __stdcall QueryInterface();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall Compact();
    virtual long __stdcall CreateClipper(unsigned long, IDirectDrawClipper**, void*);
    virtual long __stdcall CreatePalette(unsigned long, tagPALETTEENTRY*,
                                         IDirectDrawPalette**, void*);
    virtual long __stdcall CreateSurface();
    virtual long __stdcall DuplicateSurface();
    virtual long __stdcall EnumDisplayModes();
    virtual long __stdcall EnumSurfaces();
    virtual long __stdcall FlipToGDISurface();
    virtual long __stdcall GetCaps(_DDCAPS*, _DDCAPS*);
    virtual long __stdcall GetDisplayMode(_DDSURFACEDESC*);
    virtual long __stdcall GetFourCCCodes();
    virtual long __stdcall GetGDISurface();
    virtual long __stdcall GetMonitorFrequency();
    virtual long __stdcall GetScanLine();
    virtual long __stdcall GetVerticalBlankStatus();
    virtual long __stdcall Initialize();
    virtual long __stdcall RestoreDisplayMode();
    virtual long __stdcall SetCooperativeLevel(void*, unsigned long);
    virtual long __stdcall SetDisplayMode(long, long, long);
};

class TDrawSystem;

class TDrawArea {
public:
    TDrawArea(char*, int);
    int Init(TDrawSystem*, long, long, int, int);
};

extern "C" long __stdcall DirectDrawCreate(void*, IDirectDraw**, void*);
extern "C" __declspec(dllimport) unsigned int __stdcall GetPaletteEntries(
    void*, unsigned int, unsigned int, PALETTEENTRY*);
extern "C" __declspec(dllimport) int __stdcall GetClientRect(void*, RECT*);

class TDrawSystem {
public:
    void* Inst;                          // +0x00
    void* Wnd;                           // +0x04
    void* Pal;                           // +0x08
    TDrawArea* DrawArea;                // +0x0C
    TDrawArea* PrimaryArea;             // +0x10
    void* DrawAreaList;                 // +0x14
    IDirectDraw* DirDraw;               // +0x18
    IDirectDrawSurface* PrimarySurface; // +0x1C
    IDirectDrawClipper* Clipper;        // +0x20
    IDirectDrawPalette* DirDrawPal;     // +0x24
    unsigned long Flags;                // +0x28
    long ScreenWidth;                   // +0x2C
    long ScreenHeight;                  // +0x30
    long ColorBits;                     // +0x34
    long ErrorCode;                     // +0x38
    long ChangedMode;                   // +0x3C
    long IsBanked;                      // +0x40
    long CanSrcBlt;                     // +0x44
    long Restored;                      // +0x48
    long ModeAvail640;                  // +0x4C
    long ModeAvail800;                  // +0x50
    long ModeAvail1024;                 // +0x54
    long ModeAvail1280;                 // +0x58
    long ModeAvail320_200;              // +0x5C
    long ModeAvail320_240;              // +0x60
    long ModeAvail320_200_16;           // +0x64
    long ModeAvail320_240_16;           // +0x68
    long ModeAvail640_16;               // +0x6C
    long ModeAvail800_16;               // +0x70
    long ModeAvail1024_16;              // +0x74
    PALETTEENTRY palette[256];          // +0x78 .. +0x477
    unsigned char DrawType;             // +0x478
    unsigned char ScreenMode;           // +0x479

    void CheckAvailModes(int);
    int CreateSurfaces();
    int Init(void*, void*, void*, unsigned char, unsigned char,
             long, long, unsigned long);
};

int TDrawSystem::Init(void* inst, void* wnd, void* pal,
                      unsigned char draw_type, unsigned char screen_mode,
                      long width, long height, unsigned long flags)
{
    _DDSURFACEDESC ddsd;
    _DDBLTFX ddbltfx;
    _DDCAPS ddcaps;
    PALETTEENTRY color_table[256];
    IDirectDraw** direct_draw;
    IDirectDraw* dd;

    this->Inst = inst;
    this->Pal = pal;
    this->Wnd = wnd;
    this->ScreenMode = screen_mode;
    this->ScreenWidth = width;
    this->DrawType = draw_type;
    this->ScreenHeight = height;
    this->Flags = flags;
    if (draw_type == 1)
        return 0;

    direct_draw = &this->DirDraw;
    if (DirectDrawCreate(0, direct_draw, 0) != 0) {
        this->ErrorCode = 1;
        return 0;
    }

    this->CheckAvailModes(1);
    dd = *direct_draw;
    if (this->ScreenMode == 1) {
        if (dd->SetCooperativeLevel(this->Wnd, 8) != 0) {
            this->ErrorCode = 1;
            return 0;
        }

        memset(&ddsd, 0, 0x6C);
        ddsd.dwSize = 0x6C;
        if ((*direct_draw)->GetDisplayMode(&ddsd) != 0) {
            this->ErrorCode = 1;
            return 0;
        }
        if (ddsd.dwHeight != 8) {
            this->ErrorCode = 2;
            return 0;
        }
    }
    else {
        if (dd->SetCooperativeLevel(this->Wnd, 0x11) != 0) {
            this->ErrorCode = 1;
            return 0;
        }
        this->ColorBits = 8;
        if ((*direct_draw)->SetDisplayMode(this->ScreenWidth, this->ScreenHeight, 8) != 0) {
            this->ErrorCode = 1;
            return 0;
        }
        this->ChangedMode = 1;
    }

    if (this->Pal != 0) {
        GetPaletteEntries(this->Pal, 0, 0x100, color_table);
    }
    else {
        for (int i = 0; i < 0x100; ++i) {
            color_table[i].peRed = 0;
            color_table[i].peGreen = 0;
            color_table[i].peBlue = 0;
            color_table[i].peFlags = 0;
        }
    }

    for (int i = 0; i < 0x100; ++i) {
        this->palette[i].peRed = 0;
        this->palette[i].peBlue = 0;
        this->palette[i].peGreen = 0;
        this->palette[i].peFlags = 0;
    }

    if ((*direct_draw)->CreatePalette(0x44, color_table, &this->DirDrawPal, 0) != 0) {
        this->ErrorCode = 1;
        return 0;
    }
    this->DirDrawPal->SetEntries(0, 0, 0x100, this->palette);

    if ((*direct_draw)->CreateClipper(0, &this->Clipper, 0) != 0) {
        this->ErrorCode = 1;
        return 0;
    }
    if (this->Clipper->SetHWnd(0, this->Wnd) != 0) {
        this->ErrorCode = 1;
        return 0;
    }
    if (this->CreateSurfaces() == 0) {
        this->ErrorCode = 1;
        return 0;
    }

    ddcaps.dwSize = 0x13C;
    this->IsBanked = 0;
    if ((*direct_draw)->GetCaps(&ddcaps, 0) == 0) {
        if ((ddcaps.dwCaps & 0x08000000) != 0)
            this->IsBanked = 1;
        if ((ddcaps.dwCaps & 0x00400000) != 0 &&
            (ddcaps.dwCKeyCaps & 0x200) != 0)
            this->CanSrcBlt = 1;
    }

    if (this->ScreenMode == 2) {
        ddbltfx.dwSize = 0x64;
        ddbltfx.dwFillColor = 0;
        this->PrimarySurface->Blt(0, 0, 0, 0x1000400, &ddbltfx);
    }
    return 1;
}
