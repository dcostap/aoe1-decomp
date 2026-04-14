class RGE_Campaign_gcs {
public:
    int get_current_scenario(void);
};

class RGE_Campaign_Info_gcs {
public:
    int get_current_scenario(void);
    char gap_00[0x100];
    int current_person;
    char gap_104[0x04];
    void** campaigns;
    char gap_10C[0x04];
    int* campaign_valid;
};

int RGE_Campaign_Info_gcs::get_current_scenario(void) {
    int idx = this->current_person;
    if (idx <= -1) return -1;
    if (!this->campaign_valid[idx]) return -1;
    return ((RGE_Campaign_gcs*)this->campaigns[idx])->get_current_scenario();
}
