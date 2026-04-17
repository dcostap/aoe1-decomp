class RGE_Person_Info {
public:
    long get_current_scenario(void);
};

class RGE_Game_Info {
public:
    long current_person;
    long people_num;
    RGE_Person_Info** people_info;

    long get_current_scenario(void);
};

long RGE_Game_Info::get_current_scenario(void) {
    long current_person;

    current_person = this->current_person;
    if (current_person < this->people_num) {
        if (current_person >= 0) {
            return this->people_info[current_person]->get_current_scenario();
        }
    }
    return -1;
}
