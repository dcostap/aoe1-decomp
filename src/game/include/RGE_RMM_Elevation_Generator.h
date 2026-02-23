#pragma once
#include "common.h"
#include "RGE_Random_Map_Module.h"
#include "RGE_Elevation_Info.h"

class RGE_RMM_Elevation_Generator : public RGE_Random_Map_Module {
public:
    RGE_RMM_Elevation_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Elevation_Info* param_3);

    // Virtuals (best-effort)
    virtual uchar generate(); // vt[0] (0x0)

protected:
    uchar check_start_elevation(long param_1, long param_2, uchar param_3, uchar param_4, uchar param_5);
    uchar check_elevation(uchar param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6);
    void generate_modifiers();
    float fig_chance(long param_1, long param_2, long param_3);
    long count_map_tiles(uchar param_1);
    void link_stack_randomly(Map_Stack* param_1);
    void remove_area_from_lists(long param_1, long param_2, long param_3);
    uchar base_elevation_generate(RGE_Elevation_Info_Line param_1);

    RGE_Elevation_Info info;
};
static_assert(sizeof(RGE_RMM_Elevation_Generator) == 0xFB0, "Size mismatch");
