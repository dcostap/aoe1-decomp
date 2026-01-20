#pragma once
#include "common.h"

struct RGE_Object_Data {
    long object_num;
    RGE_Object_Data_Entry* objects;
};
static_assert(sizeof(RGE_Object_Data) == 0x8, "Size mismatch");
