// Attempt log:
// try 7: reset the decompiler-shaped local and fake app surface to the period
// RGE_Prog_Info and TRIBE_Game ownership model.  The source now names every
// initialized field and uses the observed virtual calls and delete path.
// probe: initial get_error_code is the constructor-result test; run is only
// called for a zero result, followed by the final get_error_code.
// probe: the error dialog passes the initial result to get_string2.
// probe: error_code is initialized after the early string setup to preserve
// the original zero register and stack-home schedule.
// probe: moved error_code initialization after vol_name copy; original xor ebx at 00454BCA follows the AOE length scan.
// probe: restored the original GUID byte order as two adjacent static GUID
// aggregates; reordered defaults and directory copies reduced the mismatch to
// an exact-size 285 bytes.
// probe: prev_instance, max_players_per_cd, instance ordering reached the best
// 159-byte mismatch and 94.01% resync similarity. Other parameter orders were
// worse. Explicit dword stores regressed and were removed. The remaining drift
// is local parameter scheduling plus one delayed zone GUID dword.

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

static const struct {
    GUID game;
    GUID zone;
} guid_pair = {
    { 0xF2E846A8, 0xEBE2, 0x11D1,
      { 0x83, 0x9B, 0x00, 0x60, 0x97, 0x07, 0xF5, 0x08 } },
    { 0xF2E846AA, 0xEBE2, 0x11D1,
      { 0x83, 0x9B, 0x00, 0x60, 0x97, 0x07, 0xF5, 0x08 } }
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
    strcpy(info.vol_name, "AOE");
    info.vol_ser_num = 0;
    info.verify_cd = 1;
    info.prev_instance = hPrev;
    info.max_players_per_cd = 3;
    info.instance = hInst;
    info.show_wnd_flag = nShow;

    info.mouse_scroll_interval = 0x54;
    info.key_scroll_interval = 0x54;
    info.game_guid = guid_pair.game;
    info.zone_guid = guid_pair.zone;

    info.max_players = 8;
    info.check_expiration = 0;
    info.expire_month = 0;
    info.expire_day = 0;
    info.expire_year = 0;
    info.update_interval = 1;
    info.check_multi_copies = 1;
    info.skip_startup = 0;
    info.full_screen = 1;
    info.fixed_window_size = 1;
    info.use_dir_draw = 1;
    info.use_sys_mem = 0;
    info.use_music = 1;
    info.use_sound = 1;
    info.use_cd_audio = 0;
    info.use_ima = 0;
    info.use_midi = 0;
    info.use_wave_music = 0;
    info.fast_view = 1;
    info.auto_scroll = 1;
    info.mouse_scroll_edge = 3;
    info.mouse_scroll_max_dist = 4.0f;
    info.key_scroll_max_dist = 4.0f;
    info.key_scroll_object_move = 0.05f;
    info.interface_style = 2;
    info.main_wid = 800;
    info.main_hgt = 600;

    strcpy(info.data_dir, "data2\\");
    strcpy(info.graphics_dir, "");
    strcpy(info.save_dir, "savegame\\");
    strcpy(info.scenario_dir, "scenario\\");
    strcpy(info.campaign_dir, "campaign\\");
    strcpy(info.sounds_dir, "sound\\");
    strcpy(info.resource_dir, "data2\\");
    strcpy(info.ai_dir, "data2\\");
    strcpy(info.avi_dir, "avi\\");

    error_code = 0;

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
