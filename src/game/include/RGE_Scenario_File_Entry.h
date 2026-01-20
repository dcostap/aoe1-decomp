#pragma once
#include "common.h"

struct RGE_Scenario_File_Entry {
    long time;
    RGE_Scenario_Header* scenario_header;
    char name[260];
};
static_assert(sizeof(RGE_Scenario_File_Entry) == 0x10C, "Size mismatch");
