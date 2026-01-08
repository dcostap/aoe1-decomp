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

class RGE_Base_Game       {
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

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~RGE_Base_Game(); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 (Override)
    virtual int run(); // Ghidra: run

    // [Slot 02] Offset 0x08 (Override)
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: wnd_proc

    // [Slot 03] Offset 0x0C (Override)
    virtual void set_prog_mode(int param_1); // Ghidra: set_prog_mode

    // [Slot 04] Offset 0x10 (Override)
    virtual void set_game_mode(int param_1, int param_2); // Ghidra: set_game_mode

    // [Slot 05] Offset 0x14 (Override)
    virtual void set_player(short param_1); // Ghidra: set_player

    // [Slot 06] Offset 0x18 (Override)
    virtual int get_error_code(); // Ghidra: get_error_code

    // [Slot 07] Offset 0x1C (Override)
    virtual char* get_string(int param_1, long param_2, char* param_3, int param_4); // Ghidra: get_string

    // [Slot 08] Offset 0x20 (Override)
    virtual char* get_string(long param_1, char* param_2, int param_3); // Ghidra: get_string

    // [Slot 09] Offset 0x24 (Override)
    virtual char* get_string(long param_1); // Ghidra: get_string

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

    // [Slot 17] Offset 0x44 (Override)
    virtual int reset_comm(); // Ghidra: reset_comm

    // [Slot 18] Offset 0x48 (Override)
    virtual void send_game_options(); // Ghidra: send_game_options

    // [Slot 19] Offset 0x4C (Override)
    virtual void receive_game_options(); // Ghidra: receive_game_options

    // [Slot 20] Offset 0x50 (Override)
    virtual char* gameSummary(); // Ghidra: gameSummary

    // [Slot 21] Offset 0x54 (Override)
    virtual int processCheatCode(int param_1, char* param_2); // Ghidra: processCheatCode

    // [Slot 22] Offset 0x58 (Override)
    virtual int setup_music_system(); // Ghidra: setup_music_system

    // [Slot 23] Offset 0x5C (Override)
    virtual void shutdown_music_system(); // Ghidra: shutdown_music_system

    // [Slot 24] Offset 0x60 (Override)
    virtual int setup(); // Ghidra: setup

    // [Slot 25] Offset 0x64 (Override)
    virtual int setup_cmd_options(); // Ghidra: setup_cmd_options

    // [Slot 26] Offset 0x68 (Override)
    virtual int setup_class(); // Ghidra: setup_class

    // [Slot 27] Offset 0x6C (Override)
    virtual int setup_main_window(); // Ghidra: setup_main_window

    // [Slot 28] Offset 0x70 (Override)
    virtual int setup_graphics_system(); // Ghidra: setup_graphics_system

    // [Slot 29] Offset 0x74 (Override)
    virtual int setup_palette(); // Ghidra: setup_palette

    // [Slot 30] Offset 0x78 (Override)
    virtual int setup_mouse(); // Ghidra: setup_mouse

    // [Slot 31] Offset 0x7C (Override)
    virtual int setup_registry(); // Ghidra: setup_registry

    // [Slot 32] Offset 0x80 (Override)
    virtual int setup_debugging_log(); // Ghidra: setup_debugging_log

    // [Slot 33] Offset 0x84 (Override)
    virtual int setup_chat(); // Ghidra: setup_chat

    // [Slot 34] Offset 0x88 (Override)
    virtual int setup_comm(); // Ghidra: setup_comm

    // [Slot 35] Offset 0x8C (Override)
    virtual int setup_sound_system(); // Ghidra: setup_sound_system

    // [Slot 36] Offset 0x90 (Override)
    virtual int setup_fonts(); // Ghidra: setup_fonts

    // [Slot 37] Offset 0x94 (Override)
    virtual int setup_sounds(); // Ghidra: setup_sounds

    // [Slot 38] Offset 0x98 (Override)
    virtual int setup_shapes(); // Ghidra: setup_shapes

    // [Slot 39] Offset 0x9C (Override)
    virtual int setup_blank_screen(); // Ghidra: setup_blank_screen

    // [Slot 40] Offset 0xA0 (Override)
    virtual void setup_timings(); // Ghidra: setup_timings

    // [Slot 41] Offset 0xA4 (Override)
    virtual void stop_sound_system(); // Ghidra: stop_sound_system

    // [Slot 42] Offset 0xA8 (Override)
    virtual int restart_sound_system(); // Ghidra: restart_sound_system

    // [Slot 43] Offset 0xAC (Override)
    virtual void stop_music_system(); // Ghidra: stop_music_system

