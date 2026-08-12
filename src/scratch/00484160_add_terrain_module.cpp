// VA: 00484160 add_terrain_module (448B)
//
// Baseline reconstruction: derive terrain sizes from the map area, copy the
// terrain records, and build hot spots from eligible map-land records.  The
// source keeps the map, terrain, and land ownership typed and named.
// Attempt log:
// - The clean typed baseline matched the single __ftol call, frame, CFG, and
//   hot-spot behavior but was 41 bytes short.
// - Named controller/terrain-data aliases were neutral.  A diagnostic
//   member-anchored/source-offset form reached exact size and improved shape,
//   but was rolled back as raw cursor plumbing.
// - Current source retains canonical typed arrays and natural indexed loops;
//   remaining lead is the source/destination cursor topology and register
//   roles in the terrain copy, with later hot-spot drift dependent on it.
// - Fresh dossier and same-TU donor review confirm the map-entry stride 0x48,
//   terrain record stride 0x18, land stride 0x2C, and the single __ftol call.
// - Fresh direct-map and shared-counter forms changed frame or size but not
//   the first structural hunk; explicit controller ownership was a duplicate.
// - Repeated typed source fields overran the target by 80 bytes.  Hoisted
//   counters recovered EBX as this but grew the frame to 0x14.  Both were
//   rolled back.
// - A terrain_type-anchored output cursor moved shape from 45.71% to 46.43%
//   without positional gain.  It was rolled back as opaque field plumbing.
// - Fresh pass remains paused: exact call parity and frame parity hold, but
//   the terrain-copy topology is still structurally unresolved.

#include "../../include/game_globals.h"

class RGE_Map;
class RGE_Game_World;

class RGE_Random_Map_Module {
public:
    virtual ~RGE_Random_Map_Module();

    RGE_Random_Map_Module* parent;
    void* list;
    RGE_Map* map;
    void* map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    unsigned char* search_map;
    void* stack_array;
    unsigned char** search_map_rows;
    void* stack_offsets;
};

struct RGE_Land_Data_Entry {
    long land_id;
    unsigned char terrain_type;
    unsigned char pad_0[3];
    long land_avoidance_tiles;
    long base_square_radius;
    unsigned char zone;
    unsigned char placement_type;
    unsigned char pad_1[2];
    long x;
    long y;
    unsigned char amount_of_land_used_percent;
    unsigned char by_player_flag;
    unsigned char pad_2[2];
    long radius;
    long fade;
    long clumpiness_factor;
};

struct RGE_Land_Data {
    long map_edge_buffer[4];
    long map_edge_fade;
    long land_placement_edge;
    long base_terrain;
    long grown_land_percent;
    long id;
    long land_num;
    RGE_Land_Data_Entry* land;
};

struct RGE_Terrain_Data_Entry {
    long terrain_percent;
    long terrain_type;
    long clumps;
    long spacing;
    long base_terrain_type;
    long clumpiness_factor;
};

struct RGE_Terrain_Data {
    long terrain_num;
    RGE_Terrain_Data_Entry* terrain;
};

struct RGE_Map_Data_Entry {
    long map_id;
    RGE_Land_Data land_info;
    RGE_Terrain_Data terrain_info;
    unsigned char object_info[8];
    unsigned char elevation_info[8];
};

struct RGE_Map_Data {
    long map_num;
    RGE_Map_Data_Entry* maps;
};

struct RGE_Terrain_Info_Line {
    long terrain_size;
    long terrain_generated;
    long terrain_type;
    long clumps;
    long spacing;
    long base_terrain_type;
    long clumpiness_factor;
    long avoid_hot_spots;
};

struct RGE_Terrain_Hot_Spots {
    long x;
    long y;
    long radius;
    long fade;
};

struct RGE_Terrain_Info {
    RGE_Terrain_Info_Line terrain[99];
    long terrain_num;
    RGE_Terrain_Hot_Spots hot_spots[99];
    long hot_spot_num;
};

struct RGE_Land_Info_Line {
    long land_size;
    long terrain_type;
    long x;
    long y;
    long base_size;
    long area;
    unsigned char zone;
    unsigned char pad_0[3];
    long clumpiness_factor;
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    unsigned char wall_fade;
    unsigned char pad_end[3];
};

struct RGE_Land_Info {
    RGE_Land_Info_Line land[99];
    long land_num;
    unsigned char base_terrain;
    unsigned char pad_0[3];
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    unsigned char wall_fade;
    unsigned char pad_end[3];
};

class RGE_RMM_Database_Controller : public RGE_Random_Map_Module {
public:
    RGE_Game_World* world;
    long map_type;
    long number_of_players;
    RGE_Land_Info land_info;
    RGE_Terrain_Info terrain_info;
    unsigned char object_info[0x18C8];
    unsigned char elevation_info[0xF80];
    RGE_Map_Data map_info;

    virtual void add_terrain_module();
};

void RGE_RMM_Database_Controller::add_terrain_module()
{
    RGE_Map_Data_Entry* map = this->map_info.maps + this->map_type;
    long land_area = this->map_width * this->map_height;
    land_area = land_area * map->land_info.grown_land_percent / 100;
    int terrain_index = 0;

    this->terrain_info.terrain_num = map->terrain_info.terrain_num;
    if (this->terrain_info.terrain_num > 0) {
        RGE_Terrain_Info_Line* destination = this->terrain_info.terrain;
        RGE_Terrain_Data_Entry* source = map->terrain_info.terrain;
        do {
            destination->terrain_size = (long)(
                (float)(source->terrain_percent * land_area) * DAT_00571ec0);
            destination->terrain_type = source->terrain_type;
            destination->clumps = source->clumps;
            destination->base_terrain_type = source->base_terrain_type;
            destination->terrain_generated = 0;
            destination->spacing = source->spacing;
            destination->clumpiness_factor = source->clumpiness_factor;
            destination->avoid_hot_spots = 1;

            ++terrain_index;
            ++destination;
            ++source;
        } while (terrain_index < map->terrain_info.terrain_num);
    }

    int hot_spot_index = 0;
    int land_index = 0;
    int land_count = 0;
    if (map->land_info.land_num > 0) {
        do {
            RGE_Land_Data_Entry* land = &map->land_info.land[land_index];
            if (land->radius >= 0) {
                if (land->by_player_flag == 0) {
                    this->terrain_info.hot_spots[hot_spot_index].x =
                        this->land_info.land[hot_spot_index].x;
                    this->terrain_info.hot_spots[hot_spot_index].y =
                        this->land_info.land[hot_spot_index].y;
                    this->terrain_info.hot_spots[hot_spot_index].radius = land->radius;
                    this->terrain_info.hot_spots[hot_spot_index].fade = land->fade;
                    ++hot_spot_index;
                } else {
                    int player_index = 0;
                    if (this->number_of_players > 0) {
                        do {
                            this->terrain_info.hot_spots[hot_spot_index].x =
                                this->land_info.land[hot_spot_index].x;
                            this->terrain_info.hot_spots[hot_spot_index].y =
                                this->land_info.land[hot_spot_index].y;
                            this->terrain_info.hot_spots[hot_spot_index].radius = land->radius;
                            this->terrain_info.hot_spots[hot_spot_index].fade = land->fade;
                            ++hot_spot_index;
                            ++player_index;
                        } while (player_index < this->number_of_players);
                    }
                }
            }

            ++land_count;
            ++land_index;
        } while (land_count < map->land_info.land_num);
    }

    this->terrain_info.hot_spot_num = hot_spot_index;
}
