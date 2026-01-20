#pragma once
#include "common.h"

struct RGE_Scenario_File_Info {
    char filename[260];
    long scenario_num;
    RGE_Scenario_File_Entry* scenarios;
};
static_assert(sizeof(RGE_Scenario_File_Info) == 0x10C, "Size mismatch");
