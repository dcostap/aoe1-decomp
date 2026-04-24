// previous agent: used strcpy (library call) instead of inline rep; used initializer list
// attempt 1: body-only inits, name copy matches (inline rep), tail store order differs at offset 42
// attempt 2: swapped campaign_num/campaigns order → offset 66 (only last 2 stores swapped after pop edi)
// attempt 3: tried campaign_num before campaign_info in source → back to offset 42
// attempt 4: tried campaign_num first in source → still offset 66, same last-2-stores-swap
// Left in scratch: VC5 consistently stores campaign_num (from ecx) before current_campaign=-1 after pop edi,
// while original does the reverse. Benign store reordering, behavior identical. 88 bytes.

#include <string.h>

class RGE_Campaign_Info;
class RGE_Campaign;

class RGE_Person_Info {
public:
    char name[256];
    long current_campaign;       // +0x100
    long campaign_info_num;      // +0x104
    RGE_Campaign_Info** campaign_info;  // +0x108
    long campaign_num;           // +0x10C
    RGE_Campaign** campaigns;    // +0x110

    RGE_Person_Info(char* name, RGE_Campaign** campaigns, long campaign_num);
};

RGE_Person_Info::RGE_Person_Info(char* name, RGE_Campaign** campaigns, long campaign_num) {
    strcpy(this->name, name);
    this->campaign_num = campaign_num;
    this->campaign_info_num = 0;
    this->campaign_info = 0;
    this->campaigns = campaigns;
    this->current_campaign = -1;
}
