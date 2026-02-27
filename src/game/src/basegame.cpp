#include "../include/RGE_Base_Game.h"
#include "../include/ui_core.h"
#include "../include/TPanel.h"
#include "../include/TPanelSystem.h"
#include "../include/TScreenPanel.h"
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
#include "../include/RGE_Map.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Sound.h"
#include "../include/RGE_Scenario.h"
#include "../include/RGE_Scenario_Header.h"
#include "../include/RGE_Scenario_File_Info.h"
#include "../include/RGE_Game_Info.h"
#include "../include/RGE_Communications_Speed.h"
#include "../include/RGE_Communications_Synchronize.h"
#include "../include/DriveInformation.h"
#include "../include/globals.h"
#include <windows.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <new>
#include <timeapi.h>
#include <direct.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "../include/debug_helpers.h"

struct TPanelSystem;
extern struct TPanelSystem* panel_system;

static int snapshot_number = 1;
static void* last_mouse_cursor = nullptr;

static char s_ver_empty[] = "";
static char s_ver_1_0[] = "1.0";
static char s_ver_1_0a[] = "1.0a";
static char s_ver_1_0b[] = "1.0b";
static char s_ver_1_0c[] = "1.0c";
static char s_ver_1_0d[] = "1.0d";
static char s_ver_1_0e[] = "1.0e";
static char s_ver_1_1[] = "1.1";
static char s_ver_1_1a[] = "1.1a";
static char s_ver_1_1b[] = "1.1b";
static char s_ver_1_1c[] = "1.1c";
static char s_ver_1_2[] = "1.2";
static char s_ver_1_2a[] = "1.2a";
static char s_ver_1_2b[] = "1.2b";
static char s_ver_1_2c[] = "1.2c";
static char s_ver_1_3[] = "1.3";
static char s_ver_1_3a[] = "1.3a";
static char s_ver_1_3b[] = "1.3b";
static char s_ver_1_3c[] = "1.3c";
static char s_ver_1_4[] = "1.4";
static char s_ver_1_4a[] = "1.4a";
static char s_ver_1_4b[] = "1.4b";
static char s_ver_1_4c[] = "1.4c";
static char s_ver_1_X[] = "1.X";
static char s_dot_AoE_04d_bmp[] = ".\\AoE%04d.bmp";
static const char kBasegameSourcePath[] = "C:\\msdev\\work\\age1_x1\\basegame.cpp";
static char DAT_0062c49c[4];

// Command-line / debug toggles referenced by basegame.cpp.decomp but not yet exported globally.
static int resend_adj1 = 0;
static int resend_adj2 = 0;
static int do_fps_log = 0;
static int debug_timeGetTime_interval = 5;
static int allowAIToCheat = 1;
static int chatCheatCodes = 1;
static int logUpdateChanges = 0;
static int useInfluencePlacement = 0;
static int all_grassland_on = 0;
static int useNewPathing = 0;
static int logDebugID = -1;
static int pathingCapValue = 2;
static int Sys_DDLOG_Enable = 0;
static int Sys_DDLOG_ErrorOn = 0;
static int DDlogAutoFlush = 0;
static int debug_log_lock = 0;
static int speed_val1 = 0;
static int speed_val2 = 0;
static FILE* fps_log = nullptr;

static int cmd_has_token(const char* cmd_line_upper, const char* token) {
    return (cmd_line_upper != nullptr && token != nullptr && strstr(cmd_line_upper, token) != nullptr) ? 1 : 0;
}

static int cmd_has_any3(const char* cmd_line_upper, const char* a, const char* b, const char* c) {
    if (cmd_has_token(cmd_line_upper, a) != 0) {
        return 1;
    }
    if (cmd_has_token(cmd_line_upper, b) != 0) {
        return 1;
    }
    if (cmd_has_token(cmd_line_upper, c) != 0) {
        return 1;
    }
    return 0;
}

static int cmd_parse_value(const char* cmd_line_upper, const char* key_upper, char* out_value, int out_cap) {
    if (cmd_line_upper == nullptr || key_upper == nullptr || out_value == nullptr || out_cap <= 0) {
        return 0;
    }

    const char* key_pos = strstr(cmd_line_upper, key_upper);
    if (key_pos == nullptr) {
        out_value[0] = '\0';
        return 0;
    }

    const char* equal_pos = strchr(key_pos, '=');
    if (equal_pos == nullptr) {
        out_value[0] = '\0';
        return 0;
    }

    const char* src = equal_pos + 1;
    int out_index = 0;
    while (*src != '\0' && !isspace((unsigned char)*src) && out_index < out_cap - 1) {
        out_value[out_index++] = *src;
        ++src;
    }
    out_value[out_index] = '\0';
    return (out_index > 0) ? 1 : 0;
}

static int cmd_parse_long_value(const char* cmd_line_upper, const char* key_upper, long* out_value) {
    if (out_value == nullptr) {
        return 0;
    }
    char value_buf[256];
    if (cmd_parse_value(cmd_line_upper, key_upper, value_buf, sizeof(value_buf)) == 0) {
        return 0;
    }
    *out_value = atol(value_buf);
    return 1;
}

static void RESFILE_Set_Missing_Flag(int flag) {
    (void)flag;
    // TODO: STUB: resource-file missing flag plumbing is not exported in this decomp branch yet.
}

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
    if (fps_log != nullptr) {
        fclose(fps_log);
        fps_log = nullptr;
    }
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
        delete driveInfo;
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

