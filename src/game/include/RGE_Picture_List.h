#pragma once
#include "common.h"

struct RGE_Picture_List {
    short picture_num;
    RGE_Sprite* sprite;
    short offset_x;
    short offset_y;
    short facet;
};
static_assert(sizeof(RGE_Picture_List) == 0x10, "Size mismatch");
