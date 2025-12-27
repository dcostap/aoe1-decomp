#pragma once
#include <windows.h>
#include <ddraw.h>
#include "../types.h"

struct DrawAreaNode;
struct TSpan_List_Manager;
struct RGE_Color_Table;
class TDrawSystem;

#pragma pack(push, 1)

struct BITMAPINFO256 {
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD bmiColors[256];
};

class TDrawArea {
public:
    /* 0x0000 */ TDrawSystem *DrawSystem;
    /* 0x0004 */ HWND Wnd;
    /* 0x0008 */ IDirectDrawSurface *DrawSurface;
    /* 0x000C */ int UsingVidMem;
    /* 0x0010 */ HDC DrawDc;
    /* 0x0014 */ BITMAPINFO256 *BitmapInfo;
    /* 0x0018 */ HBITMAP Bitmap;
    /* 0x001C */ HGDIOBJ OldBitmap;
    /* 0x0020 */ uchar *Bits;
    /* 0x0024 */ int Width;
    /* 0x0028 */ int Height;
    /* 0x002C */ int Pitch;
    /* 0x0030 */ int UseTrans;
    /* 0x0034 */ uchar TransColor;
    /* 0x0035 */ DrawAreaNode *Node;
    /* 0x0039 */ int Restored;
    /* 0x003D */ int IsPrimarySurface;
    /* 0x0041 */ int SystemMemOnly;
    /* 0x0045 */ RECT ClipRect;
    /* 0x0055 */ uchar *LastBits;
    /* 0x0059 */ void **DisplayOffsets;
    /* 0x005D */ void **CurDisplayOffsets;
    /* 0x0061 */ int DisplayOffsetsSz;
    /* 0x0065 */ int ExtendedLines;
    /* 0x0069 */ void **FloatOffsets;
    /* 0x006D */ int Float_X_Delta;
    /* 0x0071 */ int Float_Y_Delta;
    /* 0x0075 */ int FloatOffsetsSz;
    /* 0x0079 */ DDSURFACEDESC SurfaceDesc; // 0x6c bytes
    /* 0x00E5 */ int Orien;
    /* 0x00E9 */ TSpan_List_Manager *SpanList;
    /* 0x00ED */ TSpan_List_Manager *CurSpanList;
    /* 0x00F1 */ RGE_Color_Table *shadow_color_table;
    /* 0x00F5 */ char *Name;

    TDrawArea(const char *name, int system_mem_only);
    ~TDrawArea();

    int Init(TDrawSystem *draw_system, int width, int height, int using_vid_mem, int is_primary_surface);
    void SetSize(int width, int height, int extended_lines);
    void Clear(RECT *rect, int color);
    void SetClipRect(RECT *rect);
};

#pragma pack(pop)

static_assert(sizeof(TDrawArea) == 0xF9, "TDrawArea size mismatch");
