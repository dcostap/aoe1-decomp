// TCommunications_Handler::WaitingOnNamedInfo
// VA: 00425780
// Com_hand.cpp:134-152
// MATCH: 0.0000% diff, 0 relocations masked

#include "../../include/game_globals.h"

class TCommunications_Handler {
public:
    char gap_00[0xFC5];
    char TBuff[0x37F];              // +0xFC5, ends at 0x1344
    int LastPlayerCommunication[4]; // +0x1344
    char gap_1354[0x1720 - 0x1354]; // gap
    int LastTurnAck[4];             // +0x1720

    char* WaitingOnInfo(int playerIndex);
    char* GetPlayerName(int playerIndex);
    char* WaitingOnNamedInfo(int playerIndex);
};

extern "C" int debug_timeGetTime(char* file, int line);
extern "C" int sprintf(char* buffer, const char* format, ...);

char* TCommunications_Handler::WaitingOnNamedInfo(int playerIndex) {
    sprintf(this->TBuff, "[%d] %s - %s", playerIndex,
        this->GetPlayerName(playerIndex),
        this->WaitingOnInfo(playerIndex));

    int timeSince = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x8E)
        - this->LastPlayerCommunication[playerIndex];

    sprintf(this->TBuff, "[%d] %s - %s (QUIET=%d msec  T#=%d )",
        playerIndex,
        this->GetPlayerName(playerIndex),
        this->WaitingOnInfo(playerIndex),
        timeSince,
        this->LastTurnAck[playerIndex]);

    return this->TBuff;
}
