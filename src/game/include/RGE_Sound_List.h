#pragma once
#include "common.h"

struct RGE_Sound_List {
    RGE_Sound* sound[3];
    short frame[3];
};
static_assert(sizeof(RGE_Sound_List) == 0x14, "Size mismatch");
