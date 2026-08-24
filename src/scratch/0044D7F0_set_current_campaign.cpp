#ifndef GAMEINFO_SHARED_CONTEXT
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
#endif

unsigned char RGE_Game_Info::set_current_campaign(int campaign) {
    if (this->current_person < this->people_num && this->current_person >= 0)
        return this->people_info[this->current_person]->set_current_campaign(campaign);
    return 0;
}
