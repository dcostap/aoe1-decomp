#include "../include/RGE_Base_Game.h"
#include "../include/ui_core.h"
#include "../include/TPanel.h"
#include "../include/TPanelSystem.h"
#include "../include/TRegistry.h"
#include "../include/TDebuggingLog.h"
#include "../include/TCommunications_Handler.h"
#include "../include/TMousePointer.h"
#include "../include/TChat.h"
#include "../include/TDrawSystem.h"
#include "../include/TDrawArea.h"
#include "../include/TShape.h"
#include "../include/TSound_Driver.h"
#include "../include/TMusic_System.h"
#include "../include/TDigital.h"
#include "../include/RGE_Font.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Scenario.h"
#include "../include/RGE_Scenario_Header.h"
#include "../include/RGE_Scenario_File_Info.h"
#include "../include/RGE_Game_Info.h"
#include <windows.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <timeapi.h>
#include <direct.h>

#include "../include/debug_helpers.h"

struct TPanelSystem;
extern struct TPanelSystem* panel_system;

#include "../include/globals.h"
#include "../include/custom_debug.h"

LRESULT CALLBACK rge_base_game_wnd_proc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (rge_base_game) {
        return rge_base_game->wnd_proc(hWnd, (uint)msg, (uint)wParam, (long)lParam);
    }
    return DefWindowProcA(hWnd, msg, wParam, lParam);
}

RGE_Base_Game::RGE_Base_Game(RGE_Prog_Info* info, int param_2) {
    rge_base_game = this;
    
    // ASM at 0x0041B6A0
    this->player_game_info = nullptr; // [EBP + 0x4] = 0
    this->scenario_info = nullptr;    // [EBP + 0x8] = 0
    this->random_game_seed = -1;      // [EBP + 0x28] = -1
    this->random_map_seed = -1;       // [EBP + 0x2C] = -1
    this->save_random_game_seed = -1; // [EBP + 0x30] = -1
    this->save_random_map_seed = -1;  // [EBP + 0x34] = -1
    this->quick_build = 0;            // [EBP + 0x9a8] = 0

    // Set vftable
    // *(void**)this = RGE_Base_Game::vftable;

    this->setVersion(1.0f);
    this->setScenarioGame(0);
    this->setCampaignGame(0);
    this->setSavedGame(0);
    this->setSinglePlayerGame(1);
    this->setMultiplayerGame(0);
    this->setMapSize(96, 96, 8);
    this->setAllowCheatCodes(0);
    this->setCheatNotification(1);
    this->setFullVisibility(0);
    this->setFogOfWar(1);
    this->setColoredChat(1);
    this->setGameDeveloperMode(0);
    this->setDifficulty(0);

    for (int i = 0; i < 9; i++) {
        this->setPlayerCDAndVersion(i, 0);
        this->setPlayerHasCD(i, 0);
        this->setPlayerVersion(i, 0);
        this->setPlayerTeam(i, 1);
    }

    this->setPathFinding(0);
    this->setMpPathFinding(0);
    this->setNumberPlayers(4);
    this->setScenarioName("");

    this->prog_info = info;
    this->prog_window = nullptr;
    this->prog_ready = 0; // ASM 0x0041b7b9
    this->prog_active = 0;
    this->prog_palette = nullptr;
    this->prog_mutex = nullptr;
    
    StringTable = nullptr;
    
    this->is_timer = 0; // +0x44
    this->draw_system = nullptr; // +0x48
    this->draw_area = nullptr; // +0x4C
    this->outline_type = 2; // +0x50
    this->custom_mouse = 0; // +0x54
    this->shape_num = 0; // +0x58
    this->shapes = nullptr; // +0x5C
    this->sound_system = nullptr; // +0x60
    this->music_system = nullptr; // +0x64
    this->sound_num = 0; // +0x68
    this->sounds = nullptr; // +0x6C
    this->save_music_type = 0; // +0x70
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
    this->mouse_cursor = LoadCursorA(NULL, (LPCSTR)IDC_ARROW);
    this->font_num = 0;
    this->fonts = nullptr;
    
    GetCurrentDirectoryA(sizeof(this->work_dir), this->work_dir);
    strcpy(this->string_dll_name, "language.dll");
    
    this->master_obj_id = -1;
    this->terrain_id = -1;
    this->elevation_height = -1;
    this->world = nullptr;
    this->render_all = 1;
    this->brush_size = 1;
    this->timing_text[0] = '\0';
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

    for (int i = 0; i < 30; i++) {
        memset(&this->timings[i], 0, sizeof(RGE_Timing_Info));
    }

    this->do_show_timings = 0;
    this->do_show_comm = 0;
    this->do_show_ai = 0;
    this->save_check_for_cd = 1; // +0x9ac
    
    AppInst = this->prog_info ? (HINSTANCE)this->prog_info->instance : nullptr;
    AppWnd = nullptr;
    chat = nullptr;
    comm = nullptr;
    Regs = nullptr;
    sound_driver = nullptr;
    driveInfo = nullptr;
    
    for (int i = 0; i < 9; i++) {
        this->playerIDValue[i] = 0;
        this->resigned[i] = 0;
    }
    
    this->auto_paused = 0;
    this->rollover = 1;
    this->map_save_area = nullptr;
    this->game_speed = 1.0f;
    this->single_player_difficulty = 2;

    // Registry and Debug log setup
    if (this->setup_registry()) {
        Regs = this->registry; 
        if (this->setup_debugging_log()) {
            if (param_2 && this->setup() == 0) {
                if (this->error_code == 0) {
                    this->error_code = 1;
                }
            }
        } else {
            this->error_code = 15;
        }
    } else {
        this->error_code = 14;
    }
}

RGE_Base_Game::~RGE_Base_Game() {
    // Source of truth: basegame.cpp.decomp @ destructor
    CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG("RGE_Base_Game::~RGE_Base_Game: destructor start");
    CUSTOM_DEBUG_END

    // Save settings to registry before cleanup
    if (this->registry && this->draw_system) {
        this->registry->RegSetInt(1, "Screen Size", this->draw_system->ScreenWidth);
    }
    if (this->registry) {
        this->registry->RegSetInt(1, "Rollover Text", 2 - (this->rollover != 0 ? 1 : 0));
        int mouse_style = (this->prog_info && this->prog_info->interface_style == 2) ? 2 : 1;
        this->registry->RegSetInt(1, "Mouse Style", mouse_style);
        this->registry->RegSetInt(1, "Difficulty", this->single_player_difficulty);
        if (this->prog_info) {
            this->registry->RegSetInt(1, "Scroll Speed", this->prog_info->mouse_scroll_interval);
        }
    }

    // Close log files
    if (actionFile != nullptr) {
        fclose(actionFile);
        actionFile = nullptr;
    }
    // fps_log close skipped — not declared as global yet
    if (draw_log != nullptr) {
        fclose(draw_log);
        draw_log = nullptr;
    }

    // Delete scenario info
    if (this->scenario_info != nullptr) {
        delete this->scenario_info;
        this->scenario_info = nullptr;
    }

    // Delete player game info
    if (this->player_game_info != nullptr) {
        delete this->player_game_info;
        this->player_game_info = nullptr;
    }

    this->prog_mode = 0;

    // Delete world
    if (this->world != nullptr) {
        CUSTOM_DEBUG_LOG("RGE_Base_Game dtor: deleting world");
        delete this->world;
        this->world = nullptr;
    }

    // Delete map save area
    if (this->map_save_area != nullptr) {
        delete this->map_save_area;
        this->map_save_area = nullptr;
    }

    // Delete mouse pointer
    if (this->mouse_pointer != nullptr) {
        delete this->mouse_pointer;
        this->mouse_pointer = nullptr;
    }

    // Delete drive info
    if (driveInfo != nullptr) {
        free(driveInfo);
        driveInfo = nullptr;
    }

    // Delete comm handler
    if (this->comm_handler != nullptr) {
        delete this->comm_handler;
        this->comm_handler = nullptr;
    }

    // Delete chat
    if (chat != nullptr) {
        delete chat;
        chat = nullptr;
    }

    // Delete fonts
    if (this->fonts != nullptr) {
        for (int i = 0; i < this->font_num; i++) {
            if (this->fonts[i].font != nullptr) {
                DeleteObject(this->fonts[i].font);
            }
        }
        free(this->fonts);
        this->fonts = nullptr;
    }

    // Stop sound system
    this->stop_sound_system();

    // Delete sounds array
    if (this->sounds != nullptr) {
        for (int i = 0; i < this->sound_num; i++) {
            if (this->sounds[i] != nullptr) {
                delete this->sounds[i];
                this->sounds[i] = nullptr;
            }
        }
        free(this->sounds);
        this->sounds = nullptr;
    }

    // Delete sound system
    if (this->sound_system != nullptr) {
        delete this->sound_system;
        this->sound_system = nullptr;
        sound_driver = nullptr;
    }

    // Delete music system
    if (this->music_system != nullptr) {
        delete this->music_system;
        this->music_system = nullptr;
    }

    // Destroy blank screen
    if (panel_system) {
        panel_system->destroyPanel((char*)"Blank Screen");
    }

    // Delete draw system
    if (this->draw_system != nullptr) {
        CUSTOM_DEBUG_LOG("RGE_Base_Game dtor: deleting draw system");
        delete this->draw_system;
        this->draw_system = nullptr;
        this->draw_area = nullptr;
    }

    // Restore system parameters
    if (this->screen_saver_enabled != 0) {
        SystemParametersInfoA(0x11, 1, NULL, 2); // SPI_SETSCREENSAVEACTIVE
    }
    if (this->low_power_enabled != 0) {
        SystemParametersInfoA(0x55, 1, NULL, 2); // SPI_SETLOWPOWERACTIVE
    }

    // Release palette
    if (this->prog_palette != nullptr) {
        if (panel_system) {
            panel_system->release_palette(this->prog_palette);
        }
        this->prog_palette = nullptr;
    }

    // Delete registry
    if (this->registry != nullptr) {
        delete this->registry;
        this->registry = nullptr;
    }

    // Close mutex
    if (this->prog_mutex != nullptr) {
        CloseHandle(this->prog_mutex);
        this->prog_mutex = nullptr;
    }

    rge_base_game = nullptr;

    // Destroy window
    if (this->prog_window != nullptr) {
        CUSTOM_DEBUG_LOG("RGE_Base_Game dtor: destroying window");
        DestroyWindow((HWND)this->prog_window);
    }

    // Free string table
    if (StringTable != nullptr && StringTable != this->prog_info->instance) {
        FreeLibrary(StringTable);
        StringTable = nullptr;
    }

    // Delete debug log
    if (this->debugLog != nullptr) {
        delete this->debugLog;
        this->debugLog = nullptr;
    }

    // Delete shapes
    if (this->shapes != nullptr) {
        for (int i = 0; i < this->shape_num; i++) {
            if (this->shapes[i] != nullptr) {
                delete this->shapes[i];
            }
        }
        free(this->shapes);
        this->shapes = nullptr;
    }

    // Delete panel system
    if (panel_system) {
        CUSTOM_DEBUG_LOG("RGE_Base_Game dtor: deleting panel system");
        delete panel_system;
        panel_system = nullptr;
    }

    CUSTOM_DEBUG_LOG("RGE_Base_Game::~RGE_Base_Game: destructor end");
}

