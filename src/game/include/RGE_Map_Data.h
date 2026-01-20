#pragma once
#include "common.h"

struct RGE_Map_Data {
    long map_num;
    RGE_Map_Data_Entry* maps;
};
static_assert(sizeof(RGE_Map_Data) == 0x8, "Size mismatch");
