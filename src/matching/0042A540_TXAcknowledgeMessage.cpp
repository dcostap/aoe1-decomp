// 0042A540 TCommunications_Handler::TXAcknowledgeMessage
// Com_hand.cpp:3381-3438

typedef unsigned int uint;

class TDebuggingLog {
public:
    static void Log(TDebuggingLog* log, const char* format, ...);
};

class RGE_Comm_Error {
public:
    void ShowReturn(long result, const char* name);
};

struct IDirectPlayLike {
    void* vtbl;
};

extern void* operator new(unsigned int size);
extern void operator delete(void* ptr);
extern unsigned long debug_timeGetTime(const char* file, int line);
extern TDebuggingLog* L;
extern unsigned int DAT_0062cf04;
extern IDirectPlayLike* DAT_0062c5ec;
extern const char s_Com_hand_cpp[];

class TCommunications_Handler {
public:
    char gap_0000[0x12C0];
    int TXPacketLength;              // +0x12C0
    char gap_12C4[0x14E0 - 0x12C4];
    RGE_Comm_Error* Err;             // +0x14E0
    char gap_14E4[0x1514 - 0x14E4];
    unsigned char RGE_Guaranteed_Delivery; // +0x1514
    char gap_1515[0x1564 - 0x1515];
    unsigned int dcoID[1];           // +0x1564

    int TXAcknowledgeMessage(uint param_1, uint param_2);
};

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

    unsigned int dco = this->dcoID[param_2];
    long result = (*(long (__stdcall **)(IDirectPlayLike*, unsigned int, unsigned int, int, void*, int))((char*)DAT_0062c5ec->vtbl + 0x68))(
        DAT_0062c5ec, DAT_0062cf04, dco, 0, buf, 8);

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

void TDebuggingLog::Log(TDebuggingLog* log, const char* format, ...) {}
void RGE_Comm_Error::ShowReturn(long result, const char* name) {}
