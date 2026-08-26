#ifndef RMM_DBCT_CONTEXT_H
#define RMM_DBCT_CONTEXT_H

#include "rmm_base_context.h"

// Canonical declarations for the authentic rmm_dbct.cpp owner sequence.
// The base layout is shared with rmm_obj.cpp. The record widths and controller
// offsets come from the exact constructor and destructor anchors.

class RGE_Game_World;

struct RGE_Land_Data_Entry {
    long land_id;                              // +0x00
    uchar terrain_type;                        // +0x04
    uchar pad_05[3];                           // +0x05
    long land_avoidance_tiles;                 // +0x08
    long base_square_radius;                   // +0x0C
    uchar zone;                                // +0x10
    uchar placement_type;                      // +0x11
    uchar pad_12[2];                           // +0x12
    long x;                                     // +0x14
    long y;                                     // +0x18
    uchar amount_of_land_used_percent;         // +0x1C
    uchar by_player_flag;                      // +0x1D
    uchar pad_1E[2];                            // +0x1E
    long radius;                                // +0x20
    long fade;                                  // +0x24
    long clumpiness_factor;                    // +0x28
};

struct RGE_Land_Data {
    long map_edge_buffer[4];                   // +0x00
    long map_edge_fade;                        // +0x10
    long land_placement_edge;                  // +0x14
    long base_terrain;                          // +0x18
    long grown_land_percent;                   // +0x1C
    long id;                                    // +0x20
    long land_num;                              // +0x24
    RGE_Land_Data_Entry* land;                 // +0x28
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

struct RGE_Land_Info_Line {
    long land_size;                            // +0x00
    long terrain_type;                         // +0x04
    long x;                                     // +0x08
    long y;                                     // +0x0C
    long base_size;                             // +0x10
    long area;                                  // +0x14
    uchar zone;                                // +0x18
    uchar pad_19[3];                            // +0x19
    long clumpiness_factor;                    // +0x1C
    long wall_1_avoidance_line;                // +0x20
    long wall_2_avoidance_line;                // +0x24
    long wall_3_avoidance_line;                // +0x28
    long wall_4_avoidance_line;                // +0x2C
    uchar wall_fade;                            // +0x30
    uchar pad_31[3];                            // +0x31
};

struct RGE_Land_Info {
    RGE_Land_Info_Line land[99];               // +0x00
    long land_num;                              // +0x141C
    uchar base_terrain;                         // +0x1420
    uchar pad_1421[3];                          // +0x1421
    long wall_1_avoidance_line;                // +0x1424
    long wall_2_avoidance_line;                // +0x1428
    long wall_3_avoidance_line;                // +0x142C
    long wall_4_avoidance_line;                // +0x1430
    uchar wall_fade;                            // +0x1434
    uchar pad_1435[3];                          // +0x1435
};

struct RGE_Terrain_Info {
    uchar data[0x1298];
};

struct RGE_Object_Info {
    uchar data[0x18C8];
};

struct RGE_Elevation_Info {
    uchar data[0xF80];
};

class RGE_RMM_Database_Controller : public RGE_Random_Map_Module {
public:
    RGE_Game_World* world;                     // +0x30
    long map_type;                              // +0x34
    long number_of_players;                     // +0x38
    RGE_Land_Info land_info;                    // +0x3C
    RGE_Terrain_Info terrain_info;              // +0x1474
    RGE_Object_Info object_info;                // +0x270C
    RGE_Elevation_Info elevation_info;          // +0x3FD4
    RGE_Map_Data map_info;                      // +0x4F54

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

public:
    virtual uchar init(RGE_Map* map, RGE_Game_World* world,
                       uchar map_type, long players, uchar value);
    virtual uchar de_init();
    uchar save(int file);

protected:
    void calc_land_start(long start, long radius, long count,
                         RGE_Land_Data_Entry* land);
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

#endif
