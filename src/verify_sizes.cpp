#include <stdio.h>
#include <stddef.h>
#include "tribe/TRIBE_Game.h"

int main() {
    printf("Verifying Struct Sizes (Runtime Check)...\n");
    
    // RGE_Base_Game
    printf("RGE_Base_Game: Actual=0x%X, Expected=0xA24, Diff=%d\n", sizeof(RGE_Base_Game), 0xA24, (int)sizeof(RGE_Base_Game) - 0xA24);
    printf("  Offset rge_game_options: 0x%X\n", offsetof(RGE_Base_Game, rge_game_options));
    printf("  Size   RGE_Game_Options: 0x%X\n", sizeof(RGE_Game_Options));
    
    // TRIBE_Game
    printf("TRIBE_Game:    Actual=0x%X, Expected=0x1254, Diff=%d\n", sizeof(TRIBE_Game), 0x1254, (int)sizeof(TRIBE_Game) - 0x1254);
    printf("  Offset MouseRightClickTable: 0x%X (Expected 0xA24)\n", offsetof(TRIBE_Game, MouseRightClickTable));
    printf("  Offset tribe_game_options:   0x%X\n", offsetof(TRIBE_Game, tribe_game_options));

    return 0;
}
