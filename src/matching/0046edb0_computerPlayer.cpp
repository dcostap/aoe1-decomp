#ifndef PLAYER_GROUPED_TU
class RGE_Player {
public:
    virtual ~RGE_Player();
    int computerPlayerValue;
    int pathingAttemptCap_;
    int pathingDelayCap_;
    int currentUpdatePathingAttempts_;
    char gap_14[0x6D];
    unsigned char resigned_;
    char gap_82[0x82];
    unsigned char allied_victory_;

    int computerPlayer() const;
};
#endif

int RGE_Player::computerPlayer() const {
    return this->computerPlayerValue;
}