// Stubs for now
void RGE_Base_Game::setVersion(float p1) { rge_game_options.versionValue = p1; }
void RGE_Base_Game::setScenarioGame(int p1) { rge_game_options.scenarioGameValue = p1; }
void RGE_Base_Game::setCampaignGame(int p1) { campaignGameValue = p1; } 
void RGE_Base_Game::setSavedGame(int p1) { savedGameValue = p1; }
void RGE_Base_Game::setSinglePlayerGame(int p1) { rge_game_options.singlePlayerGameValue = p1; }
void RGE_Base_Game::setMultiplayerGame(int p1) { rge_game_options.multiplayerGameValue = p1; }
void RGE_Base_Game::setMapSize(int p1, int p2, int p3) { 
    rge_game_options.mapXSizeValue = p1; 
    rge_game_options.mapYSizeValue = p2; 
    rge_game_options.mapZSizeValue = p3; 
}
void RGE_Base_Game::setAllowCheatCodes(int p1) { rge_game_options.allowCheatCodesValue = p1; }
void RGE_Base_Game::setCheatNotification(int p1) { rge_game_options.cheatNotificationValue = p1; }
void RGE_Base_Game::setFullVisibility(int p1) { rge_game_options.fullVisibilityValue = p1; }
void RGE_Base_Game::setFogOfWar(int p1) { rge_game_options.fogOfWarValue = p1; }
void RGE_Base_Game::setColoredChat(int p1) { rge_game_options.coloredChatValue = p1; }
void RGE_Base_Game::setGameDeveloperMode(int p1) { rge_game_options.gameDeveloperModeValue = p1; }
void RGE_Base_Game::setDifficulty(int p1) { rge_game_options.difficultyValue = p1; }
void RGE_Base_Game::setPlayerCDAndVersion(int p1, int p2) { rge_game_options.playerCDAndVersionValue[p1] = p2; }
void RGE_Base_Game::setPlayerHasCD(int p1, int p2) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422800
    uchar value = rge_game_options.playerCDAndVersionValue[p1];
    value = (uchar)((value & 0xFE) | (uchar)p2);
    rge_game_options.playerCDAndVersionValue[p1] = value;
}
void RGE_Base_Game::setPlayerVersion(int p1, int p2) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422820
    uchar value = rge_game_options.playerCDAndVersionValue[p1];
    value = (uchar)(((uchar)p2 << 1) | (value & 0x01));
    rge_game_options.playerCDAndVersionValue[p1] = value;
}
void RGE_Base_Game::setPlayerTeam(int p1, int p2) { rge_game_options.playerTeamValue[p1] = p2; }
void RGE_Base_Game::setPathFinding(unsigned char p1) { pathFindingValue = p1; }
void RGE_Base_Game::setMpPathFinding(unsigned char p1) { rge_game_options.mpPathFindingValue = p1; }
void RGE_Base_Game::setNumberPlayers(int p1) { rge_game_options.numberPlayersValue = p1; }
void RGE_Base_Game::setScenarioName(char* p1) { strncpy(rge_game_options.scenarioNameValue, p1, 127); }

int RGE_Base_Game::setup_registry() {
    if (this->prog_info) {
        this->registry = new TRegistry(this->prog_info->registry_key);
        return (this->registry != NULL);
    }
    return 0;
}

int RGE_Base_Game::setup_debugging_log() {
    this->debugLog = new TDebuggingLog();
    if (this->debugLog) {
        this->debugLog->LogFile(this->log_comm);
        this->debugLog->LogOutput(log_output);
        this->debugLog->LogTimestamp(1);
        return 1;
    }
    return 0;
}

int RGE_Base_Game::setup() {
    // ASM order: srand -> registry -> empires.exe check -> cmd_options -> language.dll -> memory check
    //            -> music -> expiration -> multi_copies -> DX version -> system params -> setup chain

CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_FUNC_ENTER();
CUSTOM_DEBUG_END

    // Random seed initialization (ASM 0x0041bacb)
    debug_srand("C:\\msdev\\work\\age1_x1\\basegame.cpp", 522, debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 522));

    // Registry settings
    if (this->registry) {
        int screen_size = this->registry->RegGetInt(1, "Screen Size");
        if (screen_size == 640) {
            this->prog_info->main_wid = 640;
            this->prog_info->main_hgt = 480;
        } else if (screen_size == 800) {
            this->prog_info->main_wid = 800;
            this->prog_info->main_hgt = 600;
        } else if (screen_size == 1024) {
            this->prog_info->main_wid = 1024;
            this->prog_info->main_hgt = 768;
        } else if (screen_size == 1280) {
            this->prog_info->main_wid = 1280;
            this->prog_info->main_hgt = 1024;
        }

        this->rollover = this->registry->RegGetInt(1, "Rollover Text") != 2;
        
        int interface_style_reg = this->registry->RegGetInt(1, "Mouse Style");
        if (interface_style_reg == 2) {
            this->prog_info->interface_style = 2;
        } else if (interface_style_reg == 1) {
            this->prog_info->interface_style = 1;
        }

        int game_speed_reg = this->registry->RegGetInt(1, "Game Speed");
        if (game_speed_reg != -1) {
            this->game_speed = (float)game_speed_reg * 0.01f;
        }

        int difficulty_reg = this->registry->RegGetInt(1, "Difficulty");
        if (difficulty_reg != -1) {
            this->single_player_difficulty = difficulty_reg;
        }

        int pf_reg = this->registry->RegGetInt(1, "Path Finding");
        if (pf_reg >= 1 && pf_reg <= 3) {
            this->setPathFinding((unsigned char)(pf_reg - 1));
        }

        int mp_pf_reg = this->registry->RegGetInt(1, "MP Path Finding");
        if (mp_pf_reg >= 1 && mp_pf_reg <= 3) {
            this->setMpPathFinding((unsigned char)(mp_pf_reg - 1));
        }

        int scroll_speed = this->registry->RegGetInt(1, "Scroll Speed");
        if (scroll_speed != -1 && scroll_speed >= 10 && scroll_speed <= 200) {
            this->prog_info->mouse_scroll_interval = scroll_speed;
            this->prog_info->key_scroll_interval = scroll_speed;
        }
    }

    // Check if empires.exe exists (minimal version check)
    // NOTE: Also accept empiresx.exe for decompiled version
    struct _finddata_t file_info;
    if (_findfirst("empires.exe", &file_info) == -1 &&
        _findfirst("empiresx.exe", &file_info) == -1) {
CUSTOM_DEBUG_BEGIN
        char cwd[260];
        _getcwd(cwd, sizeof(cwd));
        CUSTOM_DEBUG_LOG_FMT("Failed empires.exe check. CWD: %s", cwd);
CUSTOM_DEBUG_END
        this->error_code = 0x17;
        return 0;
    }

    // Call setup_cmd_options (offset 0x64 in vtable)
    if (!this->setup_cmd_options()) {
        this->error_code = 0;
        return 0;
    }

    // Source of truth: `basegame.cpp.decomp` loads exactly `this->string_dll_name`.
    StringTable = LoadLibraryA(this->string_dll_name);
    if (!StringTable) {
        this->error_code = 1;
        return 0;
    }

    // Check Memory
    MEMORYSTATUS memStatus;
    GlobalMemoryStatus(&memStatus);
    // 0x1400000 = 20MB, 0xa00000 = 10MB
    if (memStatus.dwTotalPhys < 0xa00000) {
        this->error_code = 0x14; // TODO: verify code
        return 0;
    }

    // Music setup
    if (!this->setup_music_system()) {
        // ...
    }

    // Expiration check (ASM 0x0041bd56)
    if (this->prog_info->check_expiration && !this->check_expiration()) {
        this->error_code = 3;
        return 0;
    }

    // Multi-copy check (ASM 0x0041bd7a) - NOTE: this is after expiration check per ASM order
    if (this->prog_info->check_multi_copies && !this->check_multi_copies()) {
        this->error_code = 4;
        return 0;
    }

    // DX Version check (ASM 0x0041bd9e-0x0041bdd2)
    extern void GetDXVersion(unsigned long*, unsigned long*);
    if (!this->check_prog_argument("NODXCHECK")) {
        unsigned long dx_version, dx_platform;
        GetDXVersion(&dx_version, &dx_platform);
        if (dx_version < 0x501) {
            this->error_code = 0x14;
            return 0;
        }
    }

    // System Parameter updates (ASM 0x0041bdd7)
    SystemParametersInfoA(SPI_GETMOUSE, 0, &this->screen_saver_enabled, 0); // ESI + 0x38
    if (this->screen_saver_enabled != 0) {
        SystemParametersInfoA(SPI_SETMOUSE, 0, &this->screen_saver_enabled, 0);
    }
    SystemParametersInfoA(SPI_GETSCREENSAVEACTIVE, 0, &this->low_power_enabled, 0); // ESI + 0x3C
    if (this->low_power_enabled != 0) {
        SystemParametersInfoA(SPI_SETSCREENSAVEACTIVE, 0, &this->low_power_enabled, 0);
    }

    // CD check (ASM 0x0041be15)
    this->save_check_for_cd = this->check_for_cd(0); // ESI + 0x9AC

    // Initialization sequence
    if (!panel_system) {
        panel_system = new TPanelSystem;
        memset(panel_system, 0, sizeof(TPanelSystem));
        panel_system->InputEnabled = 1;
        panel_system->ImeEnabled = 1;
    }

    if (!this->setup_class()) {
        this->error_code = 5;
        return 0;
    }

    if (!this->setup_main_window()) {
        this->error_code = 6;
        return 0;
    }

    if (!this->setup_graphics_system()) {
        if (this->error_code == 0) this->error_code = 7;
        return 0;
    }

    // Sync prog_info if fullscreen fell back to windowed inside Init
    if (this->draw_system && this->draw_system->ScreenMode == 1 &&
        this->prog_info->full_screen != 0) {
        this->prog_info->full_screen = 0;
    }

    if (!this->setup_palette()) {
        this->error_code = 0x11;
        return 0;
    }

    if (!this->setup_shapes()) {
        this->error_code = 7;
        return 0;
    }

    if (!this->setup_map_save_area()) {
        this->error_code = 7;
        return 0;
    }

    if (!this->setup_mouse()) {
        this->error_code = 8;
        return 0;
    }

    if (!this->setup_sound_system()) {
        this->error_code = 0xa;
        return 0;
    }

    if (!this->setup_chat()) {
        this->error_code = 0x10;
        return 0;
    }

    if (!this->setup_comm()) {
        this->error_code = 9;
        return 0;
    }

    if (!this->setup_fonts()) {
        this->error_code = 0xb;
        return 0;
    }

    if (!this->setup_sounds()) {
        this->error_code = 0xc;
        return 0;
    }

    if (this->scenario_info == nullptr) {
        char scenario_info_file[300];
        sprintf(scenario_info_file, "%sscenario.inf", this->prog_info->scenario_dir);
        this->scenario_info = new RGE_Scenario_File_Info(scenario_info_file);
    }

    // Drive Info (ASM 0x0041bf40) - TODO: implement DriveInformation class
    // driveInfo = new DriveInformation();
    
    if (!this->setup_blank_screen()) { // vtable offset 0x9c (index 39)
        this->error_code = 0xd;
        return 0;
    }

    this->set_prog_mode(0); // vtable offset 0xc (index 3)
    this->setup_timings();

    this->handle_size((void*)this->prog_window, WM_SIZE, 0, 0);

    ShowWindow((HWND)this->prog_window, SW_SHOW);
    SetFocus((HWND)this->prog_window);

    this->mouse_on();

    this->is_timer = SetTimer((HWND)this->prog_window, 1, 0, NULL);

    return 1;
}

