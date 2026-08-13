// Attempt log:
// try 7: reset the decompiler-shaped local and fake app surface to the period
// RGE_Prog_Info and TRIBE_Game ownership model.  The source now names every
// initialized field and uses the observed virtual calls and delete path.
// probe: initial get_error_code is the constructor-result test; run is only
// called for a zero result, followed by the final get_error_code.
// probe: the error dialog passes the initial result to get_string2.
// probe: error_code is initialized after the early string setup to preserve
// the original zero register and stack-home schedule.

#include <stdio.h>
#include <string.h>
#include <windows.h>

void* __cdecl operator new(unsigned int size);

class RGE_Prog_Info {
public:
    char prog_name[101];
    char prog_version[21];
    char prog_title[121];
    char world_db_file[261];
    char game_data_file[261];
    char vol_name[261];
    unsigned char pad_402[2];
    unsigned long vol_ser_num;
    int verify_cd;
    int max_players_per_cd;
    HINSTANCE instance;
    HINSTANCE prev_instance;
    char registry_key[256];
    char cmd_line[256];
    int show_wnd_flag;
    char icon_name[41];
    char menu_name[41];
    char pal_file[261];
    char cursor_file[261];
    int max_players;
    int check_expiration;
    short expire_month;
    short expire_day;
    short expire_year;
    unsigned char pad_886[2];
    unsigned long update_interval;
    int check_multi_copies;
    int skip_startup;
    int full_screen;
    int fixed_window_size;
    int use_dir_draw;
    int use_sys_mem;
    int use_music;
    int use_sound;
    int use_cd_audio;
    int use_ima;
    int use_midi;
    int use_wave_music;
    int fast_view;
    int auto_scroll;
    long mouse_scroll_edge;
    unsigned long mouse_scroll_interval;
    float mouse_scroll_max_dist;
    unsigned long key_scroll_interval;
    float key_scroll_max_dist;
    float key_scroll_object_move;
    short interface_style;
    unsigned char pad_8de[2];
    long main_wid;
    long main_hgt;
    GUID game_guid;
    GUID zone_guid;
    char data_dir[261];
    char graphics_dir[261];
    char save_dir[261];
    char scenario_dir[261];
    char campaign_dir[261];
    char sounds_dir[261];
    char resource_dir[261];
    char ai_dir[261];
    char avi_dir[261];
    unsigned char pad_end[3];
};

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
    char base_size[0xA20];
};

class TRIBE_Game : public RGE_Base_Game {
public:
    virtual ~TRIBE_Game();
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
    char game_size[0x830];

    TRIBE_Game(RGE_Prog_Info*, int);
};

extern "C" int __stdcall WinMain(HINSTANCE hInst, HINSTANCE hPrev,
                                  char* cmdLine, int nShow)
{
    int error_code;
    TRIBE_Game* game;
    RGE_Prog_Info info;
    char title[256];
    char msg[256];

    strcpy(info.prog_name, "Age of Empires, Roman Expansion");
    strcpy(info.prog_version, "00.03.01.0717");
    sprintf(info.prog_title, "%s", info.prog_name);
    strcpy(info.world_db_file, "tr_wrld.txt");
    strcpy(info.game_data_file, "data2\\empires.dat");
    strcpy(info.registry_key,
           "Software\\Microsoft\\Games\\Age of Empires\\1.00");
    strcpy(info.cmd_line, cmdLine);
    strcpy(info.icon_name, "AppIcon");
    strcpy(info.menu_name, "");
    strcpy(info.pal_file, "palette");
    strcpy(info.cursor_file, "mcursors");
    error_code = 0;
    strcpy(info.vol_name, "AOE");

    info.instance = hInst;
    info.prev_instance = hPrev;
    info.show_wnd_flag = nShow;

    info.mouse_scroll_interval = 0x54;
    info.mouse_scroll_max_dist = 4.0f;
    info.key_scroll_interval = 0x54;
    info.key_scroll_max_dist = 4.0f;
    info.key_scroll_object_move = 0.05f;
    info.interface_style = 2;
    info.main_wid = 800;
    info.main_hgt = 600;

    info.game_guid.Data1 = 0x60009B83;
    info.game_guid.Data2 = 0x46A8;
    info.game_guid.Data3 = 0xF2E8;
    info.game_guid.Data4[0] = 0xE2;
    info.game_guid.Data4[1] = 0xEB;
    info.game_guid.Data4[2] = 0xD1;
    info.game_guid.Data4[3] = 0x11;
    info.game_guid.Data4[4] = 0x83;
    info.game_guid.Data4[5] = 0x9B;
    info.game_guid.Data4[6] = 0;
    info.game_guid.Data4[7] = 0x60;

    info.zone_guid.Data1 = 0x08F50797;
    info.zone_guid.Data2 = 0x46AA;
    info.zone_guid.Data3 = 0xF2E8;
    info.zone_guid.Data4[0] = 0xE2;
    info.zone_guid.Data4[1] = 0xEB;
    info.zone_guid.Data4[2] = 0xD1;
    info.zone_guid.Data4[3] = 0x11;
    info.zone_guid.Data4[4] = 0x83;
    info.zone_guid.Data4[5] = 0x9B;
    info.zone_guid.Data4[6] = 0;
    info.zone_guid.Data4[7] = 0x60;

    info.vol_ser_num = 0;
    info.verify_cd = 1;
    info.max_players_per_cd = 3;
    info.max_players = 8;
    info.check_expiration = 0;
    info.expire_month = 0;
    info.expire_day = 0;
    info.expire_year = 0;
    info.update_interval = 1;
    info.check_multi_copies = 1;
    info.skip_startup = 0;
    info.full_screen = 0;
    info.fixed_window_size = 0;
    info.use_dir_draw = 1;
    info.use_sys_mem = 1;
    info.use_music = 0;
    info.use_sound = 1;
    info.use_cd_audio = 1;
    info.use_ima = 1;
    info.use_midi = 0;
    info.use_wave_music = 1;
    info.fast_view = 1;
    info.auto_scroll = 1;
    info.mouse_scroll_edge = 0;
    info.mouse_scroll_interval = 0;
    info.mouse_scroll_max_dist = 0;
    info.key_scroll_interval = 0;
    info.key_scroll_max_dist = 1.0f;
    info.key_scroll_object_move = 1.0f;
    info.interface_style = 3;

    strcpy(info.data_dir, "data2\\");
    strcpy(info.graphics_dir, "");
    strcpy(info.save_dir, "savegame\\");
    strcpy(info.scenario_dir, "scenario\\");
    strcpy(info.campaign_dir, "campaign\\");
    strcpy(info.sounds_dir, "sound\\");
    strcpy(info.resource_dir, "data2\\");
    strcpy(info.ai_dir, "data2\\");
    strcpy(info.avi_dir, "avi\\");

    game = new TRIBE_Game(&info, 1);
    if (game != 0) {
        int result = game->get_error_code();
        if (result == 0) {
            game->run();
            error_code = game->get_error_code();
            delete game;
        }
        else if (result != 4) {
            game->get_string(0x7D1, title, 0x100);
            game->get_string2(1, result, 0, msg, 0x100);
            delete game;
            MessageBoxA(0, msg, title, 0x10);
        }
    }
    return error_code;
}
