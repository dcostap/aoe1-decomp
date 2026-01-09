#pragma once
#include "common.h"

class RGE_RMM_Shallows_Generator : public RGE_Random_Map_Module {
public:
    RGE_Shallows_Info info;                  // 0x30

    virtual uchar generate();                               // vt0[0]+0x0=0x487050
    RGE_RMM_Shallows_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Shallows_Info* param_3);
    void make_tribe_connections(long param_1, long param_2);
};

static_assert(sizeof(RGE_RMM_Shallows_Generator) == 0x34C, "RGE_RMM_Shallows_Generator Size Mismatch");

