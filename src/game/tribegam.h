#pragma once
#include "../common.h"
#include "basegame.h"
#include "Panel.h"
#include "Res_file.h"

class TRIBE_Screen_Game;
class TPanel;

extern int player_dropped[9]; 
extern int out_of_sync;
extern int disable_terrain_sounds;

enum Age : unsigned int {
    DefaultAge = 0,
    NomadAge = 1,
    StoneAge = 2,
    ToolAge = 3,
    BronzeAge = 4,
    IronAge = 5,
};

enum MapSize : unsigned int {
    Tiny = 0,
    Small = 1,
    Medium = 2,
    Large = 3,
    Huge = 4,
    Humongous = 5,
};

enum MapType : unsigned int {
    AllWater = 0,
    MostlyWater = 1,
    WaterAndLand = 2,
    MostlyLand = 3,
    AllLand = 4,
    Continental = 5,
    Lake = 6,
    Hilly = 7,
    Isthmas = 8,
};

enum ResourceLevel : unsigned int {
    DefaultResources = 0,
    LowResource = 1,
    MediumResources = 2,
    HighResources = 3,
    VeryHighResources = 4,
};


enum VictoryType : unsigned int {
    VictoryDefault = 0,
    VictoryConquest = 1,
    VictoryExplore = 2,
    VictoryRuins = 3,
    VictoryArtifacts = 4,
    VictoryDiscoveries = 5,
    VictoryGold = 6,
    VictoryTime = 7,
    VictoryScore = 8,
    VictoryStandard = 9,
};

// ----------------------------------------------------------------
// TRIBE_Game_Options
// Size: 0x6C
struct TRIBE_Game_Options {
    MapSize mapSizeValue; // 0x0
    MapType mapTypeValue; // 0x4
    int animalsValue; // 0x8
    int predatorsValue; // 0xC
    VictoryType victoryTypeValue; // 0x10
    int victoryAmountValue; // 0x14
    uchar civilizationValue[9]; // 0x18
    int scenarioPlayerValue[9]; // 0x24
    uchar playerColorValue[9]; // 0x48
    uchar computerNameValue[9]; // 0x51
    uchar allowTradingValue; // 0x5A
    uchar longCombatValue; // 0x5B
    uchar randomizePositionsValue; // 0x5C
    uchar fullTechTreeValue; // 0x5D
    ResourceLevel resourceLevelValue; // 0x60
    Age startingAgeValue; // 0x64
    uchar startingUnitsValue; // 0x68
    uchar deathMatchValue; // 0x69
    uchar popLimitValue; // 0x6A
};

// ----------------------------------------------------------------
// combined_options
// Size: 0x114
struct combined_options {
    RGE_Game_Options rge_options; // 0x0
    TRIBE_Game_Options tribe_options; // 0xA8
};

class TRIBE_Game : public RGE_Base_Game       {
public:
    MouseClickInfo* MouseRightClickTable;    // 0xA24
    int MouseRightClickTableSize;            // 0xA28
    MouseClickInfo* MouseLeftClickTable;     // 0xA2C
    int MouseLeftClickTableSize;             // 0xA30
    long queue_is_waiting_on_pop_counter[9]; // 0xA34
    int random_civ[9];                       // 0xA58
    TRIBE_Game_Options tribe_game_options;   // 0xA7C
    char testing_scenario[260];              // 0xAE8
    void* video_window;                      // 0xBEC
    int cur_video;                           // 0xBF0
    void* old_video_wnd_proc;                // 0xBF4
    int video_paused;                        // 0xBF8
    ulong last_video_time;                   // 0xBFC
    int video_setup;                         // 0xC00
    int video_double_size;                   // 0xC04
    int video_changed_res;                   // 0xC08
    int video_hi_color;                      // 0xC0C
    long video_save_res_wid;                 // 0xC10
    long video_save_res_hgt;                 // 0xC14
    void* video_save_palette;                // 0xC18
    int started_menu_music;                  // 0xC1C
    int show_object_id;                      // 0xC20
    TRIBE_Screen_Game* game_screen;          // 0xC24
    long notification_loc_x[5];              // 0xC28
    long notification_loc_y[5];              // 0xC3C
    long current_notification_loc;           // 0xC50
    long current_notification_recalled;      // 0xC54
    char startup_scenario[260];              // 0xC58
    char startup_game[260];                  // 0xD5C
    ulong auto_exit_time;                    // 0xE60
    char save_game_name[260];                // 0xE64
    char load_game_name[260];                // 0xF68
    char timing_text2[256];                  // 0x106C
    int save_humanity[9];                    // 0x116C
    uchar quick_start_game;                  // 0x1190
    int random_start_value;                  // 0x1194
    uchar computerNameUsed[18][10];          // 0x1198
    void* handleIdleLock;                    // 0x124C
    int inHandleIdle;                        // 0x1250

