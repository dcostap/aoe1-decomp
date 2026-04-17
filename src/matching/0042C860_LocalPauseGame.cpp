class TCommunications_Handler {
public:
    char gap_00[0x1558];
    int ProgramState;

    void NotifyWindowParam(int command, unsigned int param);
    void LocalPauseGame(unsigned int player);
};

void TCommunications_Handler::LocalPauseGame(unsigned int player) {
    ProgramState = 4;
    NotifyWindowParam(0x17A2, player);
}
