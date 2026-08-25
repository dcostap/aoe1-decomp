// 0041C830 RGE_Base_Game::add_to_timing (60B)
// basegame.cpp


void RGE_Base_Game::add_to_timing(int index, unsigned long value) {
    timings[index].accum_time += value;
    timings[index].last_single_time = value;
    if (value > timings[index].max_time) {
        timings[index].max_time = value;
    }
}
