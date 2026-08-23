#ifndef AOE1_TRIBEGAM_CONTEXT_H
#define AOE1_TRIBEGAM_CONTEXT_H

// Canonical tribegam.cpp context for the validated prefix owners.
// Evidence: original PDB source order, exact constructor/destructor/cleanup
// anchors, and the repaired setup_palette/setup_sounds owners. This header is
// only for the grouped module. It is not a complete game class declaration.

class RGE_Prog_Info;
class RGE_Game_Info;
class RGE_Game_World;
class RGE_Scenario;
class RGE_Scenario_Header;
class TRIBE_World;
class TCommunications_Handler;
class TribeJoinScreen;
class TPanelSystem;
class TPanel;
class TPicture;
class TScreenPanel;
class TSound_Driver;
class TMusic_System;
class TDigital;

class TDrawSystem {
public:
    void SetPalette(void* palette);
    void ClearPrimarySurface();
};

class TMusic_System {
public:
    char gap_00[0x104];
    unsigned char music_type;
    char gap_105[0x3];
    int play_track(int track, int position, unsigned long loop);
    int play_file(char* file, int position, unsigned long loop);
};

class TRegistry {
public:
    char* RegGetAscii(int value, char* name);
};

class RGE_Game_Options {
public:
    char gap_00[0x86];
    unsigned char multiplayerGameValue;
    char gap_87[0x21];
};

class TribePlayerInfo {
public:
    char gap_00[0x7C];
    short playerNum;
};

class TPanel {
public:
    char gap_00[0x4C8];
    TPanel* previousPanelValue;
};

// TPanel is kept as the proven panel lookup surface above. These layout-only
// bases provide the canonical status and mission screen ABI.
class TPanelLayout {
public:
    virtual ~TPanelLayout();
    char gap_04[0xD4];
    int error_code;
    char gap_DC[0x18];
};

class TEasy_Panel : public TPanelLayout {
public:
    virtual ~TEasy_Panel();
    char gap_F4[0x384];
};

// Inventory sizes: TScreenPanel is 0x478 and the status screen is 0x47C.
class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TRIBE_Screen_Status_Message : public TScreenPanel {
public:
    TPanel* message;
    TRIBE_Screen_Status_Message(char* panel_name, char* text,
                                char* info_file, long info_id);
    void set_text(char* text);
};

class TRIBE_Mission_Screen : public TScreenPanel {
public:
    char gap_478[0x24];
    TRIBE_Mission_Screen(char* description, unsigned char flag,
                         TPicture* picture);
};

class TribeAchievementsScreen : public TScreenPanel {
public:
    char gap_478[0x180];
    virtual ~TribeAchievementsScreen();
    TribeAchievementsScreen(char* message, int end_game);
};

class TRIBE_Screen_Game {
public:
    void game_mode_changed(int old_mode, int new_mode);
    void player_changed(int old_player, int new_player);
    char gap_00[0x4B8];
    TPanel* main_view;
    TPanel* map_view;
};

class RGE_Prog_Info {
public:
    char gap_00[0x410];
    void* instance;
    char gap_414[0x104];
    char cmd_line[0x100];
    char gap_618[0x2C8];
    long main_wid;
    long main_hgt;
    char gap_8E8[0x22A];
    char save_dir[0x105];
    char scenario_dir[0x105];
    char gap_D1C[0x414];
    char avi_dir[0x105];
    char gap_1235[0x3];
};

class TPanelSystem {
public:
    TPanel* panel(char* panel_name);
    int restorePreviousPanel(int mode);
    int destroyPanel(char* name);
    int setCurrentPanel(char* name, int mode);
};

extern TPanelSystem panel_system;

class RGE_Game_Info {
public:
    long current_person;
    long people_num;
    void* people_info;

    unsigned char set_current_person(long person);
    unsigned char set_current_campaign(long campaign);
};

class RGE_Player {
public:
    char gap_00[0x80];
    unsigned char game_status;
    char gap_81[0x3];
};

class TCommunications_Handler {
public:
    int IsLobbyLaunched();
};

// This is the shared world surface used by create_world and quit_game.
// The virtual slot at +0xB8 is proved by quit_game's del_game_info call.
class RGE_Game_World {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual ~RGE_Game_World();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void del_game_info();

