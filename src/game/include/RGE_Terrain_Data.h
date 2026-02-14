#pragma once
#include "common.h"
#include "RGE_Terrain_Data_Entry.h"

struct RGE_Terrain_Data {
    long terrain_num;
    RGE_Terrain_Data_Entry* terrain;
};
static_assert(sizeof(RGE_Terrain_Data) == 0x8, "Size mismatch");
