#pragma once
#include "common.h"
#include "RGE_Terrain_Info_Line.h"
#include "RGE_Terrain_Hot_Spots.h"

struct RGE_Terrain_Info {
    RGE_Terrain_Info_Line terrain[99];
    long terrain_num;
    RGE_Terrain_Hot_Spots hot_spots[99];
    long hot_spot_num;
};
static_assert(sizeof(RGE_Terrain_Info) == 0x1298, "Size mismatch");
