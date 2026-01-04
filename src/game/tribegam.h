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

class TRIBE_Game : public RGE_Base_Game {
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
    uchar _pad1191[3];  
    int random_start_value;                  // 0x1194
    uchar computerNameUsed[18][10];             // 0x1198
    void* handleIdleLock;                    // 0x124C
    int inHandleIdle;                        // 0x1250

    TRIBE_Game(RGE_Prog_Info* param_1, int param_2);
    virtual ~TRIBE_Game();
    virtual void close_game_screens(int param_1);
    virtual int setup();
    virtual int setup_cmd_options();
    virtual int setup_palette();
    virtual int setup_sounds();
    virtual RGE_Game_World* create_world();
    virtual void set_game_mode(int param_1, int param_2);
    virtual void set_player(short param_1);
    virtual void set_save_game_name(char* param_1);
    virtual void set_load_game_name(char* param_1);
    virtual char* get_string(long param_1, char* param_2, int param_3);
    virtual char* get_string2(int param_1, long param_2, long param_3, char* param_4, int param_5);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    virtual char* get_save_game_name();
    virtual char* get_load_game_name();
    virtual RGE_Scenario_Header* new_scenario_header(int param_1);
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario* param_1);
    virtual RGE_Scenario* new_scenario_info(int param_1);
    virtual void show_error_message(int param_1);
    virtual void show_status_message(char* param_1, char* param_2, long param_3);
    virtual void show_status_message(int param_1, char* param_2, long param_3);
    virtual void close_status_message();
    virtual int start_video(int param_1, char* param_2);
    virtual void stop_video(uchar param_1);
    virtual int start_campaign_menu();
    virtual int start_menu();
    virtual void quit_game();
    virtual void restart_game();
    virtual int load_db_files();
    virtual int load_game_data();
    virtual int save_game(char* param_1);
    virtual int save_scenario(char* param_1);
    virtual void calc_timing_text();
    virtual void show_timings();
    virtual void show_comm();
    virtual void show_ai();
    virtual void notification(int param_1, long param_2, long param_3, long param_4, long param_5);
    virtual int start_game(int param_1);
    virtual int test_scenario(char* param_1);
    virtual int start_scenario(char* param_1);
    virtual int load_game(char* param_1);
    virtual void do_game_over();
    virtual int create_game(int param_1);
    virtual int create_game_screen();
    virtual int processCheatCode(int param_1, char* param_2);
    virtual void let_game_begin();
    virtual int start_scenario_editor(char* param_1, int param_2);
    virtual void send_game_options();
    virtual void receive_game_options();
    virtual void set_tribe_options(TRIBE_Game_Options* param_1);
    virtual void get_tribe_options(TRIBE_Game_Options* param_1);
    virtual MapSize mapSize();
    virtual void setMapSize(MapSize param_1);
    virtual MapType mapType();
    virtual void setMapType(MapType param_1);
    virtual int animals();
    virtual void setAnimals(int param_1);
    virtual int predators();
    virtual void setPredators(int param_1);
    virtual VictoryType victoryType();
    virtual int victoryAmount();
    virtual void setVictoryType(VictoryType param_1, int param_2);
    virtual int civilization(int param_1);
    virtual void setCivilization(int param_1, int param_2);
    virtual int scenarioPlayer(int param_1);
    virtual void setScenarioPlayer(int param_1, int param_2);
    virtual int playerColor(int param_1);
    virtual void setPlayerColor(int param_1, int param_2);
    virtual int computerName(int param_1);
    virtual void setComputerName(int param_1, int param_2);
    virtual int allowTrading();
    virtual int longCombat();
    virtual int randomizePositions();
    virtual int fullTechTree();
    virtual ResourceLevel resourceLevel();
    virtual Age startingAge();
    virtual int startingUnits();
    virtual uchar deathMatch();
    virtual uchar popLimit();
    virtual uchar quickStartGame();
    virtual int randomStartValue();
    virtual void setAllowTrading(int param_1);
    virtual void setLongCombat(int param_1);
    virtual void setRandomizePositions(int param_1);
    virtual void setFullTechTree(int param_1);
    virtual void setResourceLevel(ResourceLevel param_1);
    virtual void setStartingAge(Age param_1);
    virtual void setStartingUnits(int param_1);
    virtual void setDeathMatch(uchar param_1);
    virtual void setPopLimit(uchar param_1);
    virtual void setQuickStartGame(uchar param_1);
    virtual void setRandomStartValue(int param_1);
    virtual char* gameSummary();
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4);
    virtual int handle_idle();
    virtual int handle_query_new_palette(void* param_1, uint param_2, uint param_3, long param_4);
    virtual int handle_activate(void* param_1, uint param_2, uint param_3, long param_4);
    virtual int action_user_command(ulong param_1, ulong param_2);
    virtual int action_key_down(ulong param_1, int param_2, int param_3, int param_4, int param_5);
    virtual int action_close();
    virtual char* game_over_msg();
    virtual long get_achievement_info(uchar param_1, char** param_2);
    virtual int randomComputerName(int param_1);
    virtual void resetRandomComputerName();
    virtual long video_wnd_proc(void* param_1, uint param_2, uint param_3, long param_4);
    virtual void SetClickTables(MouseClickInfo* param_1, int param_2, MouseClickInfo* param_3, int param_4);
    virtual void set_interface_messages();
    virtual int setup_video_system();
    virtual void shutdown_video_system();
    virtual void disconnect_multiplayer_game();
    virtual void add_notification_loc(long param_1, long param_2);
    virtual void goto_notification_loc();
};

static_assert(sizeof(TRIBE_Game) == 0x1254, "TRIBE_Game Size Mismatch");
static_assert(offsetof(TRIBE_Game, inHandleIdle) == 0x1250, "TRIBE_Game Offset Mismatch");

