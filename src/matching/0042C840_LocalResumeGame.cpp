class TCommunications_Handler {
public:
    char gap_00[0x1558];
    int ProgramState;

    void NotifyWindowParam(int command, unsigned int param);
    void LocalResumeGame(unsigned int player);
};

void TCommunications_Handler::LocalResumeGame(unsigned int player) {
    ProgramState = 5;
    NotifyWindowParam(0x17A3, player);
}
