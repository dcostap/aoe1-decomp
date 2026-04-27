// attempt log:
// first pass: direct current-campaign scan over the campaign lists using the real offsets from the person-info dump
// target shape: validate current_campaign, ensure campaign_num > 0, loop campaigns, compare get_name() against the current campaign info entry, return match index or -1
// paused here: the behavior is right, but VC5 keeps choosing a different saved-register/loop basin than the packet

class RGE_Campaign {
public:
    char* get_name(void);
};

class RGE_Campaign_Info {
public:
    unsigned char verify_campaign_name(char* campaign_name);
};

class RGE_Person_Info {
public:
    char name[0x100];
    long current_campaign;
    long campaign_info_num;
    RGE_Campaign_Info** campaign_info;
    long campaign_num;
    RGE_Campaign** campaigns;

    long get_current_campaign(void);
};

long RGE_Person_Info::get_current_campaign(void) {
    long i;
    long count;

    if (this->current_campaign < 0 || this->current_campaign >= this->campaign_info_num) {
        return -1;
    }

    count = this->campaign_num;
    if (count <= 0) {
        return -1;
    }

    i = 0;
    do {
        if (this->campaign_info[this->current_campaign]->verify_campaign_name(this->campaigns[i]->get_name()) != 0) {
            return i;
        }
        ++i;
    } while (i < count);

    return -1;
}
