#include <windows.h>
#include <stdio.h>

#include "types.h"
#include "rge/RGE_Prog_Info.h"
#include "tribe/TRIBE_Game.h"

//------------------------------------------------------------------------------
// WinMain
// Address: 004549e0
//------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Local stack variable: RGE_Prog_Info info
    RGE_Prog_Info info;
    memset(&info, 0, sizeof(RGE_Prog_Info));

    // String initialization logic (Mmapped from Ghidra assembly loops)
    // 00454a0d - 00454bc6
    strcpy(info.prog_name, "Age of Empires - Roman Expansion");
    strcpy(info.prog_version, "00.03.01.0717");
    sprintf(info.prog_title, "Age of Empires Expansion");
    
    strcpy(info.world_db_file, "tr_wrld.txt");
    strcpy(info.game_data_file, "data2\\empires.dat");
    strcpy(info.registry_key, "Software\\Microsoft\\Games\\Age of Empires\\1.00");
    strcpy(info.cmd_line, lpCmdLine);
    strcpy(info.icon_name, "AppIcon");
    strcpy(info.pal_file, "palette");
    strcpy(info.cursor_file, "mcursors");
    strcpy(info.vol_name, "AOE");

    // Directory path assignments (00454c60)
    strcpy(info.data_dir, "data2\\");
    strcpy(info.sounds_dir, "sound\\");
    strcpy(info.graphics_dir, "");
    strcpy(info.save_dir, "savegame\\");
    strcpy(info.scenario_dir, "scenario\\");
    strcpy(info.campaign_dir, "campaign\\");
    strcpy(info.resource_dir, "data2\\");
    strcpy(info.ai_dir, "data2\\");
    strcpy(info.avi_dir, "avi\\");

    // Value assignments from assembly (00454bdd)
    info.instance = (void*)3;
    info.prev_instance = hPrevInstance;
    info.show_wnd_flag = nCmdShow;
    info.game_guid = _TRIBE_GUID;
    info.zone_guid = _ZONE_GUID;

    info.mouse_scroll_max_dist = 0.000117709f;
    info.key_scroll_max_dist = 0.000117709f;
    info.key_scroll_interval = 4;           // Assembly 0x40800000 (float 4.0)
    info.key_scroll_object_move = 4.0f;
    info.main_wid = 800;
    info.main_hgt = 600;

    int error_code = 0;

    // Allocate TRIBE_Game object (Ghidra: operator_new(0x1254))
    // 00454d6d
    TRIBE_Game* game = new TRIBE_Game(&info, 1);

    if (game) {
        // VTable call [6]: TRIBE_Game::run()
        int run_result = game->run(); 
        
        if (run_result == 0) {
            error_code = game->get_error_code(); // VTable call [1]
            delete game;
        } 
        else if (run_result != 4) {
            char title[256], msg[256];
            game->show_error(0x7D1, title, 256); // VTable call [8]
            game->fatal_exit(1, 0, 0, msg, 256); // VTable call [10]
            delete game;

            MessageBoxA(NULL, "Engine initialization failed.", "Error", MB_ICONERROR);
        }
    }

    return error_code;
}