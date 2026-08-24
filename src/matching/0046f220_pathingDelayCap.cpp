#ifndef PLAYER_GROUPED_TU
class RGE_Player {
public:
    virtual ~RGE_Player();
    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    char gap_14[0x6D];
    unsigned char resigned_;
    char gap_82[0x82];
    unsigned char allied_victory_;

    int pathingDelayCap();
};
#endif

int RGE_Player::pathingDelayCap() {
    return this->pathingDelayCapValue;
}
