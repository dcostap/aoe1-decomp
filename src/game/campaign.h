#pragma once
#include "../common.h"

class RGE_Campaign {
public:
    RGE_Scenario_Offset* scenario_offsets;   // 0x108
    char filename[255];                      // 0x10C

    RGE_Campaign(char* param_1);
    RGE_Campaign(char* param_1, char* param_2, long param_3, char** param_4, char** param_5);
    virtual ~RGE_Campaign();
    virtual void create_file();
    virtual int open_scenario(long param_1);
    virtual char* get_name();
    virtual long scenario_number();
    virtual long scenario_info(char*** param_1);
    virtual char* get_scenario_name(long param_1);
};

static_assert(sizeof(RGE_Campaign) == 0x20C, "RGE_Campaign Size Mismatch");
static_assert(offsetof(RGE_Campaign, filename) == 0x10C, "RGE_Campaign Offset Mismatch");