    char gap_04[0x58];
    RGE_Scenario* scenario;
    char gap_60[0x44];
    int campaign;
    int person;
    char gap_AC[0x58];
};

class TRIBE_World : public RGE_Game_World {
public:
    void* tech;
    int victory_type;
    int artifact_count;
    int ruin_count;
    unsigned char countdown_victory;
    unsigned char gap_115[0x3];
    float countdown_clock;
    unsigned char score_displayed;
    unsigned char controllingComputerPlayer;
    unsigned char gap_11E[0x2];
    int sent_zone_score;

    TRIBE_World();
    void send_zone_score_info();
};

class RGE_Scenario {
public:
    char pad_0[0x198C];
    TPicture* picture;
    char* Get_description();
};

class T_Scenario : public RGE_Scenario {
public:
    char pad_0[0x514C - 0x1990];
    T_Scenario(int param_1, RGE_Game_World* zero);
};

class RGE_Scenario_Header {
public:
    virtual long get_size();
    virtual void save(int file);
    int error_code;
    long version;
    unsigned long checksum;
    char* description;

    RGE_Scenario_Header(RGE_Scenario* param_1);
    RGE_Scenario_Header(int param_1);
};

class TRIBE_Scenario_Header : public RGE_Scenario_Header {
public:
    int any_sp_victory;
    int active_player_count;

    TRIBE_Scenario_Header(int param_1);
    TRIBE_Scenario_Header(RGE_Scenario* param_1);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    RGE_Base_Game(RGE_Prog_Info* prog_info, int flags);

    // The first four slots are proved by quit_game's set_prog_mode call.
    virtual int run();
    virtual long wnd_proc(void* window, unsigned int message,
                          unsigned int wparam, long lparam);
    virtual void set_prog_mode(int mode);
    virtual void set_game_mode(int mode, int sub_mode);
    virtual void set_player(short player);
    virtual int get_error_code();
    virtual char* get_string(int id, long param, char* buffer, int length);
    virtual char* get_string(long id, char* buffer, int length);
    virtual char* get_string(long id);
    virtual char* get_string2(int id, long p2, long p3, char* buffer, int length);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario* scenario);
    virtual RGE_Scenario_Header* new_scenario_header(int scenario);
    virtual RGE_Scenario* new_scenario_info(int scenario);
    virtual void notification(int id, long p2, long p3, long p4, long p5);
    virtual int reset_comm();
    virtual void send_game_options();
    virtual void receive_game_options();
    virtual char* gameSummary();
    virtual int processCheatCode(int id, char* code);
    virtual int setup_music_system();
    virtual void shutdown_music_system();
    virtual int setup();

protected:
    virtual int setup_cmd_options();
    virtual int setup_class();
    virtual int setup_main_window();
    virtual int setup_graphics_system();
    virtual int setup_palette();

public:
    virtual int setup_mouse();
    virtual int setup_registry();
    virtual int setup_debugging_log();
    virtual int setup_chat();
    virtual int setup_comm();
    virtual int setup_sound_system();
    virtual int setup_fonts();

protected:
    virtual int setup_sounds();

public:
    virtual int setup_shapes();
    virtual int setup_blank_screen();
    virtual void setup_timings();
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void stop_music_system();
    virtual int restart_music_system();

protected:
    virtual RGE_Game_World* create_world();

    RGE_Game_Info* game_info;
    void* scenario_info;
    RGE_Prog_Info* prog_info;
    void* prog_window;
    char gap_14[0x08];
    void* prog_palette;
    char gap_20[0x20];
    int error_code;
    int is_timer;
    TDrawSystem* draw_system;
    void* draw_area;
    unsigned char outline_type;
    unsigned char gap_51[0x3];
    int custom_mouse;
    short shape_num;
    unsigned char gap_5A[0x2];
    void* shapes;
    TSound_Driver* sound_system;
    TMusic_System* music_system;
    short sound_num;
    unsigned char gap_6A[0x2];
    TDigital** sounds;
    char gap_70[0x11C];
    TCommunications_Handler* comm_handler;
    char gap_190[0x1C];
    TRegistry* registry;
    int prog_mode;
    int field_1B4;
    int field_1B8;
    char gap_1BC[0x1C];
    int is_mouse_on;
    void* windows_mouse;
    char gap_1E0[0x214];
    union {
        TRIBE_World* world;
        TribePlayerInfo* tribeInfo;
    };
    char gap_3F8[0x500];
    RGE_Game_Options rge_game_options;
    char gap_9A0[0x84];

