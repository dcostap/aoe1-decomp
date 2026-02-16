#pragma once
#include "common.h"
#include "RGE_Cliffs_Hot_Spots.h"

struct RGE_Cliffs_Info {
    long number_of_cliffs;
    long number_of_cliffs_variance;
    long average_cliff_size;
    long cliff_size_variance;
    long cliff_terrain_spacing;
    long cliff_to_cliff_spacing;
    RGE_Cliffs_Hot_Spots hot_spots[99];
    long hot_spot_num;
};
static_assert(sizeof(RGE_Cliffs_Info) == 0x4C0, "Size mismatch");