void RGE_Base_Game::setVersion(float p1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x004226C0
    rge_game_options.versionValue = p1;
}
void RGE_Base_Game::setScenarioGame(int p1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x004226B0
    rge_game_options.scenarioGameValue = (unsigned char)p1;
}
void RGE_Base_Game::setCampaignGame(int p1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422700
    campaignGameValue = p1;
}
void RGE_Base_Game::setSavedGame(int p1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422710
    savedGameValue = p1;
}
void RGE_Base_Game::setSinglePlayerGame(int p1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422720
    rge_game_options.singlePlayerGameValue = (unsigned char)p1;
    rge_game_options.multiplayerGameValue = (unsigned char)(p1 == 0);
}
void RGE_Base_Game::setMultiplayerGame(int p1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422740
    rge_game_options.multiplayerGameValue = (unsigned char)p1;
    rge_game_options.singlePlayerGameValue = (unsigned char)(p1 == 0);
}
void RGE_Base_Game::setMapSize(int p1, int p2, int p3) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422760
    rge_game_options.mapXSizeValue = (unsigned char)p1;
    rge_game_options.mapYSizeValue = (unsigned char)p2;
    rge_game_options.mapZSizeValue = (unsigned char)p3;
}
void RGE_Base_Game::setAllowCheatCodes(int p1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422790
    rge_game_options.allowCheatCodesValue = (unsigned char)p1;
}
void RGE_Base_Game::setCheatNotification(int p1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x004227A0
    rge_game_options.cheatNotificationValue = (unsigned char)p1;
}
void RGE_Base_Game::setFullVisibility(int p1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x004227B0
    rge_game_options.fullVisibilityValue = (unsigned char)p1;
}
void RGE_Base_Game::setFogOfWar(int p1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x004227C0
    rge_game_options.fogOfWarValue = (unsigned char)p1;
}
void RGE_Base_Game::setColoredChat(int p1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x004227D0
    rge_game_options.coloredChatValue = (unsigned char)p1;
}
void RGE_Base_Game::setGameDeveloperMode(int p1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x004227F0
    rge_game_options.gameDeveloperModeValue = (unsigned char)p1;
}
void RGE_Base_Game::setDifficulty(int p1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422870
    rge_game_options.difficultyValue = (unsigned char)p1;
}
void RGE_Base_Game::setPlayerCDAndVersion(int p1, int p2) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422850
    rge_game_options.playerCDAndVersionValue[p1] = (unsigned char)p2;
}
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
void RGE_Base_Game::setPlayerTeam(int p1, int p2) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422880
    rge_game_options.playerTeamValue[p1] = (unsigned char)p2;
}
void RGE_Base_Game::setPathFinding(unsigned char p1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x004228A0
    pathFindingValue = p1;
}
void RGE_Base_Game::setMpPathFinding(unsigned char p1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x004228B0
    rge_game_options.mpPathFindingValue = p1;
}
void RGE_Base_Game::setNumberPlayers(int p1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x004227E0
    rge_game_options.numberPlayersValue = (unsigned char)p1;
}
void RGE_Base_Game::setScenarioName(char* p1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x004226D0
    strncpy(rge_game_options.scenarioNameValue, p1, 0x80);
    rge_game_options.scenarioNameValue[0x7f] = '\0';
}

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
        L = this->debugLog;
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
        this->error_code = 2;
        return 0;
    }

    if (do_fps_log != 0) {
        fps_log = fopen("c:\\fps.txt", "w");
        if (fps_log == nullptr) {
            do_fps_log = 0;
        }
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
    if ((((memStatus.dwTotalPageFile < 0x1400000) || (memStatus.dwTotalVirtual < 0xa00000)) &&
         ((memStatus.dwTotalPageFile < 0xa00000) || (memStatus.dwTotalVirtual < 0x1400000))) &&
        (memStatus.dwTotalVirtual < 0x1e00000)) {
        this->error_code = 0x16;
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

    // Drive Info (ASM 0x0041bf40)
    driveInfo = new (std::nothrow) DriveInformation();
    if (driveInfo == nullptr) {
        return 0;
    }
    
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
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041FC90
    if (this->prog_info->verify_cd == 0) {
        return 1;
    }

    if (p1 > 0) {
        int iVar4 = 0;
        uint uVar5 = 0;
        uint uVar1 = 0;
        do {
            uVar1 = uVar5 + 1;
            int iVar2 = this->comm_handler->GetPlayerHumanity(uVar1);
            if (iVar2 == 2) {
                iVar2 = this->playerHasCD((int)uVar5);
                if (iVar2 != 0) {
                    iVar4 = iVar4 + 1;
                }
            }
            uVar5 = uVar1;
        } while ((int)uVar1 < 9);
        return (uint)(p1 <= this->prog_info->max_players_per_cd * iVar4);
    }

    if (force_cd != 0) {
        return 1;
    }

    char* pcVar3 = this->registry->RegGetAscii(0, "CDPath");
    if (pcVar3 == nullptr) {
        return 0;
    }

    int iVar4 = GetDriveTypeA(pcVar3);
    if (iVar4 != 5) {
        return 0;
    }

    unsigned long vol_ser_num = 0;
    unsigned long file_sys_flags = 0;
    unsigned long max_comp_len = 0;
    char vol_name[256];
    char file_sys_name[256];

    int ok = GetVolumeInformationA(
        pcVar3, vol_name, 0x100, &vol_ser_num, &max_comp_len, &file_sys_flags, file_sys_name, 0x100);
    if (ok == 0) {
        return 0;
    }

    iVar4 = stricmp(vol_name, this->prog_info->vol_name);
    return (uint)(iVar4 == 0);
}

void RGE_Base_Game::set_mouse_cursor(void* p1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00420500
    this->mouse_cursor = p1;
    if (p1 != nullptr) {
        last_mouse_cursor = p1;
    }

    if ((this->is_mouse_on != 0) && ((this->custom_mouse == 0) || (this->windows_mouse != 0))) {
        SetCursor((HCURSOR)this->mouse_cursor);
        SetClassLongA((HWND)this->prog_window, GCL_HCURSOR, (LONG)this->mouse_cursor);
    }
}

void RGE_Base_Game::set_mouse_facet(long p1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00420560
    if (this->mouse_pointer) {
        this->mouse_pointer->set_facet((int)p1);
    }
}

void RGE_Base_Game::set_windows_mouse(int p1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00420440
    if (this->custom_mouse == 0) {
        this->windows_mouse = 1;
    } else {
        this->windows_mouse = p1;
        if (this->windows_mouse == 0) {
            SetCursor(nullptr);
            SetClassLongA((HWND)this->prog_window, GCL_HCURSOR, 0);
            if (this->is_mouse_on == 0) {
                this->mouse_pointer->off();
            } else {
                this->mouse_pointer->on();
            }
            return;
        }
    }

    this->mouse_pointer->off();
    if (this->is_mouse_on == 0) {
        SetCursor(nullptr);
        SetClassLongA((HWND)this->prog_window, GCL_HCURSOR, 0);
        return;
    }
    SetCursor((HCURSOR)this->mouse_cursor);
    SetClassLongA((HWND)this->prog_window, GCL_HCURSOR, (LONG)this->mouse_cursor);
}

void RGE_Base_Game::get_mouse_info(uint param_1, long param_2, tagPOINT* param_3, int* param_4, int* param_5, int* param_6, int* param_7) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00420270
    uint x = (uint)(param_2 & 0xFFFF);
    uint y = (uint)((ulong)param_2 >> 16);

    param_3->x = x;
    param_3->y = y;
    if (x > 60000) {
        param_3->x = (long)(x - 0x10000);
    }
    if (y > 60000) {
        param_3->y = (long)(y - 0x10000);
    }

    *param_4 = (param_1 & MK_LBUTTON) != 0;
    *param_5 = (param_1 & MK_RBUTTON) != 0;
    *param_6 = (param_1 & MK_CONTROL) != 0;
    *param_7 = (param_1 & MK_SHIFT) != 0;
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

void RGE_Base_Game::set_screen_size(long param_1, long param_2) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422B10
    if (this->draw_area == nullptr || this->draw_system == nullptr || this->prog_window == nullptr) {
        return;
    }
    if (this->draw_area->Width == param_1 && this->draw_area->Height == param_2) {
        return;
    }

    if (this->draw_system->DrawType == 2 && this->draw_system->ScreenMode == 2) {
        SetCursor(nullptr);
        SetClassLongA((HWND)this->prog_window, GCL_HCURSOR, 0);
        if (this->mouse_pointer != nullptr) {
            this->mouse_pointer->reset();
        }
        this->draw_system->SetDisplaySize(param_1, param_2, 8);
        this->draw_system->CheckSurfaces();
        this->draw_system->ClearRestored();
        this->set_render_all();
        restore_mouse_after_paint = 1;
        return;
    }

    HDC desktop_dc = CreateICA("DISPLAY", nullptr, nullptr, nullptr);
    int desktop_w = 0;
    int desktop_h = 0;
    if (desktop_dc != nullptr) {
        desktop_w = GetDeviceCaps(desktop_dc, HORZRES);
        desktop_h = GetDeviceCaps(desktop_dc, VERTRES);
        DeleteDC(desktop_dc);
    }

    if (param_1 <= desktop_w && param_2 <= desktop_h) {
        if (desktop_w == param_1 && desktop_h == param_2) {
            this->window_style = 0x92080000;
            SetWindowLongA((HWND)this->prog_window, GWL_EXSTYLE, this->window_style);
            SetWindowLongA((HWND)this->prog_window, GWL_STYLE, this->window_style);
        } else {
            this->window_style = 0x12CA0000;
            SetWindowLongA((HWND)this->prog_window, GWL_STYLE, this->window_style);
            SetWindowLongA((HWND)this->prog_window, GWL_EXSTYLE, this->window_style);
        }

        SetWindowPos((HWND)this->prog_window, nullptr, 0, 0, (int)param_1, (int)param_2, SWP_NOMOVE | SWP_NOZORDER);

        RECT win_rect;
        RECT client_rect;
        GetWindowRect((HWND)this->prog_window, &win_rect);
        GetClientRect((HWND)this->prog_window, &client_rect);
        if (client_rect.right != param_1 || client_rect.bottom != param_2) {
            SetWindowPos(
                (HWND)this->prog_window,
                nullptr,
                win_rect.left,
                win_rect.top,
                ((int)param_1 + (win_rect.right - win_rect.left)) - client_rect.right,
                ((int)param_2 + (win_rect.bottom - win_rect.top)) - client_rect.bottom,
                SWP_NOZORDER);
        }
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
char* RGE_Base_Game::get_string2(int p1, long p2, long p3, char* p4, int p5) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041CA10
    (void)p3;
    p4[0] = '\0';

    if (p1 == 1) {
        switch (p2) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 0xE:
        case 0xF:
            return this->get_string(0x7D2, 0, p4, p5);
        case 7:
        case 8:
        case 0xB:
        case 0xD:
        case 0x11:
            return this->get_string(0x7D3, 0, p4, p5);
        case 9:
        case 0x10:
            return this->get_string(0x7D5, 0, p4, p5);
        case 10:
        case 0xC:
            return this->get_string(0x7D4, 0, p4, p5);
        case 0x12:
            return this->get_string(0x7DC, 0, p4, p5);
        case 0x13:
            return this->get_string(0x7DB, 0, p4, p5);
        case 0x14:
            return this->get_string(0x7DD, 0, p4, p5);
        case 0x15:
            return this->get_string(0x7DE, 0, p4, p5);
        case 0x16:
            return this->get_string(0x7DF, 0, p4, p5);
        case 0x17:
            return this->get_string(0x7E0, 0, p4, p5);
        default:
            break;
        }
    } else if (p1 == 2) {
        return this->get_string((int)p2, 0, p4, p5);
    }

    p4[p5 - 1] = '\0';
    return p4;
}
unsigned char RGE_Base_Game::check_prog_argument(const char* p1) {
    // Source of truth: basegame.cpp.decomp @ 0x00422CC0
    if (!this->prog_info || !this->prog_info->cmd_line || !p1) return 0;
    char cmd_line[256];
    char token[128];
    strncpy(cmd_line, this->prog_info->cmd_line, 255);
    cmd_line[255] = '\0';
    strncpy(token, p1, sizeof(token) - 1);
    token[sizeof(token) - 1] = '\0';
    CharUpperA(cmd_line);
    CharUpperA(token);
    return (strstr(cmd_line, token) != nullptr) ? 1 : 0;
}
void RGE_Base_Game::close() {
    if (this->prog_window) {
        SendMessageA((HWND)this->prog_window, WM_CLOSE, 0, 0);
    }
}

int RGE_Base_Game::check_expiration() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041FDE0
    if (this->prog_info == nullptr) {
        return 1;
    }

    tm kill_def;
    memset(&kill_def, 0, sizeof(kill_def));
    kill_def.tm_mon = (int)this->prog_info->expire_month - 1;
    kill_def.tm_mday = (int)this->prog_info->expire_day;
    kill_def.tm_year = (int)this->prog_info->expire_year;

    time_t expire_time = mktime(&kill_def);
    time_t now = 0;
    time(&now);
    return (now <= expire_time) ? 1 : 0;
}

