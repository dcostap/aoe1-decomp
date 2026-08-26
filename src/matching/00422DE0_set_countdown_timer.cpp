void RGE_Base_Game::set_countdown_timer(long index, long value) {
    long current = this->countdown_timer[index];
    if (current > value || current < 0) {
        this->countdown_timer[index] = value;
    }
}
