#pragma once
#include "common.h"
#include "RGE_Random_Map_Module.h"
#include "RGE_Shallows_Info.h"

class RGE_RMM_Shallows_Generator : public RGE_Random_Map_Module {
public:
    RGE_RMM_Shallows_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Shallows_Info* param_3);

    // Virtuals (best-effort)
    virtual uchar generate(); // vt[0] (0x0)

    void make_tribe_connections(long param_1, long param_2);

    RGE_Shallows_Info info;
};
static_assert(sizeof(RGE_RMM_Shallows_Generator) == 0x34C, "Size mismatch");
