#pragma once
#include "common.h"
#include "RGE_Random_Map_Module.h"

class RGE_Zone_Map;

class RGE_RMM_Terrain_Generator : public RGE_Random_Map_Module {
public:
    RGE_RMM_Terrain_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Terrain_Info* param_3);

    // Virtuals (best-effort)
    virtual uchar generate(); // vt[0] (0x0)

    RGE_Terrain_Info info;
    RGE_Zone_Map* map_zone;
};
static_assert(sizeof(RGE_RMM_Terrain_Generator) == 0x12CC, "Size mismatch");
