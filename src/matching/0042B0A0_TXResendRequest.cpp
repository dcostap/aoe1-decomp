// 0042B0A0 TCommunications_Handler::TXResendRequest (Com_hand.cpp:3956-4039, 348B)
// Attempt log:
//   baseline: natural resend-request throttling, allocation, logging, DirectPlay send,
//     timing, cleanup, and TX byte accounting; size/frame/call set already matched but
//     string/global relocation identities and the final vtable setup were wrong (122B).
//   ABI: replaced the fake Sender global/vtable with the DirectPlay object at 62C5EC,
//     its __stdcall Send slot +0x68, DAT_0062CF04, and the canonical Com_hand.cpp string;
//     this recovered all 348 bytes and 23/23 relocation identities.
//   context: restored PlayerOptions.dcoID ownership at +0x1550+0x14; codegen unchanged.
//   flags: removed the redundant per-function response file; default /O2 /Oy remains exact.
// Exact result: 348/348 bytes, 10/10 ordered calls, default flags.

unsigned long debug_timeGetTime(const char* file, int line);
void* operator new(unsigned int);
void operator delete(void*);

class TDebuggingLog { public: void Log(char* fmt, ...); };
extern TDebuggingLog* L;
extern const char s_Com_hand_cpp[];
extern unsigned int DAT_0062cf04;

struct IUnknown {
    virtual long __stdcall QueryInterface(void*, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct IDirectPlay3 : IUnknown {
    virtual long __stdcall AddPlayerToGroup() = 0;
    virtual long __stdcall Close() = 0;
    virtual long __stdcall CreateGroup() = 0;
    virtual long __stdcall CreatePlayer() = 0;
    virtual long __stdcall DeletePlayerFromGroup() = 0;
    virtual long __stdcall DestroyGroup() = 0;
    virtual long __stdcall DestroyPlayer() = 0;
    virtual long __stdcall EnumGroupPlayers() = 0;
    virtual long __stdcall EnumGroups() = 0;
    virtual long __stdcall EnumPlayers() = 0;
    virtual long __stdcall EnumSessions() = 0;
    virtual long __stdcall GetCaps() = 0;
    virtual long __stdcall GetGroupData() = 0;
    virtual long __stdcall GetGroupName() = 0;
    virtual long __stdcall GetMessageCount() = 0;
    virtual long __stdcall GetPlayerAddress() = 0;
    virtual long __stdcall GetPlayerCaps() = 0;
    virtual long __stdcall GetPlayerData() = 0;
    virtual long __stdcall GetPlayerName() = 0;
    virtual long __stdcall GetSessionDesc() = 0;
    virtual long __stdcall Initialize() = 0;
    virtual long __stdcall Open() = 0;
    virtual long __stdcall Receive() = 0;
    virtual int __stdcall Send(unsigned int from, unsigned int to,
                               int flags, void* msg, unsigned int size) = 0;
};

extern IDirectPlay3* DAT_0062c5ec;

struct COMMPLAYEROPTIONS {
    char gap_00[0x14];
    unsigned int dcoID[10];       // +0x14
};

class TCommunications_Handler {
public:
    char gap_0000[0x12C0];
    int TXPacketLength;
    char gap_12C4[0x13E4-0x12C4];
    unsigned int LastSerialRequestedTX[10];
    unsigned int LastRequestHonoredTX[10];
    char gap_1434[0x1514-0x1434];
    unsigned char RGE_Guaranteed_Delivery;
    char gap_1515[0x1550-0x1515];
    COMMPLAYEROPTIONS PlayerOptions;
    int TXResendRequest(unsigned int serial, unsigned int player);
};

int TCommunications_Handler::TXResendRequest(unsigned int serial, unsigned int player) {
    if (!this->RGE_Guaranteed_Delivery) {
        return 0;
    }
    unsigned long now = debug_timeGetTime(s_Com_hand_cpp, 3980);
    if (serial == this->LastSerialRequestedTX[player]) {
        unsigned long elapsed = now - this->LastRequestHonoredTX[player];
        if (elapsed < 500) {
            return 0;
        }
    }
    this->LastSerialRequestedTX[player] = serial;
    this->LastRequestHonoredTX[player] = now;
    char* msg = (char*)operator new(8);
    msg[0] = 0x58;
    *(unsigned int*)(msg + 4) = serial;
    L->Log("GTD: TX RESEND REQ to P#%d  Ser#%d ", player, serial);
    if (DAT_0062cf04 == 0) {
        L->Log("+++BAD DCOID=0 NO TX");
        return 0;
    }
    unsigned long sendStart = debug_timeGetTime(s_Com_hand_cpp, 4009);
    L->Log("  >TX RES REQ #%d %d (%d)", player, serial, 8);
    int to = this->PlayerOptions.dcoID[player];
    IDirectPlay3* dp = DAT_0062c5ec;
    int ok = dp->Send(DAT_0062cf04, to, 0, msg, 8);
    unsigned long elapsed2 = debug_timeGetTime(s_Com_hand_cpp, 4024) - sendStart;
    if (elapsed2 > 50) {
        L->Log("  TX RES REQ took %d", elapsed2);
    }
    operator delete(msg);
    if (ok == 0) {
        this->TXPacketLength += 8;
        return 1;
    }
    return 0;
}
