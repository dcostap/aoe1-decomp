#pragma once
#include "../common.h"

class RGE_RMM_Cliffs_Generator : public RGE_Random_Map_Module {
public:
    RGE_Cliffs_Info info;                    // 0x30
    Map_Stack valid_cliff_sites;             // 0x4F0

    RGE_RMM_Cliffs_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Cliffs_Info param_3);
    virtual uchar generate();
    virtual void setup_cliff_maps();
    virtual void generate_cliff();
    virtual uchar check_for_valid_cliff_site(long param_1, long* param_2, long* param_3, long param_4);
    virtual void invalidate_cliff_area(long param_1, long param_2, long param_3);
};

static_assert(sizeof(RGE_RMM_Cliffs_Generator) == 0x508, "RGE_RMM_Cliffs_Generator Size Mismatch");
static_assert(offsetof(RGE_RMM_Cliffs_Generator, valid_cliff_sites) == 0x4F0, "RGE_RMM_Cliffs_Generator Offset Mismatch");

