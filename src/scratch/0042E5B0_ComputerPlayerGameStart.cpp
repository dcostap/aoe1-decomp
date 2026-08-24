class TCommunications_Handler_cpgs {
public:
    int ComputerPlayerGameStart(void);
    char gap_00[0x10C8];
    int current_turn;
    char gap_10CC[0x18];
    int multiplayer_flag;
};


int TCommunications_Handler_cpgs::ComputerPlayerGameStart(void) {
    if (!this->multiplayer_flag)
        return 1;
    // sbb+neg pattern: returns (6 < current_turn) i.e. current_turn > 6
    return (unsigned int)6 < (unsigned int)this->current_turn;
}
