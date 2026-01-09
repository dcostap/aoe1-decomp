#pragma once
#include "common.h"

class RGE_RMM_Terrain_Generator : public RGE_Random_Map_Module {
public:
    RGE_Terrain_Info info;                   // 0x30
    RGE_Zone_Map* map_zone;                  // 0x12C8

    virtual uchar generate();                               // vt0[0]+0x0=0x488920
    RGE_RMM_Terrain_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Terrain_Info* param_3);
    uchar water(uchar param_1);
    void check_borders();
    uchar check_terrain(uchar param_1, long param_2, long param_3, long param_4, uchar param_5);
    void generate_modifiers();
    float fig_chance(long param_1, long param_2, long param_3, long param_4);
    long count_map_tiles(uchar param_1);
    void link_stack_randomly(Map_Stack* param_1, uchar param_2);
    void remove_area_from_lists(long param_1, long param_2, long param_3);
    uchar base_terrain_generate(RGE_Terrain_Info_Line param_1);
};

static_assert(sizeof(RGE_RMM_Terrain_Generator) == 0x12CC, "RGE_RMM_Terrain_Generator Size Mismatch");

