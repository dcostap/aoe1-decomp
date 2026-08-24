#ifndef GAMEINFO_SHARED_CONTEXT
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
#endif

void RGE_Game_Info::notify_of_scenario_complete(void) {
    if (this->current_person < this->people_num && this->current_person >= 0) {
        this->people_info[this->current_person]->notify_of_scenario_complete();
    }
    this->save(this->save_filename);
}
