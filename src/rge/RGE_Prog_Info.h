#pragma once
#include <windows.h>
#include <stddef.h>

struct RGE_Prog_Info {
    /* 0x0000 */ char prog_name[101];
    /* 0x0065 */ char prog_version[21];
    /* 0x007A */ char prog_title[121];
    /* 0x00F3 */ char world_db_file[261];
    /* 0x01F8 */ char game_data_file[261];
    /* 0x02FD */ char vol_name[261];
    
    // Offset 0x0402 (1026). Next int must align to 4 bytes (0x0404).
    // Implicit Padding: 2 bytes
    
    /* 0x0404 */ unsigned long vol_ser_num;
    /* 0x0408 */ int verify_cd;
    /* 0x040C */ int max_players_per_cd;
    /* 0x0410 */ void *instance;
    /* 0x0414 */ void *prev_instance;
    /* 0x0418 */ char registry_key[256];
    /* 0x0518 */ char cmd_line[256];
    /* 0x0618 */ int show_wnd_flag;
    /* 0x061C */ char icon_name[41];
    /* 0x0645 */ char menu_name[41];
    /* 0x066E */ char pal_file[261];
    /* 0x0773 */ char cursor_file[261];
    
    // Offset 0x0878 (2168). Aligned (2168 % 4 == 0).
    /* 0x0878 */ int max_players;
    /* 0x087C */ int check_expiration;
    /* 0x0880 */ short expire_month;
    /* 0x0882 */ short expire_day;
    /* 0x0884 */ short expire_year;
    
    // Offset 0x0886 (2182). Next ulong align to 0x0888.
    // Implicit Padding: 2 bytes
    
    /* 0x0888 */ unsigned long update_interval;
    /* 0x088C */ int check_multi_copies;
    /* 0x0890 */ int skip_startup;
    /* 0x0894 */ int full_screen;
    /* 0x0898 */ int fixed_window_size;
    /* 0x089C */ int use_dir_draw;
    /* 0x08A0 */ int use_sys_mem;
    /* 0x08A4 */ int use_music;
    /* 0x08A8 */ int use_sound;
    /* 0x08AC */ int use_cd_audio;
    /* 0x08B0 */ int use_ima;
    /* 0x08B4 */ int use_midi;
    /* 0x08B8 */ int use_wave_music;
    /* 0x08BC */ int fast_view;
    /* 0x08C0 */ int auto_scroll;
    /* 0x08C4 */ long mouse_scroll_edge;
    /* 0x08C8 */ unsigned long mouse_scroll_interval;
    /* 0x08CC */ float mouse_scroll_max_dist;
    /* 0x08D0 */ unsigned long key_scroll_interval;
    /* 0x08D4 */ float key_scroll_max_dist;
    /* 0x08D8 */ float key_scroll_object_move;
    /* 0x08DC */ short interface_style;
    
    // Offset 0x08DE. Next long align to 0x08E0.
    // Implicit Padding: 2 bytes
    
    /* 0x08E0 */ long main_wid;
    /* 0x08E4 */ long main_hgt;
    
    /* 0x08E8 */ GUID game_guid;
    /* 0x08F8 */ GUID zone_guid;
    
    /* 0x0908 */ char data_dir[261];
    /* 0x0A0D */ char graphics_dir[261];
    /* 0x0B12 */ char save_dir[261];
    /* 0x0C17 */ char scenario_dir[261];
    /* 0x0D1C */ char campaign_dir[261];
    /* 0x0E21 */ char sounds_dir[261];
    /* 0x0F26 */ char resource_dir[261];
    /* 0x102B */ char ai_dir[261];
    /* 0x1130 */ char avi_dir[261];
    
    // End 0x1235 (4661). 
    // Struct alignment (largest member is 4 bytes or GUID 4-byte align) -> Pad to 0x1238.
};

// MANDATORY VERIFICATION
static_assert(sizeof(RGE_Prog_Info) == 0x1238, "RGE_Prog_Info size mismatch");
static_assert(offsetof(RGE_Prog_Info, vol_ser_num) == 0x0404, "RGE_Prog_Info::vol_ser_num offset mismatch (Padding Error 1)");
static_assert(offsetof(RGE_Prog_Info, game_guid) == 0x08E8, "RGE_Prog_Info::game_guid offset mismatch (Padding Error 2)");
static_assert(offsetof(RGE_Prog_Info, avi_dir) == 0x1130, "RGE_Prog_Info::avi_dir offset mismatch");