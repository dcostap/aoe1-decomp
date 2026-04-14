class TCommunications_Handler_mpgs {
public:
    int MultiplayerGameStart(void);
    void DoCycle(int param);
    char gap_00[0x10C8];
    int current_turn;
    char gap_10CC[0x18];
    int multiplayer_flag;
};

int TCommunications_Handler_mpgs::MultiplayerGameStart(void) {
    if (!this->multiplayer_flag)
        return 1;
    if (this->current_turn > 6)
        return 1;
    this->DoCycle(0);
    return 0;
}