int RGE_Base_Game::check_multi_copies() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041FE50
    this->prog_mutex = CreateMutexA(nullptr, 1, this->prog_info->menu_name);
    if (GetLastError() != ERROR_ALREADY_EXISTS) {
        if (this->prog_mutex != nullptr) {
            ReleaseMutex(this->prog_mutex);
        }
        return 1;
    }

    HWND existing = FindWindowA(this->prog_info->menu_name, this->prog_info->prog_title);
    if (existing != nullptr) {
        if (this->check_prog_argument("LOBBY") != 0) {
            SendMessageA(existing, WM_CLOSE, 0, 0);
            if (this->prog_mutex != nullptr) {
                ReleaseMutex(this->prog_mutex);
            }
            return 1;
        }

        if (IsIconic(existing) != 0) {
            ShowWindow(existing, SW_RESTORE);
        }
        SetForegroundWindow(existing);
        HWND popup = GetLastActivePopup(existing);
        BringWindowToTop(popup);
    }

    if (this->prog_mutex != nullptr) {
        ReleaseMutex(this->prog_mutex);
        CloseHandle(this->prog_mutex);
        this->prog_mutex = nullptr;
    }
    return 0;
}

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
    // Fully verified. Source of truth: basegame.cpp.asm @ 0x00420150
    RGE_Game_World* pWorld = this->world;
    if ((pWorld != nullptr) && (p1 < pWorld->player_num)) {
        pWorld->curr_player = p1;
        this->world->map->clear_map_view_info();
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
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00420180
    if (this->prog_mode == 7) {
        return 0;
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

unsigned char RGE_Base_Game::GetWorldChecksums(long& checksum_out, long& position_checksum_out, long& action_checksum_out) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422960
    int player = 0;
    checksum_out = 0;
    position_checksum_out = 0;
    action_checksum_out = 0;

    RGE_Game_World* w = this->world;
    if (w != nullptr) {
        if (0 < w->player_num) {
            do {
                long checksum = 0;
                long pos_checksum = 0;
                long action_checksum = 0;
                w->players[player]->get_checksums(checksum, pos_checksum, action_checksum);
                checksum_out = checksum_out + checksum;
                position_checksum_out = position_checksum_out + pos_checksum;
                action_checksum_out = action_checksum_out + action_checksum;
                player = player + 1;
                w = this->world;
            } while (player < w->player_num);
        }
        return '\x01';
    }
    return '\0';
}

int RGE_Base_Game::create_dialog(TPanel** out_dialog, TPanel* dialog) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x004200D0
    if (out_dialog) {
        *out_dialog = nullptr;
    }
    if (dialog == nullptr) {
        return 0;
    }
    if (dialog->error_code != 0) {
        delete dialog;
        return 0;
    }
    if (out_dialog) {
        *out_dialog = dialog;
    }
    return 1;
}

void RGE_Base_Game::delete_dialog(TPanel** dialog) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00420110
    if (dialog != nullptr && *dialog != nullptr) {
        delete *dialog;
        *dialog = nullptr;
    }
}

TPanel* RGE_Base_Game::get_view_panel() { return nullptr; }
TPanel* RGE_Base_Game::get_map_panel() { return nullptr; }
RGE_Scenario_Header* RGE_Base_Game::new_scenario_header(RGE_Scenario* p1) { return new RGE_Scenario_Header(p1); }
RGE_Scenario_Header* RGE_Base_Game::new_scenario_header(int p1) { return new RGE_Scenario_Header(p1); }

void RGE_Base_Game::write_scenario_header(int param_1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041CDA0
    RGE_Scenario_Header* header = this->new_scenario_header(this->world->scenario);
    if (header != nullptr) {
        header->save(param_1);
        delete header;
        return;
    }

    long header_size = 0;
    rge_write_uncompressed(param_1, &header_size, 4);
}

RGE_Scenario* RGE_Base_Game::new_scenario_info(int p1) { return nullptr; }
void RGE_Base_Game::notification(int p1, long p2, long p3, long p4, long p5) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041C6E0
    (void)p1;
    (void)p2;
    (void)p3;
    (void)p4;
    (void)p5;
}
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
void RGE_Base_Game::send_game_options() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x004220D0
    if (this->comm_handler != nullptr) {
        this->comm_handler->FreeOptions();
        char* options = (char*)::operator new(0xA8 + 1, std::nothrow);
        if (options == nullptr) {
            return;
        }
        ::RGE_Game_Options local_options;
        this->get_game_options(&local_options);
        memcpy(options, &local_options, 0xA8);
        this->comm_handler->OptionsData = options;
        this->comm_handler->PlayerOptions.DataSizeToFollow = 0xA8;
        if (this->comm_handler->MeHost != 0) {
            this->comm_handler->PlayerOptions.NeedsToBeSent = '\x01';
        }
    }
}

void RGE_Base_Game::receive_game_options() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x004220F0
    if (this->comm_handler != nullptr) {
        ulong size = this->comm_handler->PlayerOptions.DataSizeToFollow;
        ::RGE_Game_Options* options = (::RGE_Game_Options*)this->comm_handler->OptionsData;
        if ((options != nullptr) && (size == 0xA8)) {
            this->set_game_options(options);
        }
    }
}

void RGE_Base_Game::set_game_options(::RGE_Game_Options* param_1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422130
    this->setVersion(param_1->versionValue);
    this->setScenarioGame((uint)param_1->scenarioGameValue);
    this->setScenarioName(param_1->scenarioNameValue);
    this->setSinglePlayerGame((uint)param_1->singlePlayerGameValue);
    this->setMultiplayerGame((uint)param_1->multiplayerGameValue);
    this->setMapSize((uint)param_1->mapXSizeValue, (uint)param_1->mapYSizeValue, (uint)param_1->mapZSizeValue);
    this->setAllowCheatCodes((uint)param_1->allowCheatCodesValue);
    this->setCheatNotification((uint)param_1->cheatNotificationValue);
    this->setFullVisibility((uint)param_1->fullVisibilityValue);
    this->setFogOfWar((uint)param_1->fogOfWarValue);
    this->setColoredChat((uint)param_1->coloredChatValue);
    this->setNumberPlayers((uint)param_1->numberPlayersValue);
    this->setGameDeveloperMode((uint)param_1->gameDeveloperModeValue);
    this->setDifficulty((uint)param_1->difficultyValue);
    this->setMpPathFinding(param_1->mpPathFindingValue);
    for (int i = 0; i < 9; ++i) {
        this->setPlayerCDAndVersion(i, param_1->playerCDAndVersionValue[i]);
        this->setPlayerTeam(i, (uint)param_1->playerTeamValue[i]);
    }
}

void RGE_Base_Game::get_game_options(::RGE_Game_Options* param_1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422260
    param_1->versionValue = this->version();
    param_1->scenarioGameValue = (uchar)this->scenarioGame();
    strncpy(param_1->scenarioNameValue, this->scenarioName(), sizeof(param_1->scenarioNameValue) - 1);
    param_1->scenarioNameValue[sizeof(param_1->scenarioNameValue) - 1] = '\0';
    param_1->singlePlayerGameValue = (uchar)this->singlePlayerGame();
    param_1->multiplayerGameValue = (uchar)this->multiplayerGame();
    param_1->mapXSizeValue = (uchar)this->mapXSize();
    param_1->mapYSizeValue = (uchar)this->mapYSize();
    param_1->mapZSizeValue = (uchar)this->mapZSize();
    param_1->allowCheatCodesValue = (uchar)this->allowCheatCodes();
    param_1->cheatNotificationValue = (uchar)this->cheatNotification();
    param_1->fullVisibilityValue = (uchar)this->fullVisibility();
    param_1->fogOfWarValue = (uchar)this->fogOfWar();
    param_1->coloredChatValue = (uchar)this->coloredChat();
    param_1->numberPlayersValue = (uchar)this->numberPlayers();
    param_1->gameDeveloperModeValue = (uchar)this->gameDeveloperMode();
    param_1->difficultyValue = (uchar)this->difficulty();
    param_1->mpPathFindingValue = this->mpPathFinding();
    for (int i = 0; i < 9; ++i) {
        param_1->playerCDAndVersionValue[i] = this->playerCDAndVersion(i);
        param_1->playerTeamValue[i] = (uchar)this->playerTeam(i);
    }
}

char* RGE_Base_Game::gameSummary() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422690
    DAT_0062c49c[0] = '\0';
    return DAT_0062c49c;
}

