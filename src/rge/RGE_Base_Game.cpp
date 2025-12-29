#include "RGE_Base_Game.h"
#include <stdio.h>
#include <string.h>
#include <io.h>  // For _findfirst
#include <new>   // REQUIRED for placement new

// --- Global Stubs (Rule 3) ---
RGE_Base_Game* rge_base_game = nullptr;
HMODULE StringTable = nullptr;
int do_draw_log = 0;
int safe_draw_log = 0;
int debugActions = 0;
FILE* actionFile = nullptr;
int do_fps_log = 0;
FILE* fps_log = nullptr;

// Globals needed for handle_idle logic
int do_restore_palette = 0;
unsigned long restore_palette_timer = 0;

// Global Window Handle
HWND AppWnd = nullptr;

// -------------------------------------------------------------------------
// Static Window Procedure Wrapper
// -------------------------------------------------------------------------
LRESULT CALLBACK RGE_Base_Game_WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    // If game instance exists, delegate
    if (rge_base_game) {
        return rge_base_game->wnd_proc(hwnd, msg, wParam, lParam);
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

// Stub for TPanelSystem needed by setup_main_window
struct TPanelSystem {
    static void DisableIME(void* sys) {}
    static void* currentPanel(void* sys) { return nullptr; }
};
extern TPanelSystem panel_system; // Defined in TRIBE_Game.cpp or similar

// Placeholder Stub Classes
struct TRegistry {
    static int RegGetInt(TRegistry* reg, int mode, const char* name) {
        // TODO: Implement TRegistry::RegGetInt
        if (strcmp(name, "Screen Size") == 0) return 800; 
        if (strcmp(name, "Rollover Text") == 0) return 1;
        if (strcmp(name, "Mouse Style") == 0) return 2;
        if (strcmp(name, "Game Speed") == 0) return 30; 
        return -1;
    }
    static void RegSetInt(TRegistry* reg, int mode, const char* name, int val) {
        // TODO: Implement TRegistry::RegSetInt
    }
};

struct DriveInformation {
    DriveInformation(void* ptr) {
        // TODO: Implement DriveInformation Constructor
    }
};

struct RGE_Game_Info {
    RGE_Game_Info(void* ptr, char* file) {
        // TODO: Implement RGE_Game_Info Constructor
    }
};

struct RGE_Scenario_File_Info {
    RGE_Scenario_File_Info(void* ptr, char* file) {
        // TODO: Implement RGE_Scenario_File_Info Constructor
    }
};

// Global Helper Stubs
unsigned long debug_timeGetTime(const char* file, int line) { return 0; }
void debug_srand(const char* file, int line, unsigned long seed) {}
void GetDXVersion(unsigned long* len, unsigned long* ver) { *len = 0x600; *ver = 0x600; } // Fake DX6

// --- RGE_Base_Game Implementation ---

RGE_Base_Game::RGE_Base_Game(RGE_Prog_Info* info, int param_2) {
    this->player_game_info = nullptr;
    this->random_game_seed = -1;
    this->random_map_seed = -1;
    this->save_random_game_seed = -1;
    this->save_random_map_seed = -1;
    this->quick_build = 0;
    
    do_draw_log = 0;
    
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

    for (int i = 0; i < 9; i++) {
        setPlayerCDAndVersion(i, 0);
        setPlayerHasCD(i, 0);
        setPlayerVersion(i, 0);
        setPlayerTeam(i, 1);
    }
    
    setPathFinding(0);
    setMpPathFinding(0);
    setNumberPlayers(4);
    setScenarioName((char*)"");
    
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
    this->save_music_file[0] = '\0';
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
    this->mouse_cursor = LoadCursorA(NULL, IDC_ARROW);
    this->font_num = 0;
    this->fonts = nullptr;
    
    GetCurrentDirectoryA(261, this->work_dir);
    strcpy(this->string_dll_name, "language.dll");
    
    this->master_obj_id = -1;
    this->terrain_id = -1;
    this->elevation_height = -1;
    this->world = nullptr;
    this->render_all = 1;
    this->brush_size = 1;
    this->timing_text[0] = '\0';
    this->frame_count = 0;
    
    for (int i = 0; i < 30; i++) {
        this->timings[i].accum_time = 0;
        this->timings[i].last_time = 0;
    }
    
    this->do_show_timings = 0;
    this->do_show_comm = 0;
    this->do_show_ai = 0;
    this->save_check_for_cd = 1;
    this->scenario_info = nullptr;
    
    for (int i = 0; i < 9; i++) {
        this->playerIDValue[i] = 0;
        this->resigned[i] = 0;
    }
    
    this->auto_paused = 0;
    this->rollover = 1;
    this->map_save_area = nullptr;
    this->game_speed = 1.0f;
    this->single_player_difficulty = 2;
    
    if (setup_registry() == 0) {
        this->error_code = 14;
        return;
    }
    
    if (setup_debugging_log() == 0) {
        this->error_code = 15;
        return;
    }
    
    if (param_2 != 0) {
        if (setup() == 0 && this->error_code == 0) {
            this->error_code = 1;
        }
    }
    
    this->display_selected_ids = 0;
}

// -------------------------------------------------------------------------
// VTABLE IMPLEMENTATION: setup()
// -------------------------------------------------------------------------
int RGE_Base_Game::setup() {
    auto fail = [&](int code) -> int {
        this->error_code = code;
        return 0;
    };

    // --- registry-driven options (matches decomp intent) ---
    // Screen Size -> sets prog_info->main_wid/hgt
    {
        int screen = TRegistry::RegGetInt(this->registry, 1, "Screen Size");
        if (screen == 800) { prog_info->main_wid = 800; prog_info->main_hgt = 600; }
        else if (screen == 0x280) { prog_info->main_wid = 0x280; prog_info->main_hgt = 0x1e0; } // 640x480
        else if (screen == 0x400) { prog_info->main_wid = 0x400; prog_info->main_hgt = 0x300; } // 1024x768
        else if (screen == 0x500) { prog_info->main_wid = 0x500; prog_info->main_hgt = 0x400; } // 1280x1024
    }

    // Rollover Text
    this->rollover = (TRegistry::RegGetInt(this->registry, 1, "Rollover Text") == 2) ? 0 : 1;

    // Mouse Style -> interface_style
    {
        int ms = TRegistry::RegGetInt(this->registry, 1, "Mouse Style");
        if (ms == 2) prog_info->interface_style = 2;
        else if (ms == 1) prog_info->interface_style = 1;
    }

    // Game Speed (registry stored int -> float)
    {
        int gs = TRegistry::RegGetInt(this->registry, 1, "Game Speed");
        if (gs != -1) this->game_speed = (float)gs * 0.01f; // matches decomp “* _DAT_...”
    }

    // Difficulty
    {
        int diff = TRegistry::RegGetInt(this->registry, 1, "Difficulty");
        if (diff != -1) this->single_player_difficulty = diff;
    }

    // Scroll speed
    {
        int scroll = TRegistry::RegGetInt(this->registry, 1, "Scroll Speed");
        if (scroll != -1 && scroll > 9 && scroll < 0xC9) {
            prog_info->mouse_scroll_interval = scroll;
            prog_info->key_scroll_interval   = scroll;
        }
    }

    // --- check empires.exe exists (decomp sets error_code=0x17 if missing) ---
    // Cleaner: GetFileAttributesA is easier than __findfirst for just existence.
    if (GetFileAttributesA("empires.exe") == INVALID_FILE_ATTRIBUTES) {
        return fail(0x17);
    }

    // --- setup_cmd_options (vtbl[25]) ---
    if (!this->setup_cmd_options()) {
        return fail(2);
    }

    // --- load base string table (language.dll by default) ---
    if (!StringTable) {
        StringTable = LoadStringDll(this->work_dir, this->string_dll_name);
    }
    if (!StringTable) {
        return fail(1);
    }

    // --- memory check (same spirit as decomp) ---
    MEMORYSTATUS ms{};
    ms.dwLength = sizeof(ms);
    GlobalMemoryStatus(&ms);

    // Decomp’s thresholds are quirky; keep a simple conservative check:
    if (ms.dwTotalVirtual < (30u * 1024u * 1024u)) { // ~30MB virtual
        return fail(0x16);
    }

    // --- interface strings/messages (vtbl[80]) ---
    this->set_interface_messages();

    // --- expiration / multi-copy checks (optional flags from prog_info) ---
    if (prog_info->check_expiration && !check_expiration()) return fail(3);
    if (prog_info->check_multi_copies && !check_multi_copies()) return fail(4);

    // --- DX check unless NODXCHECK (decomp: error_code=0x14) ---
    if (!check_prog_argument("NODXCHECK")) {
        // If you have GetDXVersion(), call it here.
        // If DX too old -> fail(0x14)
    }

    // --- disable screensaver / low power (same APIs as decomp) ---
    SystemParametersInfoA(SPI_GETSCREENSAVEACTIVE, 0, &this->screen_saver_enabled, 0);
    if (this->screen_saver_enabled) SystemParametersInfoA(SPI_SETSCREENSAVEACTIVE, 0, 0, SPIF_SENDCHANGE);

    SystemParametersInfoA(SPI_GETLOWPOWERACTIVE, 0, &this->low_power_enabled, 0);
    if (this->low_power_enabled) SystemParametersInfoA(SPI_SETLOWPOWERACTIVE, 0, 0, SPIF_SENDCHANGE);

    // --- CD check (decomp stores save_check_for_cd) ---
    this->save_check_for_cd = check_for_cd(0);

    // --- main setup chain (error codes match the decomp’s intent) ---
    if (!setup_class())           return fail(5);
    if (!setup_main_window())     return fail(6);
    if (!setup_graphics_system()) return fail(this->error_code ? this->error_code : 7);
    if (!setup_palette())         return fail(0x11);

    if (!setup_shapes())          return fail(7);
    if (!setup_map_save_area())   return fail(7);

    if (!setup_mouse())           return fail(8);
    if (!setup_sound_system())    return fail(10);
    if (!setup_chat())            return fail(0x10);
    if (!setup_comm())            return fail(9);
    if (!setup_fonts())           return fail(0x0B);
    if (!setup_sounds())          return fail(0x0C);

    if (!setup_blank_screen())    return fail(0x0D);
    if (!setup_timings())         return fail(7);

    // If you actually created a window in setup_main_window():
    if (this->prog_window) {
        this->prog_ready = 1;
        ShowWindow(this->prog_window, SW_SHOW);
        SetFocus(this->prog_window);
        mouse_on();

        this->is_timer = SetTimer((HWND)this->prog_window, 1, 0x32, nullptr);
    }

    // success
    return 1;
}


// Stubs for Virtuals
int RGE_Base_Game::setup_cmd_options() {
    // TODO: Implement setup_cmd_options
    return 1;
}

// -------------------------------------------------------------------------
// Implementation: setup_class [VTable 26]
// -------------------------------------------------------------------------
int RGE_Base_Game::setup_class() {
#ifdef _DEBUG
    printf("[RGE_Base_Game] setup_class() called\n");
#endif
    
    if (this->prog_info->prev_instance != nullptr) {
        return 1; // Already registered
    }

    WNDCLASSA cls;
    memset(&cls, 0, sizeof(WNDCLASSA));

    // Decomp logic: uses "menu_name" if available, otherwise blank/prog_name?
    // We will ensure a valid class name "RGE_Class" or prog_name is used.
    const char* className = this->prog_info->prog_name;
    if (this->prog_info->menu_name[0] != '\0') {
         // In decomp setup_class uses menu_name for lpszClassName, 
         // but setup_main_window uses prog_name for creation. 
         // We will register 'prog_name' to ensure match.
         className = this->prog_info->prog_name; 
    }

    cls.lpszClassName = className;
    cls.lpfnWndProc = RGE_Base_Game_WndProc; // Static Wrapper
    cls.hInstance = (HINSTANCE)this->prog_info->instance;
    cls.hIcon = LoadIconA((HINSTANCE)this->prog_info->instance, this->prog_info->icon_name);
    cls.hCursor = LoadCursorA(NULL, IDC_ARROW);
    cls.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    cls.lpszMenuName = NULL; // Decomp sets to 0
    cls.cbClsExtra = 0;
    cls.cbWndExtra = 0;

    if (!RegisterClassA(&cls)) {
#ifdef _DEBUG
        printf("[RGE_Base_Game] RegisterClassA failed! Error: %d\n", GetLastError());
#endif

        // TODO: this is not in the decomp
        this->error_code = 1;

        return 0;
    }

    return 1;
}


// -------------------------------------------------------------------------
// Implementation: setup_main_window [VTable 27]
// -------------------------------------------------------------------------
int RGE_Base_Game::setup_main_window() {
#ifdef _DEBUG
    printf("[RGE_Base_Game] setup_main_window() called\n");
#endif

    int screenW = GetSystemMetrics(SM_CXSCREEN);
    int screenH = GetSystemMetrics(SM_CYSCREEN);
    
    DWORD style = 0;
    int width = this->prog_info->main_wid;
    int height = this->prog_info->main_hgt;
    
    // Decomp logic for Windowed vs Fullscreen styles
    if (this->prog_info->full_screen == 0) {
        // Windowed Mode
        if (screenW != width || screenH != height) {
             style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_CLIPCHILDREN; 
             // Decomp magic number 0x2ca0000 approx matches this
        } else {
             style = WS_POPUP | WS_CLIPCHILDREN | WS_SYSMENU; // 0x82080000
        }
    } else {
        // Fullscreen
        style = WS_POPUP | WS_CLIPCHILDREN | WS_VISIBLE; 
    }

    // Adjust Window Rect to ensure client area size matches resolution
    RECT rc = { 0, 0, width, height };
    AdjustWindowRect(&rc, style, FALSE);
    int winW = rc.right - rc.left;
    int winH = rc.bottom - rc.top;

    // Centered position
    int x = (screenW - winW) / 2;
    int y = (screenH - winH) / 2;

    HWND hWnd = CreateWindowExA(
        0,
        this->prog_info->prog_name, // Class Name
        this->prog_info->prog_title, // Title
        style,
        x, y, winW, winH,
        NULL, NULL,
        (HINSTANCE)this->prog_info->instance,
        NULL
    );

    this->prog_window = hWnd;
    AppWnd = hWnd;

    if (!hWnd) {
#ifdef _DEBUG
        printf("[RGE_Base_Game] CreateWindowEx failed! Error: %d\n", GetLastError());
#endif
        return 0;
    }

    // Decomp size verification logic (simplified)
    RECT clientRect;
    GetClientRect(hWnd, &clientRect);
    if ((clientRect.right - clientRect.left) != width || (clientRect.bottom - clientRect.top) != height) {
        // Resize if mismatch
        SetWindowPos(hWnd, NULL, 0, 0, winW, winH, SWP_NOMOVE | SWP_NOZORDER);
    }

    // Show Window (if full screen, decomp forces it here)
    if (this->prog_info->full_screen) {
        ShowWindow(hWnd, this->prog_info->show_wnd_flag);
        UpdateWindow(hWnd);
        SetFocus(hWnd);
    }
    
    TPanelSystem::DisableIME(&panel_system);

    return 1;
}

int RGE_Base_Game::setup_graphics_system() {
    // TODO: Implement setup_graphics_system
    return 1;
}

int RGE_Base_Game::setup_palette() {
    // TODO: Implement setup_palette
    return 1;
}

int RGE_Base_Game::setup_mouse() {
    // TODO: Implement setup_mouse
    return 1;
}

int RGE_Base_Game::setup_chat() {
    // TODO: Implement setup_chat
    return 1;
}

int RGE_Base_Game::setup_comm() {
    // TODO: Implement setup_comm
    return 1;
}

int RGE_Base_Game::setup_sound_system() {
    // TODO: Implement setup_sound_system
    return 1;
}

int RGE_Base_Game::setup_fonts() {
    // TODO: Implement setup_fonts
    return 1;
}

int RGE_Base_Game::setup_sounds() {
    // TODO: Implement setup_sounds
    return 1;
}

int RGE_Base_Game::setup_shapes() {
    // TODO: Implement setup_shapes
    return 1;
}

int RGE_Base_Game::setup_blank_screen() {
    // TODO: Implement setup_blank_screen
    return 1;
}

int RGE_Base_Game::setup_timings() {
    // TODO: Implement setup_timings
    return 1;
}

int RGE_Base_Game::setup_map_save_area() {
    // TODO: Implement setup_map_save_area
    return 1;
}

void RGE_Base_Game::set_prog_mode() {
    // TODO: Implement set_prog_mode
}

void RGE_Base_Game::handle_size() {
    // TODO: Implement handle_size
}

void RGE_Base_Game::close() {
    // TODO: Implement close
}

// Helper Implementations
int RGE_Base_Game::check_expiration() { return 1; }
int RGE_Base_Game::check_multi_copies() { return 1; }
int RGE_Base_Game::check_for_cd(int v) { return 1; }
unsigned char RGE_Base_Game::check_prog_argument(char* arg) { return 0; }
void RGE_Base_Game::mouse_on() {
    // TODO: Implement mouse_on
}

// Previous Stubs
RGE_Base_Game::~RGE_Base_Game() {}

// -------------------------------------------------------------------------
// Implementation: run [VTable 1]
// -------------------------------------------------------------------------
int RGE_Base_Game::run() {
#ifdef _DEBUG
    printf("[RGE_Base_Game] run() loop started\n");
#endif

    MSG msg;
    int res;

    while (true) {
        // Inner Loop: Handle Paused State or Empty Queue
        while (true) {
            int is_paused = 0;
            if (this->comm_handler) {
                // TODO: TCommunications_Handler::IsPaused implementation
                // is_paused = TCommunications_Handler::IsPaused(this->comm_handler);
            }

            // If not active, or in specific modes, or paused -> Blocking Wait
            if (this->prog_active == 0 || 
               (this->prog_mode != 4 && this->prog_mode != 2) || 
               is_paused != 0) 
            {
                res = GetMessageA(&msg, NULL, 0, 0);
                if (res == 0) {
                    // WM_QUIT received
                    return (int)msg.lParam; 
                }
                TranslateMessage(&msg);
                DispatchMessageA(&msg);
            } else {
                // Active Game Loop -> Non-Blocking Peek
                res = PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE);
                if (res != 0) break; // Message found, exit inner wait loop
                
                // No message? Run Idle logic
                // [VTable 47] handle_idle()
                handle_idle();
            }
        }

        // Check for WM_QUIT (0x12)
        if (msg.message == WM_QUIT) break;

        // [VTable 46] handle_message()
        // Returns 1 if message should be dispatched, 0 if consumed
        if (handle_message(&msg)) {
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }
    }

    return (int)msg.lParam;
}

