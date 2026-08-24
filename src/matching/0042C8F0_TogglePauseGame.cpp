#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x12A0];
    int PauseChangePending;

    int IsPaused();
    void RequestPauseGame(int value);
    void RequestResumeGame(int value);
    int TogglePauseGame();
};
#endif // COM_HAND_TU_CONTEXT


int TCommunications_Handler::TogglePauseGame() {
    if (PauseChangePending != 0) {
        return 0;
    }
    if (IsPaused() != 0) {
        RequestResumeGame(0);
    } else {
        RequestPauseGame(0);
    }
    return 1;
}
