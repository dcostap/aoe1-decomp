#ifndef AOE1_TRIBEGAM_H
#define AOE1_TRIBEGAM_H

// The constructor PDB symbol spells RGE_Prog_Info as a struct (PAU...).
// Keep this declaration before the canonical base-game header.
struct RGE_Prog_Info;
#include "basegame.h"

struct MouseClickInfo {
    int object_group;
    int self_action;
    int self_text_id;
    int gaia_action;
    int gaia_text_id;
    int ally_action;
    int ally_text_id;
    int neutral_action;
    int neutral_text_id;
    int enemy_action;
    int enemy_text_id;
};

class TRIBE_Screen_Game;

class TRIBE_Game : public RGE_Base_Game {
public:
    enum MapSize {
        Tiny = 0,
        Small,
        Medium,
        Large,
        Huge,
        Humongous
    };
    enum MapType {
        MapType_Unknown = 0
    };
    enum VictoryType {
        VictoryType_Unknown = 0
    };
    enum ResourceLevel {
        ResourceLevel_Unknown = 0
    };
    enum Age {
        Age_Unknown = 0
    };

    struct TRIBE_Game_Options {
        MapSize mapSizeValue;
        MapType mapTypeValue;
        int animalsValue;
        int predatorsValue;
        VictoryType victoryTypeValue;
        int victoryAmountValue;
        unsigned char civilizationValue[9];
        unsigned char _pad_0[3];
        int scenarioPlayerValue[9];
        unsigned char playerColorValue[9];
        unsigned char computerNameValue[9];
        unsigned char allowTradingValue;
        unsigned char longCombatValue;
        unsigned char randomizePositionsValue;
        unsigned char fullTechTreeValue;
        unsigned char _pad_1[2];
        ResourceLevel resourceLevelValue;
        Age startingAgeValue;
        unsigned char startingUnitsValue;
        unsigned char deathMatchValue;
        unsigned char popLimitValue;
        unsigned char _pad_end[1];
    };

    virtual ~TRIBE_Game();
    virtual long __stdcall wnd_proc(void* window, unsigned int message,
                                    unsigned int wparam, long lparam);
    TRIBE_Game(RGE_Prog_Info* prog_info, int setup_game);
    virtual int setup_cmd_options();

    void close_game_screens(int destroy_game_screen);

protected:
    virtual int setup();

    virtual int setup_palette();
    virtual int setup_sounds();
    virtual RGE_Game_World* create_world();

public:
    virtual void set_game_mode(int mode, int sub_mode);
    virtual void set_player(short player);
    void set_save_game_name(char* name);
    void set_load_game_name(char* name);
    char* get_save_game_name();
    char* get_load_game_name();
    virtual char* get_string(long id, char* buffer, int length);
    virtual char* get_string2(int id, long p2, long p3, char* buffer,
                              int length);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    long video_wnd_proc(void* window, unsigned int message,
                        unsigned int wparam, long lparam);
    virtual RGE_Scenario_Header* new_scenario_header(int scenario);
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario* scenario);
    virtual RGE_Scenario* new_scenario_info(int scenario);
    void show_error_message(int id);
    void show_status_message(char* text, char* format, long value);
    void show_status_message(int id, char* format, long value);
    void close_status_message();
    int setup_video_system();
    int start_video(int mode, char* file);
    void shutdown_video_system();
    char* game_over_msg();
    long video_sub_wnd_proc(void* window, unsigned int message,
                            unsigned int wparam, long lparam);
    void stop_video(unsigned char mode);
    int start_campaign_menu();
    int start_menu();
    void quit_game();
    void restart_game();
    int load_db_files();
    int load_game_data();
    int save_game(char* name);
    int save_scenario(char* name);
    virtual void calc_timing_text();
    virtual void show_timings();
    virtual void show_comm();
    virtual void show_ai();
    int start_game(int mode);
    int test_scenario(char* name);
    int start_scenario(char* name);
    int load_game(char* name);
    RGE_Game_World* createGameWorld();
    void do_game_over();

protected:
    int create_game(int mode);

public:
    int create_game_screen();
    int processCheatCode(char* code);

protected:
    void let_game_begin();

