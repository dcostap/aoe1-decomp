#pragma once
#include "common.h"
#include "RGE_Campaign_Info.h"
#include "RGE_Campaign.h"

struct RGE_Person_Info {
    long get_current_campaign();
    long get_current_scenario();
    int open_scenario();

    char name[255];
    long current_campaign;
    long campaign_info_num;
    RGE_Campaign_Info** campaign_info;
    long campaign_num;
    RGE_Campaign** campaigns;
};
static_assert(sizeof(RGE_Person_Info) == 0x114, "Size mismatch");
