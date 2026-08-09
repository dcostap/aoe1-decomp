// VA: 00484470 add_elevation_module (578B)
// rmm_dbct.cpp, lines 962-1026
//
// Baseline reconstruction: derive four elevation rules from the selected map's
// grown-land area, then turn eligible map land records into elevation hot spots.
// The map records, controller aggregates, and source/destination line layouts
// are named and exact-sized; the loops use typed record ownership rather than
// the decompiler's byte cursors.
// Attempt log:
// - The initial typed array baseline matched the 0x8 frame and all six CFG
//   signals, but left a broad field-scheduling and hot-spot-loop mismatch.
// - Selected-map and selected-land aggregate aliases improved emitted shape;
//   the current natural form keeps the selected map entry and defers the
//   hot-spot counter until after rule initialization (445 differing bytes).
// - Reordered arithmetic, counter scopes, indexed land access, and a separate
//   typed cursor were tested.  A byte-stride cursor was diagnostic only and is
//   not retained; the remaining lead is VC5 register/liveness scheduling in
//   the rule stores and eligible-land loop.

struct RGE_Map;
struct RGE_Random_Map_Module_List;
struct Map_Stack;

struct RGE_Random_Map_Module {
    virtual unsigned char generate();
    RGE_Random_Map_Module* parent;
    RGE_Random_Map_Module_List* list;
    RGE_Map* map;
    void* map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    unsigned char* search_map;
    unsigned char** search_map_rows;
    Map_Stack* stack_array;
    Map_Stack** stack_offsets;
};

struct RGE_Land_Data_Entry {
    long land_id;
    unsigned char terrain_type;
    unsigned char pad_05[3];
    long land_avoidance_tiles;
    long base_square_radius;
    unsigned char zone;
    unsigned char placement_type;
    unsigned char pad_12[2];
    long x;
    long y;
    unsigned char amount_of_land_used_percent;
    unsigned char by_player_flag;
    unsigned char pad_1e[2];
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

struct RGE_Land_Info_Line {
    long land_size;
    long terrain_type;
    long x;
    long y;
    long base_size;
    long area;
    unsigned char zone;
    unsigned char pad_19[3];
    long clumpiness_factor;
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    unsigned char wall_fade;
    unsigned char pad_31[3];
};

struct RGE_Land_Info {
    RGE_Land_Info_Line land[99];
    long land_num;
    unsigned char base_terrain;
    unsigned char pad_1421[3];
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    unsigned char wall_fade;
    unsigned char pad_end[3];
};

struct RGE_Terrain_Data {
    long terrain_num;
    void* terrain;
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

struct RGE_Elevation_Info_Line {
    long elevation_size;
    long elevation;
    long clumps;
    long spacing;
    long base_elevation;
    long base_terrain_type;
};

struct RGE_Elevation_Hot_Spots {
    long x;
    long y;
    long radius;
    long fade;
};

struct RGE_Elevation_Info {
    RGE_Elevation_Info_Line elevation[99];
    long elevation_num;
    RGE_Elevation_Hot_Spots hot_spots[99];
    long hot_spot_num;
};

struct RGE_Game_World;

struct RGE_RMM_Database_Controller : RGE_Random_Map_Module {
    RGE_Game_World* world;
    long map_type;
    long number_of_players;
    RGE_Land_Info land_info;
    char terrain_info[0x1298];
    char object_info[0x18C8];
    RGE_Elevation_Info elevation_info;
    RGE_Map_Data map_info;

    virtual void add_elevation_module();
};

void RGE_RMM_Database_Controller::add_elevation_module()
{
    int map_type = this->map_type;
    RGE_Map_Data_Entry* map = this->map_info.maps + map_type;
    int land_area = (this->map_width *
                     map->land_info.grown_land_percent *
                     this->map_height) / 100;

    this->elevation_info.elevation_num = 4;

    this->elevation_info.elevation[0].elevation = 1;
    this->elevation_info.elevation[0].clumps = 10;
    this->elevation_info.elevation[0].base_terrain_type = 0;
    this->elevation_info.elevation[0].base_elevation = 0;
    this->elevation_info.elevation[0].spacing = 2;
    this->elevation_info.elevation[0].elevation_size =
        (land_area * 10) / 100;

    this->elevation_info.elevation[1].elevation = 2;
    this->elevation_info.elevation[1].elevation_size =
        (land_area * 8) / 100;
    this->elevation_info.elevation[1].clumps = 8;
    this->elevation_info.elevation[1].base_terrain_type = 0;
    this->elevation_info.elevation[1].base_elevation = 1;
    this->elevation_info.elevation[1].spacing = 1;

    this->elevation_info.elevation[2].elevation_size =
        (land_area * 6) / 100;
    this->elevation_info.elevation[2].elevation = 3;
    this->elevation_info.elevation[2].clumps = 6;
    this->elevation_info.elevation[2].base_terrain_type = 0;
    this->elevation_info.elevation[2].base_elevation = 2;
    this->elevation_info.elevation[2].spacing = 1;

    this->elevation_info.elevation[3].elevation_size =
        (land_area * 4) / 100;
    this->elevation_info.elevation[3].elevation = 4;
    this->elevation_info.elevation[3].clumps = 4;
    this->elevation_info.elevation[3].base_terrain_type = 0;
    this->elevation_info.elevation[3].base_elevation = 3;
    this->elevation_info.elevation[3].spacing = 1;

    int hot_spot_num = 0;
    RGE_Land_Data_Entry* map_land = map->land_info.land;
    int land_index = 0;
    if (map->land_info.land_num > 0) {
        do {
            if (map_land->radius >= 0) {
                if (map_land->by_player_flag == 0) {
                    this->elevation_info.hot_spots[hot_spot_num].x =
                        this->land_info.land[hot_spot_num].x;
                    this->elevation_info.hot_spots[hot_spot_num].y =
                        this->land_info.land[hot_spot_num].y;
                    this->elevation_info.hot_spots[hot_spot_num].radius =
                        map_land->radius;
                    this->elevation_info.hot_spots[hot_spot_num].fade =
                        map_land->fade;
                    ++hot_spot_num;
                } else {
                    int player_index = 0;
                    if (this->number_of_players > 0) {
                        do {
                            this->elevation_info.hot_spots[hot_spot_num].x =
                                this->land_info.land[hot_spot_num].x;
                            this->elevation_info.hot_spots[hot_spot_num].y =
                                this->land_info.land[hot_spot_num].y;
                            this->elevation_info.hot_spots[hot_spot_num].radius =
                                map_land->radius;
                            this->elevation_info.hot_spots[hot_spot_num].fade =
                                map_land->fade;
                            ++hot_spot_num;
                            ++player_index;
                        } while (player_index < this->number_of_players);
                    }
                }
            }
            ++land_index;
            ++map_land;
        } while (land_index < map->land_info.land_num);
    }

    this->elevation_info.hot_spot_num = hot_spot_num;
}
