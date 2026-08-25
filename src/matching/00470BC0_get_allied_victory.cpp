#ifndef PLAYER_GROUPED_TU
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

    unsigned char get_allied_victory();
};
#endif

unsigned char RGE_Player::get_allied_victory() {
    return this->allied_victory;
}