// -------------------------------------------------------------------------
// Implementation: wnd_proc [VTable 2]
// -------------------------------------------------------------------------
long RGE_Base_Game::wnd_proc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    // TODO: Implement Sound/Music message handling
    // if (this->sound_system) TSound_Driver::handle_messages(...)
    // if (this->music_system) TMusic_System::handle_messages(...)

    // TODO: Implement Panel System message handling
    // if (TPanelSystem::currentPanel(...) ...)
    
    // Main Message Dispatch (Mapped from Decomp Offsets)
    switch (msg) {
        case WM_SIZE: // 0x05
            // handle_size [57]
            handle_size(); 
            break;

        case WM_DESTROY: // 0x02
            // handle_destroy [61]
            handle_destroy();
            PostQuitMessage(0); // Essential for exiting the loop
            return 0;

        case WM_PAINT: // 0x0F
            // handle_paint [53]
            handle_paint();
            break;

        case WM_CLOSE: // 0x10
            // handle_close [60]
            handle_close();
            return 0;

        case WM_ACTIVATE: // 0x06
            // handle_activate [54]
            handle_activate();
            break;

        case WM_ACTIVATEAPP: // 0x1C
            if (wParam) {
                // Activated
                restart_sound_system(); // [42]
            } else {
                // Deactivated
                stop_sound_system(); // [41]
            }
            break;

        case WM_KEYDOWN:    // 0x100
        case WM_SYSKEYDOWN: // 0x104
            // handle_key_down [49]
            handle_key_down(); 
            break;

        case WM_COMMAND: // 0x111
            // handle_command [51]
            handle_command();
            break;

        case WM_MOUSEMOVE: // 0x200
            // handle_mouse_move [48]
            handle_mouse_move();
            break;
            
        case WM_USER: // 0x400
             // handle_user_command [50]
             handle_user_command();
             break;
             
        case WM_PALETTECHANGED: // 0x311
             // handle_palette_changed [58]
             handle_palette_changed();
             break;
             
        case WM_QUERYNEWPALETTE: // 0x30F
             // handle_query_new_palette [59]
             handle_query_new_palette();
             break;
    }

    return DefWindowProc(hWnd, msg, wParam, lParam);
}

