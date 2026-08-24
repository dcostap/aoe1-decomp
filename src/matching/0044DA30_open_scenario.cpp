#ifndef GAMEINFO_SHARED_CONTEXT
class RGE_Person_Info {
public:
    int open_scenario(void);
};

class RGE_Game_Info {
public:
    long current_person;
    long people_num;
    RGE_Person_Info** people_info;

    int open_scenario(void);
};
#endif

int RGE_Game_Info::open_scenario(void) {
    long current_person;

    current_person = this->current_person;
    if (current_person < this->people_num) {
        if (current_person >= 0) {
            return this->people_info[current_person]->open_scenario();
        }
    }
    return -1;
}
