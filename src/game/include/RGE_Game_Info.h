#pragma once
#include "common.h"

struct RGE_Game_Info {
    long current_person;
    long people_num;
    RGE_Person_Info** people_info;
    long campaign_num;
    RGE_Campaign** campaigns;
    char save_filename[260];
};
static_assert(sizeof(RGE_Game_Info) == 0x118, "Size mismatch");
