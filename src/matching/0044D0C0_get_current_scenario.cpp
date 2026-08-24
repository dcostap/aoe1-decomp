#ifndef GAMEINFO_SHARED_CONTEXT
class RGE_Campaign_Info_gcs {
public:
    int get_current_scenario(void);
};

class RGE_Person_Info_gcs {
public:
    int get_current_scenario(void);
    char gap_00[0x100];
    int current_campaign;
    char gap_104[0x04];
    RGE_Campaign_Info_gcs** campaign_info;
    char gap_10C[0x04];
    void** campaigns;
};
#endif

int RGE_Person_Info::get_current_scenario(void) {
    int i;

    i = this->current_campaign;
    if (i > -1 && this->campaigns[i] != 0)
        return this->campaign_info[i]->get_current_scenario();
    return -1;
}