int RGE_Base_Game::processCheatCode(int p1, char* p2) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041C6F0
    (void)p1;
    (void)p2;
    return 0;
}
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
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041D0A0
    if (this->prog_info == nullptr || this->prog_info->cmd_line == nullptr) {
        return 1;
    }

    char cmd_line[1024];
    strncpy(cmd_line, this->prog_info->cmd_line, sizeof(cmd_line) - 1);
    cmd_line[sizeof(cmd_line) - 1] = '\0';
    CharUpperA(cmd_line);

    if (cmd_has_any3(cmd_line, "NOSTARTUP", "NO STARTUP", "NO_STARTUP") != 0) {
        this->prog_info->skip_startup = 1;
    }
    if (cmd_has_any3(cmd_line, "SYSTEMMEMORY", "SYSTEM MEMORY", "SYSTEM_MEMORY") != 0) {
        this->prog_info->use_sys_mem = 1;
    }
    if (cmd_has_any3(cmd_line, "MIDIMUSIC", "MIDI MUSIC", "MIDI_MUSIC") != 0) {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 0;
        this->prog_info->use_ima = 0;
        this->prog_info->use_midi = 1;
        this->prog_info->use_wave_music = 0;
    }
    if (cmd_has_token(cmd_line, "MSYNC") != 0) {
        this->mouse_blit_sync = 1;
    }
    DDSys_CanColorFill = (cmd_has_token(cmd_line, "MFILL") == 0) ? 1 : 0;
    if (cmd_has_any3(cmd_line, "NOSOUND", "NO SOUND", "NO_SOUND") != 0) {
        this->prog_info->use_sound = 0;
    }
    if (cmd_has_token(cmd_line, "640") != 0) {
        this->prog_info->main_wid = 640;
        this->prog_info->main_hgt = 480;
    }
    if (cmd_has_token(cmd_line, "800") != 0) {
        this->prog_info->main_wid = 800;
        this->prog_info->main_hgt = 600;
    }
    if (cmd_has_token(cmd_line, "1024") != 0) {
        this->prog_info->main_wid = 1024;
        this->prog_info->main_hgt = 768;
    }

    if (cmd_has_token(cmd_line, "ALLCP") != 0) {
        all_cp = 1;
        do_run_log = 1;
        this->comm_speed = 0;
        debug_timeGetTime_on = 1;
        debug_timeGetTime_interval = 10;
        do_fixed_update = 1;
        fixed_update_time = 0x14;
    }

    long parsed_value = 0;
    if (cmd_parse_long_value(cmd_line, "RESEND1", &parsed_value) != 0) {
        resend_adj1 = (int)parsed_value;
    }
    if (cmd_parse_long_value(cmd_line, "RESEND2", &parsed_value) != 0) {
        resend_adj2 = (int)parsed_value;
    }

    if (cmd_has_any3(cmd_line, "NOMOUSE", "NO MOUSE", "NO_MOUSE") != 0) {
        this->custom_mouse = 0;
    }
    if (cmd_has_token(cmd_line, "WING") != 0) {
        this->prog_info->full_screen = 0;
        this->prog_info->use_dir_draw = 0;
    }
    if (cmd_has_any3(cmd_line, "DIRECTDRAW", "DIRECT DRAW", "DIRECT_DRAW") != 0) {
        this->prog_info->use_dir_draw = 1;
    }
    if (cmd_has_any3(cmd_line, "FULLSCREEN", "FULL SCREEN", "FULL_SCREEN") != 0) {
        this->prog_info->full_screen = 1;
        this->prog_info->use_dir_draw = 1;
    }
    if (cmd_has_any3(cmd_line, "VIDEOMEMORY", "VIDEO MEMORY", "VIDEO_MEMORY") != 0) {
        this->prog_info->use_sys_mem = 0;
    }
    if (cmd_has_any3(cmd_line, "STREAMMUSIC", "STREAM MUSIC", "STREAM_MUSIC") != 0) {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 0;
        this->prog_info->use_ima = 0;
        this->prog_info->use_midi = 0;
        this->prog_info->use_wave_music = 1;
    }
    if (cmd_has_any3(cmd_line, "IMAMUSIC", "IMA MUSIC", "IMA_MUSIC") != 0) {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 0;
        this->prog_info->use_ima = 1;
        this->prog_info->use_midi = 0;
        this->prog_info->use_wave_music = 0;
    }
    if (cmd_has_any3(cmd_line, "FASTVIEW", "FAST VIEW", "FAST_VIEW") != 0) {
        this->prog_info->fast_view = 1;
    }
    if (cmd_has_any3(cmd_line, "SLOWVIEW", "SLOW VIEW", "SLOW_VIEW") != 0) {
        this->prog_info->fast_view = 0;
    }
    if (cmd_has_any3(cmd_line, "ONEBUTTON", "ONE BUTTON", "ONE_BUTTON") != 0) {
        this->prog_info->interface_style = 1;
    }
    if (cmd_has_any3(cmd_line, "TWOBUTTON", "TWO BUTTON", "TWO_BUTTON") != 0) {
        this->prog_info->interface_style = 2;
    }
    if (cmd_has_token(cmd_line, "RUNLOG") != 0) {
        do_run_log = 1;
    }
    if (cmd_has_token(cmd_line, "SYNCMSG") != 0) {
        this->comm_syncmsg = 1;
    }
    if (cmd_has_token(cmd_line, "DROPPACKETS") != 0) {
        this->comm_droppackets = 1;
    }
    if (cmd_has_token(cmd_line, "NOCOMMSPEED") != 0) {
        this->comm_speed = 0;
    }
    if (cmd_has_token(cmd_line, "SYNCSTOP") != 0) {
        this->comm_syncstop = 1;
    }
    if (cmd_has_token(cmd_line, "STEPMODE") != 0) {
        this->comm_stepmode = 1;
    }
    if (cmd_has_any3(cmd_line, "SQUAREOUTLINE", "SQUARE OUTLINE", "SQUARE_OUTLINE") != 0) {
        this->outline_type = 0;
    }
    if (cmd_has_any3(cmd_line, "CUBEOUTLINE", "CUBE OUTLINE", "CUBE_OUTLINE") != 0) {
        this->outline_type = 1;
    }
    if (cmd_has_any3(cmd_line, "GROUNDOUTLINE", "GROUND OUTLINE", "GROUND_OUTLINE") != 0) {
        this->outline_type = 2;
    }
    if (cmd_has_any3(cmd_line, "EDGEOUTLINE", "EDGE OUTLINE", "EDGE_OUTLINE") != 0) {
        this->outline_type = 3;
    }
    if (cmd_has_any3(cmd_line, "CUSTOMMOUSE", "CUSTOM MOUSE", "CUSTOM_MOUSE") != 0) {
        this->custom_mouse = 1;
    }
    if (cmd_has_token(cmd_line, "NOCP") != 0) {
        useComputerPlayers = 0;
    }
    if (cmd_has_token(cmd_line, "LOGAI") != 0) {
        startLoggingAI = 1;
    }
    if (cmd_has_token(cmd_line, "NOLOGSTATUS") != 0) {
        logStatusOn = 0;
    }
    if (cmd_has_token(cmd_line, "DOLOGSTATUS") != 0) {
        logStatusOn = 1;
    }
    if (cmd_has_token(cmd_line, "NOAICHEAT") != 0) {
        allowAIToCheat = 0;
    }
    if (cmd_has_token(cmd_line, "NOCHATCHEATCODES") != 0) {
        chatCheatCodes = 0;
    }
    if (cmd_has_token(cmd_line, "LOGUPDATECHANGES") != 0) {
        logUpdateChanges = 1;
    }
    if (cmd_has_token(cmd_line, "UIP") != 0) {
        useInfluencePlacement = 1;
    }
    if (cmd_has_token(cmd_line, "ALLGRASS") != 0) {
        all_grassland_on = 1;
    }
    if (cmd_has_token(cmd_line, "ALLCP") != 0) {
        all_cp = 1;
    }
    if (cmd_has_token(cmd_line, "ALLCP1") != 0) {
        all_cp = 2;
    }
    if (cmd_has_token(cmd_line, "NOPATHLIMIT") != 0) {
        numberPathingIterations = -1;
    }
    if (cmd_has_token(cmd_line, "UNP") != 0) {
        useNewPathing = -1;
    }
    if (cmd_has_token(cmd_line, "COLORLOG") != 0) {
        do_color_log = 1;
    }
    if (cmd_parse_long_value(cmd_line, "LOGAI", &parsed_value) != 0) {
        specificAIPlayerToLog = (int)parsed_value;
    }
    if (cmd_parse_long_value(cmd_line, "LOGDEBUG", &parsed_value) != 0) {
        logDebugID = (int)parsed_value;
    }
    if (cmd_has_token(cmd_line, "NOPATHCAP") != 0) {
        pathingCapValue = -1;
    }
    if (cmd_has_token(cmd_line, "GAMECD") != 0) {
        force_cd = 1;
    }
    if (cmd_has_token(cmd_line, "1280") != 0) {
        this->prog_info->main_wid = 1280;
        this->prog_info->main_hgt = 1024;
    }
    if (cmd_has_any3(cmd_line, "LOGFPS", "LOG FPS", "LOG_FPS") != 0) {
        do_fps_log = 1;
    }
    if (cmd_has_token(cmd_line, "DDERRORLOG") != 0) {
        Sys_DDLOG_Enable = 1;
        Sys_DDLOG_ErrorOn = 1;
    }
    if (cmd_has_token(cmd_line, "DDLOG") != 0) {
        Sys_DDLOG_Enable = 1;
        Sys_DDLOG_ErrorOn = 0;
    }
    if (cmd_has_token(cmd_line, "DDFLUSHLOG") != 0) {
        DDlogAutoFlush = 1;
    }
    if (cmd_has_token(cmd_line, "DDNOFLUSHLOG") != 0) {
        DDlogAutoFlush = 0;
    }
    if (cmd_has_token(cmd_line, "DDLOCKLOG") != 0) {
        debug_log_lock = 1;
    }
    if (cmd_has_token(cmd_line, "LOGRANDOM") != 0) {
        do_debug_random = 1;
    }
    if (cmd_has_token(cmd_line, "FIXEDUPDATE") != 0) {
        debug_timeGetTime_on = 1;
        do_fixed_update = 1;
    }
    if (cmd_has_token(cmd_line, "LOGACTION") != 0) {
        debugActions = 1;
    }
    if (cmd_has_token(cmd_line, "RES_WARN") != 0) {
        RESFILE_Set_Missing_Flag(1);
    }

    char value_buf[512];
    if (cmd_parse_value(cmd_line, "SCENARIOS", value_buf, sizeof(value_buf)) != 0) {
        strncpy(this->prog_info->scenario_dir, value_buf, sizeof(this->prog_info->scenario_dir) - 2);
        this->prog_info->scenario_dir[sizeof(this->prog_info->scenario_dir) - 2] = '\0';
        strcat(this->prog_info->scenario_dir, "\\");
    }
    if (cmd_parse_value(cmd_line, "WORLD", value_buf, sizeof(value_buf)) != 0) {
        strncpy(this->prog_info->world_db_file, value_buf, sizeof(this->prog_info->world_db_file) - 1);
        this->prog_info->world_db_file[sizeof(this->prog_info->world_db_file) - 1] = '\0';
    }
    if (cmd_parse_long_value(cmd_line, "FIXEDUPDATE", &parsed_value) != 0) {
        debug_timeGetTime_on = 1;
        do_fixed_update = 1;
        fixed_update_time = (int)parsed_value;
    }
    if (cmd_parse_long_value(cmd_line, "AISPEED", &parsed_value) != 0) {
        debug_timeGetTime_on = 1;
        do_fixed_update = 1;
        debug_timeGetTime_interval = (int)parsed_value;
    }
    if (cmd_parse_long_value(cmd_line, "RANDOMGAME", &parsed_value) != 0) {
        this->random_game_seed = (int)parsed_value;
    }
    if (cmd_parse_long_value(cmd_line, "RANDOMMAP", &parsed_value) != 0) {
        this->random_map_seed = (int)parsed_value;
    }
    if (cmd_parse_value(cmd_line, "DRAWLOG", value_buf, sizeof(value_buf)) != 0) {
        strncpy(draw_log_name, value_buf, sizeof(draw_log_name) - 1);
        draw_log_name[sizeof(draw_log_name) - 1] = '\0';
    }
    if (cmd_has_token(cmd_line, "DRAWLOG") != 0) {
        do_draw_log = 1;
    }
    if (cmd_has_token(cmd_line, "SAFEDRAWLOG") != 0) {
        safe_draw_log = 1;
    }
    if (cmd_parse_value(cmd_line, "DATA", value_buf, sizeof(value_buf)) != 0) {
        strncpy(this->prog_info->game_data_file, value_buf, sizeof(this->prog_info->game_data_file) - 1);
        this->prog_info->game_data_file[sizeof(this->prog_info->game_data_file) - 1] = '\0';
    }
    if (cmd_has_any3(cmd_line, "CDAUDIO", "CD AUDIO", "CD_AUDIO") != 0) {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 1;
        this->prog_info->use_ima = 0;
        this->prog_info->use_midi = 0;
        this->prog_info->use_wave_music = 0;
    }
    if (cmd_has_token(cmd_line, "WINDOW") != 0) {
        this->prog_info->full_screen = 0;
    }
    if (cmd_has_any3(cmd_line, "FILEFIRST", "FILE FIRST", "FILE_FIRST") != 0) {
        shape_file_first = 1;
        sound_file_first = 1;
    }
    if (cmd_has_any3(cmd_line, "LOGCOMM", "LOG COMM", "LOG_COMM") != 0) {
        this->log_comm = 1;
        if (L != nullptr) {
            L->LogFile(1);
            L->LogTimestamp(1);
        }
    }
    if (cmd_has_any3(cmd_line, "LOGOUTPUT", "LOG OUTPUT", "LOG_OUTPUT") != 0) {
        log_output = 1;
        if (L != nullptr) {
            L->LogOutput(1);
        }
    }
    if (cmd_has_token(cmd_line, "DEVELOPER") != 0) {
        this->setGameDeveloperMode(1);
    }
    if (cmd_parse_long_value(cmd_line, "SPEED1", &parsed_value) != 0) {
        speed_val1 = (int)parsed_value;
    }
    if (cmd_parse_long_value(cmd_line, "SPEED2", &parsed_value) != 0) {
        speed_val2 = (int)parsed_value;
    }
    if ((this->prog_info->use_sound == 0) || cmd_has_any3(cmd_line, "NOMUSIC", "NO MUSIC", "NO_MUSIC") != 0) {
        this->prog_info->use_music = 0;
    }
    if (this->prog_info->use_dir_draw == 1 && this->prog_info->full_screen == 1) {
        this->custom_mouse = 1;
    }
    if (cmd_has_any3(cmd_line, "NORMALMOUSE", "NORMAL MOUSE", "NORMAL_MOUSE") != 0) {
        this->custom_mouse = 0;
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
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041EBF0, basegame.cpp.asm @ 0x0041EBF0
    int custom_mouse_reg = this->registry->RegGetInt(0, "Custom Mouse");

    int custom_type = 0;
    if (custom_mouse_reg == -1) {
        this->registry->RegSetInt(0, "Custom Mouse", 0);
    } else if (custom_mouse_reg == 1) {
        custom_type = 1;
    } else if (custom_mouse_reg == 2) {
        this->custom_mouse = 0;
        custom_type = (int)this;
    }

    this->mouse_pointer = new (std::nothrow) TMousePointer(custom_type);
    if (this->mouse_pointer == nullptr) {
        return 0;
    }

    if (this->mouse_pointer->setup(this->custom_mouse, this->draw_area, this->prog_info->cursor_file, 51000, 10) == 0) {
        return 0;
    }

    this->mouse_off();
    return 1;
}

