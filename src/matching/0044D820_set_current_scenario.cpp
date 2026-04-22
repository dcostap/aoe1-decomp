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
    if (this->person_index >= 0 && this->person_index < this->people_count)
        return ((RGE_Campaign_scs*)this->campaigns[this->person_index])->set_current_scenario(scenario);
    return 0;
}
