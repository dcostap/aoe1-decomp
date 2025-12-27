#include "RGE_Base_Game.h"
#include "RGE_Prog_Info.h"
#include "RGE_Game_World.h"
#include "TDrawSystem.h"
#include "TDrawArea.h"
#include "TPanelSystem.h"
#include "TMousePointer.h"
#include "TRegistry.h"
#include "TCommunications_Handler.h"
#include <windows.h>
#include <cstdio>

// Global pointers
RGE_Base_Game* rge_base_game = nullptr;
void* StringTable = nullptr;
extern void* panel_system;
HINSTANCE AppInst = nullptr;
HWND AppWnd = nullptr;

RGE_Base_Game::RGE_Base_Game(RGE_Prog_Info* info, int setup_flag) {
    this->player_game_info = nullptr;
    this->random_game_seed = -1;
    this->random_map_seed = -1;
    this->save_random_game_seed = -1;
    this->save_random_map_seed = -1;
    this->quick_build = 0;
    
    setVersion(1.0f);
    setScenarioGame(0);
    setCampaignGame(0);
    setSavedGame(0);
    setSinglePlayerGame(1);
    setMultiplayerGame(0);
    setMapSize(0x60, 0x60, 8);
    setAllowCheatCodes(0);
    setCheatNotification(1);
    setFullVisibility(0);
    setFogOfWar(1);
    setColoredChat(1);
    setGameDeveloperMode(0);
    setDifficulty(0);

    for (int i = 0; i < 9; ++i) {
        setPlayerCDAndVersion(i, 0);
        setPlayerHasCD(i, 0);
        setPlayerVersion(i, 0);
        setPlayerTeam(i, 1);
    }

    setPathFinding(0);
    setMpPathFinding(0);
    setNumberPlayers(4);
    setScenarioName("");

    rge_base_game = this;
    this->prog_info = info;
    this->prog_window = nullptr;
    this->prog_ready = 0;
    this->prog_active = 1;
    this->prog_palette = nullptr;
    this->window_style = 0;
    StringTable = nullptr;
    this->screen_saver_enabled = 0;
    this->error_code = 0;
    this->is_timer = 0;
    this->draw_system = nullptr;
    this->draw_area = nullptr;
    this->outline_type = 2;
    this->custom_mouse = 0;
    this->shapes = nullptr;
    this->sound_system = nullptr;
    this->music_system = nullptr;
    this->sound_num = 0;
    this->sounds = nullptr;
    this->save_music_type = 0;
    this->save_music_track_from = 0;
    this->save_music_track_to = 0;
    this->save_music_cur_track = 0;
    this->save_music_file[0] = 0;
    this->save_music_loop = 0;
    this->save_music_pos = 0;
    this->comm_handler = nullptr;
    this->debugLog = nullptr;
    this->log_comm = 0;
    this->comm_syncstop = 0;
    this->comm_syncmsg = 0;
    this->comm_stepmode = 0;
    this->comm_speed = 1;
    this->comm_droppackets = 0;
    this->registry = nullptr;
    this->prog_mode = 0;
    this->game_mode = 0;
    this->sub_game_mode = 0;
    this->paused = 0;
    this->mouse_pointer = nullptr;
    this->erase_mouse = 0;
    this->mouse_blit_sync = 0;
    this->is_mouse_on = 1;
    this->windows_mouse = 1;
    this->mouse_cursor = LoadCursorA(nullptr, (LPCSTR)IDC_ARROW);
    this->font_num = 0;
    this->fonts = nullptr;
    
    GetCurrentDirectoryA(0x104, this->work_dir);
    strcpy(this->string_dll_name, "language.dll");

    this->master_obj_id = -1;
    this->terrain_id = -1;
    this->elevation_height = -1;
    this->world = nullptr;
    this->render_all = 1;
    this->brush_size = 1;
    this->timing_text[0] = 0;
    this->frame_count = 0;
    this->world_update_count = 0;
    this->view_update_count = 0;
    this->last_frame_count = 0;
    this->last_world_update_count = 0;
    this->last_view_update_count = 0;
    this->fps = 0;
    this->world_update_fps = 0;
    this->view_update_fps = 0;
    this->last_view_time = 0;

    for (int i = 0; i < 30; ++i) {
        this->timings[i].accum_time = 0;
        this->timings[i].last_time = 0;
        this->timings[i].max_time = 0;
    }

    this->do_show_timings = 0;
    this->do_show_comm = 0;
    this->do_show_ai = 0;
    this->save_check_for_cd = 1;
    
    AppInst = (HINSTANCE)this->prog_info->instance;
    this->scenario_info = nullptr;

    for (int i = 0; i < 9; ++i) {
        this->playerIDValue[i] = 0;
        this->resigned[i] = 0;
    }

    this->auto_paused = 0;
    this->rollover = 1;
    this->map_save_area = nullptr;
    this->game_speed = 1.0f;
    this->single_player_difficulty = 2;

    if (setup_flag != 0) {
        if (setup() == 0 && this->error_code == 0) {
            this->error_code = 1;
        }
    }
    this->display_selected_ids = 0;
}