int RGE_Base_Game::check_for_cd(int p1) {
    // TODO: implement logic from 0x0041FD40
    return 1;
}

void RGE_Base_Game::set_mouse_cursor(void* p1) {
    // Source of truth: `src/game/src/basegame.cpp.decomp` (`set_mouse_cursor` @ 0x00420500).
    this->mouse_cursor = p1;

    if ((this->is_mouse_on != 0) && ((this->custom_mouse == 0) || (this->windows_mouse != 0))) {
        SetCursor((HCURSOR)this->mouse_cursor);
        SetClassLongA((HWND)this->prog_window, GCL_HCURSOR, (LONG)this->mouse_cursor);
    }
}

void RGE_Base_Game::set_mouse_facet(long p1) {
    // Source of truth: `src/game/src/basegame.cpp.decomp` (`set_mouse_facet` @ 0x00420560).
    if (this->mouse_pointer) {
        this->mouse_pointer->set_facet((int)p1);
    }
}

void RGE_Base_Game::disable_input() {
    // Source of truth: `src/game/src/basegame.cpp.decomp` (`disable_input` @ 0x00422A50).
    if (this->is_mouse_on != 0) {
        this->set_mouse_cursor(LoadCursorA(NULL, IDC_WAIT));
    }

    if (panel_system) {
        panel_system->InputEnabled = 0;
    }
    this->input_enabled = 0;

    if (this->input_disabled_window != nullptr) {
        if (GetCapture() != NULL) {
            ReleaseCapture();
        }
        SetCapture((HWND)this->input_disabled_window);
    }
}

void RGE_Base_Game::enable_input() {
    // Source of truth: `src/game/src/basegame.cpp.decomp` (`enable_input` @ 0x00422AB0).
    if (this->input_disabled_window != nullptr) {
        if (GetCapture() != NULL) {
            ReleaseCapture();
        }
    }

    if (panel_system) {
        panel_system->InputEnabled = 1;
    }
    this->input_enabled = 1;

    if (this->is_mouse_on != 0) {
        this->set_mouse_cursor(LoadCursorA(NULL, IDC_ARROW));
    }
}

void RGE_Base_Game::mouse_on() {
    if (this->is_mouse_on == 0) {
        if ((this->custom_mouse != 0) && (this->windows_mouse == 0)) {
            if (this->mouse_pointer) {
                this->mouse_pointer->on();
            }
            this->is_mouse_on = 1;
            return;
        }
        SetCursor((HCURSOR)this->mouse_cursor);
        SetClassLongA((HWND)this->prog_window, GCL_HCURSOR, (LONG)this->mouse_cursor);
        this->is_mouse_on = 1;
    }
}

void RGE_Base_Game::mouse_off() {
    if (this->is_mouse_on != 0) {
        if ((this->custom_mouse != 0) && (this->windows_mouse == 0)) {
            if (this->mouse_pointer) {
                this->mouse_pointer->off();
            }
            this->is_mouse_on = 0;
            return;
        }
        SetCursor(NULL);
        SetClassLongA((HWND)this->prog_window, GCL_HCURSOR, 0);
        this->is_mouse_on = 0;
    }
}
int RGE_Base_Game::get_error_code() { 
    return this->error_code; 
}
char* RGE_Base_Game::get_string(int p1, long p2, char* p3, int p4) { 
    if (StringTable) {
        if (LoadStringA(StringTable, p1, p3, p4) > 0) {
            return p3;
        }
    }
    if (p4 > 0) p3[0] = '\0';
    return p3;
}
char* RGE_Base_Game::get_string2(int p1, long p2, long p3, char* p4, int p5) { return p4; }
unsigned char RGE_Base_Game::check_prog_argument(const char* p1) {
    // Source of truth: basegame.cpp.decomp @ 0x00422CC0
    if (!this->prog_info || !this->prog_info->cmd_line || !p1) return 0;
    char cmd_line[256];
    strncpy(cmd_line, this->prog_info->cmd_line, 255);
    cmd_line[255] = '\0';
    CharUpperA(cmd_line);
    return (strstr(cmd_line, p1) != nullptr) ? 1 : 0;
}
void RGE_Base_Game::close() {
    if (this->prog_window) {
        SendMessageA((HWND)this->prog_window, WM_CLOSE, 0, 0);
    }
}

int RGE_Base_Game::check_expiration() { return 1; }
int RGE_Base_Game::check_multi_copies() { return 1; }

