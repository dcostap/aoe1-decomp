#pragma once
#include "common.h"
#include "DrawAreaNode.h"

struct TDrawArea {
    TDrawArea(char* name);
    ~TDrawArea();

    int Init(TDrawSystem* system, void* wnd, int width, int height, int use_trans, int is_primary, int use_sys_mem);
    void SetSize(long width, long height, int pitch);
    void SetFloatOffsets(int p1, int p2);
    // NOTE: `tagRECT` coordinates are inclusive (matches `Drawarea.cpp.decomp`).
    void Clear(tagRECT* rect, int color);
    void PtrClear(tagRECT* rect, int color);
    void OverlayMemCopy(tagRECT* rect, TDrawArea* src, int x, int y);
    uchar* Lock(char* name, int p2);
    void Unlock(char* name);
    void SetTrans(int enabled, uchar trans_color);
    void SetAccessOffsets();
    void SetInfo();
    void PtrSpanCopy(TDrawArea* src, int x, int y);
    void DrawLine(int x1, int y1, int x2, int y2, uchar color);
    void SetPixel(long x, long y, uchar color);
    // NOTE: coordinates are inclusive (matches `Drawarea.cpp.decomp`).
    void FillRect(long left, long top, long right, long bottom, uchar color);
    // Primitive helpers (source of truth: `src/game/src/Drawarea.cpp.asm` / `.decomp`).
    // NOTE: `DrawHorzLine`/`DrawVertLine` take a start coordinate and a length (not x1/x2).
    void DrawHorzLine(long x, long y, long len, uchar color);
    void DrawVertLine(long x, long y, long len, uchar color);
    void DrawRect(long x1, long y1, long x2, long y2, uchar color);
    void DrawRect(tagRECT* rect, uchar color);
    void DrawBevel(long x1, long y1, long x2, long y2, uchar c_tl, uchar c_br);
    void DrawBevel2(long x1, long y1, long x2, long y2, uchar c1, uchar c2, uchar c3, uchar c4);
    void DrawBevel21(long x1, long y1, long x2, long y2, uchar c1, uchar c2, uchar c3, uchar c4);
    void DrawBevel3(long x1, long y1, long x2, long y2, uchar c1, uchar c2, uchar c3, uchar c4, uchar c5, uchar c6);
    void DrawBevel32(long x1, long y1, long x2, long y2, uchar c1, uchar c2, uchar c3, uchar c4, uchar c5, uchar c6);
    void* GetDc(char* name);
    void ReleaseDc(char* name);
    void SaveBitmap(char* filename);
    void take_snapshot(char* filename_fmt, int* snapshot_number);

    // Source-of-truth methods needed by `Panel_ez` and UI shading.
    long AlignedWidth();
    uchar CheckSurface();
    void SetClipRect(tagRECT* rect);
    void SetClipRect(long left, long top, long right, long bottom);
    void Copy(TDrawArea* dest, long x, long y, tagRECT* src_rect, int flags);
    void SetShadowTable(RGE_Color_Table* table);
    void DrawShadowBox(long left, long top, long right, long bottom);
    void GetPalette(tagPALETTEENTRY* out_entries);
    void SetPalette(tagPALETTEENTRY* entries);

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
