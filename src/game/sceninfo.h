#pragma once
#include "../common.h"

class RGE_Scenario_File_Info {
public:
    char filename[260];                      // 0x0
    long scenario_num;                       // 0x104
    RGE_Scenario_File_Entry* scenarios;      // 0x108

    RGE_Scenario_File_Info(char* param_1);
    ~RGE_Scenario_File_Info();
    void save();
    void reload_scenarios();
    char* get_scenario_name(long param_1);
    RGE_Scenario_Header* get_scenario_info(long param_1);
};

static_assert(sizeof(RGE_Scenario_File_Info) == 0x10C, "RGE_Scenario_File_Info Size Mismatch");
static_assert(offsetof(RGE_Scenario_File_Info, scenarios) == 0x108, "RGE_Scenario_File_Info Offset Mismatch");

