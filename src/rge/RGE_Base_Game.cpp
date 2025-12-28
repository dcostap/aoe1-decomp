#include "RGE_Base_Game.h"
#include "RGE_Game_World.h"
#include "RGE_Map.h"
#include "RGE_Prog_Info.h"
#include "TDrawSystem.h"
#include "TDrawArea.h"
#include "TPanelSystem.h"
#include <stdio.h>

RGE_Base_Game* rge_base_game = nullptr;

LRESULT CALLBACK rge_base_game_wnd_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    if (rge_base_game) {
        return rge_base_game->wnd_proc(hwnd, msg, wparam, lparam);
    }
    return DefWindowProcA(hwnd, msg, wparam, lparam);
}

RGE_Base_Game::RGE_Base_Game(RGE_Prog_Info *info, int setup_flag) {
    this->prog_info = info;
    this->world = nullptr;
    this->prog_ready = 0;
    this->prog_active = 1;
    this->windows_mouse = 1;
    this->error_code = 0;
    this->save_music_file[0] = 0;
    this->prog_window = nullptr;
    this->registry = nullptr;
    this->debugLog = nullptr;
    this->draw_system = nullptr;
    this->draw_area = nullptr;
    this->sound_system = nullptr;
    this->music_system = nullptr;
    this->comm_handler = nullptr;
    this->mouse_pointer = nullptr;
    this->fonts = nullptr;
    this->shapes = nullptr;
    this->sounds = nullptr;

    rge_base_game = this;
}

RGE_Base_Game::~RGE_Base_Game() {
    if (this->world) delete this->world;
}

int RGE_Base_Game::setup() {
    if (!this->setup_registry()) return 0;
    if (!this->setup_debugging_log()) return 0;
    if (!this->setup_cmd_options()) return 0;
    if (!this->setup_class()) return 0;
    if (!this->setup_main_window()) return 0;
    if (!this->setup_palette()) return 0;
    if (!this->setup_graphics_system()) return 0;
    
    this->prog_ready = 1;
    return 1;
}

int RGE_Base_Game::run() {
    MSG msg;
    while (true) {
        if (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                break;
            }
            if (this->handle_message(&msg)) {
                TranslateMessage(&msg);
                DispatchMessageA(&msg);
            }
        } else {
            if (this->prog_active) {
                this->handle_idle();
            } else {
                WaitMessage();
            }
        }
    }
    return (int)msg.wParam;
}

int RGE_Base_Game::handle_idle() {
    if (this->draw_system && this->draw_area) {
        static int frame_count = 0;
        frame_count++;

        if (frame_count % 100 == 0) {
            printf("RGE_Base_Game::handle_idle: frame %d\n", frame_count);
        }

        // Cycle colors to show it's alive
        this->draw_area->Clear(nullptr, (frame_count / 10) % 256);
        this->draw_system->Paint(nullptr);
    }
    Sleep(1);
    return 1;
}

int RGE_Base_Game::handle_message(tagMSG *msg) {
    return 1;
}

long RGE_Base_Game::wnd_proc(HWND hwnd, uint msg, WPARAM wparam, LPARAM lparam) {
    switch (msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            RECT rect;
            GetClientRect(hwnd, &rect);
            FillRect(hdc, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
            EndPaint(hwnd, &ps);
            return 0;
        }
        case WM_ACTIVATE:
            this->prog_active = (LOWORD(wparam) != WA_INACTIVE);
            return 0;
    }
    return DefWindowProcA(hwnd, msg, wparam, lparam);
}

int RGE_Base_Game::setup_class() {
    if (this->prog_info->prev_instance) {
        return 1;
    }

    WNDCLASSA cls;
    memset(&cls, 0, sizeof(cls));
    cls.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
    cls.lpfnWndProc = rge_base_game_wnd_proc;
    cls.cbClsExtra = 0;
    cls.cbWndExtra = 0;
    cls.hInstance = (HINSTANCE)this->prog_info->instance;
    cls.hIcon = LoadIconA((HINSTANCE)this->prog_info->instance, this->prog_info->icon_name);
    cls.hCursor = LoadCursorA(NULL, IDC_ARROW);
    cls.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    cls.lpszMenuName = NULL;
    cls.lpszClassName = this->prog_info->prog_name;

    if (this->prog_info->menu_name[0] != '\0') {
        cls.lpszMenuName = this->prog_info->menu_name;
    }

    return RegisterClassA(&cls) != 0;
}

