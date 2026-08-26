#if !defined(COM_HAND_TU_CONTEXT)
struct COMMPLAYEROPTIONS {
public:
    char gap_00[8];
    int ProgramState;
};
class TCommunications_Handler {
public:
    char gap_00[0x1550];
    COMMPLAYEROPTIONS PlayerOptions;
    int IsPaused();
};
#endif // COM_HAND_TU_CONTEXT


int TCommunications_Handler::IsPaused() {
    return this->PlayerOptions.ProgramState == 4;
}
