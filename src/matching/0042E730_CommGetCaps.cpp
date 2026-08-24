// 0042E730 TCommunications_Handler::CommGetCaps
// PDB: Com_hand.cpp:6372-6464, 484 bytes
// Attempt log:
// - v1: reconstructed DirectPlay GetCaps calls, logging, flags checks, and handler field stores from packet.
// - v2: corrected DPCAPS local size to 0x28 bytes.
// - v3: introduced vtbl local before dwSize store to probe original load-before-store call setup.
// - v4: corrected DPCAPS field order: dwMaxLocalPlayers precedes header length/timeout.

typedef unsigned long DWORD;
typedef long HRESULT;

#if !defined(COM_HAND_TU_CONTEXT)
struct DPCAPS {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwMaxBufferSize;
    DWORD dwMaxQueueSize;
    DWORD dwMaxPlayers;
    DWORD dwHundredBaud;
    DWORD dwLatency;
    DWORD dwMaxLocalPlayers;
    DWORD dwHeaderLength;
    DWORD dwTimeout;
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
struct IDirectPlay3 {
    void** vtbl;
};
#endif // COM_HAND_TU_CONTEXT


typedef HRESULT (__stdcall *GetCapsProc)(IDirectPlay3* self, DPCAPS* caps, DWORD flags);

#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Comm_Error {
public:
    void ShowReturn(HRESULT hr, char* text);
};
#endif // COM_HAND_TU_CONTEXT


class TDebuggingLog;
#if !defined(COM_HAND_TU_CONTEXT)
void __cdecl Log(TDebuggingLog* log, char* text, ...);
#endif // COM_HAND_TU_CONTEXT

extern IDirectPlay3* g_pDP;
#if !defined(COM_HAND_TU_CONTEXT)
extern TDebuggingLog* L;
#endif // COM_HAND_TU_CONTEXT

static char s_get_caps[] = "Get Caps";
static char s_get_guaranteed_caps[] = "Get guaranteed Caps";
static char s_header[] = "-----------Direct Play III Capabilities -----------";
static char s_max_buffer[] = "Max Buffer Size = %d";
static char s_max_queue[] = "Max Queue Size  = %d";
static char s_max_players[] = "Max Players     = %d";
static char s_baud[] = "Baud Rate       = %d00";
static char s_latency[] = "Latency         = %d";
static char s_header_len[] = "Header Length   = %d";
static char s_timeout[] = "Timeout         = %d";
static char s_guar_opt[] = "Guaranteed Optimized.";
static char s_not_guar_opt[] = "NOT Guaranteed Optimized.";
static char s_session_host_msg[] = "This player is the Session Host.";
static char s_not_session_host_msg[] = "Not the host.";
static char s_keepalive[] = "Optimized keepalive detection.";
static char s_not_keepalive[] = "Not optimized for keepalive.";
static char s_guar_delivery[] = "Guaranteed delivery is Supported";
static char s_not_guar_service[] = "NOT Guaranteed Service!";

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_0000[0x1340];
    int ServiceTimeout;
    char gap_1344[0x14e0 - 0x1344];
    RGE_Comm_Error* Err;
    char gap_14e4[0x1514 - 0x14e4];
    unsigned char RGE_Guaranteed_Delivery;

    HRESULT CommGetCaps();
};
#endif // COM_HAND_TU_CONTEXT


HRESULT TCommunications_Handler::CommGetCaps()
{
    DPCAPS caps;
    HRESULT hr;

    IDirectPlay3* dp = g_pDP;
    if (dp == 0) {
        return 0x80004005;
    }

    void** vtbl = *(void***)dp;
    caps.dwSize = sizeof(DPCAPS);
    hr = ((GetCapsProc)vtbl[14])(dp, &caps, 0);
    this->Err->ShowReturn(hr, s_get_caps);

    dp = g_pDP;
    hr = ((GetCapsProc)(*(void***)dp)[14])(dp, &caps, 1);
    this->Err->ShowReturn(hr, s_get_guaranteed_caps);

    Log(L, s_header);
    Log(L, s_max_buffer, caps.dwMaxBufferSize);
    Log(L, s_max_queue, caps.dwMaxQueueSize);
    Log(L, s_max_players, caps.dwMaxPlayers);
    Log(L, s_baud, caps.dwHundredBaud);
    Log(L, s_latency, caps.dwLatency);
    Log(L, s_header_len, caps.dwHeaderLength);
    Log(L, s_timeout, caps.dwTimeout);

    this->ServiceTimeout = caps.dwTimeout;

    if (caps.dwFlags & 0x20) {
        Log(L, s_guar_opt);
    } else {
        Log(L, s_not_guar_opt);
    }

    if (caps.dwFlags & 2) {
        Log(L, s_session_host_msg);
    } else {
        Log(L, s_not_session_host_msg);
    }

    if (caps.dwFlags & 0x10) {
        Log(L, s_keepalive);
    } else {
        Log(L, s_not_keepalive);
    }

    if (caps.dwFlags & 0x40) {
        Log(L, s_guar_delivery);
    } else {
        Log(L, s_not_guar_service);
    }

    this->RGE_Guaranteed_Delivery = 1;
    return hr;
}
