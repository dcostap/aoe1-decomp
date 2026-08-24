#ifndef GAMEINFO_SHARED_CONTEXT
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
#endif

unsigned char RGE_Game_Info::set_current_scenario(int scenario) {
    if (this->current_person >= 0 && this->current_person < this->people_num)
        return this->people_info[this->current_person]->set_current_scenario(scenario);
    return 0;
}
