// VA: 004C76C0 RGE_Static_Object::findClosestPointInTerrainType
// stat_obj.cpp

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
struct XYPoint {
    int x;
    int y;
};

class RGE_Zone_Map {
public:
    int findClosestPointInTerrainType(XYPoint point, XYPoint* out, int a, int b, int c);
};

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map* get_zone_map(int terrain, int terrain_size, int* zone_index);
    RGE_Zone_Map* get_zone_map(int zone_index);
};

struct RGE_Map {
    char gap_0000[0x8DC4];
    RGE_Zone_Map_List* map_zones;
};

struct RGE_World {
    char gap_00[0x28];
    RGE_Map* map;
    char gap_2C[0x10];
    int gap_3C;
    char gap_40[0x12];
    short terrain_size;
    int* terrains;
};

struct RGE_Player {
    char gap_00[0x3C];
    RGE_World* world;
};

struct RGE_Master_Static_Object {
    char gap_00[0x66];
    short terrain;
};

class RGE_Static_Object {
public:
    char gap_00[0x08];
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x6C];
    int zoneMapIndex;

    int findClosestPointInTerrainType(XYPoint point, XYPoint* out, int a, int b, int c);
};

#endif

int RGE_Static_Object::findClosestPointInTerrainType(XYPoint point, XYPoint* out, int a, int b, int c) {
    RGE_Zone_Map* zone_map;
    if (this->zoneMapIndex == -1) {
        RGE_Game_World* world = this->owner->world;
        zone_map = world->map->map_zones->get_zone_map(world->terrains[this->master_obj->terrain], world->terrain_size, &this->zoneMapIndex);
    } else {
        zone_map = this->owner->world->map->map_zones->get_zone_map(this->zoneMapIndex);
    }
    if (zone_map != 0) {
        return zone_map->findClosestPointInTerrainType(point, out, a, b, c);
    }
    return 0;
}
