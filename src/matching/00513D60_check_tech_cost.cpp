struct Inner_00513D60 {
    void target(int a, int b);
};

class TRIBE_Player {
public:
    char gap_0[0x220];
    Inner_00513D60 *ptr_;
    void check_tech_cost(int a, int b);
};

void TRIBE_Player::check_tech_cost(int a, int b) {
    this->ptr_->target(a, b);
}
