#pragma once
#include <windows.h>
#include "common.h"
#include "ui_core.h"
#include "RGE_Prog_Info.h"
#include "RGE_Game_Options.h"
#include "RGE_Timing_Info.h"

class TPanel;
struct TPanelSystem;
class RGE_Scenario_Header;
class RGE_Scenario;
class TDrawSystem;
class TDrawArea;
class TShape;
class TSound_Driver;
class TMusic_System;
class TDigital;
class TCommunications_Handler;
class TDebuggingLog;
class TRegistry;
class TMousePointer;
class RGE_Font;
class RGE_Game_World;
class RGE_Game_Info;
class RGE_Scenario_File_Info;

class RGE_Base_Game {
public:
    RGE_Base_Game(RGE_Prog_Info* info, int param_2);
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
    virtual int handle_message(struct tagMSG* param_1); // vt[46] (0xB8)
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

    void setVersion(float p1);
    void setScenarioGame(int p1);
    void setCampaignGame(int p1);
    void setSavedGame(int p1);
    void setSinglePlayerGame(int p1);
    void setMultiplayerGame(int p1);
    void setMapSize(int p1, int p2, int p3);
    void setAllowCheatCodes(int p1);
    void setCheatNotification(int p1);
    void setFullVisibility(int p1);
    void setFogOfWar(int p1);
    void setColoredChat(int p1);
    void setGameDeveloperMode(int p1);
    void setDifficulty(int p1);
    void setPlayerCDAndVersion(int p1, int p2);
    void setPlayerHasCD(int p1, int p2);
    void setPlayerVersion(int p1, int p2);
    void setPlayerTeam(int p1, int p2);
    void setPathFinding(unsigned char p1);
    void setMpPathFinding(unsigned char p1);
    void setNumberPlayers(int p1);
    void setScenarioName(char* p1);
    int check_for_cd(int p1);
    void set_mouse_cursor(void* p1);
    void set_mouse_facet(long p1);
    void disable_input();
    void enable_input();
    void mouse_on();
    void mouse_off();
    int check_expiration();
    int check_multi_copies();
    unsigned char check_prog_argument(const char* p1);
    void close();
    int get_paused();
    RGE_Player* get_player();
    RGE_Font* get_font(int index);
    TShape* get_shape(int index);
    TDigital* get_sound(int index);
    unsigned long get_last_max_time();
    unsigned long get_last_world_update_count();
    unsigned long get_last_view_update_count();
    unsigned long get_world_update_count();
    unsigned long get_view_update_count();
    
    void* create_font(void* dc, int id1, int id2);

    // Accessor methods used by create_game and game start paths
    int numberPlayers();
    int mapXSize();
    int mapYSize();
    int scenarioGame();
    int campaignGame();
    int multiplayerGame();
    int singlePlayerGame();
    unsigned char playerVersion(int index);
    int playerTeam(int index);
    int randomGame();
    int fullVisibility();
    int fogOfWar();
    int playerID(int index);
    void setPlayerID(int index, int value);
    float get_game_speed();
    unsigned char pathFinding();
    unsigned char mpPathFinding();
    void set_map_visible(unsigned char p1);
    void set_map_fog(unsigned char p1);
    void reset_countdown_timer(int p1);
    void set_paused(int p1, int p2);
    void request_pause();
    void reset_timings();
    void add_to_timing(int param_1, ulong param_2);
    void increment_world_update_count();
    void increment_view_update_count();
    char* scenarioName();
    int campaign_open_scenario();
    void get_campaign_info(long* param_1, long* param_2, long* param_3);
    uchar set_campaign_info(long param_1, long param_2, long param_3);
    void set_campaign_win();
    RGE_Scenario* get_scenario_info(char* p1, int p2);

