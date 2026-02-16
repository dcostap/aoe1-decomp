#pragma once
#include "common.h"
#include "RGE_Random_Map_Module.h"

class RGE_RMM_Elevation_Generator : public RGE_Random_Map_Module {
public:
    RGE_RMM_Elevation_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Elevation_Info* param_3);

    // Virtuals (best-effort)
    virtual uchar generate(); // vt[0] (0x0)

    RGE_Elevation_Info info;
};
static_assert(sizeof(RGE_RMM_Elevation_Generator) == 0xFB0, "Size mismatch");