    // [Slot 44] Offset 0xB0 (Override)
    virtual int restart_music_system(); // Ghidra: restart_music_system

    // [Slot 45] Offset 0xB4 (Override)
    virtual RGE_Game_World* create_world(); // Ghidra: create_world

    // [Slot 46] Offset 0xB8 (Override)
    virtual int handle_message(tagMSG* param_1); // Ghidra: handle_message

    // [Slot 47] Offset 0xBC (Override)
    virtual int handle_idle(); // Ghidra: handle_idle

    // [Slot 48] Offset 0xC0 (Override)
    virtual int handle_mouse_move(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: handle_mouse_move

    // [Slot 49] Offset 0xC4 (Override)
    virtual int handle_key_down(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: handle_key_down

    // [Slot 50] Offset 0xC8 (Override)
    virtual int handle_user_command(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: handle_user_command

    // [Slot 51] Offset 0xCC (Override)
    virtual int handle_command(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: handle_command

    // [Slot 52] Offset 0xD0 (Override)
    virtual int handle_music_done(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: handle_music_done

    // [Slot 53] Offset 0xD4 (Override)
    virtual int handle_paint(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: handle_paint

    // [Slot 54] Offset 0xD8 (Override)
    virtual int handle_activate(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: handle_activate

    // [Slot 55] Offset 0xDC (Override)
    virtual int handle_init_menu(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: handle_init_menu

    // [Slot 56] Offset 0xE0 (Override)
    virtual int handle_exit_menu(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: handle_exit_menu

    // [Slot 57] Offset 0xE4 (Override)
    virtual int handle_size(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: handle_size

    // [Slot 58] Offset 0xE8 (Override)
    virtual int handle_palette_changed(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: handle_palette_changed

    // [Slot 59] Offset 0xEC (Override)
    virtual int handle_query_new_palette(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: handle_query_new_palette

    // [Slot 60] Offset 0xF0 (Override)
    virtual int handle_close(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: handle_close

    // [Slot 61] Offset 0xF4 (Override)
    virtual int handle_destroy(void* param_1, uint param_2, uint param_3, long param_4); // Ghidra: handle_destroy

    // [Slot 62] Offset 0xF8 (Override)
    virtual int action_update(); // Ghidra: action_update

    // [Slot 63] Offset 0xFC (Override)
    virtual int action_mouse_move(long param_1, long param_2, int param_3, int param_4, int param_5, int param_6); // Ghidra: action_mouse_move

    // [Slot 64] Offset 0x100 (Override)
    virtual int action_key_down(ulong param_1, int param_2, int param_3, int param_4, int param_5); // Ghidra: action_key_down

    // [Slot 65] Offset 0x104 (Override)
    virtual int action_user_command(ulong param_1, ulong param_2); // Ghidra: action_user_command

    // [Slot 66] Offset 0x108 (Override)
    virtual int action_command(ulong param_1, ulong param_2); // Ghidra: action_command

    // [Slot 67] Offset 0x10C (Override)
    virtual int action_music_done(); // Ghidra: action_music_done

    // [Slot 68] Offset 0x110 (Override)
    virtual int action_activate(); // Ghidra: action_activate

    // [Slot 69] Offset 0x114 (Override)
    virtual int action_deactivate(); // Ghidra: action_deactivate

    // [Slot 70] Offset 0x118 (Override)
    virtual int action_init_menu(); // Ghidra: action_init_menu

    // [Slot 71] Offset 0x11C (Override)
    virtual int action_exit_menu(); // Ghidra: action_exit_menu

    // [Slot 72] Offset 0x120 (Override)
    virtual int action_size(); // Ghidra: action_size

    // [Slot 73] Offset 0x124 (Override)
    virtual int action_close(); // Ghidra: action_close

    // [Slot 74] Offset 0x128 (Override)
    virtual void calc_timings(); // Ghidra: calc_timings

    // [Slot 75] Offset 0x12C (Override)
    virtual void calc_timing_text(); // Ghidra: calc_timing_text

    // [Slot 76] Offset 0x130 (Override)
    virtual void show_timings(); // Ghidra: show_timings

    // [Slot 77] Offset 0x134 (Override)
    virtual void show_comm(); // Ghidra: show_comm

    // [Slot 78] Offset 0x138 (Override)
    virtual void show_ai(); // Ghidra: show_ai

    // [Slot 79] Offset 0x13C (Override)
    virtual int setup_map_save_area(); // Ghidra: setup_map_save_area

    // [Slot 80] Offset 0x140 (Override)
    virtual void set_interface_messages(); // Ghidra: set_interface_messages

    // --- Non-Virtual Members ---
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