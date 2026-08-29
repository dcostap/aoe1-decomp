// RGE_Prog_Info and TRIBE_Game ownership model.  The source now names every
// initialized field and uses the observed virtual calls and delete path.
// called for a zero result, followed by the final get_error_code.
// the original zero register and stack-home schedule.
// is local parameter scheduling plus one delayed zone GUID dword.
// use_wave_music until after the scroll values, and retain use_dir_draw=1.
// assignment permutations and late aliases did not reproduce the final order.
// four remaining bytes. Reverting that one change restored the 4-byte diff.

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "../include/main.h"
#include "../include/tribegam.h"
#include "../include/game_globals.h"

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
    info.max_players_per_cd = 3;
    info.instance = hInst;
    info.prev_instance = hPrev;
    info.show_wnd_flag = nShow;

    info.mouse_scroll_interval = 0x54;
    info.key_scroll_interval = 0x54;
    info.game_guid = TRIBE_GUID;

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
    info.fast_view = 1;
    info.auto_scroll = 1;
    info.mouse_scroll_edge = 3;
    info.mouse_scroll_max_dist = 4.0f;
    info.key_scroll_max_dist = 4.0f;
    info.key_scroll_object_move = 0.05f;
    info.interface_style = 2;
    info.use_cd_audio = 0;
    info.use_ima = 0;
    info.use_midi = 0;
    info.use_wave_music = 0;
    info.main_wid = 800;
    info.main_hgt = 600;
    info.zone_guid = ZONE_GUID;

    strcpy(info.data_dir, "data2\\");
    strcpy(info.sounds_dir, "sound\\");
    strcpy(info.graphics_dir, "");
    strcpy(info.save_dir, "savegame\\");
    strcpy(info.scenario_dir, "scenario\\");
    strcpy(info.campaign_dir, "campaign\\");
    strcpy(info.resource_dir, "data2\\");
    strcpy(info.ai_dir, "data2\\");
    strcpy(info.avi_dir, "avi\\");

    error_code = 0;

    game = new TRIBE_Game(&info, 1);
    if (game != 0) {
        int result = game->get_error_code();
        if (result == 0) {
            error_code = game->run();
            game->get_error_code();
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