void RGE_Base_Game::set_game_mode() {}
void RGE_Base_Game::set_player() {}

int RGE_Base_Game::get_error_code() { 
    return this->error_code; 
}

// Shared helper: loads a Win32 string resource and enforces termination rules
static inline char* load_from_module(HINSTANCE mod, long id, char* out, int outLen) {
    if (!out || outLen <= 0) return out;

    int n = 0;
    if (mod) {
        n = ::LoadStringA(mod, static_cast<UINT>(id), out, outLen);
    }

    if (n == 0) {
        out[0] = '\0';
    }
    out[outLen - 1] = '\0';
    return out;
}

// 0041c9c0
char* RGE_Base_Game::get_string(long id, char* out, int outLen) {
    // Exactly matches: LoadStringA(StringTable, id, out, outLen), then:
    // if (0) *out = '\0';
    // out[outLen - 1] = '\0';
    return load_from_module(StringTable, id, out, outLen);
}

// 0041c9a0
char* RGE_Base_Game::get_string(long id) {
    // Decomp uses global DAT_005b2168 with size 0x200.
    static char g_buf[0x200];

    // Important detail: the original calls the VIRTUAL loader through the vtable.
    // In C++, calling the virtual function directly does the same thing.
    this->get_string(id, g_buf, static_cast<int>(sizeof(g_buf)));
    return g_buf;
}

