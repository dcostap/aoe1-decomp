#include <stdio.h>
#include <string.h>
#include "../include/TRIBE_Game.h"
#include "../include/Res_file.h"
#include "../include/RGE_Prog_Info.h"
#include <windows.h>

extern HINSTANCE StringTableX;
extern int disable_terrain_sounds;

TRIBE_Game::TRIBE_Game(RGE_Prog_Info* info, int param_2) : RGE_Base_Game(info, 0) {
    memset(&tribe_game_options, 0, sizeof(tribe_game_options));
    
    setMapSize(2);
    setMapType(2);
    setAnimals(1);
    setPredators(1);
    setVictoryType(1, 1);
    setAllowTrading(1);
    setLongCombat(0);
    setRandomizePositions(0);
    setFullTechTree(0);
    setResourceLevel(0);
    setStartingAge(0);
    setStartingUnits(0);
    setDeathMatch(0);
    setPopLimit(50);
    setQuickStartGame(0);
    setRandomStartValue(-1);

    for (int i = 0; i < 9; i++) {
        setCivilization(i, 1);
        setScenarioPlayer(i, 0);
        setPlayerColor(i, 1);
        setComputerName(i, 0);
    }

    RGE_Base_Game::setNumberPlayers(4);
    resetRandomComputerName();

    if (param_2) {
        if (setup() == 0) {
            if (error_code == 0) {
                error_code = 1;
            }
        }
    }
}

TRIBE_Game::~TRIBE_Game() {}

int TRIBE_Game::setup() {
    if (this->player_game_info) {
        return 0;
    }

    char* cmdLine = (char*)((unsigned char*)this->prog_info + 0x518);
    if (strstr(cmdLine, "makeres") || strstr(cmdLine, "Makeres") || strstr(cmdLine, "MAKERES")) {
        char* resDir = (char*)((unsigned char*)this->prog_info + 0xF26);
        RESFILE_build_res_file(resDir, "resource\\", "graphics.rm");
        RESFILE_build_res_file(resDir, "resource\\", "sounds.rm");
        RESFILE_build_res_file(resDir, "resource\\", "interfac.rm");
    }

    char* resDir = (char*)((unsigned char*)this->prog_info + 0xF26);
    RESFILE_open_new_resource_file(resDir, "sounds.drs", "tribe", 1);
    RESFILE_open_new_resource_file(resDir, "graphics.drs", "tribe", 0);
    RESFILE_open_new_resource_file(resDir, "Interfac.drs", "tribe", 0);

    RESFILE_open_new_resource_file("data\\", "sounds.drs", "tribe", 1);
    RESFILE_open_new_resource_file("data\\", "graphics.drs", "tribe", 0);
    RESFILE_open_new_resource_file("data\\", "Terrain.drs", "tribe", 0);
    RESFILE_open_new_resource_file("data\\", "Border.drs", "tribe", 0);
    RESFILE_open_new_resource_file("data\\", "Interfac.drs", "tribe", 0);

    if (RGE_Base_Game::setup() == 0) {
        return 0;
    }

    StringTableX = LoadLibraryA("languagex.dll");
    if (!StringTableX) {
        this->error_code = 1;
        return 0;
    }

    return 1;
}

int TRIBE_Game::setup_cmd_options() {
    char cmd_line_upper[260];
    char* cmdLine = (char*)((unsigned char*)this->prog_info + 0x518);
    strncpy(cmd_line_upper, cmdLine, 255);
    cmd_line_upper[255] = '\0';
    _strupr(cmd_line_upper);

    if (strstr(cmd_line_upper, "NOTERRAINSOUND")) {
        disable_terrain_sounds = 1;
    }

    return 1;
}

// Stubs for now
void TRIBE_Game::setMapSize(MapSize p1) { tribe_game_options.mapSizeValue = p1; }
void TRIBE_Game::setMapType(MapType p1) { tribe_game_options.mapTypeValue = p1; }
void TRIBE_Game::setAnimals(int p1) { tribe_game_options.animalsValue = p1; }
void TRIBE_Game::setPredators(int p1) { tribe_game_options.predatorsValue = p1; }
void TRIBE_Game::setVictoryType(VictoryType p1, int p2) { 
    tribe_game_options.victoryTypeValue = p1; 
    tribe_game_options.victoryAmountValue = p2; 
}
void TRIBE_Game::setAllowTrading(int p1) { tribe_game_options.allowTradingValue = p1; }
void TRIBE_Game::setLongCombat(int p1) { tribe_game_options.longCombatValue = p1; }
void TRIBE_Game::setRandomizePositions(int p1) { tribe_game_options.randomizePositionsValue = p1; }
void TRIBE_Game::setFullTechTree(int p1) { tribe_game_options.fullTechTreeValue = p1; }
void TRIBE_Game::setResourceLevel(ResourceLevel p1) { tribe_game_options.resourceLevelValue = p1; }
void TRIBE_Game::setStartingAge(Age p1) { tribe_game_options.startingAgeValue = p1; }
void TRIBE_Game::setStartingUnits(int p1) { tribe_game_options.startingUnitsValue = p1; }
void TRIBE_Game::setDeathMatch(unsigned char p1) { tribe_game_options.deathMatchValue = p1; }
void TRIBE_Game::setPopLimit(unsigned char p1) { tribe_game_options.popLimitValue = p1; }
void TRIBE_Game::setQuickStartGame(unsigned char p1) { quick_start_game = p1; }
void TRIBE_Game::setRandomStartValue(int p1) { random_start_value = p1; }
void TRIBE_Game::setCivilization(int p1, int p2) { tribe_game_options.civilizationValue[p1] = p2; }
void TRIBE_Game::setScenarioPlayer(int p1, int p2) { tribe_game_options.scenarioPlayerValue[p1] = p2; }
void TRIBE_Game::setPlayerColor(int p1, int p2) { tribe_game_options.playerColorValue[p1] = p2; }
void TRIBE_Game::setComputerName(int p1, int p2) { tribe_game_options.computerNameValue[p1] = p2; }
void TRIBE_Game::resetRandomComputerName() {}
void TRIBE_Game::close_game_screens(int p1) {}
int TRIBE_Game::start_scenario(char* p1) { return 1; }
int TRIBE_Game::load_game(char* p1) { return 1; }
int TRIBE_Game::start_menu() { return 1; }
int TRIBE_Game::start_video(const char* p1, int p2) { return 1; }

// Virtual overrides
int TRIBE_Game::run() { return RGE_Base_Game::run(); }
long TRIBE_Game::wnd_proc(void* p1, uint p2, uint p3, long p4) { return RGE_Base_Game::wnd_proc(p1, p2, p3, p4); }
void TRIBE_Game::set_prog_mode(int p1) {}
void TRIBE_Game::set_game_mode(int p1, int p2) {}
void TRIBE_Game::set_player(short p1) {}
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
RGE_Game_World* TRIBE_Game::create_world() { return nullptr; }
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
void TRIBE_Game::set_interface_messages() {}
void TRIBE_Game::close() { RGE_Base_Game::close(); }