void* RGE_Base_Game::create_font(void* dc, int id1, int id2) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ make_font wrappers
    return this->make_font(dc, (long)id1, id2);
}

void* RGE_Base_Game::make_font(void* dc, long id, int strikeout) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041FAF0
    char face_name[256];
    char point_size_str[32];
    char style[32];

    face_name[0] = '\0';
    point_size_str[0] = '\0';
    style[0] = '\0';

    this->get_string((int)id, face_name, sizeof(face_name));
    if (face_name[0] == '\0') {
        return nullptr;
    }
    this->get_string((int)id + 1, point_size_str, sizeof(point_size_str));
    this->get_string((int)id + 2, style, sizeof(style));

    const int point_size = atoi(point_size_str);
    int weight = 400;
    if (strstr(style, "B") != nullptr || strstr(style, "b") != nullptr) {
        weight = 700;
    }
    return this->make_font(dc, face_name, point_size, weight, strikeout);
}

void* RGE_Base_Game::make_font(void* dc, char* face_name, int point_size, int weight, int strikeout) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041FBC0
    char charset_str[64];
    charset_str[0] = '\0';
    this->get_string(0x65, charset_str, sizeof(charset_str));
    const int charset = atoi(charset_str);

    LOGFONTA logfont;
    memset(&logfont, 0, sizeof(logfont));

    int log_pixels_y = 96;
    if (dc != nullptr) {
        int dpi = GetDeviceCaps((HDC)dc, LOGPIXELSY);
        if (dpi > 0) {
            log_pixels_y = dpi;
        }
    }

    logfont.lfHeight = -MulDiv(point_size, log_pixels_y, 72);
    logfont.lfWidth = 0;
    logfont.lfEscapement = 0;
    logfont.lfOrientation = 0;
    logfont.lfWeight = weight;
    logfont.lfItalic = 0;
    logfont.lfUnderline = 0;
    logfont.lfStrikeOut = (BYTE)(strikeout ? 1 : 0);
    logfont.lfCharSet = (BYTE)charset;
    logfont.lfOutPrecision = 0;
    logfont.lfClipPrecision = 0;
    logfont.lfQuality = 2;
    logfont.lfPitchAndFamily = 2;
    strncpy(logfont.lfFaceName, face_name, LF_FACESIZE - 1);
    logfont.lfFaceName[LF_FACESIZE - 1] = '\0';

    return CreateFontIndirectA(&logfont);
}

int RGE_Base_Game::setup_fonts() {
    // Fully verified. Source of truth: basegame.cpp.asm @ 0x0041F560
    this->font_num = 12;
    this->fonts = (RGE_Font*)calloc(12, sizeof(RGE_Font));
    if (!this->fonts) return 0;

    HDC hdc = (HDC)this->draw_area->GetDc((char*)"basegame::setup_fonts");
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
            this->fonts[i].font_wid = tm.tmAveCharWidth;
            this->fonts[i].font_hgt = tm.tmHeight + tm.tmExternalLeading;
            SelectObject(hdc, old_font);
        }
    }

    this->draw_area->ReleaseDc((char*)"basegame::setup_fonts");
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
    // Fully verified. Source of truth: basegame.cpp.asm @ 0x0041F2D0
    this->shape_num = 3;
    this->shapes = (TShape**)calloc(3, sizeof(TShape*));
    if (this->shapes == nullptr) {
        return 0;
    }

    for (int i = 0; i < this->shape_num; ++i) {
        this->shapes[i] = nullptr;
    }

    this->shapes[0] = new TShape((char*)"groupnum.shp", 0xC4E3);
    this->shapes[1] = new TShape((char*)"waypoint.shp", 0xC4E4);
    this->shapes[2] = new TShape((char*)"moveto.shp", 0xC4E5);
    return 1;
}

int RGE_Base_Game::setup_blank_screen() { 
    // Fully verified. Source of truth: basegame.cpp.asm @ 0x0041F730
    TScreenPanel* blank = new TScreenPanel((char*)"Blank Screen");
    if (blank == nullptr) {
        return 0;
    }

    if (blank->setup(this->draw_area, (char*)0, -1, 0) == 0) {
        return 0;
    }

    panel_system->setCurrentPanel((char*)"Blank Screen", 0);
    this->set_render_all();
    SendMessageA((HWND)this->prog_window, 0xF, 0, 0); // WM_PAINT
    return 1;
}
void RGE_Base_Game::setup_timings() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041F800
    this->timings[1].include_in_total = 1;
    this->timings[2].include_in_total = 1;
    this->timings[3].include_in_total = 1;
    this->timings[10].include_in_total = 1;
    this->timings[13].include_in_total = 1;
    this->timings[0].is_summary = 1;
    this->timings[4].is_summary = 1;
}

void RGE_Base_Game::stop_sound_system() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041F830
    TChat* chat_ptr = (TChat*)chat;
    if (chat_ptr != nullptr) {
        chat_ptr->StopSoundSystem();
    }

    if (panel_system != nullptr) {
        TPanel* panel = panel_system->currentPanel();
        if (panel != nullptr) {
            panel->stop_sound_system();
        }
    }

    if (this->world != nullptr && this->world->sound_num > 0) {
        for (int i = 0; i < this->world->sound_num; ++i) {
            RGE_Sound* world_sound = this->world->sounds[i];
            if (world_sound != nullptr) {
                world_sound->restart_sound(nullptr);
            }
        }
    }

    if (this->sounds != nullptr) {
        for (int i = 0; i < this->sound_num; ++i) {
            if (this->sounds[i] != nullptr) {
                delete this->sounds[i];
            }
        }
        free(this->sounds);
        this->sounds = nullptr;
    }

    this->shutdown_music_system();

    if (this->sound_system != nullptr) {
        long volume = this->sound_system->get_volume();
        if (this->registry != nullptr) {
            this->registry->RegSetInt(1, "Sound Volume", -volume);
        }
        delete this->sound_system;
        this->sound_system = nullptr;
        sound_driver = nullptr;
    }
}

