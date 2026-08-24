// VA: 004C7530 | RGE_Static_Object::currentZone() | stat_obj.cpp:4706-4718 | 117 bytes
//
// Attempt log:
// [1] Sibling of lookupZone (004C7430). Same zone map logic, but converts
//     world_x/world_y (float) to int via __ftol for get_zone_info call.

#include "../../include/game_types.h"
#include <stdlib.h>

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Zone_Map {
public:
    unsigned char get_zone_info(int x, int y); // at 00546EB0
};

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map* get_zone_map_by_terrain(void* terrainRow, int terrainSize, int* outIndex); // at 005473B0
    RGE_Zone_Map* get_zone_map_by_index(int index); // at 005474B0
};

class RGE_Map {
public:
    char _gap_00[0x8DC4];
    RGE_Zone_Map_List* map_zones; // +0x8DC4
};

class RGE_Game_World {
public:
    char _gap_00[0x28];
    RGE_Map* map;                // +0x28
    char _gap_2C[0x24];
    short terrain_num;           // +0x50
    short terrain_size;          // +0x52
    float** terrains;            // +0x54
};

class RGE_Master_Static_Object {
public:
    char _gap_00[0x66];
    short terrain;               // +0x66
};

class RGE_Player {
public:
    char _gap_00[0x3C];
    RGE_Game_World* world;       // +0x3C
};

class RGE_Static_Object {
public:
    char _gap_00[0x08];
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner;                    // +0x0C
    char _gap_10[0x28];
    float world_x;                        // +0x38
    float world_y;                        // +0x3C
    char _gap_40[0x3C];
    int zoneMapIndex;                     // +0x7C

    unsigned char currentZone();
};

#endif

unsigned char RGE_Static_Object::currentZone() {
    RGE_Zone_Map* zoneMap;

    if (zoneMapIndex == -1) {
        RGE_Game_World* world = owner->world;
        zoneMap = world->map->map_zones->get_zone_map_by_terrain(
            world->terrains[master_obj->terrain],
            world->terrain_size,
            &zoneMapIndex);
    } else {
        RGE_Game_World* world = owner->world;
        zoneMap = world->map->map_zones->get_zone_map_by_index(zoneMapIndex);
    }

    if (zoneMap != 0) {
        return zoneMap->get_zone_info((int)world_x, (int)world_y);
    }

    return 0;
}
