#pragma once
#include "common.h"

struct RGE_Object_Info {
    RGE_Object_Info_Line objects[99];
    long object_num;
    RGE_Land_Point_Info_Line lands[99];
    long land_num;
};
static_assert(sizeof(RGE_Object_Info) == 0x18C8, "Size mismatch");
