#pragma once
#include "common.h"

struct DisplaySelectedObjRec {
    int active;
    int id;
    ulong start_time;
    ulong duration;
    int select_type;
};
static_assert(sizeof(DisplaySelectedObjRec) == 0x14, "Size mismatch");
