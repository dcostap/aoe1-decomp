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
    void find_campaigns();
    uchar add_new_person(char* param_1);
    uchar set_current_person(long param_1);
    uchar set_current_campaign(long param_1);
    uchar set_current_scenario(long param_1);
    long get_people_list(char*** param_1, long* param_2);
    long get_campaign_list(char*** param_1, long* param_2);
    long get_scenario_list(char*** param_1, long* param_2);
    void save(char* param_1);
    void notify_of_scenario_complete();
    void remove_player(long param_1);

    long current_person;
    long people_num;
    RGE_Person_Info** people_info;
    long campaign_num;
    RGE_Campaign** campaigns;
    char save_filename[260];
};
static_assert(sizeof(RGE_Game_Info) == 0x118, "Size mismatch");
