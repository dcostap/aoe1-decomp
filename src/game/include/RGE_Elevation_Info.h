#pragma once
#include "common.h"
#include "RGE_Elevation_Info_Line.h"
#include "RGE_Elevation_Hot_Spots.h"

struct RGE_Elevation_Info {
    RGE_Elevation_Info_Line elevation[99];
    long elevation_num;
    RGE_Elevation_Hot_Spots hot_spots[99];
    long hot_spot_num;
};
static_assert(sizeof(RGE_Elevation_Info) == 0xF80, "Size mismatch");
