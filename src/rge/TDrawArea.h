#pragma once
#include <windows.h>
#include <ddraw.h>
#include "../types.h"

struct DrawAreaNode;
struct TSpan_List_Manager;
struct RGE_Color_Table;
class TDrawSystem;

struct BITMAPINFO256 {
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD bmiColors[256];
};

// TDrawArea - 256 bytes per layout.json
class TDrawArea {
public:
    /* 0x0000 */ TDrawSystem* DrawSystem;
    /* 0x0004 */ void* Wnd;
    /* 0x0008 */ uchar* Bits;
    /* 0x000C */ BITMAPINFO256* BitmapInfo;
    /* 0x0010 */ void* Bitmap;
    /* 0x0014 */ void* OldBitmap;
    /* 0x0018 */ int Width;
    /* 0x001C */ int Height;
    /* 0x0020 */ int Pitch;
    /* 0x0024 */ int Orien;
    /* 0x0028 */ RECT ClipRect;           // tagRECT, 16 bytes
    /* 0x0038 */ void* DrawDc;
    /* 0x003C */ IDirectDrawSurface7* DrawSurface;
    /* 0x0040 */ DDSURFACEDESC SurfaceDesc; // _DDSURFACEDESC, 108 bytes (0x6C)
    /* 0x00AC */ DrawAreaNode* Node;
    /* 0x00B0 */ char* Name;
    /* 0x00B4 */ uchar* LastBits;
    /* 0x00B8 */ int LastPitch;
    /* 0x00BC */ void** DisplayOffsets;
    /* 0x00C0 */ void** CurDisplayOffsets;
    /* 0x00C4 */ void** FloatOffsets;
    /* 0x00C8 */ RGE_Color_Table* shadow_color_table;
    /* 0x00CC */ TSpan_List_Manager* SpanList;
    /* 0x00D0 */ TSpan_List_Manager* CurSpanList;
    /* 0x00D4 */ int Float_X_Delta;
    /* 0x00D8 */ int Float_Y_Delta;
    /* 0x00DC */ int DisplayOffsetsSz;
    /* 0x00E0 */ int FloatOffsetsSz;
    /* 0x00E4 */ int SystemMemOnly;
    /* 0x00E8 */ int UsingVidMem;
    /* 0x00EC */ int UseTrans;
    /* 0x00F0 */ int IsPrimarySurface;
    /* 0x00F4 */ int Restored;
    /* 0x00F8 */ int ExtendedLines;
    /* 0x00FC */ uchar TransColor;
    // Compiler adds 3 bytes padding to reach 256 bytes

    TDrawArea(const char* name, int system_mem_only);
    ~TDrawArea();

    int Init(TDrawSystem* draw_system, int width, int height, int using_vid_mem, int is_primary_surface);
    void SetSize(int width, int height, int extended_lines);
    void Clear(RECT* rect, int color);
    void SetClipRect(RECT* rect);
};

// MANDATORY VERIFICATION
static_assert(sizeof(TDrawArea) == 0x100, "TDrawArea size mismatch");
static_assert(offsetof(TDrawArea, SurfaceDesc) == 0x40, "SurfaceDesc offset");
static_assert(offsetof(TDrawArea, Name) == 0xB0, "Name offset");
static_assert(offsetof(TDrawArea, TransColor) == 0xFC, "TransColor offset");
