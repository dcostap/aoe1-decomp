#pragma once
#include "../common.h"


class TDrawSystem {
public:
    void* Wnd;                               // 0x4
    void* Pal;                               // 0x8
    TDrawArea* DrawArea;                     // 0xC
    TDrawArea* PrimaryArea;                  // 0x10
    DrawAreaNode* DrawAreaList;              // 0x14
    IDirectDraw* DirDraw;                    // 0x18
    IDirectDrawSurface* PrimarySurface;      // 0x1C
    IDirectDrawClipper* Clipper;             // 0x20
    IDirectDrawPalette* DirDrawPal;          // 0x24
    ulong Flags;                             // 0x28
    int ScreenWidth;                         // 0x2C
    int ScreenHeight;                        // 0x30
    int ColorBits;                           // 0x34
    int ErrorCode;                           // 0x38
    int ChangedMode;                         // 0x3C
    int IsBanked;                            // 0x40
    int CanSrcBlt;                           // 0x44
    int Restored;                            // 0x48
    int ModeAvail640;                        // 0x4C
    int ModeAvail800;                        // 0x50
    int ModeAvail1024;                       // 0x54
    int ModeAvail1280;                       // 0x58
    int ModeAvail320_200;                    // 0x5C
    int ModeAvail320_240;                    // 0x60
    int ModeAvail320_200_16;                 // 0x64
    int ModeAvail320_240_16;                 // 0x68
    int ModeAvail640_16;                     // 0x6C
    int ModeAvail800_16;                     // 0x70
    int ModeAvail1024_16;                    // 0x74
    tagPALETTEENTRY palette[256];            // 0x78
    uchar DrawType;                          // 0x478
    uchar ScreenMode;                        // 0x479

    TDrawSystem();
    virtual ~TDrawSystem();
    virtual void CheckAvailModes(int param_1);
    virtual long CheckAvailModesCallback(_DDSURFACEDESC* param_1, void* param_2);
    virtual int IsModeAvail(long param_1, long param_2, int param_3);
    virtual int Init(void* param_1, void* param_2, void* param_3, uchar param_4, uchar param_5, long param_6, long param_7, ulong param_8);
    virtual int SetDisplaySize(long param_1, long param_2, int param_3);
    virtual void ClearPrimarySurface();
    virtual uchar CheckSurfaces();
    virtual void ClearRestored();
    virtual void DeleteSurfaces();
    virtual int CreateSurfaces();
    virtual void HandleSize(void* param_1, uint param_2, uint param_3, long param_4);
    virtual void HandlePaletteChanged(void* param_1, uint param_2, uint param_3, long param_4);
    virtual int HandleQueryNewPalette(void* param_1, uint param_2, uint param_3, long param_4);
    virtual void Paint(tagRECT* param_1);
    virtual int GetIsLostErrorNum(long param_1);
    virtual int GetRestoreErrorNum(long param_1);
    virtual int GetSetDispModeErrorNum(long param_1);
    virtual int GetLockErrorNum(long param_1);
    virtual int GetDCErrorNum(long param_1);
    virtual int GetBlitErrorNum(long param_1);
    virtual int GetCreateErrorNum(long param_1);
    virtual int GetColorKeyErrorNum(long param_1);
    virtual void SetPalette(void* param_1);
    virtual void ModifyPalette(int param_1, int param_2, tagPALETTEENTRY* param_3);
};

static_assert(sizeof(TDrawSystem) == 0x47C, "TDrawSystem Size Mismatch");
static_assert(offsetof(TDrawSystem, ScreenMode) == 0x479, "TDrawSystem Offset Mismatch");

