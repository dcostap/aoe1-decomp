#pragma once
#include "common.h"
#include "DrawAreaNode.h"

struct TDrawSystem {
    TDrawSystem();
    ~TDrawSystem();

    int Init(void* inst, void* wnd, void* pal, uchar draw_type, uchar screen_mode, long width, long height, ulong flags);
    void CheckAvailModes(int param_1);
    static long __stdcall CheckAvailModesCallback(_DDSURFACEDESC* param_1, void* param_2);
    int IsModeAvail(long param_1, long param_2, int param_3);
    
    void DeleteSurfaces();
    void SetPalette(void* pal);
    void ClearPrimarySurface();
    uchar CheckSurfaces();
    void ClearRestored();
    void Paint(tagRECT* rect);
    void ModifyPalette(int start, int count, tagPALETTEENTRY* entries);
    int CreateSurfaces();
    int SetDisplaySize(long p1, long p2, int p3);

    void* Inst;
    void* Wnd;
    void* Pal;
    TDrawArea* DrawArea;
    TDrawArea* PrimaryArea;
    DrawAreaNode* DrawAreaList;
    IDirectDraw* DirDraw;
    IDirectDrawSurface* PrimarySurface;
    IDirectDrawClipper* Clipper;
    IDirectDrawPalette* DirDrawPal;
    ulong Flags;
    int ScreenWidth;
    int ScreenHeight;
    int ColorBits;
    int ErrorCode;
    int ChangedMode;
    int IsBanked;
    int CanSrcBlt;
    int Restored;
    int ModeAvail640;
    int ModeAvail800;
    int ModeAvail1024;
    int ModeAvail1280;
    int ModeAvail320_200;
    int ModeAvail320_240;
    int ModeAvail320_200_16;
    int ModeAvail320_240_16;
    int ModeAvail640_16;
    int ModeAvail800_16;
    int ModeAvail1024_16;
    tagPALETTEENTRY palette[256];
    uchar DrawType;
    uchar ScreenMode;
};
static_assert(sizeof(TDrawSystem) == 0x47C, "Size mismatch");
