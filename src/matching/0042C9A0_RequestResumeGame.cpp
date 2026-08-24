// 0042C9A0 TCommunications_Handler::RequestResumeGame
// Source: Com_hand.cpp lines 4856-4887. 124 bytes. __thiscall, ret 4.
//
// MATCHED. Exact 124-byte match confirmed via local check_function.py.
// Sibling to RequestPauseGame (0042C930); same 3-way branch structure
// but with Log before LocalResumeGame in !Multiplayer path, SendPauseGame(0),
// different strings, and CommOut(0, '+', 0, 0, 0).

class TDebuggingLog;
extern TDebuggingLog* DAT_0062C4FC;
#if !defined(COM_HAND_TU_CONTEXT)
extern void Log(TDebuggingLog* log, char* text);
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x1C];
    int MeHost;                        // +0x1C
    char gap_20[0x10C0];
    unsigned int Me;                   // +0x10E0
    int Multiplayer;                   // +0x10E4

    void LocalResumeGame(unsigned int player);
    void SendPauseGame(int value);
    long CommOut(int, int, int, int, int);
    void RequestResumeGame(int value);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::RequestResumeGame(int) {
    if (this->Multiplayer == 0) {
        Log(DAT_0062C4FC, "Resume requested");
        this->LocalResumeGame(this->Me);
        return;
    }

    if (this->MeHost != 0) {
        this->SendPauseGame(0);
        this->LocalResumeGame(this->Me);
        return;
    }

    Log(DAT_0062C4FC, "  >TX REQ RES");
    this->CommOut(0, 0x2B, 0, 0, 0);
}
