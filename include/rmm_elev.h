#ifndef AOE1_RMM_ELEV_H
#define AOE1_RMM_ELEV_H


#include "rmm_base.h"

struct RGE_Elevation_Info_Line {
    long elevation_size;
    long elevation;
    long clumps;
    long spacing;
    long base_elevation;
    long base_terrain_type;
};

struct RGE_Elevation_Hot_Spots {
    long x;
    long y;
    long radius;
    long fade;
};

struct RGE_Elevation_Info {
    RGE_Elevation_Info_Line elevation[99];
    long elevation_num;
    RGE_Elevation_Hot_Spots hot_spots[99];
    long hot_spot_num;
};

typedef char rmm_elev_info_line_size_check[
    (sizeof(RGE_Elevation_Info_Line) == 0x18) ? 1 : -1];
typedef char rmm_elev_hot_spots_size_check[
    (sizeof(RGE_Elevation_Hot_Spots) == 0x10) ? 1 : -1];
typedef char rmm_elev_info_size_check[
    (sizeof(RGE_Elevation_Info) == 0xF80) ? 1 : -1];

class RGE_RMM_Elevation_Generator : public RGE_Random_Map_Module {
public:
    RGE_RMM_Elevation_Generator(RGE_Map* in_map,
        RGE_Random_Map_Module* parent_module, RGE_Elevation_Info* in_info);
    virtual uchar generate();

protected:
    uchar check_start_elevation(long x, long y, uchar base_terrain,
        uchar base_elevation, uchar spacing);
    uchar check_elevation(uchar target, long x, long y, long spacing,
        uchar base_terrain, uchar base_elevation);
    void generate_modifiers();
    float fig_chance(long count, long x, long y);
    long count_map_tiles(uchar terrain);
    void link_stack_randomly(Map_Stack* loc_stack);
    void remove_area_from_lists(long x, long y, long spacing);
    uchar base_elevation_generate(RGE_Elevation_Info_Line info_line);

    RGE_Elevation_Info info;
};

typedef char rmm_elev_generator_size_check[
    (sizeof(RGE_RMM_Elevation_Generator) == 0xFB0) ? 1 : -1];

#endif
