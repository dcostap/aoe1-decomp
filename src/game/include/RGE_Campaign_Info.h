#pragma once
#include "common.h"

struct RGE_Campaign_Info {
    char campaign_name[255];
    long current_scenario;
    long scenario_num;
    RGE_Scenario_Info* scenario_info;
    long last_scenario;
    RGE_Campaign* campaign;
};
static_assert(sizeof(RGE_Campaign_Info) == 0x114, "Size mismatch");
