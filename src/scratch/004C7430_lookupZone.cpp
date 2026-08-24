// VA: 004C7430 | RGE_Static_Object::lookupZone(XYPoint) | stat_obj.cpp:4664-4679 | 117 bytes
//
// Attempt log:
// [1] First attempt.

#include "../../include/game_types.h"

// XYPoint struct (x, y as ints)
#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
struct XYPoint {
    int x;
    int y;
};

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
    char _gap_10[0x6C];
    int zoneMapIndex;                     // +0x7C

    unsigned char lookupZone(XYPoint pt);
};

#endif

unsigned char RGE_Static_Object::lookupZone(XYPoint pt) {
    if (pt.x < 0 || pt.y < 0) {
        return 0;
    }

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

    if (zoneMap == 0) {
        return 0;
    }

    return zoneMap->get_zone_info(pt.x, pt.y);
}
