#ifndef AOE1_TRIBEGAM_H
#define AOE1_TRIBEGAM_H

// RGE_Prog_Info is a struct in the period ABI (constructor symbol PAU...).
// Declare the same tag before the canonical base-game composition.
struct RGE_Prog_Info;
#include "basegame.h"

// These are game civilization IDs, not string resource IDs or zero-based list indices.
// Fixed-value macros avoid adding declarations that can change VC5 output in unrelated functions.
#define CIVILIZATION_EGYPTIAN     1
#define CIVILIZATION_GREEK        2
#define CIVILIZATION_BABYLONIAN   3
#define CIVILIZATION_ASSYRIAN     4
#define CIVILIZATION_MINOAN       5
#define CIVILIZATION_HITTITE      6
#define CIVILIZATION_PHOENICIAN   7
#define CIVILIZATION_SUMERIAN     8
#define CIVILIZATION_PERSIAN      9
#define CIVILIZATION_SHANG        10
#define CIVILIZATION_YAMATO       11
#define CIVILIZATION_CHOSON       12
#define CIVILIZATION_ROMAN        13
#define CIVILIZATION_CARTHAGINIAN 14
#define CIVILIZATION_PALMYRAN      15
#define CIVILIZATION_MACEDONIAN   16

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

typedef char tribe_mouse_click_info_size_check[
    (sizeof(MouseClickInfo) == 44) ? 1 : -1];

class TRIBE_Screen_Game;

class TRIBE_Game : public RGE_Base_Game {
    friend class TRIBE_Screen_Game;
    friend class TRIBE_Panel_Object;

public:
    using RGE_Base_Game::get_string;

    enum MapSize {
        Tiny = 0,
        Small,
        Medium,
        Large,
        Huge,
        Humongous
    };
    enum MapType {
        AllWater = 0,
        MostlyWater = 1,
        WaterAndLand = 2,
        MostlyLand = 3,
        AllLand = 4,
        Continental = 5,
        Lake = 6,
        Hilly = 7,
        Isthmas = 8
    };
    enum VictoryType {
        VictoryDefault = 0,
        VictoryConquest = 1,
        VictoryTime = 7,
        VictoryScore = 8,
        VictoryStandard = 9
    };
    enum ResourceLevel {
        DefaultResources = 0,
        LowResources = 1,
        MediumResources = 2,
        HighResources = 3
    };
    enum Age {
        DefaultAge = 0,
        NomadAge = 1,
        StoneAge = 2,
        ToolAge = 3,
        BronzeAge = 4,
        IronAge = 5
    };

    struct TRIBE_Game_Options {
        MapSize mapSizeValue;
        MapType mapTypeValue;
        int animalsValue;
        int predatorsValue;
        VictoryType victoryTypeValue;
        int victoryAmountValue;
        unsigned char civilizationValue[9];
        int scenarioPlayerValue[9];
        unsigned char playerColorValue[9];
        unsigned char computerNameValue[9];
        unsigned char allowTradingValue;
        unsigned char longCombatValue;
        unsigned char randomizePositionsValue;
        unsigned char fullTechTreeValue;
        ResourceLevel resourceLevelValue;
        Age startingAgeValue;
        unsigned char startingUnitsValue;
        unsigned char deathMatchValue;
        unsigned char popLimitValue;
    };

    virtual ~TRIBE_Game();
    virtual long __stdcall wnd_proc(void* wnd, unsigned int msg,
                                    unsigned int wparam, long lparam);
    TRIBE_Game(RGE_Prog_Info* prog_info_in, int do_setup);
    virtual int setup_cmd_options();

    void close_game_screens(int close_main_game_screen);

protected:
    virtual int setup();

    virtual int setup_palette();
    virtual int setup_sounds();
    virtual RGE_Game_World* create_world();

public:
    virtual void set_game_mode(int new_mode, int new_sub_mode);
    virtual void set_player(short new_player_id);
    void set_save_game_name(char* file_name);
    void set_load_game_name(char* file_name);
    char* get_save_game_name();
    char* get_load_game_name();
    virtual char* get_string(long string_id, char* str, int max_len);
    virtual char* get_string2(int string_type, long id, long id2, char* str,
                              int max_len);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    long video_wnd_proc(void* hwnd, unsigned int msg,
                        unsigned int wParam, long lParam);
    virtual RGE_Scenario_Header* new_scenario_header(int infile);
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario* scenario_info);
    virtual RGE_Scenario* new_scenario_info(int infile);
    void show_error_message(int error_code_in);
    void show_status_message(char* messageIn, char* info_file, long info_id);
    void show_status_message(int string_id, char* info_file, long info_id);
    void close_status_message();
    int setup_video_system();
    int start_video(int video_num, char* video_file);
    void shutdown_video_system();
    char* game_over_msg();
    void stop_video(unsigned char goto_next_video);
    int start_campaign_menu();
    int start_menu();
    void quit_game();
    void restart_game();
    int load_db_files();
    int load_game_data();
    int save_game(char* fileName);
    int save_scenario(char* fileName);
    virtual void calc_timing_text();
    virtual void show_timings();
    virtual void show_comm();
    virtual void show_ai();
    int start_game(int skip_startup_screens);
    int test_scenario(char* scenario_file);
    int start_scenario(char* scenario_file);
    int load_game(char* fileName);
    RGE_Game_World* createGameWorld();
    void do_game_over();

