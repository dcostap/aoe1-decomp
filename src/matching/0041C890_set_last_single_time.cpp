class RGE_Base_Game {
public:
    char gap_0[0x53C];
    char data_[1];
    void set_last_single_time(int i, unsigned long v);
};

void RGE_Base_Game::set_last_single_time(int i, unsigned long v) {
    *(unsigned long *)((char *)&this->data_ + (i << 5)) = v;
}
