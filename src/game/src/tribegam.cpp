#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/TRIBE_Game.h"
#include "../include/Res_file.h"
#include "../include/RGE_Prog_Info.h"
#include "../include/globals.h"
#include "../include/RGE_Map.h"
#include "../include/TRIBE_Screen_Game.h"
#include "../include/TRIBE_Screen_Wait.h"
#include "../include/TRIBE_Screen_Main_Menu.h"
#include "../include/TRIBE_Screen_Status_Message.h"
#include "../include/TRIBE_World.h"
#include "../include/TDrawSystem.h"
#include "../include/TDrawArea.h"
#include "../include/TPanel.h"
#include "../include/TPanelSystem.h"
#include "../include/TScreenPanel.h"
#include "../include/TMusic_System.h"
#include "../include/RGE_Player_Info.h"
#include "../include/RGE_Map_Gen_Info.h"
#include "../include/RGE_Scenario.h"
#include "../include/RGE_Game_Info.h"
#include "../include/RGE_Player.h"
#include "../include/TRIBE_Scenario_Header.h"
#include "../include/T_Scenario.h"
#include "../include/TCommunications_Handler.h"
#include "../include/TRegistry.h"
#include "../include/TChat.h"
#include "../include/TMousePointer.h"
#include "../include/debug_helpers.h"
#include "../include/custom_debug.h"
#include <windows.h>
#include <io.h>

// Static global to track current screen until TPanel_System is implemented
static TPanel* gCurrentScreen = nullptr;
static TPanel* gPendingScreen = nullptr;
static TPanel* gRetiredScreens[32];
static int gRetiredScreenCount = 0;

static void tribe_retire_screen_for_later_delete(TPanel* screen) {
    // Non-original safety shim:
    // several screen dtors still rely on not-yet-reimplemented panel teardown paths.
    // Defer deletion so menu transitions remain stable while those dtors are filled in.
    if (!screen) return;

    if (gRetiredScreenCount < (int)(sizeof(gRetiredScreens) / sizeof(gRetiredScreens[0]))) {
        gRetiredScreens[gRetiredScreenCount++] = screen;
        return;
    }

    // Fallback if retire buffer is full.
    delete screen;
}

static int tribe_panel_belongs_to_screen(TPanel* panel, TPanel* screen) {
    if (!panel || !screen) {
        return 0;
    }

    // Non-original safety helper:
    // avoid dereferencing dangling panel pointers after screen switches by clearing owner references
    // that still point into the outgoing screen tree.
    TPanel* cursor = panel;
    int guard = 0;
    while (cursor && guard < 1024) {
        if (cursor == screen) {
            return 1;
        }
        cursor = cursor->parent_panel;
        ++guard;
    }

    return 0;
}

static void tribe_clear_panel_system_owners_for_screen(TPanel* screen) {
    if (!panel_system || !screen) {
        return;
    }

    if (tribe_panel_belongs_to_screen(panel_system->mouseOwnerValue, screen)) {
        panel_system->mouseOwnerValue = nullptr;
    }
    if (tribe_panel_belongs_to_screen(panel_system->keyboardOwnerValue, screen)) {
        panel_system->keyboardOwnerValue = nullptr;
    }
    if (tribe_panel_belongs_to_screen(panel_system->modalPanelValue, screen)) {
        panel_system->modalPanelValue = nullptr;
    }
    if (tribe_panel_belongs_to_screen(panel_system->currentPanelValue, screen)) {
        panel_system->currentPanelValue = nullptr;
    }
    if (tribe_panel_belongs_to_screen(panel_system->prevCurrentChildValue, screen)) {
        panel_system->prevCurrentChildValue = nullptr;
    }
}

static void tribe_apply_screen_switch(TPanel* new_screen) {
    if (new_screen == gCurrentScreen) return;
    tribe_clear_panel_system_owners_for_screen(gCurrentScreen);

    if (panel_system && gCurrentScreen) {
        panel_system->remove_panel(gCurrentScreen);
    }
    if (gCurrentScreen) {
        tribe_retire_screen_for_later_delete(gCurrentScreen);
        gCurrentScreen = nullptr;
    }

    gCurrentScreen = new_screen;
    if (panel_system && gCurrentScreen) {
        panel_system->add_panel(gCurrentScreen);
        panel_system->setCurrentPanel(gCurrentScreen, 0);
    }

    // Non-original safety shim:
    // some transitions disable input before queueing the new screen and rely on idle to re-enable.
    // If idle gets starved by a message storm, force one activation pass here so the UI does not
    // remain stuck with wait-cursor/captured input.
    if (gCurrentScreen && rge_base_game && rge_base_game->input_enabled == 0) {
        gCurrentScreen->handle_idle();
        if (rge_base_game->input_enabled == 0) {
            rge_base_game->enable_input();
        }
    }
}

void tribe_set_current_screen(TPanel* new_screen) {
    tribe_apply_screen_switch(new_screen);
}

void tribe_queue_screen_switch(TPanel* new_screen) {
    // Non-original safety shim:
    // queue screen destruction/creation until idle so we do not mutate panel lists while dispatching
    // the current input message.
    if (new_screen == gCurrentScreen) {
        return;
    }

    if (gPendingScreen && gPendingScreen != new_screen) {
        delete gPendingScreen;
    }
    gPendingScreen = new_screen;
}

static void tribe_process_pending_screen_switch() {
    if (!gPendingScreen) {
        return;
    }
    TPanel* next = gPendingScreen;
    gPendingScreen = nullptr;
    tribe_apply_screen_switch(next);
}

static void tribe_retire_panel_by_name(const char* panel_name) {
    if (panel_system == nullptr || panel_name == nullptr || panel_name[0] == '\0') {
        return;
    }

    TPanel* panel = panel_system->panel((char*)panel_name);
    if (panel == nullptr) {
        return;
    }

    tribe_clear_panel_system_owners_for_screen(panel);
    panel_system->remove_panel(panel);
    tribe_retire_screen_for_later_delete(panel);
}

static int tribe_ascii_str_eq(const char* lhs, const char* rhs) {
    if (lhs == nullptr || rhs == nullptr) {
        return 0;
    }
    return strcmp(lhs, rhs) == 0;
}

static void tribe_close_video_window(TRIBE_Game* game) {
    if (game == nullptr || game->video_window == nullptr) {
        return;
    }

    char status[100];
    status[0] = '\0';
    SendMessageA((HWND)game->video_window, 0x46a, 100, (LPARAM)status);

    if (status[0] != '\0' && tribe_ascii_str_eq(status, "stopped") == 0) {
        SendMessageA((HWND)game->video_window, 0x808, 0, 0);
    }

    SendMessageA((HWND)game->video_window, 0x10, 0, 0);
    game->video_window = nullptr;
}

static void tribe_write_debugload_dump(TRIBE_Game* game, const char* save_name_no_ext) {
    if (game == nullptr || save_name_no_ext == nullptr || save_name_no_ext[0] == '\0') {
        return;
    }

    char dump_name[300];
    sprintf(dump_name, "c:\\%s.txt", save_name_no_ext);

    FILE* out = fopen(dump_name, "w");
    if (out == nullptr) {
        return;
    }

    RGE_Game_World* world = game->world;
    if (world == nullptr) {
        fprintf(out, "world=null\n");
        fclose(out);
        return;
    }

    fprintf(out, "world_time=%lu\n", world->world_time);
    fprintf(out, "old_world_time=%lu\n", world->old_world_time);
    fprintf(out, "game_speed=%f\n", world->game_speed);
    fprintf(out, "player_num=%d\n", (int)world->player_num);

    if (world->map != nullptr) {
        fprintf(out, "map=%ldx%ld visible=%u fog=%u\n",
            world->map->map_width,
            world->map->map_height,
            (unsigned int)world->map->map_visible_flag,
            (unsigned int)world->map->fog_flag);
    }

    for (int i = 0; i < (int)world->player_num; ++i) {
        RGE_Player* player = (world->players != nullptr) ? world->players[i] : nullptr;
        if (player == nullptr) {
            continue;
        }

        int humanity = (game->comm_handler != nullptr) ? game->comm_handler->GetPlayerHumanity((uint)(i + 1)) : 0;
        fprintf(out, "player[%d] id=%d civ=%u humanity=%d status=%u checksum=%ld name=%s\n",
            i,
            (int)player->id,
            (unsigned int)player->culture,
            humanity,
            (unsigned int)player->game_status,
            player->checksum,
            (player->name != nullptr) ? player->name : "");
    }

    fclose(out);
}

TRIBE_Game::TRIBE_Game(RGE_Prog_Info* info, int param_2) : RGE_Base_Game(info, 0) {
    // tribegam.cpp:263
    // Assembly at 0x00521150
    this->cur_video = -1; // [ESI + 0xbf0] = -1
    
    // Line 250: [ESI + 0x1d8] = 1 (input_enabled = 1)
    this->input_enabled = 1;
    
    this->video_window = nullptr; // [ESI + 0x1dc]
    this->started_menu_music = 0;
    
    // Lines 258-268: Initialize various strings and values
    this->testing_scenario[0] = '\0'; // [ESI + 0xc58]
    this->startup_scenario[0] = '\0'; // [ESI + 0xd5c]
    this->startup_game[0] = '\0';     // [ESI + 0xe64]
    this->save_game_name[0] = '\0';   // [ESI + 0xf68]
    this->load_game_name[0] = '\0';   // [ESI + 0x106c]
    this->auto_exit_time = 0;         // [ESI + 0xe60]
    
    // Lines 270-274: Initialize global flags
    disable_terrain_sounds = 0;
    out_of_sync = 0;
    out_of_sync2 = 0;
    
    // Lines 287-302: Set default game options
    setMapSize(static_cast<MapSize>(2));
    setMapType(static_cast<MapType>(2));
    setAnimals(1);
    setPredators(1);
    setVictoryType(static_cast<VictoryType>(1), 1);
    setAllowTrading(1);
    setLongCombat(0);
    setRandomizePositions(0);
    setFullTechTree(0);
    setResourceLevel(static_cast<ResourceLevel>(0));
    setStartingAge(static_cast<Age>(0));
    setStartingUnits(0);
    setDeathMatch(0);
    setPopLimit(50);
    setQuickStartGame(0);
    setRandomStartValue(-1);
    
    // Lines 345-354: Initialize notification locations
    for (int i = 0; i < 5; i++) {
        this->notification_loc_x[i] = -1;
        this->notification_loc_y[i] = -1;
    }
    
    // Lines 360-399: Initialize player settings
    // Arrays are size 9 per TRIBE_Game_Options.h
    for (int i = 0; i < 9; i++) {
        setCivilization(i, (i % 16) + 1);
        setScenarioPlayer(i, 0);
        setPlayerColor(i, i + 1); // Default: player i gets color i+1 (1-based)
        setComputerName(i, 0);
    }
    
    // Line 401-405: Initialize save_humanity array
    for (int i = 0; i < 9; i++) {
        this->save_humanity[i] = 4; // STOSD in ASM 0x00521333 sets to 4
    }
    
    setNumberPlayers(4);
    resetRandomComputerName();
    
    if (param_2) {
        if (this->setup() == 0) {
            if (this->error_code == 0) {
                this->error_code = 1;
            }
        }
    }
}

