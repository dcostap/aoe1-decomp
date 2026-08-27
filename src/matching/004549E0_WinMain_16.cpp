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
// probe: matched the original option-store order: defer use_cd_audio through
// use_wave_music until after the scroll values, and retain use_dir_draw=1.
// probe: moved the zone GUID aggregate after scalar setup; this delayed its
// final dword store and reduced the mismatch to 24 bytes.
// probe: ordered paths as data, sound, graphics, save, scenario, campaign,
// resource, AI, and AVI; this reduced the mismatch to 14 bytes.
// probe: the executable returns the run() result and discards the following
// get_error_code() result. Modeling that bug reduced the mismatch to 4 bytes.
// probe: pointer field ABI changed to void* with no codegen change. Instance
// assignment permutations and late aliases did not reproduce the final order.
// exact-finish: reversing the independent instance assignments matched all
// four remaining bytes. Reverting that one change restored the 4-byte diff.
// The retained order is the smallest natural source form; no compiler
// scaffolding or manual exception ownership was added.

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "../../include/main.h"
#include "../../include/tribegam.h"

void* __cdecl operator new(unsigned int size);

static const struct {
    GUID game;
    GUID zone;
} guid_pair = {
    { 0xF2E846A8, 0xEBE2, 0x11D1,
      { 0x83, 0x9B, 0x00, 0x60, 0x97, 0x07, 0xF5, 0x08 } },
    { 0xF2E846AA, 0xEBE2, 0x11D1,
      { 0x83, 0x9B, 0x00, 0x60, 0x97, 0x07, 0xF5, 0x08 } }
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
    info.max_players_per_cd = 3;
    info.instance = hInst;
    info.prev_instance = hPrev;
    info.show_wnd_flag = nShow;

    info.mouse_scroll_interval = 0x54;
    info.key_scroll_interval = 0x54;
    info.game_guid = guid_pair.game;

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
    info.zone_guid = guid_pair.zone;

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
