#ifndef GAMEINFO_SHARED_CONTEXT
class RGE_Person_Info;

class RGE_Game_Info {
public:
    long current_person;
    long people_num;
    RGE_Person_Info** people_info;

    long get_scenario_list(char*** param_1, long* param_2);
};

class RGE_Person_Info {
public:
    long get_current_scenario();
    long get_scenario_list(char*** param_1, long* param_2);
};
#endif

long RGE_Game_Info::get_scenario_list(char*** param_1, long* param_2) {
    if (this->current_person < this->people_num) {
        if (0 <= this->current_person) {
            *param_2 = this->people_info[this->current_person]->get_current_scenario();
            return this->people_info[this->current_person]->get_scenario_list(param_1, param_2);
        }
    }
    *param_2 = -1;
    return -1;
}
