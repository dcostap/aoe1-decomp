#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class TRIBE_History_Info {
public:
    void add_history_entry(unsigned char param_1, int param_2);
};

class TRIBE_Population_Source {
public:
    char gap_00[0x2C];
    float population_value;
};

class TRIBE_Player {
public:
    char gap_00[0x50];
    TRIBE_Population_Source* population_source;
    char gap_54[0x7E8];
    TRIBE_History_Info* history;

    void add_population_entry(void);
};
#endif

void TRIBE_Player::add_population_entry(void) {
    if (this->population_source->population_value < 0.0f) {
        this->history->add_history_entry(0, 0);
        return;
    }

    this->history->add_history_entry(0, (int)this->population_source->population_value);
}
