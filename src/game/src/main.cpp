#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "../include/TRIBE_Game.h"
#include "../include/RGE_Prog_Info.h"

// Fully verified GUID initialization parity with main.cpp.asm @ 0x00454c17.
// _TRIBE_GUID dword stores:
//   Data1=0x08F50797, Data2=0x46A8, Data3=0xF2E8, Data4={0xE2,0xEB,0xD1,0x11,0x83,0x9B,0x00,0x60}
const _GUID AGE1_TRIBE_GUID = { 0x08F50797, 0x46A8, 0xF2E8, { 0xE2, 0xEB, 0xD1, 0x11, 0x83, 0x9B, 0x00, 0x60 } };
// _ZONE_GUID dword stores:
//   Data1=0x08F50797, Data2=0x46AA, Data3=0xF2E8, Data4={0xE2,0xEB,0xD1,0x11,0x83,0x9B,0x00,0x60}
const _GUID AGE1_ZONE_GUID  = { 0x08F50797, 0x46AA, 0xF2E8, { 0xE2, 0xEB, 0xD1, 0x11, 0x83, 0x9B, 0x00, 0x60 } };

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    // Fully verified. Source of truth: main.cpp.decomp @ 0x004549E0

    RGE_Prog_Info info;
    memset(&info, 0, sizeof(info));

    // main.cpp:74
    strcpy(info.prog_title, "Age of Empires, Roman Expansion");
    // main.cpp:75
    strcpy(info.prog_version, "00.03.01.0717");
    
    // main.cpp:76
    sprintf(info.prog_name, "%s", info.prog_title);
    
    // main.cpp:77
    strcpy(info.world_db_file, "tr_wrld.txt");
    // main.cpp:83
    strcpy(info.game_data_file, "data2\\empires.dat");

    // main.cpp:86
    strcpy(info.registry_key, "Software\\Microsoft\\Games\\Age of Empires\\1.0");

    info.instance = hInstance;
    info.prev_instance = hPrevInstance;
    
    // main.cpp:108
    if (lpCmdLine) {
        strncpy(info.cmd_line, lpCmdLine, sizeof(info.cmd_line) - 1);
    }
    
    info.show_wnd_flag = nShowCmd;
    
    // main.cpp:134
    strcpy(info.icon_name, "AppIcon");
    // main.cpp:153 (Offset 0x649)
    strcpy(info.menu_name, "AOE");
    // main.cpp:153 (Offset 0x672)
    strcpy(info.pal_file, "palette");
    // main.cpp:153 (Offset 0x777)
    strcpy(info.cursor_file, "mcursors");

    // main.cpp:153 (Scalar initializations)
    // NOTE: ASM stores integer 0x00000054 into these float fields (raw bits; float value ~= 1.17709e-43).
    {
        const uint32_t scroll_max_dist_bits = 0x00000054u;
        memcpy(&info.mouse_scroll_max_dist, &scroll_max_dist_bits, sizeof(scroll_max_dist_bits));
        memcpy(&info.key_scroll_max_dist, &scroll_max_dist_bits, sizeof(scroll_max_dist_bits));
    }
    
    info.game_guid = AGE1_TRIBE_GUID;
    info.zone_guid = AGE1_ZONE_GUID;
    
    info.verify_cd = 0;
    info.max_players_per_cd = 1;
    info.max_players = 8;
    info.check_expiration = 8;
    info.expire_month = 0;
    info.expire_day = 0;
    info.expire_year = 0;
    info.update_interval = 0;
    info.check_multi_copies = 1;
    info.skip_startup = 1;
    info.full_screen = 0;
    info.fixed_window_size = 1;
    info.use_dir_draw = 1;
    info.use_sys_mem = 1;
    info.use_music = 0;
    info.use_sound = 1;
    info.use_cd_audio = 1;
    info.use_midi = 0;
    info.use_wave_music = 0;
    info.auto_scroll = 1;
    info.mouse_scroll_edge = 1;
    info.mouse_scroll_interval = 3;
    info.key_scroll_interval = 4;
    info.key_scroll_object_move = 1.2f; // 0x3f99999a
    info.interface_style = 2;
    info.main_wid = 800;
    info.main_hgt = 600;

    // main.cpp:156 (Directories)
    strcpy(info.data_dir, "data2\\");
    // main.cpp:157
    strcpy(info.sounds_dir, "sound\\");
    // main.cpp:158 - ASM at 0x454ea2 shows resource_dir = "data2\\"
    strcpy(info.resource_dir, "data2\\");
    // main.cpp:159
    strcpy(info.save_dir, "savegame\\");
    // main.cpp:160
    strcpy(info.scenario_dir, "scenario\\");
    // main.cpp:161
    strcpy(info.campaign_dir, "campaign\\");
    // main.cpp:168
    strcpy(info.graphics_dir, "data2\\");
    strcpy(info.ai_dir, "data2\\");
    strcpy(info.avi_dir, "avi\\");

    int retval = 0;
    TRIBE_Game* game = new TRIBE_Game(&info, 1);
    if (game) {
        if (game->get_error_code() == 0) {
            retval = game->run();
            (void)game->get_error_code();
        } else {
            int init_error = game->get_error_code();
            if (init_error != 4) {
                char msg[256];
                char title[256];
                game->get_string(2001, title, sizeof(title));
                game->get_string2(1, init_error, 0, msg, sizeof(msg));
                MessageBoxA(NULL, msg, title, MB_OK | MB_ICONERROR);
            }
            retval = init_error;
        }
        delete game;
    }
    return retval;
}
