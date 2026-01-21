#pragma once
#include <windows.h>
#include "common.h"

#pragma pack(push, 1)
struct RGE_Prog_Info {
    class TRIBE_Game* prog_game_ptr; // 0x0000
    char prog_name_init[101];   // 0x0004
    char prog_version[21];      // 0x0069
    char prog_title[121];       // 0x007E
    char world_db_file[261];    // 0x00F7
    char game_data_file[261];   // 0x01FC
    char vol_name[261];         // 0x0301
    unsigned long vol_ser_num;  // 0x0406
    int verify_cd;              // 0x040A
    int max_players_per_cd;     // 0x040E
    void* instance;             // 0x0412
    void* prev_instance;        // 0x0416
    char _pad0[2];              // 0x041A
    char registry_key[256];     // 0x041C
    char cmd_line[260];         // 0x051C
    char icon_name[41];         // 0x0620
    char menu_name[41];         // 0x0649
    char pal_file[261];         // 0x0672
    char cursor_file[261];      // 0x0777
    int show_wnd_flag;          // 0x087C
    int max_players;            // 0x0880
    int check_expiration;       // 0x0884
    int expire_month;           // 0x0888
    short expire_day;           // 0x088C
    short expire_year;          // 0x088E
    unsigned long update_interval; // 0x0890
    int check_multi_copies;     // 0x0894
    int skip_startup;           // 0x0898
    int full_screen;            // 0x089C
    int fixed_window_size;      // 0x08A0
    int use_dir_draw;           // 0x08A4
    int use_sys_mem;            // 0x08A8
    int use_music;              // 0x08AC
    int use_sound;              // 0x08B0
    int use_cd_audio;           // 0x08B4
    int auto_scroll;            // 0x08B8
    int mouse_scroll_edge;      // 0x08BC
    unsigned long mouse_scroll_interval; // 0x08C0
    unsigned long key_scroll_interval;   // 0x08C4
    float mouse_scroll_max_dist;         // 0x08C8
    float key_scroll_max_dist;           // 0x08CC
    float key_scroll_object_move;        // 0x08D0
    int use_ima;                // 0x08D4
    int use_midi;               // 0x08D8
    int use_wave_music;         // 0x08DC
    int fast_view;              // 0x08E0
    short interface_style;      // 0x08E4
    short main_wid;             // 0x08E6
    long main_hgt;              // 0x08E8
    GUID game_guid;             // 0x08EC
    GUID zone_guid;             // 0x08FC
    char data_dir[261];         // 0x090C
    char graphics_dir[261];     // 0x0A11
    char save_dir[261];         // 0x0B16
    char scenario_dir[261];     // 0x0C1B
    char campaign_dir[261];     // 0x0D20
    char sounds_dir[261];       // 0x0E23
    char resource_dir[261];     // 0x0F2A
    char ai_dir[261];           // 0x102F
    char avi_dir[260];          // 0x1134
};
#pragma pack(pop)
static_assert(sizeof(RGE_Prog_Info) == 0x1238, "Size mismatch");
