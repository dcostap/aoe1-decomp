class RGE_Game_Info {
public:
    long current_person;
    long people_num;

    unsigned char set_current_person(long person);
};

unsigned char RGE_Game_Info::set_current_person(long person) {
    if (person < this->people_num) {
        this->current_person = person;
        return 1;
    }
    this->current_person = -1;
    return 0;
}
