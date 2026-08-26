#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x1558];
    int ProgramState;

    void NotifyWindowParam(int command, unsigned int param);
protected:
    void LocalResumeGame(unsigned int player);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::LocalResumeGame(unsigned int player) {
    this->PlayerOptions.ProgramState = 5;
    this->NotifyWindowParam(0x17A3, player);
}
