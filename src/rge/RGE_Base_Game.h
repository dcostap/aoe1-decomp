#pragma once

#include "../types.h"

// Forward declarations
class TDrawSystem;
class TDrawArea;
struct TShape;
struct TSound_Driver;
struct TMusic_System;
struct TDigital;
struct TCommunications_Handler;
struct TDebuggingLog;
class TRegistry;
class TMousePointer;
class RGE_Game_World;
struct RGE_Game_Info;
struct RGE_Scenario_File_Info;
struct RGE_Prog_Info;
struct RGE_Font;

// RGE_Timing_Info - 32 bytes (960/30 = 32)
struct RGE_Timing_Info {
    /* 0x00 */ ulong accum_time;
    /* 0x04 */ ulong last_time;
    /* 0x08 */ ulong start_time;
    /* 0x0C */ int include_in_total;
    /* 0x10 */ int is_summary;
    /* 0x14 */ ulong last_single_time;
    /* 0x18 */ ulong max_time;
    /* 0x1C */ ulong last_max_time;
};
static_assert(sizeof(RGE_Timing_Info) == 32, "RGE_Timing_Info size mismatch");

// RGE_Game_Options - 168 bytes per layout.json
struct RGE_Game_Options {
    /* 0x00 */ float versionValue;
    /* 0x04 */ uchar scenarioGameValue;
    /* 0x05 */ char scenarioNameValue[124];
    /* 0x81 */ uchar singlePlayerGameValue;
    /* 0x82 */ uchar multiplayerGameValue;
    /* 0x83 */ uchar mapXSizeValue;
    /* 0x84 */ uchar mapYSizeValue;
    /* 0x85 */ uchar mapZSizeValue;
    /* 0x86 */ uchar allowCheatCodesValue;
    /* 0x87 */ uchar mpPathFindingValue;
    /* 0x88 */ uchar cheatNotificationValue;
    /* 0x89 */ uchar fullVisibilityValue;
    /* 0x8A */ uchar fogOfWarValue;
    /* 0x8B */ uchar coloredChatValue;
    /* 0x8C */ uchar numberPlayersValue;
    /* 0x8D */ uchar gameDeveloperModeValue;
    /* 0x8E */ uchar playerCDAndVersionValue[8];
    /* 0x96 */ uchar difficultyValue;
    /* 0x97 */ uchar playerTeamValue[8];
    /* 0x9F */ uchar _padding[9]; // Pad to 168 bytes
};
static_assert(sizeof(RGE_Game_Options) == 168, "RGE_Game_Options size mismatch");