    RGE_Game_Info* player_game_info; // +0x4 (Size: 0x4)
    RGE_Scenario_File_Info* scenario_info; // +0x8 (Size: 0x4)
    RGE_Prog_Info* prog_info; // +0xC (Size: 0x4)
    void* prog_window; // +0x10 (Size: 0x4)
    int prog_ready; // +0x14 (Size: 0x4)
    int prog_active; // +0x18 (Size: 0x4)
    void* prog_palette; // +0x1C (Size: 0x4)
    void* prog_mutex; // +0x20 (Size: 0x4)
    long window_style; // +0x24 (Size: 0x4)
    int random_game_seed; // +0x28 (Size: 0x4)
    int random_map_seed; // +0x2C (Size: 0x4)
    int save_random_game_seed; // +0x30 (Size: 0x4)
    int save_random_map_seed; // +0x34 (Size: 0x4)
    int screen_saver_enabled; // +0x38 (Size: 0x4)
    int low_power_enabled; // +0x3C (Size: 0x4)
    int error_code; // +0x40 (Size: 0x4)
    int is_timer; // +0x44 (Size: 0x4)
    TDrawSystem* draw_system; // +0x48 (Size: 0x4)
    TDrawArea* draw_area; // +0x4C (Size: 0x4)
    unsigned char outline_type; // +0x50 (Size: 0x1)
    unsigned char _pad_0[0x3]; // 0x0051 (Gap: 3)
    int custom_mouse; // +0x54 (Size: 0x4)
    short shape_num; // +0x58 (Size: 0x2)
    unsigned char _pad_1[0x2]; // 0x005a (Gap: 2)
    TShape** shapes; // +0x5C (Size: 0x4)
    TSound_Driver* sound_system; // +0x60 (Size: 0x4)
    TMusic_System* music_system; // +0x64 (Size: 0x4)
    short sound_num; // +0x68 (Size: 0x2)
    unsigned char _pad_2[0x2]; // 0x006a (Gap: 2)
    TDigital** sounds; // +0x6C (Size: 0x4)
    unsigned char save_music_type; // +0x70 (Size: 0x1)
    unsigned char _pad_3[0x3]; // 0x0071 (Gap: 3)
    int save_music_track_from; // +0x74 (Size: 0x4)
    int save_music_track_to; // +0x78 (Size: 0x4)
    int save_music_cur_track; // +0x7C (Size: 0x4)
    char save_music_file[260]; // +0x80 (Size: 0x104)
    int save_music_loop; // +0x184 (Size: 0x4)
    unsigned long save_music_pos; // +0x188 (Size: 0x4)
    TCommunications_Handler* comm_handler; // +0x18C (Size: 0x4)
    int comm_syncstop; // +0x190 (Size: 0x4)
    int comm_droppackets; // +0x194 (Size: 0x4)
    int comm_syncmsg; // +0x198 (Size: 0x4)
    int comm_stepmode; // +0x19C (Size: 0x4)
    int comm_speed; // +0x1A0 (Size: 0x4)
    TDebuggingLog* debugLog; // +0x1A4 (Size: 0x4)
    int log_comm; // +0x1A8 (Size: 0x4)
    TRegistry* registry; // +0x1AC (Size: 0x4)
    int prog_mode; // +0x1B0 (Size: 0x4)
    int game_mode; // +0x1B4 (Size: 0x4)
    int sub_game_mode; // +0x1B8 (Size: 0x4)
    int paused; // +0x1BC (Size: 0x4)
    TMousePointer* mouse_pointer; // +0x1C0 (Size: 0x4)
    int erase_mouse; // +0x1C4 (Size: 0x4)
    int mouse_blit_sync; // +0x1C8 (Size: 0x4)
    int is_mouse_on; // +0x1CC (Size: 0x4)
    int windows_mouse; // +0x1D0 (Size: 0x4)
    void* mouse_cursor; // +0x1D4 (Size: 0x4)
    int input_enabled; // +0x1D8 (Size: 0x4)
    void* input_disabled_window; // +0x1DC (Size: 0x4)
    short font_num; // +0x1E0 (Size: 0x2)
    unsigned char _pad_4[0x2]; // 0x01e2 (Gap: 2)
    RGE_Font* fonts; // +0x1E4 (Size: 0x4)
    char work_dir[261]; // +0x1E8 (Size: 0x105)
    char string_dll_name[261]; // +0x2ED (Size: 0x105)
    unsigned char _pad_5[0x2]; // 0x03f2 (Gap: 2)
    RGE_Game_World* world; // +0x3F4 (Size: 0x4)
    int render_all; // +0x3F8 (Size: 0x4)
    short master_obj_id; // +0x3FC (Size: 0x2)
    short terrain_id; // +0x3FE (Size: 0x2)
    short elevation_height; // +0x400 (Size: 0x2)
    short brush_size; // +0x402 (Size: 0x2)
    char timing_text[256]; // +0x404 (Size: 0x100)
    unsigned long frame_count; // +0x504 (Size: 0x4)
    unsigned long world_update_count; // +0x508 (Size: 0x4)
    unsigned long view_update_count; // +0x50C (Size: 0x4)
    unsigned long last_frame_count; // +0x510 (Size: 0x4)
    unsigned long last_world_update_count; // +0x514 (Size: 0x4)
    unsigned long last_view_update_count; // +0x518 (Size: 0x4)
    unsigned long fps; // +0x51C (Size: 0x4)
    unsigned long world_update_fps; // +0x520 (Size: 0x4)
    unsigned long view_update_fps; // +0x524 (Size: 0x4)
    RGE_Timing_Info timings[30]; // +0x528 (Size: 0x3C0)
    int do_show_timings; // +0x8E8 (Size: 0x4)
    int do_show_comm; // +0x8EC (Size: 0x4)
    int do_show_ai; // +0x8F0 (Size: 0x4)
    unsigned long last_view_time; // +0x8F4 (Size: 0x4)
    struct RGE_Game_Options {
        float versionValue; // +0x0 (Size: 0x4)
        unsigned char scenarioGameValue; // +0x4 (Size: 0x1)
        char scenarioNameValue[128]; // +0x5 (Size: 0x80)
        unsigned char singlePlayerGameValue; // +0x85 (Size: 0x1)
        unsigned char multiplayerGameValue; // +0x86 (Size: 0x1)
        unsigned char mapXSizeValue; // +0x87 (Size: 0x1)
        unsigned char mapYSizeValue; // +0x88 (Size: 0x1)
        unsigned char mapZSizeValue; // +0x89 (Size: 0x1)
        unsigned char allowCheatCodesValue; // +0x8A (Size: 0x1)
        unsigned char mpPathFindingValue; // +0x8B (Size: 0x1)
        unsigned char cheatNotificationValue; // +0x8C (Size: 0x1)
        unsigned char fullVisibilityValue; // +0x8D (Size: 0x1)
        unsigned char fogOfWarValue; // +0x8E (Size: 0x1)
        unsigned char coloredChatValue; // +0x8F (Size: 0x1)
        unsigned char numberPlayersValue; // +0x90 (Size: 0x1)
        unsigned char gameDeveloperModeValue; // +0x91 (Size: 0x1)
        unsigned char playerCDAndVersionValue[9]; // +0x92 (Size: 0x9)
        unsigned char difficultyValue; // +0x9B (Size: 0x1)
        unsigned char playerTeamValue[9]; // +0x9C (Size: 0x9)
        unsigned char _pad_end[0x3]; // 0x00a5 (Gap: 3)
    } rge_game_options; // +0x8F8 (Size: 0xA8)
    int campaignGameValue; // +0x9A0 (Size: 0x4)
    int savedGameValue; // +0x9A4 (Size: 0x4)
    int quick_build; // +0x9A8 (Size: 0x4)
    int save_check_for_cd; // +0x9AC (Size: 0x4)
    int playerIDValue[9]; // +0x9B0 (Size: 0x24)
    int display_selected_ids; // +0x9D4 (Size: 0x4)
    long countdown_timer[9]; // +0x9D8 (Size: 0x24)
    int auto_paused; // +0x9FC (Size: 0x4)
    int save_paused; // +0xA00 (Size: 0x4)
    int non_user_pause; // +0xA04 (Size: 0x4)
    int rollover; // +0xA08 (Size: 0x4)
    float game_speed; // +0xA0C (Size: 0x4)
    int single_player_difficulty; // +0xA10 (Size: 0x4)
    unsigned char pathFindingValue; // +0xA14 (Size: 0x1)
    unsigned char resigned[9]; // +0xA15 (Size: 0x9)
    unsigned char _pad_6[0x2]; // 0x0a1e (Gap: 2)
    TDrawArea* map_save_area; // +0xA20 (Size: 0x4)
};
static_assert(sizeof(RGE_Base_Game) == 0xA24, "Size mismatch");
