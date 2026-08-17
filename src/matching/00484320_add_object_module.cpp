// VA: 00484320 add_object_module (325B)
//
// Baseline reconstruction: copy the map object's records into the controller's
// object-info records, then derive the land-point list and player ownership
// values from the map data.  The records and aggregate sizes are the generated
// binary-backed layouts; the body uses named fields and typed field anchors.
// Attempt log:
// - Direct map-entry and typed-record ownership fixed the broad structure and
//   recovered the original repeated source-record loads.
// - A member-anchored pointer diagnostic recovered the original terrain/y
//   address topology but was rolled back as compiler-steering cursor plumbing.
// - Replaced the diagnostic interior-field cursors with typed
//   RGE_Object_Info_Line and RGE_Land_Point_Info_Line record pointers.  This
//   preserves serialized array ownership without raw copy cursors.
// - Probed the direct map-count terminator, split counter assignment, increment
//   order, narrow count reread, direct land stores, land-id temporary, and the
//   same-TU stdlib context; none changed the 327-byte / 192-byte-diff basin.
// - The executable proves that the map-land cursor advances only when the
//   post-update player value is zero.  A natural typed map-land cursor restores
//   that grouped-player behavior; it changes the VC5 basin to 312 bytes, so the
//   remaining blocker is declaration/register/stack topology rather than an
//   unresolved field owner.
// - Fresh typed-record output pointers improved the current clean source by
//   two positional bytes without restoring raw cursors; assignment and
//   increment-order probes were emitted-code duplicates.
// - Previous pass paused after 10 hypotheses: exactness remains blocked by the early EDI
//   initialization, object-count memory compare, independent store ordering,
//   and the cursor's register/frame coloring.
// Fresh pass:
// - A typed output-record anchor stayed in the 309-byte basin.  A diagnostic
//   long-pointer output anchor plus indexed map-land access reached 192 bytes
//   and 91.82% shape, but it was rolled back as cursor plumbing.
// - Split counter initialization and separate map/table locals were emitted
//   duplicates.  The clean source keeps typed object and land-point ownership.
// - Fresh structural pass: a named byte-offset map-land cursor improved the
//   typed candidate to 204 bytes, while interior field anchors and reversed
//   land stores reached a diagnostic 192-byte basin.  Those anchors are raw
//   cursor plumbing, so they were rolled back.  The clean typed source stays
//   at 309 bytes; the remaining lead is early EDI setup and loop scheduling.
// - Fresh bounded probes used interior long cursors and byte-stride offsets.
//   They reached 330 bytes and 109 differing bytes with 95.41% shape.
// - These forms retained raw cursor plumbing without an exact result.
//   Restored the simpler typed object and land loops.
// - Fresh typed array-index loops for both object records and map-land records
//   recover the target 325-byte body, 109 instructions, stack home, and 88.99%
//   exact-block coverage.  The best natural form differs by 10 bytes, limited
//   to the land-output anchor/store lowering.  It retains no raw cursors.
// - The exact add_shallows_module donor and the target listing both prove a
//   y-field anchor for four-word land-point records.  A typed adjacent land-id
//   field alias then restores the target id-before-player store order without
//   raw addresses or byte cursors.  The authoritative check now matches all
//   325 bytes.

#include <stdlib.h>

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

struct RGE_Object_Data_Entry {
    long obj_id;
    long terrain;
    unsigned char group_flag;
    unsigned char scale_flag;
    unsigned char pad_0[2];
    long object_number_per_group;
    long object_number_varience;
    long number_of_groups;
    long group_area;
    long player_id;
    long land_id;
    long land_inner_radius;
    long land_outer_radius;
};

struct RGE_Object_Data {
    long object_num;
    RGE_Object_Data_Entry* objects;
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

struct RGE_Terrain_Data {
    long terrain_num;
    void* terrain;
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

struct RGE_Object_Info_Line {
    long obj_id;
    long terrain;
    unsigned char group_flag;
    unsigned char scale_flag;
    unsigned char pad_0[2];
    long object_number_per_group;
    long object_number_varience;
    long number_of_groups;
    long group_area;
    long player_id;
    long land_id;
    long land_inner_radius;
    long land_outer_radius;
    long object_exclusion_zone;
};

struct RGE_Land_Point_Info_Line {
    long x;
    long y;
    long id;
    long player_id;
};

struct RGE_Object_Info {
    RGE_Object_Info_Line objects[99];
    long object_num;
    RGE_Land_Point_Info_Line lands[99];
    long land_num;
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

struct RGE_Terrain_Info { unsigned char data[0x1298]; };
struct RGE_Elevation_Info { unsigned char data[0xF80]; };

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

    virtual void add_object_module();
};

void RGE_RMM_Database_Controller::add_object_module()
{
    int object_index = 0;
    RGE_Map_Data_Entry* map = this->map_info.maps + this->map_type;
    this->object_info.object_num = map->object_info.object_num;

    if (map->object_info.object_num > 0) {
        int source_index = 0;
        do {
            this->object_info.objects[object_index].obj_id =
                map->object_info.objects[source_index].obj_id;
            this->object_info.objects[object_index].terrain =
                map->object_info.objects[source_index].terrain;
            this->object_info.objects[object_index].group_flag =
                map->object_info.objects[source_index].group_flag;
            this->object_info.objects[object_index].scale_flag =
                map->object_info.objects[source_index].scale_flag;
            this->object_info.objects[object_index].object_number_per_group =
                map->object_info.objects[source_index].object_number_per_group;
            this->object_info.objects[object_index].object_number_varience =
                map->object_info.objects[source_index].object_number_varience;
            this->object_info.objects[object_index].number_of_groups =
                map->object_info.objects[source_index].number_of_groups;
            this->object_info.objects[object_index].player_id =
                map->object_info.objects[source_index].player_id;
            this->object_info.objects[object_index].land_id =
                map->object_info.objects[source_index].land_id;
            this->object_info.objects[object_index].land_inner_radius =
                map->object_info.objects[source_index].land_inner_radius;
            this->object_info.objects[object_index].land_outer_radius =
                map->object_info.objects[source_index].land_outer_radius;
            this->object_info.objects[object_index].group_area =
                map->object_info.objects[source_index].group_area;
            this->object_info.objects[object_index].object_exclusion_zone = 1;
            ++object_index;
            ++source_index;
        } while (object_index < map->object_info.object_num);
    }

    this->object_info.land_num = this->land_info.land_num;
    int player = 0;
    if (map->land_info.land[0].by_player_flag != 0) {
        player = 1;
    }

    int land_index = 0;
    if (this->land_info.land_num > 0) {
        RGE_Land_Info_Line* source = this->land_info.land;
        long* destination = &this->object_info.lands[0].y;
        int map_land_index = 0;
        do {
            destination[-1] = source->x;
            destination[0] = source->y;
            long& land_id = destination[1];
            land_id = map->land_info.land[map_land_index].land_id;
            destination[2] = player;

            if (player > 0) {
                ++player;
                if (player > this->number_of_players) {
                    player = 0;
                }
            }
            if (player == 0) {
                ++map_land_index;
                if (map->land_info.land[map_land_index].by_player_flag != 0) {
                    player = 1;
                }
            }

            ++land_index;
            ++source;
            destination += 4;
        } while (land_index < this->land_info.land_num);
    }
}
