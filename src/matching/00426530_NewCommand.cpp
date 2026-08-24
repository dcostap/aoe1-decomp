// VA: 00426530 TCommunications_Handler::NewCommand
// Com_hand.cpp:467-493

#include "../../include/com_hand_context.h"

#if 0
void Log(void* log, const char* format, ...);

#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Communications_Queue {
public:
    unsigned char GetNextSequence(unsigned long value);
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Comm_Error {
public:
    void ShowReturn(long code, const char* context);
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x10C8];
    unsigned long current_turn;           // +0x10C8
    char gap_10CC[0x14];                  // +0x10CC..+0x10DF
    int Me;                               // +0x10E0
    int Multiplayer;                      // +0x10E4
    char gap_10E8[0x3DC];                 // +0x10E8..+0x14C3
    RGE_Communications_Queue* InQ;        // +0x14C4
    char gap_14C8[0x18];                  // +0x14C8..+0x14DF
    RGE_Comm_Error* Err;                  // +0x14E0
    char gap_14E4[0xAC];                  // +0x14E4..+0x158F
    unsigned char commandTurnIncrement;   // +0x1590

    long CommOut(unsigned char a, unsigned long b, void* c, unsigned long d, unsigned long e);
    int AddCommand(int a, int b, int c, int d, unsigned char e, int f);
    int NewCommand(void* command, int size, int ordered);
};
#endif // COM_HAND_TU_CONTEXT

#endif

int TCommunications_Handler::NewCommand(void* command, int size, int ordered) {
    if (this->Multiplayer != 0) {
        Log(*(void**)0x62C4FC, "  >TX CMD (%d) Cmd=%d ", size, (int)*(unsigned char*)command);
        long _r = this->CommOut(0, 0x3E, command, size, 0);
        this->Err->ShowReturn(_r, "NewCmnd");
    } else {
        int _t = this->current_turn + this->PlayerOptions.CommandTurnIncrement;
        this->AddCommand(_t, (int)command, size, this->Me, this->InQ->GetNextSequence(this->current_turn), ordered);
    }
    return 1;
}
