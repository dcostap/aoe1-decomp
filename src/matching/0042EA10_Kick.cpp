// 0042EA10 TCommunications_Handler::Kick (Com_hand.cpp:6506-6548)

extern "C" int g_DirectPlayConversation;  // 62C5ECh

#if !defined(COM_HAND_TU_CONTEXT)
class TDebuggingLog {
public:
    static void __cdecl Log(TDebuggingLog* log, const char* format, ...);
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
extern TDebuggingLog* L;  // 62C4FCh
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
struct MSGFORMAT_KILL_PLAYER {
    int dcoID;
    int CurrentTurn;
    int current_turn;
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
struct COMMPLAYEROPTIONS {
    char gap_00[0x14];
    unsigned long dcoID[10];
};

class TCommunications_Handler {
public:
    char gap_00[0x1C];
    int MeHost;                        // +0x1C
    char gap_20[0x10A8];
    unsigned long current_turn;        // +0x10C8
    char gap_10CC[0x20C];
    unsigned short MaxGamePlayers;     // +0x12D8
    char gap_12DA[0xE2];
    unsigned long PlayerStopTurn[1];   // +0x13BC (array base, size 10)
    char gap_13C0[0x190];
    COMMPLAYEROPTIONS PlayerOptions;   // dcoID at +0x1564

    int IsPlayerHuman(unsigned int player);
    void DropDeadPlayer(unsigned int player, unsigned long dco);
    long CommOut(long a, long b, void* buf, long size, long c);
    void NotifyWindow(unsigned long msg);
    long SendSharedData(long a);

    int Kick(unsigned int param_1);
};
#endif // COM_HAND_TU_CONTEXT


int TCommunications_Handler::Kick(unsigned int param_1)
{
    if (param_1 >= 1 && param_1 <= this->MaxGamePlayers && g_DirectPlayConversation) {
        if (this->IsPlayerHuman(param_1)) {
            if (this->PlayerOptions.dcoID[param_1] != 0) {
                MSGFORMAT_KILL_PLAYER kp;
                kp.dcoID = param_1;
                kp.CurrentTurn = this->PlayerOptions.dcoID[param_1];
                kp.current_turn = this->current_turn;

                TDebuggingLog::Log(L, "Sent to all - drop player %d ID=%d ", param_1, this->PlayerOptions.dcoID[param_1]);
                TDebuggingLog::Log(L, "  >TX KP3 #d (%d)", param_1, 0x0C);

                this->CommOut(0, 'K', &kp, 0x0C, 0);

                if (this->PlayerStopTurn[param_1] == 0) {
                    this->DropDeadPlayer(param_1, this->PlayerOptions.dcoID[param_1]);
                }
            }

            this->NotifyWindow(0x17A4);

            if (this->MeHost != 0 && this->current_turn <= 6) {
                this->SendSharedData(1);
            }

            return 1;
        }
    }
    return 0;
}
