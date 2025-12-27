#include <stdio.h>
#include <stddef.h>
#include "tribe/TRIBE_Game.h"
#include "rge/TDrawSystem.h"
#include "rge/TDrawArea.h"
#include "rge/RGE_Game_World.h"

int main() {
    printf("Verifying Struct Sizes (Runtime Check)...\n");
    
    // RGE_Base_Game
    printf("RGE_Base_Game: Actual=0x%X, Expected=0xA24, Diff=%d\n", (int)sizeof(RGE_Base_Game), (int)sizeof(RGE_Base_Game) - 0xA24);
    printf("  Offset rge_game_options: 0x%X\n", (int)offsetof(RGE_Base_Game, rge_game_options));
    printf("  Size   RGE_Game_Options: 0x%X\n", (int)sizeof(RGE_Game_Options));
    
    // TRIBE_Game
    printf("TRIBE_Game:    Actual=0x%X, Expected=0x1254, Diff=%d\n", (int)sizeof(TRIBE_Game), (int)sizeof(TRIBE_Game) - 0x1254);
    printf("  Offset MouseRightClickTable: 0x%X (Expected 0xA24)\n", (int)offsetof(TRIBE_Game, MouseRightClickTable));
    printf("  Offset tribe_game_options:   0x%X\n", (int)offsetof(TRIBE_Game, tribe_game_options));

    // TDrawSystem
    printf("TDrawSystem:   Actual=0x%X, Expected=0x47C, Diff=%d\n", (int)sizeof(TDrawSystem), (int)sizeof(TDrawSystem) - 0x47C);
    printf("  Offset palette: 0x%X (Expected 0x78)\n", (int)offsetof(TDrawSystem, palette));
    printf("  Offset DrawType: 0x%X (Expected 0x478)\n", (int)offsetof(TDrawSystem, DrawType));

    // TDrawArea
    printf("TDrawArea:     Actual=0x%X, Expected=0xF9, Diff=%d\n", (int)sizeof(TDrawArea), (int)sizeof(TDrawArea) - 0xF9);
    printf("  Offset SurfaceDesc: 0x%X (Expected 0x79)\n", (int)offsetof(TDrawArea, SurfaceDesc));
    printf("  Offset Name:        0x%X (Expected 0xF5)\n", (int)offsetof(TDrawArea, Name));

    // RGE_Game_World
    printf("RGE_Game_World: Actual=0x%X, Expected=0xF8, Diff=%d\n", (int)sizeof(RGE_Game_World), (int)sizeof(RGE_Game_World) - 0xF8);
    printf("  Offset players: 0x%X (Expected 0x3A)\n", (int)offsetof(RGE_Game_World, players));

    // RGE_Map
    printf("RGE_Map:        Actual=0x%X, Expected=0x8DD0, Diff=%d\n", (int)sizeof(RGE_Map), (int)sizeof(RGE_Map) - 0x8DD0);
    printf("  Offset tilesizes:     0x%X\n", (int)offsetof(RGE_Map, tilesizes));
    printf("  Offset terrain_types: 0x%X\n", (int)offsetof(RGE_Map, terrain_types));
    printf("  Offset border_types:  0x%X\n", (int)offsetof(RGE_Map, border_types));
    printf("  Offset map_row_offset: 0x%X\n", (int)offsetof(RGE_Map, map_row_offset));
    printf("  Size RGE_Tile_Set:    0x%X\n", (int)sizeof(RGE_Tile_Set));
    printf("  Size RGE_Border_Set:  0x%X\n", (int)sizeof(RGE_Border_Set));

    // RGE_Player
    printf("RGE_Player:     Actual=0x%X, Expected=0x1D8, Diff=%d\n", (int)sizeof(RGE_Player), (int)sizeof(RGE_Player) - 0x1D8);
    printf("  Offset tile_list:     0x%X\n", (int)offsetof(RGE_Player, tile_list));
    printf("  Offset unitDiplomacy: 0x%X\n", (int)offsetof(RGE_Player, unitDiplomacy));
    printf("  Offset sel_list:      0x%X\n", (int)offsetof(RGE_Player, sel_list));
    printf("  Offset groups_used:   0x%X\n", (int)offsetof(RGE_Player, groups_used));

    return 0;
}
