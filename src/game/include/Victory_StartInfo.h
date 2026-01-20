#pragma once
#include "common.h"

struct Victory_StartInfo {
    int MP_Conquest;
    int MP_Ruins;
    int MP_Artifacts;
    int MP_Discoveries;
    int MP_Exploration;
    int MP_Gold;
};
static_assert(sizeof(Victory_StartInfo) == 0x18, "Size mismatch");
