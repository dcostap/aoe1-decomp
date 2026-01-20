#pragma once
#include "common.h"

struct RGE_Obj_Info {
    long id;
};
static_assert(sizeof(RGE_Obj_Info) == 0x4, "Size mismatch");