int RGE_Base_Game::setup_main_window() {
    DWORD style;
    int x, y, width, height;

    if (this->prog_info->full_screen) {
        style = WS_POPUP;
        x = 0;
        y = 0;
        width = this->prog_info->main_wid;
        height = this->prog_info->main_hgt;
    } else {
        style = WS_OVERLAPPEDWINDOW;
        x = CW_USEDEFAULT;
        y = CW_USEDEFAULT;
        width = this->prog_info->main_wid;
        height = this->prog_info->main_hgt;

        RECT rect = { 0, 0, width, height };
        AdjustWindowRect(&rect, style, FALSE);
        width = rect.right - rect.left;
        height = rect.bottom - rect.top;
    }

    this->prog_window = CreateWindowExA(
        0,
        this->prog_info->prog_name,
        this->prog_info->prog_title,
        style,
        x, y, width, height,
        NULL, NULL, (HINSTANCE)this->prog_info->instance, NULL
    );

    if (!this->prog_window) {
        return 0;
    }

    ShowWindow((HWND)this->prog_window, this->prog_info->show_wnd_flag);
    UpdateWindow((HWND)this->prog_window);

    return 1;
}

int RGE_Base_Game::setup_registry() { return 1; }
int RGE_Base_Game::setup_debugging_log() { return 1; }
int RGE_Base_Game::setup_cmd_options() { return 1; }
void RGE_Base_Game::set_game_mode(int mode, int sub_mode) { this->prog_mode = mode; }
void RGE_Base_Game::set_player(short player_id) {}
char *RGE_Base_Game::get_string(long a, char *b, int c) { return nullptr; }
char *RGE_Base_Game::get_string2(int a, long b, long c, char *d, int e) { return nullptr; }
void *RGE_Base_Game::get_view_panel() { return nullptr; }
void *RGE_Base_Game::get_map_panel() { return nullptr; }
void *RGE_Base_Game::new_scenario_header(void *scenario) { return nullptr; }
void *RGE_Base_Game::new_scenario_header(int a) { return nullptr; }
void *RGE_Base_Game::new_scenario_info(int a) { return nullptr; }
void RGE_Base_Game::notification(int a, long b, long c, long d, long e) {}
void RGE_Base_Game::send_game_options() {}
void RGE_Base_Game::receive_game_options() {}
char *RGE_Base_Game::gameSummary() { return nullptr; }
int RGE_Base_Game::processCheatCode(int a, char *b) { return 0; }
void RGE_Base_Game::setNumberPlayers(int n) { this->rge_game_options.numberPlayersValue = (uchar)n; }
int RGE_Base_Game::setup_palette() {
    this->prog_palette = TPanelSystem::get_palette(&panel_system, this->prog_info->pal_file, 50500);
    if (!this->prog_palette) {
        printf("RGE_Base_Game::setup_palette: WARNING: Failed to load palette, continuing anyway...\n");
    }
    return 1;
}
int RGE_Base_Game::setup_sounds() { return 1; }
RGE_Game_World* RGE_Base_Game::create_world() { return new RGE_Game_World(); }
int RGE_Base_Game::handle_activate(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_query_new_palette(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::action_key_down(ulong key, int a, int b, int c, int d) { return 0; }
int RGE_Base_Game::action_user_command(ulong a, ulong b) { return 0; }
int RGE_Base_Game::action_close() { return 0; }
void RGE_Base_Game::calc_timing_text() {}
void RGE_Base_Game::show_timings() {}
void RGE_Base_Game::show_comm() {}
void RGE_Base_Game::show_ai() {}
void RGE_Base_Game::set_interface_messages() {}
void RGE_Base_Game::set_prog_mode(int mode) { this->prog_mode = mode; }
char* RGE_Base_Game::get_string(int a, long b, char* c, int d) { return nullptr; }
char* RGE_Base_Game::get_string(long a) { return nullptr; }
int RGE_Base_Game::reset_comm() { return 1; }
int RGE_Base_Game::setup_music_system() { return 1; }
void RGE_Base_Game::shutdown_music_system() {}
int RGE_Base_Game::setup_graphics_system() {
    if (this->prog_info->use_dir_draw) {
        HDC hdc = GetDC(NULL);
        int bpp = GetDeviceCaps(hdc, BITSPIXEL);
        ReleaseDC(NULL, hdc);
        if (bpp < 8) {
            this->error_code = 19;
            return 0;
        }
    }

    this->draw_system = new TDrawSystem();
    if (!this->draw_system) {
        return 0;
    }

    this->draw_system->CheckAvailModes(this->prog_info->full_screen);

    // Try to find a valid mode
    int widths[] = { this->prog_info->main_wid, 640, 800, 1024, 1280 };
    int heights[] = { this->prog_info->main_hgt, 480, 600, 768, 1024 };
    bool found = false;

    for (int i = 0; i < 5; ++i) {
        if (this->draw_system->IsModeAvail(widths[i], heights[i], 8)) {
            this->prog_info->main_wid = widths[i];
            this->prog_info->main_hgt = heights[i];
            found = true;
            break;
        }
    }

    if (this->draw_system->Init(
        (HINSTANCE)this->prog_info->instance,
        (HWND)this->prog_window,
        this->prog_palette,
        this->prog_info->use_dir_draw ? 2 : 1,
        this->prog_info->full_screen ? 2 : 1,
        this->prog_info->main_wid,
        this->prog_info->main_hgt,
        this->prog_info->use_sys_mem)) 
    {
        TPanelSystem::release_palette(&panel_system, this->prog_palette);
        this->prog_palette = TPanelSystem::get_palette(&panel_system, this->prog_info->pal_file, 50500);

        if (this->prog_palette && this->draw_system) {
            LOGPALETTE *lp = (LOGPALETTE *)this->prog_palette;
            this->draw_system->ModifyPalette(0, lp->palNumEntries, lp->palPalEntry);
        }

        this->draw_area = this->draw_system->DrawArea;
        if (this->draw_area) {
            this->draw_area->Clear(nullptr, 0);
            this->draw_system->Paint(nullptr);
        }
        return 1;
    }

    return 0;
}
int RGE_Base_Game::setup_mouse() { return 1; }
int RGE_Base_Game::setup_chat() { return 1; }
int RGE_Base_Game::setup_comm() { return 1; }
int RGE_Base_Game::setup_sound_system() { return 1; }
int RGE_Base_Game::setup_fonts() { return 1; }
int RGE_Base_Game::setup_shapes() { return 1; }
int RGE_Base_Game::setup_blank_screen() { return 1; }
void RGE_Base_Game::setup_timings() {}
void RGE_Base_Game::stop_sound_system() {}
int RGE_Base_Game::restart_sound_system() { return 1; }
void RGE_Base_Game::stop_music_system() {}
int RGE_Base_Game::restart_music_system() { return 1; }
int RGE_Base_Game::handle_mouse_move(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_key_down(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_user_command(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_command(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_music_done(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_paint(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_init_menu(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_exit_menu(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_size(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_palette_changed(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_close(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_destroy(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::action_update() { return 1; }
int RGE_Base_Game::action_mouse_move(long x, long y, int a, int b, int c, int d) { return 0; }
int RGE_Base_Game::action_command(ulong a, ulong b) { return 0; }
int RGE_Base_Game::action_music_done() { return 0; }
int RGE_Base_Game::action_activate() { return 0; }
int RGE_Base_Game::action_deactivate() { return 0; }
int RGE_Base_Game::action_init_menu() { return 0; }
int RGE_Base_Game::action_exit_menu() { return 0; }
int RGE_Base_Game::action_size() { return 0; }
void RGE_Base_Game::calc_timings() {}
int RGE_Base_Game::setup_map_save_area() { return 1; }
int RGE_Base_Game::get_error_code() { return this->error_code; }
