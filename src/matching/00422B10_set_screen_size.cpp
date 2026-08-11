// VA: 00422B10 RGE_Base_Game::set_screen_size (430 B)
// PDB source: basegame.cpp lines 5664-5735
//
// Attempt log:
// - The packet scaffold used free-function shims, null guards, and the wrong
//   direct-call/import surfaces.  Replaced it with the period typed member and
//   Win32 API forms; the binary proves the draw-area, draw-system, window, and
//   mouse-pointer offsets used below.
// - Corrected the fallback guard and client-size correction from the packet
//   decompiler's window-size expression to the executable's client RECT logic.
// - Hand-declared Win32 imports left a four-byte late register/arithmetic drift;
//   the donor-era <windows.h> surface restores the VC5 optimizer basin exactly.
// - Added the high-confidence polymorphic RGE_Base_Game prefix and canonical
//   TDrawArea widths; both preserve the exact output and the proven offsets.

#include <windows.h>

class TDrawArea {
public:
    char gap_00[0x18];
    int Width;
    int Height;
};

class TDrawSystem {
public:
    char gap_00[0x478];
    unsigned char DrawType;
    unsigned char ScreenMode;

    int SetDisplaySize(long width, long height, int bits);
    unsigned char CheckSurfaces();
    void ClearRestored();
};

class TMousePointer {
public:
    int Shutdown_Mouse();
};

extern int restore_mouse_after_paint;

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

    char gap_04[0x08];
    void* prog_info;
    void* prog_window;
    int prog_ready;
    int prog_active;
    void* prog_palette;
    void* prog_mutex;
    long window_style;
    int random_game_seed;
    int random_map_seed;
    int save_random_game_seed;
    int save_random_map_seed;
    int screen_saver_enabled;
    int low_power_enabled;
    int error_code;
    int is_timer;
    TDrawSystem* draw_system;
    TDrawArea* draw_area;
    char gap_50[0x170];
    TMousePointer* mouse_pointer;

    void set_render_all();
    void set_screen_size(long width, long height);
};

void RGE_Base_Game::set_screen_size(long width, long height)
{
    RECT win_rect;
    RECT client_rect;

    if (this->draw_area->Width != width || this->draw_area->Height != height) {
        if (this->draw_system->DrawType == 2 &&
            this->draw_system->ScreenMode == 2) {
            SetCursor(0);
            SetClassLongA(this->prog_window, -12, 0);
            this->mouse_pointer->Shutdown_Mouse();
            this->draw_system->SetDisplaySize(width, height, 8);
            this->draw_system->CheckSurfaces();
            this->draw_system->ClearRestored();
            this->set_render_all();
            restore_mouse_after_paint = 1;
            return;
        }

        int display_width = 0;
        int display_height = 0;
        void* dc = CreateICA("DISPLAY", 0, 0, 0);
        if (dc != 0) {
            display_width = GetDeviceCaps(dc, 8);
            display_height = GetDeviceCaps(dc, 10);
            DeleteDC(dc);
        }

        if (width <= display_width && height <= display_height) {
            if (display_width == width && display_height == height) {
                this->window_style = 0x92080000;
                SetWindowLongA(this->prog_window, -16, 0x92080000);
                SetWindowLongA(this->prog_window, -20, this->window_style);
            } else {
                this->window_style = 0x12CA0000;
                SetWindowLongA(this->prog_window, -20, 0x12CA0000);
                SetWindowLongA(this->prog_window, -16, this->window_style);
            }

            SetWindowPos(this->prog_window, 0, 0, 0, width, height, 0);
            GetWindowRect(this->prog_window, &win_rect);
            GetClientRect(this->prog_window, &client_rect);

            if (client_rect.right != width || client_rect.bottom != height) {
                SetWindowPos(this->prog_window, 0,
                    win_rect.left, win_rect.top,
                    width + win_rect.right - win_rect.left - client_rect.right,
                    height + win_rect.bottom - win_rect.top - client_rect.bottom,
                    0);
            }
        }
    }
}
