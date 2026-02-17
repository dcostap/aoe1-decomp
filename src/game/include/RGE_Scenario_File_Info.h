#pragma once
#include "common.h"

struct RGE_Scenario_File_Entry;
class RGE_Scenario_Header;

struct RGE_Scenario_File_Info {
    RGE_Scenario_File_Info(char* param_1);
    ~RGE_Scenario_File_Info();

    void save();
    void reload_scenarios();
    char* get_scenario_name(long param_1);
    RGE_Scenario_Header* get_scenario_info(long param_1);

    char filename[260];
    long scenario_num;
    RGE_Scenario_File_Entry* scenarios;
};
static_assert(sizeof(RGE_Scenario_File_Info) == 0x10C, "Size mismatch");