class RGE_Base_Game {
public:
    // ========================================================================
    // Virtual Table (Order MUST match layout.json vtable array exactly)
    // ========================================================================
    /* [0]  */ virtual ~RGE_Base_Game();
    /* [1]  */ virtual int run();
    /* [2]  */ virtual long wnd_proc(HWND hwnd, uint msg, WPARAM wparam, LPARAM lparam);
    /* [3]  */ virtual void set_prog_mode(int mode);
    /* [4]  */ virtual void set_game_mode(int mode, int sub_mode);
    /* [5]  */ virtual void set_player(short player_id);
    /* [6]  */ virtual int get_error_code();
    /* [7]  */ virtual char* get_string(int a, long b, char* c, int d);
    /* [8]  */ virtual char* get_string(long a, char* b, int c);
    /* [9]  */ virtual char* get_string(long a);
    /* [10] */ virtual char* get_string2(int a, long b, long c, char* d, int e);
    /* [11] */ virtual void* get_view_panel();
    /* [12] */ virtual void* get_map_panel();
    /* [13] */ virtual void* new_scenario_header(void* scenario);
    /* [14] */ virtual void* new_scenario_header(int a);
    /* [15] */ virtual void* new_scenario_info(int a);
    /* [16] */ virtual void notification(int a, long b, long c, long d, long e);
    /* [17] */ virtual int reset_comm();
    /* [18] */ virtual void send_game_options();
    /* [19] */ virtual void receive_game_options();
    /* [20] */ virtual char* gameSummary();
    /* [21] */ virtual int processCheatCode(int a, char* b);
    /* [22] */ virtual int setup_music_system();
    /* [23] */ virtual void shutdown_music_system();
    /* [24] */ virtual int setup();
    /* [25] */ virtual int setup_cmd_options();
    /* [26] */ virtual int setup_class();
    /* [27] */ virtual int setup_main_window();
    /* [28] */ virtual int setup_graphics_system();
    /* [29] */ virtual int setup_palette();
    /* [30] */ virtual int setup_mouse();
    /* [31] */ virtual int setup_registry();
    /* [32] */ virtual int setup_debugging_log();
    /* [33] */ virtual int setup_chat();
    /* [34] */ virtual int setup_comm();
    /* [35] */ virtual int setup_sound_system();
    /* [36] */ virtual int setup_fonts();
    /* [37] */ virtual int setup_sounds();
    /* [38] */ virtual int setup_shapes();
    /* [39] */ virtual int setup_blank_screen();
    /* [40] */ virtual void setup_timings();
    /* [41] */ virtual void stop_sound_system();
    /* [42] */ virtual int restart_sound_system();
    /* [43] */ virtual void stop_music_system();
    /* [44] */ virtual int restart_music_system();
    /* [45] */ virtual RGE_Game_World* create_world();
    /* [46] */ virtual int handle_message(tagMSG* msg);
    /* [47] */ virtual int handle_idle();
    /* [48] */ virtual int handle_mouse_move(void* hwnd, uint msg, uint wparam, long lparam);
    /* [49] */ virtual int handle_key_down(void* hwnd, uint msg, uint wparam, long lparam);
    /* [50] */ virtual int handle_user_command(void* hwnd, uint msg, uint wparam, long lparam);
    /* [51] */ virtual int handle_command(void* hwnd, uint msg, uint wparam, long lparam);
    /* [52] */ virtual int handle_music_done(void* hwnd, uint msg, uint wparam, long lparam);
    /* [53] */ virtual int handle_paint(void* hwnd, uint msg, uint wparam, long lparam);
    /* [54] */ virtual int handle_activate(void* hwnd, uint msg, uint wparam, long lparam);
    /* [55] */ virtual int handle_init_menu(void* hwnd, uint msg, uint wparam, long lparam);
    /* [56] */ virtual int handle_exit_menu(void* hwnd, uint msg, uint wparam, long lparam);
    /* [57] */ virtual int handle_size(void* hwnd, uint msg, uint wparam, long lparam);
    /* [58] */ virtual int handle_palette_changed(void* hwnd, uint msg, uint wparam, long lparam);
    /* [59] */ virtual int handle_query_new_palette(void* hwnd, uint msg, uint wparam, long lparam);
    /* [60] */ virtual int handle_close(void* hwnd, uint msg, uint wparam, long lparam);
    /* [61] */ virtual int handle_destroy(void* hwnd, uint msg, uint wparam, long lparam);
    /* [62] */ virtual int action_update();
    /* [63] */ virtual int action_mouse_move(long x, long y, int a, int b, int c, int d);
    /* [64] */ virtual int action_key_down(ulong key, int a, int b, int c, int d);
    /* [65] */ virtual int action_user_command(ulong a, ulong b);
    /* [66] */ virtual int action_command(ulong a, ulong b);
    /* [67] */ virtual int action_music_done();
    /* [68] */ virtual int action_activate();
    /* [69] */ virtual int action_deactivate();
    /* [70] */ virtual int action_init_menu();
    /* [71] */ virtual int action_exit_menu();
    /* [72] */ virtual int action_size();
    /* [73] */ virtual int action_close();
    /* [74] */ virtual void calc_timings();
    /* [75] */ virtual void calc_timing_text();
    /* [76] */ virtual void show_timings();
    /* [77] */ virtual void show_comm();
    /* [78] */ virtual void show_ai();
    /* [79] */ virtual int setup_map_save_area();
    /* [80] */ virtual void set_interface_messages();

