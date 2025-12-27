#include <windows.h>
#include <stdio.h>
#include "tribe/TRIBE_Game.h"
#include "rge/RGE_Prog_Info.h"

// Define the WinMain entry point
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // 1. Initialize RGE_Prog_Info
    RGE_Prog_Info prog_info;
    memset(&prog_info, 0, sizeof(RGE_Prog_Info));
    
    // Set basic fields
    strcpy(prog_info.prog_name, "Age of Empires");
    prog_info.instance = hInstance;
    prog_info.main_wid = 640;
    prog_info.main_hgt = 480;
    
    // Set directories to current directory for now
    char current_dir[260];
    GetCurrentDirectoryA(260, current_dir);
    strcpy(prog_info.data_dir, current_dir);
    strcpy(prog_info.graphics_dir, current_dir);
    strcpy(prog_info.sounds_dir, current_dir);
    
    // 2. Create TRIBE_Game instance
    // Passing setup_flag = 1 triggers setup() inside constructor
    TRIBE_Game* game = new TRIBE_Game(&prog_info, 1);
    
    if (game->error_code != 0) {
        char err_msg[100];
        sprintf(err_msg, "Game initialization failed with error code: %d", game->error_code);
        MessageBoxA(NULL, err_msg, "Error", MB_OK | MB_ICONERROR);
        delete game;
        return 1;
    }

    MessageBoxA(NULL, "Game Initialized Successfully! Starting Run Loop...", "AoE Decomp", MB_OK);

    // 3. Run the Game Loop
    int result = game->run();
    
    // 4. Cleanup
    delete game;
    
    return result;
}