// attempt 1: direct 3-way branch with the LocalPauseGame / SendPauseGame / log+CommOut paths
// result: exact match after switching the log helper to a free-function call on the global TDebuggingLog pointer
// moved to src\matching\0042C930_RequestPauseGame.cpp after local validation

class TDebuggingLog;
extern TDebuggingLog* DAT_0062C4FC;
#if !defined(COM_HAND_TU_CONTEXT)
extern void Log(TDebuggingLog* log, char* text);
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x1C];
    int MeHost;
    char gap_20[0x10C0];
    unsigned int Me;
    int Multiplayer;

    void LocalPauseGame(unsigned int player);
    void SendPauseGame(int value);
    long CommOut(int, int, int, int, int);
    void RequestPauseGame(int value);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::RequestPauseGame(int) {
    if (this->Multiplayer == 0) {
        this->LocalPauseGame(this->Me);
        return;
    }

    if (this->MeHost != 0) {
        this->SendPauseGame(1);
        this->LocalPauseGame(this->Me);
        return;
    }

    Log(*(TDebuggingLog**)0x62C4FC, "  >TX_REQ_PAUSE");
    this->CommOut(0, 0x57, 0, 0, 0);
}
