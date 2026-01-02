#pragma once
#include "../common.h"

class RGE_RMM_Controller : public RGE_Random_Map_Module {
public:

    RGE_RMM_Controller(RGE_Map* param_1, RGE_Game_World* param_2, uchar param_3, long param_4);
    virtual uchar generate();
    virtual void add_land_module(RGE_Land_Info* param_1, long param_2, long param_3);
    virtual void add_terrain_module(RGE_Terrain_Info* param_1, RGE_Land_Info* param_2, long param_3);
    virtual long count_map_tiles(uchar param_1);
    virtual void add_object_module(RGE_Game_World* param_1, RGE_Land_Info* param_2);
};

static_assert(sizeof(RGE_RMM_Controller) == 0x30, "RGE_RMM_Controller Size Mismatch");