// 0041c9f0
char* RGE_Base_Game::get_string(int mode, long code, char* out, int outLen) {
    // Wrapper that calls vtable[+0x28] = get_string2(mode, code, 0, out, outLen).
    return this->get_string2(mode, code, 0, out, outLen);
}

// 0041ca10
char* RGE_Base_Game::get_string2(int mode, long code, long /*extra*/, char* out, int outLen) {
    clear(out);

    if (!out || outLen <= 0) return out;

    if (mode == 1) {
        // Maps engine/setup error codes -> localized string IDs
        switch (code) {
            case 1: case 2: case 3: case 4: case 5: case 6:
            case 0x0E: case 0x0F:
                // load 0x7d2
                return this->get_string(0x7D2, out, outLen);

            case 7: case 8: case 0x0B: case 0x0D: case 0x11:
                // load 0x7d3
                return this->get_string(0x7D3, out, outLen);

            case 9: case 0x10:
                // load 0x7d5
                return this->get_string(0x7D5, out, outLen);

            case 10: case 0x0C:
                // load 0x7d4
                return this->get_string(0x7D4, out, outLen);

            case 0x12: return this->get_string(0x7DC, out, outLen);
            case 0x13: return this->get_string(0x7DB, out, outLen);
            case 0x14: return this->get_string(0x7DD, out, outLen);
            case 0x15: return this->get_string(0x7DE, out, outLen);
            case 0x16: return this->get_string(0x7DF, out, outLen);
            case 0x17: return this->get_string(0x7E0, out, outLen);

            default:
                // If not handled, the original just falls through and returns out (empty or whatever).
                break;
        }
    }
    else if (mode == 2) {
        // mode 2: treat 'code' as a direct string resource ID
        return this->get_string(code, out, outLen);
    }

    // Always enforce termination before returning.
    force_terminate(out, outLen);
    return out;
}

