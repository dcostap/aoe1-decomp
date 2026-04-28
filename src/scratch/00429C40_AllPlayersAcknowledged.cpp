// TCommunications_Handler::AllPlayersAcknowledged
// VA: 00429C40
// Com_hand.cpp:2952-2994
// 146 bytes, not matched (parked)
// Loops from LowPlayerNumber to HighPlayerNumber, checking if all human players
// have acknowledged the current turn. Returns 1 if yes, 0 if any human player
// hasn't acked yet.
//
// Attempt log (7 forms):
// v0: for(i=Low; i<=High; i++) + if/else + separate return-1 after loop → 144 bytes (2 short)
// v1: goto-based early check → same size issue
// v2: if(Low<=High) { do { } while(); } → same
// v3: while(1) with break → same
// v4: local hi var, do { } while(i<=hi); → same  
// v5: pointer-arithmetic for fields → same
// v6: local result var → changes structure entirely
//
// Remaining diff: VC5 merges the two distinct return-1 epilogues (after-loop vs
// Low>High) into one shared epilogue. Original has 3 separate epilogues (return 1
// after loop, return 0, return 1 for Low>High). 2 bytes short.
//
// Fields: +0x10C8 current_turn, +0x10E4 Multiplayer, +0x12A8 ShuttingDown,
// +0x1558 ProgramState, +0x1710 HighPlayerNumber, +0x1712 LowPlayerNumber,
// +0x1720 LastTurnAck[]

#include "../../include/game_globals.h"

class TCommunications_Handler {
public:
    char gap_00[0x10C8];
    int current_turn;
    char gap_10CC[0x10E4 - 0x10CC];
    int Multiplayer;
    char gap_10E8[0x12A8 - 0x10E8];
    int ShuttingDown;
    char gap_12AC[0x1558 - 0x12AC];
    int ProgramState;
    char gap_155C[0x1710 - 0x155C];
    unsigned short HighPlayerNumber;
    unsigned short LowPlayerNumber;
    char gap_1714[0x1720 - 0x1714];
    int LastTurnAck[1];

    int AllPlayersAcknowledged(void);
    int IsPlayerHuman(int player);
};

int TCommunications_Handler::AllPlayersAcknowledged(void) {
    if (this->Multiplayer == 0)
        return 0;

    if (this->ShuttingDown != 0)
        return 0;

    if (this->ProgramState == 4)
        return 0;

    {
        unsigned int i = this->LowPlayerNumber;
        if (i > this->HighPlayerNumber)
            return 1;

        do {
            if (IsPlayerHuman((int)i)) {
                if ((unsigned int)LastTurnAck[i] < (unsigned int)current_turn)
                    return 0;
            }
            i++;
        } while (i <= this->HighPlayerNumber);
    }
    return 1;
}
