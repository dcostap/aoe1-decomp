#ifndef RMM_CNTR_CONTEXT_H
#define RMM_CNTR_CONTEXT_H

// Canonical declarations for C:\\msdev\\work\\age1_x1\\rmm_cntr.cpp.
//
// The PDB owner sequence is 004821A0, 00482260, 00482270, 004826E0,
// 004828A0, and 004828B0.  004826B2 and 0048287E are switch-data padding,
// not behavior owners.  The constructor, virtual tail, and map-count helper
// are exact anchors.  The land, terrain, and object helpers remain behavior
// reviewed scratch owners.
//
// Keep the map pointer and random-map base fields on their reviewed owners.
// The controller publishes its child modules through the inherited map/module
// surface.  Do not replace this typed surface with absolute map offsets.

#include "rmm_base_context.h"

typedef unsigned char uchar;

class RGE_Game_World;
class RGE_Zone_Map;

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

typedef char rmm_cntr_land_line_size_check[
    (sizeof(RGE_Land_Info_Line) == 0x34) ? 1 : -1];

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

typedef char rmm_cntr_land_info_size_check[
    (sizeof(RGE_Land_Info) == 0x1438) ? 1 : -1];

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

typedef char rmm_cntr_terrain_line_size_check[
    (sizeof(RGE_Terrain_Info_Line) == 0x20) ? 1 : -1];

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

typedef char rmm_cntr_terrain_info_size_check[
    (sizeof(RGE_Terrain_Info) == 0x1298) ? 1 : -1];

struct RGE_Object_Number_Per_Group {
    uchar _0_1_;
    uchar _1_1_;
    uchar pad[2];
};

struct RGE_Object_Info_Line {
    long obj_id;
    long terrain;
    union {
        struct {
            uchar group_flag;
            uchar scale_flag;
            unsigned short reserved;
        } bytes;
        unsigned long group_flags;
    } initial_flags;
    RGE_Object_Number_Per_Group object_number_per_group;
    long object_number_varience;
    long number_of_groups;
    long group_area;
    long player_id;
    long land_id;
    long land_inner_radius;
    long land_outer_radius;
    long object_exclusion_zone;
};

typedef char rmm_cntr_object_line_size_check[
    (sizeof(RGE_Object_Info_Line) == 0x30) ? 1 : -1];

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

typedef char rmm_cntr_object_info_size_check[
    (sizeof(RGE_Object_Info) == 0x18C8) ? 1 : -1];

class RGE_RMM_Land_Generator : public RGE_Random_Map_Module {
public:
    RGE_Land_Info info;

    virtual uchar generate();
    RGE_RMM_Land_Generator(RGE_Map* map,
        RGE_Random_Map_Module* parent, RGE_Land_Info* info);
};

typedef char rmm_cntr_land_generator_size_check[
    (sizeof(RGE_RMM_Land_Generator) == 0x1468) ? 1 : -1];

class RGE_RMM_Terrain_Generator : public RGE_Random_Map_Module {
public:
    RGE_Terrain_Info info;
    RGE_Zone_Map* map_zone;

    virtual uchar generate();
    RGE_RMM_Terrain_Generator(RGE_Map* map,
        RGE_Random_Map_Module* parent, RGE_Terrain_Info* info);
};

typedef char rmm_cntr_terrain_generator_size_check[
    (sizeof(RGE_RMM_Terrain_Generator) == 0x12CC) ? 1 : -1];

class RGE_RMM_Object_Generator : public RGE_Random_Map_Module {
public:
    RGE_Game_World* world;
    RGE_Object_Info info;
    uchar terrain_table[32];
    uchar add_terrain;
    uchar pad_191D[3];

    virtual uchar generate();
    RGE_RMM_Object_Generator(RGE_Map* map,
        RGE_Random_Map_Module* parent, RGE_Game_World* world,
        RGE_Object_Info* info, uchar add_terrain);
};

typedef char rmm_cntr_object_generator_size_check[
    (sizeof(RGE_RMM_Object_Generator) == 0x1920) ? 1 : -1];

class RGE_RMM_Controller : public RGE_Random_Map_Module {
public:
    RGE_RMM_Controller(RGE_Map* map, RGE_Game_World* world,
        uchar map_type, long number_of_players);
    virtual uchar generate();

protected:
    void add_land_module(RGE_Land_Info& land_info,
        long map_type, long number_of_players);
    void add_terrain_module(RGE_Terrain_Info& terrain_info,
        RGE_Land_Info& land_info, long map_type);
    void add_object_module(RGE_Game_World* world,
        RGE_Land_Info* land_info);
    long count_map_tiles(uchar ignored);
};

extern "C" int __cdecl debug_rand(char* file, int line);
extern char rmm_cntr_cpp_path[];

#endif
