#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/TRIBE_Game.h"
#include "../include/Res_file.h"
#include "../include/RGE_Prog_Info.h"
#include "../include/globals.h"
#include "../include/screens.h"
#include "../include/TRIBE_World.h"
#include <windows.h>

#define CMD_LINE ((char*)((unsigned char*)this->prog_info + 0x518))
#define RESOURCE_DIR ((char*)((unsigned char*)this->prog_info + 0xF26))

TRIBE_Game::TRIBE_Game(RGE_Prog_Info* info, int param_2) : RGE_Base_Game(info, 0) {
    // tribegam.cpp:263
    // Assembly at 0x00521150
    this->cur_video = -1; // [ESI + 0xbf0] = -1
    
    // Line 250: [ESI + 0x1d8] = 1 (input_enabled = 1)
    this->input_enabled = 1;
    
    this->video_window = nullptr; // [ESI + 0x1dc]
    
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
    for (int i = 0; i < 16; i++) {
        setCivilization(i, (i % 16) + 1);
        setScenarioPlayer(i, 0);
        setPlayerColor(i, 1);
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

TRIBE_Game::~TRIBE_Game() {}

int TRIBE_Game::setup() {
    if (this->player_game_info) {
        return 0;
    }

    if (strstr(CMD_LINE, "makeres") || strstr(CMD_LINE, "Makeres") || strstr(CMD_LINE, "MAKERES")) {
        RESFILE_build_res_file(RESOURCE_DIR, "resource\\", "graphics.rm");
        RESFILE_build_res_file(RESOURCE_DIR, "resource\\", "sounds.rm");
        RESFILE_build_res_file(RESOURCE_DIR, "resource\\", "interfac.rm");
    }

    RESFILE_open_new_resource_file(RESOURCE_DIR, "sounds.drs", "tribe", 1);
    RESFILE_open_new_resource_file(RESOURCE_DIR, "graphics.drs", "tribe", 0);
    RESFILE_open_new_resource_file(RESOURCE_DIR, "Interfac.drs", "tribe", 0);

    RESFILE_open_new_resource_file("data\\", "sounds.drs", "tribe", 1);
    RESFILE_open_new_resource_file("data\\", "graphics.drs", "tribe", 0);
    RESFILE_open_new_resource_file("data\\", "Terrain.drs", "tribe", 0);
    RESFILE_open_new_resource_file("data\\", "Border.drs", "tribe", 0);
    RESFILE_open_new_resource_file("data\\", "Interfac.drs", "tribe", 0);

    if (RGE_Base_Game::setup() == 0) {
        return 0;
    }

    // Command line STRING= handler (ASM 0x0052194a)
    char cmd_line_str[260];
    strncpy(cmd_line_str, CMD_LINE, 255);
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
        this->error_code = 1;
        return 0;
    }

    // Palette setup (ASM 0x00521a55)
    if (this->prog_palette) {
        PALETTEENTRY pe[39];
        memset(pe, 0, sizeof(pe));
        
        // ASM hardcoded values at 0x00521A55
        // This is a partial manual mapping of the push/mov sequence in ASM
        pe[0].peRed = 0x17; pe[0].peGreen = 0x27; pe[0].peBlue = 0x7c; 
        pe[1].peRed = 0x17; pe[1].peGreen = 0x27; pe[1].peBlue = 0x90;
        pe[2].peRed = 0x5f; pe[2].peGreen = 0x9f; pe[2].peBlue = 0x00;
        pe[3].peRed = 0x57; pe[3].peGreen = 0xb4; pe[3].peBlue = 0x00;
        pe[4].peRed = 0x5f; pe[4].peGreen = 0xa0; pe[4].peBlue = 0x00;
        pe[5].peRed = 0x27; pe[5].peGreen = 0x91; pe[5].peBlue = 0x00;
        pe[6].peRed = 0x17; pe[6].peGreen = 0x27; pe[6].peBlue = 0x00;
        
        SetPaletteEntries((HPALETTE)this->prog_palette, 0x17, 39, pe); 
    }

    this->input_disabled_window = CreateWindowExA(0, "STATIC", "InputDisabledWindow", WS_CHILD, 0, 0, 1, 1, 
        (HWND)this->prog_window, NULL, (HINSTANCE)this->prog_info->instance, NULL);

    // Startup screens logic (ASM 0x00521b3f)
    if (this->check_prog_argument("LOBBY")) {
        // Lobby startup logic
        // TCommunications_Handler::LaunchLobbyGame ...
    } else {
        if (this->startup_scenario[0]) {
            if (this->start_scenario(this->startup_scenario)) goto FINAL_SETUP;
        }
        if (this->startup_game[0]) {
            if (this->load_game(this->startup_game)) goto FINAL_SETUP;
        }
        
        if (this->check_prog_argument("NOSTARTUP") || this->check_prog_argument("NO STARTUP")) {
            this->start_menu();
        } else {
            // Check for NOVIDEO/SKIPVIDEO etc inside start_video
            this->start_video("logo1", 0);
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
    sprintf(options_log, "options=%s", CMD_LINE);
    run_log(options_log, 0);

    return 1;
}

int TRIBE_Game::setup_cmd_options() {
    char cmd_line_upper[260];
    strncpy(cmd_line_upper, CMD_LINE, 255);
    cmd_line_upper[255] = '\0';
    _strupr(cmd_line_upper);

    if (strstr(cmd_line_upper, "NOTERRAINSOUND")) {
        disable_terrain_sounds = 1;
    }
    
    // Pop limit logic (ASM 0x0052203d)
    // ...

    if (strstr(cmd_line_upper, "QUICK1")) {
        quick_start_game_mode = 1;
    }

    return 1;
}

void TRIBE_Game::setMapSize(MapSize p1) { this->tribe_game_options.mapSizeValue = p1; }
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
void TRIBE_Game::setCivilization(int p1, int p2) { this->tribe_game_options.civilizationValue[p1] = p2; }
void TRIBE_Game::setScenarioPlayer(int p1, int p2) { this->tribe_game_options.scenarioPlayerValue[p1] = p2; }
void TRIBE_Game::setPlayerColor(int p1, int p2) { this->tribe_game_options.playerColorValue[p1] = p2; }
void TRIBE_Game::setComputerName(int p1, int p2) { this->tribe_game_options.computerNameValue[p1] = p2; }

void TRIBE_Game::resetRandomComputerName() {
    memset(this->computerNameUsed, 0, sizeof(this->computerNameUsed));
}

void TRIBE_Game::close_game_screens(int p1) {
    // TODO: implement logic from 0x00523E10
}

int TRIBE_Game::start_scenario(char* p1) {
    // TODO: implement logic from 0x00523620
    return 0;
}

int TRIBE_Game::load_game(char* p1) {
    // TODO: implement logic from 0x00523C60
    return 0;
}

int TRIBE_Game::start_menu() {
    // ASM 0x00524030
    if (this->video_setup) {
        // this->shutdown_video_system();
    }

    TRIBE_Screen_Main_Menu* menu = new TRIBE_Screen_Main_Menu();
    if (!menu) return 0;
    
    // ASM logic checks for panel error states
    
    // Set current panel and change mode
    // panel_system->setCurrentPanel("Main Menu", 0);
    this->set_prog_mode(2);
    
    // Play music etc.
    return 1;
}

int TRIBE_Game::start_video(const char* p1, int p2) {
    // TODO: implement logic from 0x00523910
    return 0;
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
        this->game_screen->game_mode_changed(this->game_mode, old_mode);
    }
}

void TRIBE_Game::set_player(short p1) {
    // ASM 0x00522810
    short old_player = 0;
    if (this->world) {
        // old_player = this->world->curr_player;
    }
    RGE_Base_Game::set_player(p1);
    // ... additional TRIBE logic ...
}

int TRIBE_Game::get_error_code() { return RGE_Base_Game::get_error_code(); }

char* TRIBE_Game::get_string(int p1, long p2, char* p3, int p4) { return RGE_Base_Game::get_string(p1, p2, p3, p4); }
char* TRIBE_Game::get_string(long p1, char* p2, int p3) { return RGE_Base_Game::get_string(p1, p2, p3); }
char* TRIBE_Game::get_string(long p1) { return RGE_Base_Game::get_string(p1); }
char* TRIBE_Game::get_string2(int p1, long p2, long p3, char* p4, int p5) { return RGE_Base_Game::get_string2(p1, p2, p3, p4, p5); }

TPanel* TRIBE_Game::get_view_panel() { return nullptr; }
TPanel* TRIBE_Game::get_map_panel() { return nullptr; }

RGE_Scenario_Header* TRIBE_Game::new_scenario_header(RGE_Scenario* p1) { return nullptr; }
RGE_Scenario_Header* TRIBE_Game::new_scenario_header(int p1) { return nullptr; }
RGE_Scenario* TRIBE_Game::new_scenario_info(int p1) { return nullptr; }

void TRIBE_Game::notification(int p1, long p2, long p3, long p4, long p5) {}
int TRIBE_Game::reset_comm() { return 0; }
void TRIBE_Game::send_game_options() {}
void TRIBE_Game::receive_game_options() {}
char* TRIBE_Game::gameSummary() { return nullptr; }
int TRIBE_Game::processCheatCode(int p1, char* p2) { return 0; }
int TRIBE_Game::setup_music_system() { return 1; }
void TRIBE_Game::shutdown_music_system() {}

int TRIBE_Game::setup_class() { return 1; }
int TRIBE_Game::setup_main_window() { return 1; }
int TRIBE_Game::setup_graphics_system() { return 1; }
int TRIBE_Game::setup_palette() { return 1; }
int TRIBE_Game::setup_mouse() { return 1; }
int TRIBE_Game::setup_registry() { return RGE_Base_Game::setup_registry(); }
int TRIBE_Game::setup_debugging_log() { return RGE_Base_Game::setup_debugging_log(); }
int TRIBE_Game::setup_chat() { return 1; }
int TRIBE_Game::setup_comm() { return 1; }
int TRIBE_Game::setup_sound_system() { return 1; }
int TRIBE_Game::setup_fonts() { return 1; }
int TRIBE_Game::setup_sounds() { return 1; }
int TRIBE_Game::setup_shapes() { return 1; }
int TRIBE_Game::setup_blank_screen() { return 1; }
void TRIBE_Game::setup_timings() {}

void TRIBE_Game::stop_sound_system() {}
int TRIBE_Game::restart_sound_system() { return 1; }
void TRIBE_Game::stop_music_system() {}
int TRIBE_Game::restart_music_system() { return 1; }

RGE_Game_World* TRIBE_Game::create_world() { 
    if (this->world) {
        delete this->world;
    }
    this->world = (RGE_Game_World*)new TRIBE_World();
    return this->world;
}

int TRIBE_Game::handle_message(struct tagMSG* p1) { return 0; }
int TRIBE_Game::handle_idle() { return 0; }
int TRIBE_Game::handle_mouse_move(void* p1, uint p2, uint p3, long p4) { return 0; }
int TRIBE_Game::handle_key_down(void* p1, uint p2, uint p3, long p4) { return 0; }
int TRIBE_Game::handle_user_command(void* p1, uint p2, uint p3, long p4) { return 0; }
int TRIBE_Game::handle_command(void* p1, uint p2, uint p3, long p4) { return 0; }
int TRIBE_Game::handle_music_done(void* p1, uint p2, uint p3, long p4) { return 0; }
int TRIBE_Game::handle_paint(void* p1, uint p2, uint p3, long p4) { return 0; }
int TRIBE_Game::handle_activate(void* p1, uint p2, uint p3, long p4) { return 0; }
int TRIBE_Game::handle_init_menu(void* p1, uint p2, uint p3, long p4) { return 0; }
int TRIBE_Game::handle_exit_menu(void* p1, uint p2, uint p3, long p4) { return 0; }
int TRIBE_Game::handle_size(void* p1, uint p2, uint p3, long p4) { return 0; }
int TRIBE_Game::handle_palette_changed(void* p1, uint p2, uint p3, long p4) { return 0; }
int TRIBE_Game::handle_query_new_palette(void* p1, uint p2, uint p3, long p4) { return 0; }
int TRIBE_Game::handle_close(void* p1, uint p2, uint p3, long p4) { return 0; }
int TRIBE_Game::handle_destroy(void* p1, uint p2, uint p3, long p4) { return 0; }

int TRIBE_Game::action_update() { return 0; }
int TRIBE_Game::action_mouse_move(long p1, long p2, int p3, int p4, int p5, int p6) { return 0; }
int TRIBE_Game::action_key_down(ulong p1, int p2, int p3, int p4, int p5) { return 0; }
int TRIBE_Game::action_user_command(ulong p1, ulong p2) { return 0; }
int TRIBE_Game::action_command(ulong p1, ulong p2) { return 0; }
int TRIBE_Game::action_music_done() { return 0; }
int TRIBE_Game::action_activate() { return 0; }
int TRIBE_Game::action_deactivate() { return 0; }
int TRIBE_Game::action_init_menu() { return 0; }
int TRIBE_Game::action_exit_menu() { return 0; }
int TRIBE_Game::action_size() { return 0; }
int TRIBE_Game::action_close() { return 0; }

void TRIBE_Game::calc_timings() {}
void TRIBE_Game::calc_timing_text() {}
void TRIBE_Game::show_timings() {}
void TRIBE_Game::show_comm() {}
void TRIBE_Game::show_ai() {}

int TRIBE_Game::setup_map_save_area() { return 1; }

void TRIBE_Game::set_interface_messages() {
    // ASM 0x0052A210
    // Simplified selection of mouse click tables
}

void TRIBE_Game::close() { 
    // ASM 0x00524150 (quit_game-like logic)
    RGE_Base_Game::close(); 
}
