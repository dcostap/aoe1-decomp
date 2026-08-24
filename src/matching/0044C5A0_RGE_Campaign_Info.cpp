// VA: 0044C5A0 RGE_Campaign_Info ctor (474B)
// gameinfo.cpp
//
// Attempt log:
// - baseline: named RGE_Campaign_Info layout and constructor ownership; the
//   current source still used a hand-written name loop, cached campaign, and
//   current_scenario for the resize tests.
// - behavior: restored the same-TU source shape: strcmp on the campaign name,
//   direct *camps ownership, scenario_num as the serialized count, and
//   memcpy for the byte-record resize.  This removes an extra
//   scenario_number call and preserves the original call topology.

#include <string.h>

 #ifndef GAMEINFO_SHARED_CONTEXT
int __cdecl rge_read(int fd, void* buf, int size);
void* __cdecl calloc(int count, int size);
void __cdecl free(void*);

class RGE_Campaign {
public:
    char* get_name(void);
    int scenario_number(void);
};

struct RGE_Scenario_Info {
    char scenario_status;
};

class RGE_Campaign_Info {
public:
    char name[256];             // +0x000
    int current_scenario;       // +0x100
    int scenario_num;           // +0x104
    RGE_Scenario_Info* scenario_info; // +0x108
    int last_scenario;          // +0x10C
    RGE_Campaign* campaign;     // +0x110

    RGE_Campaign_Info(int fd, RGE_Campaign** camps, int cnum);
};
#endif

RGE_Campaign_Info::RGE_Campaign_Info(int fd, RGE_Campaign** camps, int cnum) {
    rge_read(fd, this, 0xFF);
    rge_read(fd, &current_scenario, 4);
    rge_read(fd, &scenario_num, 4);
    rge_read(fd, &last_scenario, 4);

    if (scenario_num > 0) {
        scenario_info = (RGE_Scenario_Info*)calloc(scenario_num, 1);
        rge_read(fd, scenario_info, scenario_num);
    } else {
        scenario_info = 0;
    }

    campaign = 0;

    if (cnum > 0) {
        RGE_Campaign** pcamp = camps;
        while (cnum > 0) {
            if (strcmp((*pcamp)->get_name(), name) == 0) {
                campaign = *pcamp;
                if (scenario_num != campaign->scenario_number()) {
                    if (scenario_num > campaign->scenario_number()) {
                        RGE_Scenario_Info* new_info =
                            (RGE_Scenario_Info*)calloc(campaign->scenario_number(), 1);
                        if (scenario_num < campaign->scenario_number()) {
                            memcpy(new_info, scenario_info, scenario_num);
                        } else {
                            memcpy(new_info, scenario_info,
                                   campaign->scenario_number());
                        }
                        free(scenario_info);
                        scenario_info = new_info;
                    }

                    scenario_num = campaign->scenario_number();
                    if (last_scenario >= scenario_num) {
                        last_scenario = scenario_num - 1;
                    }
                    if (current_scenario > last_scenario) {
                        current_scenario = last_scenario;
                    }
                }
            }
            ++pcamp;
            --cnum;
        }
    }
}
