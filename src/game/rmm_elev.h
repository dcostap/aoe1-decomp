#pragma once
#include "../common.h"

class RGE_RMM_Elevation_Generator : public RGE_Random_Map_Module {
public:
    RGE_Elevation_Info info;                 // 0x30

    RGE_RMM_Elevation_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Elevation_Info* param_3);
    virtual uchar generate();
    virtual uchar check_start_elevation(long param_1, long param_2, uchar param_3, uchar param_4, uchar param_5);
    virtual uchar check_elevation(uchar param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6);
    virtual void generate_modifiers();
    virtual float fig_chance(long param_1, long param_2, long param_3);
    virtual long count_map_tiles(uchar param_1);
    virtual void link_stack_randomly(Map_Stack* param_1);
    virtual void remove_area_from_lists(long param_1, long param_2, long param_3);
    virtual uchar base_elevation_generate(RGE_Elevation_Info_Line param_1);
};

static_assert(sizeof(RGE_RMM_Elevation_Generator) == 0xFB0, "RGE_RMM_Elevation_Generator Size Mismatch");
static_assert(offsetof(RGE_RMM_Elevation_Generator, info) == 0x30, "RGE_RMM_Elevation_Generator Offset Mismatch");

