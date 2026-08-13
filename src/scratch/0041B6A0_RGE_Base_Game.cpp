// VA: 0041B6A0 RGE_Base_Game::RGE_Base_Game (988 B)
// PDB source: basegame.cpp
// Attempt log:
// - Baseline was a packet-grounded free-function/raw-offset scaffold; it rebuilt
//   with the right call sequence but had a non-member prologue and wrong imported
//   call surfaces.  The current candidate uses the generated RGE_Base_Game layout,
//   the real virtual-destructor class context, named member setters, and the
//   period string/intrinsic surfaces.
// - Moving the six binary-first member initializations into a natural constructor
//   initializer list reproduced the delayed vptr scheduling and reached MATCH.
// Source audit: the byte-exact variant used __declspec(novtable) plus an explicit
// vptr store; that compiler-steering form is rejected.  The retained virtual
// destructor class and member initializer list are natural and produce the same
// delayed vptr store without an explicit vptr write.
// Declaration probe: packet symbols require _iobuf* and char[260]. The full
// binary-backed virtual surface through +0x140 changed no bytes. Exact setter
// donors preserve their real narrow and wide parameter types. The remaining
// drift starts at the natural implicit vptr store.

#include <string.h>

class RGE_Game_Info;
class RGE_Scenario_File_Info;
class RGE_Prog_Info {
public:
    char gap_00[0x410];
    void* instance;
};
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
struct _iobuf;

class RGE_Timing_Info {
public:
    unsigned long accum_time;
    unsigned long last_time;
    unsigned long start_time;
    int include_in_total;
    int is_summary;
    unsigned long last_single_time;
    unsigned long max_time;
    unsigned long last_max_time;
};

class RGE_Base_Game;

extern "C" __declspec(dllimport) void* __stdcall LoadCursorA(void* instance, const char* cursor);
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentDirectoryA(unsigned long size, char* buffer);