public:
    int start_scenario_editor(char* scenario_filename, int mode);
    virtual void send_game_options();
    virtual void receive_game_options();
    void set_tribe_options(TRIBE_Game_Options* options);
    void get_tribe_options(TRIBE_Game_Options* options);
    MapSize mapSize() const;
    void setMapSize(MapSize value);
    MapType mapType() const;
    void setMapType(MapType value);
    int animals() const;
    int predators() const;
    void setAnimals(int value);
    void setPredators(int value);
    VictoryType victoryType() const;
    int victoryAmount() const;
    void setVictoryType(VictoryType type, int amount);
    int civilization(int player);
    void setCivilization(int player, int civilization);
    int scenarioPlayer(int player);
    void setScenarioPlayer(int player, int value);
    int playerColor(int player);
    void setPlayerColor(int player, int color);
    int computerName(int player);
    void setComputerName(int player, int value);
    int allowTrading();
    int longCombat();
    void setAllowTrading(int value);
    void setLongCombat(int value);
    int randomizePositions();
    void setRandomizePositions(int value);
    int fullTechTree();
    void setFullTechTree(int value);
    ResourceLevel resourceLevel();
    void setResourceLevel(ResourceLevel value);
    Age startingAge();
    void setStartingAge(Age value);
    int startingUnits();
    void setStartingUnits(int value);
    unsigned char deathMatch();
    void setDeathMatch(unsigned char value);
    unsigned char popLimit();
    void setPopLimit(unsigned char value);
    void setQuickStartGame(unsigned char value);
    unsigned char quickStartGame();
    int randomStartValue();
    void setRandomStartValue(int value);
    void resetRandomComputerName();
    void SetClickTables(MouseClickInfo* right, int right_count,
                        MouseClickInfo* left, int left_count);
    virtual int action_close();
    virtual int action_key_down(unsigned long key, int param_2, int param_3,
                                int param_4, int param_5);
    virtual void set_interface_messages();
    void disconnect_multiplayer_game();
    virtual int handle_idle();
    virtual int handle_query_new_palette(void* window, unsigned int message,
                                         unsigned int wparam, long lparam);
    virtual int handle_activate(void* window, unsigned int message,
                                unsigned int wparam, long lparam);
    virtual int action_user_command(unsigned long param_1,
                                    unsigned long param_2);
    void add_notification_loc(long x, long y);
    virtual void notification(int type, long a, long b, long c, long d);
    long get_achievement_info(unsigned char param_1, char** param_2);
    void goto_notification_loc();
    virtual char* gameSummary();

    MouseClickInfo* MouseRightClickTable;
    int MouseRightClickTableSize;
    MouseClickInfo* MouseLeftClickTable;
    int MouseLeftClickTableSize;
    long queue_is_waiting_on_pop_counter[9];
    int random_civ[9];
    TRIBE_Game_Options tribe_game_options;
    char testing_scenario[260];
    void* video_window;
    int cur_video;
    int (__stdcall *old_video_wnd_proc)();
    int video_paused;
    unsigned long last_video_time;
    int video_setup;
    int video_double_size;
    int video_changed_res;
    int video_hi_color;
    long video_save_res_wid;
    long video_save_res_hgt;
    void* video_save_palette;
    int started_menu_music;
    int show_object_id;
    TRIBE_Screen_Game* game_screen;
    long notification_loc_x[5];
    long notification_loc_y[5];
    long current_notification_loc;
    long current_notification_recalled;
    char startup_scenario[260];
    char startup_game[260];
    unsigned long auto_exit_time;
    char save_game_name[260];
    char load_game_name[260];
    char timing_text2[256];
    int save_humanity[9];
    unsigned char quick_start_game;
    unsigned char _pad_2[3];
    int random_start_value;
    unsigned char computerNameUsed[18][10];
    void* handleIdleLock;
    int inHandleIdle;
};

typedef char mouse_click_info_size_check[
    (sizeof(MouseClickInfo) == 0x2C) ? 1 : -1];
typedef char tribe_game_options_size_check[
    (sizeof(TRIBE_Game::TRIBE_Game_Options) == 0x6C) ? 1 : -1];
typedef char tribe_game_size_check[
    (sizeof(TRIBE_Game) == 0x1254) ? 1 : -1];

#endif
