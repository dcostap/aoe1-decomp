class RGE_Timing_Info {
public:
    unsigned long accum_time;
    unsigned long last_time;
    unsigned long start_time;
    int include_in_total;
    int is_summary;
    unsigned long last_single_time;
    unsigned long max_time;
    unsigned long last_max_time;
};

class RGE_Base_Game {
public:
    char gap_00[0x528];
    RGE_Timing_Info timings[30];

    void add_to_timing(int index, unsigned long value);
};

void RGE_Base_Game::add_to_timing(int index, unsigned long value) {
    RGE_Timing_Info* timing = &this->timings[index];
    timing->accum_time += value;
    timing->last_single_time = value;
    if (timing->max_time < value) {
        timing->max_time = value;
    }
}
