// MATCHED. Exact 88-byte match confirmed via local check_function.py.
// Key insight: current_campaign must appear in SOURCE BEFORE campaign_num
// to match the post-pop-edi store order (current_campaign=-1 first, campaign_num second).
// strcpy(->name) inlines to rep movsd/movsb with /O2. Param register assignments
// match naturally when campaign_num is first in C++ read order (ecx=campaign_num, eax=campaigns).

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
    this->current_campaign = -1;
    this->campaign_num = campaign_num;
    this->campaign_info_num = 0;
    this->campaign_info = 0;
    this->campaigns = campaigns;
}
