#pragma once
#include "common.h"

struct RGE_Scenario_Offset {
    long size;
    long offset;
    char name[255];
    char file_name[255];
};
static_assert(sizeof(RGE_Scenario_Offset) == 0x208, "Size mismatch");
