class RGE_Campaign_Info {
public:
    int open_scenario(void);
};

class RGE_Person_Info {
public:
    char gap_00[0x100];
    long current_campaign;
    long gap_104;
    RGE_Campaign_Info** campaign_info;

    int open_scenario(void);
};

int RGE_Person_Info::open_scenario(void) {
    long current_campaign;

    current_campaign = this->current_campaign;
    if (current_campaign > -1) {
        return this->campaign_info[current_campaign]->open_scenario();
    }
    return -1;
}