TRIBE_Game::~TRIBE_Game() {
    // Source of truth: tribegam.cpp.decomp @ 0x005213A0
    CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG("TRIBE_Game::~TRIBE_Game: destructor start");
    CUSTOM_DEBUG_END

    this->inHandleIdle = 0;

    // Destroy video window if present
    if (this->video_window != nullptr) {
        CUSTOM_DEBUG_LOG("TRIBE_Game dtor: destroying video_window");
        DestroyWindow((HWND)this->video_window);
        this->video_window = nullptr;
    }

    // Close all game screens and dialogs
    CUSTOM_DEBUG_LOG("TRIBE_Game dtor: closing game screens");
    this->close_game_screens(1);

    // Destroy all remaining panels
    if (panel_system) {
        CUSTOM_DEBUG_LOG("TRIBE_Game dtor: destroying panel system panels");
        panel_system->destroyPanel((char*)"Video Screen");
        panel_system->destroyPanel((char*)"Create Dialog");
        panel_system->destroyPanel((char*)"Campaign Editor Screen");
        panel_system->destroyPanel((char*)"Game Setup Screen");
        panel_system->destroyPanel((char*)"Game Settings Screen");
        panel_system->destroyPanel((char*)"Select Scenario Screen");
        panel_system->destroyPanel((char*)"Campaign Selection Screen");
        panel_system->destroyPanel((char*)"Load Saved Game Screen");
        panel_system->destroyPanel((char*)"MP Startup Screen");
        panel_system->destroyPanel((char*)"MP Setup Screen");
        panel_system->destroyPanel((char*)"Connecting Screen");
        panel_system->destroyPanel((char*)"Join Screen");
        panel_system->destroyPanel((char*)"Main Menu");
        panel_system->destroyPanel((char*)"Save Game Screen");
        panel_system->destroyPanel((char*)"End Screen");
        panel_system->destroyPanel((char*)"Scenario Editor Menu");
        panel_system->destroyPanel((char*)"Scenario Editor Open");
        panel_system->destroyPanel((char*)"Scenario Editor Screen");
        panel_system->destroyPanel((char*)"Single Player Menu");
        panel_system->destroyPanel((char*)"New Name Dialog");
        panel_system->destroyPanel((char*)"Name Selection Screen");
        panel_system->destroyPanel((char*)"Status Screen");
        panel_system->destroyPanel((char*)"Temp Screen");
        panel_system->destroyPanel((char*)"ScenarioEditorInfo");
        panel_system->destroyPanel((char*)"FeaturesInfo");
        panel_system->destroyPanel((char*)"QuotesInfo");
        panel_system->destroyPanel((char*)"Logo1Screen");
        panel_system->destroyPanel((char*)"Logo2Screen");
    }

    // Close DRS resource files
    CUSTOM_DEBUG_LOG("TRIBE_Game dtor: closing resource files");
    RESFILE_close_new_resource_file((char*)"sounds.drs");
    RESFILE_close_new_resource_file((char*)"graphics.drs");
    RESFILE_close_new_resource_file((char*)"Terrain.drs");
    RESFILE_close_new_resource_file((char*)"Border.drs");
    RESFILE_close_new_resource_file((char*)"Interfac.drs");

    // Free extended string table
    if (StringTableX != nullptr) {
        FreeLibrary(StringTableX);
        StringTableX = nullptr;
    }

    CUSTOM_DEBUG_LOG("TRIBE_Game::~TRIBE_Game: destructor end");
    // ~RGE_Base_Game() is called automatically by C++ destructor chain
}

int TRIBE_Game::setup() {
CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("TRIBE_Game::setup: enter cmd_line='%s'", this->prog_info ? this->prog_info->cmd_line : "(null)");
CUSTOM_DEBUG_END
    if (this->player_game_info) {
        return 0;
    }

    if (strstr(this->prog_info->cmd_line, "makeres") || strstr(this->prog_info->cmd_line, "Makeres") || strstr(this->prog_info->cmd_line, "MAKERES")) {
        RESFILE_build_res_file(this->prog_info->resource_dir, "resource\\", "graphics.rm");
        RESFILE_build_res_file(this->prog_info->resource_dir, "resource\\", "sounds.rm");
        RESFILE_build_res_file(this->prog_info->resource_dir, "resource\\", "interfac.rm");
    }

    RESFILE_open_new_resource_file(this->prog_info->resource_dir, "sounds.drs", "tribe", 1);
    RESFILE_open_new_resource_file(this->prog_info->resource_dir, "graphics.drs", "tribe", 0);
    RESFILE_open_new_resource_file(this->prog_info->resource_dir, "Interfac.drs", "tribe", 0);

    RESFILE_open_new_resource_file("data\\", "sounds.drs", "tribe", 1);
    RESFILE_open_new_resource_file("data\\", "graphics.drs", "tribe", 0);
    RESFILE_open_new_resource_file("data\\", "Terrain.drs", "tribe", 0);
    RESFILE_open_new_resource_file("data\\", "Border.drs", "tribe", 0);
    RESFILE_open_new_resource_file("data\\", "Interfac.drs", "tribe", 0);

    if (RGE_Base_Game::setup() == 0) {
        return 0;
    }

    // Set initial game mode to Menu (2)
    this->game_mode = 2;

    // Command line STRING= handler (ASM 0x0052194a)
    char cmd_line_str[260];
    strncpy(cmd_line_str, this->prog_info->cmd_line, 255);
    cmd_line_str[255] = '\0';
    CharUpperA(cmd_line_str);
    
    char string_dll_name[100];
    strcpy(string_dll_name, "languagex.dll");
    
    char* string_arg = strstr(cmd_line_str, "STRING=");
    if (string_arg) {
        char* val = string_arg + 7;
        while (*val && (*val == ' ' || *val == '=')) val++;
        
        int i = 0;
        while (*val && *val != ' ' && i < 99) {
            string_dll_name[i++] = *val++;
        }
        string_dll_name[i] = '\0';
    }
    
    StringTableX = LoadLibraryA(string_dll_name);
    if (!StringTableX) {
CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT("TRIBE_Game::setup: LoadLibraryA failed for '%s'", string_dll_name);
CUSTOM_DEBUG_END
        this->error_code = 1;
        return 0;
    }

    // Simplified selection of mouse click tables
    // (Palette setup removed and moved to setup_palette override)

    this->input_disabled_window = CreateWindowExA(0, "STATIC", "InputDisabledWindow", WS_CHILD, 0, 0, 1, 1, 
        (HWND)this->prog_window, NULL, (HINSTANCE)this->prog_info->instance, NULL);

    // Startup screens logic (ASM 0x00521b3f)
    if (this->check_prog_argument("LOBBY")) {
        // Lobby startup logic
        // TCommunications_Handler::LaunchLobbyGame ...
CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG("TRIBE_Game::setup: LOBBY startup path");
CUSTOM_DEBUG_END
    } else {
        if (this->startup_scenario[0]) {
            if (this->start_scenario(this->startup_scenario)) goto FINAL_SETUP;
        }
        if (this->startup_game[0]) {
            if (this->load_game(this->startup_game)) goto FINAL_SETUP;
        }
        
        if (quick_start_game_mode) {
            int start_ok = this->start_game(0);
CUSTOM_DEBUG_BEGIN
            CUSTOM_DEBUG_LOG_FMT("TRIBE_Game::setup: quick_start -> start_game result=%d", start_ok);
CUSTOM_DEBUG_END
        } else if (this->check_prog_argument("NOSTARTUP") || this->check_prog_argument("NO STARTUP")) {
            int menu_ok = this->start_menu();
CUSTOM_DEBUG_BEGIN
            CUSTOM_DEBUG_LOG_FMT("TRIBE_Game::setup: NOSTARTUP -> start_menu result=%d", menu_ok);
CUSTOM_DEBUG_END
        } else {
            // Check for NOVIDEO/SKIPVIDEO etc inside start_video
            int video_ok = this->start_video(0, (char*)"logo1");
CUSTOM_DEBUG_BEGIN
            CUSTOM_DEBUG_LOG_FMT("TRIBE_Game::setup: start_video(0,'logo1') result=%d", video_ok);
CUSTOM_DEBUG_END
        }
    }

FINAL_SETUP:
    this->set_interface_messages();
    
    // Program logging logic (ASM 0x00521c94)
    run_log("------------------------------", 0);
    run_log("", 1);
    
    // FindFirstFile program info
    char pgm_path[MAX_PATH];
    GetModuleFileNameA(NULL, pgm_path, MAX_PATH);
    WIN32_FIND_DATAA find_data;
    HANDLE hFind = FindFirstFileA(pgm_path, &find_data);
    if (hFind != INVALID_HANDLE_VALUE) {
        SYSTEMTIME st;
        FileTimeToSystemTime(&find_data.ftLastWriteTime, &st);
        char log_str[1024];
        sprintf(log_str, "program=%s, size=%d, date=%d/%d/%d, time=%d:%d:%d", 
                pgm_path, find_data.nFileSizeLow, st.wMonth, st.wDay, st.wYear, st.wHour, st.wMinute, st.wSecond);
        run_log(log_str, 0);
        FindClose(hFind);
    }
    
    // FindFirstFile data info (using prog_info string at 0x1F8)
    hFind = FindFirstFileA((char*)this->prog_info + 0x1F8, &find_data);
    if (hFind != INVALID_HANDLE_VALUE) {
        SYSTEMTIME st;
        FileTimeToSystemTime(&find_data.ftLastWriteTime, &st);
        char log_str[1024];
        sprintf(log_str, "data=%s, size=%d, date=%d/%d/%d, time=%d:%d:%d", 
                (char*)this->prog_info + 0x1F8, find_data.nFileSizeLow, st.wMonth, st.wDay, st.wYear, st.wHour, st.wMinute, st.wSecond);
        run_log(log_str, 0);
        FindClose(hFind);
    }

    char options_log[1024];
    sprintf(options_log, "options=%s", this->prog_info->cmd_line);
    run_log(options_log, 0);

CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("TRIBE_Game::setup: exit success prog_mode=%d game_mode=%d", this->prog_mode, this->game_mode);
CUSTOM_DEBUG_END
    return 1;
}

