#pragma once
#include <windows.h>
#include <ddraw.h>
#include "TDrawArea.h"

struct DrawAreaNode;

#pragma pack(push, 1)

struct DrawAreaNode {
    TDrawArea *DrawArea;
    DrawAreaNode *PrevNode;
    DrawAreaNode *NextNode;
};

class TDrawSystem {
public:
    /* 0x0000 */ HINSTANCE Inst;
    /* 0x0004 */ HWND Wnd;
    /* 0x0008 */ void *Pal;
    /* 0x000C */ TDrawArea *DrawArea;
    /* 0x0010 */ TDrawArea *PrimaryArea;
    /* 0x0014 */ DrawAreaNode *DrawAreaList;
    /* 0x0018 */ IDirectDraw7 *DirDraw;
    /* 0x001C */ IDirectDrawSurface7 *PrimarySurface;
    /* 0x0020 */ IDirectDrawClipper *Clipper;
    /* 0x0024 */ IDirectDrawPalette *DirDrawPal;
    /* 0x0028 */ unsigned int Flags;
    /* 0x002C */ int ScreenWidth;
    /* 0x0030 */ int ScreenHeight;
    /* 0x0034 */ int ColorBits;
    /* 0x0038 */ int ErrorCode;
    /* 0x003C */ int ChangedMode;
    /* 0x0040 */ int IsBanked;
    /* 0x0044 */ int CanSrcBlt;
    /* 0x0048 */ int Restored;
    /* 0x004C */ int ModeAvail640;
    /* 0x0050 */ int ModeAvail800;
    /* 0x0054 */ int ModeAvail1024;
    /* 0x0058 */ int ModeAvail1280;
    /* 0x005C */ int ModeAvail320_200;
    /* 0x0060 */ int ModeAvail320_240;
    /* 0x0064 */ int ModeAvail320_200_16;
    /* 0x0068 */ int ModeAvail320_240_16;
    /* 0x006C */ int ModeAvail640_16;
    /* 0x0070 */ int ModeAvail800_16;
    /* 0x0074 */ int ModeAvail1024_16;
    /* 0x0078 */ PALETTEENTRY palette[256];
    /* 0x0478 */ unsigned char DrawType;
    /* 0x0479 */ unsigned char ScreenMode;
    /* 0x047A */ unsigned char _pad_47a[2]; // Padding to 0x47C

    TDrawSystem();
    ~TDrawSystem();

    void CheckAvailModes(int full_screen);
    int IsModeAvail(int width, int height, int color_bits);
    int Init(HINSTANCE instance, HWND window, void *palette, int draw_type, int screen_mode, int width, int height, int system_mem);
    int CreateSurfaces();
    void Paint(RECT *rect);
};

#pragma pack(pop)

static_assert(sizeof(TDrawSystem) == 0x47C, "TDrawSystem size mismatch");
