// VA: 0042E380 TCommunications_Handler::SetMyReadiness
// Source: Com_hand.cpp lines 6191-6258
// Attempt log:
// 1: natural raw-offset reconstruction with MSGFORMAT_SETREADYOPTIONS local; frame was 0x24 because packet has extra byte at +0x24.
// 2: add trailing guaranteed-delivery byte/pad to force 0x28 local frame; only rdy field scheduling drift remains.
// 3: reorder packet field assignments and name MeHost temp to match original store/load schedule; remaining 20-byte diff is localized packet-store scheduling/register allocation.
// 4: tried moving User7 assignment after User1; worsened to 49-byte diff, rolled back.
// ACCEPTED_DRIFT: reviewed localized packet-fill scheduling/register-allocation drift only.
// Calls, frame size, packet size, stack cleanup, field offsets, packet offsets, return value, and memory effects match;
// remaining byte differences are equivalent store order/register choices while filling independent rdy fields.

typedef unsigned long ulong;

class TDebuggingLog {
public:
    void Log(const char* fmt, ...);
};

#define L (*(TDebuggingLog**)0x0062C4FC)
#define STR_SET_MY_READINESS ((const char*)0x00582CDC)
#define STR_TX_RDY           ((const char*)0x00582CCC)

#pragma pack(push, 1)
struct MSGFORMAT_SETREADYOPTIONS {
    unsigned char User1;
    unsigned char Ready;
    unsigned char pad_02[2];
    ulong User2;
    ulong User3;
    ulong User4;
    ulong User5;
    ulong User6;
    ulong User7;
    ulong CommunicationsVersionCode;
    ulong RGEGuaranteed;
    unsigned char GuaranteedDeliveryByte;
    unsigned char pad_25[3];
};
#pragma pack(pop)

class TCommunications_Handler {
public:
    int FastSend(int p1, void* data, int size, int p4, int p5);
    void NotifyWindow(int msg);
    int SetMyReadiness(int ready, ulong user1, ulong user2, ulong user3, ulong user4, ulong user5, ulong user6, ulong user7);
};

#define FIELD_DWORD(off) (*(ulong*)((char*)this + (off)))
#define FIELD_BYTE(off) (*(unsigned char*)((char*)this + (off)))
#define ARR(base, idx) (*(ulong*)((char*)this + (base) + (idx) * 4))

int TCommunications_Handler::SetMyReadiness(int ready, ulong user1, ulong user2, ulong user3, ulong user4, ulong user5, ulong user6, ulong user7)
{
    MSGFORMAT_SETREADYOPTIONS rdy;

    int me = FIELD_DWORD(0x10E0);
    L->Log(STR_SET_MY_READINESS,
           me,
           ARR(0x1594, me),
           ARR(0x15BC, me),
           ARR(0x15E4, me),
           ARR(0x160C, me),
           ARR(0x1634, me),
           ARR(0x165C, me),
           ARR(0x1684, me),
           ARR(0x16AC, me));

    ARR(0x1594, FIELD_DWORD(0x10E0)) = ready;
    ARR(0x15BC, FIELD_DWORD(0x10E0)) = user1;
    ARR(0x15E4, FIELD_DWORD(0x10E0)) = user2;
    ARR(0x160C, FIELD_DWORD(0x10E0)) = user3;
    ARR(0x1634, FIELD_DWORD(0x10E0)) = user4;
    ARR(0x165C, FIELD_DWORD(0x10E0)) = user5;
    ARR(0x1684, FIELD_DWORD(0x10E0)) = user6;
    ARR(0x16AC, FIELD_DWORD(0x10E0)) = user7;

    rdy.Ready = (unsigned char)ready;
    rdy.User2 = user1;
    rdy.User5 = user4;
    rdy.User3 = user2;
    rdy.RGEGuaranteed = FIELD_DWORD(0x12A4);
    rdy.User6 = user5;
    rdy.User4 = user3;
    int meHost = FIELD_DWORD(0x1C);
    rdy.User7 = user6;
    rdy.CommunicationsVersionCode = user7;
    rdy.GuaranteedDeliveryByte = FIELD_BYTE(0x1514);
    rdy.User1 = 0x52;

    if (meHost == 0) {
        L->Log(STR_TX_RDY, 0x28);
        this->FastSend(0, &rdy.User1, 0x28, 0, 0);
    }

    this->NotifyWindow(0x17A6);
    return 1;
}
