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
// session: making packet counters/last counters unsigned long recovered the original
// qword FPU conversions, exact frame/size, and most block topology; direct elapsed
// arithmetic is the clean surviving reconstruction. Captured dplay-id and named
// debug-byte variants were codegen-worse; the remaining drift is debug-flag register
// order plus wait-output initialization scheduling.
// fresh pass baseline: restored the current validated source and confirmed the 285-byte
// mismatch with the named-byte and cached-wait variants absent.
// fresh probe: separate debug-byte mask/temp duplicated the old AL basin; rolled back.
// fresh probe: widened debug flag to int worsened size and liveness; rolled back.
// fresh probe: named DAT_0062c5d0 extern changed the byte register to oracle CL and
// recovered the rate and control-flow blocks; retained this natural declaration surface.
// fresh probes: cached dplay id, changed wait-count declaration/zero spellings, and
// restored direct initialized output; only the id cache improved, while assignment order
// stayed unchanged. Cached both id and interface so VC5 emits oracle object-load, LEA,
// pushes, and vtable load order. Exact match: 409/409 bytes, 10/10 calls, default flags.
// Exact validated source remains in scratch for the parent to promote. The named byte
// global and cached DirectPlay id/interface are period-plausible declaration and lifetime
// surfaces, not compiler-only scaffolding.

typedef unsigned long ulong;

#if !defined(COM_HAND_TU_CONTEXT)
extern ulong __cdecl debug_timeGetTime(char* file, int line);
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class TDebuggingLog { public: void Log(char* fmt, ...); };
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Comm_Error { public: void ShowReturn(long result, char* msg); };
#endif // COM_HAND_TU_CONTEXT

class IDirectPlay4A;

extern unsigned char DAT_0062c5d0;
#define debug_once DAT_0062c5d0
#if !defined(COM_HAND_TU_CONTEXT)
extern ulong DAT_0062cef0;
#endif // COM_HAND_TU_CONTEXT
#if !defined(COM_HAND_TU_CONTEXT)
extern ulong DAT_0062cf14;
#endif // COM_HAND_TU_CONTEXT
#if !defined(COM_HAND_TU_CONTEXT)
extern ulong DAT_0062cf18;
#endif // COM_HAND_TU_CONTEXT
#if !defined(COM_HAND_TU_CONTEXT)
extern unsigned int DAT_0062cf04;
#endif // COM_HAND_TU_CONTEXT
#if !defined(COM_HAND_TU_CONTEXT)
extern IDirectPlay4A* DAT_0062c5ec;
#endif // COM_HAND_TU_CONTEXT
#if !defined(COM_HAND_TU_CONTEXT)
extern TDebuggingLog* L;
#endif // COM_HAND_TU_CONTEXT
#define last_time DAT_0062cef0
#define last_rx DAT_0062cf14
#define last_tx DAT_0062cf18
#define dplay_id DAT_0062cf04
#define dplay DAT_0062c5ec
#define log_obj L

#if !defined(COM_HAND_TU_CONTEXT)
class IDirectPlay4A {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40();
    virtual long __stdcall v44(int id, int* out);
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_0000[0x10E4];
    int Multiplayer;
    char gap_10E8[0x10F0 - 0x10E8];
    float lastRXDataRate;
    float lastTXDataRate;
    char gap_10F8[0x12B8 - 0x10F8];
    ulong RXPacketLength;
    char gap_12BC[0x12C0 - 0x12BC];
    ulong TXPacketLength;
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
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::ReceiveGameMessages()
{
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
        this->lastTXDataRate = ((float)(this->TXPacketLength - last_tx) * 1000.0f) / (float)elapsed;
        this->lastRXDataRate = ((float)(this->RXPacketLength - last_rx) * 1000.0f) / (float)elapsed;
        last_time = now;
        last_tx = this->TXPacketLength;
        last_rx = this->RXPacketLength;
    }

    if (this->RGE_Guaranteed_Delivery != 0) {
        this->ExecuteIncoming();
    }

    unsigned long current_dplay_id = dplay_id;
    if (current_dplay_id != 0) {
        IDirectPlay4A* current_dplay = dplay;
        unsigned long wait_count = zero;
        long result = current_dplay->GetMessageCount(current_dplay_id,
                                                      &wait_count);
        if (result != zero) {
            this->Err->ShowReturn(result, (char*)"MsgWait");
            goto after_dplay;
        }
        if (wait_count == zero) {
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
