// VA: 0044C930 RGE_Campaign_Info::rehook_campaigns(RGE_Campaign**, long)
// gameinfo.cpp lines 156-187, 338 bytes
//
// Attempt log:
// - baseline: named campaign/scenario ownership and a persistent list/count
//   scan, but cached scenario_number calls and reversed final comparisons.
// - behavior: mirror the constructor's period source shape with repeated
//   campaign->scenario_number() expressions and typed memcpy resize copies.

#include <string.h>

#ifndef GAMEINFO_SHARED_CONTEXT
struct RGE_Campaign {
    char* get_name();
    long scenario_number();
};

struct RGE_Scenario_Info {
    char scenario_status;
};

struct RGE_Campaign_Info {
    char name[256];
    int current_scenario;
    int scenario_num;
    RGE_Scenario_Info* scenario_info;
    int last_scenario;
    RGE_Campaign* campaign;

    void rehook_campaigns(RGE_Campaign** list, long count);
};

void __cdecl free(void*);
void* __cdecl calloc(int count, int size);
#endif

void RGE_Campaign_Info::rehook_campaigns(RGE_Campaign** list, long count) {
    campaign = 0;
    if (count <= 0) return;
    RGE_Campaign** pp = list;
    long remaining = count;
    do {
        if (strcmp((*pp)->get_name(), name) == 0) {
            campaign = *pp;
            if (scenario_num != campaign->scenario_number()) {
                RGE_Scenario_Info* newsi =
                    (RGE_Scenario_Info*)calloc(campaign->scenario_number(), 1);
                if (scenario_num < campaign->scenario_number()) {
                    memcpy(newsi, scenario_info, scenario_num);
                } else {
                    memcpy(newsi, scenario_info,
                           campaign->scenario_number());
                }
                free(scenario_info);
                scenario_info = newsi;
            }
            scenario_num = campaign->scenario_number();
            if (last_scenario >= scenario_num) {
                last_scenario = scenario_num - 1;
            }
            if (current_scenario > last_scenario) {
                current_scenario = last_scenario;
            }
        }
        pp++;
        remaining--;
    } while (remaining);
}