    // ========================================================================
    // Members (Offsets MUST match layout.json exactly)
    // ========================================================================
    /* 0x0004 */ RGE_Game_Info* player_game_info;
    /* 0x0008 */ RGE_Scenario_File_Info* scenario_info;
    /* 0x000C */ RGE_Prog_Info* prog_info;
    /* 0x0010 */ void* prog_window;
    /* 0x0014 */ int prog_ready;
    /* 0x0018 */ int prog_active;
    /* 0x001C */ void* prog_palette;
    /* 0x0020 */ void* prog_mutex;
    /* 0x0024 */ long window_style;
    /* 0x0028 */ int random_game_seed;
    /* 0x002C */ int random_map_seed;
    /* 0x0030 */ int save_random_game_seed;
    /* 0x0034 */ int save_random_map_seed;
    /* 0x0038 */ int screen_saver_enabled;
    /* 0x003C */ int low_power_enabled;
    /* 0x0040 */ int error_code;
    /* 0x0044 */ int is_timer;
    /* 0x0048 */ TDrawSystem* draw_system;
    /* 0x004C */ TDrawArea* draw_area;
    /* 0x0050 */ uchar outline_type;
    // Compiler adds 3 bytes padding here to align custom_mouse to 4-byte boundary
    /* 0x0054 */ int custom_mouse;
    /* 0x0058 */ short shape_num;
    // Compiler adds 2 bytes padding here to align shapes to 4-byte boundary
    /* 0x005C */ TShape** shapes;
    /* 0x0060 */ TSound_Driver* sound_system;
    /* 0x0064 */ TMusic_System* music_system;
    /* 0x0068 */ short sound_num;
    // Compiler adds 2 bytes padding here
    /* 0x006C */ TDigital** sounds;
    /* 0x0070 */ uchar save_music_type;
    // Compiler adds 3 bytes padding here
    /* 0x0074 */ int save_music_track_from;
    /* 0x0078 */ int save_music_track_to;
    /* 0x007C */ int save_music_cur_track;
    /* 0x0080 */ char save_music_file[260];
    /* 0x0184 */ int save_music_loop;
    /* 0x0188 */ ulong save_music_pos;
    /* 0x018C */ TCommunications_Handler* comm_handler;
    /* 0x0190 */ int comm_syncstop;
    /* 0x0194 */ int comm_droppackets;
    /* 0x0198 */ int comm_syncmsg;
    /* 0x019C */ int comm_stepmode;
    /* 0x01A0 */ int comm_speed;
    /* 0x01A4 */ TDebuggingLog* debugLog;
    /* 0x01A8 */ int log_comm;
    /* 0x01AC */ TRegistry* registry;
    /* 0x01B0 */ int prog_mode;
    /* 0x01B4 */ int game_mode;
    /* 0x01B8 */ int sub_game_mode;
    /* 0x01BC */ int paused;
    /* 0x01C0 */ TMousePointer* mouse_pointer;
    /* 0x01C4 */ int erase_mouse;
    /* 0x01C8 */ int mouse_blit_sync;
    /* 0x01CC */ int is_mouse_on;
    /* 0x01D0 */ int windows_mouse;
    /* 0x01D4 */ void* mouse_cursor;
    /* 0x01D8 */ int input_enabled;
    /* 0x01DC */ void* input_disabled_window;
    /* 0x01E0 */ short font_num;
    // Compiler adds 2 bytes padding here
    /* 0x01E4 */ RGE_Font* fonts;
    /* 0x01E8 */ char work_dir[261];
    /* 0x02ED */ char string_dll_name[261];
    // After string_dll_name ends at 0x02ED + 261 = 0x03F2, need 2 bytes padding for 4-byte alignment
    /* 0x03F4 */ RGE_Game_World* world;
    /* 0x03F8 */ int render_all;
    /* 0x03FC */ short master_obj_id;
    /* 0x03FE */ short terrain_id;
    /* 0x0400 */ short elevation_height;
    /* 0x0402 */ short brush_size;
    /* 0x0404 */ char timing_text[256];
    /* 0x0504 */ ulong frame_count;
    /* 0x0508 */ ulong world_update_count;
    /* 0x050C */ ulong view_update_count;
    /* 0x0510 */ ulong last_frame_count;
    /* 0x0514 */ ulong last_world_update_count;
    /* 0x0518 */ ulong last_view_update_count;
    /* 0x051C */ ulong fps;
    /* 0x0520 */ ulong world_update_fps;
    /* 0x0524 */ ulong view_update_fps;
    /* 0x0528 */ RGE_Timing_Info timings[30];
    /* 0x08E8 */ int do_show_timings;
    /* 0x08EC */ int do_show_comm;
    /* 0x08F0 */ int do_show_ai;
    /* 0x08F4 */ ulong last_view_time;
    /* 0x08F8 */ RGE_Game_Options rge_game_options;
    /* 0x09A0 */ int campaignGameValue;
    /* 0x09A4 */ int savedGameValue;
    /* 0x09A8 */ int quick_build;
    /* 0x09AC */ int save_check_for_cd;
    /* 0x09B0 */ int playerIDValue[9];
    /* 0x09D4 */ int display_selected_ids;
    /* 0x09D8 */ long countdown_timer[9];
    /* 0x09FC */ int auto_paused;
    /* 0x0A00 */ int save_paused;
    /* 0x0A04 */ int non_user_pause;
    /* 0x0A08 */ int rollover;
    /* 0x0A0C */ float game_speed;
    /* 0x0A10 */ int single_player_difficulty;
    /* 0x0A14 */ uchar pathFindingValue;
    /* 0x0A15 */ uchar resigned[9];
    // After resigned ends at 0x0A15 + 9 = 0x0A1E, need 2 bytes padding
    /* 0x0A20 */ TDrawArea* map_save_area;

