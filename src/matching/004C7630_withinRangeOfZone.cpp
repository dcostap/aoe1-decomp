// VA: 004C7630 RGE_Static_Object::withinRangeOfZone (135B)
// stat_obj.cpp
// Attempt log:
// - Previous scratch stub only returned/cached field_7C and produced 48-byte too-short body.
// - 2026-05-10 StarryZephyr pass: implemented packet behavior with local typed layout and zone-map calls.

class RGE_Zone_Map {
public:
    int withinRange(unsigned char type, int x, int y, float range);
};

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map* get_zone_map(int terrain_id, int terrain_size, int* cache_index);
    RGE_Zone_Map* get_zone_map(int index);
};

class RGE_Map {
public:
    char gap_0000[0x8DC4];
    RGE_Zone_Map_List* map_zones;
};

class RGE_World_Info {
public:
    char gap_00[0x28];
    RGE_Map* map;
    char gap_2C[0x52 - 0x2C];
    short terrain_size;
    int* terrains;
};

class RGE_Owner {
public:
    char gap_00[0x3C];
    RGE_World_Info* world;
};

class RGE_Master_Object {
public:
    char gap_00[0x66];
    short terrain;
};

class RGE_Static_Object {
public:
    char gap_00[0x08];
    RGE_Master_Object* master_obj;
    RGE_Owner* owner;
    char gap_10[0x38 - 0x10];
    float x;
    float y;
    char gap_40[0x7C - 0x40];
    int zoneMapIndex;

    int withinRangeOfZone(unsigned char type, float range);
};

extern "C" long __cdecl _ftol(void);

int RGE_Static_Object::withinRangeOfZone(unsigned char type, float range)
{
    int ix = (int)this->x;
    int iy = (int)this->y;
    RGE_Zone_Map* zone;

    if (this->zoneMapIndex == -1) {
        RGE_World_Info* world = this->owner->world;
        int terrain_id = world->terrains[this->master_obj->terrain];
        zone = world->map->map_zones->get_zone_map(terrain_id, world->terrain_size, &this->zoneMapIndex);
    } else {
        RGE_World_Info* world = this->owner->world;
        zone = world->map->map_zones->get_zone_map(this->zoneMapIndex);
    }

    if (zone != 0) {
        return zone->withinRange(type, ix, iy, range);
    }
    return 0;
}
