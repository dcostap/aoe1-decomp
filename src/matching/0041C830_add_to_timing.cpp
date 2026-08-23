// 0041C830 RGE_Base_Game::add_to_timing (60B)
// basegame.cpp

#ifndef BASEGAME_GROUPED_TU
class RGE_Timing_Info {
public:
    unsigned long accum_time;       // +0x00
    unsigned long last_time;        // +0x04
    unsigned long start_time;       // +0x08
    int include_in_total;           // +0x0C
    int is_summary;                 // +0x10
    unsigned long last_single_time; // +0x14
    unsigned long max_time;         // +0x18
    unsigned long last_max_time;    // +0x1C
};

class RGE_Base_Game {
public:
    char gap_00[0x528];
    RGE_Timing_Info timings[30];

    void add_to_timing(int index, unsigned long value);
};
#endif

void RGE_Base_Game::add_to_timing(int index, unsigned long value) {
    timings[index].accum_time += value;
    timings[index].last_single_time = value;
    if (value > timings[index].max_time) {
        timings[index].max_time = value;
    }
}
