#pragma once
#include "common.h"

class RGE_Base_Game {
public:
    // Virtuals (best-effort)
    virtual ~RGE_Base_Game(); // vt[0] (0x0)
    virtual int run(); // vt[1] (0x4)
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4); // vt[2] (0x8)
    virtual void set_prog_mode(int param_1); // vt[3] (0xC)
    virtual void set_game_mode(int param_1, int param_2); // vt[4] (0x10)
    virtual void set_player(short param_1); // vt[5] (0x14)
    virtual int get_error_code(); // vt[6] (0x18)
    virtual char* get_string(int param_1, long param_2, char* param_3, int param_4); // vt[7] (0x1C)
    virtual char* get_string(long param_1, char* param_2, int param_3); // vt[8] (0x20)
    virtual char* get_string(long param_1); // vt[9] (0x24)
    virtual char* get_string2(int param_1, long param_2, long param_3, char* param_4, int param_5); // vt[10] (0x28)
    virtual TPanel* get_view_panel(); // vt[11] (0x2C)
    virtual TPanel* get_map_panel(); // vt[12] (0x30)
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario* param_1); // vt[13] (0x34)
    virtual RGE_Scenario_Header* new_scenario_header(int param_1); // vt[14] (0x38)
    virtual RGE_Scenario* new_scenario_info(int param_1); // vt[15] (0x3C)
    virtual void notification(int param_1, long param_2, long param_3, long param_4, long param_5); // vt[16] (0x40)
    virtual int reset_comm(); // vt[17] (0x44)
    virtual void send_game_options(); // vt[18] (0x48)
    virtual void receive_game_options(); // vt[19] (0x4C)
    virtual char* gameSummary(); // vt[20] (0x50)
    virtual int processCheatCode(int param_1, char* param_2); // vt[21] (0x54)
    virtual int setup_music_system(); // vt[22] (0x58)
    virtual void shutdown_music_system(); // vt[23] (0x5C)
    virtual int setup(); // vt[24] (0x60)
    virtual int setup_cmd_options(); // vt[25] (0x64)
    virtual int setup_class(); // vt[26] (0x68)
    virtual int setup_main_window(); // vt[27] (0x6C)
    virtual int setup_graphics_system(); // vt[28] (0x70)
    virtual int setup_palette(); // vt[29] (0x74)
    virtual int setup_mouse(); // vt[30] (0x78)
    virtual int setup_registry(); // vt[31] (0x7C)
    virtual int setup_debugging_log(); // vt[32] (0x80)
    virtual int setup_chat(); // vt[33] (0x84)
    virtual int setup_comm(); // vt[34] (0x88)
    virtual int setup_sound_system(); // vt[35] (0x8C)
    virtual int setup_fonts(); // vt[36] (0x90)
    virtual int setup_sounds(); // vt[37] (0x94)
    virtual int setup_shapes(); // vt[38] (0x98)
    virtual int setup_blank_screen(); // vt[39] (0x9C)
    virtual void setup_timings(); // vt[40] (0xA0)
    virtual void stop_sound_system(); // vt[41] (0xA4)
    virtual int restart_sound_system(); // vt[42] (0xA8)
    virtual void stop_music_system(); // vt[43] (0xAC)
    virtual int restart_music_system(); // vt[44] (0xB0)
    virtual RGE_Game_World* create_world(); // vt[45] (0xB4)
    virtual int handle_message(tagMSG* param_1); // vt[46] (0xB8)
    virtual int handle_idle(); // vt[47] (0xBC)
    virtual int handle_mouse_move(void* param_1, uint param_2, uint param_3, long param_4); // vt[48] (0xC0)
    virtual int handle_key_down(void* param_1, uint param_2, uint param_3, long param_4); // vt[49] (0xC4)
    virtual int handle_user_command(void* param_1, uint param_2, uint param_3, long param_4); // vt[50] (0xC8)
    virtual int handle_command(void* param_1, uint param_2, uint param_3, long param_4); // vt[51] (0xCC)
    virtual int handle_music_done(void* param_1, uint param_2, uint param_3, long param_4); // vt[52] (0xD0)
    virtual int handle_paint(void* param_1, uint param_2, uint param_3, long param_4); // vt[53] (0xD4)
    virtual int handle_activate(void* param_1, uint param_2, uint param_3, long param_4); // vt[54] (0xD8)
    virtual int handle_init_menu(void* param_1, uint param_2, uint param_3, long param_4); // vt[55] (0xDC)
    virtual int handle_exit_menu(void* param_1, uint param_2, uint param_3, long param_4); // vt[56] (0xE0)
    virtual int handle_size(void* param_1, uint param_2, uint param_3, long param_4); // vt[57] (0xE4)
    virtual int handle_palette_changed(void* param_1, uint param_2, uint param_3, long param_4); // vt[58] (0xE8)
    virtual int handle_query_new_palette(void* param_1, uint param_2, uint param_3, long param_4); // vt[59] (0xEC)
    virtual int handle_close(void* param_1, uint param_2, uint param_3, long param_4); // vt[60] (0xF0)
    virtual int handle_destroy(void* param_1, uint param_2, uint param_3, long param_4); // vt[61] (0xF4)
    virtual int action_update(); // vt[62] (0xF8)
    virtual int action_mouse_move(long param_1, long param_2, int param_3, int param_4, int param_5, int param_6); // vt[63] (0xFC)
    virtual int action_key_down(ulong param_1, int param_2, int param_3, int param_4, int param_5); // vt[64] (0x100)
    virtual int action_user_command(ulong param_1, ulong param_2); // vt[65] (0x104)
    virtual int action_command(ulong param_1, ulong param_2); // vt[66] (0x108)
    virtual int action_music_done(); // vt[67] (0x10C)
    virtual int action_activate(); // vt[68] (0x110)
    virtual int action_deactivate(); // vt[69] (0x114)
    virtual int action_init_menu(); // vt[70] (0x118)
    virtual int action_exit_menu(); // vt[71] (0x11C)
    virtual int action_size(); // vt[72] (0x120)
    virtual int action_close(); // vt[73] (0x124)
    virtual void calc_timings(); // vt[74] (0x128)
    virtual void calc_timing_text(); // vt[75] (0x12C)
    virtual void show_timings(); // vt[76] (0x130)
    virtual void show_comm(); // vt[77] (0x134)
    virtual void show_ai(); // vt[78] (0x138)
    virtual int setup_map_save_area(); // vt[79] (0x13C)
    virtual void set_interface_messages(); // vt[80] (0x140)

    RGE_Game_Info* player_game_info;
    RGE_Scenario_File_Info* scenario_info;
    RGE_Prog_Info* prog_info;
    void* prog_window;
    int prog_ready;
    int prog_active;
    void* prog_palette;
    void* prog_mutex;
    long window_style;
    int random_game_seed;
    int random_map_seed;
    int save_random_game_seed;
    int save_random_map_seed;
    int screen_saver_enabled;
    int low_power_enabled;
    int error_code;
    int is_timer;
    TDrawSystem* draw_system;
    TDrawArea* draw_area;
    unsigned char outline_type;
    int custom_mouse;
    short shape_num;
    TShape** shapes;
    TSound_Driver* sound_system;
    TMusic_System* music_system;
    short sound_num;
    TDigital** sounds;
    unsigned char save_music_type;
    int save_music_track_from;
    int save_music_track_to;
    int save_music_cur_track;
    char save_music_file[260];
    int save_music_loop;
    unsigned long save_music_pos;
    TCommunications_Handler* comm_handler;
    int comm_syncstop;
    int comm_droppackets;
    int comm_syncmsg;
    int comm_stepmode;
    int comm_speed;
    TDebuggingLog* debugLog;
    int log_comm;
    TRegistry* registry;
    int prog_mode;
    int game_mode;
    int sub_game_mode;
    int paused;
    TMousePointer* mouse_pointer;
    int erase_mouse;
    int mouse_blit_sync;
    int is_mouse_on;
    int windows_mouse;
    void* mouse_cursor;
    int input_enabled;
    void* input_disabled_window;
    short font_num;
    RGE_Font* fonts;
    char work_dir[261];
    char string_dll_name[261];
    RGE_Game_World* world;
    int render_all;
    short master_obj_id;
    short terrain_id;
    short elevation_height;
    short brush_size;
    char timing_text[256];
    unsigned long frame_count;
    unsigned long world_update_count;
    unsigned long view_update_count;
    unsigned long last_frame_count;
    unsigned long last_world_update_count;
    unsigned long last_view_update_count;
    unsigned long fps;
    unsigned long world_update_fps;
    unsigned long view_update_fps;
    RGE_Timing_Info timings[30];
    int do_show_timings;
    int do_show_comm;
    int do_show_ai;
    unsigned long last_view_time;
    RGE_Base_Game::RGE_Game_Options rge_game_options;
    int campaignGameValue;
    int savedGameValue;
    int quick_build;
    int save_check_for_cd;
    int playerIDValue[9];
    int display_selected_ids;
    long countdown_timer[9];
    int auto_paused;
    int save_paused;
    int non_user_pause;
    int rollover;
    float game_speed;
    int single_player_difficulty;
    unsigned char pathFindingValue;
    unsigned char resigned[9];
    TDrawArea* map_save_area;
};
static_assert(sizeof(RGE_Base_Game) == 0xA24, "Size mismatch");
