#pragma once
#include "common.h"

// ----------------------------------------------------------------
// RGE_Game_Options
// Size: 0xA8
struct RGE_Game_Options {
    float versionValue; // 0x0
    uchar scenarioGameValue; // 0x4
    char scenarioNameValue[128]; // 0x5
    uchar singlePlayerGameValue; // 0x85
    uchar multiplayerGameValue; // 0x86
    uchar mapXSizeValue; // 0x87
    uchar mapYSizeValue; // 0x88
    uchar mapZSizeValue; // 0x89
    uchar allowCheatCodesValue; // 0x8A
    uchar mpPathFindingValue; // 0x8B
    uchar cheatNotificationValue; // 0x8C
    uchar fullVisibilityValue; // 0x8D
    uchar fogOfWarValue; // 0x8E
    uchar coloredChatValue; // 0x8F
    uchar numberPlayersValue; // 0x90
    uchar gameDeveloperModeValue; // 0x91
    uchar playerCDAndVersionValue[9]; // 0x92
    uchar difficultyValue; // 0x9B
    uchar playerTeamValue[9]; // 0x9C
};

class RGE_Base_Game {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
    RGE_Game_Info* player_game_info;         // 0x4
    RGE_Scenario_File_Info* scenario_info;   // 0x8
    RGE_Prog_Info* prog_info;                // 0xC
    void* prog_window;                       // 0x10
    int prog_ready;                          // 0x14
    int prog_active;                         // 0x18
    void* prog_palette;                      // 0x1C
    void* prog_mutex;                        // 0x20
    long window_style;                       // 0x24
    int random_game_seed;                    // 0x28
    int random_map_seed;                     // 0x2C
    int save_random_game_seed;               // 0x30
    int save_random_map_seed;                // 0x34
    int screen_saver_enabled;                // 0x38
    int low_power_enabled;                   // 0x3C
    int error_code;                          // 0x40
    int is_timer;                            // 0x44
    TDrawSystem* draw_system;                // 0x48
    TDrawArea* draw_area;                    // 0x4C
    uchar outline_type;                      // 0x50
    int custom_mouse;                        // 0x54
    short shape_num;                         // 0x58
    TShape** shapes;                         // 0x5C
    TSound_Driver* sound_system;             // 0x60
    TMusic_System* music_system;             // 0x64
    short sound_num;                         // 0x68
    TDigital** sounds;                       // 0x6C
    uchar save_music_type;                   // 0x70
    int save_music_track_from;               // 0x74
    int save_music_track_to;                 // 0x78
    int save_music_cur_track;                // 0x7C
    char save_music_file[260];               // 0x80
    int save_music_loop;                     // 0x184
    ulong save_music_pos;                    // 0x188
    TCommunications_Handler* comm_handler;   // 0x18C
    int comm_syncstop;                       // 0x190
    int comm_droppackets;                    // 0x194
    int comm_syncmsg;                        // 0x198
    int comm_stepmode;                       // 0x19C
    int comm_speed;                          // 0x1A0
    TDebuggingLog* debugLog;                 // 0x1A4
    int log_comm;                            // 0x1A8
    TRegistry* registry;                     // 0x1AC
    int prog_mode;                           // 0x1B0
    int game_mode;                           // 0x1B4
    int sub_game_mode;                       // 0x1B8
    int paused;                              // 0x1BC
    TMousePointer* mouse_pointer;            // 0x1C0
    int erase_mouse;                         // 0x1C4
    int mouse_blit_sync;                     // 0x1C8
    int is_mouse_on;                         // 0x1CC
    int windows_mouse;                       // 0x1D0
    void* mouse_cursor;                      // 0x1D4
    int input_enabled;                       // 0x1D8
    void* input_disabled_window;             // 0x1DC
    short font_num;                          // 0x1E0
    RGE_Font* fonts;                         // 0x1E4
    char work_dir[261];                      // 0x1E8
    char string_dll_name[261];               // 0x2ED
    RGE_Game_World* world;                   // 0x3F4
    int render_all;                          // 0x3F8
    short master_obj_id;                     // 0x3FC
    short terrain_id;                        // 0x3FE
    short elevation_height;                  // 0x400
    short brush_size;                        // 0x402
    char timing_text[256];                   // 0x404
    ulong frame_count;                       // 0x504
    ulong world_update_count;                // 0x508
    ulong view_update_count;                 // 0x50C
    ulong last_frame_count;                  // 0x510
    ulong last_world_update_count;           // 0x514
    ulong last_view_update_count;            // 0x518
    ulong fps;                               // 0x51C
    ulong world_update_fps;                  // 0x520
    ulong view_update_fps;                   // 0x524
    RGE_Timing_Info timings[30];             // 0x528
    int do_show_timings;                     // 0x8E8
    int do_show_comm;                        // 0x8EC
    int do_show_ai;                          // 0x8F0
    ulong last_view_time;                    // 0x8F4
    RGE_Game_Options rge_game_options;       // 0x8F8
    int campaignGameValue;                   // 0x9A0
    int savedGameValue;                      // 0x9A4
    int quick_build;                         // 0x9A8
    int save_check_for_cd;                   // 0x9AC
    int playerIDValue[9];                    // 0x9B0
    int display_selected_ids;                // 0x9D4
    long countdown_timer[9];                 // 0x9D8
    int auto_paused;                         // 0x9FC
    int save_paused;                         // 0xA00
    int non_user_pause;                      // 0xA04
    int rollover;                            // 0xA08
    float game_speed;                        // 0xA0C
    int single_player_difficulty;            // 0xA10
    uchar pathFindingValue;                  // 0xA14
    uchar resigned[9];                       // 0xA15
    TDrawArea* map_save_area;                // 0xA20

