// VA: 0044C930 RGE_Campaign_Info::rehook_campaigns(RGE_Campaign**, long)
// gameinfo.cpp lines 156-187, 338 bytes

#include <string.h>

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

void RGE_Campaign_Info::rehook_campaigns(RGE_Campaign** list, long count) {
    campaign = 0;
    if (count <= 0) return;
    RGE_Campaign** pp = list;
    long remaining = count;
    do {
        if (strcmp((*pp)->get_name(), name) == 0) {
            campaign = *pp;
            long snum = campaign->scenario_number();
            if (scenario_num != snum) {
                snum = campaign->scenario_number();
                RGE_Scenario_Info* newsi = (RGE_Scenario_Info*)calloc(snum, 1);
                if (scenario_num < snum) {
                    memcpy(newsi, scenario_info, scenario_num);
                } else {
                    memcpy(newsi, scenario_info, snum);
                }
                free(scenario_info);
                scenario_info = newsi;
            }
            snum = campaign->scenario_number();
            scenario_num = snum;
            if (snum <= last_scenario) {
                last_scenario = snum - 1;
            }
            if (last_scenario < current_scenario) {
                current_scenario = last_scenario;
            }
        }
        pp++;
        remaining--;
    } while (remaining);
}
