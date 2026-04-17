class RGE_Campaign_Info {
public:
    void notify_of_scenario_complete(void);
};

class RGE_Person_Info {
public:
    char gap_00[0x100];
    long current_campaign;
    long gap_104;
    RGE_Campaign_Info** campaign_info;

    void notify_of_scenario_complete(void);
};

void RGE_Person_Info::notify_of_scenario_complete(void) {
    long current_campaign;

    current_campaign = this->current_campaign;
    if (current_campaign > -1) {
        this->campaign_info[current_campaign]->notify_of_scenario_complete();
    }
}
