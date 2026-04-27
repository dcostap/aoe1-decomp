// VA: 0044C780 RGE_Campaign_Info::RGE_Campaign_Info(RGE_Campaign*)
// gameinfo.cpp lines 84-126, 227 bytes

#include <string.h>

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
        name[0] = 0;
        current_scenario = 0;
        last_scenario = 0;
        scenario_num = 0;
        scenario_info = 0;
    }
}
