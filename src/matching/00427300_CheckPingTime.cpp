// TCommunications_Handler::CheckPingTime
// VA: 00427300
// Com_hand.cpp:1116-1129
// MATCH: 0.0000% diff, 4 relocations masked

#include "../../include/game_globals.h"

class TCommunications_Handler {
public:
    char gap_00[0x10E0];
    int Me;                      // +0x10E0
    int Multiplayer;             // +0x10E4
    char gap_10E8[0x12D8 - 0x10E8];
    short MaxGamePlayers;        // +0x12D8
    char gap_12DA[0x1398 - 0x12DA];
    unsigned long LastTXPing[1]; // +0x1398

    int IsPlayerHuman(int playerIndex);
    void TXPing(int playerIndex);
    void CheckPingTime(int param_1);
};

extern "C" unsigned long debug_timeGetTime(char* file, int line);

void TCommunications_Handler::CheckPingTime(int param_1) {
    if (!this->Multiplayer)
        return;

    unsigned long currentTime = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x460);

    unsigned int i = 1;
    if ((unsigned int)(unsigned short)this->MaxGamePlayers < i)
        return;

    unsigned long* lastPing = this->LastTXPing;
    do {
        if (this->IsPlayerHuman(i) && i != (unsigned int)this->Me) {
            unsigned long elapsed = currentTime - *lastPing;
            if (elapsed > 8000 || param_1) {
                this->TXPing(i);
            }
        }
        i++;
        lastPing++;
    } while (i <= (unsigned int)(unsigned short)this->MaxGamePlayers);
}
