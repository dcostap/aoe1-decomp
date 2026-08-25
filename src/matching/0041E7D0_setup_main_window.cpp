// VA: 0041E7D0 RGE_Base_Game::setup_main_window (330 B)
// PDB source: basegame.cpp:2242-2288
//
// Attempt log:
// - Replaced the packet's free-function/raw-offset scaffold with the typed
//   RGE_Prog_Info and RGE_Base_Game member surface.  The source follows the
//   natural CreateWindowExA, RECT, SetWindowPos, and panel-system flow proved
//   by the original call order.
// - The typed baseline is exact in size/frame/CFG and all 10 calls.  The only
//   drift is the SetWindowPos arithmetic schedule: VC5 loads window bottom
//   before top, while the original loads top, then bottom.  Algebraic,
//   compound, grouped, named-top, unsigned, and four-case height-lab variants
//   all duplicated the 11-byte mismatch; keep the natural expression here.
// - Main-agent audit confirmed canonical game/program/window ownership and kept
//   the direct Win32 rectangle arithmetic rather than scheduling scaffolding.
// - Follow-up top-first and inline-helper spellings, plus a gated nine-way
//   height-expression lab, all collapsed to the same 11-byte SetWindowPos drift;
//   restored the pinned natural source.
// - This pass rechecked int/long field widths, compound updates, custom RECT
//   overlays, ordinary aliases, and likely basegame.cpp header context; all
//   remained in the same 11-byte basin.
// - A narrow volatile lvalue on win_rect.bottom alone reproduces the original
//   330 bytes exactly by preserving its observed delayed stack load.  It is
//   diagnostic only: no source/donor evidence supports volatile on a local
//   Win32 RECT, so the natural typed expression remains the living source.

#include <windows.h>

#ifndef BASEGAME_GROUPED_TU
class RGE_Prog_Info {
public:
    char prog_name[101];
    char prog_version[21];
    char prog_title[121];
    char gap_F3[0x410 - 0xF3];
    HINSTANCE instance;
    char gap_414[0x618 - 0x414];
    int show_wnd_flag;
    char gap_61C[0x894 - 0x61C];
    int full_screen;
    char gap_898[0x8E0 - 0x898];
    long main_wid;
    long main_hgt;
};

class TPanelSystem {
public:
    void DisableIME();
};
#endif

extern TPanelSystem panel_system;
extern HWND AppWnd;

#ifndef BASEGAME_GROUPED_TU
class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

    char gap_04[0x08];
    RGE_Prog_Info* prog_info;
    HWND prog_window;

protected:
    virtual int setup_main_window();
};
#endif

int RGE_Base_Game::setup_main_window()
{
    int screen_width = GetSystemMetrics(0);
    int screen_height = GetSystemMetrics(1);
    RECT win_rect;
    RECT client_rect;

    if (this->prog_info->full_screen == 0 &&
        (screen_width != this->prog_info->main_wid ||
         screen_height != this->prog_info->main_hgt)) {
        this->prog_window = CreateWindowExA(
            0, this->prog_info->prog_name, this->prog_info->prog_title,
            0x02CA0000, 0, 0,
            this->prog_info->main_wid, this->prog_info->main_hgt,
            0, 0, this->prog_info->instance, 0);
    }
    else {
        this->prog_window = CreateWindowExA(
            0, this->prog_info->prog_name, this->prog_info->prog_title,
            0x82080000, 0, 0, screen_width, screen_height,
            0, 0, this->prog_info->instance, 0);
    }

    if (this->prog_window == 0)
        return 0;

    GetWindowRect(this->prog_window, &win_rect);
    GetClientRect(this->prog_window, &client_rect);

    if (client_rect.right != this->prog_info->main_wid ||
        client_rect.bottom != this->prog_info->main_hgt) {
        SetWindowPos(
            this->prog_window, 0, win_rect.left, win_rect.top,
            (win_rect.right - win_rect.left) - client_rect.right +
                this->prog_info->main_wid,
            (win_rect.bottom - win_rect.top) - client_rect.bottom +
                this->prog_info->main_hgt,
            0);
    }

    if (this->prog_info->full_screen != 0) {
        ShowWindow(this->prog_window, this->prog_info->show_wnd_flag);
        UpdateWindow(this->prog_window);
        SetFocus(this->prog_window);
    }

    AppWnd = this->prog_window;
    panel_system.DisableIME();
    return 1;
}