RGE_Base_Game::~RGE_Base_Game() {}

int RGE_Base_Game::get_error_code() { return this->error_code; }

void RGE_Base_Game::setVersion(float v) { this->rge_game_options.versionValue = v; }
void RGE_Base_Game::setScenarioGame(int v) { this->rge_game_options.scenarioGameValue = (uchar)v; }
void RGE_Base_Game::setScenarioName(const char* name) { strncpy(this->rge_game_options.scenarioNameValue, name, 128); }
void RGE_Base_Game::setCampaignGame(int v) { this->campaignGameValue = v; }
void RGE_Base_Game::setSavedGame(int v) { this->savedGameValue = v; }
void RGE_Base_Game::setSinglePlayerGame(int v) { this->rge_game_options.singlePlayerGameValue = (uchar)v; }
void RGE_Base_Game::setMultiplayerGame(int v) { this->rge_game_options.multiplayerGameValue = (uchar)v; }
void RGE_Base_Game::setMapSize(int x, int y, int z) { 
    this->rge_game_options.mapXSizeValue = (uchar)x; 
    this->rge_game_options.mapYSizeValue = (uchar)y;
    this->rge_game_options.mapZSizeValue = (uchar)z;
}
void RGE_Base_Game::setAllowCheatCodes(int v) { this->rge_game_options.allowCheatCodesValue = (uchar)v; }
void RGE_Base_Game::setCheatNotification(int v) { this->rge_game_options.cheatNotificationValue = (uchar)v; }
void RGE_Base_Game::setFullVisibility(int v) { this->rge_game_options.fullVisibilityValue = (uchar)v; }
void RGE_Base_Game::setFogOfWar(int v) { this->rge_game_options.fogOfWarValue = (uchar)v; }
void RGE_Base_Game::setColoredChat(int v) { this->rge_game_options.coloredChatValue = (uchar)v; }
void RGE_Base_Game::setGameDeveloperMode(int v) { this->rge_game_options.gameDeveloperModeValue = (uchar)v; }
void RGE_Base_Game::setDifficulty(int v) { this->rge_game_options.difficultyValue = (uchar)v; }
void RGE_Base_Game::setPlayerCDAndVersion(int p, char v) { if(p>=0 && p<9) this->rge_game_options.playerCDAndVersionValue[p] = (uchar)v; }
void RGE_Base_Game::setPlayerHasCD(int p, int v) {}
void RGE_Base_Game::setPlayerVersion(int p, char v) {}
void RGE_Base_Game::setPlayerTeam(int p, int v) { if(p>=0 && p<9) this->rge_game_options.playerTeamValue[p] = (uchar)v; }
void RGE_Base_Game::setPathFinding(char v) { this->pathFindingValue = (uchar)v; }
void RGE_Base_Game::setMpPathFinding(char v) { this->rge_game_options.mpPathFindingValue = (uchar)v; }
void RGE_Base_Game::setNumberPlayers(int v) { this->rge_game_options.numberPlayersValue = (uchar)v; }

int RGE_Base_Game::setup_registry() {
    this->registry = new TRegistry(this->prog_info->registry_key);
    return 1;
}

int RGE_Base_Game::setup_debugging_log() { return 1; }
int RGE_Base_Game::setup_cmd_options() { return 1; }
LRESULT CALLBACK rge_base_game_wnd_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    if (rge_base_game) {
        return rge_base_game->wnd_proc(hwnd, msg, wparam, lparam);
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
    cls.hInstance = (HINSTANCE)this->prog_info->instance;
    cls.hIcon = LoadIconA((HINSTANCE)this->prog_info->instance, this->prog_info->icon_name);
    cls.hCursor = nullptr;
    cls.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    cls.lpszMenuName = this->prog_info->menu_name[0] ? this->prog_info->menu_name : nullptr;
    cls.lpszClassName = this->prog_info->prog_name;

    if (RegisterClassA(&cls)) {
        return 1;
    }
    return 0;
}

