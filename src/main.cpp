#include <windows.h>
#include <stdio.h>
#include "tribe/TRIBE_Game.h"
#include "rge/RGE_Prog_Info.h"

// Define the WinMain entry point
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
#ifdef _DEBUG
    // AllocConsole();
    freopen("build\\debug.log", "w", stdout);
    freopen("build\\debug.log", "w", stderr);
    setvbuf(stdout, NULL, _IONBF, 0);
    printf("AoE Decomp: Debug Console Initialized\n");
#endif

    // 1. Initialize RGE_Prog_Info
    RGE_Prog_Info prog_info;
    memset(&prog_info, 0, sizeof(RGE_Prog_Info));
    
    // Strings from 0x004549e0 (WinMain)
    strcpy(prog_info.prog_name, "Age of Empires - Roman Expansion");
    strcpy(prog_info.prog_version, "00.03.01.0717");
    strcpy(prog_info.prog_title, "Age of Empires - Roman Expansion");
    strcpy(prog_info.world_db_file, "tr_wrld.txt");
    strcpy(prog_info.game_data_file, "empires.dat");
    strcpy(prog_info.registry_key, "Software\\Microsoft\\Games\\Age of Empires\\1.00");
    strcpy(prog_info.icon_name, "AppIcon");
    prog_info.menu_name[0] = '\0';
    strcpy(prog_info.pal_file, "palette");
    strcpy(prog_info.cursor_file, "mcursors");
    strcpy(prog_info.vol_name, "AOE");

    // Directories
    strcpy(prog_info.data_dir, "data2\\");
    strcpy(prog_info.sounds_dir, "sound\\");
    strcpy(prog_info.graphics_dir, "");
    strcpy(prog_info.save_dir, "savegame\\");
    strcpy(prog_info.scenario_dir, "scenario\\");
    strcpy(prog_info.campaign_dir, "campaign\\");
    strcpy(prog_info.resource_dir, "data2\\");
    strcpy(prog_info.ai_dir, "data2\\");
    strcpy(prog_info.avi_dir, "avi\\");

    // GUIDs
    prog_info.game_guid = { 0x3B3F4596, 0x46A8, 0xF2E8, { 0xE2, 0xEB, 0xD1, 0x11, 0x83, 0x9B, 0x00, 0x60 } };
    prog_info.zone_guid = { 0x08F50797, 0x46AA, 0xF2E8, { 0xE2, 0xEB, 0xD1, 0x11, 0x83, 0x9B, 0x00, 0x60 } };

    // Engine Flags
    prog_info.instance = hInstance;
    prog_info.prev_instance = hPrevInstance;
    prog_info.show_wnd_flag = SW_SHOW;
    prog_info.cmd_line[0] = '\0'; // Should copy lpCmdLine if needed
    if (lpCmdLine) strncpy(prog_info.cmd_line, lpCmdLine, 255);

    prog_info.verify_cd = 0;
    prog_info.max_players_per_cd = 1;
    prog_info.check_expiration = 8;
    prog_info.expire_month = 0;
    prog_info.expire_day = 0;
    prog_info.expire_year = 0;
    prog_info.check_multi_copies = 1;
    prog_info.skip_startup = 1;
    prog_info.full_screen = 0;
    prog_info.fixed_window_size = 1;
    prog_info.use_dir_draw = 1;
    prog_info.use_sys_mem = 1;
    prog_info.use_music = 0;
    prog_info.use_sound = 1;
    prog_info.use_cd_audio = 1;
    prog_info.auto_scroll = 1;
    prog_info.mouse_scroll_edge = 1;
    prog_info.mouse_scroll_interval = 3;
    prog_info.key_scroll_interval = 4; 
    prog_info.key_scroll_object_move = 4.0f;
    prog_info.interface_style = 1; // Standard AoE style
    prog_info.main_wid = 800;
    prog_info.main_hgt = 600;
    
    // 2. Create TRIBE_Game instance
    TRIBE_Game* game = new TRIBE_Game(&prog_info, 1);
    
#ifdef _DEBUG
    printf("TRIBE_Game created, error_code=%d\n", game->error_code);
#endif
    
    if (game->error_code != 0) {
        char err_msg[100];
        sprintf(err_msg, "Game initialization failed with error code: %d", game->error_code);
        MessageBoxA(NULL, err_msg, "Error", MB_OK | MB_ICONERROR);
        delete game;
        return 1;
    }

    // 3. Start a new game (Map generation)
#ifdef _DEBUG
    printf("Calling start_game(0)...\n");
#endif
    game->start_game(0);

#ifdef _DEBUG
    printf("Calling run()...\n");
#endif
    // 4. Run the Game Loop
    int result = game->run();
    
    // 5. Cleanup
    delete game;
    
    return result;
}