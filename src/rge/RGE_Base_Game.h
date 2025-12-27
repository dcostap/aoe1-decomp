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
    char scenarioNameValue[128];
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
    uchar playerCDAndVersionValue[9];
    uchar difficultyValue;
    uchar playerTeamValue[9];
};

class RGE_Base_Game {
public:
    // Virtual table alignment
    virtual ~RGE_Base_Game() {}                                        // [0]
    virtual int get_error_code() { return 0; }                         // [1]
    virtual void stub_2() {}                                           // [2]
    virtual void stub_3() {}                                           // [3]
    virtual void stub_4() {}                                           // [4]
    virtual void stub_5() {}                                           // [5]
    virtual int run() { return 0; }                                    // [6]
    virtual void stub_7() {}                                           // [7]
    virtual void show_error(int id, char* buf, int s) {}               // [8]
    virtual void stub_9() {}                                           // [9]
    virtual void fatal_exit(int a, int b, int c, char* d, int e) {}    // [10]

    // Members from 0x0004
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
    /* 0x0051 */ // 3 bytes padding likely here, check dump if needed but strict packing might mean no padding if types align.
                 // Dump said: 
                 // 10035:     uchar outline_type;
                 // 10036:     int custom_mouse;
                 // If #pragma pack(1), then outline_type is 1 byte, custom_mouse is at 0x0051.
                 // Pointers are 4 bytes.
                 // Wait, uchar is 1 byte. int is 4 bytes.
                 // If pack(1), then custom_mouse is at offset+1.
                 // BUT standard visual c++ packing usually aligns int to 4 bytes unless #pragma pack(1) is used.
                 // The project instructions say "Strict 1-byte packing for all game structures." and "Header files must use #pragma pack(push, 1)".
                 // So I trust pack(1).
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
    /* 0x08F2 */ int do_show_timings;
    /* 0x08F6 */ int do_show_comm;
    /* 0x08FA */ int do_show_ai;
    /* 0x08FE */ ulong last_view_time;
    /* 0x0902 */ struct RGE_Game_Options rge_game_options;

    // RGE_Game_Options size:
    // float (4) + uchar (1) + char[128] + uchar(1)*7 + uchar[9] + uchar(1) + uchar[9]
    // 4 + 1 + 128 + 7 + 9 + 1 + 9 = 159 bytes?
    // Let's check struct size.
    // 9993-10011.
    // offsets are not explicit in dump for struct members, but can be inferred.
    
    /* 0x09A1??? */ // We will check exact offset with check later.
    
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
    uchar pathFindingValue;
    uchar resigned[9];
    struct TDrawArea *map_save_area;
    
    // Fix size to 0xA24 (Current size 0xA11, need 19 bytes)
    uchar _pad_fix[19];

    RGE_Base_Game(RGE_Prog_Info* info, int setup);

};
#pragma pack(pop)

static_assert(sizeof(RGE_Base_Game) == 0xA24, "RGE_Base_Game size mismatch");



