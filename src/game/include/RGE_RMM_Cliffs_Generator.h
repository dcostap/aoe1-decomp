#pragma once
#include "common.h"
#include "RGE_Cliffs_Info.h"
#include "RGE_Random_Map_Module.h"

class RGE_RMM_Cliffs_Generator : public RGE_Random_Map_Module {
public:
    RGE_RMM_Cliffs_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Cliffs_Info param_3);

    // Virtuals (best-effort)
    virtual uchar generate(); // vt[0] (0x0)

    void setup_cliff_maps();
    void generate_cliff();
    uchar check_for_valid_cliff_site(long param_1, long* param_2, long* param_3, long param_4);
    void invalidate_cliff_area(long param_1, long param_2, long param_3);

    RGE_Cliffs_Info info;
    Map_Stack valid_cliff_sites;
};
static_assert(sizeof(RGE_RMM_Cliffs_Generator) == 0x508, "Size mismatch");
