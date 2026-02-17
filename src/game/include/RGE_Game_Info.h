#pragma once
#include "common.h"
#include "RGE_Person_Info.h"
#include "RGE_Campaign.h"

struct RGE_Game_Info {
    long get_current_scenario();
    long get_current_campaign();
    long get_current_player();
    char* get_current_player_name();
    int open_scenario();

    long current_person;
    long people_num;
    RGE_Person_Info** people_info;
    long campaign_num;
    RGE_Campaign** campaigns;
    char save_filename[260];
};
static_assert(sizeof(RGE_Game_Info) == 0x118, "Size mismatch");