int TRIBE_Game::setup_cmd_options() {
    // Source of truth: tribegam.cpp.decomp @ 0x00521FA0
    char cmd_line_upper[260];
    strncpy(cmd_line_upper, this->prog_info->cmd_line, 255);
    cmd_line_upper[255] = '\0';
    CharUpperA(cmd_line_upper);

    if (strstr(cmd_line_upper, "NOTERRAINSOUND")) {
        disable_terrain_sounds = 1;
    }

    // Pop limit from encrypted command line (simplified — skip encrypt_codes)
    // TODO(accuracy): encrypt_codes for obfuscated pop limit argument

    if (strstr(cmd_line_upper, "QUICK1")) {
        quick_start_game_mode = 1;
    }

    // SCN= : startup scenario from command line
    char* scn_arg = strstr(cmd_line_upper, "SCN=");
    if (scn_arg) {
        while (*scn_arg && *scn_arg != '=') scn_arg++;
        scn_arg++; // skip '='
        int i = 0;
        while (*scn_arg && *scn_arg != ' ' && i < 255) {
            this->startup_scenario[i++] = *scn_arg++;
        }
        this->startup_scenario[i] = '\0';
    }

    // EXIT= : auto exit time
    char* exit_arg = strstr(cmd_line_upper, "EXIT=");
    if (exit_arg) {
        while (*exit_arg && *exit_arg != '=') exit_arg++;
        exit_arg++;
        char temp[256];
        int i = 0;
        while (*exit_arg && *exit_arg != ' ' && i < 255) {
            temp[i++] = *exit_arg++;
        }
        temp[i] = '\0';
        this->auto_exit_time = atol(temp);
    }

    // GAM= : startup saved game from command line
    char* gam_arg = strstr(cmd_line_upper, "GAM=");
    if (gam_arg) {
        while (*gam_arg && *gam_arg != '=') gam_arg++;
        gam_arg++;
        int i = 0;
        while (*gam_arg && *gam_arg != ' ' && i < 255) {
            this->startup_game[i++] = *gam_arg++;
        }
        this->startup_game[i] = '\0';
        // Append .gmx extension if no extension present
        if (!strchr(this->startup_game, '.')) {
            strcat(this->startup_game, ".gmx");
        }
    }

    return RGE_Base_Game::setup_cmd_options();
}

void TRIBE_Game::setMapSize(MapSize p1) {
    // Source of truth: tribegam.cpp.decomp @ 0x00529200
    this->tribe_game_options.mapSizeValue = p1;
    switch (p1) {
        case 0: RGE_Base_Game::setMapSize(0x48, 0x48, 8); break; // Tiny
        case 1: RGE_Base_Game::setMapSize(0x60, 0x60, 8); break; // Small
        case 2: RGE_Base_Game::setMapSize(0x78, 0x78, 8); break; // Medium
        case 3: RGE_Base_Game::setMapSize(0x90, 0x90, 8); break; // Large
        case 4: RGE_Base_Game::setMapSize(200, 200, 8); break;   // Huge
        case 5: RGE_Base_Game::setMapSize(0xfa, 0xfa, 8); break; // Humongous
        default: break;
    }
}
void TRIBE_Game::setMapType(MapType p1) { this->tribe_game_options.mapTypeValue = p1; }
void TRIBE_Game::setAnimals(int p1) { this->tribe_game_options.animalsValue = p1; }
void TRIBE_Game::setPredators(int p1) { this->tribe_game_options.predatorsValue = p1; }
void TRIBE_Game::setVictoryType(VictoryType p1, int p2) { 
    this->tribe_game_options.victoryTypeValue = p1; 
    this->tribe_game_options.victoryAmountValue = p2; 
}
void TRIBE_Game::setAllowTrading(int p1) { this->tribe_game_options.allowTradingValue = p1; }
void TRIBE_Game::setLongCombat(int p1) { this->tribe_game_options.longCombatValue = p1; }
void TRIBE_Game::setRandomizePositions(int p1) { this->tribe_game_options.randomizePositionsValue = p1; }
void TRIBE_Game::setFullTechTree(int p1) { this->tribe_game_options.fullTechTreeValue = p1; }
void TRIBE_Game::setResourceLevel(ResourceLevel p1) { this->tribe_game_options.resourceLevelValue = p1; }
void TRIBE_Game::setStartingAge(Age p1) { this->tribe_game_options.startingAgeValue = p1; }
void TRIBE_Game::setStartingUnits(int p1) { this->tribe_game_options.startingUnitsValue = p1; }
void TRIBE_Game::setDeathMatch(unsigned char p1) { this->tribe_game_options.deathMatchValue = p1; }
void TRIBE_Game::setPopLimit(unsigned char p1) { this->tribe_game_options.popLimitValue = p1; }
void TRIBE_Game::setQuickStartGame(unsigned char p1) { this->quick_start_game = p1; }
void TRIBE_Game::setRandomStartValue(int p1) { this->random_start_value = p1; }
void TRIBE_Game::setCivilization(int p1, int p2) { if (p1 >= 0 && p1 < 9) this->tribe_game_options.civilizationValue[p1] = p2; }
void TRIBE_Game::setScenarioPlayer(int p1, int p2) { if (p1 >= 0 && p1 < 9) this->tribe_game_options.scenarioPlayerValue[p1] = p2; }
void TRIBE_Game::setPlayerColor(int p1, int p2) { if (p1 >= 0 && p1 < 9) this->tribe_game_options.playerColorValue[p1] = p2; }
void TRIBE_Game::setComputerName(int p1, int p2) { if (p1 >= 0 && p1 < 9) this->tribe_game_options.computerNameValue[p1] = p2; }

void TRIBE_Game::resetRandomComputerName() {
    memset(this->computerNameUsed, 0, sizeof(this->computerNameUsed));
}

void TRIBE_Game::set_save_game_name(char* p1) {
    if (!p1) {
        this->save_game_name[0] = '\0';
        return;
    }
    strncpy(this->save_game_name, p1, sizeof(this->save_game_name) - 1);
    this->save_game_name[sizeof(this->save_game_name) - 1] = '\0';
}

void TRIBE_Game::set_load_game_name(char* p1) {
    if (!p1) {
        this->load_game_name[0] = '\0';
        return;
    }
    strncpy(this->load_game_name, p1, sizeof(this->load_game_name) - 1);
    this->load_game_name[sizeof(this->load_game_name) - 1] = '\0';
}

unsigned char TRIBE_Game::quickStartGame() { return this->quick_start_game; }

char* TRIBE_Game::get_save_game_name() {
    // Source of truth: tribegam.cpp.decomp @ 0x005234F0
    return this->save_game_name;
}

char* TRIBE_Game::get_load_game_name() {
    // Source of truth: tribegam.cpp.decomp @ 0x00523500
    return this->load_game_name;
}

int TRIBE_Game::civilization(int p1) {
    if (p1 >= 0 && p1 < 9) {
        return (int)this->tribe_game_options.civilizationValue[p1];
    }
    return 0;
}

int TRIBE_Game::playerColor(int p1) {
    if (p1 >= 0 && p1 < 9) {
        return (int)this->tribe_game_options.playerColorValue[p1];
    }
    return 1;
}

int TRIBE_Game::computerName(int p1) {
    if (p1 >= 0 && p1 < 9) {
        return (int)this->tribe_game_options.computerNameValue[p1];
    }
    return 0;
}

MapSize TRIBE_Game::mapSize() { return this->tribe_game_options.mapSizeValue; }
MapType TRIBE_Game::mapType() { return this->tribe_game_options.mapTypeValue; }
VictoryType TRIBE_Game::victoryType() { return this->tribe_game_options.victoryTypeValue; }
int TRIBE_Game::victoryAmount() { return this->tribe_game_options.victoryAmountValue; }
ResourceLevel TRIBE_Game::resourceLevel() { return this->tribe_game_options.resourceLevelValue; }
Age TRIBE_Game::startingAge() { return this->tribe_game_options.startingAgeValue; }
int TRIBE_Game::randomizePositions() { return this->tribe_game_options.randomizePositionsValue; }
int TRIBE_Game::fullTechTree() { return this->tribe_game_options.fullTechTreeValue; }
int TRIBE_Game::allowTrading() { return this->tribe_game_options.allowTradingValue; }
int TRIBE_Game::longCombat() { return this->tribe_game_options.longCombatValue; }
unsigned char TRIBE_Game::deathMatch() { return this->tribe_game_options.deathMatchValue; }
unsigned char TRIBE_Game::popLimit() { return this->tribe_game_options.popLimitValue; }

