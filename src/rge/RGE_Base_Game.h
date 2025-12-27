#pragma once

#include "../types.h"

#pragma pack(push, 1)

struct RGE_Timing_Info {
    ulong accum_time;
    ulong last_time;
    ulong start_time;
    int include_in_total;
    int is_summary;
    ulong last_single_time;
    ulong max_time;
    ulong last_max_time;
};

struct RGE_Game_Options {
    float versionValue;
    uchar scenarioGameValue;
    char scenarioNameValue[124];
    uchar singlePlayerGameValue;
    uchar multiplayerGameValue;
    uchar mapXSizeValue;
    uchar mapYSizeValue;
    uchar mapZSizeValue;
    uchar allowCheatCodesValue;
    uchar mpPathFindingValue;
    uchar cheatNotificationValue;
    uchar fullVisibilityValue;
    uchar fogOfWarValue;
    uchar coloredChatValue;
    uchar numberPlayersValue;
    uchar gameDeveloperModeValue;
    uchar playerCDAndVersionValue[8];
    uchar difficultyValue;
    uchar playerTeamValue[8];
};

class RGE_Base_Game {
public:
    // Virtual table alignment (vptr at 0x0000)
    virtual ~RGE_Base_Game();                                          // [0]
    virtual int get_error_code();                                      // [1]
    virtual long wnd_proc(HWND hwnd, uint msg, WPARAM wparam, LPARAM lparam); // [2]
    virtual void stub_3(int a) {}                                      // [3]
    virtual void stub_4() {}                                           // [4]
    virtual void stub_5() {}                                           // [5]
    virtual int run();                                                 // [6]
    virtual void stub_7() {}                                           // [7]
    virtual void show_error(int id, char* buf, int s) {}               // [8]
    virtual void stub_9() {}                                           // [9]
    virtual void fatal_exit(int a, int b, int c, char* d, int e) {}    // [10]
    virtual void stub_11() {}
    virtual void stub_12() {}
    virtual void stub_13() {}
    virtual void stub_14() {}
    virtual void stub_15() {}
    virtual void stub_16() {}
    virtual void stub_17() {}
    virtual void stub_18() {}
    virtual void stub_19() {}
    virtual void stub_20() {}
    virtual void stub_21() {}
    virtual void stub_22() {}
    virtual void stub_23() {}
    virtual void stub_24() {}                                          // [24]
    virtual int setup_class();                                         // [25]
    virtual int setup_main_window();                                   // [26]
    virtual int setup_graphics_system();                               // [27]
    virtual int setup_palette();                                       // [28]
    virtual int setup_mouse();                                         // [29]
    virtual int setup_chat();                                          // [30]
    virtual void stub_31() {}
    virtual void stub_32() {}
    virtual int setup_sounds();                                        // [33]
    virtual int setup_music_system();                                  // [34]
    virtual int setup_sound_system();                                  // [35]
    virtual int setup_comm();                                          // [36]
    virtual int setup_blank_screen();                                  // [37]
    virtual int setup_shapes();                                        // [38]
    virtual void stub_39() {}
    virtual void stub_40() {}
    virtual void paint_activate() {}                                   // [41]
    virtual void paint_deactivate() {}                                 // [42]
    virtual void stub_43() {}
    virtual void stub_44() {}
    virtual void stub_45() {}
    virtual int handle_message(tagMSG* msg);                           // [46]
    virtual int handle_idle();                                         // [47]
    virtual void stub_48() {}
    virtual void key_down(uint key, uint flags) {}                     // [49]
    virtual void stub_50() {}
    virtual void command(uint id, uint code) {}                        // [51]
    virtual void stub_52() {}
    virtual void paint(HWND hwnd, uint msg, WPARAM wparam, LPARAM lparam); // [53]
    virtual void activate(HWND hwnd, uint msg, WPARAM wparam, LPARAM lparam) {} // [54]
    virtual void stub_55() {}
    virtual void stub_56() {}
    virtual void size(HWND hwnd, uint msg, WPARAM wparam, LPARAM lparam) {} // [57]
    virtual void stub_58() {}
    virtual void stub_59() {}
    virtual void close(HWND hwnd, uint msg, WPARAM wparam, LPARAM lparam); // [60]
    virtual void destroy(HWND hwnd, uint msg, WPARAM wparam, LPARAM lparam); // [61]
    virtual void stub_62() {}
    virtual void stub_63() {}
    virtual void stub_64() {}
    virtual void stub_65() {}
    virtual void stub_66() {}
    virtual void stub_67() {}
    virtual void stub_68() {}
    virtual void stub_69() {}
    virtual void stub_70() {}
    virtual void stub_71() {}
    virtual void stub_72() {}
    virtual void stub_73() {}
    virtual void stub_74() {}
    virtual void stub_75() {}
    virtual void stub_76() {}
    virtual void stub_77() {}
    virtual void stub_78() {}
    virtual int setup_fonts();                                         // [79]
    virtual int setup_map_save_area();                                 // [80]
    virtual void stub_81() {}

