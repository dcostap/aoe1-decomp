#pragma once
#include "common.h"
#include "RGE_Campaign_Header.h"
#include "RGE_Scenario_Offset.h"

struct RGE_Campaign {
    RGE_Campaign(char* param_1);
    RGE_Campaign(char* param_1, char* param_2, long param_3, char** param_4, char** param_5);
    ~RGE_Campaign();

    void create_file();
    long scenario_info(char*** param_1);

    int open_scenario(long param_1);
    char* get_name();
    char* get_scenario_name(long param_1);
    long scenario_number();

    RGE_Campaign_Header campaign_header;
    RGE_Scenario_Offset* scenario_offsets;
    char filename[255];
};
static_assert(sizeof(RGE_Campaign) == 0x20C, "Size mismatch");
