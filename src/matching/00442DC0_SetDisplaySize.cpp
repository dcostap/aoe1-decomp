// VA: 00442DC0 TDrawSystem::SetDisplaySize (300 bytes)
// PDB source: Drawarea.cpp, lines 845-906
//
// Attempt log:
// - baseline: replaced the old raw shim with the typed TDrawSystem,
//   DirectDraw, DDBLTFX, and TDrawArea surfaces; behavior was still wrong
//   because the requested dimensions were mistaken for DDBLTFX output fields.
// - behavior: use wid/hgt for the display-mode change; frame and call/CFG
//   structure aligned, leaving a register/lifetime mismatch.
// - variant: the period Win32 MAKELONG(wid,hgt) spelling recovered the
//   original EBX/EDI roles and reduced the drift to three stack-offset bytes.
// - liveness/layout probes for scoped/reordered locals were codegen duplicates.
// - behavior: initialize DDBLTFX.dwSize, pass the complete structure to Blt,
//   and use dwFillColor for the color-fill operation; exact match.
// - Main-agent audit confirmed the non-polymorphic draw-system layout and
//   period DirectDraw/MAKELONG surfaces; emitted code remains exact.

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

class IDirectDrawSurface {
public:
    virtual long __stdcall QueryInterface();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall AddAttachedSurface();
    virtual long __stdcall AddOverlayDirtyRect();
    virtual long __stdcall Blt(
        void* dest_rect, void* src_surface, void* src_rect,
        unsigned long flags, void* fx);
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
    virtual long __stdcall GetDisplayMode();
    virtual long __stdcall GetFourCCCodes();
    virtual long __stdcall GetGDISurface();
    virtual long __stdcall GetMonitorFrequency();
    virtual long __stdcall GetScanLine();
    virtual long __stdcall GetVerticalBlankStatus();
    virtual long __stdcall Initialize();
    virtual long __stdcall RestoreDisplayMode();
    virtual long __stdcall SetCooperativeLevel();
    virtual long __stdcall SetDisplayMode(long width, long height, int bits);
};

class TDrawArea {
public:
    void SetSize(long width, long height, int flags);
};

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
    char gap_28[4];                      // +0x28
    long ScreenWidth;                   // +0x2C
    long ScreenHeight;                  // +0x30
    long ColorBits;                     // +0x34
    char gap_38[4];                      // +0x38
    int ChangedMode;                    // +0x3C
    char gap_40[0x438];                  // +0x40 .. +0x477
    unsigned char DrawType;             // +0x478
    unsigned char ScreenMode;           // +0x479

    int CreateSurfaces();
    int SetDisplaySize(long wid, long hgt, int bits);
};

extern int system_ignore_size_messages;
extern "C" __declspec(dllimport) long __stdcall SendMessageA(
    void* hwnd, unsigned int msg, unsigned int wparam, long lparam);

#define MAKELONG(low, high) \
    ((long)(((unsigned short)(low)) | \
            ((unsigned long)((unsigned short)(high)) << 16)))

int TDrawSystem::SetDisplaySize(long wid, long hgt, int bits)
{
    _DDBLTFX ddbltfx;
    long save_wid;
    long save_hgt;

    if (this->DrawType != 2 || this->ScreenMode != 2)
        return 0;

    system_ignore_size_messages = 1;
    ddbltfx.dwSize = 100;
    ddbltfx.dwFillColor = 0;
    this->PrimarySurface->Blt(0, 0, 0, 0x1000400, &ddbltfx);
    save_wid = this->ScreenWidth;
    save_hgt = this->ScreenHeight;
    this->ScreenWidth = wid;
    this->ScreenHeight = hgt;

    if (this->DirDraw->SetDisplayMode(this->ScreenWidth, this->ScreenHeight, bits) != 0) {
        system_ignore_size_messages = 0;
        this->ScreenWidth = save_wid;
        this->ScreenHeight = save_hgt;
        return 0;
    }

    system_ignore_size_messages = 0;
    this->ColorBits = bits;
    this->ChangedMode = 1;

    if (this->PrimarySurface != 0) {
        this->PrimarySurface->Release();
        this->PrimarySurface = 0;
    }

    this->CreateSurfaces();
    if (this->DrawArea != 0)
        this->DrawArea->SetSize(this->ScreenWidth, this->ScreenHeight, 0);

    SendMessageA(this->Wnd, 5, 0, MAKELONG(wid, hgt));
    return 1;
}
