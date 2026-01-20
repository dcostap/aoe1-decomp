#pragma once
#include "common.h"

struct RGE_Object_Info_Line {
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
    long object_exclusion_zone;
};
static_assert(sizeof(RGE_Object_Info_Line) == 0x30, "Size mismatch");