// Source of truth: basegame.cpp.decomp @ 0x004206D0
long RGE_Base_Game::wnd_proc(void* p1, uint p2, uint p3, long p4) { 
    // p1=HWND, p2=message, p3=wParam, p4=lParam
    long result = 0;

    CUSTOM_DEBUG_BEGIN
    if (p2 == WM_CLOSE) {
        CUSTOM_DEBUG_LOG("RGE_Base_Game::wnd_proc: received WM_CLOSE");
    } else if (p2 == WM_DESTROY) {
        CUSTOM_DEBUG_LOG("RGE_Base_Game::wnd_proc: received WM_DESTROY");
    } else if (p2 == WM_QUIT) {
        CUSTOM_DEBUG_LOG("RGE_Base_Game::wnd_proc: received WM_QUIT");
    }
    CUSTOM_DEBUG_END

    // Forward messages to sound and music systems
    if (this->sound_system != nullptr) {
        this->sound_system->handle_messages(p1, p2, p3, p4);
    }
    if (this->music_system != nullptr) {
        this->music_system->handle_messages(p1, p2, p3, p4);
    }

    // Route through currentPanel first
    TPanel* curPanel = nullptr;
    if (panel_system) {
        curPanel = panel_system->currentPanelValue;
    }

    if (curPanel != nullptr) {
        result = curPanel->wnd_proc(p1, p2, p3, p4);
        // If panel consumed the message AND it's not WM_MOUSEMOVE or WM_TIMER,
        // return the result directly (decomp: goto LAB_004207c2 only if result==0 or msg==0x200 or msg==0x113)
        if (result != 0 && p2 != 0x200 && p2 != 0x113) {
            return result;
        }
    }

    // Big message switch (decomp @ LAB_004207c2)
    int iVar3;
    switch (p2) {
        case WM_DESTROY: // 0x02
            iVar3 = this->handle_destroy(p1, p2, p3, p4);
            if (iVar3 == 0) return 0;
            break;

        case WM_SIZE: // 0x05
            if (system_ignore_size_messages != 0) break;
            iVar3 = this->handle_size(p1, p2, p3, p4);
            if (iVar3 == 0) return 0;
            break;

        case WM_PAINT: // 0x0F
            iVar3 = this->handle_paint(p1, p2, p3, p4);
            if (iVar3 == 0) return 0;
            break;

        case WM_CLOSE: // 0x10
            iVar3 = this->handle_close(p1, p2, p3, p4);
            if (iVar3 == 0) return 0;
            break;

        case WM_ACTIVATEAPP: // 0x1C
            // Decomp: complex activate/deactivate with surface restoration
            if (this->prog_active != 0) {
                if ((long)p3 == 1) {
                    // Activating
                    if (this->draw_system != nullptr) {
                        this->draw_system->CheckSurfaces();
                        this->draw_system->ClearRestored();
                    }
                    this->render_all = 1;
                    if (this->draw_system != nullptr) {
                        this->draw_system->ClearPrimarySurface();
                        this->draw_system->ModifyPalette(0, 0x100, this->draw_system->palette);
                    }
                    this->render_all = 1;
                    InvalidateRect((HWND)this->prog_window, NULL, 1);
                    do_restore_palette = 10;
                    restore_palette_timer = debug_timeGetTime("basegame.cpp", 0xe9b);
                    restore_mouse_after_paint = 1;
                } else {
                    // Deactivating
                    SetClassLongA((HWND)this->prog_window, GCL_HCURSOR, 0);
                }
            }
            iVar3 = this->handle_activate(p1, 0x1c, p3, p4);
            if (iVar3 == 0) return 0;
            break;

        case WM_SETCURSOR: // 0x20
            if (this->is_mouse_on && this->windows_mouse == 0) {
                SetCursor(NULL);
                return 1;
            }
            break;

        case WM_KEYDOWN: // 0x100
        case 0x104:      // WM_SYSKEYDOWN
            iVar3 = this->handle_key_down(p1, p2, p3, p4);
            if (iVar3 == 0) return 0;
            break;

        case 0x105: // WM_SYSKEYUP — Alt key release handling
            if (p3 == 0x12 && panel_system != nullptr) {
                TPanel* cp = panel_system->currentPanelValue;
                if (cp != nullptr) {
                    cp->handle_key_down(p3, 0, 0, 1, 0);
                }
            }
            break;

        case WM_COMMAND: // 0x111
            iVar3 = this->handle_command(p1, p2, p3, p4);
            if (iVar3 == 0) return 0;
            break;

        case WM_SYSCOMMAND: // 0x112
            // Block SC_KEYMENU (Alt+key) if full-screen to prevent menu activation
            if (p3 == 0xf100 && this->prog_info != nullptr &&
                this->prog_info->full_screen != 0) {
                if (!IsIconic((HWND)this->prog_window)) {
                    return 0;
                }
            }
            break;

        case WM_TIMER: // 0x113
            this->handle_idle();
            break;

        case 0x200: // WM_MOUSEMOVE
            iVar3 = this->handle_mouse_move(p1, p2, p3, p4);
            if (iVar3 == 0) return 0;
            break;

        case 0x212: // WM_EXITMENULOOP
            iVar3 = this->handle_exit_menu(p1, p2, p3, p4);
            if (iVar3 == 0) return 0;
            break;

        case 0x218: // WM_POWERBROADCAST
            if (p3 == 0) {
                return 0x424d5144; // "DMBQ" — deny power suspend
            }
            break;

        case 0x30f: // WM_QUERYNEWPALETTE
            iVar3 = this->handle_query_new_palette(p1, p2, p3, p4);
            if (iVar3 != 0) {
                // Fall through to handle_close path per decomp (goto LAB_00420dc9)
                iVar3 = this->handle_close(p1, p2, p3, p4);
                if (iVar3 == 0) return 0;
            }
            break;

        case 0x311: // WM_PALETTECHANGED
            iVar3 = this->handle_palette_changed(p1, p2, p3, p4);
            if (iVar3 == 0) return 0;
            break;

        case 0x3b9: // MM_MCINOTIFY
        case 0x500: // Custom music message
            iVar3 = this->handle_music_done(p1, p2, p3, p4);
            if (iVar3 == 0) return 0;
            break;

        case 0x400: // WM_USER
            iVar3 = this->handle_user_command(p1, p2, p3, p4);
            if (iVar3 == 0) return 0;
            break;
    }

    return DefWindowProcA((HWND)p1, p2, p3, p4); 
}
void RGE_Base_Game::set_prog_mode(int p1) {
    this->prog_mode = p1;
}
void RGE_Base_Game::set_game_mode(int p1, int p2) {
    this->game_mode = p1;
    this->sub_game_mode = p2;
}
void RGE_Base_Game::set_player(short p1) {
    // ASM 0x00420150: Sets world->curr_player and clears map view info
    // NOTE: From basegame.cpp.asm analysis, this checks player_num before assignment
    if (this->world) {
        // ASM shows this writes to [world + 0x7C] which is curr_player
        this->world->curr_player = p1;
        if (this->world->map) {
            // TODO: implement clear_map_view_info when RGE_Map is available
            // this->world->map->clear_map_view_info();
        }
    }
}
char* RGE_Base_Game::get_string(long p1, char* p2, int p3) { 
    if (StringTable) {
        if (LoadStringA(StringTable, p1, p2, p3) > 0) {
            return p2;
        }
    }
    if (p3 > 0) p2[0] = '\0';
    return p2; 
}
char* RGE_Base_Game::get_string(long p1) {
    // Source of truth: basegame.cpp.decomp @ 0x0041C9A0
    // Loads string into a static buffer and returns it.
    static char static_string_buf[512];
    this->get_string(p1, static_string_buf, sizeof(static_string_buf));
    return static_string_buf;
}
int RGE_Base_Game::get_paused() {
    if (this->prog_mode == 7) {
        return 1;
    }
    if (this->comm_handler) {
        return this->comm_handler->IsPaused();
    }
    return 0;
}

RGE_Player* RGE_Base_Game::get_player() {
    // Fully verified. Source of truth: basegame.cpp.asm @ 0x00420330
    if (this->world == nullptr) {
        return nullptr;
    }
    if (this->world->player_num == 0) {
        return nullptr;
    }
    if (this->world->curr_player >= this->world->player_num) {
        return nullptr;
    }
    return this->world->players[this->world->curr_player];
}

TPanel* RGE_Base_Game::get_view_panel() { return nullptr; }
TPanel* RGE_Base_Game::get_map_panel() { return nullptr; }
RGE_Scenario_Header* RGE_Base_Game::new_scenario_header(RGE_Scenario* p1) { return new RGE_Scenario_Header(p1); }
RGE_Scenario_Header* RGE_Base_Game::new_scenario_header(int p1) { return new RGE_Scenario_Header(p1); }
RGE_Scenario* RGE_Base_Game::new_scenario_info(int p1) { return nullptr; }
void RGE_Base_Game::notification(int p1, long p2, long p3, long p4, long p5) {}
int RGE_Base_Game::reset_comm() {
    // Source of truth: basegame.cpp.decomp @ 0x0041EFF0
    // Tear down existing comm object, then re-run setup_comm() via virtual dispatch.
    if (this->comm_handler != nullptr) {
        delete this->comm_handler;
        this->comm_handler = nullptr;
        comm = nullptr;
    }
    return this->setup_comm();
}
void RGE_Base_Game::send_game_options() {}
void RGE_Base_Game::receive_game_options() {}
char* RGE_Base_Game::gameSummary() { return nullptr; }
int RGE_Base_Game::processCheatCode(int p1, char* p2) { return 0; }
int RGE_Base_Game::setup_music_system() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041F110
    // Offset: 0x0041F110
    if (this->prog_info->use_music != 0) {
        int vol = -5000;
        if (this->registry != nullptr) {
            int regVal = this->registry->RegGetInt(1, "Music Volume");
            if (regVal != -1) {
                vol = -regVal;
            }
        }
        // If volume is too low, disable music
        if (vol < -9899) {
            this->prog_info->use_music = 0;
            if (this->music_system != nullptr) {
                delete this->music_system;
                this->music_system = nullptr;
            }
        }
        else if (this->music_system == nullptr) {
            // Determine music type
            uchar mtype;
            if (this->prog_info->use_cd_audio != 0) {
                mtype = 1;
            } else if (this->prog_info->use_midi != 0) {
                mtype = 2;
            } else if (this->prog_info->use_ima != 0) {
                mtype = 4;
            } else {
                mtype = (this->prog_info->use_wave_music != 0) ? 3 : 1;
            }

            char music_path[260];
            sprintf(music_path, "%s\\%s", this->work_dir, this->prog_info->sounds_dir);

            TMusic_System* pMusic = new TMusic_System(mtype, this->prog_info->instance,
                this->prog_window, this->sound_system, music_path);
            this->music_system = pMusic;

            // If CD was chosen but isn't available, fallback to MIDI then WAV
            if (pMusic != nullptr && mtype == 1 &&
                this->prog_info->use_cd_audio == 0 &&
                (pMusic->device_open == 0 || pMusic->track_count < 2)) {
                if (pMusic->set_music_type(2) == 0) {
                    pMusic->set_music_type(3);
                }
            }

            if (this->music_system != nullptr) {
                this->music_system->set_volume(vol, 1);
            }
        }
    }
    return 1;
}
void RGE_Base_Game::shutdown_music_system() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041FA90
    if (this->music_system != nullptr) {
        this->stop_music_system();
        this->registry->RegSetInt(1, "Music Volume", -this->music_system->volume);
        delete this->music_system;
        this->music_system = nullptr;
    }
}
int RGE_Base_Game::setup_cmd_options() {
    // Source of truth: basegame.cpp.decomp @ 0x0041D0A0
    if (!this->prog_info || !this->prog_info->cmd_line) return 1;

    char cmd_line[256];
    strncpy(cmd_line, this->prog_info->cmd_line, 255);
    cmd_line[255] = '\0';
    CharUpperA(cmd_line);

    if (strstr(cmd_line, "NOSTARTUP") || strstr(cmd_line, "NO STARTUP") || strstr(cmd_line, "NO_STARTUP")) {
        this->prog_info->skip_startup = 1;
    }
    if (strstr(cmd_line, "SYSTEMMEMORY") || strstr(cmd_line, "SYSTEM MEMORY") || strstr(cmd_line, "SYSTEM_MEMORY")) {
        this->prog_info->use_sys_mem = 1;
    }
    if (strstr(cmd_line, "MIDIMUSIC") || strstr(cmd_line, "MIDI MUSIC") || strstr(cmd_line, "MIDI_MUSIC")) {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 0;
        this->prog_info->use_ima = 0;
        this->prog_info->use_midi = 1;
        this->prog_info->use_wave_music = 0;
    }
    if (strstr(cmd_line, "MSYNC")) {
        this->mouse_blit_sync = 1;
    }
    if (strstr(cmd_line, "MFILL")) {
        DDSys_CanColorFill = 0;
    }
    if (strstr(cmd_line, "NOSOUND") || strstr(cmd_line, "NO SOUND") || strstr(cmd_line, "NO_SOUND")) {
        this->prog_info->use_sound = 0;
    }
    if (strstr(cmd_line, "640")) {
        this->prog_info->main_wid = 640;
        this->prog_info->main_hgt = 480;
    }
    if (strstr(cmd_line, "800")) {
        this->prog_info->main_wid = 800;
        this->prog_info->main_hgt = 600;
    }
    if (strstr(cmd_line, "1024")) {
        this->prog_info->main_wid = 1024;
        this->prog_info->main_hgt = 768;
    }
    if (strstr(cmd_line, "NOMOUSE") || strstr(cmd_line, "NO MOUSE") || strstr(cmd_line, "NO_MOUSE")) {
        this->custom_mouse = 0;
    }
    if (strstr(cmd_line, "NORMSCRN") || strstr(cmd_line, "WINDOWED")) {
        this->prog_info->full_screen = 0;
    }
    if (strstr(cmd_line, "FULLSCREEN") || strstr(cmd_line, "FULL SCREEN") || strstr(cmd_line, "FULL_SCREEN")) {
        this->prog_info->full_screen = 1;
        this->prog_info->use_dir_draw = 1;
    }
    if (strstr(cmd_line, "VIDEOMEMORY") || strstr(cmd_line, "VIDEO MEMORY") || strstr(cmd_line, "VIDEO_MEMORY")) {
        this->prog_info->use_sys_mem = 0;
    }
    if (strstr(cmd_line, "STREAMMUSIC") || strstr(cmd_line, "STREAM MUSIC") || strstr(cmd_line, "STREAM_MUSIC")) {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 0;
        this->prog_info->use_ima = 0;
        this->prog_info->use_midi = 0;
        this->prog_info->use_wave_music = 1;
    }
    if (strstr(cmd_line, "RUNLOG")) {
        do_run_log = 1;
    }
    if (strstr(cmd_line, "SYNCMSG")) {
        this->comm_syncmsg = 1;
    }
    if (strstr(cmd_line, "DROPPACKETS")) {
        this->comm_droppackets = 1;
    }
    if (strstr(cmd_line, "NOCOMMSPEED")) {
        this->comm_speed = 0;
    }
    if (strstr(cmd_line, "SYNCSTOP")) {
        this->comm_syncstop = 1;
    }
    if (strstr(cmd_line, "STEPMODE")) {
        this->comm_stepmode = 1;
    }

    return 1;
}
int RGE_Base_Game::setup_class() {
    CUSTOM_DEBUG_FUNC_ENTER();
    if (!this->prog_info) {
        CUSTOM_DEBUG_LOG("setup_class: prog_info is NULL");
        return 0;
    }
    
    WNDCLASSA cls;
    memset(&cls, 0, sizeof(cls));
    cls.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
    cls.lpfnWndProc = (WNDPROC)rge_base_game_wnd_proc;
    cls.cbClsExtra = 0;
    cls.cbWndExtra = 0;
    cls.hInstance = (HINSTANCE)this->prog_info->instance;
    cls.hIcon = LoadIconA((HINSTANCE)this->prog_info->instance, (char*)this->prog_info + 0x61C);
    cls.hCursor = LoadCursorA(NULL, IDC_ARROW);
    cls.hbrBackground = NULL;
    cls.lpszMenuName = NULL;
    cls.lpszClassName = (char*)this->prog_info + 0x645;
    
    CUSTOM_DEBUG_LOG_FMT("setup_class: className='%s'", cls.lpszClassName);
    
    if (RegisterClassA(&cls)) {
        CUSTOM_DEBUG_LOG("setup_class: RegisterClassA succeeded");
        return 1;
    }
    CUSTOM_DEBUG_WIN_ERROR("RegisterClassA");
    return 0;
}

