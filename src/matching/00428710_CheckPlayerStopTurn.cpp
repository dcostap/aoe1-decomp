// VA: 00428710 CheckPlayerStopTurn (252 bytes)
// PDB: Com_hand.cpp lines 2144-2171
// __thiscall
//
// Attempt log:
// 1: Initial period-plausible reconstruction: named MaxGamePlayers,
//    PlayerStopTurn, current-turn guard, and the two natural player scans.

struct TDebuggingLog {
    void Log(char* format, ...);
};

#define L (*(TDebuggingLog**)0x0062C4FC)
#define S(address) ((char*)(address))

class TCommunications_Handler {
public:
    char gap_0000[0x10C8];
    unsigned int current_turn;
    char gap_10CC[0x10E0 - 0x10CC];
    unsigned int Me;
    char gap_10E4[0x12D8 - 0x10E4];
    unsigned short MaxGamePlayers;
    char gap_12DA[0x13BC - 0x12DA];
    int PlayerStopTurn[16];

    void InitPlayerInformation(unsigned int player, unsigned long dco_id,
                               char* status, char* information);
    void SetPlayerHumanity(unsigned int player, int humanity);
    void NotifyWindowParam(int message, int player);
    int IsPlayerHuman(unsigned int player);
    int IsPlayerComputer(unsigned int player);
    void NotifyWindow(int message);
    void CheckPlayerStopTurn(unsigned long turn);
};

void TCommunications_Handler::CheckPlayerStopTurn(unsigned long turn)
{
    int StopPending = 0;
    unsigned int i = 1;

    if (this->MaxGamePlayers >= i) {
        do {
            if (this->PlayerStopTurn[i] != 0)
                StopPending = 1;

            if (this->PlayerStopTurn[i] == turn) {
                L->Log(S(0x581710), i, turn);
                this->InitPlayerInformation(i, 0, S(0x581704), S(0x580460));
                this->SetPlayerHumanity(i, 3);
                this->NotifyWindowParam(0x17B4, i);
                this->PlayerStopTurn[i] = 0;
            }
            ++i;
        } while (i <= this->MaxGamePlayers);
    }

    if (this->current_turn > 6 && StopPending == 0) {
        StopPending = 0;
        i = 1;
        if (this->MaxGamePlayers >= i) {
            do {
                if (this->IsPlayerHuman(i) || this->IsPlayerComputer(i)) {
                    if (i != this->Me)
                        StopPending = 1;
                }
                ++i;
            } while (i <= this->MaxGamePlayers);
        }
        if (StopPending == 0)
            this->NotifyWindow(0x17BC);
    }
}
