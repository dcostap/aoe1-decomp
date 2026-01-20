#pragma once
#include "common.h"

struct RGE_Terrain_Data_Entry {
    long terrain_percent;
    long terrain_type;
    long clumps;
    long spacing;
    long base_terrain_type;
    long clumpiness_factor;
};
static_assert(sizeof(RGE_Terrain_Data_Entry) == 0x18, "Size mismatch");
