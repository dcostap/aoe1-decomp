#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x1558];
    int ProgramState;

    void NotifyWindowParam(int command, unsigned int param);
protected:
    void LocalPauseGame(unsigned int player);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::LocalPauseGame(unsigned int player) {
    this->PlayerOptions.ProgramState = 4;
    this->NotifyWindowParam(0x17A2, player);
}
