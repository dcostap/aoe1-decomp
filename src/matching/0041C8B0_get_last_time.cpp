#ifndef BASEGAME_GROUPED_TU
class RGE_Base_Game {
public:
    char gap_0[0x52C];
    char data_[1];
    unsigned long get_last_time(int i);
};
#endif

unsigned long RGE_Base_Game::get_last_time(int i) {
#ifdef BASEGAME_GROUPED_TU
    return *(unsigned long *)((char *)&this->data_ + 4 + (i << 5));
#else
    return *(unsigned long *)((char *)&this->data_ + (i << 5));
#endif
}
