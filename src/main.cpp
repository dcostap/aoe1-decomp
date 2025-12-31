#define _CRT_SECURE_NO_WARNINGS // For freopen in MSVC
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "tribe/Tribe_Game.h"

static const GUID TRIBE_GUID = { 0xF2E846A8, 0x11D1, 0xEBE2, { 0x08, 0xF5, 0x07, 0x97, 0x60, 0x00, 0x9B, 0x83 } };
static const GUID ZONE_GUID  = { 0xF2E846AA, 0x11D1, 0xEBE2, { 0x08, 0xF5, 0x07, 0x97, 0x60, 0x00, 0x9B, 0x83 } };

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    RGE_Prog_Info info;
    memset(&info, 0, sizeof(RGE_Prog_Info));

    // --- 1. Strings Setup (Matching offsets 00454a03 - 00454ba7) ---
    strcpy(info.prog_name, "Age of Empires, Roman Expansion");
    strcpy(info.prog_version, "00.03.01.0717");
    sprintf(info.prog_title, "%s", info.prog_name); // 00454a56
    
    strcpy(info.world_db_file, "tr_wrld.txt");
    strcpy(info.game_data_file, "data2\\empires.dat");
    strcpy(info.registry_key, "Software\\Microsoft\\Games\\Age of Empires\\1.00");
    
    if (lpCmdLine) {
        strncpy(info.cmd_line, lpCmdLine, 255);
    } else {
        info.cmd_line[0] = '\0';
    }

    strcpy(info.icon_name, "AppIcon");
    info.menu_name[0] = '\0'; 
    strcpy(info.pal_file, "palette");
    strcpy(info.cursor_file, "mcursors");
    strcpy(info.vol_name, "AOE"); 

    // --- 2. POD Settings (Matching 00454c7b - 00454d72) ---
    info.instance = hInstance;
    info.prev_instance = hPrevInstance;
    info.show_wnd_flag = nCmdShow;
    
    info.verify_cd = 0;
    info.max_players_per_cd = 1;
    info.check_expiration = 8;
    info.expire_month = 0;
    info.expire_year = 0; // Using 0 based on XOR EBX/EBX
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
    info.mouse_scroll_max_dist = 84.0f; // 0x54
    info.key_scroll_max_dist = 84.0f;   // 0x54
    info.key_scroll_object_move = 4.0f;
    
    // Assembly 00454d2b sets this to 0x3D4CC. 
    // Note: Struct says short, but assembly writes dword. We cast to keep compiler happy.
    info.interface_style = (short)0x3D4CC; 

    // Resolution: Assembly 00454d67 (0x258 = 600), 00454d5c (0x320 = 800)
    info.main_wid = 600; 
    info.main_hgt = 800;

    info.game_guid = TRIBE_GUID;
    info.zone_guid = ZONE_GUID;

    // --- 3. Directory Overrides (Verified by LEA offsets in assembly) ---
    strcpy(info.data_dir, "data2\\");       // info + 0x90c
    strcpy(info.sounds_dir, "sound\\");     // info + 0xe25
    strcpy(info.graphics_dir, "");           // info + 0xa11
    strcpy(info.save_dir, "savegame\\");    // info + 0xb16
    strcpy(info.scenario_dir, "scenario\\"); // info + 0xc1b
    strcpy(info.campaign_dir, "campaign\\"); // info + 0xd20
    strcpy(info.resource_dir, "data2\\");   // info + 0xf2a
    strcpy(info.ai_dir, "data2\\");         // info + 0x102f
    strcpy(info.avi_dir, "avi\\");           // info + 0x1134

    int final_error_code = 0; // Local Stack[-0x144]

    // --- 4. Game Initialization (00454e82) ---
    TRIBE_Game* game = (TRIBE_Game*)operator new(0x1254);
    if (game) {
        game = new (game) TRIBE_Game(&info, 1);

        int status = game->get_error_code(); // vtable + 0x18

        if (status == 0) {
            // 00454f6c: game->run() returns to EAX, stored in local_10
            game->run(); 
            // 00454f75: Result of get_error_code is called but effectively ignored for return
            game->get_error_code(); 
            
            delete game;
        }
        else if (status != 4) {
            char title[256];
            char msg[256];

            game->get_string(0x7D1, title, 256);
            game->get_string2(1, status, 0, msg, 256);

            delete game;

            MessageBoxA(NULL, msg, title, MB_ICONSTOP | MB_TASKMODAL);
        }
        else {
            delete game;
        }
    }

    return final_error_code;
}