void *RGE_Base_Game::get_view_panel() { return nullptr; }
void RGE_Base_Game::get_map_panel() {}
void RGE_Base_Game::new_scenario_header_13() {}
void RGE_Base_Game::new_scenario_header_14() {}
void RGE_Base_Game::new_scenario_info() {}
void RGE_Base_Game::notification() {}
void RGE_Base_Game::reset_comm() {}
void RGE_Base_Game::send_game_options() {}
void RGE_Base_Game::receive_game_options() {}
void RGE_Base_Game::gameSummary() {}
void RGE_Base_Game::processCheatCode() {}
int RGE_Base_Game::setup_music_system() { return 1; }
void RGE_Base_Game::shutdown_music_system() {}
int RGE_Base_Game::setup_registry() { return 1; }
int RGE_Base_Game::setup_debugging_log() { return 1; }
void RGE_Base_Game::stop_sound_system() {}
void RGE_Base_Game::restart_sound_system() {}
void RGE_Base_Game::stop_music_system() {}
void RGE_Base_Game::restart_music_system() {}
void RGE_Base_Game::create_world() {}

// -------------------------------------------------------------------------
// Stub: handle_message [VTable 46]
// -------------------------------------------------------------------------
int RGE_Base_Game::handle_message(MSG* msg) {
    // Default behavior: return 1 to allow DispatchMessage
    // TODO: Implement actual message filtering logic
    return 1;
}

