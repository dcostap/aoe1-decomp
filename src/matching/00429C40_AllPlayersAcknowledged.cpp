// 00429C40 TCommunications_Handler::AllPlayersAcknowledged (Com_hand.cpp:2952-2994, 146B)
// FLAGS: default
// MATCH: 0.0000% (146/146 bytes exact)
//
// Key insights:
// - unsigned int i = Low: gives xor esi;mov si zero-ext pattern
// - for(; i <= High; i++): gives jbe at loop bottom + memory reload of High + separate return-1 epilogues
// - no unsigned int high local: avoids push ebp (3-register save matches original)

class TCommunications_Handler {
public:
    char gap_00[0x10C8];
    int current_turn;             // +0x10C8
    char gap_10CC[0x10E4 - 0x10CC];
    int Multiplayer;               // +0x10E4
    char gap_10E8[0x12A8 - 0x10E8];
    int ShuttingDown;              // +0x12A8
    char gap_12AC[0x1558 - 0x12AC];
    int ProgramState;              // +0x1558
    char gap_155C[0x1710 - 0x155C];
    unsigned short HighPlayerNumber;  // +0x1710
    unsigned short LowPlayerNumber;   // +0x1712
    char gap_1714[0x1720 - 0x1714];
    int LastTurnAck[1];            // +0x1720

    int IsPlayerHuman(int player);
    int AllPlayersAcknowledged(void);
};

int TCommunications_Handler::AllPlayersAcknowledged(void)
{
    if (this->Multiplayer == 0)
        return 0;

    if (this->ShuttingDown != 0)
        return 0;

    if (this->ProgramState == 4)
        return 0;

    unsigned int i = this->LowPlayerNumber;

    if (i > this->HighPlayerNumber)
        return 1;

    for (; i <= this->HighPlayerNumber; i++) {
        if (IsPlayerHuman(i)) {
            if ((unsigned int)this->LastTurnAck[i] < (unsigned int)this->current_turn)
                return 0;
        }
    }

    return 1;
}