    TRIBE_Game(RGE_Prog_Info* param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TRIBE_Game() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void run();

    // [Slot 02] Offset 0x08 (Override)
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: wnd_proc

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void set_prog_mode();

    // [Slot 04] Offset 0x10 (Override)
    virtual void set_game_mode(int param_1, int param_2); // Ghidra: set_game_mode

    // [Slot 05] Offset 0x14 (Override)
    virtual void set_player(short param_1); // Ghidra: set_player

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void get_error_code();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void get_string();

    // [Slot 08] Offset 0x20 (Override)
    virtual char* get_string(long param_1, char* param_2, int param_3); // Ghidra: get_string

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void get_string();

    // [Slot 10] Offset 0x28 (Override)
    virtual char* get_string2(int param_1, long param_2, long param_3, char* param_4, int param_5); // Ghidra: get_string2

    // [Slot 11] Offset 0x2C (Override)
    virtual TPanel* get_view_panel(); // Ghidra: get_view_panel

    // [Slot 12] Offset 0x30 (Override)
    virtual TPanel* get_map_panel(); // Ghidra: get_map_panel

    // [Slot 13] Offset 0x34 (Override)
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario* param_1); // Ghidra: new_scenario_header

    // [Slot 14] Offset 0x38 (Override)
    virtual RGE_Scenario_Header* new_scenario_header(int param_1); // Ghidra: new_scenario_header

    // [Slot 15] Offset 0x3C (Override)
    virtual RGE_Scenario* new_scenario_info(int param_1); // Ghidra: new_scenario_info

    // [Slot 16] Offset 0x40 (Override)
    virtual void notification(int param_1, long param_2, long param_3, long param_4, long param_5); // Ghidra: notification

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void reset_comm();

    // [Slot 18] Offset 0x48 (Override)
    virtual void send_game_options(); // Ghidra: send_game_options

    // [Slot 19] Offset 0x4C (Override)
    virtual void receive_game_options(); // Ghidra: receive_game_options

    // [Slot 20] Offset 0x50 (Override)
    virtual char* gameSummary(); // Ghidra: gameSummary

    // [Slot 21] Offset 0x54 (Override)
    virtual int processCheatCode(int param_1, char* param_2); // Ghidra: processCheatCode

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void setup_music_system();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void shutdown_music_system();

    // [Slot 24] Offset 0x60 (Override)
    virtual int setup(); // Ghidra: setup

    // [Slot 25] Offset 0x64 (Override)
    virtual int setup_cmd_options(); // Ghidra: setup_cmd_options

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void setup_class();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void setup_main_window();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void setup_graphics_system();

    // [Slot 29] Offset 0x74 (Override)
    virtual int setup_palette(); // Ghidra: setup_palette

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void setup_mouse();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void setup_registry();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void setup_debugging_log();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void setup_chat();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void setup_comm();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void setup_sound_system();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void setup_fonts();

    // [Slot 37] Offset 0x94 (Override)
    virtual int setup_sounds(); // Ghidra: setup_sounds

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void setup_shapes();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void setup_blank_screen();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void setup_timings();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void stop_music_system();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void restart_music_system();

    // [Slot 45] Offset 0xB4 (Override)
    virtual RGE_Game_World* create_world(); // Ghidra: create_world

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void handle_message();

