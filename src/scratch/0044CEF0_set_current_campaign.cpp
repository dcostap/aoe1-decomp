// VA: 0044CEF0 RGE_Person_Info::set_current_campaign(long)
// 337 bytes, EH-framed (/GX)

#include <string.h>

void* __cdecl calloc(int count, int size);
void __cdecl free(void*);

struct RGE_Campaign {
    char* get_name(void);
    long scenario_number(void);
};

struct RGE_Campaign_Info {
    char name[256];          // +0x000
    int current_scenario;    // +0x100
    int scenario_num;        // +0x104
    char* scenario_info;     // +0x108
    int last_scenario;       // +0x10C
    RGE_Campaign* campaign;  // +0x110

    RGE_Campaign_Info(RGE_Campaign* camp);
    unsigned char verify_campaign_name(char* name);
};

struct RGE_Person_Info {
    char name[256];                   // +0x000
    int current_campaign;             // +0x100
    int campaign_info_num;            // +0x104
    RGE_Campaign_Info** campaign_info; // +0x108
    int campaign_num;                 // +0x10C
    RGE_Campaign** campaigns;         // +0x110

    unsigned char set_current_campaign(long index);
};

unsigned char RGE_Person_Info::set_current_campaign(long index) {
    // Bounds check
    if (index < 0 || index >= campaign_num || campaigns[index] == 0) {
        return 0;
    }
    
    // Search for matching campaign info
    for (int i = 0; i < campaign_info_num; i++) {
        if (campaign_info[i]->verify_campaign_name(campaigns[index]->get_name())) {
            current_campaign = i;
            return 1;
        }
    }
    
    // No match found - allocate new campaign info entry
    RGE_Campaign_Info** newlist = (RGE_Campaign_Info**)calloc(campaign_info_num + 1, 4);
    if (campaign_info != 0) {
        memcpy(newlist, campaign_info, campaign_info_num * 4);
    }
    free(campaign_info);
    campaign_info = newlist;
    
    // Use C++ new expression for EH frame generation
    campaign_info[campaign_info_num] = new RGE_Campaign_Info(campaigns[index]);
    current_campaign = campaign_info_num;
    campaign_info_num++;
    return 1;
}
