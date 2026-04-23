class RGE_Player {
public:
    char gap_00[0x8];
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;

    int availablePathingAttempts(int value);
};

int RGE_Player::availablePathingAttempts(int value) {
    if (pathingDelayCapValue != -1 && value > pathingDelayCapValue) {
        return 1;
    }
    if (pathingAttemptCapValue == -1) {
        return 1;
    }
    return currentUpdatePathingAttemptsValue < pathingAttemptCapValue;
}
