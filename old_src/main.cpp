#include <windows.h>
#include <stdio.h>
#include "tribe/TRIBE_Game.h"
#include "rge/RGE_Prog_Info.h"

// [HELPER] Global GUIDs defined in globals.json / Decomp
// GUIDs: Data1, Data2, Data3, {Data4[0]..Data4[7]}
const GUID _TRIBE_GUID = { 0x3B3F4596, 0x46A8, 0xF2E8, { 0xE2, 0xEB, 0xD1, 0x11, 0x83, 0x9B, 0x00, 0x60 } };
const GUID _ZONE_GUID  = { 0x08F50797, 0x46AA, 0xF2E8, { 0xE2, 0xEB, 0xD1, 0x11, 0x83, 0x9B, 0x00, 0x60 } };

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
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
    strcpy(info.menu_name, "AppIcon");
    strcpy(info.pal_file, "");
    strcpy(info.cursor_file, "palette");
    strcpy(info.vol_name, "mcursors"); // Note: Decomp maps 'mcursors' to vol_name
    strcpy(info.sounds_dir, "AOE");    // Note: Decomp maps 'AOE' to sound_dir logic before resetting it below?
    
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
    info.key_scroll_interval = 4; // Decomp float 0x40800000 -> 4.0? But struct is ulong?
                                  // Common issue in AoE1 decomp: union-like behavior or cast.
                                  // Assuming 4 based on context.
    info.key_scroll_object_move = 4.0f;
    info.interface_style = -0x3333; // 13107 in dec? Likely specific flag.
    info.main_wid = 800;
    info.main_hgt = 600;

    info.game_guid = _TRIBE_GUID;
    info.zone_guid = _ZONE_GUID;

    // 3. Game Lifecycle
    // operator_new(0x1254)
    TRIBE_Game* game = new TRIBE_Game(&info, 1);
    
    int error_code = 0;

    if (game) {
        // [VTABLE OFFSET 6]: setup()
        int setup_res = game->setup();

        if (setup_res == 0) {
            // [VTABLE OFFSET 1]: run()
            error_code = game->run();

            // [VTABLE OFFSET 6]: setup() (Cleanup phase?)
            // Decomp: (*(code *)puVar2[6])();
            game->setup();
            
            // Destructor handles delete
            delete game;
        }
        else if (setup_res != 4) {
            // Error handling
            char title_buf[256];
            char msg_buf[256];
            
            // [VTABLE OFFSET 8]: get_string(id, buffer, size)
            // 0x7d1 = 2001 ("Error")
            game->get_string(2001, title_buf, 256);
            
            // [VTABLE OFFSET 10]: Display error (likely internal popup or format)
            // For now, mirroring behavior with MessageBox
            sprintf(msg_buf, "Setup failed: %d", setup_res);
            MessageBoxA(NULL, msg_buf, title_buf, MB_OK | MB_ICONSTOP);
            
            delete game;
        }
    }

    return error_code;
}