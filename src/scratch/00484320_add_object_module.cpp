// VA: 00484320 add_object_module (325B)
//
// Baseline reconstruction: copy the map object's records into the controller's
// object-info records, then derive the land-point list and player ownership
// values from the map data.  The records and aggregate sizes are the generated
// binary-backed layouts; the body uses their named fields rather than raw
// offsets or decompiler cursor arithmetic.
// Attempt log:
// - Direct map-entry and typed-record ownership fixed the broad structure and
//   recovered the original repeated source-record loads.
// - A member-anchored pointer diagnostic recovered the original terrain/y
//   address topology but was rolled back as compiler-steering cursor plumbing.
// - Current clean candidate retains named map/object/land records; remaining
//   drift is the initial counter scheduling, two independent store orders, and
//   the associated two-byte loop-size difference.

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
        RGE_Object_Info_Line* destination = this->object_info.objects;
        int source_index = 0;
        do {
            destination->obj_id = map->object_info.objects[source_index].obj_id;
            destination->terrain = map->object_info.objects[source_index].terrain;
            destination->group_flag = map->object_info.objects[source_index].group_flag;
            destination->scale_flag = map->object_info.objects[source_index].scale_flag;
            destination->object_number_per_group =
                map->object_info.objects[source_index].object_number_per_group;
            destination->object_number_varience =
                map->object_info.objects[source_index].object_number_varience;
            destination->number_of_groups =
                map->object_info.objects[source_index].number_of_groups;
            destination->player_id = map->object_info.objects[source_index].player_id;
            destination->land_id = map->object_info.objects[source_index].land_id;
            destination->land_inner_radius =
                map->object_info.objects[source_index].land_inner_radius;
            destination->land_outer_radius =
                map->object_info.objects[source_index].land_outer_radius;
            destination->group_area = map->object_info.objects[source_index].group_area;
            destination->object_exclusion_zone = 1;
            ++destination;
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
        RGE_Land_Point_Info_Line* destination = this->object_info.lands;
        RGE_Land_Info_Line* source = this->land_info.land;
        do {
            destination->x = source->x;
            destination->y = source->y;
            destination->id = map->land_info.land[land_index].land_id;
            destination->player_id = player;

            if (player > 0) {
                ++player;
                if (player > this->number_of_players) {
                    player = 0;
                }
            }
            if (player == 0 &&
                map->land_info.land[land_index + 1].by_player_flag != 0) {
                player = 1;
            }

            ++destination;
            ++source;
            ++land_index;
        } while (land_index < this->land_info.land_num);
    }
}
