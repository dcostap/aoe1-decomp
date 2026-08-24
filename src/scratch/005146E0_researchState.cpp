#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
struct Inner_005146E0 {
    void target(int param);
};

class TRIBE_Player {
public:
    char gap_0[0x220];
    Inner_005146E0 *ptr_;
    void researchState(int param);
};
#endif

void TRIBE_Player::researchState(int param) {
    this->ptr_->target(param);
}
