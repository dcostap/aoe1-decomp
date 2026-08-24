// tried the straight decompiler shape; first mismatch is still at the prolog/arg load
// narrowed the local to a 4-byte speed-change packet and kept the logging/send split
#include <stdlib.h>

#if !defined(COM_HAND_TU_CONTEXT)
class TDebuggingLog {
public:
    static void Log(void* log, const char* text, int value);
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    int OptionsChanged;
    char* OptionsData;
    int Steps;
    unsigned long TickStart;
    unsigned long TickCount;
    unsigned long TimeSinceLastCall;
    void* Chat;
    int MeHost;
    int HaveHostInit;
    char InCommBuff[4001];
    char TBuff[257];
    unsigned long current_turn;
    unsigned long next_command_turn;
    unsigned int sequence;
    long WaitOnPlayer;
    unsigned long TurnSpeedMsec;
    unsigned long AcknowledgeAfterMsec;
    unsigned int Me;
    int Multiplayer;

    long CommOut(unsigned char, unsigned long, void*, unsigned long, unsigned long);
    void SendSpeedChange(unsigned int, unsigned int);
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
extern void* L;
#endif // COM_HAND_TU_CONTEXT

void TCommunications_Handler::SendSpeedChange(unsigned int param_1, unsigned int param_2) {
    if (this->MeHost != 0 && this->Multiplayer != 0) {
        unsigned int speed_change;
        ((unsigned short *)&speed_change)[0] = (unsigned short)param_1;
        ((unsigned short *)&speed_change)[1] = (unsigned short)param_2;
        TDebuggingLog::Log(L, "  >TX KP SPD (%d)", 4);
        this->CommOut(0, 'S', &speed_change, 4, 0);
    }
}
