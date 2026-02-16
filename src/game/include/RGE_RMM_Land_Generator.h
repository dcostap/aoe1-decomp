#pragma once
#include "common.h"
#include "RGE_Random_Map_Module.h"

class RGE_RMM_Land_Generator : public RGE_Random_Map_Module {
public:
    RGE_RMM_Land_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Land_Info* param_3);

    // Virtuals (best-effort)
    virtual uchar generate(); // vt[0] (0x0)

protected:
    uchar check_terrain_and_zone(uchar param_1, uchar param_2, long param_3, long param_4);
    uchar chance(long param_1, long param_2, long param_3);
    uchar base_land_generate();

    RGE_Land_Info info;
};
static_assert(sizeof(RGE_RMM_Land_Generator) == 0x1468, "Size mismatch");
