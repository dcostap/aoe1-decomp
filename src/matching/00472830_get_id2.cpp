class Pnl_drop {
public:
    char gap_0[0x118];
    int ids2[55];
    char gap_1F4b[2];
    short currentIndex;
    int get_id2();
};

int Pnl_drop::get_id2() {
    return this->ids2[(int)this->currentIndex];
}