    // [Slot 47] Offset 0xBC (Override)
    virtual int handle_idle(); // Ghidra: handle_idle

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 51] Offset 0xCC WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void handle_music_done();

    // [Slot 53] Offset 0xD4 WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 54] Offset 0xD8 (Override)
    virtual int handle_activate(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: handle_activate

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void handle_init_menu();

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void handle_exit_menu();

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void handle_palette_changed();

    // [Slot 59] Offset 0xEC (Override)
    virtual int handle_query_new_palette(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: handle_query_new_palette

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void handle_close();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void handle_destroy();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void action_update();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void action_mouse_move();

    // [Slot 64] Offset 0x100 (Override)
    virtual int action_key_down(ulong param_1, int param_2, int param_3, int param_4, int param_5); // Ghidra: action_key_down

    // [Slot 65] Offset 0x104 (Override)
    virtual int action_user_command(ulong param_1, ulong param_2); // Ghidra: action_user_command

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void action_command();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void action_music_done();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void action_activate();

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void action_deactivate();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void action_init_menu();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void action_exit_menu();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void action_size();

    // [Slot 73] Offset 0x124 (Override)
    virtual int action_close(); // Ghidra: action_close

    // [Slot 74] Offset 0x128 WARNING: Function body missing in analysis
    // virtual void calc_timings();

    // [Slot 75] Offset 0x12C (Override)
    virtual void calc_timing_text(); // Ghidra: calc_timing_text

    // [Slot 76] Offset 0x130 (Override)
    virtual void show_timings(); // Ghidra: show_timings

    // [Slot 77] Offset 0x134 (Override)
    virtual void show_comm(); // Ghidra: show_comm

    // [Slot 78] Offset 0x138 (Override)
    virtual void show_ai(); // Ghidra: show_ai

    // [Slot 79] Offset 0x13C WARNING: Function body missing in analysis
    // virtual void setup_map_save_area();

    // [Slot 80] Offset 0x140 (Override)
    virtual void set_interface_messages(); // Ghidra: set_interface_messages

    // --- Non-Virtual Members ---
    void close_game_screens(int param_1);
    void set_save_game_name(char* param_1);
    void set_load_game_name(char* param_1);
    char* get_save_game_name();
    char* get_load_game_name();
    void show_error_message(int param_1);
    void show_status_message(char* param_1, char* param_2, long param_3);
    void show_status_message(int param_1, char* param_2, long param_3);
    void close_status_message();
    int start_video(int param_1, char* param_2);
    void stop_video(uchar param_1);
    int start_campaign_menu();
    int start_menu();
    void quit_game();
    void restart_game();
    int load_db_files();
    int load_game_data();
    int save_game(char* param_1);
    int save_scenario(char* param_1);
    int start_game(int param_1);
    int test_scenario(char* param_1);
    int start_scenario(char* param_1);
    int load_game(char* param_1);
    void do_game_over();
    int create_game(int param_1);
    int create_game_screen();
    void let_game_begin();
    int start_scenario_editor(char* param_1, int param_2);
    void set_tribe_options(TRIBE_Game_Options* param_1);
    void get_tribe_options(TRIBE_Game_Options* param_1);
    MapSize mapSize();
    void setMapSize(MapSize param_1);
    MapType mapType();
    void setMapType(MapType param_1);
    int animals();
    void setAnimals(int param_1);
    int predators();
    void setPredators(int param_1);
    VictoryType victoryType();
    int victoryAmount();
    void setVictoryType(VictoryType param_1, int param_2);
    int civilization(int param_1);
    void setCivilization(int param_1, int param_2);
    int scenarioPlayer(int param_1);
    void setScenarioPlayer(int param_1, int param_2);
    int playerColor(int param_1);
    void setPlayerColor(int param_1, int param_2);
    int computerName(int param_1);
    void setComputerName(int param_1, int param_2);
    int allowTrading();
    int longCombat();
    int randomizePositions();
    int fullTechTree();
    ResourceLevel resourceLevel();
    Age startingAge();
    int startingUnits();
    uchar deathMatch();
    uchar popLimit();
    uchar quickStartGame();
    int randomStartValue();
    void setAllowTrading(int param_1);
    void setLongCombat(int param_1);
    void setRandomizePositions(int param_1);
    void setFullTechTree(int param_1);
    void setResourceLevel(ResourceLevel param_1);
    void setStartingAge(Age param_1);
    void setStartingUnits(int param_1);
    void setDeathMatch(uchar param_1);
    void setPopLimit(uchar param_1);
    void setQuickStartGame(uchar param_1);
    void setRandomStartValue(int param_1);
    char* game_over_msg();
    long get_achievement_info(uchar param_1, char** param_2);
    int randomComputerName(int param_1);
    void resetRandomComputerName();
    long video_wnd_proc(void* param_1, uint param_2, uint param_3, long param_4);
    void SetClickTables(MouseClickInfo* param_1, int param_2, MouseClickInfo* param_3, int param_4);
    int setup_video_system();
    void shutdown_video_system();
    void disconnect_multiplayer_game();
    void add_notification_loc(long param_1, long param_2);
    void goto_notification_loc();
};

static_assert(sizeof(TRIBE_Game) == 0x1254, "TRIBE_Game Size Mismatch");
static_assert(offsetof(TRIBE_Game, inHandleIdle) == 0x1250, "TRIBE_Game Offset Mismatch");

