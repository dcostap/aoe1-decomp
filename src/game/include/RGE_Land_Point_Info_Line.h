#pragma once
#include "common.h"

struct RGE_Land_Point_Info_Line {
    long x;
    long y;
    long id;
    long player_id;
};
static_assert(sizeof(RGE_Land_Point_Info_Line) == 0x10, "Size mismatch");