    // ========================================================================
    // Non-virtual Methods
    // ========================================================================
    RGE_Base_Game(RGE_Prog_Info* info, int setup);

    void setVersion(float v);
    void setScenarioGame(int v);
    void setCampaignGame(int v);
    void setSavedGame(int v);
    void setSinglePlayerGame(int v);
    void setMultiplayerGame(int v);
    void setMapSize(int x, int y, int z);
    void setAllowCheatCodes(int v);
    void setCheatNotification(int v);
    void setFullVisibility(int v);
    void setFogOfWar(int v);
    void setColoredChat(int v);
    void setGameDeveloperMode(int v);
    void setDifficulty(int v);
    void setPlayerCDAndVersion(int p, char v);
    void setPlayerHasCD(int p, int v);
    void setPlayerVersion(int p, char v);
    void setPlayerTeam(int p, int v);
    void setPathFinding(char v);
    void setMpPathFinding(char v);
    void setNumberPlayers(int v);
    void setScenarioName(const char* name);

    // Getters
    uchar pathFinding() const { return this->pathFindingValue; }
    uchar mpPathFinding() const { return this->rge_game_options.mpPathFindingValue; }
};

extern RGE_Base_Game* rge_base_game;

// ============================================================================
// MANDATORY VERIFICATION (per AI_INSTRUCTIONS.md)
// ============================================================================
static_assert(sizeof(RGE_Base_Game) == 0xA24, "RGE_Base_Game size mismatch");
static_assert(offsetof(RGE_Base_Game, player_game_info) == 0x04, "player_game_info offset");
static_assert(offsetof(RGE_Base_Game, custom_mouse) == 0x54, "custom_mouse offset");
static_assert(offsetof(RGE_Base_Game, save_music_file) == 0x80, "save_music_file offset");
static_assert(offsetof(RGE_Base_Game, rge_game_options) == 0x8F8, "rge_game_options offset");
static_assert(offsetof(RGE_Base_Game, map_save_area) == 0xA20, "map_save_area offset");