int RGE_Base_Game::restart_sound_system() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041F920
    if (this->sound_system == nullptr) {
        if (this->setup_sound_system() == 0) {
            return 0;
        }
        if (this->setup_sounds() == 0) {
            return 0;
        }

        if (this->world != nullptr && this->world->sound_num > 0) {
            for (int i = 0; i < this->world->sound_num; ++i) {
                RGE_Sound* world_sound = this->world->sounds[i];
                if (world_sound != nullptr) {
                    world_sound->restart_sound(this->sound_system);
                }
            }
        }

        if (panel_system != nullptr) {
            TPanel* panel = panel_system->currentPanel();
            if (panel != nullptr) {
                panel->restart_sound_system();
            }
        }

        TChat* chat_ptr = (TChat*)chat;
        if (chat_ptr != nullptr) {
            chat_ptr->RestartSoundSystem(this->sound_system);
        }

        this->restart_music_system();
    }
    return 1;
}
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
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00420F60, basegame.cpp.asm @ 0x00420F60
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
    TPanel* curPanel = panel_system->currentPanel();
    if (curPanel != nullptr) {
        curPanel = panel_system->currentPanel();
        curPanel->handle_idle();
    }

    // Comm handler message receiving
    if (this->comm_handler != nullptr) {
        if (this->multiplayerGame() != 0) {
            this->comm_handler->ReceiveGameMessages();
        }
    }

    if (this->do_show_comm != 0) {
        this->show_comm();
    }

    if (this->do_show_ai != 0) {
        this->show_ai();
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
        // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00421110
        if (this->mouse_pointer->in_game_mode() == 0) {
            this->mouse_pointer->draw(0);
        } else {
            this->mouse_pointer->Poll();
        }
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
        this->draw_system->DrawArea->take_snapshot(s_dot_AoE_04d_bmp, &snapshot_number);
        return 0;
    }

    // Dispatch to virtual action_key_down
    int result = this->action_key_down(key_code, repeat_count, ctrl_down, alt_down, shift_down);
    return (result != 0) ? 1 : 0;
}
int RGE_Base_Game::handle_user_command(void* p1, uint p2, uint p3, long p4) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x004212E0, basegame.cpp.asm @ 0x004212E0
    int mp_started = this->comm_handler->MultiplayerGameStart();
    if ((mp_started != 0) && (out_of_sync == 0)) {
        if (p3 == 0x17b3) {
            int player_index = this->playerID((int)p4);
            this->world->players[player_index]->command_resign((int)p4, 1);
        } else if (p3 == 0x17b4) {
            int player_index = this->playerID((int)p4);
            this->world->players[player_index]->command_resign((int)p4, 0);
        }
    }

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
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x004213A0, basegame.cpp.asm @ 0x004213A0
    int result = this->action_command(p3, p4);
    return (result != 0) ? 1 : 0;
}
int RGE_Base_Game::handle_music_done(void* p1, uint p2, uint p3, long p4) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x004213C0, basegame.cpp.asm @ 0x004213C0
    int result = this->action_music_done();
    return (result != 0) ? 1 : 0;
}

int RGE_Base_Game::check_paint() {
    // Fully verified. Source of truth: basegame.cpp.asm @ 0x0041FF20
    tagRECT update_rect;

    if (this->prog_ready == 0) {
        this->clear_window();
        ValidateRect((HWND)this->prog_window, nullptr);
        return 0;
    }

    if (IsIconic((HWND)this->prog_window) != 0) {
        ValidateRect((HWND)this->prog_window, nullptr);
        return 0;
    }

    if (this->prog_active == 0) {
        if (GetUpdateRect((HWND)this->prog_window, (RECT*)&update_rect, 0) != 0) {
            this->draw_system->Paint(&update_rect);
        }
        ValidateRect((HWND)this->prog_window, nullptr);
        return 0;
    }

    const uchar surface_status = this->draw_system->CheckSurfaces();
    if (surface_status != 1) {
        if (surface_status == 2) {
            this->draw_system->ClearRestored();
            this->set_render_all();
        } else if (surface_status == 3) {
            ValidateRect((HWND)this->prog_window, nullptr);
            DestroyWindow((HWND)this->prog_window);
            return 0;
        }
        return 1;
    }

    return 0;
}

void RGE_Base_Game::draw_window() {
    // Source of truth: basegame.cpp.decomp draw_window @ 0x00420360
    UpdateWindow((HWND)this->prog_window);
}

void RGE_Base_Game::clear_window() {
    // Fully verified. Source of truth: basegame.cpp.asm @ 0x00420000
    if (this->prog_window != nullptr) {
        HDC dc = GetDC((HWND)this->prog_window);
        RECT rect;
        GetClientRect((HWND)this->prog_window, &rect);
        HBRUSH brush = (HBRUSH)GetStockObject(4); // BLACK_BRUSH
        FillRect(dc, &rect, brush);
        ReleaseDC((HWND)this->prog_window, dc);
    }
}

int RGE_Base_Game::handle_paint(void* p1, uint p2, uint p3, long p4) {
    // Fully verified. Source of truth: basegame.cpp.asm @ 0x004213E0
    IDirectDrawSurface* pIVar1;
    ulong uVar2;
    int iVar3;
    ulong uVar4;
    ulong uVar5;
    TPanel* pTVar6;
    ulong uVar7;

    color_log('2', '2', 4);
    uVar2 = debug_timeGetTime(kBasegameSourcePath, 0x10ea);
    iVar3 = this->check_paint();
    uVar4 = debug_timeGetTime(kBasegameSourcePath, 0x10ee);
    this->add_to_timing(5, uVar4 - uVar2);
    if (iVar3 == 0) {
        color_log('2', '_', 4);
        return 0;
    }

    int pm = this->prog_mode;
    if (((pm == 4) || (pm == 6) || (pm == 7)) && (this->draw_system->DrawType != 1 && this->custom_mouse != 0) &&
        (this->mouse_blit_sync != 0)) {
        pIVar1 = this->draw_system->PrimarySurface;
        iVar3 = (int)pIVar1->GetBltStatus(1);
        uVar2 = debug_timeGetTime(kBasegameSourcePath, 0x10fc);
        do {
            if (iVar3 != (int)0x8876021c) goto LAB_004214dc; // DDERR_WASSTILLDRAWING
            pIVar1 = this->draw_system->PrimarySurface;
            iVar3 = (int)pIVar1->GetBltStatus(1);
            uVar4 = debug_timeGetTime(kBasegameSourcePath, 0x1100);
        } while (uVar4 <= uVar2 + 100);
        this->mouse_blit_sync = 0;
    }

LAB_004214dc:
    color_log('2', 0xBA, 4);
    uVar2 = debug_timeGetTime(kBasegameSourcePath, 0x110c);
    if (rge_base_game->sound_system != nullptr) {
        rge_base_game->sound_system->play_list();
        rge_base_game->sound_system->reset_play_list();
    }
    uVar4 = debug_timeGetTime(kBasegameSourcePath, 0x1115);
    this->add_to_timing(10, uVar4 - uVar2);

    uVar2 = debug_timeGetTime(kBasegameSourcePath, 0x111c);
    if (this->erase_mouse != 0) {
        color_log('2', 'L', 4);
        if ((this->render_all == 0) && (this->custom_mouse != 0)) {
            this->mouse_pointer->erase();
        }
        this->erase_mouse = 0;
    }
    uVar4 = debug_timeGetTime(kBasegameSourcePath, 0x1127);
    uVar5 = debug_timeGetTime(kBasegameSourcePath, 0x112a);

    color_log('2', 0x16, 4);
    pTVar6 = (panel_system != nullptr) ? panel_system->currentPanel() : nullptr;
    if (pTVar6 == nullptr) {
        this->clear_window();
    } else {
        color_log(0x16, 0x16, 1);
        if (this->render_all != 0) {
            pTVar6 = (panel_system != nullptr) ? panel_system->currentPanel() : nullptr;
            pTVar6->set_redraw(TPanel::RedrawMode::RedrawFull);
        }
        pTVar6 = (panel_system != nullptr) ? panel_system->currentPanel() : nullptr;
        pTVar6->handle_paint();
        color_log(0x16, '_', 1);
    }

    color_log('2', '$', 4);
    if (DAT_0062c57c != 0) {
        DAT_0062c57c = 0;
        if (((this->prog_mode == 4) || (this->prog_mode == 5)) && (this->do_show_timings != 0)) {
            this->show_timings();
        }
    }

    uVar7 = debug_timeGetTime(kBasegameSourcePath, 0x1147);
    this->add_to_timing(2, uVar7 - uVar5);
    uVar5 = debug_timeGetTime(kBasegameSourcePath, 0x114b);

    color_log('2', 'T', 4);
    if ((this->custom_mouse != 0) && (this->windows_mouse == 0)) {
        this->mouse_pointer->draw(1);
        this->erase_mouse = 1;
    }

    uVar7 = debug_timeGetTime(kBasegameSourcePath, 0x115b);
    this->add_to_timing(8, (uVar4 - uVar2) + (uVar7 - uVar5));

    uVar2 = debug_timeGetTime(kBasegameSourcePath, 0x1160);
    color_log('2', 'E', 4);
    this->draw_system->Paint(nullptr);
    ValidateRect((HWND)this->prog_window, nullptr);
    ValidateRect((HWND)this->prog_window, nullptr);
    this->render_all = 0;
    uVar4 = debug_timeGetTime(kBasegameSourcePath, 0x1176);
    this->add_to_timing(3, uVar4 - uVar2);
    color_log('2', '_', 4);

    this->frame_count++;

    uVar2 = debug_timeGetTime(kBasegameSourcePath, 0x1182);
    if (999 < uVar2 - DAT_0062c578) {
        this->calc_timings();
        DAT_0062c57c = 1;
        DAT_0062c578 = uVar2;
    }

    if (restore_mouse_after_paint != 0) {
        if (this->mouse_pointer != nullptr) {
            this->mouse_pointer->Restore_Mouse(this->draw_area);
            if (this->is_mouse_on != 0) {
                if ((this->custom_mouse == 0) || (this->windows_mouse != 0)) {
                    SetCursor((HCURSOR)this->mouse_cursor);
                    SetClassLongA((HWND)this->prog_window, -12, (LONG)this->mouse_cursor);
                } else {
                    this->mouse_pointer->on();
                    this->mouse_pointer->draw(1);
                }
            }
            InvalidateRect((HWND)p1, nullptr, 0);
        }
        restore_mouse_after_paint = 0;
    }

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
        this->draw_system->HandleSize(p1, p2, p3, p4);
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
int RGE_Base_Game::handle_palette_changed(void* p1, uint p2, uint p3, long p4) {
    // TODO: basegame decomp parity would call TDrawSystem::HandlePaletteChanged, but this symbol is
    // not implemented in this branch yet.
    (void)p2;
    (void)p4;

    if ((void*)p3 != p1 && this->draw_system != nullptr) {
        if (this->draw_system->DrawType == 1 || this->draw_system->ScreenMode == 1) {
            this->handle_query_new_palette(p1, p2, p3, p4);
        } else if (this->prog_mode != 1) {
            this->draw_system->ModifyPalette(0, 0x100, this->draw_system->palette);
        }
    }
    return 1;
}

int RGE_Base_Game::handle_query_new_palette(void* p1, uint p2, uint p3, long p4) {
    // TODO: basegame decomp parity would call TDrawSystem::HandleQueryNewPalette, but this symbol is
    // not implemented in this branch yet.
    (void)p2;
    (void)p3;
    (void)p4;
    TDrawSystem* ds = this->draw_system;
    if (ds != nullptr && ds->DrawType != 1 && ds->ScreenMode != 1) {
        InvalidateRect((HWND)p1, nullptr, 0);
        return 1;
    }

    HDC dc = GetDC((HWND)p1);
    if (dc != nullptr) {
        void* pal = this->prog_palette;
        if (pal != nullptr) {
            SelectPalette(dc, (HPALETTE)pal, 0);
        }
        int realized = RealizePalette(dc);
        ReleaseDC((HWND)p1, dc);
        if (realized != 0) {
            InvalidateRect((HWND)p1, nullptr, 0);
        }
    }

    return 1;
}

int RGE_Base_Game::handle_close(void* p1, uint p2, uint p3, long p4) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00421B70
    if (this->action_close() == 0) {
        return 0;
    }
    if (this->draw_area != nullptr && this->draw_system != nullptr) {
        this->draw_area->Clear(nullptr, 0);
        this->draw_system->Paint(nullptr);
    }
    return 1;
}

