// 0042A540 TCommunications_Handler::TXAcknowledgeMessage
// Com_hand.cpp:3381-3438

#include "../../include/directplay4a_context.h"

typedef unsigned int uint;

#if !defined(COM_HAND_TU_CONTEXT)
class TDebuggingLog {
public:
    static void Log(TDebuggingLog* log, const char* format, ...);
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Comm_Error {
public:
    void ShowReturn(long result, const char* name);
};
#endif // COM_HAND_TU_CONTEXT


extern void* operator new(unsigned int size);
extern void operator delete(void* ptr);
#if !defined(COM_HAND_TU_CONTEXT)
extern unsigned long debug_timeGetTime(const char* file, int line);
#endif // COM_HAND_TU_CONTEXT
#if !defined(COM_HAND_TU_CONTEXT)
extern TDebuggingLog* L;
#endif // COM_HAND_TU_CONTEXT
#if !defined(COM_HAND_TU_CONTEXT)
extern unsigned int DAT_0062cf04;
#endif // COM_HAND_TU_CONTEXT
#if !defined(COM_HAND_TU_CONTEXT)
extern IDirectPlay4A* DAT_0062c5ec;
#endif // COM_HAND_TU_CONTEXT
extern const char s_Com_hand_cpp[];

#if !defined(COM_HAND_TU_CONTEXT)
struct COMMPLAYEROPTIONS {
    char gap_00[0x14];
    unsigned int dcoID[10];
};

class TCommunications_Handler {
public:
    char gap_0000[0x12C0];
    int TXPacketLength;              // +0x12C0
    char gap_12C4[0x14E0 - 0x12C4];
    RGE_Comm_Error* Err;             // +0x14E0
    char gap_14E4[0x1514 - 0x14E4];
    unsigned char RGE_Guaranteed_Delivery; // +0x1514
    char gap_1515[0x1550 - 0x1515];
    COMMPLAYEROPTIONS PlayerOptions; // dcoID at +0x1564

    int TXAcknowledgeMessage(uint param_1, uint param_2);
};
#endif // COM_HAND_TU_CONTEXT


int TCommunications_Handler::TXAcknowledgeMessage(uint param_1, uint param_2)
{
    if (this->RGE_Guaranteed_Delivery == 0) {
        TDebuggingLog::Log(L, "!RGEGTD Ack");
        return 0;
    }

    unsigned char* buf = (unsigned char*)operator new(8);
    buf[0] = 0x41;
    *(uint*)(buf + 4) = param_1;

    if (DAT_0062cf04 == 0) {
        TDebuggingLog::Log(L, "+++BAD DCOID=0 NO TX");
        return 0;
    }

    unsigned long start = debug_timeGetTime(s_Com_hand_cpp, 0xD53);

    unsigned int dco = this->PlayerOptions.dcoID[param_2];
    long result = DAT_0062c5ec->Send(DAT_0062cf04, dco, 0, buf, 8);

    unsigned long elapsed = debug_timeGetTime(s_Com_hand_cpp, 0xD5E) - start;
    if (elapsed > 0x32) {
        TDebuggingLog::Log(L, "!!!TXAcknowledgeMessage slow - %ld msec", elapsed);
    }

    this->TXPacketLength += 8;
    operator delete(buf);

    if (result == 0) {
        return 1;
    }

    this->Err->ShowReturn(result, "GTD ACK");
    return 0;
}

#if !defined(COM_HAND_TU_CONTEXT)
void TDebuggingLog::Log(TDebuggingLog* log, const char* format, ...) {}
#endif // COM_HAND_TU_CONTEXT
#if !defined(COM_HAND_TU_CONTEXT)
void RGE_Comm_Error::ShowReturn(long result, const char* name) {}
#endif // COM_HAND_TU_CONTEXT
