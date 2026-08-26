#ifndef RMM_DBCT_TU_CONTEXT_H
#define RMM_DBCT_TU_CONTEXT_H

// Complete local declaration surface for the authentic rmm_dbct.cpp wrapper.
// The owner sources keep their standalone declarations.  The wrapper includes
// this header so those declarations use one class and one layout.
// RMM_DBCT_CONTEXT_H also prevents owner-local includes from reopening a
// narrower per-function declaration surface.
#define RMM_DBCT_CONTEXT_H
#include "../include/rmm_base_context.h"

typedef unsigned char uchar;

class RGE_Game_World;
class RGE_Player;

struct RGE_Land_Data_Entry {
    long land_id;
    uchar terrain_type;
    uchar pad_05[3];
    long land_avoidance_tiles;
    long base_square_radius;
    uchar zone;
    uchar placement_type;
    uchar pad_12[2];
    long x;
    long y;
    uchar amount_of_land_used_percent;
    uchar by_player_flag;
    uchar pad_1E[2];
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
    uchar group_flag;
    uchar scale_flag;
    uchar pad_0[2];
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

struct RGE_Object_Info_Line {
    long obj_id;
    long terrain;
    uchar group_flag;
    uchar scale_flag;
    uchar pad_0[2];
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
    uchar zone;
    uchar pad_19[3];
    long clumpiness_factor;
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    uchar wall_fade;
    uchar pad_31[3];
};

struct RGE_Land_Info {
    RGE_Land_Info_Line land[99];
    long land_num;
    uchar base_terrain;
    uchar pad_1421[3];
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    uchar wall_fade;
    uchar pad_1435[3];
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

class RGE_Player {
public:
    uchar relation(long player);
};

class RGE_Game_World {
public:
    char gap_00[0x40];
    RGE_Player** players;
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
    union {
        RGE_Map_Data map_info;
        struct {
            long map_num;
            RGE_Map_Data_Entry* maps;
        };
    };

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

class RGE_RMM_Terrain_Generator : public RGE_Random_Map_Module {
public:
    uchar data[0x1298];
    void* map_zone;
    RGE_RMM_Terrain_Generator(RGE_Map* map,
        RGE_Random_Map_Module* parent, RGE_Terrain_Info* info);
};

class RGE_RMM_Land_Generator : public RGE_Random_Map_Module {
public:
    uchar data[0x1438];
    RGE_RMM_Land_Generator(RGE_Map* map,
        RGE_Random_Map_Module* parent, RGE_Land_Info* info);
};

class RGE_RMM_Object_Generator : public RGE_Random_Map_Module {
public:
    uchar data[0x18F0];
    RGE_RMM_Object_Generator(RGE_Map* map,
        RGE_Random_Map_Module* parent, RGE_Game_World* world,
        RGE_Object_Info* info, uchar add_terrain);
};

class RGE_RMM_Elevation_Generator : public RGE_Random_Map_Module {
public:
    uchar data[0xF80];
    RGE_RMM_Elevation_Generator(RGE_Map* map,
        RGE_Random_Map_Module* parent, RGE_Elevation_Info* info);
};

typedef char RMM_DBCT_LAND_ENTRY_SIZE_CHECK[
    (sizeof(RGE_Land_Data_Entry) == 0x2C) ? 1 : -1];
typedef char RMM_DBCT_MAP_ENTRY_SIZE_CHECK[
    (sizeof(RGE_Map_Data_Entry) == 0x48) ? 1 : -1];
typedef char RMM_DBCT_LAND_INFO_SIZE_CHECK[
    (sizeof(RGE_Land_Info) == 0x1438) ? 1 : -1];
typedef char RMM_DBCT_TERRAIN_INFO_SIZE_CHECK[
    (sizeof(RGE_Terrain_Info) == 0x1298) ? 1 : -1];
typedef char RMM_DBCT_OBJECT_INFO_SIZE_CHECK[
    (sizeof(RGE_Object_Info) == 0x18C8) ? 1 : -1];
typedef char RMM_DBCT_ELEVATION_INFO_SIZE_CHECK[
    (sizeof(RGE_Elevation_Info) == 0xF80) ? 1 : -1];

#endif
