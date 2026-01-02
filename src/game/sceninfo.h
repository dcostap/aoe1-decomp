#pragma once
#include "../common.h"

class RGE_Scenario_File_Info {
public:
    long scenario_num;                       // 0x104
    RGE_Scenario_File_Entry* scenarios;      // 0x108

    RGE_Scenario_File_Info(char* param_1);
    virtual ~RGE_Scenario_File_Info();
    virtual void save();
    virtual void reload_scenarios();
    virtual char* get_scenario_name(long param_1);
    virtual RGE_Scenario_Header* get_scenario_info(long param_1);
};

static_assert(sizeof(RGE_Scenario_File_Info) == 0x10C, "RGE_Scenario_File_Info Size Mismatch");
static_assert(offsetof(RGE_Scenario_File_Info, scenarios) == 0x108, "RGE_Scenario_File_Info Offset Mismatch");