public:
    void setNumberPlayers(int number_players);
    int singlePlayerGame();
    void close();
    void draw_window();
    void set_render_all();
    void enable_input();
    int multiplayerGame();
    int randomGame();
    int campaignGame();
    RGE_Player* get_player();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    void* MouseRightClickTable;
    int MouseRightClickTableSize;
    void* MouseLeftClickTable;
    int MouseLeftClickTableSize;
    char gap_A34[0xB4];
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
    union {
        TRIBE_Screen_Game* game_screen;
        TRIBE_Screen_Game* gameScreen;
    };
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
    unsigned char gap_1191[3];
    int random_start_value;
    unsigned char computerNameUsed[18][10];
    void* handleIdleLock;
    int inHandleIdle;

    virtual ~TRIBE_Game();
    TRIBE_Game(RGE_Prog_Info* prog_info, int setup_game);
    virtual int setup_cmd_options();

    void close_game_screens(int destroy_game_screen);
    int setup();

protected:
    virtual int setup_palette();
    virtual int setup_sounds();
    virtual RGE_Game_World* create_world();

public:
    virtual void set_game_mode(int mode, int sub_mode);
    void set_player(short player);
    void set_save_game_name(char* name);
    void set_load_game_name(char* name);
    char* get_save_game_name();
    char* get_load_game_name();
    virtual char* get_string(int id, long param, char* buffer, int length);
    virtual char* get_string(long id, char* buffer, int length);
    virtual char* get_string(long id);
    virtual char* get_string2(int id, long p2, long p3, char* buffer, int length);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    long video_wnd_proc(void* window, unsigned int message, unsigned int wparam, long lparam);
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
    long video_sub_wnd_proc(void* window, unsigned int message, unsigned int wparam, long lparam);
    void stop_video(unsigned char mode);
    int start_campaign_menu();
    int start_menu();
    void quit_game();
    void restart_game();
    int load_db_files();
    int load_game_data();
    int save_game(char* name);
    int save_scenario(char* name);
    void calc_timing_text();
    void show_timings();
    void show_comm();
    void show_ai();
    int start_game(int mode);
    int test_scenario(char* name);
    int start_scenario(char* name);
    void do_game_over();
    int create_game(int mode);
    int create_game_screen();
    int processCheatCode(char* code);
    void let_game_begin();
    int start_scenario_editor(char* scenario_filename, int mode);
    void send_game_options();
    void receive_game_options();
    void set_tribe_options(void* options);
    void get_tribe_options(void* options);
    int mapSize();
    void setMapSize(int value);
    int mapType();
    void setMapType(int value);
    int animals();
    void setAnimals(int value);
    int predators();
    void setPredators(int value);
    int victoryType();
    int victoryAmount();
    void setVictoryType(int type, int amount);
    int civilization(int player);
    void setCivilization(int player, int civilization);
    int scenarioPlayer(int player);
    void setScenarioPlayer(int player, int value);
    int playerColor(int player);
    void setPlayerColor(int player, int color);
    int computerName(int player);
    void setComputerName(int player, int value);
    int allowTrading();
    void setAllowTrading(int value);
    int longCombat();
    void setLongCombat(int value);
    int randomizePositions();
    void setRandomizePositions(int value);
    int fullTechTree();
    void setFullTechTree(int value);
    int resourceLevel();
    void setResourceLevel(int value);
    int startingAge();
    void setStartingAge(int value);
    int startingUnits();
    void setStartingUnits(int value);
    int deathMatch();
    void setDeathMatch(unsigned char value);
    int popLimit();
    void setPopLimit(unsigned char value);
    int quickStartGame();
    void setQuickStartGame(unsigned char value);
    int randomStartValue();
    void setRandomStartValue(int value);
    void resetRandomComputerName();
    int SetClickTables(void* right, int right_count, void* left, int left_count);
    int action_close(void* window, unsigned int message, unsigned int wparam, long lparam);
    void set_interface_messages();
    void disconnect_multiplayer_game();
    void add_notification_loc(long x, long y);
    void goto_notification_loc();
};

class TribeJoinScreen {
public:
    virtual ~TribeJoinScreen();
    char gap_04[0x4AC];
    TribeJoinScreen();
};

#endif
