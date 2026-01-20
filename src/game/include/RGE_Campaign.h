#pragma once
#include "common.h"

struct RGE_Campaign {
    RGE_Campaign_Header campaign_header;
    RGE_Scenario_Offset* scenario_offsets;
    char filename[255];
};
static_assert(sizeof(RGE_Campaign) == 0x20C, "Size mismatch");