// -------------------------------------------------------------------------
// Implementation: handle_idle [VTable 47]
// -------------------------------------------------------------------------
int RGE_Base_Game::handle_idle() {
    if (this->prog_ready != 0 && this->prog_window != nullptr) {
        
        // Palette Restoration Logic
        if (do_restore_palette != 0 && this->prog_active != 0) {
            unsigned long delay = (do_restore_palette > 5) ? 500 : 250; // 0xfa
            unsigned long now = debug_timeGetTime("basegame.cpp", 3994);
            
            if (delay <= (now - restore_palette_timer)) {
                if (this->draw_system) {
                    // TODO: TDrawSystem::ModifyPalette
                }
                do_restore_palette--;
                restore_palette_timer = debug_timeGetTime("basegame.cpp", 4004);
            }
        }

        // Sound System Update
        if (this->sound_system) {
            // TODO: TSound_Driver::handle_messages(this->sound_system, this->prog_window, 0x113, 0, 0);
        }

        // Panel System Update
        void* currentPanel = TPanelSystem::currentPanel(&panel_system);
        if (currentPanel) {
            // TODO: Call Panel Action (offset 0x4C)
            // (**(code **)(pTVar2->_padding_ + 0x4c))();
        }

        // Multiplayer Updates
        if (this->comm_handler) {
            // TODO: multiplayerGame check and ReceiveGameMessages
        }

        // Comm Display
        if (this->do_show_comm != 0) {
            show_comm(); // [VTable 77]
        }

        // AI Display
        if (this->do_show_ai != 0) {
            show_ai(); // [VTable 78]
        }

        return 1;
    }
    return 0;
}

