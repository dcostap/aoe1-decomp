// VA: 0044C780 RGE_Campaign_Info::RGE_Campaign_Info(RGE_Campaign*)
// gameinfo.cpp lines 84-126, 227 bytes
//
// Attempt log:
// - baseline: canonical layout from matched donors (name[256] @0x0, current_scenario
//   @0x100, scenario_num @0x104, scenario_info @0x108, last_scenario @0x10C,
//   campaign @0x110); null path must use strcpy(name, "") to reproduce the
//   full inline strlen+rep-copy of the empty literal (mov edi, "" at 0x592A40),
//   not a plain name[0] = 0 store.

#include <string.h>

#ifndef GAMEINFO_SHARED_CONTEXT
void* __cdecl calloc(int count, int size);

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

    RGE_Campaign_Info(RGE_Campaign* camp);
};
#endif

RGE_Campaign_Info::RGE_Campaign_Info(RGE_Campaign* camp) {
    if (camp) {
        campaign = camp;
        strcpy(name, camp->get_name());
        long snum = campaign->scenario_number();
        scenario_num = snum;
        if (snum > 0) {
            current_scenario = 0;
            last_scenario = 0;
            scenario_info = (RGE_Scenario_Info*)calloc(snum, 1);
            scenario_info->scenario_status = 2;
        } else {
            scenario_info = 0;
            current_scenario = -1;
            last_scenario = -1;
        }
    } else {
        campaign = 0;
        strcpy(name, "");
        current_scenario = 0;
        last_scenario = 0;
        scenario_num = 0;
        scenario_info = 0;
    }
}