int RGE_Base_Game::setup_main_window() {
    CUSTOM_DEBUG_FUNC_ENTER();
    if (!this->prog_info) {
        CUSTOM_DEBUG_LOG("setup_main_window: prog_info is NULL");
        return 0;
    }

    int screen_wid = GetSystemMetrics(SM_CXSCREEN);
    int screen_hgt = GetSystemMetrics(SM_CYSCREEN);

    CUSTOM_DEBUG_LOG_FMT("setup_main_window: screen=%dx%d, main=%ldx%ld",
                         screen_wid, screen_hgt, this->prog_info->main_wid, this->prog_info->main_hgt);

    int wnd_w = screen_wid;
    int wnd_h = screen_hgt;
    DWORD style = 0x82080000;
    if ((this->prog_info->full_screen == 0) &&
        ((screen_wid != this->prog_info->main_wid) || (screen_hgt != this->prog_info->main_hgt))) {
        style = 0x02CA0000;
        wnd_w = (int)this->prog_info->main_wid;
        wnd_h = (int)this->prog_info->main_hgt;
    }

    const char* className = (char*)this->prog_info + 0x645;
    const char* windowTitle = (char*)this->prog_info + 0x7A;
    CUSTOM_DEBUG_LOG_FMT("setup_main_window: className='%s', title='%s', style=0x%lx", className, windowTitle, style);

    this->prog_window = CreateWindowExA(0, className, windowTitle, style, 0, 0, wnd_w, wnd_h, NULL, NULL,
                                        (HINSTANCE)this->prog_info->instance, NULL);

    if (!this->prog_window) {
        CUSTOM_DEBUG_WIN_ERROR("CreateWindowExA");
        return 0;
    }

    CUSTOM_DEBUG_LOG("setup_main_window: window created successfully");

    RECT win_rect;
    RECT client_rect;
    GetWindowRect((HWND)this->prog_window, &win_rect);
    GetClientRect((HWND)this->prog_window, &client_rect);
    if (((long)client_rect.right != this->prog_info->main_wid) ||
        ((long)client_rect.bottom != this->prog_info->main_hgt)) {
        int non_client_w = (win_rect.right - win_rect.left) - (client_rect.right - client_rect.left);
        int non_client_h = (win_rect.bottom - win_rect.top) - (client_rect.bottom - client_rect.top);
        SetWindowPos((HWND)this->prog_window, NULL, win_rect.left, win_rect.top,
                     (int)this->prog_info->main_wid + non_client_w,
                     (int)this->prog_info->main_hgt + non_client_h, 0);
    }

    if (this->prog_info->full_screen != 0) {
        ShowWindow((HWND)this->prog_window, this->prog_info->show_wnd_flag);
        UpdateWindow((HWND)this->prog_window);
        SetFocus((HWND)this->prog_window);
    }

    AppWnd = (HWND)this->prog_window;
    if (panel_system) {
        panel_system->DisableIME();
    }

    return 1;
}

// Source of truth: basegame.cpp.decomp @ 0x0041E920
int RGE_Base_Game::setup_graphics_system() {
    // Device caps check — need at least 8-bit color when using DirectDraw
    if (this->prog_info->use_dir_draw != 0) {
        HDC hdc = GetDC(NULL);
        int bits = GetDeviceCaps(hdc, BITSPIXEL);
        ReleaseDC(NULL, hdc);
        if (bits < 8) {
            this->error_code = 0x13;
            return 0;
        }
    }

    int iVar5 = this->prog_info->use_dir_draw;
    int iVar2 = this->prog_info->use_sys_mem;
    int iVar3 = this->prog_info->full_screen;

    TDrawSystem* ds = new TDrawSystem();
    if (!ds) return 0;
    this->draw_system = ds;

    // Decomp passes full_screen to CheckAvailModes
    ds->CheckAvailModes(this->prog_info->full_screen);
    // Modern Windows: fullscreen 8-bit enum finds nothing — retry windowed
    if (this->prog_info->full_screen && !ds->ModeAvail640) {
        ds->CheckAvailModes(0);
    }

    // Mode fallback chain per decomp
    long w = this->prog_info->main_wid;
    long h = this->prog_info->main_hgt;
    if (!ds->IsModeAvail(w, 0, 8)) {
        if (w != 640 && ds->IsModeAvail(640, 0, 8)) {
            w = 640; h = 480;
        } else if (w != 800 && ds->IsModeAvail(800, 0, 8)) {
            w = 800; h = 600;
        } else if (w != 1024 && ds->IsModeAvail(1024, 0, 8)) {
            w = 1024; h = 768;
        } else if (w != 1280 && ds->IsModeAvail(1280, 0, 8)) {
            w = 1280; h = 1024;
        } else {
            return 0;
        }
        this->prog_info->main_wid = w;
        this->prog_info->main_hgt = h;
    }

    // Decomp: draw_type = (use_dir_draw != 0) + 1  →  1=WinG, 2=DirectDraw
    //         draw_mode = (full_screen != 0) + 1    →  1=windowed, 2=fullscreen
    uchar draw_type = (uchar)((iVar5 != 0) + 1);
    uchar draw_mode = (uchar)((iVar3 != 0) + 1);

    if (!ds->Init(this->prog_info->instance, this->prog_window, this->prog_palette,
                  draw_type, draw_mode, w, h, (ulong)(iVar2 != 0))) {
        return 0;
    }

    if (panel_system) {
        panel_system->release_palette(this->prog_palette);
        this->prog_palette = panel_system->get_palette(this->prog_info->pal_file, 50500);
    }

    this->draw_area = ds->DrawArea;
    if (this->draw_area) {
        this->draw_area->Clear(NULL, 0);
    }

    this->draw_system->Paint(NULL);

    return 1;
}

int RGE_Base_Game::setup_palette() {
    if (!this->prog_info || !panel_system) return 0;

    void* pal = panel_system->get_palette(this->prog_info->pal_file, 50500); // 0xc544 per decomp
    if (pal) {
        this->prog_palette = pal;
        return 1;
    }
    return 0;
}

int RGE_Base_Game::setup_mouse() {
    if (!this->registry) return 0;

    int custom_mouse_reg = this->registry->RegGetInt(1, "Custom Mouse");
    if (custom_mouse_reg == -1) {
        this->registry->RegSetInt(1, "Custom Mouse", 0);
        custom_mouse_reg = 0;
    }

    if (custom_mouse_reg == 1 || custom_mouse_reg == 2) {
        // Stub: TMousePointer implementation
        // this->mouse_pointer = new TMousePointer(custom_mouse_reg);
        // setup call...
    } else {
        this->mouse_pointer = nullptr;
    }
    return 1;
}