    virtual int run();                                      // vt0[1]+0x4=0x41CFD0
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4); // vt0[2]+0x8=0x4206D0
    virtual void set_prog_mode(int param_1);                // vt0[3]+0xC=0x41C240
    virtual void set_game_mode(int param_1, int param_2);   // vt0[4]+0x10=0x420130
    virtual void set_player(short param_1);                 // vt0[5]+0x14=0x420150
    virtual int get_error_code();                           // vt0[6]+0x18=0x41C990
    virtual char* get_string(int param_1, long param_2, char* param_3, int param_4); // vt0[7]+0x1C=0x41C9F0
    virtual char* get_string(long param_1, char* param_2, int param_3); // vt0[8]+0x20=0x41C9C0
    virtual char* get_string(long param_1);                 // vt0[9]+0x24=0x41C9A0
    virtual char* get_string2(int param_1, long param_2, long param_3, char* param_4, int param_5); // vt0[10]+0x28=0x41CA10
    virtual TPanel* get_view_panel();                       // vt0[11]+0x2C=0x41C250
    virtual TPanel* get_map_panel();                        // vt0[12]+0x30=0x41C260
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario* param_1); // vt0[13]+0x34=0x41CE60
    virtual RGE_Scenario_Header* new_scenario_header(int param_1); // vt0[14]+0x38=0x41CE00
    virtual RGE_Scenario* new_scenario_info(int param_1);   // vt0[15]+0x3C=0x41CEC0
    virtual void notification(int param_1, long param_2, long param_3, long param_4, long param_5); // vt0[16]+0x40=0x41C6E0
    virtual int reset_comm();                               // vt0[17]+0x44=0x41EFF0
    virtual void send_game_options();                       // vt0[18]+0x48=0x4220D0
    virtual void receive_game_options();                    // vt0[19]+0x4C=0x4220F0
    virtual char* gameSummary();                            // vt0[20]+0x50=0x422690
    virtual int processCheatCode(int param_1, char* param_2); // vt0[21]+0x54=0x41C6F0
    virtual int setup_music_system();                       // vt0[22]+0x58=0x41F110
    virtual void shutdown_music_system();                   // vt0[23]+0x5C=0x41FA90
    virtual int setup();                                    // vt0[24]+0x60=0x41BAA0
    virtual int setup_cmd_options();                        // vt0[25]+0x64=0x41D0A0
    virtual int setup_class();                              // vt0[26]+0x68=0x41E700
    virtual int setup_main_window();                        // vt0[27]+0x6C=0x41E7D0
    virtual int setup_graphics_system();                    // vt0[28]+0x70=0x41E920
    virtual int setup_palette();                            // vt0[29]+0x74=0x41EBC0
    virtual int setup_mouse();                              // vt0[30]+0x78=0x41EBF0
    virtual int setup_registry();                           // vt0[31]+0x7C=0x41ED70
    virtual int setup_debugging_log();                      // vt0[32]+0x80=0x41EDE0
    virtual int setup_chat();                               // vt0[33]+0x84=0x41ED00
    virtual int setup_comm();                               // vt0[34]+0x88=0x41EE90
    virtual int setup_sound_system();                       // vt0[35]+0x8C=0x41F030
    virtual int setup_fonts();                              // vt0[36]+0x90=0x41F560
    virtual int setup_sounds();                             // vt0[37]+0x94=0x41F400
    virtual int setup_shapes();                             // vt0[38]+0x98=0x41F2D0
    virtual int setup_blank_screen();                       // vt0[39]+0x9C=0x41F730
    virtual void setup_timings();                           // vt0[40]+0xA0=0x41F800
    virtual void stop_sound_system();                       // vt0[41]+0xA4=0x41F830
    virtual int restart_sound_system();                     // vt0[42]+0xA8=0x41F920
    virtual void stop_music_system();                       // vt0[43]+0xAC=0x41F9B0
    virtual int restart_music_system();                     // vt0[44]+0xB0=0x41F9F0
    virtual RGE_Game_World* create_world();                 // vt0[45]+0xB4=0x420050
    virtual int handle_message(tagMSG* param_1);            // vt0[46]+0xB8=0x41C700
    virtual int handle_idle();                              // vt0[47]+0xBC=0x420F60
    virtual int handle_mouse_move(void* param_1, uint param_2, uint param_3, long param_4); // vt0[48]+0xC0=0x421110
    virtual int handle_key_down(void* param_1, uint param_2, uint param_3, long param_4); // vt0[49]+0xC4=0x4211D0
    virtual int handle_user_command(void* param_1, uint param_2, uint param_3, long param_4); // vt0[50]+0xC8=0x4212E0
    virtual int handle_command(void* param_1, uint param_2, uint param_3, long param_4); // vt0[51]+0xCC=0x4213A0
    virtual int handle_music_done(void* param_1, uint param_2, uint param_3, long param_4); // vt0[52]+0xD0=0x4213C0
    virtual int handle_paint(void* param_1, uint param_2, uint param_3, long param_4); // vt0[53]+0xD4=0x4213E0
    virtual int handle_activate(void* param_1, uint param_2, uint param_3, long param_4); // vt0[54]+0xD8=0x421830
    virtual int handle_init_menu(void* param_1, uint param_2, uint param_3, long param_4); // vt0[55]+0xDC=0x421910
    virtual int handle_exit_menu(void* param_1, uint param_2, uint param_3, long param_4); // vt0[56]+0xE0=0x421930
    virtual int handle_size(void* param_1, uint param_2, uint param_3, long param_4); // vt0[57]+0xE4=0x421950
    virtual int handle_palette_changed(void* param_1, uint param_2, uint param_3, long param_4); // vt0[58]+0xE8=0x4219F0
    virtual int handle_query_new_palette(void* param_1, uint param_2, uint param_3, long param_4); // vt0[59]+0xEC=0x421A80
    virtual int handle_close(void* param_1, uint param_2, uint param_3, long param_4); // vt0[60]+0xF0=0x421B70
    virtual int handle_destroy(void* param_1, uint param_2, uint param_3, long param_4); // vt0[61]+0xF4=0x421BB0
    virtual int action_update();                            // vt0[62]+0xF8=0x41C710
    virtual int action_mouse_move(long param_1, long param_2, int param_3, int param_4, int param_5, int param_6); // vt0[63]+0xFC=0x41C720
    virtual int action_key_down(ulong param_1, int param_2, int param_3, int param_4, int param_5); // vt0[64]+0x100=0x41C730
    virtual int action_user_command(ulong param_1, ulong param_2); // vt0[65]+0x104=0x41C740
    virtual int action_command(ulong param_1, ulong param_2); // vt0[66]+0x108=0x41C750
    virtual int action_music_done();                        // vt0[67]+0x10C=0x41C760
    virtual int action_activate();                          // vt0[68]+0x110=0x41C770
    virtual int action_deactivate();                        // vt0[69]+0x114=0x41C780
    virtual int action_init_menu();                         // vt0[70]+0x118=0x41C790
    virtual int action_exit_menu();                         // vt0[71]+0x11C=0x41C7A0
    virtual int action_size();                              // vt0[72]+0x120=0x41C7B0
    virtual int action_close();                             // vt0[73]+0x124=0x41C7C0
    virtual void calc_timings();                            // vt0[74]+0x128=0x421BF0
    virtual void calc_timing_text();                        // vt0[75]+0x12C=0x421FA0
    virtual void show_timings();                            // vt0[76]+0x130=0x422030
    virtual void show_comm();                               // vt0[77]+0x134=0x422050
    virtual void show_ai();                                 // vt0[78]+0x138=0x422090
    virtual int setup_map_save_area();                      // vt0[79]+0x13C=0x422EF0
    virtual void set_interface_messages();                  // vt0[80]+0x140=0x422FE0
    RGE_Base_Game(RGE_Prog_Info* param_1, int param_2);
    ~RGE_Base_Game();
    void reset_timings();
    void add_to_timing(int param_1, ulong param_2);
    void increment_world_update_count();
    void increment_view_update_count();
    void set_last_single_time(int param_1, ulong param_2);
    ulong get_last_time(int param_1);
    ulong get_last_single_time(int param_1);
    ulong get_accum_time(int param_1);
    ulong get_max_time(int param_1);
    ulong get_last_max_time(int param_1);
    ulong get_last_world_update_count();
    ulong get_last_view_update_count();
    ulong get_world_update_count();
    ulong get_view_update_count();
    RGE_Scenario* get_scenario_info(char* param_1, int param_2);
    RGE_Scenario_Header* get_scenario_header(char* param_1, int param_2);
    void write_scenario_header(int param_1);
    void get_campaign_info(long* param_1, long* param_2, long* param_3);
    uchar set_campaign_info(long param_1, long param_2, long param_3);
    void set_campaign_win();
    void* make_font(void* param_1, long param_2, int param_3);
    void* make_font(void* param_1, char* param_2, int param_3, int param_4, int param_5);
    int check_for_cd(int param_1);
    int check_expiration();
    int check_multi_copies();
    int check_paint();
    void clear_window();
    void close();
    int create_dialog(TPanel** param_1, TPanel* param_2);
    void delete_dialog(TPanel** param_1);
    int get_paused();
    RGE_Font* get_font(int param_1);
    TShape* get_shape(int param_1);
    TDigital* get_sound(int param_1);
    void request_pause();
    void set_paused(int param_1, int param_2);
    void get_mouse_info(uint param_1, long param_2, tagPOINT* param_3, int* param_4, int* param_5, int* param_6, int* param_7);
    void get_mouse_pos(tagPOINT* param_1);
    RGE_Player* get_player();
    void draw_window();
    void mouse_on();
    void mouse_off();
    void set_windows_mouse(int param_1);
    void set_mouse_cursor(void* param_1);
    void set_mouse_facet(long param_1);
    void set_game_options(RGE_Game_Options* param_1);
    void get_game_options(RGE_Game_Options* param_1);
    float version();
    int scenarioGame();
    int randomGame();
    int campaignGame();
    int savedGame();
    char* scenarioName();
    int singlePlayerGame();
    int multiplayerGame();
    int mapXSize();
    int mapYSize();
    int mapZSize();
    int allowCheatCodes();
    int cheatNotification();
    int fullVisibility();
    int fogOfWar();
    int coloredChat();
    int gameDeveloperMode();
    int playerHasCD(int param_1);
    uchar playerVersion(int param_1);
    char* playerVersionString(int param_1);
    uchar playerCDAndVersion(int param_1);
    int difficulty();
    int numberPlayers();
    int playerTeam(int param_1);
    uchar pathFinding();
    uchar mpPathFinding();
    void find_campaigns();
    void setScenarioGame(int param_1);
    void setVersion(float param_1);
    void setScenarioName(char* param_1);
    void setCampaignGame(int param_1);
    void setSavedGame(int param_1);
    void setSinglePlayerGame(int param_1);
    void setMultiplayerGame(int param_1);
    void setMapSize(int param_1, int param_2, int param_3);
    void setAllowCheatCodes(int param_1);
    void setCheatNotification(int param_1);
    void setFullVisibility(int param_1);
    void setFogOfWar(int param_1);
    void setColoredChat(int param_1);
    void setNumberPlayers(int param_1);
    void setGameDeveloperMode(int param_1);
    void setPlayerHasCD(int param_1, int param_2);
    void setPlayerVersion(int param_1, uchar param_2);
    void setPlayerCDAndVersion(int param_1, uchar param_2);
    void setDifficulty(int param_1);
    void setPlayerTeam(int param_1, int param_2);
    void setPathFinding(uchar param_1);
    void setMpPathFinding(uchar param_1);
    void set_map_visible(uchar param_1);
    void set_map_fog(uchar param_1);
    void turn_world_sound_off();
    int campaign_open_scenario();
    long GetChecksum(long param_1);
    uchar GetWorldChecksums(long* param_1, long* param_2, long* param_3);
    long GetWorldChecksum();
    void disable_input();
    void enable_input();
    void set_screen_size(long param_1, long param_2);
    uchar check_prog_argument(char* param_1);
    long get_scenario_checksum(char* param_1);
    uchar check_scenario_checksum(char* param_1, long param_2);
    void dump_memory_usage(char* param_1);
    int playerID(int param_1);
    void setPlayerID(int param_1, int param_2);
    void reset_countdown_timer(long param_1);
    void set_countdown_timer(long param_1, long param_2);
    void get_countdown_timer(long param_1, long* param_2);
    int play_video(char* param_1);
    void close_video();
    void handle_video_notify();
    int play_sound(int param_1);
    float get_game_speed();
    void set_game_speed(float param_1);
    int get_single_player_difficulty();
    void set_single_player_difficulty(int param_1);
    void reload_scenarios_info();
    void set_render_all();
};

static_assert(sizeof(RGE_Base_Game) == 0xA24, "RGE_Base_Game Size Mismatch");

