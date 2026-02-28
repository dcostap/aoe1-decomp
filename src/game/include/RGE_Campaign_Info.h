#pragma once
#include "common.h"
#include "RGE_Scenario_Info.h"

struct RGE_Campaign;

struct RGE_Campaign_Info {
    RGE_Campaign_Info(int param_1, RGE_Campaign** param_2, long param_3);
    RGE_Campaign_Info(RGE_Campaign* param_1);
    ~RGE_Campaign_Info();

    long get_current_scenario();
    int open_scenario();
    long get_scenario_list(char*** param_1, long* param_2);
    void save(int param_1);
    void rehook_campaigns(RGE_Campaign** param_1, long param_2);
    uchar set_current_scenario(long param_1);
    uchar verify_campaign_name(char* param_1);
    void notify_of_scenario_complete();

    char campaign_name[255];
    long current_scenario;
    long scenario_num;
    RGE_Scenario_Info* scenario_info;
    long last_scenario;
    RGE_Campaign* campaign;
};
static_assert(sizeof(RGE_Campaign_Info) == 0x114, "Size mismatch");
