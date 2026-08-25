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

    void notify(int, int, int, int, int, int);
};
#endif

void RGE_Player::notify(int, int, int, long, long, long) {
}
