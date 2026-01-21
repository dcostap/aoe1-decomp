#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "../include/TRIBE_Game.h"
#include "../include/RGE_Prog_Info.h"

// ASSUMPTION: GUID values are reconstructed from assembly initialization logic at 0x00454c17.
// _TRIBE_GUID: F2E846A8-08F5-0797-11D1EBE2-60009B83
const _GUID AGE1_TRIBE_GUID = { 0xF2E846A8, 0x08F5, 0x0797, { 0x11, 0xD1, 0xEB, 0xE2, 0x60, 0x00, 0x9B, 0x83 } };
// _ZONE_GUID: F2E846AA-08F5-0797-11D1EBE2-60009B83
const _GUID AGE1_ZONE_GUID  = { 0xF2E846AA, 0x08F5, 0x0797, { 0x11, 0xD1, 0xEB, 0xE2, 0x60, 0x00, 0x9B, 0x83 } };

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    RGE_Prog_Info info;
    memset(&info, 0, sizeof(info));

    // String initialization (reconstructed from main.cpp.asm)
    strcpy(info.prog_title, "Age of Empires, Roman Expansion");
    strcpy(info.prog_version, "00.03.01.0717");
    
    // 0x00454a61: sprintf(info.prog_name_init, "%s", info.prog_title)
    sprintf(info.prog_name_init, "%s", info.prog_title);
    
    strcpy(info.world_db_file, "tr_wrld.txt");
    strcpy(info.game_data_file, "data2\\empires.dat");

    // 0x00454aca: Software\Microsoft\Games\Age of Empires\1.0
    // Note: The assembly actually uses a longer string or multiple parts.
    strcpy(info.registry_key, "Software\\Microsoft\\Games\\Age of Empires\\1.0");

    info.instance = hInstance;
    info.prev_instance = hPrevInstance;
    
    // 0x00454adb: cmd_line setup
    if (lpCmdLine) {
        strncpy(info.cmd_line, lpCmdLine, sizeof(info.cmd_line) - 1);
    }
    
    info.show_wnd_flag = nShowCmd;
    
    strcpy(info.icon_name, "AppIcon");
    strcpy(info.menu_name, "AOE");
    strcpy(info.pal_file, "palette");
    strcpy(info.cursor_file, "mcursors");

    // Scalar initializations (0x00454c1d+)
    info.mouse_scroll_max_dist = 84.0f; 
    info.key_scroll_max_dist = 84.0f; 
    
    info.game_guid = AGE1_TRIBE_GUID;
    info.zone_guid = AGE1_ZONE_GUID;
    
    info.verify_cd = 0;
    info.max_players_per_cd = 1;
    info.check_expiration = 8;
    info.expire_month = 0;
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
    info.auto_scroll = 1;
    info.mouse_scroll_edge = 1;
    info.mouse_scroll_interval = 3;
    info.key_scroll_interval = 4;
    info.key_scroll_object_move = 1.25f;
    info.interface_style = 2;
    info.main_wid = 800;
    info.main_hgt = 600;

    // Directories (0x00454d79+)
    strcpy(info.data_dir, "data2\\");
    strcpy(info.sounds_dir, "sound\\");
    strcpy(info.resource_dir, "");
    strcpy(info.save_dir, "savegame\\");
    strcpy(info.scenario_dir, "scenario\\");
    strcpy(info.campaign_dir, "campaign\\");
    strcpy(info.graphics_dir, "data2\\");
    strcpy(info.ai_dir, "data2\\");
    strcpy(info.avi_dir, "avi\\");

    // 0x00454f20: game instantiation
    TRIBE_Game* game = new TRIBE_Game((RGE_Prog_Info*)&info.prog_name_init, 1);
    info.prog_game_ptr = game;
    
    int retval = 0;
    if (game) {
        // 0x00454f5d: Check error code via virtual call?
        // ASM calls a virtual function at [EDI + 0x18]. 0x18 / 4 = 6. vt[6] is get_error_code.
        if (game->get_error_code() == 0) {
            retval = game->run();
        } else {
            int err = game->get_error_code();
            // 0x00454f7f: If error is 4, just exit.
            if (err != 4) {
                char msg[256];
                char title[256];
                // 0x00454f98: Get title (2001 = "Error")
                game->get_string(2001, title, sizeof(title));
                // 0x00454fb1: Get message
                game->get_string2(err, 0, err, msg, sizeof(msg));
                // 0x00454fcc: Show MessageBox
                MessageBox(NULL, msg, title, MB_OK | MB_ICONERROR);
            }
            retval = err;
        }
        // 0x00454fb7: Cleanup via virtual call? [EDI + 0x0] is likely destructor or close.
        // ASM calls [EDI] after run/error check. vt[0] is destructor.
        delete game;
    }
    
    return retval;
}
