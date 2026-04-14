class RGE_Player {
public:
    virtual ~RGE_Player();
    int computerPlayer_;
    int pathingAttemptCap_;
    int pathingDelayCap_;
    int currentUpdatePathingAttempts_;
    char gap_14[0x6D];
    unsigned char resigned_;
    char gap_82[0x82];
    unsigned char allied_victory_;

    void set_allied_victory(unsigned char v);
};

void RGE_Player::set_allied_victory(unsigned char v) {
    this->allied_victory_ = v;
}
