struct Inner_00541EA0 {
    void target(int param);
};

class RGE_Game_World {
public:
    char gap_0[0x58];
    Inner_00541EA0 *ptr_;
    void reset_communications(int param);
};

void RGE_Game_World::reset_communications(int param) {
    this->ptr_->target(param);
}
