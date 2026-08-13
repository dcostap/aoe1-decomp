// VA: 00483020 RGE_RMM_Database_Controller(int) (466B)
// rmm_dbct.cpp, EH-framed constructor (/GX)
//
// Baseline reconstruction: invoke the real random-map base constructor, read
// the map table, then allocate and read each owned land/terrain/object/elevation
// record block.  The aggregate layouts are named and exact-sized; ownership is
// expressed with typed records rather than decompiler offsets.
// Attempt log:
// - The typed baseline established the real /GX base-constructor and all
//   sixteen calls, but missed the original local frame and map-record stride.
// - A diagnostic byte-offset record cursor recovered the 0x10 frame and exact
//   size; splitting the map load and reversing the tail updates reached a
//   32-byte emitted-code mismatch.  That cursor/parameter-home path is not
//   retained in the clean source.
// - Current source keeps ordinary typed map-entry iteration; the remaining
//   codegen lead is the original stack-home/register schedule at the loop tail.
// - Making the base destructor virtual to match the same-TU donor did not
//   change emitted code; the EH frame and first prologue hunk remain open.
// - Adding the derived virtual-destructor declaration to the same fresh TU
//   also left emitted code unchanged; no EH handler or frame appeared.
// - Naming a local RGE_Map_Data* for the aggregate moved 336 bytes and made
//   the size three bytes shorter, so the member-based clean form is restored.

#include <stdlib.h>

extern void __cdecl rge_read(int file, void* data, int size);

class RGE_Map;
class RGE_Game_World;
class RGE_Tile;
class Map_Stack;

class RGE_Random_Map_Module {
public:
    virtual unsigned char generate();
    RGE_Random_Map_Module(RGE_Map* map, RGE_Random_Map_Module* parent,
                          unsigned char create_resources);
    ~RGE_Random_Map_Module();

    RGE_Random_Map_Module* parent;
    void* list;
    RGE_Map* map;
    RGE_Tile** map_row_offset;
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

    RGE_RMM_Database_Controller(int file);
    virtual unsigned char generate();
    virtual void add_land_module(unsigned char value);
    virtual void add_terrain_module();
    virtual void add_object_module();
    virtual void add_elevation_module();
    virtual unsigned char init(RGE_Map* map, RGE_Game_World* world,
                               unsigned char map_type, long players,
                               unsigned char value);
    virtual unsigned char de_init();
};

RGE_RMM_Database_Controller::RGE_RMM_Database_Controller(int file)
    : RGE_Random_Map_Module(0, 0, 0)
{
    this->world = 0;
    this->map_type = -1;
    this->number_of_players = 0;

    rge_read(file, &this->map_info, 8);
    if (this->map_info.map_num > 0) {
        this->map_info.maps = (RGE_Map_Data_Entry*)calloc(
            this->map_info.map_num, sizeof(RGE_Map_Data_Entry));
        rge_read(file, this->map_info.maps,
                 this->map_info.map_num * sizeof(RGE_Map_Data_Entry));

        int map_index = 0;
        RGE_Map_Data_Entry* map = this->map_info.maps;
        if (this->map_info.map_num > 0) {
            do {
                RGE_Land_Data* land_info = &map->land_info;
                RGE_Terrain_Data* terrain_info = &map->terrain_info;
                RGE_Object_Data* object_info = &map->object_info;
                RGE_Elevation_Data* elevation_info = &map->elevation_info;

                rge_read(file, land_info, sizeof(RGE_Land_Data));
                if (land_info->land_num > 0) {
                    land_info->land = (RGE_Land_Data_Entry*)calloc(
                        land_info->land_num, sizeof(RGE_Land_Data_Entry));
                    rge_read(file, land_info->land,
                             land_info->land_num * sizeof(RGE_Land_Data_Entry));
                }

                rge_read(file, terrain_info, sizeof(RGE_Terrain_Data));
                if (terrain_info->terrain_num > 0) {
                    terrain_info->terrain = (RGE_Terrain_Data_Entry*)calloc(
                        terrain_info->terrain_num, sizeof(RGE_Terrain_Data_Entry));
                    rge_read(file, terrain_info->terrain,
                             terrain_info->terrain_num * sizeof(RGE_Terrain_Data_Entry));
                }

                rge_read(file, object_info, sizeof(RGE_Object_Data));
                if (object_info->object_num > 0) {
                    object_info->objects = (RGE_Object_Data_Entry*)calloc(
                        object_info->object_num, sizeof(RGE_Object_Data_Entry));
                    rge_read(file, object_info->objects,
                             object_info->object_num * sizeof(RGE_Object_Data_Entry));
                }

                rge_read(file, elevation_info, sizeof(RGE_Elevation_Data));
                if (elevation_info->elevation_num > 0) {
                    elevation_info->elevation = (RGE_Elevation_Data_Entry*)calloc(
                        elevation_info->elevation_num, sizeof(RGE_Elevation_Data_Entry));
                    rge_read(file, elevation_info->elevation,
                             elevation_info->elevation_num * sizeof(RGE_Elevation_Data_Entry));
                }

                ++map_index;
                ++map;
            } while (map_index < this->map_info.map_num);
        }
    }
}
