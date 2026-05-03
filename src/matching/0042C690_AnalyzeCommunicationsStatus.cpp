// 0042C690 TCommunications_Handler::AnalyzeCommunicationsStatus
// Initial source from packet/decompiler; exact-match in progress.

#include <string.h>
#include "../../include/game_globals.h"

class TCommunications_Handler {
public:
    char gap_0000[0x001C];
    int MeHost;                 // +0x001C
    char gap_0020[0x10C8 - 0x0020];
    unsigned int current_turn;  // +0x10C8
    char gap_10CC[0x10E0 - 0x10CC];
    unsigned int Me;            // +0x10E0
    int Multiplayer;            // +0x10E4
    char gap_10E8[0x12DC - 0x10E8];
    char ServiceGUID[16];       // +0x12DC
    char gap_12EC[0x10];
    char NullGUID[16];          // +0x12FC
    char gap_130C[0x1318 - 0x130C];
    char SessionGUID[16];       // +0x1318
    char gap_1328[0x1550 - 0x1328];
    unsigned char NeedsToBeSent;// +0x1550
    char gap_1551[0x1558 - 0x1551];
    int ProgramState;           // +0x1558

    int IsPaused(void);
    int AnalyzeCommunicationsStatus(void);
};

int TCommunications_Handler::AnalyzeCommunicationsStatus(void) {
    if (this->IsPaused() && this->current_turn >= 6) {
        return 15;
    }
    if (this->ProgramState == 5 && this->current_turn >= 6) {
        return 14;
    }
    if (this->ProgramState == 5 && this->current_turn < 6) {
        return 13;
    }
    if (this->NeedsToBeSent) {
        return 12;
    }
    if (DAT_0062cf04 != 0) {
        return 9;
    }
    if (this->MeHost != 0) {
        return 7;
    }
    if (memcmp(this->NullGUID, this->SessionGUID, 16) != 0) {
        return 6;
    }
    if (memcmp(this->ServiceGUID, this->SessionGUID, 16) != 0) {
        return 5;
    }
    if (DAT_0062c5ec != 0) {
        return 4;
    }
    if (this->Multiplayer != 0) {
        return 3;
    }
    return 2 + (this->Me - 1 ? -1 : 0);
}
