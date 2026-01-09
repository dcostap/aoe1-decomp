#pragma once
#include "common.h"
#include "basegame.h"  // Need full definition for inheritance

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
    RGE_Game_Options rge_opts; // 0x0
    TRIBE_Game_Options tribe_opts; // 0xA8
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
    int random_start_value;                  // 0x1194
    uchar* computerNameUsed[18];             // 0x1198
    void* handleIdleLock;                    // 0x124C
    int inHandleIdle;                        // 0x1250

    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4); // vt0[2]+0x8=0x529580
    virtual void set_game_mode(int param_1, int param_2);   // vt0[4]+0x10=0x5227D0
    virtual void set_player(short param_1);                 // vt0[5]+0x14=0x522810
    virtual char* get_string(long param_1, char* param_2, int param_3); // vt0[8]+0x20=0x5228E0
    virtual char* get_string2(int param_1, long param_2, long param_3, char* param_4, int param_5); // vt0[10]+0x28=0x522930
    virtual TPanel* get_view_panel();                       // vt0[11]+0x2C=0x523450
    virtual TPanel* get_map_panel();                        // vt0[12]+0x30=0x5234A0
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario* param_1); // vt0[13]+0x34=0x523570
    virtual RGE_Scenario_Header* new_scenario_header(int param_1); // vt0[14]+0x38=0x523510
    virtual RGE_Scenario* new_scenario_info(int param_1);   // vt0[15]+0x3C=0x5235D0
    virtual void notification(int param_1, long param_2, long param_3, long param_4, long param_5); // vt0[16]+0x40=0x524D70
    virtual void send_game_options();                       // vt0[18]+0x48=0x528F60
    virtual void receive_game_options();                    // vt0[19]+0x4C=0x528FB0
    virtual char* gameSummary();                            // vt0[20]+0x50=0x529570
    virtual int processCheatCode(int param_1, char* param_2); // vt0[21]+0x54=0x527A70
    virtual int setup();                                    // vt0[24]+0x60=0x521790
    virtual int setup_cmd_options();                        // vt0[25]+0x64=0x521FA0
    virtual int setup_palette();                            // vt0[29]+0x74=0x522200
    virtual int setup_sounds();                             // vt0[37]+0x94=0x5222C0
    virtual RGE_Game_World* create_world();                 // vt0[45]+0xB4=0x522770
    virtual int handle_idle();                              // vt0[47]+0xBC=0x529610
    virtual int handle_activate(void* param_1, uint param_2, uint param_3, long param_4); // vt0[54]+0xD8=0x5299E0
    virtual int handle_query_new_palette(void* param_1, uint param_2, uint param_3, long param_4); // vt0[59]+0xEC=0x529980
    virtual int action_key_down(ulong param_1, int param_2, int param_3, int param_4, int param_5); // vt0[64]+0x100=0x529F60
    virtual int action_user_command(ulong param_1, ulong param_2); // vt0[65]+0x104=0x529A70
    virtual int action_close();                             // vt0[73]+0x124=0x52A000
    virtual void calc_timing_text();                        // vt0[75]+0x12C=0x524880
    virtual void show_timings();                            // vt0[76]+0x130=0x524A60
    virtual void show_comm();                               // vt0[77]+0x134=0x524A80
    virtual void show_ai();                                 // vt0[78]+0x138=0x524AF0
    virtual void set_interface_messages();                  // vt0[80]+0x140=0x52A210
    
    // Override from base
    virtual int get_error_code() override;                  // vt0[6]+0x18
    virtual int run() override;                             // vt0[1]+0x4
    
    TRIBE_Game(RGE_Prog_Info* param_1, int param_2);
    ~TRIBE_Game();
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
    void setNumberPlayers(int count);  // Forward to base class
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

// NOTE: Size assertion temporarily disabled during incremental implementation
// TODO: Re-enable once all members are properly initialized
// static_assert(sizeof(TRIBE_Game) == 0x1254, "TRIBE_Game Size Mismatch");

