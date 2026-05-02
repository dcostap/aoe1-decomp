// VA: 0044CC40 RGE_Person_Info::RGE_Person_Info(int, RGE_Campaign**, long)
// gameinfo.cpp - EH-framed constructor (/GX)

#include <stdlib.h>

int __cdecl rge_read(int fd, void* buf, int size);
void* __cdecl calloc(int count, int size);

struct RGE_Campaign {
    char* get_name(void);
    long scenario_number(void);
};

struct RGE_Campaign_Info {
    char name[256];             // +0x000
    int current_scenario;       // +0x100
    int scenario_num;           // +0x104
    char* scenario_info;        // +0x108
    int last_scenario;          // +0x10C
    RGE_Campaign* campaign;     // +0x110

    RGE_Campaign_Info(int fd, RGE_Campaign** camps, int cnum);
};

struct RGE_Person_Info {
    char name[256];                   // +0x000
    int current_campaign;             // +0x100
    int scenario_num;                 // +0x104
    RGE_Campaign_Info** campaign_info; // +0x108
    int campaign_num;                 // +0x10C
    RGE_Campaign** campaigns;         // +0x110

    RGE_Person_Info(int fd, RGE_Campaign** camps, int cnum);
};

RGE_Person_Info::RGE_Person_Info(int fd, RGE_Campaign** camps, int cnum) {
    // Store params
    campaign_num = cnum;
    campaigns = camps;
    
    // Read name (255 bytes)
    rge_read(fd, this, 0xFF);
    
    // Read current_campaign
    rge_read(fd, &current_campaign, 4);
    
    // Read scenario_num
    rge_read(fd, &scenario_num, 4);
    
    // Allocate campaign_info array
    if (scenario_num > 0) {
        campaign_info = (RGE_Campaign_Info**)calloc(scenario_num, 4);
    } else {
        campaign_info = 0;
    }
    
    // Loop to create campaign info entries
    for (int i = 0; i < scenario_num; i++) {
        campaign_info[i] = new RGE_Campaign_Info(fd, camps, cnum);
    }
}
