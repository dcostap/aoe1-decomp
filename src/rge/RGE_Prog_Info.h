#pragma once
#include "../types.h"

// Address: 004549e0 (Mapping from WinMain Stack)
#pragma pack(push, 1)
struct RGE_Prog_Info {
    /* 0x0000 */ char prog_name[101];
    /* 0x0065 */ char prog_version[21];
    /* 0x007a */ char prog_title[121];
    /* 0x00f3 */ char world_db_file[261];
    /* 0x01f8 */ char game_data_file[261];
    /* 0x02fd */ char vol_name[261];
    /* 0x0402 */ uchar _pad_402[2];
    /* 0x0404 */ ulong vol_ser_num;
    /* 0x0408 */ int verify_cd;
    /* 0x040c */ int max_players_per_cd;
    /* 0x0410 */ void* instance;
    /* 0x0414 */ void* prev_instance;
    /* 0x0418 */ char registry_key[256];
    /* 0x0518 */ char cmd_line[256];
    /* 0x0618 */ int show_wnd_flag;
    /* 0x061c */ char icon_name[41];
    /* 0x0645 */ char menu_name[41];
    /* 0x066e */ char pal_file[261];
    /* 0x0773 */ char cursor_file[261];
    /* 0x0878 */ int max_players;
    /* 0x087c */ int check_expiration;
    /* 0x0880 */ short expire_month;
    /* 0x0882 */ short expire_day;
    /* 0x0884 */ short expire_year;
    /* 0x0886 */ uchar _pad_886[2];
    /* 0x0888 */ ulong update_interval;
    /* 0x088c */ int check_multi_copies;
    /* 0x0890 */ int skip_startup;
    /* 0x0894 */ int full_screen;
    /* 0x0898 */ int fixed_window_size;
    /* 0x089c */ int use_dir_draw;
    /* 0x08a0 */ int use_sys_mem;
    /* 0x08a4 */ int use_music;
    /* 0x08a8 */ int use_sound;
    /* 0x08ac */ int use_cd_audio;
    /* 0x08b0 */ int use_ima;
    /* 0x08b4 */ int use_midi;
    /* 0x08b8 */ int use_wave_music;
    /* 0x08bc */ int fast_view;
    /* 0x08c0 */ int auto_scroll;
    /* 0x08c4 */ long mouse_scroll_edge;
    /* 0x08c8 */ ulong mouse_scroll_interval;
    /* 0x08cc */ float mouse_scroll_max_dist;
    /* 0x08d0 */ ulong key_scroll_interval;
    /* 0x08d4 */ float key_scroll_max_dist;
    /* 0x08d8 */ float key_scroll_object_move;
    /* 0x08dc */ short interface_style;
    /* 0x08de */ uchar _pad_8de[2];
    /* 0x08e0 */ long main_wid;
    /* 0x08e4 */ long main_hgt;
    /* 0x08e8 */ GUID game_guid;
    /* 0x08f8 */ GUID zone_guid;
    /* 0x0908 */ char data_dir[261];
    /* 0x0a0d */ char graphics_dir[261];
    /* 0x0b12 */ char save_dir[261];
    /* 0x0c17 */ char scenario_dir[261];
    /* 0x0d1c */ char campaign_dir[261];
    /* 0x0e21 */ char sounds_dir[261];
    /* 0x0f26 */ char resource_dir[261];
    /* 0x102b */ char ai_dir[261];
    /* 0x1130 */ char avi_dir[261];
};
#pragma pack(pop)