int TRIBE_Game::randomComputerName(int civ) {
    // Fully verified. Source of truth: tribegam.cpp.decomp @ 0x0052A0B0
    if (civ < 0 || civ >= 18) {
        civ = 0;
    }

    char scount[10];
    scount[0] = '\0';
    this->get_string((civ + 0x1b7) * 10, scount, sizeof(scount));

    int name_count = atoi(scount);
    if (name_count <= 0) {
        name_count = 1;
    }

    int selected = 0;
    int tries = 0;
    do {
        int r = debug_rand("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x1521);
        selected = r % name_count;
        if (selected > name_count - 1) {
            selected = name_count - 1;
        }
        tries = tries + 1;
    } while (this->computerNameUsed[civ][selected] != 0 && tries < 0x14);

    int index = selected;
    if (this->computerNameUsed[civ][selected] == 1) {
        for (int i = 0; i < 10; ++i) {
            if (this->computerNameUsed[civ][i] == 0) {
                index = i;
                break;
            }
        }
    }

    this->computerNameUsed[civ][index] = 1;
    return index + civ * 10 - 9;
}

void TRIBE_Game::show_status_message(char* p1, char* p2, long p3) {
    // Fully verified. Source of truth: tribegam.cpp.decomp @ 0x005236A0
    TRIBE_Screen_Status_Message* status =
        (TRIBE_Screen_Status_Message*)(panel_system ? panel_system->panel((char*)"Status Screen") : nullptr);

    if (status == nullptr) {
        status = new TRIBE_Screen_Status_Message((char*)"Status Screen", p1, p2, p3);
    } else {
        status->set_text(p1);
        if (this->prog_window != nullptr) {
            InvalidateRect((HWND)this->prog_window, 0, 0);
            UpdateWindow((HWND)this->prog_window);
        }
    }

    if (panel_system != nullptr) {
        panel_system->setCurrentPanel((char*)"Status Screen", 0);
    }
}

void TRIBE_Game::show_status_message(int p1, char* p2, long p3) {
    // Fully verified. Source of truth: tribegam.cpp.decomp @ 0x00523750
    char msg[256];
    this->get_string(p1, msg, sizeof(msg));
    this->show_status_message(msg, p2, p3);
}

void TRIBE_Game::close_status_message() {
    // Fully verified. Source of truth: tribegam.cpp.decomp @ 0x005237A0
    if (panel_system != nullptr) {
        panel_system->restorePreviousPanel(1);
    }
}

int TRIBE_Game::load_game_data() {
    // Source of truth:
    // - `src/game/src/tribegam.cpp.asm` (`load_game_data` @ 0x005245D0)
    // - `src/game/src/tribegam.cpp.decomp`
    if (!this->world) {
        RGE_Game_World* world = this->create_world();
        if (!world) {
            return 0;
        }

        // Source of truth uses virtual dispatch. Current decomp tree still has vtable fidelity gaps,
        // so call the base implementation explicitly to keep binary data bootstrap deterministic.
        if (!world->RGE_Game_World::init(this->prog_info->game_data_file, this->sound_system, this->comm_handler)) {
            delete world;
            this->world = nullptr;
            return 0;
        }
    }
    return 1;
}

int TRIBE_Game::create_game(int p1) {
    // Source of truth:
    // - `src/game/src/tribegam.cpp.asm` (`create_game` @ 0x00526E60)
    // - `src/game/src/tribegam.cpp.decomp`
    //
    // Transliteration scoped to single-player random-map/scenario launch.
    TCommunications_Handler* comm_handler = this->comm_handler;

    // --- Phase 1: Reset game state ---
    this->inHandleIdle = 0;
    for (int i = 0; i < 5; ++i) {
        this->notification_loc_x[i] = -1;
        this->notification_loc_y[i] = -1;
    }
    this->current_notification_loc = -1;
    this->current_notification_recalled = -1;

    // QUICKBUILD check
    if (this->check_prog_argument("QUICKBUILD")) {
        this->quick_build = 1;
    } else {
        this->quick_build = 0;
    }

    this->do_show_timings = 0;
    this->do_show_comm = 0;
    this->do_show_ai = 0;

    this->set_map_visible('\0');
    this->set_map_fog('\0');

    // Source of truth: tribegam.cpp.asm @ 0x00526EDE..0x00526F02
    // Reset per-slot startup flags for active player slots (1..8).
    for (int i = 1; i < 9; ++i) {
        this->resigned[i] = 0;
        player_dropped[i - 1] = 0;
        this->queue_is_waiting_on_pop_counter[i] = 0;
    }
    for (int i = 0; i < 9; ++i) {
        this->random_civ[i] = 0;
    }
    out_of_sync = 0;
    out_of_sync2 = 0;
    no_other_humans_count = 0;

    // --- Phase 2: Quick start game handling ---
    // Source of truth: tribegam.cpp.decomp @ 0xcdd-0xcf8
    if (this->quickStartGame() != 0) {
        MapType mt;
        if (quick_start_game_mode == 1) {
            this->setMapSize(static_cast<MapSize>(2)); // Medium
            mt = (MapType)4;
        } else {
            this->setMapSize(static_cast<MapSize>(3)); // Large
            int r = debug_rand("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0xcdd);
            mt = (MapType)(r % 10);
            // Exact numeric remap from 0x00526F5D..0x00526FAE.
            if ((int)mt < 2) {
                mt = (MapType)4;
            } else if (mt == (MapType)2) {
                mt = (MapType)3;
            } else if (mt == (MapType)3) {
                mt = (MapType)2;
            } else if (mt == (MapType)4) {
                mt = (MapType)1;
            } else if (mt == (MapType)5 || mt == (MapType)6 || mt == (MapType)7) {
                // pass through
            } else {
                mt = ((int)mt == 8) ? (MapType)8 : (MapType)0;
            }
        }
        this->setMapType(mt);
        this->resetRandomComputerName();
        int np = this->numberPlayers();
        for (int i = 0; i < np; ++i) {
            int r = debug_rand("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0xcf8);
            int sign = r >> 31;
            int civIdx = (((((r ^ sign) - sign) & 0xF) ^ sign) - sign) + 1;
            this->setCivilization(i, civIdx);
            int cn = this->randomComputerName(civIdx);
            this->setComputerName(i, cn);
        }
    }

    // --- Phase 3: Build RGE_Player_Info ---
    RGE_Player_Info player_info;
    memset(&player_info, 0, sizeof(player_info));

    RGE_Map_Gen_Info map_info;
    memset(&map_info, 0, sizeof(map_info));
    char scenario_file[260];
    memset(scenario_file, 0, sizeof(scenario_file));

    int isCampaign = this->campaignGame();
    int isScenario = this->scenarioGame();

    if (isCampaign != 0) {
        // Campaign: set campaign flag
        player_info.campaign = 1;
    } else if (isScenario != 0) {
        // Scenario path
        char* scenario_name = this->scenarioName();
        if (scenario_name == nullptr || scenario_name[0] == '\0' || this->prog_info == nullptr) {
            return 0;
        }

        char probe_path[300];
        _finddata_t file_info;
        memset(&file_info, 0, sizeof(file_info));
        sprintf(probe_path, "%s%s.scn", this->prog_info->scenario_dir, scenario_name);
        intptr_t find_handle = _findfirst(probe_path, &file_info);
        if (find_handle == -1) {
            sprintf(scenario_file, "%s.scx", scenario_name);
        } else {
            _findclose(find_handle);
            sprintf(scenario_file, "%s.scn", scenario_name);
        }

        player_info.scenario = scenario_file;
    } else {
        // Random map path
        player_info.map_info = &map_info;
        player_info.map_type = (short)this->mapType();
        player_info.map_width = (short)this->mapXSize();
        player_info.map_height = (short)this->mapYSize();
    }

    // --- Phase 4: Seed random number generator ---
    if (this->multiplayerGame() == 0) {
        unsigned int seed;
        int seed_line;
        if (this->random_start_value == -1) {
            seed = debug_rand("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0xd2a);
            seed_line = 0xd2a;
        } else {
            seed = (unsigned int)this->random_start_value;
            seed_line = 0xd28;
        }
        debug_srand("C:\\msdev\\work\\age1_x1\\tribegam.cpp", seed_line, seed);
    } else {
        // Multiplayer: get seed from comm
        unsigned int seed = comm_handler->GetRandomSeed();
        debug_srand("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0xd24, seed);
    }

    // --- Phase 5: Initialize per-player slot defaults ---
    for (int i = 0; i < 9; ++i) {
        player_info.type[i] = -1;
        player_info.name[i][0] = '\0';
        player_info.player_id_hash[i] = i;
        player_info.tribe[i] = 1;
        player_info.color[i] = -1;
        this->random_civ[i] = 0;

        int civVal = this->civilization(i);
        if (civVal > 16 || civVal < 0) {
            int r = debug_rand("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0xd3b);
            this->setCivilization(i, (r * 16) / 0x7fff + 1);
            this->random_civ[i] = 1;
        }
    }

    // --- Phase 6: Assign computer names for CP players ---
    this->resetRandomComputerName();
    int numPlayers = this->numberPlayers();
    for (int i = 0; i < numPlayers; ++i) {
        int humanity = comm_handler->GetPlayerHumanity(i + 1);
        if (humanity == 4) {
            int civVal = this->civilization(i);
            int cn = this->randomComputerName(civVal);
            this->setComputerName(i, cn);
        }
    }

    // --- Phase 7: Resolve campaign/scenario source ---
    RGE_Scenario* scenario_info = nullptr;
    if (this->campaignGame() != 0) {
        scenario_info = this->get_scenario_info((char*)0, 1);
        if (scenario_info == nullptr) {
            return 0;
        }
    } else if (this->scenarioGame() != 0) {
        scenario_info = this->get_scenario_info(player_info.scenario, 0);
        if (scenario_info == nullptr) {
            return 0;
        }
    }

    // --- Phase 8: Assign player positions (color -> position mapping) ---
    int position_used[9];
    for (int i = 0; i < 9; ++i) {
        position_used[i] = -1;
    }

    // Clear all player IDs first
    for (int i = 0; i < 9; ++i) {
        this->setPlayerID(i, 0);
    }

    int scenario_player = 0;
    numPlayers = this->numberPlayers();

    // Source of truth: tribegam.cpp.asm @ 0x00527318..0x00527412
    // Single pass over comm slots: handle humans first, then computer-color remap when needed.
    for (int slot = 1; slot <= numPlayers; ++slot) {
        int humanity = comm_handler->GetPlayerHumanity(slot);
        if (humanity == 2) {
            int colorVal = this->playerColor(slot - 1);
            int colorIndex = colorVal - 1;
            if (position_used[colorIndex] == -1) {
                position_used[colorIndex] = scenario_player;
                scenario_player++;
            }
            this->setPlayerID(slot, position_used[colorIndex] + 1);
        } else if (humanity == 4) {
            // Find an unused color position
            for (int c = 0; c < 8; ++c) {
                if (position_used[c] == -1) {
                    // Check no human has claimed this color
                    int claimed = 0;
                    for (uint check = 1; check < 9; ++check) {
                        int h = comm_handler->GetPlayerHumanity(check);
                        if (h == 2) {
                            int pc = this->playerColor(check - 1);
                            if (pc - 1 == c) {
                                claimed = 1;
                                break;
                            }
                        }
                    }
                    if (!claimed) {
                        this->setPlayerColor(slot - 1, c + 1);
                        position_used[c] = scenario_player;
                        scenario_player++;
                        this->setPlayerID(slot, position_used[c] + 1);
                        break;
                    }
                }
            }
        }
    }

    // --- Phase 9: Build final player info array ---
    this->resetRandomComputerName();
    player_info.player_num = 0;

    for (int pos = 0; pos < 8; ++pos) {
        // Find which comm slot has playerID == pos+1
        int commSlot = 0;
        for (int s = 1; s < 9; ++s) {
            if (this->playerID(s) == pos + 1) {
                commSlot = s;
                break;
            }
        }
        if (commSlot == 0) break;

        int humanity = comm_handler->GetPlayerHumanity(commSlot);
        int playerIdx = commSlot - 1;
        int colorVal = this->playerColor(playerIdx);
        int colorIdx = colorVal - 1;

        // Set player type: 4 = computer, 0 = human
        if (humanity == 4 || all_cp == 1 || (all_cp == 2 && pos > 0)) {
            player_info.type[pos] = 4;
        } else {
            player_info.type[pos] = 0;
        }

        // Set civilization
        int civVal;
        if (this->campaignGame() == 0) {
            civVal = this->civilization(playerIdx);
        } else {
            civVal = (scenario_info != nullptr) ? scenario_info->PlCivilization[colorIdx] : this->civilization(playerIdx);
        }
        player_info.tribe[pos] = (char)civVal;

        // Set player name
        if (this->multiplayerGame() != 0 && humanity == 2) {
            // Multiplayer human: get name from comm
            char* commName = comm_handler->GetPlayerName(commSlot);
            if (commName) {
                strncpy(player_info.name[pos], commName, 64);
                player_info.name[pos][64] = '\0';
            }
        } else {
            if (this->campaignGame() != 0 && player_info.type[pos] == 0) {
                const char* campaign_name =
                    (this->player_game_info != nullptr) ? this->player_game_info->get_current_player_name() : nullptr;
                if (campaign_name != nullptr) {
                    strncpy(player_info.name[pos], campaign_name, 64);
                    player_info.name[pos][64] = '\0';
                }
            } else if (this->campaignGame() == 0 && this->randomGame() != 0 && player_info.type[pos] == 0) {
                this->get_string(0x286d, player_info.name[pos], 65);
            } else if ((this->campaignGame() != 0 || this->scenarioGame() != 0) &&
                       scenario_info != nullptr) {
                const char* scenario_name = scenario_info->player_name[colorIdx];
                if (scenario_name != nullptr) {
                    strncpy(player_info.name[pos], scenario_name, 64);
                    player_info.name[pos][64] = '\0';
                }
            }

            if (player_info.name[pos][0] == '\0') {
                if (player_info.type[pos] == 0) {
                    this->get_string(0x286d, player_info.name[pos], 65);
                } else {
                    int cnIdx = this->computerName(playerIdx);
                    if (this->campaignGame() == 0 && cnIdx != 0) {
                        this->get_string(cnIdx + 0x1130, player_info.name[pos], 65);
                    } else {
                        int rcn = this->randomComputerName((int)player_info.tribe[pos]);
                        this->get_string(rcn + 0x1130, player_info.name[pos], 65);
                    }
                }
            }

            comm_handler->SetPlayerName(commSlot, player_info.name[pos]);
        }

        // Set color and player_id_hash
        player_info.color[pos] = (short)colorIdx;
        player_info.player_id_hash[pos] = colorVal;
        player_info.player_num = (short)(pos + 1);
    }

    if (scenario_info != nullptr) {
        delete scenario_info;
        scenario_info = nullptr;
    }

    // --- Phase 10: Call world->new_game() ---
    if (player_info.player_num == 0) {
        return 0;
    }

    if (!this->world && !this->load_game_data()) {
        return 0;
    }
    if (!this->world) {
        return 0;
    }

    int local_player_slot = 1;
    if (this->multiplayerGame() != 0) {
        local_player_slot = (int)comm_handler->WhoAmI();
    }
    int local_player_id = this->playerID(local_player_slot);

    if (this->sound_system != nullptr) {
        *((unsigned char*)this->sound_system + 1) = 1;
    }

    int result = (int)this->world->new_game(&player_info, local_player_id);
    if (result != 0 && this->world->player_num < 2) {
        this->world->del_game_info();
        result = 0;
    }
    if (this->sound_system != nullptr) {
        *((unsigned char*)this->sound_system + 1) = 0;
    }

    // --- Phase 10: Post-game-creation setup ---

    // Reset countdown timers
    for (int i = 0; i < this->world->player_num; ++i) {
        this->reset_countdown_timer(i);
    }

    this->world->update_mutual_allies();

    this->set_map_visible('\0');

    // Full visibility check
    if (this->fullVisibility() != 0) {
        for (int i = 1; i < this->world->player_num; ++i) {
            RGE_Player* player = this->world->players[i];
            if (player != nullptr && player->computerPlayer() == 0) {
                player->set_map_visible();
            }
        }
    }

    // Fog of war
    this->set_map_fog((unsigned char)this->fogOfWar());

    // Path finding iterations based on setting
    unsigned char pf;
    if (this->multiplayerGame() == 0) {
        pf = this->pathFinding();
    } else {
        pf = this->mpPathFinding();
    }
    if (pf == 1) {
        numberPathingIterations = 5000;
    } else if (pf == 2) {
        numberPathingIterations = 7500; // 0x1d4c
    } else {
        numberPathingIterations = 2500; // 0x9c4
    }

    // Save humanity values
    for (uint i = 1; i < 9; ++i) {
        int h = comm_handler->GetPlayerHumanity(i);
        this->save_humanity[i] = h;
    }

    return result;
}

int TRIBE_Game::create_game_screen() {
    // Source of truth:
    // - `src/game/src/tribegam.cpp.asm` (`create_game_screen` @ 0x00527830)
    // - `src/game/src/tribegam.cpp.decomp`

    this->disable_input();
    this->set_game_mode(0, 0);
    TRIBE_Screen_Game* screen = new TRIBE_Screen_Game();
    this->game_screen = screen;

    if (screen != nullptr) {
        if (screen->error_code == 0) {
            int mp_started = 1;
            if (this->comm_handler != nullptr) {
                mp_started = this->comm_handler->MultiplayerGameStart();
            } else if (this->multiplayerGame() != 0) {
                mp_started = 0;
            }
            if (mp_started != 0) {
                tribe_set_current_screen(screen);
                if (panel_system) {
                    panel_system->destroyPanel((char*)"Status Screen");
                }
            } else {
                TRIBE_Screen_Wait* wait_screen = new TRIBE_Screen_Wait();
                if (wait_screen != nullptr && wait_screen->error_code == 0) {
                    wait_screen->set_text(0x454);
                    tribe_set_current_screen(wait_screen);
                } else if (wait_screen != nullptr) {
                    delete wait_screen;
                    wait_screen = nullptr;
                }
                if (panel_system) {
                    panel_system->destroyPanel((char*)"Status Screen");
                }
                this->set_prog_mode(3);
            }

            tribe_retire_panel_by_name("Single Player Menu");
            tribe_retire_panel_by_name("Game Setup Screen");
            tribe_retire_panel_by_name("Select Scenario Screen");
            tribe_retire_panel_by_name("Game Settings Screen");
            tribe_retire_panel_by_name("Load Saved Game Screen");
            tribe_retire_panel_by_name("MP Setup Screen");
            tribe_retire_panel_by_name("Join Screen");
            tribe_retire_panel_by_name("MP Startup Screen");
            tribe_retire_panel_by_name("Main Menu");
            tribe_retire_panel_by_name("Campaign Selection Screen");

            if (this->prog_mode != 3) {
                this->let_game_begin();
            }
            return 1;
        }

        delete screen;
        this->game_screen = nullptr;
    }

    if (this->world) {
        this->world->del_game_info();
    }
    this->close_status_message();
    this->enable_input();
    return 0;
}

void TRIBE_Game::close_game_screens(int p1) {
    // Source of truth: tribegam.cpp.decomp @ 0x00521620
    // Destroy all in-game dialog and screen panels.
    if (panel_system) {
        panel_system->destroyPanel((char*)"Object List Dialog");
        panel_system->destroyPanel((char*)"OKDialog");
        panel_system->destroyPanel((char*)"YesNoDialog");
        panel_system->destroyPanel((char*)"RestartDialog");
        panel_system->destroyPanel((char*)"QuitGameDialog");
        panel_system->destroyPanel((char*)"CloseProgramDialog");
        panel_system->destroyPanel((char*)"QuitAndLoadDialog");
        panel_system->destroyPanel((char*)"ResignDialog");
        panel_system->destroyPanel((char*)"Help Dialog");
        panel_system->destroyPanel((char*)"About Dialog");
        panel_system->destroyPanel((char*)"Send Quick Message Dialog");
        panel_system->destroyPanel((char*)"Mission Dialog");
        panel_system->destroyPanel((char*)"Send Message Dialog");
        panel_system->destroyPanel((char*)"Diplomacy Dialog");
        panel_system->destroyPanel((char*)"Menu Dialog");
        panel_system->destroyPanel((char*)"Save Game Screen");
        panel_system->destroyPanel((char*)"Load Saved Game Screen");
        panel_system->destroyPanel((char*)"End Screen");
        panel_system->destroyPanel((char*)"Achievements Screen");
        panel_system->destroyPanel((char*)"Multiplayer Wait Screen");
        panel_system->destroyPanel((char*)"Multiplayer Disconnect Screen");
        if (p1 != 0) {
            this->game_screen = nullptr;
            panel_system->destroyPanel((char*)"Game Screen");
        }
    }
}

int TRIBE_Game::start_game(int p1) {
    // Source of truth:
    // - `src/game/src/tribegam.cpp.asm` (`start_game` @ 0x00525D20)
    // - `src/game/src/tribegam.cpp.decomp`
CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("start_game(%d): SP=%d MP=%d scenario=%d random=%d numPlayers=%d",
        p1, this->singlePlayerGame(), this->multiplayerGame(),
        this->scenarioGame(), this->randomGame(), this->numberPlayers());
CUSTOM_DEBUG_END
    char info_file[256];
    long info_id;

    if (this->rge_game_options.singlePlayerGameValue != 0) {
        strcpy(info_file, "scr2");
        info_id = 0xc384;
    } else {
        strcpy(info_file, "scr3");
        info_id = 0xc385;
    }

    this->disable_input();

    if (!this->world) {
        this->show_status_message(0x44d, info_file, info_id);
        if (!this->load_game_data()) {
            goto start_game_fail;
        }
    }

    this->show_status_message(0x451, info_file, info_id);
    if (!this->create_game(0)) {
        goto start_game_fail;
    }

    this->set_save_game_name((char*)0);
    this->set_load_game_name((char*)0);

    if (p1 != 0) {
CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG("start_game: direct path calling create_game_screen");
CUSTOM_DEBUG_END
        return this->create_game_screen();
    }

    // Original path starts intro video id=3 and reaches game screen through video callbacks.
    // Our current path keeps the same sequencing but still skips actual AVI decode/playback.
    //
    // Source-of-truth note: `start_game` does not branch on `start_video` return; it returns
    // success after scheduling video/start transition.
    this->start_video(3, info_file);
CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("start_game: complete, prog_mode=%d", this->prog_mode);
CUSTOM_DEBUG_END
    return 1;

start_game_fail:
    this->close_status_message();
    this->enable_input();
    return 0;
}

int TRIBE_Game::start_scenario(char* p1) {
    // Fully verified. Source of truth: tribegam.cpp.decomp @ 0x00525EE0
    _finddata_t file_info;
    char scenario_file[260];
    int first_any_player = -1;

    this->disable_input();

    this->setSinglePlayerGame(1);
    this->setCampaignGame(0);
    this->setSavedGame(0);
    this->setScenarioGame(1);
    this->setScenarioName(p1);

    this->setVictoryType((VictoryType)1, 0);
    this->setFullVisibility(0);
    this->setFogOfWar(1);
    this->setAllowCheatCodes(1);
    this->setRandomizePositions(0);
    this->setLongCombat(0);
    this->setAllowTrading(1);
    this->setFullTechTree(0);
    this->setResourceLevel((ResourceLevel)0);
    this->setStartingAge((Age)0);
    this->setStartingUnits(0);
    this->setDeathMatch('\0');
    this->setPopLimit('2');
    this->setDifficulty(this->single_player_difficulty);
    this->setQuickStartGame('\0');

    sprintf(scenario_file, "%s%s.scn", this->prog_info->scenario_dir, p1);
    long find_h = _findfirst(scenario_file, &file_info);
    const char* ext_fmt = (find_h == -1) ? "%s.scx" : "%s.scn";
    if (find_h != -1) {
        _findclose(find_h);
    }
    sprintf(scenario_file, ext_fmt, p1);

    RGE_Scenario* scenario = this->get_scenario_info(scenario_file, 0);
    if (scenario == nullptr) {
        this->enable_input();
        return 0;
    }

    int active_count = 0;
    for (int i = 0; i < 9; ++i) {
        if (scenario->PlActive[i] != 0) {
            this->setScenarioPlayer(active_count, i);
            this->setCivilization(i, scenario->PlCivilization[i]);
            this->setPlayerColor(i, i + 1);
            this->setPlayerTeam(i, 1);
            this->setComputerName(i, 0);
            active_count = active_count + 1;

            if (first_any_player == -1 && scenario->PlType[i] == 1) {
                first_any_player = i;
            }
        }
    }

    delete scenario;

    if (active_count == 0) {
        this->enable_input();
        return 0;
    }

    this->setNumberPlayers(active_count);

    if (first_any_player != -1) {
        for (int i = 1; i < active_count; ++i) {
            if (this->tribe_game_options.scenarioPlayerValue[i] == first_any_player) {
                this->setScenarioPlayer(i, this->tribe_game_options.scenarioPlayerValue[0]);
                break;
            }
        }
        this->setScenarioPlayer(0, first_any_player);
    }

    if (this->comm_handler != nullptr) {
        this->comm_handler->SetPlayerHumanity(1, 2);

        for (int slot = 2; slot <= active_count; ++slot) {
            this->comm_handler->SetPlayerHumanity((uint)slot, 4);
        }

        for (int slot = active_count + 1; slot < 10; ++slot) {
            this->comm_handler->SetPlayerHumanity((uint)slot, 1);
        }
    }

    return this->start_game(1);
}

int TRIBE_Game::load_game(char* p1) {
    // Source of truth:
    // - `src/game/src/tribegam.cpp.asm` (`load_game` @ 0x00526170)
    // - `src/game/src/tribegam.cpp.decomp`
    this->inHandleIdle = 0;

    TPanel* previous_panel = (panel_system != nullptr) ? panel_system->currentPanelValue : nullptr;
    uchar loaded = 0;
    this->disable_input();

    if (this->prog_mode == 4 || this->prog_mode == 5 || this->prog_mode == 6) {
        this->prog_mode = 0;
        this->game_screen = nullptr;
        if (panel_system != nullptr) {
            panel_system->destroyPanel((char*)"Game Screen");
        }
    }

    this->show_status_message(0x44d, (char*)0, -1);
    if (this->load_game_data() == 0) {
        goto LOAD_GAME_FAILED;
    }

    this->show_status_message(0x452, (char*)0, -1);

    if (this->check_prog_argument((char*)"DEBUGSAVEGAME") != 0) {
        ENABLE_COMPRESSION = 0;
    }

    if (this->world != nullptr) {
        loaded = this->world->load_game(p1);
        for (int i = 0; i < this->world->player_num; ++i) {
            this->reset_countdown_timer(i);
        }
    }

    ENABLE_COMPRESSION = 1;

    if (loaded != 0) {
        if (this->world != nullptr && this->world->map != nullptr) {
            this->setFullVisibility((int)this->world->map->map_visible_flag);
            this->setFogOfWar((int)this->world->map->fog_flag);
        }
        this->setAllowCheatCodes(1);
        this->setSavedGame(1);

        if (this->world != nullptr) {
            this->setNumberPlayers((int)this->world->player_num - 1);
        }

        unsigned char pf = this->pathFinding();
        if (pf == 1) {
            numberPathingIterations = 5000;
        } else if (pf == 2) {
            numberPathingIterations = 7500;
        } else {
            numberPathingIterations = 2500;
        }

        for (int slot = 0; slot < 9; ++slot) {
            if (this->world != nullptr && slot < this->world->player_num) {
                this->setPlayerID(slot, slot);

                if (slot > 0 && this->comm_handler != nullptr) {
                    RGE_Player* p = this->world->players[slot];
                    if (p != nullptr && p->name != nullptr) {
                        this->comm_handler->SetPlayerName((uint)slot, p->name);
                    }

                    int humanity = (slot == 1) ? 2 : 4;
                    this->comm_handler->SetPlayerHumanity((uint)slot, humanity);
                }
            } else {
                this->setPlayerID(slot, 0);
                if (slot > 0 && this->comm_handler != nullptr) {
                    this->comm_handler->SetPlayerHumanity((uint)slot, 1);
                }
            }
        }

        char file_name_no_ext[260];
        file_name_no_ext[0] = '\0';
        if (p1 != nullptr) {
            strncpy(file_name_no_ext, p1, sizeof(file_name_no_ext) - 1);
            file_name_no_ext[sizeof(file_name_no_ext) - 1] = '\0';
            char* dot = strchr(file_name_no_ext, '.');
            if (dot != nullptr) {
                *dot = '\0';
            }
        }
        this->set_save_game_name(file_name_no_ext);
        this->set_load_game_name(file_name_no_ext);

        if (this->check_prog_argument((char*)"DEBUGLOAD") != 0) {
            // Partial parity with tribegam.cpp DEBUGLOAD path:
            // write a deterministic runtime snapshot to C:\<save_name>.txt.
            tribe_write_debugload_dump(this, file_name_no_ext);
        }

        this->close_status_message();
        this->close_game_screens(0);
        return this->create_game_screen();
    }

LOAD_GAME_FAILED:
    if (previous_panel != nullptr &&
        previous_panel->panelNameValue != nullptr &&
        previous_panel->panelNameValue[0] != '\0' &&
        panel_system != nullptr) {
        panel_system->setCurrentPanel(previous_panel->panelNameValue, 0);
        panel_system->destroyPanel((char*)"Status Screen");
        this->close_status_message();
        this->enable_input();
        return 0;
    }

    this->close_status_message();
    this->enable_input();
    return 0;
}

int TRIBE_Game::load_db_files() {
    // Fully verified. Source of truth: tribegam.cpp.decomp @ 0x00524530
    this->disable_input();
    this->show_status_message(0x44d, (char*)0, -1);

    uint result = 0;

    if (this->world != nullptr) {
        delete this->world;
        this->world = nullptr;
    }

    RGE_Game_World* world = this->create_world();
    this->world = world;
    if (world != nullptr) {
        result = (uint)(world->data_load(this->prog_info->game_data_file, this->prog_info->sounds_dir) != 0);

        if (this->world != nullptr) {
            delete this->world;
            this->world = nullptr;
        }
    }

    this->close_status_message();
    this->enable_input();
    return (int)result;
}

int TRIBE_Game::start_menu() {
    // Best-effort reimplementation based on immutable reference:
    // `src/game/src/tribegam.cpp.asm` / `.decomp` (start_menu @ 0x00524030).
CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("TRIBE_Game::start_menu: enter world=%p game_screen=%p", this->world, this->game_screen);
CUSTOM_DEBUG_END

    // If we are returning from an active game, clear gameplay state before menu creation.
    // Important: keep Game Screen destruction out of close_game_screens here, because
    // screen switching already removes/retires the old current screen.
    this->close_game_screens(0);
    this->game_screen = nullptr;
    if (this->world) {
        delete this->world;
        this->world = nullptr;
    }

    if (this->video_setup != 0) {
        this->shutdown_video_system();
    }

    TRIBE_Screen_Main_Menu* menu = new TRIBE_Screen_Main_Menu();
    if (!menu) {
CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG("TRIBE_Game::start_menu: allocation failed");
CUSTOM_DEBUG_END
        return 0;
    }

    // The constructor calls `TScreenPanel::setup(...)`. If it failed, `TPanel::error_code` is set.
    if (menu->error_code != 0) {
CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT("TRIBE_Game::start_menu: menu setup failed error_code=%d", menu->error_code);
CUSTOM_DEBUG_END
        delete menu;
        return 0;
    }

    // The original uses `TPanelSystem::setCurrentPanel(panel_system, "Main Menu", 0)`.
    // We do best-effort equivalent with our simplified panel-system implementation.
    tribe_set_current_screen(menu);

    // In the original, this is done via a virtual call at vtable +0xC (set_prog_mode).
    this->set_prog_mode(2);

    TMusic_System* music = this->music_system;
    if (music != nullptr && this->started_menu_music == 0) {
        uchar music_type = music->music_type;
        if (music_type == 1) {
            music->play_track(2, 0, 0);
        } else if (music_type == 2) {
            music->play_file((char*)"open.mid", 0, 0);
        } else if (music_type == 3) {
            music->play_file((char*)"open.wav", 0, 0);
        }
        this->started_menu_music = 1;
    }

CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("TRIBE_Game::start_menu: success prog_mode=%d current_screen=%p", this->prog_mode, menu);
CUSTOM_DEBUG_END
    return 1;
}

void TRIBE_Game::let_game_begin() {
    // Source of truth: tribegam.cpp.decomp @ 0x00528670
    // This function transitions the game from setup into actual gameplay.
    // The original does extensive run_log of game settings (map type, size, victory, etc.)
    // We skip the logging and focus on the critical state transitions.

    // Source of truth: tribegam.cpp.decomp @ 0x00528670.
    // Panel transitions into "Game Screen" are handled by create_game_screen().

    run_log((char*)"game_started", 1);

CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG("let_game_begin: transitioning to in-game mode");
CUSTOM_DEBUG_END

    TMusic_System* music = this->music_system;
    if (music != nullptr) {
        uchar music_type = music->music_type;
        if (music_type == 1) {
            music->play_tracks(5, 0x0E, 1, 0, 0);
        } else if (music_type == 2) {
            music->play_tracks(1, music->track_count, 1, 0, 0);
        } else if (music_type == 3) {
            music->stop_track();
        }
        this->started_menu_music = 0;
    }

    // Source of truth: tribegam.cpp.decomp @ 0x00528670 line 6780
    this->reset_timings();

    // Critical: set prog_mode to 4 (in-game)
    this->set_prog_mode(4);

    // Single player: unpause
    if (this->singlePlayerGame() == 1) {
        this->set_paused(0, 0);
    }

    this->auto_paused = 0;

    if (chat != nullptr) {
        TChat* chat_system = (TChat*)chat;
        chat_system->ClearChat();

        int current_world_player = 0;
        if (this->world != nullptr) {
            current_world_player = (int)this->world->curr_player;
        }
        chat_system->setInChatGroup(current_world_player, 1);
    }

    if (this->mouse_pointer != nullptr && this->prog_ready != 0 && this->prog_window != nullptr) {
        if (!IsIconic((HWND)this->prog_window)) {
            this->mouse_pointer->center();
        }
    }

    this->enable_input();
}

int TRIBE_Game::start_video(int p1, char* p2) {
    // Source of truth: tribegam.cpp.decomp @ 0x005237B0
    char temp_name[260];
    temp_name[0] = '\0';

    if (this->video_window != nullptr) {
        tribe_close_video_window(this);
    }

    this->cur_video = p1;

    if (this->check_prog_argument((char*)"NOVIDEO") != 0 || this->check_prog_argument((char*)"SKIPVIDEO") != 0) {
        this->stop_video(1);
        return 0;
    }

    if (p2 != nullptr && p2[0] != '\0' && this->prog_info != nullptr) {
        sprintf(temp_name, "%s%s.avi", this->prog_info->avi_dir, p2);
        int fd = _open(temp_name, 0, 0x100);
        if (fd == -1) {
            char* cd_path = (this->registry != nullptr) ? this->registry->RegGetAscii(0, "CDPath") : nullptr;
            if (cd_path != nullptr) {
                sprintf(temp_name, "%sgame\\avi\\%s.avi", cd_path, p2);
                fd = _open(temp_name, 0, 0x100);
            }
        }

        if (fd != -1) {
            _close(fd);

            if (video_codec_available != 0 && (this->video_setup != 0 || this->setup_video_system() != 0)) {
                // TODO: STUB: AVI playback/callback flow is not restored yet.
                // Keep timing fields coherent, then advance via stop_video sequence.
                this->video_paused = 0;
                this->last_video_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x598);
            }
        }
    }

    this->stop_video(1);
    return 0;
}

int TRIBE_Game::setup_video_system() {
    // Source of truth: tribegam.cpp.decomp @ 0x0052A260
    if (this->video_setup != 0) {
        return 1;
    }

    if (panel_system != nullptr) {
        panel_system->setCurrentPanel((char*)"Blank Screen", 0);
    }

    this->mouse_off();
    this->video_double_size = 1;
    this->video_changed_res = 0;
    this->video_hi_color = 0;
    this->video_save_palette = this->prog_palette;

    if (this->draw_system != nullptr && this->draw_system->ScreenMode == 2) {
        SetCursor(nullptr);
        if (this->prog_window != nullptr) {
            SetClassLongA((HWND)this->prog_window, GCL_HCURSOR, 0);
        }

        this->video_save_res_wid = this->draw_system->ScreenWidth;
        this->video_save_res_hgt = this->draw_system->ScreenHeight;

        if (this->check_prog_argument((char*)"8BITVIDEO") == 0) {
            if (this->draw_system->IsModeAvail(0x280, 0x1e0, 0x10) != 0) {
                this->video_changed_res = this->draw_system->SetDisplaySize(0x280, 0x1e0, 0x10);
                if (this->video_changed_res != 0) {
                    this->video_double_size = 1;
                    this->video_hi_color = 1;
                }
            }

            if (this->video_changed_res == 0 && this->draw_system->ScreenWidth != 0x280) {
                if (this->draw_system->IsModeAvail(0x280, 0x1e0, 8) != 0) {
                    this->video_changed_res = this->draw_system->SetDisplaySize(0x280, 0x1e0, 8);
                    if (this->video_changed_res != 0) {
                        this->video_double_size = 1;
                    }
                }
            }
        }
    }

    this->set_prog_mode(1);
    this->stop_sound_system();
    this->video_setup = 1;
    return 1;
}

void TRIBE_Game::stop_video(int p1) {
    // Source of truth: tribegam.cpp.decomp @ 0x00523B10
    int save_vid_num = this->cur_video;
    this->cur_video = -1;

    if (this->video_window != nullptr) {
        tribe_close_video_window(this);

        if (this->draw_system != nullptr) {
            this->draw_system->ClearPrimarySurface();
            this->draw_system->SetPalette(this->prog_palette);
            this->render_all = 1;
            if (this->prog_window != nullptr) {
                InvalidateRect((HWND)this->prog_window, 0, 1);
                SendMessageA((HWND)this->prog_window, 0x0F, 0, 0);
            }
            this->draw_system->ClearPrimarySurface();
        }
    }

    switch (save_vid_num) {
    case 0:
        if (p1 != 0) {
            this->start_video(1, (char*)"logo2");
            return;
        }
        break;
    case 1:
        if (p1 != 0) {
            this->start_video(2, (char*)"introx");
            return;
        }
        break;
    case 3:
        if (this->video_setup != 0) {
            this->shutdown_video_system();
        }
        // TODO: STUB: mission-dialog branch from 0x00523C8D is not restored.
        this->create_game_screen();
        return;
    case 4:
        if (this->video_setup != 0) {
            this->shutdown_video_system();
        }
        // TODO: STUB: achievements/game-over branch from 0x00523D0F is not restored.
        break;
    default:
        break;
    }

    if (this->start_menu() == 0) {
        this->close();
    }
}

void TRIBE_Game::shutdown_video_system() {
    // Source of truth: tribegam.cpp.decomp @ 0x0052A430
    if (this->video_setup == 0) {
        return;
    }

    if (this->video_changed_res != 0 && this->draw_system != nullptr) {
        this->draw_system->SetDisplaySize(this->video_save_res_wid, this->video_save_res_hgt, 8);
        this->draw_system->ClearPrimarySurface();
        this->draw_system->SetPalette(this->video_save_palette);
        this->video_changed_res = 0;
        this->draw_system->CheckSurfaces();
        this->draw_system->ClearRestored();
        restore_mouse_after_paint = 1;
    }

    if (this->draw_system != nullptr) {
        this->draw_system->ClearPrimarySurface();
        this->draw_system->SetPalette(this->video_save_palette);
    }

    this->render_all = 1;
    if (this->prog_window != nullptr) {
        InvalidateRect((HWND)this->prog_window, 0, 1);
    }

    this->set_prog_mode(2);
    this->restart_sound_system();
    this->set_mouse_cursor(LoadCursorA(0, IDC_ARROW));
    this->mouse_on();
    this->video_setup = 0;
}

long TRIBE_Game::video_wnd_proc(void* p1, uint p2, uint p3, long p4) {
    // Source of truth: tribegam.cpp.decomp @ 0x0052A190
    if (p2 == 0x200) {
        SetCursor(0);
        return 0;
    }

    if (p2 == 0x201 || p2 == 0x204) {
        this->stop_video(1);
        return 0;
    }

    if (this->old_video_wnd_proc != nullptr) {
        return CallWindowProcA((WNDPROC)this->old_video_wnd_proc, (HWND)p1, p2, p3, p4);
    }

    return DefWindowProcA((HWND)p1, p2, p3, p4);
}

void TRIBE_Game::disconnect_multiplayer_game() {
    // Source of truth: tribegam.cpp.decomp @ 0x0052A510
    if (this->comm_handler == nullptr) {
        return;
    }

    if (this->multiplayerGame() == 0) {
        this->comm_handler->GameOver();
        return;
    }

    int mode = this->prog_mode;
    if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
        this->comm_handler->SendIResignMsg();
        this->comm_handler->ShutdownGameMessages();

        if (this->comm_handler->CountWaitingMessages() > 0) {
            this->disable_input();
            this->show_status_message(0x4c0, (char*)0, -1);

            ulong start = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x15f8);
            ulong loop_time = start;

            for (;;) {
                if (this->world == nullptr || this->world->game_state == 1) {
                    break;
                }

                this->comm_handler->ShutdownGameMessages();

                ulong now = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x1601);
                if (now - loop_time < 500) {
                    continue;
                }

                if (this->comm_handler->CountWaitingMessages() == 0) {
                    break;
                }

                loop_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x1605);
                if (loop_time - start >= 15000) {
                    break;
                }
            }
        }

        this->comm_handler->GameOver();
        this->comm_handler->UnlinkToLevel((COMMSTATUS)5);
    }
}

// Virtual overrides
int TRIBE_Game::run() { return RGE_Base_Game::run(); }
long TRIBE_Game::wnd_proc(void* p1, uint p2, uint p3, long p4) { return RGE_Base_Game::wnd_proc(p1, p2, p3, p4); }

void TRIBE_Game::set_prog_mode(int p1) {
    // TRIBE_Game doesn't seem to override this, but uses base
    RGE_Base_Game::set_prog_mode(p1);
}

void TRIBE_Game::set_game_mode(int param_1, int param_2) {
    // ASM 0x005227D0
    int old_mode = this->game_mode;
    RGE_Base_Game::set_game_mode(param_1, param_2);
    if (this->game_screen) {
        this->game_screen->game_mode_changed(param_1, old_mode);
    }
}

void TRIBE_Game::set_player(short p1) {
    // ASM 0x00522810
    short old_player = 0;
    if (this->world) {
        old_player = this->world->curr_player;
    }
    RGE_Base_Game::set_player(p1);
    if (this->world != nullptr && this->game_screen != nullptr) {
        this->game_screen->player_changed((int)old_player, (int)this->world->curr_player);
    }
}

int TRIBE_Game::get_error_code() { return RGE_Base_Game::get_error_code(); }

char* TRIBE_Game::get_string(int p1, long p2, char* p3, int p4) { return RGE_Base_Game::get_string(p1, p2, p3, p4); }
char* TRIBE_Game::get_string(long p1, char* p2, int p3) {
    // Source of truth: `src/game/src/tribegam.cpp.decomp` @ 0x005228E0.
    // Expansion string table is checked first, then base table fallback.
    if (!p2 || p3 <= 0) return p2;

    const int loaded = (StringTableX != nullptr) ? LoadStringA((HMODULE)StringTableX, (UINT)p1, p2, p3) : 0;
    if (loaded == 0) {
        return RGE_Base_Game::get_string(p1, p2, p3);
    }

    p2[p3 - 1] = '\0';
    return p2;
}
char* TRIBE_Game::get_string(long p1) { return RGE_Base_Game::get_string(p1); }
char* TRIBE_Game::get_string2(int p1, long p2, long p3, char* p4, int p5) { return RGE_Base_Game::get_string2(p1, p2, p3, p4, p5); }

TPanel* TRIBE_Game::get_view_panel() { return nullptr; }
TPanel* TRIBE_Game::get_map_panel() { return nullptr; }

RGE_Scenario_Header* TRIBE_Game::new_scenario_header(RGE_Scenario* p1) {
    // Source of truth: tribegam.cpp.decomp @ 0x00523570
    return new TRIBE_Scenario_Header((T_Scenario*)p1);
}
RGE_Scenario_Header* TRIBE_Game::new_scenario_header(int p1) {
    // Source of truth: tribegam.cpp.decomp @ 0x00523510
    return new TRIBE_Scenario_Header(p1);
}
RGE_Scenario* TRIBE_Game::new_scenario_info(int p1) {
    // Source of truth: tribegam.cpp.decomp @ 0x005235D0
    return new T_Scenario(p1, nullptr);
}

void TRIBE_Game::notification(int p1, long p2, long p3, long p4, long p5) {}
int TRIBE_Game::reset_comm() {
    // Source of truth: tribegam.cpp.decomp forwards to base reset path.
    return RGE_Base_Game::reset_comm();
}
void TRIBE_Game::send_game_options() {}
void TRIBE_Game::receive_game_options() {}
char* TRIBE_Game::gameSummary() { return nullptr; }
int TRIBE_Game::processCheatCode(int p1, char* p2) { return 0; }
int TRIBE_Game::setup_music_system() { return RGE_Base_Game::setup_music_system(); }
void TRIBE_Game::shutdown_music_system() { RGE_Base_Game::shutdown_music_system(); }

// NOTE: These setup_* functions delegate to parent class per ASM analysis.
// TRIBE_Game does NOT override initialization behavior - only TRIBE_Game::setup() is overridden.
int TRIBE_Game::setup_class() { return RGE_Base_Game::setup_class(); }
int TRIBE_Game::setup_main_window() { return RGE_Base_Game::setup_main_window(); }
int TRIBE_Game::setup_graphics_system() { return RGE_Base_Game::setup_graphics_system(); }
int TRIBE_Game::setup_palette() {
    if (!RGE_Base_Game::setup_palette()) {
        return 0;
    }

    // ASM hardcoded values for player colors (starts at index 0x17)
    // tribegam.cpp:813-818
    if (this->prog_palette) {
        PALETTEENTRY pe[39];
        memset(pe, 0, sizeof(pe));

        // Note: The original ASM sets specific entries. We map them here from the assembly at 0x00522200.
        // peFlags are set to 0.
        
        // Basic mapping based on assembly 0x00522200:
        // Index 0xF8 (pe[0]): 17 27 7c (Match ASM PUSH 0xF8)
        pe[0].peRed = 0x17; pe[0].peGreen = 0x27; pe[0].peBlue = 0x7c;
        // Index 0xF9 (pe[1]): 27 3f 90
        pe[1].peRed = 0x27; pe[1].peGreen = 0x3f; pe[1].peBlue = 0x90;
        // Index 0xFA (pe[2]): 3f 5f 9f
        pe[2].peRed = 0x3f; pe[2].peGreen = 0x5f; pe[2].peBlue = 0x9f;
        // Index 0xFB (pe[3]): 57 7b b4
        pe[3].peRed = 0x57; pe[3].peGreen = 0x7b; pe[3].peBlue = 0xb4;
        // Index 0xFC (pe[4]): 3f 5f a0
        pe[4].peRed = 0x3f; pe[4].peGreen = 0x5f; pe[4].peBlue = 0xa0;
        // Index 0xFD (pe[5]): 27 3f 91
        pe[5].peRed = 0x27; pe[5].peGreen = 0x3f; pe[5].peBlue = 0x91;
        // Index 0xFE (pe[6]): 17 27 7b
        pe[6].peRed = 0x17; pe[6].peGreen = 0x27; pe[6].peBlue = 0x7b;

        SetPaletteEntries((HPALETTE)this->prog_palette, 0xF8, 7, pe); 
        if (this->draw_system) {
            this->draw_system->SetPalette(this->prog_palette);
        }
    }

    return 1;
}
int TRIBE_Game::setup_mouse() { return RGE_Base_Game::setup_mouse(); }
int TRIBE_Game::setup_registry() { return RGE_Base_Game::setup_registry(); }
int TRIBE_Game::setup_debugging_log() { return RGE_Base_Game::setup_debugging_log(); }
int TRIBE_Game::setup_chat() { return RGE_Base_Game::setup_chat(); }
int TRIBE_Game::setup_comm() { return RGE_Base_Game::setup_comm(); }
int TRIBE_Game::setup_sound_system() { return RGE_Base_Game::setup_sound_system(); }
int TRIBE_Game::setup_fonts() { return RGE_Base_Game::setup_fonts(); }
int TRIBE_Game::setup_sounds() { return RGE_Base_Game::setup_sounds(); }
int TRIBE_Game::setup_shapes() { return RGE_Base_Game::setup_shapes(); }
int TRIBE_Game::setup_blank_screen() { return RGE_Base_Game::setup_blank_screen(); }
void TRIBE_Game::setup_timings() {}

void TRIBE_Game::stop_sound_system() {}
int TRIBE_Game::restart_sound_system() { return 1; }
void TRIBE_Game::stop_music_system() { RGE_Base_Game::stop_music_system(); }
int TRIBE_Game::restart_music_system() { return RGE_Base_Game::restart_music_system(); }

RGE_Game_World* TRIBE_Game::create_world() { 
    if (this->world) {
        delete this->world;
    }
    this->world = (RGE_Game_World*)new TRIBE_World();
    return this->world;
}

int TRIBE_Game::handle_message(struct tagMSG* p1) { return RGE_Base_Game::handle_message(p1); }
int TRIBE_Game::handle_idle() {
    // Source of truth: tribegam.cpp.decomp @ 0x00529610
    // 1. Call base class handle_idle first (palette, sound, panel->handle_idle, comm)
    // 2. Reentrancy guard via inHandleIdle
    // 3. Branch on prog_mode:
    //    - 1 + video_window: video playback polling
    //    - 3: multiplayer game start waiting
    //    - 4, 5, 6: in-game world update
    //    - else (2): menu mode — draw only (base already ran panel idle)

    tribe_process_pending_screen_switch();

    int base_result = RGE_Base_Game::handle_idle();
    if (base_result == 0) {
        return 0;
    }

    if (this->inHandleIdle != 0) {
        return 0;
    }

    this->inHandleIdle = 1;

    int pm = this->prog_mode;

    if (pm == 1 && this->video_window != nullptr) {
        // Source of truth: tribegam.cpp.decomp @ 0x00529610 (video polling branch)
        const ulong now = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x1381);
        if (now - this->last_video_time >= 1000) {
            char status[100];
            status[0] = '\0';
            SendMessageA((HWND)this->video_window, 0x46a, 100, (LPARAM)status);

            if (status[0] == '\0' || tribe_ascii_str_eq(status, "stopped")) {
                this->stop_video(1);
            } else if (this->video_paused == 0 && tribe_ascii_str_eq(status, "paused")) {
                SendMessageA((HWND)this->video_window, 0x855, 0, 0);
            }

            this->last_video_time =
                debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x138d);
        }
    } else if (pm == 4 || pm == 5 || pm == 6) {
        // In-game mode: world update + game screen update
        if (out_of_sync2 == 0 && this->game_screen != nullptr) {
            this->game_screen->handle_game_update();
        }

        // World update tick
        if (this->world) {
            this->world->update();
        }
    }
    // Menu mode (prog_mode == 2): base class already called panel->handle_idle()

    this->inHandleIdle = 0;
    return base_result;
}
int TRIBE_Game::handle_mouse_move(void* p1, uint p2, uint p3, long p4) { return RGE_Base_Game::handle_mouse_move(p1, p2, p3, p4); }
int TRIBE_Game::handle_key_down(void* p1, uint p2, uint p3, long p4) {
    // Source of truth: tribegam.cpp.decomp (handle_key_down in game screen context)
    // In the original, ESC opens the in-game menu dialog. Since we don't have that yet,
    // ESC during in-game mode (prog_mode == 4) returns to the main menu.

    if (this->prog_mode == 4 || this->prog_mode == 5 || this->prog_mode == 6) {
        // VK_ESCAPE = 0x1B
        if (p3 == 0x1B) {
CUSTOM_DEBUG_BEGIN
            CUSTOM_DEBUG_LOG("handle_key_down: ESC pressed in game mode, returning to menu");
CUSTOM_DEBUG_END
            int ret = this->start_menu();
            if (ret == 0) {
                this->close();
            }
            return 0; // consumed
        }
    }

    // Pass to base class for other keys / modes
    return RGE_Base_Game::handle_key_down(p1, p2, p3, p4);
}
int TRIBE_Game::handle_user_command(void* p1, uint p2, uint p3, long p4) { return RGE_Base_Game::handle_user_command(p1, p2, p3, p4); }
int TRIBE_Game::handle_command(void* p1, uint p2, uint p3, long p4) { return RGE_Base_Game::handle_command(p1, p2, p3, p4); }
int TRIBE_Game::handle_music_done(void* p1, uint p2, uint p3, long p4) { return RGE_Base_Game::handle_music_done(p1, p2, p3, p4); }
int TRIBE_Game::handle_paint(void* p1, uint p2, uint p3, long p4) {
    (void)p1;
    (void)p2;
    (void)p3;
    (void)p4;

    tribe_process_pending_screen_switch();

    TPanel* to_draw = nullptr;
    if (panel_system && panel_system->currentPanelValue) {
        to_draw = panel_system->currentPanelValue;
    } else {
        to_draw = gCurrentScreen;
    }

    if (to_draw) {
CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT("TRIBE_Game::handle_paint: drawing panel=%p name='%s'",
            to_draw, to_draw->panelNameValue ? to_draw->panelNameValue : "(null)");
CUSTOM_DEBUG_END
        if (this->input_enabled == 0) {
            // Same safety intent as `tribe_apply_screen_switch`: keep UI responsive even if the
            // idle path is not reached frequently.
            to_draw->handle_idle();
            if (this->input_enabled == 0) {
                this->enable_input();
            }
        }
        to_draw->draw_tree();
CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG("TRIBE_Game::handle_paint: draw_tree done");
CUSTOM_DEBUG_END
    }

    if (this->draw_system) {
CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG("TRIBE_Game::handle_paint: draw_system->Paint begin");
CUSTOM_DEBUG_END
        this->draw_system->Paint(NULL);
CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG("TRIBE_Game::handle_paint: draw_system->Paint done");
CUSTOM_DEBUG_END
    }
    return 1;
}
int TRIBE_Game::handle_activate(void* p1, uint p2, uint p3, long p4) { return RGE_Base_Game::handle_activate(p1, p2, p3, p4); }
int TRIBE_Game::handle_init_menu(void* p1, uint p2, uint p3, long p4) { return RGE_Base_Game::handle_init_menu(p1, p2, p3, p4); }
int TRIBE_Game::handle_exit_menu(void* p1, uint p2, uint p3, long p4) { return RGE_Base_Game::handle_exit_menu(p1, p2, p3, p4); }
int TRIBE_Game::handle_size(void* p1, uint p2, uint p3, long p4) { return RGE_Base_Game::handle_size(p1, p2, p3, p4); }
int TRIBE_Game::handle_palette_changed(void* p1, uint p2, uint p3, long p4) { return RGE_Base_Game::handle_palette_changed(p1, p2, p3, p4); }
int TRIBE_Game::handle_query_new_palette(void* p1, uint p2, uint p3, long p4) { return RGE_Base_Game::handle_query_new_palette(p1, p2, p3, p4); }
int TRIBE_Game::handle_close(void* p1, uint p2, uint p3, long p4) {
    // Return 1 (not consumed) so DefWindowProcA handles it → calls DestroyWindow
    return 1;
}
int TRIBE_Game::handle_destroy(void* p1, uint p2, uint p3, long p4) {
    PostQuitMessage(0);
    return 0; // consumed
}