int RGE_Base_Game::setup_main_window() {
    int screen_w = GetSystemMetrics(SM_CXSCREEN);
    int screen_h = GetSystemMetrics(SM_CYSCREEN);

    DWORD style;
    int x, y, w, h;

    if (this->prog_info->full_screen == 0 && 
        (screen_w != this->prog_info->main_wid || screen_h != this->prog_info->main_hgt)) {
        style = WS_OVERLAPPEDWINDOW;
        x = CW_USEDEFAULT;
        y = CW_USEDEFAULT;
        w = this->prog_info->main_wid;
        h = this->prog_info->main_hgt;
    } else {
        style = WS_POPUP | WS_VISIBLE;
        x = 0;
        y = 0;
        w = screen_w;
        h = screen_h;
    }

    this->prog_window = CreateWindowExA(
        0,
        this->prog_info->prog_name,
        this->prog_info->prog_title,
        style,
        x, y, w, h,
        nullptr, nullptr, (HINSTANCE)this->prog_info->instance, nullptr
    );

    if (!this->prog_window) {
        return 0;
    }

    if (style & WS_OVERLAPPEDWINDOW) {
        RECT rect;
        rect.left = 0;
        rect.top = 0;
        rect.right = this->prog_info->main_wid;
        rect.bottom = this->prog_info->main_hgt;
        AdjustWindowRect(&rect, style, FALSE);
        SetWindowPos((HWND)this->prog_window, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, SWP_NOMOVE | SWP_NOZORDER);
    }

    ShowWindow((HWND)this->prog_window, SW_SHOW);
    UpdateWindow((HWND)this->prog_window);
    SetFocus((HWND)this->prog_window);

    AppWnd = (HWND)this->prog_window;
    return 1;
}

int RGE_Base_Game::setup_graphics_system() {
    this->draw_system = new TDrawSystem();
    if (!this->draw_system) return 0;

    if (this->draw_system->Init(AppInst, (HWND)this->prog_window, nullptr, 2, this->prog_info->full_screen ? 0 : 1, 800, 600, 0)) {
        this->draw_area = this->draw_system->DrawArea;
        return 1;
    }
    return 0;
}

int RGE_Base_Game::setup_palette() { return 1; }

int RGE_Base_Game::setup_mouse() {
    this->mouse_pointer = new TMousePointer(0);
    if (this->mouse_pointer) {
        this->mouse_pointer->setup(0, this->draw_area, this->prog_info->cursor_file, 0, 0);
        return 1;
    }
    return 0;
}

int RGE_Base_Game::setup_chat() { return 1; }
int RGE_Base_Game::setup_sounds() { return 1; }
int RGE_Base_Game::setup_music_system() { return 1; }
int RGE_Base_Game::setup_sound_system() { return 1; }

int RGE_Base_Game::setup_comm() {
    this->comm_handler = new TCommunications_Handler();
    return 1;
}

int RGE_Base_Game::setup_blank_screen() {
    if (this->draw_area) {
        this->draw_area->Clear(0, 0);
    }
    return 1;
}

int RGE_Base_Game::setup_shapes() { return 1; }
int RGE_Base_Game::setup_fonts() { return 1; }
int RGE_Base_Game::setup_map_save_area() { return 1; }

int RGE_Base_Game::setup() {
    if (this->setup_class() == 0) { this->error_code = 2; return 0; }
    if (this->setup_registry() == 0) { this->error_code = 3; return 0; }
    if (this->setup_debugging_log() == 0) { this->error_code = 4; return 0; }
    if (this->setup_cmd_options() == 0) { this->error_code = 5; return 0; }
    if (this->setup_main_window() == 0) { this->error_code = 6; return 0; }
    if (this->setup_graphics_system() == 0) { this->error_code = 7; return 0; }
    if (this->setup_palette() == 0) { this->error_code = 8; return 0; }
    if (this->setup_mouse() == 0) { this->error_code = 9; return 0; }
    if (this->setup_chat() == 0) { this->error_code = 10; return 0; }
    if (this->setup_sounds() == 0) { this->error_code = 11; return 0; }
    if (this->setup_music_system() == 0) { this->error_code = 12; return 0; }
    if (this->setup_sound_system() == 0) { this->error_code = 13; return 0; }
    if (this->setup_comm() == 0) { this->error_code = 14; return 0; }
    if (this->setup_blank_screen() == 0) { this->error_code = 15; return 0; }
    if (this->setup_shapes() == 0) { this->error_code = 16; return 0; }
    if (this->setup_fonts() == 0) { this->error_code = 17; return 0; }
    if (this->setup_map_save_area() == 0) { this->error_code = 18; return 0; }

    this->prog_ready = 1;
    return 1;
}

