#pragma once
#include "common.h"

struct RGE_Terrain_Info_Line {
    long terrain_size;
    long terrain_generated;
    long terrain_type;
    long clumps;
    long spacing;
    long base_terrain_type;
    long clumpiness_factor;
    long avoid_hot_spots;
};
static_assert(sizeof(RGE_Terrain_Info_Line) == 0x20, "Size mismatch");
