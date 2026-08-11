// VA: 004443D0 TDrawArea::SetSize (675 B)
// PDB source: Drawarea.cpp, lines 2374-2577
// Attempt log:
// - Replaced the old raw scaffold with the period Drawarea.cpp ownership
//   surface: nested DirectDraw guards, typed DDSURFACEDESC/DDBLTFX locals,
//   real surface methods, and the TSpan_List_Manager lifetime/loop.
// - baseline/default flags: natural source compiled without the required EH
//   registration (607 B, 0xD0 frame); calls and loop topology were present.
// - flags probe: donor-backed /GX restored the original FS exception frame and
//   constructor EH state (667 B, 0xD4 frame).
// - control-flow probe: keeping a typed outer DrawSystem pointer while using a
//   fresh inner member guard preserved the binary's redundant null test; exact
//   675-byte match.
// FLAGS: config/flags/004443D0_SetSize.rsp uses /GX; original has EH state for
// the TSpan_List_Manager allocation/constructor.

#include <string.h>
#pragma function(memset)

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

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

struct BitmapInfoHeader {
    unsigned long biSize;
    long biWidth;
    long biHeight;
};

struct BitmapInfo {
    BitmapInfoHeader bmiHeader;
};

class IDirectDrawSurface {
public:
    virtual long __stdcall QueryInterface();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall AddAttachedSurface();
    virtual long __stdcall AddOverlayDirtyRect();
    virtual long __stdcall Blt(void*, IDirectDrawSurface*, void*,
                               unsigned long, DDBLTFX*);
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
    virtual long __stdcall GetSurfaceDesc(DDSURFACEDESC*);
};

class IDirectDraw {
public:
    virtual long __stdcall QueryInterface();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall Compact();
    virtual long __stdcall CreateClipper();
    virtual long __stdcall CreatePalette();
    virtual long __stdcall CreateSurface(DDSURFACEDESC*,
                                         IDirectDrawSurface**, void*);
};

class TDrawArea;
class TSpan_List_Manager;

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
    char gap_2C[0x44C];                 // +0x2C .. +0x477
    unsigned char DrawType;             // +0x478

    int GetCreateErrorNum(long hr);
};

class TSpan_List_Manager {
public:
    char gap_00[0x68];

    TSpan_List_Manager(int, int);
    ~TSpan_List_Manager();
    void AddSpan(int, int, int);
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;             // +0x00
    void* Wnd;                           // +0x04
    unsigned char* Bits;                 // +0x08
    BitmapInfo* BitmapInfo;             // +0x0C
    void* Bitmap;                        // +0x10
    void* OldBitmap;                     // +0x14
    long Width;                          // +0x18
    long Height;                         // +0x1C
    long Pitch;                          // +0x20
    long Orien;                          // +0x24
    tagRECT ClipRect;                    // +0x28
    void* DrawDc;                        // +0x38
    IDirectDrawSurface* DrawSurface;     // +0x3C
    DDSURFACEDESC SurfaceDesc;           // +0x40
    void* Node;                           // +0xAC
    char* Name;                           // +0xB0
    unsigned char* LastBits;             // +0xB4
    long LastPitch;                      // +0xB8
    void** DisplayOffsets;               // +0xBC
    void** CurDisplayOffsets;            // +0xC0
    void** FloatOffsets;                 // +0xC4
    void* shadow_color_table;             // +0xC8
    TSpan_List_Manager* SpanList;        // +0xCC
    TSpan_List_Manager* CurSpanList;     // +0xD0
    long Float_X_Delta;                  // +0xD4
    long Float_Y_Delta;                  // +0xD8
    long DisplayOffsetsSz;               // +0xDC
    long FloatOffsetsSz;                 // +0xE0
    long SystemMemOnly;                  // +0xE4
    long UsingVidMem;                    // +0xE8
    long UseTrans;                       // +0xEC
    long IsPrimarySurface;               // +0xF0
    long Restored;                       // +0xF4
    long ExtendedLines;                  // +0xF8
    unsigned char TransColor;            // +0xFC
    unsigned char gap_FD[3];

    void SetInfo();
    void SetAccessOffsets();
    void SetClipRect(tagRECT*);
    void Clear(tagRECT*, int);
    void SetSize(long width, long height, int flags);
};

void TDrawArea::SetSize(long width, long height, int flags)
{
    DDSURFACEDESC ddsd;
    DDBLTFX ddbltfx;
    TDrawSystem* draw_system = this->DrawSystem;

    if (draw_system != 0 && draw_system->DrawType != 1) {
        if (this->DrawSystem != 0 && this->DrawSystem->DirDraw != 0 &&
            width != 0 && height != 0 &&
            (width != this->Width || height != this->Height ||
             this->DrawSurface == 0)) {
            if (width < 1) {
                width = 1;
            }
            if (height < 1) {
                height = 1;
            }

            long surface_height = height + 10;
            if (flags == 0) {
                surface_height = height;
            }

            this->ExtendedLines = flags;
            this->BitmapInfo->bmiHeader.biWidth = width;
            if (this->Orien == 1) {
                this->BitmapInfo->bmiHeader.biHeight = -surface_height;
            }
            else {
                this->BitmapInfo->bmiHeader.biHeight = surface_height;
            }
            this->Width = width;
            this->Height = height;

            if (this->IsPrimarySurface == 0) {
                if (this->DrawSurface != 0) {
                    this->DrawSurface->Release();
                    this->DrawSurface = 0;
                    memset(&this->SurfaceDesc, 0, 0x6C);
                    this->Pitch = 0;
                    this->UsingVidMem = 0;
                }

                memset(&ddsd, 0, 0x6C);
                ddsd.dwSize = 0x6C;
                ddsd.dwFlags = 7;
                if ((this->DrawSystem->Flags & 1) != 0 ||
                    flags != 0 || this->SystemMemOnly != 0) {
                    ddsd.ddsCaps.dwCaps = 0x840;
                }
                else {
                    ddsd.ddsCaps.dwCaps = 0x40;
                }
                ddsd.dwHeight = surface_height;
                ddsd.dwWidth = this->Width;

                if (this->DrawSystem->DirDraw->CreateSurface(
                        &ddsd, &this->DrawSurface, 0) == 0) {
                    this->SurfaceDesc.dwSize = 0x6C;
                    long hr = this->DrawSurface->GetSurfaceDesc(
                        &this->SurfaceDesc);
                    if (hr == 0) {
                        this->SetInfo();
                        this->SetAccessOffsets();
                        ddbltfx.dwSize = 0x64;
                        ddbltfx.dwFillColor = 0;
                        this->DrawSurface->Blt(0, 0, 0, 0x1000400,
                                               &ddbltfx);
                    }
                    else {
                        this->DrawSystem->GetCreateErrorNum(hr);
                    }
                }
            }
            else {
                this->DrawSurface = this->DrawSystem->PrimarySurface;
            }

            this->SetClipRect(0);
            this->Clear(0, 0);
        }
    }

    if (this->SpanList != 0) {
        delete this->SpanList;
    }

    this->SpanList = new TSpan_List_Manager(width, height);
    int i = 0;
    if (height > 0) {
        do {
            this->SpanList->AddSpan(0, width - 1, i);
            ++i;
        } while (i < height);
    }
    this->CurSpanList = this->SpanList;
}
