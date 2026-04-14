class Pnl_drop {
public:
    char gap_0[0xF4];
    int ids[64];
    char gap_1F4[2];
    short currentIndex;
    int get_id();
};

int Pnl_drop::get_id() {
    return this->ids[(int)this->currentIndex];
}
