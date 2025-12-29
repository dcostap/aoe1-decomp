#define _CRT_SECURE_NO_WARNINGS // For freopen in MSVC
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "rge/RGE_Prog_Info.h"
#include "tribe/Tribe_Game.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    
    // Rule 4: Debugging & Temporary Code
#ifdef _DEBUG
    // 1. Allocate a console so we can theoretically see output if we didn't redirect
    AllocConsole();

    // 2. Redirect stdout and stderr to "debug.log" in the current directory (build/)
    // Mode "w" creates the file if missing, and truncates it (empties it) if it exists.
    freopen("build/debug.log", "w", stdout);
    freopen("build/debug.log", "w", stderr);

    // 3. Disable buffering. This is CRITICAL for debugging crashes. 
    // Without this, the crash might happen before the buffer flushes to the file.
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    printf("[SYSTEM] Debug Logging Started.\n");
    printf("[SYSTEM] Output redirected to debug.log\n");
#endif

    RGE_Prog_Info info;
    // Zero init to be safe, though decomp manually inits fields
    memset(&info, 0, sizeof(RGE_Prog_Info));

    // 1. Strings Setup
    // Source: _WinMain_16 (0x004549e0)
    strcpy(info.prog_name, "Age of Empires, Roman Expansion");
    strcpy(info.prog_version, "00.03.01.0717");
    sprintf(info.prog_title, "%s", info.prog_name); // Decomp logic: sprintf(title+4, "%s", name+4)
    
    strcpy(info.world_db_file, "tr_wrld.txt");
    strcpy(info.game_data_file, "data2\\empires.dat");
    strcpy(info.registry_key, "Software\\Microsoft\\Games\\Age of Empires\\1.00");
    
    // param_3 passed to WinMain is lpCmdLine
    if (lpCmdLine) strncpy(info.cmd_line, lpCmdLine, 255);

    strcpy(info.icon_name, "AppIcon");
    strcpy(info.menu_name, "");
    strcpy(info.pal_file, "palette");
    strcpy(info.cursor_file, "mcursors");
    strcpy(info.vol_name, "AOE"); 
    strcpy(info.sounds_dir, "");   
    
    // Directory overrides
    strcpy(info.data_dir, "data2\\");
    strcpy(info.sounds_dir, "sound\\");
    strcpy(info.graphics_dir, "");
    strcpy(info.save_dir, "savegame\\");
    strcpy(info.scenario_dir, "scenario\\");
    strcpy(info.campaign_dir, "campaign\\");
    strcpy(info.resource_dir, "data2\\");
    strcpy(info.ai_dir, "data2\\");
    strcpy(info.avi_dir, "avi\\");

    // 2. POD Settings
    info.instance = hInstance;
    info.prev_instance = hPrevInstance;
    info.show_wnd_flag = nCmdShow;
    
    info.verify_cd = 0;
    info.max_players_per_cd = 1;
    info.check_expiration = 8;
    info.check_multi_copies = 1;
    info.skip_startup = 1;
    info.fixed_window_size = 1;
    info.use_dir_draw = 1;
    info.use_sys_mem = 1;
    info.use_sound = 1;
    info.use_cd_audio = 1;
    info.auto_scroll = 1;
    info.mouse_scroll_edge = 1;
    info.mouse_scroll_interval = 3;
    info.key_scroll_interval =  0x40800000; 
    info.mouse_scroll_max_dist = 0x54;
    info.key_scroll_max_dist   = 0x54;
    info.key_scroll_object_move = 4.0;
    info.interface_style = -0x3333; // 13107 in dec? Likely specific flag.
    info.main_wid = 800;
    info.main_hgt = 600;

    info.game_guid.Data1 = 600;
    info.zone_guid.Data4[4] = 0x83;
    info.zone_guid.Data4[5] = 0x9b;
    info.zone_guid.Data4[6] = '\0';
    info.zone_guid.Data4[7] = '`';

    int error_code = 0;

    TRIBE_Game* game = (TRIBE_Game*)operator new(sizeof(TRIBE_Game));
    if (game) {
        game = new TRIBE_Game(&info, 1);

        int status = game->get_error_code();

#ifdef _DEBUG
        printf("[SYSTEM] TRIBE_Game creation Status: %d\n", error_code);
#endif       

        if (status == 0) {
            error_code = game->run();     
            game->get_error_code();      // called again; return ignored
            game->~TRIBE_Game();         // deleting dtor in real code
            operator delete(game);
        }
        else if (status != 4) {
            char title[0x104] = {};
            char msg[0x104] = {};

            game->get_string(0x7D1, title, 0x100);
            game->get_string2(1, status, 0, msg, 0x100);

            delete game; // original deletes before MessageBox
            MessageBoxA(nullptr, msg, title, MB_ICONSTOP);
        }
        else {
            game->~TRIBE_Game();
            operator delete(game);
        }
    }

    return error_code;
}