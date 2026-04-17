class RGE_Campaign_scs {
public:
    unsigned char set_current_scenario(int scenario);
};

class RGE_Campaign_Info_scs {
public:
    unsigned char set_current_scenario(int scenario);
    int person_index;
    int people_count;
    void** campaigns;
};

unsigned char RGE_Campaign_Info_scs::set_current_scenario(int scenario) {
    int idx = this->person_index;
    if (idx < 0) {
        goto fail;
    }
    if (idx >= this->people_count) {
        goto fail;
    }
    return ((RGE_Campaign_scs*)this->campaigns[idx])->set_current_scenario(scenario);
fail:
    return 0;
}