    // Members
    /* 0x0004 */ struct RGE_Game_Info *player_game_info;
    /* 0x0008 */ struct RGE_Scenario_File_Info *scenario_info;
    /* 0x000C */ struct RGE_Prog_Info *prog_info;
    /* 0x0010 */ void *prog_window;
    /* 0x0014 */ int prog_ready;
    /* 0x0018 */ int prog_active;
    /* 0x001C */ void *prog_palette;
    /* 0x0020 */ void *prog_mutex;
    /* 0x0024 */ long window_style;
    /* 0x0028 */ int random_game_seed;
    /* 0x002C */ int random_map_seed;
    /* 0x0030 */ int save_random_game_seed;
    /* 0x0034 */ int save_random_map_seed;
    /* 0x0038 */ int screen_saver_enabled;
    /* 0x003C */ int low_power_enabled;
    /* 0x0040 */ int error_code;
    /* 0x0044 */ int is_timer;
    /* 0x0048 */ struct TDrawSystem *draw_system;
    /* 0x004C */ struct TDrawArea *draw_area;
    /* 0x0050 */ uchar outline_type;
    /* 0x0051 */ int custom_mouse;
    /* 0x0055 */ short shape_num;
    /* 0x0057 */ struct TShape **shapes;
    /* 0x005B */ struct TSound_Driver *sound_system;
    /* 0x005F */ struct TMusic_System *music_system;
    /* 0x0063 */ short sound_num;
    /* 0x0065 */ struct TDigital **sounds;
    /* 0x0069 */ uchar save_music_type;
    /* 0x006A */ int save_music_track_from;
    /* 0x006E */ int save_music_track_to;
    /* 0x0072 */ int save_music_cur_track;
    /* 0x0076 */ char save_music_file[260];
    /* 0x017A */ int save_music_loop;
    /* 0x017E */ ulong save_music_pos;
    /* 0x0182 */ struct TCommunications_Handler *comm_handler;
    /* 0x0186 */ int comm_syncstop;
    /* 0x018A */ int comm_droppackets;
    /* 0x018E */ int comm_syncmsg;
    /* 0x0192 */ int comm_stepmode;
    /* 0x0196 */ int comm_speed;
    /* 0x019A */ struct TDebuggingLog *debugLog;
    /* 0x019E */ int log_comm;
    /* 0x01A2 */ struct TRegistry *registry;
    /* 0x01A6 */ int prog_mode;
    /* 0x01AA */ int game_mode;
    /* 0x01AE */ int sub_game_mode;
    /* 0x01B2 */ int paused;
    /* 0x01B6 */ struct TMousePointer *mouse_pointer;
    /* 0x01BA */ int erase_mouse;
    /* 0x01BE */ int mouse_blit_sync;
    /* 0x01C2 */ int is_mouse_on;
    /* 0x01C6 */ int windows_mouse;
    /* 0x01CA */ void *mouse_cursor;
    /* 0x01CE */ int input_enabled;
    /* 0x01D2 */ void *input_disabled_window;
    /* 0x01D6 */ short font_num;
    /* 0x01D8 */ struct RGE_Font *fonts;
    /* 0x01DC */ char work_dir[261];
    /* 0x02E1 */ char string_dll_name[261];
    /* 0x03E6 */ struct RGE_Game_World *world;
    /* 0x03EA */ int render_all;
    /* 0x03EE */ short master_obj_id;
    /* 0x03F0 */ short terrain_id;
    /* 0x03F2 */ short elevation_height;
    /* 0x03F4 */ short brush_size;
    /* 0x03F6 */ char timing_text[256];
    /* 0x04F6 */ ulong frame_count;
    /* 0x04FA */ ulong world_update_count;
    /* 0x04FE */ ulong view_update_count;
    /* 0x0502 */ ulong last_frame_count;
    /* 0x0506 */ ulong last_world_update_count;
    /* 0x050A */ ulong last_view_update_count;
    /* 0x050E */ ulong fps;
    /* 0x0512 */ ulong world_update_fps;
    /* 0x0516 */ ulong view_update_fps;
    /* 0x051A */ struct RGE_Timing_Info timings[30];
    /* 0x08DA */ uchar _pad_timings[24];
    /* 0x08F2 */ int do_show_timings;
    /* 0x08F6 */ int do_show_comm;
    /* 0x08FA */ int do_show_ai;
    /* 0x08FE */ ulong last_view_time;
    /* 0x0902 */ struct RGE_Game_Options rge_game_options;
    /* 0x09A1 */ int campaignGameValue;
    /* 0x09A5 */ int savedGameValue;
    /* 0x09A9 */ int quick_build;
    /* 0x09AD */ int save_check_for_cd;
    /* 0x09B1 */ int playerIDValue[9];
    /* 0x09D5 */ int display_selected_ids;
    /* 0x09D9 */ long countdown_timer[9];
    /* 0x09FD */ int auto_paused;
    /* 0x0A01 */ int save_paused;
    /* 0x0A05 */ int non_user_pause;
    /* 0x0A09 */ int rollover;
    /* 0x0A0D */ float game_speed;
    /* 0x0A11 */ int single_player_difficulty;
    /* 0x0A15 */ uchar pathFindingValue;
    /* 0x0A16 */ uchar resigned[9];
    /* 0x0A1F */ struct TDrawArea *map_save_area;
    /* 0x0A23 */ uchar _pad_fix;

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

    int setup_registry();
    int setup_debugging_log();
    virtual int setup();
    virtual int setup_cmd_options();

    // Getters for bitfields/properties if needed
    uchar pathFinding() const { return this->pathFindingValue; }
    uchar mpPathFinding() const { return this->rge_game_options.mpPathFindingValue; }

};
#pragma pack(pop)

extern RGE_Base_Game *rge_base_game;

static_assert(sizeof(RGE_Base_Game) == 0xA24, "RGE_Base_Game size mismatch");




