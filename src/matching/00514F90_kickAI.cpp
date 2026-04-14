struct Inner_00514F90 {
    void target(int param);
};

class TRIBE_Player {
public:
    char gap_0[0x238];
    Inner_00514F90 *inner_;
    void kickAI(int param);
};

void TRIBE_Player::kickAI(int param) {
    if (this->inner_)
        this->inner_->target(param);
}