void* RGE_Base_Game::create_font(void* dc, int id1, int id2) {
    (void)dc;
    // Source of truth: `basegame.cpp.asm/.decomp` (`make_font` helpers).
    // The original reads 3 consecutive string IDs:
    //   id     -> face name
    //   id + 1 -> point size
    //   id + 2 -> style marker (contains 'B'/'b' when bold)
    char face_name[256];
    char point_size_str[32];
    char style[32];
    char charset_str[32];

    face_name[0] = '\0';
    point_size_str[0] = '\0';
    style[0] = '\0';
    charset_str[0] = '\0';

    this->get_string(id1, face_name, sizeof(face_name));
    if (face_name[0] == '\0') return nullptr;
    this->get_string(id1 + 1, point_size_str, sizeof(point_size_str));
    this->get_string(id1 + 2, style, sizeof(style));
    this->get_string(0x65, charset_str, sizeof(charset_str)); // language.dll: "1"

    const int point_size = atoi(point_size_str);
    if (point_size <= 0) return nullptr;

    int weight = 400;
    if (strstr(style, "B") || strstr(style, "b")) {
        weight = 700;
    }

    LOGFONTA lf;
    memset(&lf, 0, sizeof(lf));
    // Source of truth: `make_font` uses current DC vertical DPI (LOGPIXELSY).
    int log_pixels_y = 96;
    if (dc) {
        const int dpi = GetDeviceCaps((HDC)dc, LOGPIXELSY);
        if (dpi > 0) log_pixels_y = dpi;
    }
    lf.lfHeight = -MulDiv(point_size, log_pixels_y, 72);
    lf.lfWidth = 0;
    lf.lfEscapement = 0;
    lf.lfOrientation = 0;
    lf.lfWeight = weight;
    lf.lfItalic = 0;
    lf.lfUnderline = 0;
    // NOTE: `id2` is the final arg in original `make_font(..., param_5)` and maps to
    // `LOGFONT::lfStrikeOut` in the assembly write sequence.
    lf.lfStrikeOut = (BYTE)(id2 ? 1 : 0);
    lf.lfCharSet = (BYTE)atoi(charset_str);
    lf.lfOutPrecision = 0;
    lf.lfClipPrecision = 0;
    lf.lfQuality = 2;
    lf.lfPitchAndFamily = 2;
    strncpy(lf.lfFaceName, face_name, LF_FACESIZE - 1);
    lf.lfFaceName[LF_FACESIZE - 1] = '\0';

    return CreateFontIndirectA(&lf);
}

int RGE_Base_Game::setup_fonts() {
    this->fonts = (RGE_Font*)calloc(12, sizeof(RGE_Font));
    if (!this->fonts) return 0;
    this->font_num = 12;

    HDC hdc = nullptr;
    int use_draw_area_dc = 0;
    if (this->draw_area) {
        hdc = (HDC)this->draw_area->GetDc((char*)"basegame::setup_fonts");
        if (hdc) use_draw_area_dc = 1;
    }
    if (!hdc) hdc = GetDC((HWND)this->prog_window);
    if (!hdc) return 0;
    
    for (int i = 0; i < 12; i++) {
        int id1 = 0;
        int id2 = 0;
        switch (i) {
            case 0: id1 = 110; break; // 0x6e
            case 1: id1 = 113; break; // 0x71
            case 4: id1 = 116; break; // 0x74
            case 6: id1 = 131; break; // 0x83
            case 7: id1 = 119; break; // 0x77
            case 8: id1 = 128; id2 = 1; break; // 0x80
            case 9: id1 = 122; break; // 0x7a
            case 10: id1 = 125; break; // 0x7d
            case 11: id1 = 128; break; // 0x80
            // Cases 2, 3, 5 are NULL
            default: break; 
        }

        if (id1 == 0) {
            this->fonts[i].font = nullptr;
            continue;
        }

        this->fonts[i].font = this->create_font(hdc, id1, id2);
        
        if (this->fonts[i].font) {
            HGDIOBJ old_font = SelectObject(hdc, (HFONT)this->fonts[i].font);
            TEXTMETRICA tm;
            GetTextMetricsA(hdc, &tm);
            // Source of truth note: `basegame.cpp.decomp` points at `tmMaxCharWidth` for width.
            this->fonts[i].font_wid = tm.tmMaxCharWidth;
            // TODO(asm-parity): field mapping in the decomp is noisy here; this line-height formula
            // may still differ from original and can be revisited with tighter stack-var mapping.
            this->fonts[i].font_hgt = tm.tmHeight + tm.tmExternalLeading;
            if (old_font) SelectObject(hdc, old_font);
        }
    }

    if (use_draw_area_dc) this->draw_area->ReleaseDc((char*)"basegame::setup_fonts");
    else ReleaseDC((HWND)this->prog_window, hdc);
    return 1;
}

int RGE_Base_Game::setup_sounds() {
    // Offset: 0x0041F400
    // Creates 3 UI sounds: button1.wav (0xC47C), button2.wav (0xC47D), chatrcvd.wav (0xC47E)
    this->sound_num = 3;
    this->sounds = (TDigital**)calloc(3, sizeof(TDigital*));
    if (this->sounds == nullptr) return 0;

    for (int i = 0; i < this->sound_num; i++) {
        this->sounds[i] = nullptr;
    }

    this->sounds[0] = new TDigital(this->sound_system, (char*)"button1.wav", 0xC47C);
    this->sounds[1] = new TDigital(this->sound_system, (char*)"button2.wav", 0xC47D);
    this->sounds[2] = new TDigital(this->sound_system, (char*)"chatrcvd.wav", 0xC47E);

    for (int i = 0; i < this->sound_num; i++) {
        if (this->sounds[i] != nullptr) {
            int r = this->sounds[i]->load(nullptr, -1);
CUSTOM_DEBUG_BEGIN
            CUSTOM_DEBUG_LOG_FMT("setup_sounds[%d]: load=%d loaded=%d failed=%d",
                i, r, (int)this->sounds[i]->loaded, (int)this->sounds[i]->failed);
CUSTOM_DEBUG_END
        }
    }
CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("setup_sounds: sound_system=%p", this->sound_system);
CUSTOM_DEBUG_END
    return 1;
}

int RGE_Base_Game::setup_shapes() { 
    // Stub implementation
    return 1; 
}

int RGE_Base_Game::setup_blank_screen() { 
    // Stub implementation
    return 1; 
}
void RGE_Base_Game::setup_timings() {}
void RGE_Base_Game::stop_sound_system() {}
int RGE_Base_Game::restart_sound_system() { return 1; }
void RGE_Base_Game::stop_music_system() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041F9B0
    if (this->music_system != nullptr) {
        this->music_system->get_play_info(
            &this->save_music_type,
            &this->save_music_track_from,
            &this->save_music_track_to,
            &this->save_music_cur_track,
            this->save_music_file,
            &this->save_music_loop,
            &this->save_music_pos);
        this->music_system->stop_track();
    }
}
int RGE_Base_Game::restart_music_system() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041F9F0
    TMusic_System* music = this->music_system;
    if (music == nullptr) {
        return 1;
    }
    int from_track = this->save_music_track_from;
    if (from_track != 0) {
        if (from_track == this->save_music_track_to) {
            music->play_track(from_track, this->save_music_loop, this->save_music_pos);
            return 1;
        }
        if ((from_track != 0) && (this->save_music_track_to != 0)) {
            music->play_tracks(
                from_track,
                this->save_music_track_to,
                this->save_music_loop,
                this->save_music_cur_track,
                this->save_music_pos);
            return 1;
        }
    }
    if (this->save_music_file[0] != '\0') {
        music->play_file(this->save_music_file, this->save_music_loop, this->save_music_pos);
    }
    return 1;
}
RGE_Game_World* RGE_Base_Game::create_world() {
    if (this->world) {
        delete this->world;
    }
    this->world = new RGE_Game_World();
    return this->world;
}
int RGE_Base_Game::run() {
    // Source of truth: basegame.cpp.decomp @ 0x0041CFD0
    MSG msg;
    
    while (1) {
        while (1) {
            // Innermost loop: blocking GetMessage when inactive/wrong mode/paused
            while (this->prog_active == 0 ||
                   (this->prog_mode != 4 && this->prog_mode != 2) ||
                   (this->comm_handler != nullptr && this->comm_handler->IsPaused() != 0)) {
                int ret = GetMessageA(&msg, NULL, 0, 0);
                if (ret == 0) {
                    return msg.lParam;
                }
                TranslateMessage(&msg);
                DispatchMessageA(&msg);
            }
            // Active mode: PeekMessage for non-blocking processing
            int got = PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE);
            if (got != 0) break;
            this->handle_idle();
        }
        // Quit check: decomp says msg.wParam == 0x12, but 0x12 = WM_QUIT (message ID).
        // Ghidra got the struct field wrong (off by 4 bytes). PostQuitMessage(0) sets wParam=0.
        // The correct standard pattern is msg.message == WM_QUIT.
        if (msg.message == WM_QUIT) break;
        // handle_message returns non-zero if message should still be dispatched
        int result = this->handle_message(&msg);
        if (result != 0) {
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }
    }

    return msg.lParam;
}
int RGE_Base_Game::handle_message(struct tagMSG* p1) {
    // Source of truth: basegame.cpp.decomp @ 0x0041C700
    // Base class just returns 1 (not consumed). All message routing is done in wnd_proc.
    return 1;
}

