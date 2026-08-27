#ifndef AOE1_COLORLOG_H
#define AOE1_COLORLOG_H

#include <windows.h>
#include <ddraw.h>

struct TDrawArea {
    char gap_00[0x18];
    int Width;
    char gap_1C[0x20];
    IDirectDrawSurface* DrawSurface;
};

struct TDrawSystem {
    char gap_00[0x04];
    HWND Wnd;
    char gap_08[0x04];
    TDrawArea* DrawArea;
    char gap_10[0x0C];
    IDirectDrawSurface* PrimarySurface;
    char gap_20[0x459];
    unsigned char ScreenMode;
};

struct RGE_Base_Game {
    char gap_00[0x48];
    TDrawSystem* draw_system;
    char gap_4C[0x164];
    int prog_mode;
};

extern RGE_Base_Game* rge_base_game;
extern unsigned char do_color_log;

void __cdecl color_log(unsigned char param_1, unsigned char param_2, int param_3);

#endif  // AOE1_COLORLOG_H
