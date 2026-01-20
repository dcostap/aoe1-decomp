#pragma once
#include "common.h"

struct RGE_Scenario_Info {
    uchar scenario_status;
};
static_assert(sizeof(RGE_Scenario_Info) == 0x1, "Size mismatch");
