#pragma once
#include "common.h"
#include "RGE_Elevation_Data_Entry.h"

struct RGE_Elevation_Data {
    long elevation_num;
    RGE_Elevation_Data_Entry* elevation;
};
static_assert(sizeof(RGE_Elevation_Data) == 0x8, "Size mismatch");