extern int do_draw_log;
extern int safe_draw_log;
extern char draw_log_name[260];
extern _iobuf* draw_log;
extern RGE_Base_Game* rge_base_game;
extern int g_592A58; // AppInst
extern int g_62C4A0; // StringTable
extern int g_62C4A8; // Regs
extern int g_62C4B0; // sound_driver
extern int g_62C4B8; // chat
extern int g_62C4C0; // comm
extern int g_62C4FC; // L
extern int g_5B215Ch; // driveInfo
extern int g_5B2160; // AppWnd
extern int g_5B236C; // comm/global window state
extern int g_62C574; // rge_base_game storage

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
    virtual char* get_string2(int, long, long, char*, int);
    virtual void* get_view_panel();
    virtual void* get_map_panel();
    virtual void* new_scenario_header(void*);
    virtual void* new_scenario_header(int);
    virtual void* new_scenario_info(int);
    virtual void notification(int, long, long, long, long);
    virtual int reset_comm();
    virtual void send_game_options();
    virtual void receive_game_options();
    virtual char* gameSummary();
    virtual int processCheatCode(int, char*);
    virtual int setup_music_system();
    virtual void shutdown_music_system();
    virtual int setup();
    virtual int setup_cmd_options();
    virtual int setup_class();
    virtual int setup_main_window();
    virtual int setup_graphics_system();
    virtual int setup_palette();
    virtual int setup_mouse();
    virtual int setup_registry();
    virtual int setup_debugging_log();
    virtual int setup_chat();
    virtual int setup_comm();
    virtual int setup_sound_system();
    virtual int setup_fonts();
    virtual int setup_sounds();
    virtual int setup_shapes();
    virtual int setup_blank_screen();
    virtual void setup_timings();
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void stop_music_system();
    virtual int restart_music_system();
    virtual void* create_world();
    virtual int handle_message(void*);
    virtual int handle_idle();
    virtual int handle_mouse_move(void*, unsigned int, unsigned int, long);
    virtual int handle_key_down(void*, unsigned int, unsigned int, long);
    virtual int handle_user_command(void*, unsigned int, unsigned int, long);
    virtual int handle_command(void*, unsigned int, unsigned int, long);
    virtual int handle_music_done(void*, unsigned int, unsigned int, long);
    virtual int handle_paint(void*, unsigned int, unsigned int, long);
    virtual int handle_activate(void*, unsigned int, unsigned int, long);
    virtual int handle_init_menu(void*, unsigned int, unsigned int, long);
    virtual int handle_exit_menu(void*, unsigned int, unsigned int, long);
    virtual int handle_size(void*, unsigned int, unsigned int, long);
    virtual int handle_palette_changed(void*, unsigned int, unsigned int, long);
    virtual int handle_query_new_palette(void*, unsigned int, unsigned int, long);
    virtual int handle_close(void*, unsigned int, unsigned int, long);
    virtual int handle_destroy(void*, unsigned int, unsigned int, long);
    virtual int action_update();
    virtual int action_mouse_move(long, long, int, int, int, int);
    virtual int action_key_down(unsigned long, int, int, int, int);
    virtual int action_user_command(unsigned long, unsigned long);
    virtual int action_command(unsigned long, unsigned long);
    virtual int action_music_done();
    virtual int action_activate();
    virtual int action_deactivate();
    virtual int action_init_menu();
    virtual int action_exit_menu();
    virtual int action_size();
    virtual int action_close();
    virtual void calc_timings();
    virtual void calc_timing_text();
    virtual void show_timings();
    virtual void show_comm();
    virtual void show_ai();
    virtual int setup_map_save_area();
    virtual void set_interface_messages();

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
    unsigned char pad_51[3];
    int custom_mouse;
    short shape_num;
    unsigned char pad_5A[2];
    TShape** shapes;
    TSound_Driver* sound_system;
    TMusic_System* music_system;
    short sound_num;
    unsigned char pad_6A[2];
    TDigital** sounds;
    unsigned char save_music_type;
    unsigned char pad_71[3];
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
    unsigned char pad_1E2[2];
    RGE_Font* fonts;
    char work_dir[261];
    char string_dll_name[261];
    unsigned char pad_3F2[2];
    void* world;
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
    char game_options[0xA8];
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
    unsigned char pad_A1E[2];
    TDrawArea* map_save_area;

    RGE_Base_Game(RGE_Prog_Info* info, int do_setup);

    void setVersion(float v);
    void setScenarioGame(unsigned char v);
    void setCampaignGame(int v);
    void setSavedGame(int v);
    void setSinglePlayerGame(int v);
    void setMultiplayerGame(int v);
    void setMapSize(char x, char y, char z);
    void setAllowCheatCodes(unsigned char v);
    void setCheatNotification(unsigned char v);
    void setFullVisibility(unsigned char v);
    void setFogOfWar(unsigned char v);
    void setColoredChat(unsigned char v);
    void setGameDeveloperMode(unsigned char v);
    void setDifficulty(unsigned char v);
    void setPlayerCDAndVersion(int player, unsigned char v);
    void setPlayerHasCD(int player, unsigned char v);
    void setPlayerVersion(int player, unsigned char v);
    void setPlayerTeam(int player, unsigned char v);
    void setPathFinding(unsigned char v);
    void setMpPathFinding(unsigned char v);
    void setNumberPlayers(unsigned char v);
    void setScenarioName(const char* name);
};

