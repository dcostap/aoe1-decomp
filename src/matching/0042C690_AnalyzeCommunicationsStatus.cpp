// 0042C690 TCommunications_Handler::AnalyzeCommunicationsStatus
// Initial source from packet/decompiler; exact-match in progress.

#include <string.h>
#if !defined(COM_HAND_TU_CONTEXT)
#include "../../include/game_globals.h"
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
enum COMMSTATUS {
    COMMSTATUS_UNINITIALIZED = 0
};

struct COMMPLAYEROPTIONS {
    unsigned char NeedsToBeSent;
    char gap_01[7];
    int ProgramState;
};

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
    COMMPLAYEROPTIONS PlayerOptions; // +0x1550

    int IsPaused(void);
    COMMSTATUS AnalyzeCommunicationsStatus(void);
};
#endif // COM_HAND_TU_CONTEXT


COMMSTATUS TCommunications_Handler::AnalyzeCommunicationsStatus(void) {
    if (this->IsPaused() && this->current_turn >= 6) {
        return (COMMSTATUS)15;
    }
    if (this->PlayerOptions.ProgramState == 5 && this->current_turn >= 6) {
        return (COMMSTATUS)14;
    }
    if (this->PlayerOptions.ProgramState == 5 && this->current_turn < 6) {
        return (COMMSTATUS)13;
    }
    if (this->PlayerOptions.NeedsToBeSent) {
        return (COMMSTATUS)12;
    }
    if (DAT_0062cf04 != 0) {
        return (COMMSTATUS)9;
    }
    if (this->MeHost != 0) {
        return (COMMSTATUS)7;
    }
    if (memcmp(&this->NullGUID, &this->SessionGUID, 16) != 0) {
        return (COMMSTATUS)6;
    }
    if (memcmp(&this->ServiceGUID, &this->SessionGUID, 16) != 0) {
        return (COMMSTATUS)5;
    }
    if (DAT_0062c5ec != 0) {
        return (COMMSTATUS)4;
    }
    if (this->Multiplayer != 0) {
        return (COMMSTATUS)3;
    }
    return (COMMSTATUS)(2 + (this->Me - 1 ? -1 : 0));
}
