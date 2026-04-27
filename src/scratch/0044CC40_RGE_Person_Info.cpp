// VA: 0044CC40 RGE_Person_Info::RGE_Person_Info(int, RGE_Campaign**, long)
// gameinfo.cpp lines 278-296, 244 bytes

int __cdecl rge_read(int fd, void* buf, int size);
void* __cdecl calloc(int count, int size);

struct RGE_Campaign;

struct RGE_Campaign_Info {
    char name[256];
    int current_scenario;
    int scenario_num;
    char* scenario_info;
    int last_scenario;
    RGE_Campaign* campaign;

    RGE_Campaign_Info(int fd, RGE_Campaign** camps, int cnum);
};

struct RGE_Person_Info {
    char name[256];
    int current_campaign;
    int campaign_info_num;
    RGE_Campaign_Info** campaign_info;
    int campaign_num;
    RGE_Campaign** campaigns;

    RGE_Person_Info(int fd, RGE_Campaign** camps, long cnum);
};

RGE_Person_Info::RGE_Person_Info(int fd, RGE_Campaign** camps, long cnum) {
    campaign_num = cnum;
    campaigns = camps;
    rge_read(fd, this, 0xFF);
    rge_read(fd, &current_campaign, 4);
    rge_read(fd, &campaign_info_num, 4);
    if (campaign_info_num <= 0) {
        campaign_info = 0;
    } else {
        campaign_info = (RGE_Campaign_Info**)calloc(campaign_info_num, 4);
        for (int i = 0; i < campaign_info_num; i++) {
            RGE_Campaign_Info* ci = new RGE_Campaign_Info(fd, campaigns, campaign_num);
            campaign_info[i] = ci;
        }
    }
}
