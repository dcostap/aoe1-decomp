// target: VA 0042C880 TCommunications_Handler::SendPauseGame(int)
// first pass: preserve the multiplayer/host guards, log branch, and CommOut call shape

class TDebuggingLog;

void TDebuggingLog_Log(TDebuggingLog* log, const char* msg);

class TCommunications_Handler {
public:
    char gap_00[0x1C];
    int MeHost; // +0x1C
    char gap_20[0x10C4];
    int Multiplayer; // +0x10E4

    long CommOut(int, int, int, int, int);
    void SendPauseGame(int param_1);
};

void TCommunications_Handler::SendPauseGame(int param_1) {
    if (this->Multiplayer == 0) {
        return;
    }
    if (this->MeHost == 0) {
        return;
    }

    if (param_1 != 0) {
        TDebuggingLog_Log(*(TDebuggingLog**)0x62C4FC, (const char*)0x58280C);
        this->CommOut(0, 0x50, 0, 0, 0);
        return;
    }

    TDebuggingLog_Log(*(TDebuggingLog**)0x62C4FC, (const char*)0x5827FC);
    this->CommOut(0, 0x55, 0, 0, 0);
}