class TDrawArea {
public:
    void* Wnd;                               // 0x4
    uchar* Bits;                             // 0x8
    BITMAPINFO256* BitmapInfo;               // 0xC
    void* Bitmap;                            // 0x10
    void* OldBitmap;                         // 0x14
    int Width;                               // 0x18
    int Height;                              // 0x1C
    int Pitch;                               // 0x20
    int Orien;                               // 0x24
    tagRECT ClipRect;                        // 0x28
    void* DrawDc;                            // 0x38
    IDirectDrawSurface* DrawSurface;         // 0x3C
    _DDSURFACEDESC SurfaceDesc;              // 0x40
    DrawAreaNode* Node;                      // 0xAC
    char* Name;                              // 0xB0
    uchar* LastBits;                         // 0xB4
    int LastPitch;                           // 0xB8
    void** DisplayOffsets;                   // 0xBC
    void** CurDisplayOffsets;                // 0xC0
    void** FloatOffsets;                     // 0xC4
    RGE_Color_Table* shadow_color_table;     // 0xC8
    TSpan_List_Manager* SpanList;            // 0xCC
    TSpan_List_Manager* CurSpanList;         // 0xD0
    int Float_X_Delta;                       // 0xD4
    int Float_Y_Delta;                       // 0xD8
    int DisplayOffsetsSz;                    // 0xDC
    int FloatOffsetsSz;                      // 0xE0
    int SystemMemOnly;                       // 0xE4
    int UsingVidMem;                         // 0xE8
    int UseTrans;                            // 0xEC
    int IsPrimarySurface;                    // 0xF0
    int Restored;                            // 0xF4
    int ExtendedLines;                       // 0xF8
    uchar TransColor;                        // 0xFC

    TDrawArea(char* param_1, int param_2);
    virtual ~TDrawArea();
    virtual int Init(TDrawSystem* param_1, long param_2, long param_3, int param_4, int param_5);
    virtual uchar CheckSurface();
    virtual uchar* Lock(char* param_1, int param_2);
    virtual void Unlock(char* param_1);
    virtual void* GetDc(char* param_1);
    virtual void ReleaseDc(char* param_1);
    virtual void SetSize(long param_1, long param_2, int param_3);
    virtual void Clear(tagRECT* param_1, int param_2);
    virtual void PtrClear(tagRECT* param_1, int param_2);
    virtual void SetAccessOffsets();
    virtual void SetFloatOffsets(int param_1, int param_2);
    virtual void SetInfo();
    virtual long AlignedWidth();
    virtual void SetClipRect(tagRECT* param_1);
    virtual void SetClipRect(long param_1, long param_2, long param_3, long param_4);
    virtual void Copy(TDrawArea* param_1, long param_2, long param_3, tagRECT* param_4, int param_5);
    virtual void PtrCopy(TDrawArea* param_1, long param_2, long param_3, tagRECT* param_4);
    virtual void PtrSpanCopy(TDrawArea* param_1, long param_2, long param_3, tagRECT* param_4, uchar** param_5);
    virtual void PtrSurfaceCopy(TDrawArea* param_1, long param_2, long param_3, tagRECT* param_4, int param_5, int param_6);
    virtual void OverlayMemCopy(tagRECT* param_1, tagRECT* param_2, int param_3, int param_4, int param_5, int param_6);
    virtual void SetTrans(int param_1, uchar param_2);
    virtual void SetOverlayTrans(int param_1, uchar param_2);
    virtual void SetPixel(long param_1, long param_2, uchar param_3);
    virtual void DrawLine(int param_1, int param_2, int param_3, int param_4, uchar param_5);
    virtual void DrawRect(long param_1, long param_2, long param_3, long param_4, uchar param_5);
    virtual void DrawRect(tagRECT* param_1, uchar param_2);
    virtual void DrawHorzLine(long param_1, long param_2, long param_3, uchar param_4);
    virtual void DrawVertLine(long param_1, long param_2, long param_3, uchar param_4);
    virtual void FillRect(long param_1, long param_2, long param_3, long param_4, uchar param_5);
    virtual void DrawBevel(long param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6);
    virtual void DrawBevel2(long param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8);
    virtual void DrawBevel3(long param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10);
    virtual void DrawBevel21(long param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8);
    virtual void DrawBevel32(long param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10);
    virtual void SetShadowTable(RGE_Color_Table* param_1);
    virtual void DrawShadowBox(long param_1, long param_2, long param_3, long param_4);
    virtual void GetPalette(tagPALETTEENTRY* param_1);
    virtual void SetPalette(tagPALETTEENTRY* param_1);
    virtual void take_snapshot(char* param_1, int* param_2);
};

static_assert(sizeof(TDrawArea) == 0x100, "TDrawArea Size Mismatch");
static_assert(offsetof(TDrawArea, TransColor) == 0xFC, "TDrawArea Offset Mismatch");

