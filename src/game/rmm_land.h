#pragma once
#include "common.h"

class RGE_RMM_Land_Generator : public RGE_Random_Map_Module {
public:
    RGE_Land_Info info;                      // 0x30

    virtual uchar generate();                               // vt0[0]+0x0=0x485240
    RGE_RMM_Land_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Land_Info* param_3);
    uchar check_terrain_and_zone(uchar param_1, uchar param_2, long param_3, long param_4);
    uchar chance(long param_1, long param_2, long param_3);
    uchar base_land_generate();
};

static_assert(sizeof(RGE_RMM_Land_Generator) == 0x1468, "RGE_RMM_Land_Generator Size Mismatch");

