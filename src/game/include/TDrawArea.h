#pragma once
#include "common.h"
#include "DrawAreaNode.h"

struct TDrawArea {
    TDrawArea(char* name);
    ~TDrawArea();

    int Init(TDrawSystem* system, void* wnd, int width, int height, int use_trans, int is_primary, int use_sys_mem);
    void SetSize(long width, long height, int pitch);
    void SetFloatOffsets(int p1, int p2);
    void Clear(tagRECT* rect);
    void PtrClear(tagRECT* rect);
    void OverlayMemCopy(tagRECT* rect, TDrawArea* src, int x, int y);
    uchar* Lock(char* name, int p2);
    void Unlock(char* name);
    void PtrSpanCopy(TDrawArea* src, int x, int y);
    void DrawLine(int x1, int y1, int x2, int y2, uchar color);
    void FillRect(long left, long top, long right, long bottom, uchar color);
    void* GetDc(char* name);
    void ReleaseDc(char* name);

    TDrawSystem* DrawSystem;
    void* Wnd;
    uchar* Bits;
    BITMAPINFO256* BitmapInfo;
    void* Bitmap;
    void* OldBitmap;
    int Width;
    int Height;
    int Pitch;
    int Orien;
    tagRECT ClipRect;
    void* DrawDc;
    IDirectDrawSurface* DrawSurface;
    _DDSURFACEDESC SurfaceDesc;
    DrawAreaNode* Node;
    char* Name;
    uchar* LastBits;
    int LastPitch;
    void** DisplayOffsets;
    void** CurDisplayOffsets;
    void** FloatOffsets;
    RGE_Color_Table* shadow_color_table;
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
    uchar TransColor;
};
static_assert(sizeof(TDrawArea) == 0x100, "Size mismatch");