void RGE_Base_Game::handle_mouse_move() {}
void RGE_Base_Game::handle_key_down() {}
void RGE_Base_Game::handle_user_command() {}
void RGE_Base_Game::handle_command() {}
void RGE_Base_Game::handle_music_done() {}
void RGE_Base_Game::handle_paint() {}
void RGE_Base_Game::handle_activate() {}
void RGE_Base_Game::handle_init_menu() {}
void RGE_Base_Game::handle_exit_menu() {}
void RGE_Base_Game::handle_palette_changed() {}
void RGE_Base_Game::handle_query_new_palette() {}
void RGE_Base_Game::handle_close() {}
void RGE_Base_Game::handle_destroy() {}
void RGE_Base_Game::action_update() {}
void RGE_Base_Game::action_mouse_move() {}
void RGE_Base_Game::action_key_down() {}
void RGE_Base_Game::action_user_command() {}
void RGE_Base_Game::action_command() {}
void RGE_Base_Game::action_music_done() {}
void RGE_Base_Game::action_activate() {}
void RGE_Base_Game::action_deactivate() {}
void RGE_Base_Game::action_init_menu() {}
void RGE_Base_Game::action_exit_menu() {}
void RGE_Base_Game::action_size() {}
void RGE_Base_Game::action_close() {}
void RGE_Base_Game::calc_timings() {}
void RGE_Base_Game::calc_timing_text() {}
void RGE_Base_Game::show_timings() {}
void RGE_Base_Game::show_comm() {}
void RGE_Base_Game::show_ai() {}
void RGE_Base_Game::set_interface_messages() {}

// Helper Stubs (Setters)
void RGE_Base_Game::setVersion(float v) {}
void RGE_Base_Game::setScenarioGame(int v) {}
void RGE_Base_Game::setCampaignGame(int v) {}
void RGE_Base_Game::setSavedGame(int v) {}
void RGE_Base_Game::setSinglePlayerGame(int v) {}
void RGE_Base_Game::setMultiplayerGame(int v) {}
void RGE_Base_Game::setMapSize(int w, int h, int d) {}
void RGE_Base_Game::setAllowCheatCodes(int v) {}
void RGE_Base_Game::setCheatNotification(int v) {}
void RGE_Base_Game::setFullVisibility(int v) {}
void RGE_Base_Game::setFogOfWar(int v) {}
void RGE_Base_Game::setColoredChat(int v) {}
void RGE_Base_Game::setGameDeveloperMode(int v) {}
void RGE_Base_Game::setDifficulty(int v) {}
void RGE_Base_Game::setPlayerCDAndVersion(int p, char v) {}
void RGE_Base_Game::setPlayerHasCD(int p, int v) {}
void RGE_Base_Game::setPlayerVersion(int p, char v) {}
void RGE_Base_Game::setPlayerTeam(int p, int v) {}
void RGE_Base_Game::setPathFinding(char v) {}
void RGE_Base_Game::setMpPathFinding(char v) {}
void RGE_Base_Game::setNumberPlayers(int v) {}
void RGE_Base_Game::setScenarioName(char* s) {}