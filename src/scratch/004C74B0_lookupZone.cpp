// target: VA 004C74B0 RGE_Static_Object::lookupZone(int,int)
// first pass: direct zone-map lookup with the negative coordinate gate and cached zone index path

class RGE_Zone_Map {
public:
    char gap_00[0x408];
    unsigned char** zone_map_rows;

    unsigned char get_zone_info(long x, long y);
};

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map* get_zone_map(long index);
    RGE_Zone_Map* get_zone_map_by_terrain(void* terrain_row, int terrain_size, int* out_index);
};

class RGE_Map {
public:
    char gap_00[0x8DC4];
    RGE_Zone_Map_List* map_zones;
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
    char gap_2C[0x24];
    short terrain_num;
    short terrain_size;
    float** terrains;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Master_Static_Object {
public:
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

    unsigned char lookupZone(int x, int y);
};

unsigned char RGE_Static_Object::lookupZone(int x, int y) {
    RGE_Game_World* world;
    RGE_Zone_Map* zone_map;

    if (x < 0 || y < 0) {
        return 0;
    }

    if (this->zoneMapIndex == -1) {
        world = this->owner->world;
        zone_map = world->map->map_zones->get_zone_map_by_terrain(
            world->terrains[this->master_obj->terrain],
            world->terrain_size,
            &this->zoneMapIndex);
    } else {
        zone_map = this->owner->world->map->map_zones->get_zone_map(this->zoneMapIndex);
    }

    if (zone_map == 0) {
        return 0;
    }

    return zone_map->get_zone_info(x, y);
}