protected:
    int create_game(int not_used);

public:
    int create_game_screen();
    virtual int processCheatCode(int playerID, char* text);

protected:
    void let_game_begin();

public:
    int start_scenario_editor(char* scenario_name_in, int is_multi_player_in);
    virtual void send_game_options();
    virtual void receive_game_options();
    void set_tribe_options(TRIBE_Game_Options* options);
    void get_tribe_options(TRIBE_Game_Options* options);
    MapSize mapSize() const;
    void setMapSize(MapSize v);
    MapType mapType() const;
    void setMapType(MapType v);
    int animals() const;
    int predators() const;
    void setAnimals(int v);
    void setPredators(int v);
    VictoryType victoryType() const;
    int victoryAmount() const;
    void setVictoryType(VictoryType victory_type_in, int amount_in);
    int civilization(int player_num);
    void setCivilization(int player_num, int civilization);
    int scenarioPlayer(int player_num);
    void setScenarioPlayer(int player_num, int scenario_player);
    int playerColor(int player_num);
    void setPlayerColor(int player_num, int color);
    int computerName(int player_num);
    void setComputerName(int player_num, int val);
    int allowTrading();
    int longCombat();
    void setAllowTrading(int val);
    void setLongCombat(int val);
    int randomizePositions();
    void setRandomizePositions(int val);
    int fullTechTree();
    void setFullTechTree(int val);
    ResourceLevel resourceLevel();
    void setResourceLevel(ResourceLevel val);
    Age startingAge();
    void setStartingAge(Age val);
    int startingUnits();
    void setStartingUnits(int val);
    unsigned char deathMatch();
    void setDeathMatch(unsigned char val);
    unsigned char popLimit();
    void setPopLimit(unsigned char val);
    void setQuickStartGame(unsigned char val);
    unsigned char quickStartGame();
    int randomStartValue();
    void setRandomStartValue(int val);
    void resetRandomComputerName();
    int randomComputerName(int civ);
    void SetClickTables(MouseClickInfo* RC, int RCS,
                        MouseClickInfo* LC, int LCS);
    virtual int action_close();
    virtual int action_key_down(unsigned long key, int repeat_count, int ctrl_key,
                                int alt_key, int shift_key);
    virtual void set_interface_messages();
    void disconnect_multiplayer_game();
    virtual int handle_idle();
    virtual int handle_query_new_palette(void* wnd, unsigned int msg,
                                         unsigned int wparam, long lparam);
    virtual int handle_activate(void* wnd, unsigned int msg,
                                unsigned int wparam, long lparam);
    virtual int action_user_command(unsigned long val1, unsigned long val2);
    void add_notification_loc(long x, long y);
    virtual void notification(int notify_type, long val1, long val2, long val3, long val4);
    long get_achievement_info(unsigned char achievement, char** info);
    void goto_notification_loc();
    virtual char* gameSummary();

public:
    MouseClickInfo* MouseRightClickTable;
    int MouseRightClickTableSize;
    MouseClickInfo* MouseLeftClickTable;
    int MouseLeftClickTableSize;
    long queue_is_waiting_on_pop_counter[9];
    int random_civ[9];

protected:
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
    int random_start_value;
    unsigned char computerNameUsed[18][10];
    void* handleIdleLock;
    int inHandleIdle;
};

// The communications packet contains the base options followed by the tribe
// options. This record names that wire layout without a byte-offset view.
struct TRIBE_Game_Combined_Options {
    RGE_Base_Game::RGE_Game_Options base;
    TRIBE_Game::TRIBE_Game_Options tribe;
};

typedef char tribe_game_combined_options_size_check[
    (sizeof(TRIBE_Game_Combined_Options) == 0x114) ? 1 : -1];

typedef char mouse_click_info_size_check[
    (sizeof(MouseClickInfo) == 0x2C) ? 1 : -1];
typedef char tribe_game_options_size_check[
    (sizeof(TRIBE_Game::TRIBE_Game_Options) == 0x6C) ? 1 : -1];
typedef char tribe_game_size_check[
    (sizeof(TRIBE_Game) == 0x1254) ? 1 : -1];

#endif
