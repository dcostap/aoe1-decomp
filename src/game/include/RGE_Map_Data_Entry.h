#pragma once
#include "common.h"

struct RGE_Map_Data_Entry {
    long map_id;
    RGE_Land_Data land_info;
    RGE_Terrain_Data terrain_info;
    RGE_Object_Data object_info;
    RGE_Elevation_Data elevation_info;
};
static_assert(sizeof(RGE_Map_Data_Entry) == 0x48, "Size mismatch");
