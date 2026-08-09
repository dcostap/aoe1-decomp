// VA: 004832E0 save (336B)
//
// Baseline reconstruction: serialize the database header, map table, and each
// map's four owned record blocks through the period rge_write surface.  The
// aggregate layouts are named and sized from the binary-backed map records.
// Attempt log:
// - Typed map-entry iteration was the initial clean source and matched all ten
//   rge_write targets but missed the original local frame.
// - Explicit controller/map-info ownership plus named per-record pointers
//   recovered the 0x10 frame, saved-register set, boundary, and call layout.
// - A diagnostic byte-offset cursor reproduced the remaining stack schedule
//   and reached a 22-byte mismatch, but was rolled back as raw cursor plumbing.
// - Current clean source keeps typed map iteration; remaining codegen lead is
//   the land-payload multiply/pointer evaluation order.

extern "C" {
    void rge_write(int file, void* data, int size);
}

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

struct RGE_Elevation_Data_Entry {
    long elevation_percent;
    long elevation;
    long clumps;
    long spacing;
    long base_terrain_type;
    long base_elevation_type;
};

struct RGE_Elevation_Data {
    long elevation_num;
    RGE_Elevation_Data_Entry* elevation;
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

class RGE_RMM_Database_Controller : public RGE_Random_Map_Module {
public:
    RGE_Game_World* world;
    long map_type;
    long number_of_players;
    unsigned char land_info[0x1438];
    unsigned char terrain_info[0x1298];
    unsigned char object_info[0x18C8];
    unsigned char elevation_info[0xF80];
    RGE_Map_Data map_info;

    virtual unsigned char generate();
    virtual unsigned char save(int file);
};

unsigned char RGE_RMM_Database_Controller::save(int file)
{
    int file_handle = file;
    RGE_RMM_Database_Controller* controller = this;
    RGE_Map_Data* data = &controller->map_info;

    rge_write(file_handle, data, 8);

    if (data->map_num > 0) {
        rge_write(file_handle, controller->map_info.maps,
                  data->map_num * sizeof(RGE_Map_Data_Entry));

        int map_index = 0;
        RGE_Map_Data_Entry* map = controller->map_info.maps;
        if (data->map_num > 0) {
            do {
            RGE_Land_Data* land_info = &map->land_info;
            RGE_Terrain_Data* terrain_info = &map->terrain_info;
            RGE_Object_Data* object_info = &map->object_info;
            RGE_Elevation_Data* elevation_info = &map->elevation_info;

            rge_write(file_handle, land_info, sizeof(RGE_Land_Data));
            int land_count = land_info->land_num;
            if (land_count > 0) {
                int land_bytes = sizeof(RGE_Land_Data_Entry) * land_count;
                RGE_Land_Data_Entry* land = land_info->land;
                rge_write(file_handle, land, land_bytes);
            }

            rge_write(file_handle, terrain_info, sizeof(RGE_Terrain_Data));
            if (terrain_info->terrain_num > 0) {
                rge_write(file_handle, terrain_info->terrain,
                          terrain_info->terrain_num * sizeof(RGE_Terrain_Data_Entry));
            }

            rge_write(file_handle, object_info, sizeof(RGE_Object_Data));
            if (object_info->object_num > 0) {
                rge_write(file_handle, object_info->objects,
                          object_info->object_num * sizeof(RGE_Object_Data_Entry));
            }

            rge_write(file_handle, elevation_info, sizeof(RGE_Elevation_Data));
            if (elevation_info->elevation_num > 0) {
                rge_write(file_handle, elevation_info->elevation,
                          elevation_info->elevation_num * sizeof(RGE_Elevation_Data_Entry));
            }

            ++map_index;
            ++map;
            } while (map_index < data->map_num);
        }
    }

    return 1;
}
