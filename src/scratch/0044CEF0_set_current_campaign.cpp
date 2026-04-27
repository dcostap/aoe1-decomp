// VA: 0044CEF0 RGE_Person_Info::set_current_campaign(long)
// 337 bytes

#include <string.h>

void* __cdecl calloc(int count, int size);
void __cdecl free(void*);

struct RGE_Campaign {
    char* get_name();
    long scenario_number();
};

struct RGE_Campaign_Info {
    char name[256];
    int current_scenario;
    int scenario_num;
    char* scenario_info;
    int last_scenario;
    RGE_Campaign* campaign;

    RGE_Campaign_Info(RGE_Campaign* camp);
    unsigned char verify_campaign_name(char* name);
};

struct RGE_Person_Info {
    char name[256];
    int current_campaign;
    int campaign_info_num;
    RGE_Campaign_Info** campaign_info;
    int campaign_num;
    RGE_Campaign** campaigns;

    unsigned char set_current_campaign(long index);
};

unsigned char RGE_Person_Info::set_current_campaign(long index) {
    if (index < 0 || index >= campaign_num || !campaigns[index]) {
        return 0;
    }
    for (int i = 0; i < campaign_info_num; i++) {
        if (campaign_info[i]->verify_campaign_name(campaigns[index]->get_name())) {
            current_campaign = i;
            return 1;
        }
    }
    RGE_Campaign_Info** newlist = (RGE_Campaign_Info**)calloc(campaign_info_num + 1, 4);
    if (campaign_info) {
        memcpy(newlist, campaign_info, campaign_info_num * 4);
    }
    free(campaign_info);
    campaign_info = newlist;
    campaign_info[campaign_info_num] = new RGE_Campaign_Info(campaigns[index]);
    current_campaign = campaign_info_num;
    campaign_info_num++;
    return 1;
}
