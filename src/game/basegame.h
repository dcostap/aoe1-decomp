#pragma once
#include "../common.h"
#include "gameinfo.h"
#include "file_stf.h"
#include "registry.h"
#include "getdxver.h"
#include "sceninfo.h"

class TDrawSystem;
class TPanel;
class RGE_Scenario_File_Info;
class TSound_Driver;
class TMusic_System;
class TDigital;
class TCommunications_Handler;
class TDebuggingLog;
class TRegistry;
class TMousePointer;
class RGE_Scenario;

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

    RGE_Base_Game(RGE_Prog_Info* param_1, int param_2);
    virtual int setup();
    virtual void set_prog_mode(int param_1);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    virtual ~RGE_Base_Game();
    virtual void notification(int param_1, long param_2, long param_3, long param_4, long param_5);
    virtual int processCheatCode(int param_1, char* param_2);
    virtual int handle_message(tagMSG* param_1);
    virtual int action_update();
    virtual int action_mouse_move(long param_1, long param_2, int param_3, int param_4, int param_5, int param_6);
    virtual int action_key_down(ulong param_1, int param_2, int param_3, int param_4, int param_5);
    virtual int action_user_command(ulong param_1, ulong param_2);
    virtual int action_command(ulong param_1, ulong param_2);
    virtual int action_music_done();
    virtual int action_activate();
    virtual int action_deactivate();
    virtual int action_init_menu();
    virtual int action_exit_menu();
    virtual int action_size();
    virtual int action_close();
    virtual void reset_timings();
    virtual void add_to_timing(int param_1, ulong param_2);
    virtual void increment_world_update_count();
    virtual void increment_view_update_count();
    virtual void set_last_single_time(int param_1, ulong param_2);
    virtual ulong get_last_time(int param_1);
    virtual ulong get_last_single_time(int param_1);
    virtual ulong get_accum_time(int param_1);
    virtual ulong get_max_time(int param_1);
    virtual ulong get_last_max_time(int param_1);
    virtual ulong get_last_world_update_count();
    virtual ulong get_last_view_update_count();
    virtual ulong get_world_update_count();
    virtual ulong get_view_update_count();
    virtual int get_error_code();
    virtual char* get_string(long param_1);
    virtual char* get_string(long param_1, char* param_2, int param_3);
    virtual char* get_string(int param_1, long param_2, char* param_3, int param_4);
    virtual char* get_string2(int param_1, long param_2, long param_3, char* param_4, int param_5);
    virtual RGE_Scenario* get_scenario_info(char* param_1, int param_2);
    virtual RGE_Scenario_Header* get_scenario_header(char* param_1, int param_2);
    virtual void write_scenario_header(int param_1);
    virtual RGE_Scenario_Header* new_scenario_header(int param_1);
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario* param_1);
    virtual RGE_Scenario* new_scenario_info(int param_1);
    virtual void get_campaign_info(long* param_1, long* param_2, long* param_3);
    virtual uchar set_campaign_info(long param_1, long param_2, long param_3);
    virtual void set_campaign_win();
    virtual int run();
    virtual int setup_cmd_options();
    virtual int setup_class();
    virtual int setup_main_window();
    virtual int setup_graphics_system();
    virtual int setup_palette();
    virtual int setup_mouse();
    virtual int setup_chat();
    virtual int setup_registry();
    virtual int setup_debugging_log();
    virtual int setup_comm();
    virtual int reset_comm();
    virtual int setup_sound_system();
    virtual int setup_music_system();
    virtual int setup_shapes();
    virtual int setup_sounds();
    virtual int setup_fonts();
    virtual int setup_blank_screen();
    virtual void setup_timings();
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void stop_music_system();
    virtual int restart_music_system();
    virtual void shutdown_music_system();
    virtual void* make_font(void* param_1, long param_2, int param_3);
    virtual void* make_font(void* param_1, char* param_2, int param_3, int param_4, int param_5);
    virtual int check_for_cd(int param_1);
    virtual int check_expiration();
    virtual int check_multi_copies();
    virtual int check_paint();
    virtual void clear_window();
    virtual RGE_Game_World* create_world();
    virtual void close();
    virtual int create_dialog(TPanel** param_1, TPanel* param_2);
    virtual void delete_dialog(TPanel** param_1);
    virtual void set_game_mode(int param_1, int param_2);
    virtual void set_player(short param_1);
    virtual int get_paused();
    virtual RGE_Font* get_font(int param_1);
    virtual TShape* get_shape(int param_1);
    virtual TDigital* get_sound(int param_1);
    virtual void request_pause();
    virtual void set_paused(int param_1, int param_2);
    virtual void get_mouse_info(uint param_1, long param_2, tagPOINT* param_3, int* param_4, int* param_5, int* param_6, int* param_7);
    virtual void get_mouse_pos(tagPOINT* param_1);
    virtual RGE_Player* get_player();
    virtual void draw_window();
    virtual void mouse_on();
    virtual void mouse_off();
    virtual void set_windows_mouse(int param_1);
    virtual void set_mouse_cursor(void* param_1);
    virtual void set_mouse_facet(long param_1);
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4);
    virtual int handle_idle();
    virtual int handle_mouse_move(void* param_1, uint param_2, uint param_3, long param_4);
    virtual int handle_key_down(void* param_1, uint param_2, uint param_3, long param_4);
    virtual int handle_user_command(void* param_1, uint param_2, uint param_3, long param_4);
    virtual int handle_command(void* param_1, uint param_2, uint param_3, long param_4);
    virtual int handle_music_done(void* param_1, uint param_2, uint param_3, long param_4);
    virtual int handle_paint(void* param_1, uint param_2, uint param_3, long param_4);
    virtual int handle_activate(void* param_1, uint param_2, uint param_3, long param_4);
    virtual int handle_init_menu(void* param_1, uint param_2, uint param_3, long param_4);
    virtual int handle_exit_menu(void* param_1, uint param_2, uint param_3, long param_4);
    virtual int handle_size(void* param_1, uint param_2, uint param_3, long param_4);
    virtual int handle_palette_changed(void* param_1, uint param_2, uint param_3, long param_4);
    virtual int handle_query_new_palette(void* param_1, uint param_2, uint param_3, long param_4);
    virtual int handle_close(void* param_1, uint param_2, uint param_3, long param_4);
    virtual int handle_destroy(void* param_1, uint param_2, uint param_3, long param_4);
    virtual void calc_timings();
    virtual void calc_timing_text();
    virtual void show_timings();
    virtual void show_comm();
    virtual void show_ai();
    virtual void send_game_options();
    virtual void receive_game_options();
    virtual void set_game_options(RGE_Game_Options* param_1);
    virtual void get_game_options(RGE_Game_Options* param_1);
    virtual float version();
    virtual int scenarioGame();
    virtual int randomGame();
    virtual int campaignGame();
    virtual int savedGame();
    virtual char* scenarioName();
    virtual int singlePlayerGame();
    virtual int multiplayerGame();
    virtual int mapXSize();
    virtual int mapYSize();
    virtual int mapZSize();
    virtual int allowCheatCodes();
    virtual int cheatNotification();
    virtual int fullVisibility();
    virtual int fogOfWar();
    virtual int coloredChat();
    virtual int gameDeveloperMode();
    virtual int playerHasCD(int param_1);
    virtual uchar playerVersion(int param_1);
    virtual char* playerVersionString(int param_1);
    virtual uchar playerCDAndVersion(int param_1);
    virtual int difficulty();
    virtual int numberPlayers();
    virtual int playerTeam(int param_1);
    virtual uchar pathFinding();
    virtual uchar mpPathFinding();
    virtual char* gameSummary();
    virtual void find_campaigns();
    virtual void setScenarioGame(int param_1);
    virtual void setVersion(float param_1);
    virtual void setScenarioName(char* param_1);
    virtual void setCampaignGame(int param_1);
    virtual void setSavedGame(int param_1);
    virtual void setSinglePlayerGame(int param_1);
    virtual void setMultiplayerGame(int param_1);
    virtual void setMapSize(int param_1, int param_2, int param_3);
    virtual void setAllowCheatCodes(int param_1);
    virtual void setCheatNotification(int param_1);
    virtual void setFullVisibility(int param_1);
    virtual void setFogOfWar(int param_1);
    virtual void setColoredChat(int param_1);
    virtual void setNumberPlayers(int param_1);
    virtual void setGameDeveloperMode(int param_1);
    virtual void setPlayerHasCD(int param_1, int param_2);
    virtual void setPlayerVersion(int param_1, uchar param_2);
    virtual void setPlayerCDAndVersion(int param_1, uchar param_2);
    virtual void setDifficulty(int param_1);
    virtual void setPlayerTeam(int param_1, int param_2);
    virtual void setPathFinding(uchar param_1);
    virtual void setMpPathFinding(uchar param_1);
    virtual void set_map_visible(uchar param_1);
    virtual void set_map_fog(uchar param_1);
    virtual void turn_world_sound_off();
    virtual int campaign_open_scenario();
    virtual long GetChecksum(long param_1);
    virtual uchar GetWorldChecksums(long* param_1, long* param_2, long* param_3);
    virtual long GetWorldChecksum();
    virtual void disable_input();
    virtual void enable_input();
    virtual void set_screen_size(long param_1, long param_2);
    virtual uchar check_prog_argument(char* param_1);
    virtual long get_scenario_checksum(char* param_1);
    virtual uchar check_scenario_checksum(char* param_1, long param_2);
    virtual void dump_memory_usage(char* param_1);
    virtual int playerID(int param_1);
    virtual void setPlayerID(int param_1, int param_2);
    virtual void reset_countdown_timer(long param_1);
    virtual void set_countdown_timer(long param_1, long param_2);
    virtual void get_countdown_timer(long param_1, long* param_2);
    virtual int play_video(char* param_1);
    virtual void close_video();
    virtual void handle_video_notify();
    virtual int play_sound(int param_1);
    virtual float get_game_speed();
    virtual void set_game_speed(float param_1);
    virtual int get_single_player_difficulty();
    virtual void set_single_player_difficulty(int param_1);
    virtual int setup_map_save_area();
    virtual void reload_scenarios_info();
    virtual void set_interface_messages();
    virtual void set_render_all();
};

static_assert(sizeof(RGE_Base_Game) == 0xA24, "RGE_Base_Game Size Mismatch");
static_assert(offsetof(RGE_Base_Game, map_save_area) == 0xA20, "RGE_Base_Game Offset Mismatch");


// Logging and Debugging
extern int do_draw_log;
extern int safe_draw_log;
extern char draw_log_name[256];
extern FILE* draw_log;
extern FILE* fps_log;
extern int do_fps_log;
extern int do_debug_random;
extern int wrote_debug_random_log;
extern int debugActions;
extern FILE* actionFile;
extern class TDebuggingLog* L;

// Application State
extern HWND AppWnd;
extern HINSTANCE AppInst;
extern HMODULE StringTable;
extern RGE_Base_Game* rge_base_game;

// Subsystems
extern class TChat* chat;
extern class TCommunications_Handler* comm;
extern class TRegistry* Regs;
extern class TSound_Driver* sound_driver;
extern class TPanelSystem* panel_system;
extern class DriveInformation* driveInfo;

// Constants (deduced from float usage)
extern float GAME_SPEED_TO_FLOAT; // DAT_0056f014
extern float FLOAT_TO_GAME_SPEED; // DAT_0056f018