#pragma once
#include "common.h"
#include "RGE_Campaign_Info.h"
#include "RGE_Campaign.h"

struct RGE_Person_Info {
    RGE_Person_Info(char* param_1, RGE_Campaign** param_2, long param_3);
    ~RGE_Person_Info();

    char* get_name();
    long get_current_campaign();
    long get_current_scenario();
    long get_scenario_list(char*** param_1, long* param_2);
    int open_scenario();
    void save(int param_1);
    uchar set_current_campaign(long param_1);
    uchar set_current_scenario(long param_1);
    void notify_of_scenario_complete();

    char name[255];
    long current_campaign;
    long campaign_info_num;
    RGE_Campaign_Info** campaign_info;
    long campaign_num;
    RGE_Campaign** campaigns;
};
static_assert(sizeof(RGE_Person_Info) == 0x114, "Size mismatch");
