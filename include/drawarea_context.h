#ifndef AOE1_DRAWAREA_CONTEXT_H
#define AOE1_DRAWAREA_CONTEXT_H

// Canonical Drawarea.cpp surface for the ordered early owners.
// PDB layout proves TDrawSystem size 0x47C and TDrawArea method ownership.
// Keep this header free of SDK includes. The period source used only the
// records and COM slots declared below for these owners.

typedef unsigned char uchar;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};
typedef tagRECT RECT;

struct tagPALETTEENTRY {
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};
typedef tagPALETTEENTRY PALETTEENTRY;

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

typedef _DDSURFACEDESC DDSURFACEDESC;

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

class IDirectDrawPalette {
public:
    virtual long __stdcall QueryInterface();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall GetCaps();
    virtual long __stdcall GetEntries();
    virtual long __stdcall Initialize();
    virtual long __stdcall SetEntries(unsigned long, unsigned long,
                                      unsigned long, PALETTEENTRY*);
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
    virtual long __stdcall CreatePalette(unsigned long, PALETTEENTRY*,
                                         IDirectDrawPalette**, void*);
    virtual long __stdcall CreateSurface();
    virtual long __stdcall DuplicateSurface();
    virtual long __stdcall EnumDisplayModes(unsigned long, _DDSURFACEDESC*,
                                            void*, void*);
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
class BITMAPINFO256;
class TDrawArea;
class RGE_Color_Table;
class TSpan_List_Manager;

struct DrawAreaNode {
    TDrawArea* DrawArea;
    DrawAreaNode* PrevNode;
    DrawAreaNode* NextNode;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;              // +0x00
    void* Wnd;                            // +0x04
    unsigned char* Bits;                  // +0x08
    BITMAPINFO256* BitmapInfo;            // +0x0C
    void* Bitmap;                         // +0x10
    void* OldBitmap;                      // +0x14
    int Width;                            // +0x18
    int Height;                           // +0x1C
    int Pitch;                            // +0x20
    int Orien;                            // +0x24
    tagRECT ClipRect;                    // +0x28
    void* DrawDc;                         // +0x38
    IDirectDrawSurface* DrawSurface;     // +0x3C
    _DDSURFACEDESC SurfaceDesc;         // +0x40
    DrawAreaNode* Node;                   // +0xAC
    char* Name;                           // +0xB0
    unsigned char* LastBits;              // +0xB4
    int LastPitch;                        // +0xB8
    void** DisplayOffsets;                // +0xBC
    void** CurDisplayOffsets;             // +0xC0
    void** FloatOffsets;                  // +0xC4
    RGE_Color_Table* shadow_color_table;  // +0xC8
    TSpan_List_Manager* SpanList;         // +0xCC
    TSpan_List_Manager* CurSpanList;      // +0xD0
    int Float_X_Delta;                    // +0xD4
    int Float_Y_Delta;                    // +0xD8
    int DisplayOffsetsSz;                 // +0xDC
    int FloatOffsetsSz;                   // +0xE0
    int SystemMemOnly;                    // +0xE4
    int UsingVidMem;                      // +0xE8
    int UseTrans;                         // +0xEC
    int IsPrimarySurface;                 // +0xF0
    int Restored;                         // +0xF4
    int ExtendedLines;                    // +0xF8
    unsigned char TransColor;             // +0xFC
    unsigned char _pad_end[3];

    TDrawArea(char*, int);
    ~TDrawArea();
    int Init(class TDrawSystem*, long, long, int, int);
    void SetSize(long, long, int);
    unsigned char CheckSurface();
};

extern "C" long __stdcall DirectDrawCreate(void*, IDirectDraw**, void*);

class TDrawSystem {
public:
    void* Inst;                          // +0x00
    void* Wnd;                           // +0x04
    void* Pal;                           // +0x08
    TDrawArea* DrawArea;                 // +0x0C
    TDrawArea* PrimaryArea;              // +0x10
    DrawAreaNode* DrawAreaList;           // +0x14
    IDirectDraw* DirDraw;                // +0x18
    IDirectDrawSurface* PrimarySurface;  // +0x1C
    IDirectDrawClipper* Clipper;         // +0x20
    IDirectDrawPalette* DirDrawPal;      // +0x24
    unsigned long Flags;                 // +0x28
    long ScreenWidth;                    // +0x2C
    long ScreenHeight;                   // +0x30
    long ColorBits;                      // +0x34
    long ErrorCode;                      // +0x38
    long ChangedMode;                    // +0x3C
    long IsBanked;                       // +0x40
    long CanSrcBlt;                      // +0x44
    long Restored;                       // +0x48
    long ModeAvail640;                   // +0x4C
    long ModeAvail800;                   // +0x50
    long ModeAvail1024;                  // +0x54
    long ModeAvail1280;                  // +0x58
    long ModeAvail320_200;               // +0x5C
    long ModeAvail320_240;               // +0x60
    long ModeAvail320_200_16;            // +0x64
    long ModeAvail320_240_16;            // +0x68
    long ModeAvail640_16;                // +0x6C
    long ModeAvail800_16;                // +0x70
    long ModeAvail1024_16;               // +0x74
    PALETTEENTRY palette[256];           // +0x78
    unsigned char DrawType;              // +0x478
    unsigned char ScreenMode;            // +0x479

    TDrawSystem();
    ~TDrawSystem();
    static long __stdcall CheckAvailModesCallback(_DDSURFACEDESC*, void*);
    void CheckAvailModes(int);
    int IsModeAvail(long, long, int);
    int Init(void*, void*, void*, unsigned char, unsigned char, long, long,
             unsigned long);
    int SetDisplaySize(long, long, int);
    void ClearPrimarySurface();
    void DeleteSurfaces();
    int CreateSurfaces();
    int GetIsLostErrorNum(long);
    int GetRestoreErrorNum(long);
    unsigned char CheckSurfaces();
    void ClearRestored();
};

#endif
