#ifndef GAMEINFO_SHARED_CONTEXT
class RGE_Campaign;
class RGE_Campaign_Info {
public:
    void rehook_campaigns(RGE_Campaign** campaigns, long campaign_num);
};

class RGE_Person_Info {
public:
    char name[0x100];
    long current_campaign;
    long campaign_info_num;
    RGE_Campaign_Info** campaign_info;
    long campaign_num;
    RGE_Campaign** campaigns;

    void rehook_campaigns(RGE_Campaign** campaigns, long campaign_num);
};
#endif

void RGE_Person_Info::rehook_campaigns(RGE_Campaign** campaigns, long campaign_num) {
    int i;

    i = 0;
    this->campaign_num = campaign_num;
    this->campaigns = campaigns;
    if (this->campaign_info_num > 0) {
        do {
            this->campaign_info[i]->rehook_campaigns(this->campaigns, this->campaign_num);
            i = i + 1;
        } while (i < this->campaign_info_num);
    }
}
