#pragma once
#include "common.h"

struct TDrawSystem {
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