int TRIBE_Game::action_update() { return 0; }
int TRIBE_Game::action_mouse_move(long p1, long p2, int p3, int p4, int p5, int p6) { return 0; }
int TRIBE_Game::action_key_down(ulong p1, int p2, int p3, int p4, int p5) {
    // Source of truth: tribegam.cpp.decomp @ 0x00529F60
    // p1 = virtual key code
    if (this->prog_mode == 1) {
        // Video playback mode
        if (p1 == 0x0D || p1 == 0x20) { // Enter or Space
            this->stop_video(1); // stop and advance
            return 0;
        }
        if (p1 == 0x1B) { // ESC
            this->stop_video(0); // stop without advancing
            return 0;
        }
        return 1; // not consumed
    }

    // Non-video mode: F1 opens help
    if (p1 == 0x70) { // VK_F1
        // Original calls WinHelpA(prog_window, "empires.hlp", 3, 0)
        // Skip for now — help file may not exist
        return 0;
    }

    return 1; // not consumed
}
int TRIBE_Game::action_user_command(ulong p1, ulong p2) { return 0; }
int TRIBE_Game::action_command(ulong p1, ulong p2) { return 0; }
int TRIBE_Game::action_music_done() { return 0; }
int TRIBE_Game::action_activate() { return 0; }
int TRIBE_Game::action_deactivate() { return 0; }
int TRIBE_Game::action_init_menu() { return 0; }
int TRIBE_Game::action_exit_menu() { return 0; }
int TRIBE_Game::action_size() { return 0; }
int TRIBE_Game::action_close() {
    // Source of truth: tribegam.cpp.decomp @ 0x0052A000
    if (this->comm_handler != nullptr) {
        this->disconnect_multiplayer_game();
        this->comm_handler = nullptr;
        comm = nullptr;
    }
    return 1;
}

void TRIBE_Game::calc_timings() {}
void TRIBE_Game::calc_timing_text() {}
void TRIBE_Game::show_timings() {}
void TRIBE_Game::show_comm() {}
void TRIBE_Game::show_ai() {}

int TRIBE_Game::setup_map_save_area() { return RGE_Base_Game::setup_map_save_area(); }

void TRIBE_Game::set_interface_messages() {
    // ASM 0x0052A210
    // Simplified selection of mouse click tables
}

void TRIBE_Game::close() { 
    // ASM 0x00524150 (quit_game-like logic)
    RGE_Base_Game::close(); 
}
