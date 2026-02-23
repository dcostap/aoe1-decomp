#pragma once
#include "common.h"
#include "RGE_Random_Map_Module.h"
#include "RGE_Terrain_Info.h"

class RGE_Zone_Map;

class RGE_RMM_Terrain_Generator : public RGE_Random_Map_Module {
public:
    RGE_RMM_Terrain_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Terrain_Info* param_3);

    // Virtuals (best-effort)
    virtual uchar generate(); // vt[0] (0x0)

protected:
    uchar water(uchar param_1);
    void check_borders();
    uchar check_terrain(uchar param_1, long param_2, long param_3, long param_4, uchar param_5);
    void generate_modifiers();
    float fig_chance(long param_1, long param_2, long param_3, long param_4);
    long count_map_tiles(uchar param_1);
    void link_stack_randomly(Map_Stack* param_1, uchar param_2);
    void remove_area_from_lists(long param_1, long param_2, long param_3);
    uchar base_terrain_generate(RGE_Terrain_Info_Line param_1);

    RGE_Terrain_Info info;
    RGE_Zone_Map* map_zone;
};
static_assert(sizeof(RGE_RMM_Terrain_Generator) == 0x12CC, "Size mismatch");
