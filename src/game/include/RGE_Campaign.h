#pragma once
#include "common.h"
#include "RGE_Campaign_Header.h"
#include "RGE_Scenario_Offset.h"

struct RGE_Campaign {
    int open_scenario(long param_1);
    char* get_name();
    char* get_scenario_name(long param_1);
    long scenario_number();

    RGE_Campaign_Header campaign_header;
    RGE_Scenario_Offset* scenario_offsets;
    char filename[255];
};
static_assert(sizeof(RGE_Campaign) == 0x20C, "Size mismatch");
