#include <stdio.h>
#include <stddef.h>
#include "tribe/TRIBE_Game.h"
#include "rge/TDrawSystem.h"
#include "rge/TDrawArea.h"
#include "rge/RGE_Game_World.h"

#define CHECK_SIZE(cls, exp) \
    { \
        int sz = (int)sizeof(cls); \
        printf("%-15s: Actual=0x%04X, Expected=0x%04X, Diff=%-4d [%s]\n", #cls, sz, exp, sz - exp, (sz == exp ? "OK" : "NOT OK")); \
    }

#define CHECK_OFFSET(cls, mem, exp) \
    { \
        int off = (int)offsetof(cls, mem); \
        printf("  Offset %-22s: 0x%04X (Expected 0x%04X) [%s]\n", #mem, off, exp, (off == exp ? "OK" : "NOT OK")); \
    }

#define CHECK_NESTED_SIZE(cls, exp) \
    { \
        int sz = (int)sizeof(cls); \
        printf("  Size   %-22s: 0x%04X (Expected 0x%04X) [%s]\n", #cls, sz, exp, (sz == exp ? "OK" : "NOT OK")); \
    }

int main() {
    printf("Verifying Struct Sizes (Runtime Check)...\n");
    
    // RGE_Base_Game
    CHECK_SIZE(RGE_Base_Game, 0xA24);
    CHECK_OFFSET(RGE_Base_Game, rge_game_options, 0x902);
    CHECK_NESTED_SIZE(RGE_Game_Options, 0x9F);
    
    // TRIBE_Game
    CHECK_SIZE(TRIBE_Game, 0x1254);
    CHECK_OFFSET(TRIBE_Game, MouseRightClickTable, 0xA24);
    CHECK_OFFSET(TRIBE_Game, tribe_game_options, 0xA7C);

    // TDrawSystem
    CHECK_SIZE(TDrawSystem, 0x47C);
    CHECK_OFFSET(TDrawSystem, palette, 0x78);
    CHECK_OFFSET(TDrawSystem, DrawType, 0x478);

    // TDrawArea
    CHECK_SIZE(TDrawArea, 0xFD);
    CHECK_OFFSET(TDrawArea, SurfaceDesc, 0x7D);
    CHECK_OFFSET(TDrawArea, Name, 0xF9);

    // RGE_Game_World
    CHECK_SIZE(RGE_Game_World, 0xF8);
    CHECK_OFFSET(RGE_Game_World, players, 0x3A);

    // RGE_Map
    CHECK_SIZE(RGE_Map, 0x8DD0);
    CHECK_OFFSET(RGE_Map, tilesizes, 0x18);
    CHECK_OFFSET(RGE_Map, terrain_types, 0x8C);
    CHECK_OFFSET(RGE_Map, border_types, 0x338C);
    CHECK_OFFSET(RGE_Map, map_row_offset, 0x8D8C);
    CHECK_OFFSET(RGE_Map, any_frame_change, 0x8DAC);
    CHECK_OFFSET(RGE_Map, search_map, 0x8DB0);
    CHECK_OFFSET(RGE_Map, random_map, 0x8DBC);
    CHECK_OFFSET(RGE_Map, unit_manager, 0x8DCC);
    CHECK_NESTED_SIZE(RGE_Tile_Set, 0x198);
    CHECK_NESTED_SIZE(RGE_Border_Set, 0x5A0);

    // RGE_Player
    CHECK_SIZE(RGE_Player, 0x220);
    CHECK_NESTED_SIZE(RGE_Tile_List, 0x14);
    CHECK_OFFSET(RGE_Player, master_object_num, 0x22);
    CHECK_OFFSET(RGE_Player, id, 0x4A);
    CHECK_OFFSET(RGE_Player, culture, 0x54);
    CHECK_OFFSET(RGE_Player, tile_list, 0x58);
    CHECK_OFFSET(RGE_Player, unitDiplomacy, 0x88);
    CHECK_OFFSET(RGE_Player, sel_list, 0x134);
    CHECK_OFFSET(RGE_Player, groups_used, 0x19E);

    return 0;
}
