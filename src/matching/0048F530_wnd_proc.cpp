// VA: 0048F530 TribeAchievementsScreen::wnd_proc (146 B)
// PDB source: scr_ach.cpp
// Attempt log:
// try 1: replaced free-function shim with natural member/class surface and dllimport IsIconic.

#include "../../include/scr_ach_context.h"

#if 0
extern int confirmed_close;

class RGE_Base_Game {
public:
    char gap_000[0x1B0];
    int prog_mode;
};
extern RGE_Base_Game* rge_base_game;

extern "C" __declspec(dllimport) int __stdcall IsIconic(void* hWnd);

class TPanel {
public:
    virtual long wnd_proc(void* h1, unsigned int msg, unsigned int w, long l);
    char* get_string(int id);
};

class TEasy_Panel : public TPanel {
public:
    void popupYesNoDialog(char* msg, void* unk, int a, int b);
};

class DrawSurface {
public:
    void* vtbl;
    void* hwnd;
};

class TribeAchievementsScreen : public TEasy_Panel {
public:
    char gap_004[0x20 - 0x04];
    DrawSurface* draw_surface;

    virtual long wnd_proc(void* h1, unsigned int msg, unsigned int w, long l);
};

#endif

long TribeAchievementsScreen::wnd_proc(void* h1, unsigned int msg, unsigned int w, long l)
{
    if (msg == 0x10 && confirmed_close == 0) {
        confirmed_close = 1;
        int mode = rge_base_game->prog_mode;
        if (mode == 5 || mode == 4 || mode == 6 || mode == 7) {
            if (IsIconic(draw_surface->hwnd) == 0) {
                popupYesNoDialog(get_string(0xC1D), 0, 0x1C2, 100);
                return 1;
            }
        }
    }
    return TPanel::wnd_proc(h1, msg, w, l);
}
