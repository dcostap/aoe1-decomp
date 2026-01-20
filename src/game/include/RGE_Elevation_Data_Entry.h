#pragma once
#include "common.h"

struct RGE_Elevation_Data_Entry {
    long elevation_percent;
    long elevation;
    long clumps;
    long spacing;
    long base_terrain_type;
    long base_elevation_type;
};
static_assert(sizeof(RGE_Elevation_Data_Entry) == 0x18, "Size mismatch");
