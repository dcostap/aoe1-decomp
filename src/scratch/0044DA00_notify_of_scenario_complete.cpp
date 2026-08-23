class RGE_Campaign_nsc {
public:
    void notify_of_scenario_complete(void);
};

class RGE_Campaign_Info_nsc {
public:
    void notify_of_scenario_complete(void);
    void save_state(char* path);
    int person_index;
    int people_count;
    void** campaigns;
    char gap_0C[0x08];
    char save_path[1];
};

void RGE_Campaign_Info_nsc::notify_of_scenario_complete(void) {
    if (this->person_index < this->people_count && this->person_index >= 0) {
        ((RGE_Campaign_nsc*)this->campaigns[this->person_index])->notify_of_scenario_complete();
    }
    this->save_state(this->save_path);
}
