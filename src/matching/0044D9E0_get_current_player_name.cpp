class RGE_Person_Info {
public:
    char* get_name(void);
};

class RGE_Game_Info {
public:
    long current_person;
    long gap_04;
    RGE_Person_Info** people_info;

    char* get_current_player_name(void);
};

char* RGE_Game_Info::get_current_player_name(void) {
    long current_person;

    current_person = this->current_person;
    if (current_person < 0) {
        return 0;
    }
    return this->people_info[current_person]->get_name();
}
