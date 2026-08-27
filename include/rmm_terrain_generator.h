#ifndef AOE1_RMM_TERRAIN_GENERATOR_H
#define AOE1_RMM_TERRAIN_GENERATOR_H

#include "rmm_base.h"
#include "rmm_terrain_info.h"

class RGE_Zone_Map;

class RGE_RMM_Terrain_Generator : public RGE_Random_Map_Module {
protected:
    RGE_Terrain_Info info;
    RGE_Zone_Map* map_zone;

    uchar water(uchar terrain);
    void check_borders();
    uchar check_terrain(uchar target, long x, long y, long spacing,
        uchar base_terrain);
    void generate_modifiers();
    float fig_chance(long count, long x, long y, long clumpiness_factor);
    long count_map_tiles(uchar terrain);
    void link_stack_randomly(Map_Stack* loc_stack, uchar base_terrain_type);
    void remove_area_from_lists(long x, long y, long spacing);
    uchar base_terrain_generate(RGE_Terrain_Info_Line info_line);

public:
    RGE_RMM_Terrain_Generator(RGE_Map* map,
        RGE_Random_Map_Module* parent, RGE_Terrain_Info* info);
    virtual uchar generate();
};

typedef char rmm_terrain_generator_size_check[
    (sizeof(RGE_RMM_Terrain_Generator) == 0x12CC) ? 1 : -1];

#endif
