class RGE_Base_Game_cdt {
public:
    void set_countdown_timer(int index, int value);
    char gap_00[0x9D8];
    int countdown_timers[1];
};

void RGE_Base_Game_cdt::set_countdown_timer(int index, int value) {
    int current = this->countdown_timers[index];
    if (current > value || current < 0) {
        this->countdown_timers[index] = value;
    }
}
