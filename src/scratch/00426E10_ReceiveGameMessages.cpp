// VA: 00426E10 TCommunications_Handler::ReceiveGameMessages
// Source: Com_hand.cpp lines 912-952
// Attempt log:
// 1: initial reconstruction from packet/decompiler; wrong frame (0x10) and FPU conversion shape.
// 2: explicit __int64 casts worsened EBX/liveness and FPU shape.
// 3: zero/double local no codegen change.
// 4: __int64 local_8 worsened dplay stack shape.
// 5: restore array and use direct zero constants.
// 6: restore qword local_8 rate math (best edit diff).
// 7: volatile local_8 worsened frame/scheduling; rolled back.
// 8: named elapsed_float from qword local improved FPU but still frame/register drift.
// 9: zero local no codegen change.
// 10: mark COM v44 as __stdcall to match pushed-this virtual call.
// 11: explicit flag/bit locals worsened liveness; rolled back.
// 12: /Og and /Ob0 flag probes no change; removed flags.
// Left in scratch: behavior modeled, but frame is 0x0C vs original 0x08 and FPU rate-math/dplay wait register topology remain broad.

typedef unsigned long ulong;

extern ulong __cdecl debug_timeGetTime(char* file, int line);

class TDebuggingLog { public: void Log(char* fmt, ...); };
class RGE_Comm_Error { public: void ShowReturn(long result, char* msg); };
class IDirectPlay4A;

#define debug_once (*(unsigned char*)0x0062C5D0)
#define last_time (*(ulong*)0x0062CEF0)
#define last_rx (*(int*)0x0062CF14)
#define last_tx (*(int*)0x0062CF18)
#define dplay_id (*(int*)0x0062CF04)
#define dplay (*(IDirectPlay4A**)0x0062C5EC)
#define log_obj (*(TDebuggingLog**)0x0062C4FC)

class IDirectPlay4A {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40();
    virtual long __stdcall v44(int id, int* out);
};

class TCommunications_Handler {
public:
    char gap_0000[0x10E4];
    int Multiplayer;
    char gap_10E8[0x10F0 - 0x10E8];
    float lastRXDataRate;
    float lastTXDataRate;
    char gap_10F8[0x12B8 - 0x10F8];
    int RXPacketLength;
    char gap_12BC[0x12C0 - 0x12BC];
    int TXPacketLength;
    char gap_12C4[0x14E0 - 0x12C4];
    RGE_Comm_Error* Err;
    char gap_14E4[0x1514 - 0x14E4];
    unsigned char RGE_Guaranteed_Delivery;

    unsigned int ExecuteIncoming();
    void GetDPLAYMessages();
    int SendStoredMessages();
    void CheckPingTime(int arg);
    void ReceiveGameMessages();
};

void TCommunications_Handler::ReceiveGameMessages()
{
    unsigned int local_8[2];
    int zero = 0;

    if (this->Multiplayer == zero) {
        return;
    }

    if ((debug_once & 1) == 0) {
        debug_once = (unsigned char)(debug_once | 1);
        last_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x396);
    }

    ulong now = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 0x397);
    unsigned int elapsed = now - last_time;
    if (elapsed > 1000) {
        log_obj->Log((char*)"TX: %ld  RX: %ld  elapsed: %ld  totTX: %ld  totRX: %ld",
                     this->TXPacketLength - last_tx,
                     this->RXPacketLength - last_rx,
                     elapsed,
                     this->TXPacketLength,
                     this->RXPacketLength);
        local_8[0] = elapsed;
        local_8[1] = zero;
        float elapsed_float = (float)*(__int64*)local_8;
        this->lastTXDataRate = ((float)(this->TXPacketLength - last_tx) * 1000.0f) / elapsed_float;
        local_8[0] = this->RXPacketLength - last_rx;
        local_8[1] = zero;
        this->lastRXDataRate = ((float)*(__int64*)local_8 * 1000.0f) / elapsed_float;
        last_time = now;
        last_tx = this->TXPacketLength;
        last_rx = this->RXPacketLength;
    }

    if (this->RGE_Guaranteed_Delivery != 0) {
        this->ExecuteIncoming();
    }

    if (dplay_id != 0) {
        local_8[0] = 0;
        long result = dplay->v44(dplay_id, (int*)local_8);
        if (result != zero) {
            this->Err->ShowReturn(result, (char*)"MsgWait");
            goto after_dplay;
        }
        if (local_8[0] == zero) {
            goto after_dplay;
        }
    }

    this->GetDPLAYMessages();
    if (this->RGE_Guaranteed_Delivery != 0) {
        this->ExecuteIncoming();
    }

after_dplay:
    if (this->RGE_Guaranteed_Delivery != 0) {
        this->SendStoredMessages();
    }
    this->CheckPingTime(zero);
}
