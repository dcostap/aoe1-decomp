class RGE_Base_Game {
public:
    char gap_0[0x528];
    char data_[1];
    unsigned long get_accum_time(int i);
};

unsigned long RGE_Base_Game::get_accum_time(int i) {
    return *(unsigned long *)((char *)&this->data_ + (i << 5));
}