int RGE_Base_Game::handle_destroy(void* p1, uint p2, uint p3, long p4) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00421BB0
    this->prog_ready = 0;
    if (this->is_timer != 0 && this->prog_window != nullptr) {
        KillTimer((HWND)this->prog_window, 1);
    }
    this->prog_window = nullptr;
    PostQuitMessage(0);
    return 1;
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

unsigned long RGE_Base_Game::get_accum_time(int param_1) {
    // Source of truth: basegame.cpp.decomp @ 0x0041C8F0
    return this->timings[param_1].accum_time;
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
void RGE_Base_Game::set_last_single_time(int param_1, ulong param_2) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041C890
    this->timings[param_1].last_single_time = param_2;
}

unsigned long RGE_Base_Game::get_last_time(int param_1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041C8B0
    return this->timings[param_1].last_time;
}

unsigned long RGE_Base_Game::get_last_single_time(int param_1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041C8D0
    return this->timings[param_1].last_single_time;
}

unsigned long RGE_Base_Game::get_max_time(int param_1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041C910
    return this->timings[param_1].max_time;
}

unsigned long RGE_Base_Game::get_last_max_time(int param_1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041C930
    return this->timings[param_1].last_max_time;
}

void RGE_Base_Game::calc_timings() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00421BF0
    ulong include_total = 0;

    for (int i = 0; i < 30; ++i) {
        RGE_Timing_Info* info = &this->timings[i];
        if (info->is_summary == 0) {
            info->last_time = info->accum_time;
            info->last_max_time = info->max_time;
            info->accum_time = 0;
            info->max_time = 0;
            info->start_time = debug_timeGetTime(kBasegameSourcePath, 0x12b5);
            if (info->include_in_total != 0) {
                include_total += info->last_time;
            }
        }
    }

    if (this->timings[0].start_time == 0) {
        this->timings[0].last_time = include_total;
    } else {
        ulong now = debug_timeGetTime(kBasegameSourcePath, 0x12be);
        this->timings[0].last_time = now - this->timings[0].start_time;
    }

    ulong now = debug_timeGetTime(kBasegameSourcePath, 0x12c1);
    ulong frame_total = this->timings[0].last_time;
    this->timings[0].start_time = now;

    if (include_total < frame_total) {
        this->timings[4].last_time = frame_total - include_total;
    } else {
        this->timings[4].last_time = 0;
    }

    ulong ui_last = this->timings[6].last_time;
    ulong map_last = this->timings[7].last_time;
    ulong rend_last = this->timings[2].last_time;
    if (map_last + ui_last < rend_last) {
        this->timings[9].last_time = (rend_last - ui_last) - map_last;
    } else {
        this->timings[9].last_time = 0;
    }

    if (frame_total == 0 || this->frame_count == 0) {
        this->fps = 1000;
    } else {
        ulong per_frame = frame_total / this->frame_count;
        this->fps = (per_frame == 0) ? 1000 : (1000 / per_frame);
    }

    if (frame_total == 0 || this->view_update_count == 0) {
        this->view_update_fps = 0;
    } else {
        ulong per_view = frame_total / this->view_update_count;
        this->view_update_fps = (per_view == 0) ? 0 : (1000 / per_view);
    }

    if (frame_total == 0 || this->world_update_count == 0) {
        this->world_update_fps = 0;
    } else {
        ulong per_world = frame_total / this->world_update_count;
        this->world_update_fps = (per_world == 0) ? 0 : (1000 / per_world);
    }

    this->calc_timing_text();

    if (do_fps_log != 0 && this->prog_mode == 4 && fps_log != nullptr && this->world != nullptr) {
        int other_objects = 0;
        int other_sleeping_objects = 0;
        for (int i = 1; i < this->world->player_num; ++i) {
            other_objects += this->world->players[i]->objects->number_of_objects;
            other_sleeping_objects += this->world->players[i]->sleeping_objects->number_of_objects;
        }

        ulong update_count = this->world_update_count;
        ulong per_idle = 0;
        ulong per_update = 0;
        ulong per_sound = 0;
        ulong per_comm = 0;
        ulong per_move = 0;
        ulong per_map = 0;
        ulong per_ui = 0;

        if (update_count != 0) {
            per_idle = this->timings[4].last_time / update_count;
            per_update = this->timings[13].last_time / update_count;
            per_sound = (this->timings[10].last_time + this->timings[12].last_time) / update_count;
            per_comm = this->timings[1].last_time / update_count;
            per_move = this->timings[3].last_time / update_count;
            per_map = this->timings[7].last_time / update_count;
            per_ui = this->timings[6].last_time / update_count;
        }

        RGE_Player* p0 = this->world->players[0];
        fprintf(
            fps_log,
            "%lu,%d,%d,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu\n",
            this->world->world_time,
            p0->objects->number_of_objects,
            p0->sleeping_objects->number_of_objects,
            (ulong)other_objects,
            (ulong)other_sleeping_objects,
            update_count,
            this->view_update_count,
            this->world_update_fps,
            this->view_update_fps,
            per_ui,
            this->timings[6].last_max_time,
            per_map,
            this->timings[7].last_max_time,
            per_move,
            this->timings[3].last_max_time,
            per_comm,
            this->timings[1].last_max_time,
            per_sound,
            this->timings[10].last_max_time + this->timings[12].last_max_time,
            per_update,
            this->timings[13].last_max_time,
            per_idle);
        fflush(fps_log);
    }

    this->last_frame_count = this->frame_count;
    this->last_world_update_count = this->world_update_count;
    this->last_view_update_count = this->view_update_count;
    this->frame_count = 0;
    this->world_update_count = 0;
    this->view_update_count = 0;
}

void RGE_Base_Game::calc_timing_text() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00421FA0
    ulong frames = this->frame_count;
    if (frames == 0) {
        frames = 1;
    }

    sprintf(
        this->timing_text,
        "fps: %lu, rend: %lu, view: %lu, map: %lu, move: %lu, comm: %lu, snd: %lu, upd: %lu, idle: %lu, total: %lu",
        this->fps,
        this->timings[2].last_time / frames,
        this->timings[6].last_time / frames,
        this->timings[7].last_time / frames,
        this->timings[3].last_time / frames,
        this->timings[1].last_time / frames,
        this->timings[10].last_time / frames,
        this->timings[13].last_time / frames,
        this->timings[4].last_time / frames,
        this->timings[0].last_time / frames);
}

void RGE_Base_Game::show_timings() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422030
    SetWindowTextA((HWND)this->prog_window, this->timing_text);
}

void RGE_Base_Game::show_comm() {
    // TODO: decomp references TCommunications_Handler::GetCommInfo, which is not exported in this branch.
    char str[256];
    sprintf(str, "Comm status: %d", this->comm_handler != nullptr ? (int)this->comm_handler->GetCommunicationsStatus() : -1);
    SetWindowTextA((HWND)this->prog_window, str);
}

void RGE_Base_Game::show_ai() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422090
    char str[256];
    int curr_player = (this->world != nullptr) ? (int)this->world->curr_player : -1;
    sprintf(str, "No AI Information for Player #%d", curr_player);
    SetWindowTextA((HWND)this->prog_window, str);
}

int RGE_Base_Game::setup_map_save_area() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422EF0
    this->map_save_area = new TDrawArea((char*)"Diamond Map Save Area");
    if (this->map_save_area == nullptr) {
        return 0;
    }

    if (this->map_save_area->Init(this->draw_system, nullptr, 0x118, 0x8C, 0, 0, 0) == 0) {
        delete this->map_save_area;
        this->map_save_area = nullptr;
        return 0;
    }
    return 1;
}

void RGE_Base_Game::set_interface_messages() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422FE0
}

