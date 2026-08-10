// 004430F0 TDrawSystem::CreateSurfaces
// Attempt log:
// FLAGS: config/flags/004430F0_CreateSurfaces.rsp uses /GX; original has VC5 EH frame around TDrawArea construction.
// try 1: natural DirectDraw/TDrawArea reconstruction with EH new areas, DDSURFACEDESC/DDBLTFX locals.
// try 2: default flags probe compiled only 560B and lacked EH frame; restored /GX.
// try 3: modeled DDSURFACEDESC 0x6c memset and DirectDraw::CreateSurface call at vt+0x18.
// try 4: modeled BackBuffer pointer at +0x1c via &this->BackBuffer for CreateSurface out-param.
// try 5: modeled fullscreen clear Blt with DDBLTFX size 0x64/fill 0 and flags 0x1000400.
// try 6: modeled bpp==8 SetPalette at surface vt+0x7c and SetClipper vt+0x70.
// try 7: modeled PrimaryArea allocation/ctor string and EH state 0; calls recognizable but compiler saves EBP unlike original.
// try 8: modeled DrawArea allocation/ctor string and EH state 1; late block recognizable with same high-level call sequence.
// try 9: GetClientRect imported as function pointer to match indirect IAT call; window RECT local offsets still drift.
// final: corrected the DirectDrawSurface COM slot prefix, restored the real
// PrimarySurface +0x1C ownership and +0x28 gap, modeled DDSURFACEDESC flags/caps,
// and used the five-argument TDrawArea::Init ABI; exact under /GX and default
// source layout.

#include <string.h>
#pragma function(memset)
extern void* __cdecl operator new(unsigned int);

struct RECT { long left, top, right, bottom; };
extern "C" int (__stdcall* const GetClientRect)(void*, RECT*);

struct DDCOLORKEY {
    unsigned long dwColorSpaceLowValue;
    unsigned long dwColorSpaceHighValue;
};

struct DDPIXELFORMAT {
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwFourCC;
    unsigned long dwRGBBitCount;
    unsigned long dwRBitMask;
    unsigned long dwGBitMask;
    unsigned long dwBBitMask;
    unsigned long dwRGBAlphaBitMask;
};

struct DDSCAPS {
    unsigned long dwCaps;
};

struct DDSURFACEDESC {
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
    DDCOLORKEY ddckCKDestOverlay;
    DDCOLORKEY ddckCKDestBlt;
    DDCOLORKEY ddckCKSrcOverlay;
    DDCOLORKEY ddckCKSrcBlt;
    DDPIXELFORMAT ddpfPixelFormat;
    DDSCAPS ddsCaps;
};
struct DDBLTFX {
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
    DDCOLORKEY ddckDestColorkey;
    DDCOLORKEY ddckSrcColorkey;
};

class IDirectDrawSurface {
public:
    virtual long __stdcall QueryInterface();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall AddAttachedSurface();
    virtual long __stdcall AddOverlayDirtyRect();
    virtual long __stdcall Blt(void*, IDirectDrawSurface*, void*, unsigned long, DDBLTFX*);
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
    virtual long __stdcall SetClipper(void*);
    virtual long __stdcall SetColorKey();
    virtual long __stdcall SetOverlayPosition();
    virtual long __stdcall SetPalette(void*);
};

class IDirectDraw {
public:
    virtual long __stdcall QueryInterface();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall Compact();
    virtual long __stdcall CreateClipper();
    virtual long __stdcall CreatePalette();
    virtual long __stdcall CreateSurface(DDSURFACEDESC*, IDirectDrawSurface**, void*);
};

class TDrawSystem;
class DrawAreaNode;
class IDirectDrawSurface;
class TSpan_List_Manager;

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    void* Wnd;
    unsigned char* Bits;
    void* BitmapInfo;
    void* Bitmap;
    void* OldBitmap;
    int Width;
    int Height;
    int Pitch;
    int Orien;
    int ClipLeft;
    int ClipTop;
    int ClipRight;
    int ClipBottom;
    void* DrawDc;
    IDirectDrawSurface* DrawSurface;
    char SurfaceDesc[0x6C];
    DrawAreaNode* Node;
    char* Name;
    unsigned char* LastBits;
    int LastPitch;
    void** DisplayOffsets;
    void** CurDisplayOffsets;
    void** FloatOffsets;
    void* shadow_color_table;
    TSpan_List_Manager* SpanList;
    TSpan_List_Manager* CurSpanList;
    int Float_X_Delta;
    int Float_Y_Delta;
    int DisplayOffsetsSz;
    int FloatOffsetsSz;
    int SystemMemOnly;
    int UsingVidMem;
    int UseTrans;
    int IsPrimarySurface;
    int Restored;
    int ExtendedLines;
    unsigned char TransColor;
    unsigned char gap_FD[3];

    TDrawArea(char*, int);
    int Init(TDrawSystem*, long, long, int, int);
};

class TDrawSystem {
public:
    void* Inst;
    void* Wnd;
    void* Pal;
    TDrawArea* DrawArea;
    TDrawArea* PrimaryArea;
    char gap14[4];
    IDirectDraw* DirDraw;
    IDirectDrawSurface* PrimarySurface;
    void* Clipper;
    void* DirDrawPal;
    char gap28[4];
    long Width;
    long Height;
    long Bpp;
    char gap38[0x478-0x38];
    unsigned char DrawType;
    unsigned char ScreenMode;

    int CreateSurfaces();
};

int TDrawSystem::CreateSurfaces()
{
    DDSURFACEDESC ddsd;
    DDBLTFX ddbltfx;
    RECT wnd_rect;

    if (this->DrawType == 2) {
        if (this->PrimarySurface == 0) {
            memset(&ddsd, 0, 0x6c);
            ddsd.dwSize = 0x6c;
            ddsd.dwFlags = 1;
            ddsd.ddsCaps.dwCaps = 0x200;
            if (this->DirDraw->CreateSurface(&ddsd, &this->PrimarySurface, 0)) return 0;
            if (this->ScreenMode == 2) {
                ddbltfx.dwSize = 0x64;
                ddbltfx.dwFillColor = 0;
                this->PrimarySurface->Blt(0, 0, 0, 0x1000400, &ddbltfx);
            }
            if (this->Bpp == 8) {
                if (this->PrimarySurface->SetPalette(this->DirDrawPal)) return 0;
            }
            if (this->PrimarySurface->SetClipper(this->Clipper)) return 0;
        }
        if (this->PrimaryArea == 0) {
            TDrawArea* area = new TDrawArea("Primary Area", 0);
            this->PrimaryArea = area;
            if (area == 0) return 0;
            if (this->ScreenMode == 1) {
                GetClientRect(this->Wnd, &wnd_rect);
                if (!this->PrimaryArea->Init(this, wnd_rect.right, wnd_rect.bottom, 0, 1)) return 0;
            } else {
                if (!area->Init(this, this->Width, this->Height, 0, 1)) return 0;
            }
        }
    }
    if (this->DrawArea == 0) {
        TDrawArea* area2 = new TDrawArea("Draw Area", 0);
        this->DrawArea = area2;
        if (area2 == 0) return 0;
        if (this->ScreenMode == 1) {
            GetClientRect(this->Wnd, &wnd_rect);
            if (!this->DrawArea->Init(this, wnd_rect.right, wnd_rect.bottom, 0, 0)) return 0;
        } else {
            if (!area2->Init(this, this->Width, this->Height, 0, 0)) return 0;
        }
    }
    return 1;
}
