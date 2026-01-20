#pragma once
#include "common.h"
#include "RGE_Random_Map_Module.h"

class RGE_RMM_Database_Controller : public RGE_Random_Map_Module {
public:
    // Virtuals (best-effort)
    virtual uchar generate(); // vt[0] (0x0)
    virtual void add_land_module(uchar param_1); // vt[1] (0x4)
    virtual void add_terrain_module(); // vt[2] (0x8)
    virtual void add_object_module(); // vt[3] (0xC)
    virtual void add_elevation_module(); // vt[4] (0x10)
    virtual uchar init(RGE_Map* param_1, RGE_Game_World* param_2, uchar param_3, long param_4, uchar param_5); // vt[5] (0x14)
    virtual uchar de_init(); // vt[6] (0x18)

    RGE_Game_World* world;
    long map_type;
    long number_of_players;
    RGE_Land_Info land_info;
    RGE_Terrain_Info terrain_info;
    RGE_Object_Info object_info;
    RGE_Elevation_Info elevation_info;
    RGE_Map_Data map_info;
};
static_assert(sizeof(RGE_RMM_Database_Controller) == 0x4F5C, "Size mismatch");