void RGE_Base_Game::set_render_all() {
    // Fully verified. Source of truth: basegame.cpp.asm @ 0x00422FF0
    this->render_all = 1;
    panel_system->set_restore();
}

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
    // TODO: This is a decomp-era helper overload not present in basegame.cpp.decomp function list.
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

float RGE_Base_Game::version() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422390
    return this->rge_game_options.versionValue;
}

int RGE_Base_Game::savedGame() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x004223E0
    return this->savedGameValue;
}

int RGE_Base_Game::numberPlayers() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422650
    return (int)this->rge_game_options.numberPlayersValue;
}

int RGE_Base_Game::mapXSize() {
    return (int)this->rge_game_options.mapXSizeValue;
}

int RGE_Base_Game::mapYSize() {
    return (int)this->rge_game_options.mapYSizeValue;
}

int RGE_Base_Game::mapZSize() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422430
    return (int)this->rge_game_options.mapZSizeValue;
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

int RGE_Base_Game::allowCheatCodes() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422440
    return (int)this->rge_game_options.allowCheatCodesValue;
}

int RGE_Base_Game::cheatNotification() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422450
    return (int)this->rge_game_options.cheatNotificationValue;
}

int RGE_Base_Game::coloredChat() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422480
    return (int)this->rge_game_options.coloredChatValue;
}

int RGE_Base_Game::gameDeveloperMode() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422490
    return (int)this->rge_game_options.gameDeveloperModeValue;
}

float RGE_Base_Game::get_game_speed() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422EB0
    return this->game_speed;
}

void RGE_Base_Game::set_game_speed(float param_1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422EC0
    this->game_speed = param_1;
}

int RGE_Base_Game::get_single_player_difficulty() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422ED0
    return this->single_player_difficulty;
}

void RGE_Base_Game::set_single_player_difficulty(int param_1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422EE0
    this->single_player_difficulty = param_1;
}

unsigned char RGE_Base_Game::playerVersion(int index) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x004224C0
    return (unsigned char)(this->rge_game_options.playerCDAndVersionValue[index] >> 1);
}

int RGE_Base_Game::playerHasCD(int index) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x004224A0
    return this->rge_game_options.playerCDAndVersionValue[index] & 1;
}

unsigned char RGE_Base_Game::playerCDAndVersion(int index) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422630
    return this->rge_game_options.playerCDAndVersionValue[index];
}

char* RGE_Base_Game::playerVersionString(int index) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x004224E0
    const unsigned char v = this->playerVersion(index);
    switch (v) {
    case 0x00: return s_ver_empty;
    case 0x01: return s_ver_1_0;
    case 0x02: return s_ver_1_0a;
    case 0x03: return s_ver_1_0b;
    case 0x04: return s_ver_1_0c;
    case 0x05: return s_ver_1_0d;
    case 0x06: return s_ver_1_0e;
    case 0x07: return s_ver_1_1;
    case 0x08: return s_ver_1_1a;
    case 0x09: return s_ver_1_1b;
    case 0x0A: return s_ver_1_1c;
    case 0x0B: return s_ver_1_2;
    case 0x0C: return s_ver_1_2a;
    case 0x0D: return s_ver_1_2b;
    case 0x0E: return s_ver_1_2c;
    case 0x0F: return s_ver_1_3;
    case 0x10: return s_ver_1_3a;
    case 0x11: return s_ver_1_3b;
    case 0x12: return s_ver_1_3c;
    case 0x13: return s_ver_1_4;
    case 0x14: return s_ver_1_4a;
    case 0x15: return s_ver_1_4b;
    case 0x16: return s_ver_1_4c;
    default: return s_ver_1_X;
    }
}

int RGE_Base_Game::playerTeam(int index) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422660
    return (uint)this->rge_game_options.playerTeamValue[index];
}

int RGE_Base_Game::difficulty() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422640
    return (int)this->rge_game_options.difficultyValue;
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
        this->countdown_timer[p1] = -1;
    }
}

void RGE_Base_Game::set_countdown_timer(int p1, long p2) {
    // Source of truth: basegame.cpp.decomp @ 0x00422DE0
    if (p1 >= 0 && p1 < 9) {
        if ((p2 < this->countdown_timer[p1]) || (this->countdown_timer[p1] < 0)) {
            this->countdown_timer[p1] = p2;
        }
    }
}

void RGE_Base_Game::get_countdown_timer(long param_1, long* param_2) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422E10
    if (param_2 == nullptr) {
        return;
    }
    if (param_1 < 0 || param_1 >= 9) {
        *param_2 = -1;
        return;
    }
    *param_2 = this->countdown_timer[param_1];
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

long RGE_Base_Game::GetChecksum(long player_index_or_special) {
    // Fully verified. Source of truth: basegame.cpp.asm @ 0x00422920
    RGE_Game_World* w = this->world;
    if (w != nullptr) {
        if (player_index_or_special < 0) {
            return w->players[(int)w->curr_player]->get_checksum();
        }
        if (player_index_or_special < (long)w->player_num) {
            return w->players[player_index_or_special]->get_checksum();
        }
    }
    return 0;
}

long RGE_Base_Game::GetWorldChecksum() {
    // Fully verified. Source of truth: basegame.cpp.asm @ 0x00422A10
    long checksum = 0;
    RGE_Game_World* w = this->world;
    if (w != nullptr) {
        int i = 0;
        if (w->player_num > 0) {
            do {
                checksum += w->players[i]->get_checksum();
                w = this->world;
                i += 1;
            } while (i < w->player_num);
        }
        return checksum;
    }
    return 0;
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

void RGE_Base_Game::turn_world_sound_off() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422900
    if (this->world != nullptr) {
        this->world->turn_sound_off();
    }
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

RGE_Scenario_Header* RGE_Base_Game::get_scenario_header(char* p1, int p2) {
    // Source of truth: basegame.cpp.decomp @ 0x0041CCA0
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

    char version_tag[4];
    rge_read(fd, version_tag, 4);

    RGE_Scenario_Header* header = nullptr;
    if (memcmp(version_tag, "1.03", 4) == 0 ||
        memcmp(version_tag, "1.04", 4) == 0 ||
        memcmp(version_tag, "1.05", 4) == 0 ||
        memcmp(version_tag, "1.06", 4) == 0 ||
        memcmp(version_tag, "1.07", 4) == 0 ||
        memcmp(version_tag, "1.08", 4) == 0 ||
        memcmp(version_tag, "1.09", 4) == 0 ||
        memcmp(version_tag, "1.10", 4) == 0 ||
        memcmp(version_tag, "1.11", 4) == 0) {
        header = this->new_scenario_header(fd);
    }

    rge_close(fd);
    return header;
}

long RGE_Base_Game::get_scenario_checksum(char* p1) {
    // Source of truth: basegame.cpp.decomp @ 0x00422D20
    RGE_Scenario_Header* header = this->get_scenario_header(p1, 0);
    if (header == nullptr) {
        return 0;
    }

    const long checksum = (long)header->checksum;
    delete header;
    return checksum;
}

unsigned char RGE_Base_Game::check_scenario_checksum(char* p1, long p2) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422D60
    long checksum = this->get_scenario_checksum(p1);
    if (checksum != 0 && checksum == p2) {
        return 1;
    }
    return 0;
}

void RGE_Base_Game::dump_memory_usage(char* p1) {
    // TODO: decomp body is empty at 0x00422D80; keep placeholder for parity hook.
    (void)p1;
}

void RGE_Base_Game::reload_scenarios_info() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422FD0
    if (this->scenario_info != nullptr) {
        this->scenario_info->reload_scenarios();
    }
}

// Linker fix stubs
int RGE_Base_Game::setup_chat() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041ED00
    TChat* chat_obj = new (std::nothrow) TChat(this->prog_window);
    chat = chat_obj;
    return (chat_obj != nullptr) ? 1 : 0;
}
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

    handler->Chat = (TChat*)chat;
    if (this->prog_info != nullptr) {
        handler->ApplicationGUID = this->prog_info->game_guid;
    } else {
        memset(&handler->ApplicationGUID, 0, sizeof(handler->ApplicationGUID));
    }

    handler->Me = 1;
    handler->Multiplayer = (this->rge_game_options.multiplayerGameValue != 0) ? 1 : 0;
    handler->MeHost = (handler->Multiplayer == 0) ? 1 : 0;
    handler->CommunicationsStatus = COMM_IDLE;
    if (handler->Sync != nullptr) {
        handler->Sync->DialogOnSyncFail = this->comm_syncstop;
        handler->Sync->StopOnSyncFail = this->comm_syncstop;
        handler->Sync->SendChatMsgs = this->comm_syncmsg;
    }
    if (handler->Speed != nullptr) {
        handler->Speed->SpeedControlEnabled = this->comm_speed;
    }
    handler->StepMode = this->comm_stepmode;
    handler->IntentionallyDropPackets = this->comm_droppackets;

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

// Fully verified. Source of truth: basegame.cpp.decomp @ 0x004202E0
void RGE_Base_Game::get_mouse_pos(tagPOINT* out)
{
    GetCursorPos(out);
    if (this->prog_info->full_screen == 0) {
        ScreenToClient((HWND)this->prog_window, out);
        if (out->x > 60000) {
            out->x -= 0x10000;
        }
        if (out->y > 60000) {
            out->y -= 0x10000;
        }
    }
}

// Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422E60
int RGE_Base_Game::play_sound(int sound_id)
{
    TDigital** pp_sounds = this->sounds;
    if (pp_sounds == nullptr) {
        return 0;
    }
    if (pp_sounds[sound_id] == nullptr) {
        return 0;
    }
    if (pp_sounds[sound_id]->is_playing() != 0) {
        return 1;
    }
    return pp_sounds[sound_id]->play();
}

int RGE_Base_Game::play_video(char* param_1) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422E30
    (void)param_1;
    return 0;
}

void RGE_Base_Game::close_video() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422E40
}

void RGE_Base_Game::handle_video_notify() {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x00422E50
}
