#pragma once
#include "common.h"

struct Shape_Info {
    ulong Shape_Data_Offsets;
    ulong Shape_Outline_Offset;
    long Reserved1;
    long Reserved2;
    long Width;
    long Height;
    long Hotspot_X;
    long Hotspot_Y;
};
static_assert(sizeof(Shape_Info) == 0x20, "Size mismatch");
