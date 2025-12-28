#pragma once
#include <windows.h>
#include <ddraw.h>

// Forward declarations
class TDrawSystem;
class TSpan_List_Manager;
class RGE_Color_Table;
struct DrawAreaNode; 

typedef unsigned char uchar;

struct BITMAPINFO256 {
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD          bmiColors[256];
};

class TDrawArea {
public:
    TDrawArea(const char *name, int system_mem);
    ~TDrawArea();

    int Init(TDrawSystem *draw_system, long width, long height, int using_vid_mem, int is_primary_surface);
    void SetSize(long width, long height, int extended_lines);
    void Clear(RECT *rect, int color);
    void SetClipRect(RECT *rect);
    void SetClipRect(long l, long t, long r, long b);
    uchar* Lock(const char* name, int wait);
    void Unlock(const char* name);
    
    void SetInfo();
    void SetAccessOffsets();
    void GetPalette(PALETTEENTRY *pal);
    void SetPalette(PALETTEENTRY *pal);
    uchar CheckSurface();
    long AlignedWidth();

        // Members sorted by offset from layout.json
    /* 0x00 */ TDrawSystem *DrawSystem;
    /* 0x04 */ void *Wnd;
    /* 0x08 */ uchar *Bits;                  // Was DrawSurface in your code
    /* 0x0C */ BITMAPINFO256 *BitmapInfo;    // Was UsingVidMem in your code
    /* 0x10 */ void *Bitmap;                 // Was DrawDc in your code
    /* 0x14 */ void *OldBitmap;              // Was BitmapInfo in your code
    /* 0x18 */ int Width;
    /* 0x1C */ int Height;
    /* 0x20 */ int Pitch;
    /* 0x24 */ int Orien;
    /* 0x28 */ RECT ClipRect;                // 16 bytes (0x28 -> 0x38)
    /* 0x38 */ void *DrawDc;
    /* 0x3C */ IDirectDrawSurface *DrawSurface;
    /* 0x40 */ DDSURFACEDESC SurfaceDesc;    // Size 108 (0x6C). Ends at 0xAC.
    // Note: The layout.json says SurfaceDesc is at 64 (0x40). 
    // 0x40 + 0x6C = 0xAC. 
    // However, Node is at 172 (0xAC). This aligns perfectly.
    
    /* 0xAC */ DrawAreaNode *Node;
    /* 0xB0 */ char *Name;
    /* 0xB4 */ uchar *LastBits;
    /* 0xB8 */ int LastPitch;                // MISSING IN YOUR CODE
    /* 0xBC */ void **DisplayOffsets;
    /* 0xC0 */ void **CurDisplayOffsets;
    /* 0xC4 */ void **FloatOffsets;
    /* 0xC8 */ RGE_Color_Table *shadow_color_table;
    /* 0xCC */ TSpan_List_Manager *SpanList;
    /* 0xD0 */ TSpan_List_Manager *CurSpanList;
    /* 0xD4 */ int Float_X_Delta;
    /* 0xD8 */ int Float_Y_Delta;
    /* 0xDC */ int DisplayOffsetsSz;
    /* 0xE0 */ int FloatOffsetsSz;
    /* 0xE4 */ int SystemMemOnly;
    /* 0xE8 */ int UsingVidMem;
    /* 0xEC */ int UseTrans;
    /* 0xF0 */ int IsPrimarySurface;
    /* 0xF4 */ int Restored;
    /* 0xF8 */ int ExtendedLines;
    /* 0xFC */ uchar TransColor;
    
    // Padding to 256 bytes (0x100) implied
};

// MANDATORY VERIFICATION
static_assert(sizeof(TDrawArea) == 256, "TDrawArea size mismatch");
static_assert(sizeof(DDSURFACEDESC) == 0x6C, "DDSURFACEDESC must be 108 bytes for AoE1");