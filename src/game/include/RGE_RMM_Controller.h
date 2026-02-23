#pragma once
#include "common.h"
#include "RGE_Random_Map_Module.h"

struct RGE_Land_Info;
struct RGE_Terrain_Info;
struct RGE_Object_Info;

class RGE_RMM_Controller : public RGE_Random_Map_Module {
public:
    RGE_RMM_Controller(RGE_Map* param_1, RGE_Game_World* param_2, uchar param_3, long param_4);

    // Virtuals (best-effort)
    virtual uchar generate(); // vt[0] (0x0)

protected:
    void add_land_module(RGE_Land_Info* param_1, long param_2, long param_3);
    void add_terrain_module(RGE_Terrain_Info* param_1, RGE_Land_Info* param_2, long param_3);
    long count_map_tiles(uchar param_1);
    void add_object_module(RGE_Game_World* param_1, RGE_Land_Info* param_2);

};
static_assert(sizeof(RGE_RMM_Controller) == 0x30, "Size mismatch");