int RGE_Base_Game::handle_idle() {
    // Source of truth: basegame.cpp.decomp @ 0x00420F60
    if (this->prog_ready == 0 || this->prog_window == nullptr) {
        return 0;
    }

    // Palette restoration timing
    if (do_restore_palette != 0 && this->prog_active != 0) {
        unsigned int threshold = (do_restore_palette > 5) ? 500 : 250;
        unsigned long now = debug_timeGetTime("basegame.cpp", 0xf9a);
        if (threshold <= (now - restore_palette_timer)) {
            if (this->draw_system != nullptr) {
                this->draw_system->ModifyPalette(0, 0x100, this->draw_system->palette);
            }
            do_restore_palette = do_restore_palette - 1;
            restore_palette_timer = debug_timeGetTime("basegame.cpp", 0xfa4);
        }
    }

    // Sound system timer processing
    if (this->sound_system != nullptr) {
        this->sound_system->handle_messages(this->prog_window, 0x113, 0, 0);
    }

    // Current panel idle
    if (panel_system != nullptr) {
        TPanel* curPanel = panel_system->currentPanelValue;
        if (curPanel != nullptr) {
            curPanel->handle_idle();
        }
    }

    // Comm handler message receiving
    if (this->comm_handler != nullptr) {
        if (this->rge_game_options.multiplayerGameValue != 0) {
            this->comm_handler->ReceiveGameMessages();
        }
    }

    return 1;
}
int RGE_Base_Game::handle_mouse_move(void* p1, uint p2, uint p3, long p4) {
    // Source of truth: basegame.cpp.decomp @ 0x00421110
    if (this->prog_ready == 0) {
        return 1;
    }

    // Custom mouse pointer update
    if (this->custom_mouse != 0 && this->windows_mouse == 0) {
        // TODO(accuracy): TMousePointer::in_game_mode check → draw(0) vs Poll()
        // Requires adding Poll/draw/in_game_mode to TMousePointer.h
    }

    // Extract mouse position from lParam
    short mouse_x = (short)(p4 & 0xFFFF);
    short mouse_y = (short)((p4 >> 16) & 0xFFFF);
    int left_btn = (p3 & MK_LBUTTON) ? 1 : 0;
    int right_btn = (p3 & MK_RBUTTON) ? 1 : 0;
    int ctrl_key = (p3 & MK_CONTROL) ? 1 : 0;

    // Dispatch to virtual action_mouse_move
    this->action_mouse_move(mouse_x, mouse_y, left_btn, right_btn, ctrl_key, 0);

    return 1;
}
int RGE_Base_Game::handle_key_down(void* p1, uint p2, uint p3, long p4) {
    // Source of truth: basegame.cpp.decomp @ 0x004211D0
    if (this->prog_ready == 0) {
        return 1;
    }

    int repeat_count = p4 & 0xFFFF;
    int key_code = p3;

    // Get modifier key states
    int ctrl_down = (GetKeyState(0x11) < 0) ? 1 : 0;  // VK_CONTROL
    int alt_down = (GetKeyState(0x12) < 0) ? 1 : 0;    // VK_MENU
    int shift_down = (GetKeyState(0x10) < 0) ? 1 : 0;  // VK_SHIFT

    // Block Alt+Space, Alt+F10 in fullscreen (WM_SYSKEYDOWN = 0x104)
    if (p1 == this->prog_window && p2 == 0x104) {
        if ((key_code == 0x12 || key_code == 0x20 || key_code == 0x79) &&
            this->prog_info->full_screen != 0) {
            if (!IsIconic((HWND)this->prog_window)) {
                return 0; // consume
            }
        }
    }

    // Ctrl+F12 takes screenshot
    if (ctrl_down != 0 && key_code == 0x7B) { // VK_F12
        // TODO(accuracy): TDrawArea::take_snapshot
        return 0;
    }

    // Dispatch to virtual action_key_down
    int result = this->action_key_down(key_code, repeat_count, ctrl_down, alt_down, shift_down);
    return (result != 0) ? 1 : 0;
}
int RGE_Base_Game::handle_user_command(void* p1, uint p2, uint p3, long p4) {
    // Source of truth: basegame.cpp.decomp @ 0x004212E0
    // p3 (wParam): 0x17a2 = pause world, 0x17a3 = unpause world
    // 0x17b3/0x17b4 = MP player commands (need players allocated)
    if (p3 == 0x17a2) {
        if (this->world != nullptr) {
            this->world->pause(1);
        }
    } else if (p3 == 0x17a3) {
        if (this->world != nullptr) {
            this->world->pause(0);
        }
    }

    int result = this->action_user_command(p3, p4);
    return (result != 0) ? 1 : 0;
}
int RGE_Base_Game::handle_command(void* p1, uint p2, uint p3, long p4) {
    // Source of truth: basegame.cpp.decomp @ 0x004213A0
    int result = this->action_command(p3, p4);
    return (result != 0) ? 1 : 0;
}
int RGE_Base_Game::handle_music_done(void* p1, uint p2, uint p3, long p4) {
    // Source of truth: basegame.cpp.decomp @ 0x004213C0
    int result = this->action_music_done();
    return (result != 0) ? 1 : 0;
}
int RGE_Base_Game::handle_paint(void* p1, uint p2, uint p3, long p4) {
    // Source of truth: basegame.cpp.decomp @ 0x004213E0
    // Simplified: the original does DirectDraw surface locking, check_paint,
    // panel draw_tree, timing calculations, mouse pointer draw, and Paint.
    // We handle the essential parts: draw current panel, Paint, ValidateRect.

    TPanel* current = panel_system ? panel_system->currentPanelValue : nullptr;
    if (current) {
        current->draw_tree();
    }

    if (this->draw_system) {
        this->draw_system->Paint(NULL);
    }

    ValidateRect((HWND)this->prog_window, NULL);
    this->render_all = 0;
    this->frame_count++;

    return 1;
}
int RGE_Base_Game::handle_activate(void* p1, uint p2, uint p3, long p4) {
    // Source of truth: basegame.cpp.decomp @ 0x00421830
    // p3 (wParam): 0 = deactivated, nonzero = activated
    if (p3 == 0) {
        this->prog_active = 0;
    } else {
        this->prog_active = 1;
    }

    int pm = this->prog_mode;

    if (this->prog_active != 0) {
        // Activated: unpause if auto-paused
        if ((pm == 4 || pm == 6 || pm == 7) && this->auto_paused == 1) {
            this->auto_paused = 0;
            this->set_paused(0, 0);
        }
        // Notify current panel and call action_activate
        this->action_activate();
        return 1;
    }

    // Deactivated: auto-pause single-player in-game
    if (pm == 4 || pm == 6 || pm == 7) {
        if (this->singlePlayerGame() == 1) {
            if (this->get_paused() == 0) {
                this->auto_paused = 1;
                this->set_paused(1, 0);
            }
        }
    }
    this->action_deactivate();
    return 1;
}
int RGE_Base_Game::handle_init_menu(void* p1, uint p2, uint p3, long p4) {
    // Source of truth: basegame.cpp.decomp @ 0x00421910
    int result = this->action_init_menu();
    return (result != 0) ? 1 : 0;
}
int RGE_Base_Game::handle_exit_menu(void* p1, uint p2, uint p3, long p4) {
    // Source of truth: basegame.cpp.decomp @ 0x00421930
    int result = this->action_exit_menu();
    return (result != 0) ? 1 : 0;
}
int RGE_Base_Game::handle_size(void* p1, uint p2, uint p3, long p4) {
    // Source of truth: basegame.cpp.decomp @ 0x00421950
    // p3 (wParam): SIZE_MINIMIZED = 1
    if (p3 == 1) {
        return 1; // minimized — do nothing
    }

    if (this->draw_system != nullptr) {
        // TODO(accuracy): TDrawSystem::HandleSize(p1, p2, p3, p4)
        // Update prog_info from draw system dimensions if available
        if (this->draw_system->ScreenWidth != 0) {
            this->prog_info->main_wid = this->draw_system->ScreenWidth;
            this->prog_info->main_hgt = this->draw_system->ScreenHeight;
        }
        // Notify current panel of resize
        TPanel* current = panel_system ? panel_system->currentPanelValue : nullptr;
        if (current) {
            current->handle_size(this->prog_info->main_wid, this->prog_info->main_hgt);
        }
    }
    this->action_size();
    return 1;
}
int RGE_Base_Game::handle_palette_changed(void* p1, uint p2, uint p3, long p4) { return 0; }
int RGE_Base_Game::handle_query_new_palette(void* p1, uint p2, uint p3, long p4) { return 0; }
int RGE_Base_Game::handle_close(void* p1, uint p2, uint p3, long p4) {
    // Return 1 (not consumed) so DefWindowProcA handles it → calls DestroyWindow
    return 1;
}
int RGE_Base_Game::handle_destroy(void* p1, uint p2, uint p3, long p4) {
    PostQuitMessage(0);
    return 0; // consumed
}
int RGE_Base_Game::action_update() { return 1; }
int RGE_Base_Game::action_mouse_move(long p1, long p2, int p3, int p4, int p5, int p6) { return 1; }
int RGE_Base_Game::action_key_down(ulong p1, int p2, int p3, int p4, int p5) { return 1; }
int RGE_Base_Game::action_user_command(ulong p1, ulong p2) { return 1; }
int RGE_Base_Game::action_command(ulong p1, ulong p2) { return 1; }
int RGE_Base_Game::action_music_done() { return 1; }
int RGE_Base_Game::action_activate() { return 1; }
int RGE_Base_Game::action_deactivate() { return 1; }
int RGE_Base_Game::action_init_menu() { return 1; }
int RGE_Base_Game::action_exit_menu() { return 1; }
int RGE_Base_Game::action_size() { return 1; }
int RGE_Base_Game::action_close() { return 1; }
void RGE_Base_Game::reset_timings() {
    // Source of truth: basegame.cpp.decomp @ 0x0041C7D0
    this->frame_count = 0;
    this->world_update_count = 0;
    this->view_update_count = 0;
    this->last_frame_count = 0;
    this->last_world_update_count = 0;
    this->last_view_update_count = 0;
    this->fps = 0;
    this->world_update_fps = 0;
    this->view_update_fps = 0;
    for (int i = 0; i < 30; i++) {
        this->timings[i].accum_time = 0;
        this->timings[i].last_time = 0;
        this->timings[i].start_time = 0;
        this->timings[i].max_time = 0;
        this->timings[i].last_max_time = 0;
        this->timings[i].last_single_time = 0;
    }
}
void RGE_Base_Game::add_to_timing(int param_1, ulong param_2) {
    // Source of truth: basegame.cpp.decomp @ 0x0041C830
    this->timings[param_1].accum_time += param_2;
    this->timings[param_1].last_single_time = param_2;
    if (this->timings[param_1].max_time < param_2) {
        this->timings[param_1].max_time = param_2;
    }
}
void RGE_Base_Game::increment_world_update_count() {
    // Source of truth: basegame.cpp.decomp @ 0x0041C870
    this->world_update_count++;
}
void RGE_Base_Game::increment_view_update_count() {
    // Source of truth: basegame.cpp.decomp @ 0x0041C880
    this->view_update_count++;
}
void RGE_Base_Game::calc_timings() {}
void RGE_Base_Game::calc_timing_text() {}
void RGE_Base_Game::show_timings() {}
void RGE_Base_Game::show_comm() {}
void RGE_Base_Game::show_ai() {}
int RGE_Base_Game::setup_map_save_area() { return 1; }
void RGE_Base_Game::set_interface_messages() {}

RGE_Font* RGE_Base_Game::get_font(int index) {
    if (index >= 0 && index < this->font_num) {
        return &this->fonts[index];
    }
    return nullptr;
}

TShape* RGE_Base_Game::get_shape(int index) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x004201C0.
    if (this->shapes == nullptr) {
        return nullptr;
    }
    return this->shapes[index];
}

