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
// Fresh pass:
// - Dossier, same-TU donors, and ABI evidence confirm controller offsets
//   0x14/0x18/0x34/0x38, map stride 0x48, and serialized line sizes 0x18/0x2C.
// - Replaced raw object/elevation module blocks with named fixed aggregates
//   and typed map records.  The emitted code moved three bytes farther, but
//   the source now preserves the complete serialized layout.
// - A typed hot-spot pointer loop regressed structure and was rolled back.
//   The indexed source remains the clearer behavior reconstruction.
// - Direct indexed land members, positive by-player fall-through, and a
//   map-source terrain-count guard recovered the target's 448-byte boundary,
//   137 instructions, frame 0xC, CFG, call, and all but six bytes.
// - The remaining six bytes are four stack-displacement fields: the target
//   reuses [esp+10h] for the outer land count and [esp+14h] for player count;
//   this natural source emits those homes in reverse. Scope, order, and width
//   probes did not change the basin. Do not retain stack-only steering.
// Revisit:
// - Removing the separate land_index and using land_tile_num for both the
//   terrain and land indexed loops recovered the target's natural counter
//   lifetime. The typed source now emits an authoritative 448-byte MATCH.

#include "../../include/game_globals.h"

#ifndef RMM_DBCT_TU_CONTEXT_H
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

struct RGE_Object_Data {
    long object_num;
    void* objects;
};

struct RGE_Elevation_Data {
    long elevation_num;
    void* elevation;
};

struct RGE_Map_Data_Entry {
    long map_id;
    RGE_Land_Data land_info;
    RGE_Terrain_Data terrain_info;
    RGE_Object_Data object_info;
    RGE_Elevation_Data elevation_info;
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

struct RGE_Object_Info {
    unsigned char data[0x18C8];
};

struct RGE_Elevation_Info {
    unsigned char data[0xF80];
};

class RGE_RMM_Database_Controller : public RGE_Random_Map_Module {
public:
    RGE_Game_World* world;
    long map_type;
    long number_of_players;
    RGE_Land_Info land_info;
    RGE_Terrain_Info terrain_info;
    RGE_Object_Info object_info;
    RGE_Elevation_Info elevation_info;
    RGE_Map_Data map_info;

    virtual void add_terrain_module();
};
#endif

void RGE_RMM_Database_Controller::add_terrain_module()
{
    RGE_Map_Data_Entry* map;
    map = this->map_info.maps + this->map_type;
    long land_tile_num = 0;
    long land_area = this->map_width * this->map_height *
        this->map_info.maps[this->map_type].land_info.grown_land_percent / 100;

    this->terrain_info.terrain_num = map->terrain_info.terrain_num;
    if (map->terrain_info.terrain_num > 0) {
        do {
            this->terrain_info.terrain[land_tile_num].terrain_size = (long)(
                (float)(map->terrain_info.terrain[land_tile_num].terrain_percent * land_area) * DAT_00571ec0);
            this->terrain_info.terrain[land_tile_num].terrain_type =
                map->terrain_info.terrain[land_tile_num].terrain_type;
            this->terrain_info.terrain[land_tile_num].clumps =
                map->terrain_info.terrain[land_tile_num].clumps;
            this->terrain_info.terrain[land_tile_num].base_terrain_type =
                map->terrain_info.terrain[land_tile_num].base_terrain_type;
            this->terrain_info.terrain[land_tile_num].terrain_generated = 0;
            this->terrain_info.terrain[land_tile_num].spacing =
                map->terrain_info.terrain[land_tile_num].spacing;
            this->terrain_info.terrain[land_tile_num].clumpiness_factor =
                map->terrain_info.terrain[land_tile_num].clumpiness_factor;
            this->terrain_info.terrain[land_tile_num].avoid_hot_spots = 1;

            ++land_tile_num;
        } while (land_tile_num < map->terrain_info.terrain_num);
    }

    int hot_spot_index = 0;
    int player_index = 0;
    land_tile_num = 0;
    if (land_tile_num < map->land_info.land_num) {
        do {
            if (map->land_info.land[land_tile_num].radius >= 0) {
                if (map->land_info.land[land_tile_num].by_player_flag != 0) {
                    player_index = 0;
                    if (this->number_of_players > 0) {
                        do {
                            this->terrain_info.hot_spots[hot_spot_index].x =
                                this->land_info.land[hot_spot_index].x;
                            this->terrain_info.hot_spots[hot_spot_index].y =
                            this->land_info.land[hot_spot_index].y;
                            this->terrain_info.hot_spots[hot_spot_index].radius =
                                map->land_info.land[land_tile_num].radius;
                            this->terrain_info.hot_spots[hot_spot_index].fade =
                                map->land_info.land[land_tile_num].fade;
                            ++hot_spot_index;
                            ++player_index;
                        } while (player_index < this->number_of_players);
                    }
                } else {
                    this->terrain_info.hot_spots[hot_spot_index].x =
                        this->land_info.land[hot_spot_index].x;
                    this->terrain_info.hot_spots[hot_spot_index].y =
                    this->land_info.land[hot_spot_index].y;
                    this->terrain_info.hot_spots[hot_spot_index].radius =
                        map->land_info.land[land_tile_num].radius;
                    this->terrain_info.hot_spots[hot_spot_index].fade =
                        map->land_info.land[land_tile_num].fade;
                    ++hot_spot_index;
                }
            }

            ++land_tile_num;
        } while (land_tile_num < map->land_info.land_num);
    }

    this->terrain_info.hot_spot_num = hot_spot_index;
}
