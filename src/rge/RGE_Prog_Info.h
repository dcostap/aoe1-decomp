#pragma once
#include "../types.h"

struct RGE_Prog_Info {
    // String Members (Used in main.cpp)
    /* 0x0000 */ char prog_name[128];
    /* 0x0080 */ char prog_version[128];
    /* 0x0100 */ char prog_title[128];
    /* 0x0180 */ char world_db_file[128];
    /* 0x0200 */ char game_data_file[128];
    /* 0x0280 */ char registry_key[128];
    /* 0x0300 */ char icon_name[128];
    /* 0x0380 */ char menu_name[128];
    /* 0x0400 */ char pal_file[128];
    /* 0x0480 */ char cursor_file[128];
    /* 0x0500 */ char vol_name[128];
    /* 0x0580 */ char data_dir[128];
    /* 0x0600 */ char sounds_dir[128];
    /* 0x0680 */ char graphics_dir[128];
    /* 0x0700 */ char save_dir[128];
    /* 0x0780 */ char scenario_dir[128];
    /* 0x0800 */ char campaign_dir[128];
    /* 0x0880 */ char resource_dir[128];
    /* 0x0900 */ char ai_dir[128];
    /* 0x0980 */ char avi_dir[128];
    
    /* 0x0A00 */ GUID game_guid;
    /* 0x0A10 */ GUID zone_guid;
    
    /* 0x0A20 */ void *instance;
    /* 0x0A24 */ void *prev_instance;
    /* 0x0A28 */ int show_wnd_flag;
    /* 0x0A2C */ char cmd_line[256];
    
    /* 0x0B2C */ int verify_cd;
    /* 0x0B30 */ int max_players_per_cd;
    /* 0x0B34 */ int check_expiration;
    /* 0x0B38 */ int expire_month;
    /* 0x0B3C */ int expire_day;
    /* 0x0B40 */ int expire_year;
    /* 0x0B44 */ int check_multi_copies;
    /* 0x0B48 */ int skip_startup;
    /* 0x0B4C */ int full_screen;
    /* 0x0B50 */ int fixed_window_size;
    /* 0x0B54 */ int use_dir_draw;
    /* 0x0B58 */ int use_sys_mem;
    /* 0x0B5C */ int use_music;
    /* 0x0B60 */ int use_sound;
    /* 0x0B64 */ int use_cd_audio;
    /* 0x0B68 */ int auto_scroll;
    /* 0x0B6C */ int mouse_scroll_edge;
    /* 0x0B70 */ int mouse_scroll_interval;
    /* 0x0B74 */ int key_scroll_interval;
    /* 0x0B78 */ float key_scroll_object_move;
    /* 0x0B7C */ int interface_style;
    /* 0x0B80 */ int main_wid;
    /* 0x0B84 */ int main_hgt;
    
    // Total size reached: 0x0B88. 
    // We need 0x1238 = 4664.
    // Padding:
    /* 0x0B88 */ char padding[0x1238 - 0x0B88];
};

static_assert(sizeof(RGE_Prog_Info) == 0x1238, "RGE_Prog_Info size mismatch");