int RGE_Base_Game::run() {
    MSG msg;
#ifdef _DEBUG
    printf("RGE_Base_Game::run: Entering loop. active=%d, mode=%d\n", this->prog_active, this->prog_mode);
#endif
    while (true) {
        while (this->prog_active == 0 || (this->prog_mode != 4 && this->prog_mode != 2) ||
               (this->comm_handler && TCommunications_Handler::IsPaused(this->comm_handler))) {
#ifdef _DEBUG
            static int last_mode = -1;
            if (this->prog_mode != last_mode) {
                printf("RGE_Base_Game::run: Blocking in inner loop. active=%d, mode=%d\n", this->prog_active, this->prog_mode);
                last_mode = this->prog_mode;
            }
#endif
            if (GetMessageA(&msg, nullptr, 0, 0) == 0) {
                return msg.wParam;
            }
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }

#ifdef _DEBUG
        static bool loop_started = false;
        if (!loop_started) {
            printf("RGE_Base_Game::run: Outer loop active\n");
            loop_started = true;
        }
#endif

        if (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                break;
            }
#ifdef _DEBUG
            static uint last_msg = 0;
            if (msg.message != last_msg && msg.message != WM_MOUSEMOVE && msg.message != WM_PAINT) {
                printf("RGE_Base_Game::run: Msg %04X\n", msg.message);
                last_msg = msg.message;
            }
#endif
            if (this->handle_message(&msg)) {
                TranslateMessage(&msg);
                DispatchMessageA(&msg);
            }
        } else {
            this->handle_idle();
        }
    }
    return msg.wParam;
}

void RGE_Base_Game::close(HWND hwnd, uint msg, WPARAM wparam, LPARAM lparam) {
    DestroyWindow(hwnd);
}

void RGE_Base_Game::destroy(HWND hwnd, uint msg, WPARAM wparam, LPARAM lparam) {
    this->prog_active = 0;
    this->prog_ready = 0;
}

long RGE_Base_Game::wnd_proc(HWND hwnd, uint msg, WPARAM wparam, LPARAM lparam) {
    switch (msg) {
    case WM_PAINT:
        this->paint(hwnd, msg, wparam, lparam);
        return 0;
    case WM_ACTIVATEAPP:
        if (wparam) {
            this->paint_activate();
        } else {
            this->paint_deactivate();
        }
        this->activate(hwnd, msg, wparam, lparam);
        return 0;
    case WM_SIZE:
        this->size(hwnd, msg, wparam, lparam);
        return 0;
    case WM_KEYDOWN:
    case WM_SYSKEYDOWN:
        this->key_down(wparam, lparam);
        break;
    case WM_COMMAND:
        this->command(LOWORD(wparam), HIWORD(wparam));
        break;
    case WM_CLOSE:
        this->close(hwnd, msg, wparam, lparam);
        return 0;
    case WM_DESTROY:
        this->destroy(hwnd, msg, wparam, lparam);
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProcA(hwnd, msg, wparam, lparam);
}

int RGE_Base_Game::handle_message(tagMSG* msg) {
    return 1;
}

void RGE_Base_Game::paint(HWND hwnd, uint msg, WPARAM wparam, LPARAM lparam) {
#ifdef _DEBUG
    static int paint_count = 0;
    if (paint_count % 1000 == 0) {
        printf("RGE_Base_Game::paint: count=%d world=%p draw_system=%p\n", paint_count, this->world, this->draw_system);
    }
    paint_count++;
#endif
    if (this->world) {
        this->world->draw();
    }
    if (this->draw_system) {
        this->draw_system->Paint(nullptr);
    }

    if (hwnd) {
        ValidateRect(hwnd, nullptr);
    }
}

int RGE_Base_Game::handle_idle() {
#ifdef _DEBUG
    static int idle_count = 0;
    if (idle_count == 0) {
        printf("RGE_Base_Game::handle_idle: First call. ready=%d, window=%p, world=%p\n", this->prog_ready, this->prog_window, this->world);
    }
    if (idle_count % 10000 == 0) {
        printf("RGE_Base_Game::handle_idle: count=%d\n", idle_count);
    }
    idle_count++;
#endif

    if (!this->prog_ready || !this->prog_window) return 0;
    
    if (this->world) {
        this->world->update();
        this->paint((HWND)this->prog_window, 0, 0, 0);
    }
    
    return 1;
}