TDigital* RGE_Base_Game::get_sound(int index) {
    // Source of truth: `src/game/src/basegame.cpp.decomp` (`RGE_Base_Game::get_sound`).
    // The original only checks for null `sounds` and then indexes directly.
    if (!this->sounds) {
        return nullptr;
    }
    return this->sounds[index];
}

unsigned long RGE_Base_Game::get_last_max_time() {
    return this->last_view_time;
}

unsigned long RGE_Base_Game::get_last_world_update_count() {
    return this->last_world_update_count;
}

unsigned long RGE_Base_Game::get_last_view_update_count() {
    return this->last_view_update_count;
}

unsigned long RGE_Base_Game::get_world_update_count() {
    return this->world_update_count;
}

unsigned long RGE_Base_Game::get_view_update_count() {
    return this->view_update_count;
}

// --- Accessor methods used by create_game and game start paths ---

int RGE_Base_Game::numberPlayers() {
    return (int)this->rge_game_options.numberPlayersValue;
}

int RGE_Base_Game::mapXSize() {
    return (int)this->rge_game_options.mapXSizeValue;
}

int RGE_Base_Game::mapYSize() {
    return (int)this->rge_game_options.mapYSizeValue;
}

int RGE_Base_Game::scenarioGame() {
    return (int)this->rge_game_options.scenarioGameValue;
}

int RGE_Base_Game::campaignGame() {
    return this->campaignGameValue;
}

int RGE_Base_Game::multiplayerGame() {
    return (int)this->rge_game_options.multiplayerGameValue;
}

int RGE_Base_Game::singlePlayerGame() {
    return (int)this->rge_game_options.singlePlayerGameValue;
}

float RGE_Base_Game::get_game_speed() {
    // Source of truth: basegame.cpp.decomp @ 0x00422EB0
    return this->game_speed;
}

unsigned char RGE_Base_Game::playerVersion(int index) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x004224C0
    return (unsigned char)(this->rge_game_options.playerCDAndVersionValue[index] >> 1);
}

int RGE_Base_Game::playerTeam(int index) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422660
    return (uint)this->rge_game_options.playerTeamValue[index];
}

int RGE_Base_Game::randomGame() {
    // Random game = not scenario and not campaign
    return (this->rge_game_options.scenarioGameValue == 0 && this->campaignGameValue == 0) ? 1 : 0;
}

int RGE_Base_Game::fullVisibility() {
    return (int)this->rge_game_options.fullVisibilityValue;
}

int RGE_Base_Game::fogOfWar() {
    return (int)this->rge_game_options.fogOfWarValue;
}

int RGE_Base_Game::playerID(int index) {
    if (index >= 0 && index < 9) {
        return this->playerIDValue[index];
    }
    return 0;
}

void RGE_Base_Game::setPlayerID(int index, int value) {
    if (index >= 0 && index < 9) {
        this->playerIDValue[index] = value;
    }
}

unsigned char RGE_Base_Game::pathFinding() {
    return this->pathFindingValue;
}

unsigned char RGE_Base_Game::mpPathFinding() {
    return this->rge_game_options.mpPathFindingValue;
}

void RGE_Base_Game::set_map_visible(unsigned char p1) {
    // Source of truth: basegame.cpp.decomp @ 0x004228C0
    if (this->world != nullptr) {
        this->world->set_map_visible(p1);
    }
}

void RGE_Base_Game::set_map_fog(unsigned char p1) {
    // Source of truth: basegame.cpp.decomp @ 0x004228E0
    if (this->world != nullptr) {
        this->world->set_map_fog(p1);
    }
}

void RGE_Base_Game::reset_countdown_timer(int p1) {
    if (p1 >= 0 && p1 < 9) {
        this->countdown_timer[p1] = 0;
    }
}

void RGE_Base_Game::set_paused(int p1, int p2) {
    // Source of truth: basegame.cpp.decomp @ 0x00420220
    int was_paused = this->get_paused();
    this->save_paused = was_paused;
    if (p1 != was_paused) {
        if (p1 != 0) {
            this->non_user_pause = p2;
        } else {
            this->non_user_pause = 0;
        }
        this->request_pause();
    }
}

void RGE_Base_Game::request_pause() {
    // Source of truth: basegame.cpp.decomp @ 0x00420200
    if (this->comm_handler) {
        this->comm_handler->TogglePauseGame();
    }
    if (this->world) {
        this->world->temp_pause = 1;
    }
}

char* RGE_Base_Game::scenarioName() {
    return this->rge_game_options.scenarioNameValue;
}

int RGE_Base_Game::campaign_open_scenario() {
    // Source of truth: basegame.cpp.decomp @ 0x00422910
    if (this->player_game_info == nullptr) {
        return -1;
    }
    return this->player_game_info->open_scenario();
}

void RGE_Base_Game::get_campaign_info(long* param_1, long* param_2, long* param_3) {
    // Source of truth: basegame.cpp.decomp @ 0x0041CF30
    if (param_1 != nullptr) {
        *param_1 = -1;
    }
    if (param_2 != nullptr) {
        *param_2 = -1;
    }
    if (param_3 != nullptr) {
        *param_3 = -1;
    }

    if (this->player_game_info == nullptr) {
        return;
    }

    if (param_1 != nullptr) {
        *param_1 = this->player_game_info->get_current_campaign();
    }
    if (param_2 != nullptr) {
        *param_2 = this->player_game_info->get_current_player();
    }
    if (param_3 != nullptr) {
        *param_3 = this->player_game_info->get_current_scenario();
    }
}

uchar RGE_Base_Game::set_campaign_info(long param_1, long param_2, long param_3) {
    // Source of truth: basegame.cpp.decomp @ 0x0041CF70
    if (this->player_game_info == nullptr) {
        return '\0';
    }

    if (this->player_game_info->set_current_campaign(param_1) != '\0') {
        if (this->player_game_info->set_current_person(param_2) != '\0') {
            if (this->player_game_info->set_current_scenario(param_3) != '\0') {
                return '\x01';
            }
        }
    }
    return '\0';
}

void RGE_Base_Game::set_campaign_win() {
    // Source of truth: basegame.cpp.decomp @ 0x0041CFC0
    this->player_game_info->notify_of_scenario_complete();
}

RGE_Scenario* RGE_Base_Game::get_scenario_info(char* p1, int p2) {
    // Source of truth: basegame.cpp.decomp @ 0x0041CB80
    char temp_name[300];
    memset(temp_name, 0, sizeof(temp_name));
    sprintf(temp_name, "%s%s", this->prog_info->scenario_dir, p1 ? p1 : "");

    int fd = -1;
    if (p2 == 0) {
        if (p1 == nullptr) {
            return nullptr;
        }
        fd = rge_open(temp_name, _O_RDONLY | _O_BINARY);
    } else {
        if (this->player_game_info == nullptr) {
            return nullptr;
        }
        fd = this->player_game_info->open_scenario();
    }

    if (fd == -1) {
        return nullptr;
    }

    long obj_id = 0;
    long version = 0;
    rge_read(fd, &obj_id, 4);
    rge_read(fd, &version, 4);

    if (version > 0) {
        void* header_data = malloc((size_t)version);
        if (header_data == nullptr) {
            rge_close(fd);
            return nullptr;
        }
        rge_read(fd, header_data, (int)version);
        free(header_data);
    }

    char version_tag[4];
    rge_read(fd, version_tag, 4);

    RGE_Scenario* scenario_info = this->new_scenario_info(fd);
    rge_close(fd);
    return scenario_info;
}

// Linker fix stubs
int RGE_Base_Game::setup_chat() { return 1; }
int RGE_Base_Game::setup_comm() {
    // Source of truth: basegame.cpp.decomp @ 0x0041EE90
    // NOTE: This used to memset a default-constructed handler (temporary stub).
    // Now that we have a real comm handler ctor, we must not clobber its internal allocations/state.
    ushort max_players = 8;
    if (this->prog_info != nullptr && this->prog_info->max_players > 0) {
        max_players = (ushort)this->prog_info->max_players;
    }
    if (max_players > 9) {
        max_players = 9;
    }

    TCommunications_Handler* handler = new TCommunications_Handler(this->prog_window, (uchar)max_players);
    if (handler == nullptr) {
        this->comm_handler = nullptr;
        comm = nullptr;
        return 0;
    }

    handler->Me = 1;
    handler->Multiplayer = (this->rge_game_options.multiplayerGameValue != 0) ? 1 : 0;
    handler->MeHost = (handler->Multiplayer == 0) ? 1 : 0;
    handler->CommunicationsStatus = COMM_IDLE;

    // Default SP humanity profile expected by create_game() mapping pass.
    handler->PlayerOptions.Humanity[1] = 2;
    for (int i = 2; i < 10; ++i) {
        handler->PlayerOptions.Humanity[i] = 4;
    }

    this->comm_handler = handler;
    comm = handler;
    return 1;
}
int RGE_Base_Game::setup_sound_system() {
    // Offset: 0x0041F030
    int vol = 0;
CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("setup_sound_system: use_sound=%d, prog_window=%p, sounds_dir=%s",
        this->prog_info->use_sound, this->prog_window, this->prog_info->sounds_dir);
CUSTOM_DEBUG_END
    if (this->prog_info->use_sound != 0) {
        TSound_Driver* pDriver = new TSound_Driver(this->prog_window, this->prog_info->sounds_dir);
        this->sound_system = pDriver;
        if (pDriver != nullptr) {
CUSTOM_DEBUG_BEGIN
            CUSTOM_DEBUG_LOG_FMT("setup_sound_system: driver_active=%d, dsrval=0x%lx",
                pDriver->driver_active(), pDriver->dsrval);
CUSTOM_DEBUG_END
            if (pDriver->driver_active() == 0) {
CUSTOM_DEBUG_BEGIN
                CUSTOM_DEBUG_LOG("setup_sound_system: DirectSound init FAILED, deleting driver");
CUSTOM_DEBUG_END
                delete this->sound_system;
                this->sound_system = nullptr;
            }
        }
        sound_driver = this->sound_system;
        if (this->registry != nullptr) {
            int regVal = this->registry->RegGetInt(1, "Sound Volume");
            if (regVal != -1) {
                vol = -regVal;
            }
        }
        if (this->sound_system != nullptr) {
            this->sound_system->set_volume(vol, 1);
        }
    }
    this->setup_music_system();
    return 1;
}
