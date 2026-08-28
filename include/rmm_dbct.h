#ifndef AOE1_RMM_DBCT_H
#define AOE1_RMM_DBCT_H

// Compiler-facing declarations for the complete
// C:\\msdev\\work\\age1_x1\\rmm_dbct.cpp source module.
// The random-map base and generated-info records stay with their canonical
// owners. This controller owns only its database records and controller ABI.
#include "rmm_base.h"
#include "rmm_land.h"
#include "rmm_terrain_info.h"
#include "rmm_obj.h"
#include "rmm_elev.h"

class RGE_Game_World;

struct RGE_Land_Data_Entry {
    long land_id;
    uchar terrain_type;
    long land_avoidance_tiles;
    long base_square_radius;
    uchar zone;
    uchar placement_type;
    long x;
    long y;
    uchar amount_of_land_used_percent;
    uchar by_player_flag;
    long radius;
    long fade;
    long clumpiness_factor;
};

typedef char rmm_dbct_land_entry_size_check[
    (sizeof(RGE_Land_Data_Entry) == 0x2C) ? 1 : -1];

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

typedef char rmm_dbct_land_data_size_check[
    (sizeof(RGE_Land_Data) == 0x2C) ? 1 : -1];

struct RGE_Terrain_Data_Entry {
    long terrain_percent;
    long terrain_type;
    long clumps;
    long spacing;
    long base_terrain_type;
    long clumpiness_factor;
};

typedef char rmm_dbct_terrain_entry_size_check[
    (sizeof(RGE_Terrain_Data_Entry) == 0x18) ? 1 : -1];

struct RGE_Terrain_Data {
    long terrain_num;
    RGE_Terrain_Data_Entry* terrain;
};

typedef char rmm_dbct_terrain_data_size_check[
    (sizeof(RGE_Terrain_Data) == 0x08) ? 1 : -1];

struct RGE_Object_Data_Entry {
    long obj_id;
    long terrain;
    uchar group_flag;
    uchar scale_flag;
    long object_number_per_group;
    long object_number_varience;
    long number_of_groups;
    long group_area;
    long player_id;
    long land_id;
    long land_inner_radius;
    long land_outer_radius;
};

typedef char rmm_dbct_object_entry_size_check[
    (sizeof(RGE_Object_Data_Entry) == 0x2C) ? 1 : -1];

struct RGE_Object_Data {
    long object_num;
    RGE_Object_Data_Entry* objects;
};

typedef char rmm_dbct_object_data_size_check[
    (sizeof(RGE_Object_Data) == 0x08) ? 1 : -1];

struct RGE_Elevation_Data_Entry {
    long elevation_percent;
    long elevation;
    long clumps;
    long spacing;
    long base_terrain_type;
    long base_elevation_type;
};

typedef char rmm_dbct_elevation_entry_size_check[
    (sizeof(RGE_Elevation_Data_Entry) == 0x18) ? 1 : -1];

struct RGE_Elevation_Data {
    long elevation_num;
    RGE_Elevation_Data_Entry* elevation;
};

typedef char rmm_dbct_elevation_data_size_check[
    (sizeof(RGE_Elevation_Data) == 0x08) ? 1 : -1];

struct RGE_Map_Data_Entry {
    long map_id;
    RGE_Land_Data land_info;
    RGE_Terrain_Data terrain_info;
    RGE_Object_Data object_info;
    RGE_Elevation_Data elevation_info;
};

typedef char rmm_dbct_map_entry_size_check[
    (sizeof(RGE_Map_Data_Entry) == 0x48) ? 1 : -1];

struct RGE_Map_Data {
    long map_num;
    RGE_Map_Data_Entry* maps;
};

typedef char rmm_dbct_map_data_size_check[
    (sizeof(RGE_Map_Data) == 0x08) ? 1 : -1];

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

    RGE_RMM_Database_Controller(int file);
    RGE_RMM_Database_Controller(char* terrain_file, char* object_file,
        char* terrain_type_file, char* map_file);
    ~RGE_RMM_Database_Controller();
    virtual uchar generate();

protected:
    virtual void add_land_module(uchar value);
    virtual void add_terrain_module();
    virtual void add_object_module();
    virtual void add_elevation_module();
    void calc_land_start(long start, long radius, long count,
        RGE_Land_Data_Entry* land);

public:
    virtual uchar init(RGE_Map* map, RGE_Game_World* world,
        uchar map_type, long players, uchar value);
    virtual uchar de_init();
    uchar save(int file);
};

typedef char rmm_dbct_controller_size_check[
    (sizeof(RGE_RMM_Database_Controller) == 0x4F5C) ? 1 : -1];

#endif
