#ifndef GAMEINFO_SHARED_CONTEXT
class RGE_Campaign_Info {
public:
    virtual ~RGE_Campaign_Info();
    char gap_0[0xFC];
    int field_100;
    unsigned char set_current_scenario(long scenario);
};

class RGE_Campaign;

class RGE_Person_Info {
public:
    char gap_00[0x100];
    int current_campaign;
    char gap_104[0x4];
    RGE_Campaign** campaigns;
    RGE_Campaign_Info** campaign_info;

    unsigned char set_current_scenario(long scenario);
};
#endif

unsigned char RGE_Person_Info::set_current_scenario(long scenario) {
    int current_campaign = this->current_campaign;
    if ((current_campaign >= 0) && (this->campaigns[current_campaign] != 0)) {
        return this->campaign_info[current_campaign]->set_current_scenario(scenario);
    }
    return 0;
}
