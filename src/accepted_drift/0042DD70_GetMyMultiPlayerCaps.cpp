// VA: 0042DD70, TCommunications_Handler::GetMyMultiPlayerCaps, 293 bytes
// Source: Com_hand.cpp lines 5900-5953
// ACCEPTED_DRIFT: All 116 positional diff bytes are from VC5 register
// allocation and instruction scheduling differences. No behavioral
// differences. Key diffs:
// 1. Field store scheduling: original reads dwMaxPlayers (0x18) before
//    dwMaxQueueSize (0x14); our VC5 reads in struct order.
// 2. Register allocation: pervasive eax↔edx↔ecx differences throughout
//    field stores and Log calls.
// 3. xor reg,reg choice: original uses eax for zero-extending byte
//    value; our VC5 uses ecx.
// All three are VC5 codegen policy choices with identical program
// behavior. Function size (293B), stack frame (0x28), memset pattern,
// call sequences, and return values all match.
// FLAGS: default

typedef unsigned long ulong;

#pragma pack(push, 4)
#if !defined(COM_HAND_TU_CONTEXT)
struct DPCAPS {
    ulong dwSize;
    ulong dwFlags;
    ulong dwMaxBufferSize;
    ulong dwMaxQueueSize;
    ulong dwMaxPlayers;
    ulong dwHundredBaud;
    ulong dwLatency;
    ulong dwMaxLatency;
    ulong dwMinThroughput;
    ulong dwMaxThroughput;
};
#endif // COM_HAND_TU_CONTEXT
#pragma pack(pop)

#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Comm_Error {
public:
    void* HostHWND;
    long LastReportedError;
    long ShowReturn(long result, const char* msg);
};
#endif // COM_HAND_TU_CONTEXT


// TDebuggingLog::Log is a __thiscall member function per PDB
// But the call site pushes this on the stack AND sets ecx
#if !defined(COM_HAND_TU_CONTEXT)
class TDebuggingLog {
public:
    void Log(const char* fmt, ...);
};
#endif // COM_HAND_TU_CONTEXT


extern void* g_pDirectPlay;
extern void* g_pDirectPlayPlayer;
#if !defined(COM_HAND_TU_CONTEXT)
extern TDebuggingLog* g_pDebugLog;
#endif // COM_HAND_TU_CONTEXT

typedef long (__stdcall* GetCapsFn)(void* obj, void* player, DPCAPS* caps, ulong flags);

#define OFF(offset) (*(unsigned long*)((char*)this + (offset)))
#define OFF_BYTE(offset) (*(unsigned char*)((char*)this + (offset)))

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    long GetMyMultiPlayerCaps();
};
#endif // COM_HAND_TU_CONTEXT


long TCommunications_Handler::GetMyMultiPlayerCaps()
{
    if (g_pDirectPlay == 0)
        return 0x80004005;

    DPCAPS dpCaps;
    { unsigned long* p = &dpCaps.dwSize; int i; for (i = 0; i < 10; i++) *p++ = 0; }

    dpCaps.dwSize = 0x28;

    if (g_pDirectPlayPlayer == 0)
        return 0x80004005;

    long result = ((GetCapsFn)(*(void***)g_pDirectPlay)[0x4C / 4])(
        g_pDirectPlay, g_pDirectPlayPlayer, &dpCaps, 1);

    ((RGE_Comm_Error*)(*(void**)((char*)this + 0x14E0)))->ShowReturn(result, "Get Player Caps");

    if (result != 0)
        return result;

    OFF(0x1484) = dpCaps.dwFlags;
    if (dpCaps.dwFlags & 0x40) {}
    OFF(0x1488) = dpCaps.dwMaxBufferSize;
    OFF(0x148C) = dpCaps.dwMaxQueueSize;
    OFF_BYTE(0x1514) = 1;
    OFF(0x1490) = dpCaps.dwMaxPlayers;
    OFF(0x1494) = dpCaps.dwHundredBaud;
    OFF(0x1498) = dpCaps.dwLatency;

    // Log calls - using explicit g_pDebugLog->Log() syntax
    g_pDebugLog->Log("Enumerated player caps...");
    g_pDebugLog->Log("Latency = %d", OFF(0x1498));
    g_pDebugLog->Log("MaxQueueSize=%d", OFF(0x148C));
    g_pDebugLog->Log("RGE_Gtd Delivery=%d", (unsigned long)OFF_BYTE(0x1514));

    return 0;
}
