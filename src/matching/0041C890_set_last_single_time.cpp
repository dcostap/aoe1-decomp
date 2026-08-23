#ifndef BASEGAME_GROUPED_TU
class RGE_Base_Game {
public:
    char gap_0[0x53C];
    char data_[1];
    void set_last_single_time(int i, unsigned long v);
};
#endif

void RGE_Base_Game::set_last_single_time(int i, unsigned long v) {
#ifdef BASEGAME_GROUPED_TU
    *(unsigned long *)((char *)&this->data_ + 0x14 + (i << 5)) = v;
#else
    *(unsigned long *)((char *)&this->data_ + (i << 5)) = v;
#endif
}
