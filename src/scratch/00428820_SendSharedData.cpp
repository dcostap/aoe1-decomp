// VA: 00428820 TCommunications_Handler::SendSharedData
// PDB: Com_hand.cpp:2185-2273
// attempt 1: reconstruct from original asm: host/DP guards, debug_time throttle,
// packet allocation/copy/send/free, clear sent flags.

#include <string.h>
#include <stdlib.h>

extern unsigned int DAT_0062c5ec; // DirectPlay interface
extern unsigned int DAT_0062cf04; // self DPID
extern void* L;

extern unsigned long __cdecl debug_timeGetTime(const char* file, int line);
extern void __cdecl Log(void* log, const char* fmt, ...);
extern void* __cdecl malloc(unsigned int size);
extern void __cdecl free(void* ptr);

class RGE_Comm_Error {
public:
    void ShowReturn(long hr, const char* msg);
};

class DirectPlayLike {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual long __stdcall Send(unsigned int from, void* data, unsigned int size, unsigned int flags); // +0x70? placeholder
    virtual long __stdcall SendEx(unsigned int from, void* data, unsigned int size, unsigned int flags); // +0x74
};

struct SharedDataPacketPrefix {
    char bytes[0x1D0];
};

class TCommunications_Handler {
public:
    char gap_00[0x04];
    char* OptionsData;                 // +0x04
    char gap_08[0x1C - 0x08];
    int MeHost;                        // +0x1C
    char gap_20[0x12D8 - 0x20];
    unsigned short MaxGamePlayers;     // +0x12D8
    char gap_12DA[0x14E0 - 0x12DA];
    RGE_Comm_Error* CommError;         // +0x14E0
    char gap_14E4[0x1550 - 0x14E4];
    unsigned char NeedsToBeSent;       // +0x1550
    char packet_1551[0x1554 - 0x1551];
    unsigned long LastSharedDataSendTime; // +0x1554
    char packet_after_1558[0x16FC - 0x1558];
    unsigned char SentFlag[0x20];      // +0x16FC, indexed 1..MaxGamePlayers
    unsigned int DataSizeToFollow;     // +0x171C

    void NotifyWindow(int msg);
    long SendSharedData(int force);
};

long TCommunications_Handler::SendSharedData(int force)
{
    if (DAT_0062c5ec == 0) {
        return 0;
    }
    if (this->MeHost == 0) {
        return 0;
    }

    unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x895);

    if (force != 0) {
        this->NeedsToBeSent = 1;
    } else {
        if (now - this->LastSharedDataSendTime < 2000) {
            return 0;
        }
    }

    if (this->NeedsToBeSent == 0) {
        return 0;
    }

    if (DAT_0062cf04 == 0) {
        Log(L, "No DCOID for Send Shared Data");
        return 0x80004005;
    }

    Log(L, "Sending Shared Data");

    unsigned int packet_size = this->DataSizeToFollow + 0x1D0;
    this->LastSharedDataSendTime = now;
    char* packet = (char*)malloc(packet_size);

    *(SharedDataPacketPrefix*)packet = *(SharedDataPacketPrefix*)&this->NeedsToBeSent;
    memcpy(packet + 0x1D0, this->OptionsData, this->DataSizeToFollow);

    long hr = ((DirectPlayLike*)DAT_0062c5ec)->SendEx(DAT_0062cf04, packet, packet_size, 2);
    this->CommError->ShowReturn(hr, "Send Shared Data");
    free(packet);

    this->NeedsToBeSent = 0;
    this->NotifyWindow(0x17BB);

    unsigned int i = 1;
    if (this->MaxGamePlayers >= 1) {
        do {
            this->SentFlag[i] = 0;
            i++;
        } while (i <= this->MaxGamePlayers);
    }

    return hr;
}