RGE_Base_Game::RGE_Base_Game(RGE_Prog_Info* info, int do_setup)
    : player_game_info(0),
      random_game_seed(-1),
      random_map_seed(-1),
      save_random_game_seed(-1),
      save_random_map_seed(-1),
      quick_build(0)
{
    int i;

    do_draw_log = 0;
    safe_draw_log = 0;
    draw_log_name[0] = 0;
    draw_log = 0;

    this->setVersion(1.0f);
    this->setScenarioGame(0);
    this->setCampaignGame(0);
    this->setSavedGame(0);
    this->setSinglePlayerGame(1);
    this->setMultiplayerGame(0);
    this->setMapSize(0x60, 0x60, 8);
    this->setAllowCheatCodes(0);
    this->setCheatNotification(1);
    this->setFullVisibility(0);
    this->setFogOfWar(1);
    this->setColoredChat(1);
    this->setGameDeveloperMode(0);
    this->setDifficulty(0);

    for (i = 0; i < 9; i++) {
        this->setPlayerCDAndVersion(i, 0);
        this->setPlayerHasCD(i, 0);
        this->setPlayerVersion(i, 0);
        this->setPlayerTeam(i, 1);
    }

    this->setPathFinding(0);
    this->setMpPathFinding(0);
    this->setNumberPlayers(4);
    this->setScenarioName((const char*)0x592A40);

    rge_base_game = this;
    this->prog_info = info;
    this->prog_window = 0;
    this->prog_ready = 0;
    this->prog_active = 1;
    this->prog_palette = 0;
    this->window_style = 0;
    g_62C4A0 = 0;
    this->screen_saver_enabled = 0;
    this->error_code = 0;
    this->is_timer = 0;
    this->draw_system = 0;
    this->draw_area = 0;
    this->outline_type = 2;
    this->custom_mouse = 0;
    this->shapes = 0;
    this->sound_system = 0;
    this->music_system = 0;
    this->sound_num = 0;
    this->sounds = 0;
    this->save_music_type = 0;
    this->save_music_track_from = 0;
    this->save_music_track_to = 0;
    this->save_music_cur_track = 0;
    this->save_music_file[0] = 0;
    this->save_music_loop = 0;
    this->save_music_pos = 0;
    this->comm_handler = 0;
    this->debugLog = 0;
    this->log_comm = 0;
    this->comm_syncstop = 0;
    this->comm_syncmsg = 0;
    this->comm_stepmode = 0;
    this->comm_speed = 1;
    this->comm_droppackets = 0;
    this->registry = 0;
    this->prog_mode = 0;
    this->game_mode = 0;
    this->sub_game_mode = 0;
    this->paused = 0;
    this->mouse_pointer = 0;
    this->erase_mouse = 0;
    this->mouse_blit_sync = 0;
    this->is_mouse_on = 1;
    this->windows_mouse = 1;
    this->mouse_cursor = LoadCursorA(0, (const char*)0x7F00);
    this->font_num = 0;
    this->fonts = 0;
    GetCurrentDirectoryA(0x105, this->work_dir);

    strcpy(this->string_dll_name, (const char*)0x57FA10);

    this->master_obj_id = -1;
    this->terrain_id = -1;
    this->elevation_height = -1;
    this->world = 0;
    this->render_all = 1;
    this->brush_size = 1;
    this->timing_text[0] = 0;
    this->frame_count = 0;
    this->world_update_count = 0;
    this->view_update_count = 0;
    this->last_frame_count = 0;
    this->last_world_update_count = 0;
    this->last_view_update_count = 0;
    this->fps = 0;
    this->world_update_fps = 0;
    this->view_update_fps = 0;
    this->last_view_time = 0;

    for (i = 0; i < 30; i++) {
        this->timings[i].accum_time = 0;
        this->timings[i].last_time = 0;
        this->timings[i].start_time = 0;
        this->timings[i].last_single_time = 0;
        this->timings[i].max_time = 0;
        this->timings[i].last_max_time = 0;
        this->timings[i].include_in_total = 0;
        this->timings[i].is_summary = 0;
    }

    this->do_show_timings = 0;
    this->do_show_comm = 0;
    this->do_show_ai = 0;
    this->save_check_for_cd = 1;
    g_62C4FC = 0;
    g_592A58 = (int)this->prog_info->instance;
    g_5B236C = 0;
    g_62C4B8 = 0;
    g_62C4C0 = 0;
    g_62C4A8 = 0;
    g_62C4B0 = 0;
    g_5B215Ch = 0;
    this->scenario_info = 0;
    for (i = 0; i < 9; i++) {
        this->playerIDValue[i] = 0;
        this->resigned[i] = 0;
    }
    this->auto_paused = 0;
    this->rollover = 1;
    this->map_save_area = 0;
    this->game_speed = 1.0f;
    this->single_player_difficulty = 2;

    if (!this->setup_registry()) {
        this->error_code = 0x0E;
        return;
    }
    g_62C4A8 = (int)this->registry;
    if (!this->setup_debugging_log()) {
        this->error_code = 0x0F;
        return;
    }
    g_62C4FC = (int)this->debugLog;
    if (do_setup) {
        if (!this->setup()) {
            if (!this->error_code)
                this->error_code = 1;
        }
    }
    this->display_selected_ids = 0;
}
