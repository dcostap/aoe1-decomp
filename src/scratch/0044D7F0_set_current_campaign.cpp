class RGE_Campaign_scc {
public:
    unsigned char set_current_campaign(int campaign);
};

class RGE_Campaign_Info_scc {
public:
    unsigned char set_current_campaign(int campaign);
    int person_index;
    int people_count;
    void** campaigns;
};

unsigned char RGE_Campaign_Info_scc::set_current_campaign(int campaign) {
    if (this->person_index >= this->people_count) return 0;
    if (this->person_index < 0) return 0;
    return ((RGE_Campaign_scc*)this->campaigns[this->person_index])->set_current_campaign(campaign);
}
