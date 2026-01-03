#pragma once
#include "../common.h"
#include "rmm_base.h"
#include "World.h"

class RGE_RMM_Database_Controller : public RGE_Random_Map_Module {
public:
    RGE_Game_World* world;                   // 0x30
    long map_type;                           // 0x34
    long number_of_players;                  // 0x38
    RGE_Land_Info land_info;                 // 0x3C
    RGE_Terrain_Info terrain_info;           // 0x1474
    RGE_Object_Info object_info;             // 0x270C
    RGE_Elevation_Info elevation_info;       // 0x3FD4
    RGE_Map_Data map_info;                   // 0x4F54

    RGE_RMM_Database_Controller(char* param_1, char* param_2, char* param_3, char* param_4);
    RGE_RMM_Database_Controller(int param_1);
    virtual ~RGE_RMM_Database_Controller();
    virtual uchar save(int param_1);
    virtual uchar generate();
    virtual uchar init(RGE_Map* param_1, RGE_Game_World* param_2, uchar param_3, long param_4, uchar param_5);
    virtual uchar de_init();
    virtual void calc_land_start(long param_1, long param_2, long param_3, RGE_Land_Data_Entry* param_4);
    virtual void add_land_module(uchar param_1);
    virtual void add_terrain_module();
    virtual void add_object_module();
    virtual void add_elevation_module();
};

static_assert(sizeof(RGE_RMM_Database_Controller) == 0x4F5C, "RGE_RMM_Database_Controller Size Mismatch");
static_assert(offsetof(RGE_RMM_Database_Controller, map_info) == 0x4F54, "RGE_RMM_Database_Controller Offset Mismatch");

