#pragma once
#include "common.h"

struct RGE_Object_Data_Entry {
    long obj_id;
    long terrain;
    uchar group_flag;
    uchar scale_flag;
    long object_number_per_group;
    long object_number_varience;
    long number_of_groups;
    long group_area;
    long player_id;
    long land_id;
    long land_inner_radius;
    long land_outer_radius;
};
static_assert(sizeof(RGE_Object_Data_Entry) == 0x2C, "Size mismatch");
