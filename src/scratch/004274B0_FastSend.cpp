// VA: 004274B0 TCommunications_Handler::FastSend
// First pass shaped directly from Com_hand.cpp packet.

#define E_FAIL ((long)0x80004005)
#define E_INVALIDARG ((long)0x80070057)
#define S_SEND_SELF ((const char*)0x5810C8)
#define S_BAD_DCOID ((const char*)0x5810B0)
#define S_SLOW_FASTSEND ((const char*)0x581094)
#define S_INVALIDARG ((const char*)0x581074)
#define S_FASTSEND_FAIL ((const char*)0x58106C)
#define S_COM_HAND_CPP ((const char*)0x580BF4)

extern unsigned long local_dcoid;
extern void* debug_log;
extern void* direct_play;

extern "C" void __cdecl debug_log_write(void* log, const char* msg);
extern "C" void __cdecl debug_log_write_int(void* log, const char* msg, int value);
#if !defined(COM_HAND_TU_CONTEXT)
extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
struct DirectPlayVtbl {
    char pad_00[0x68];
    long (__stdcall* Send)(void* self, unsigned long from, unsigned long to, unsigned long flags, void* data, unsigned long size);
};
#endif // COM_HAND_TU_CONTEXT

class ErrorLogger {
public:
    void log(long hr, const char* msg);
};

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char pad_00[0x10E0];
    int my_player;
    char pad_10E4[0x12C0 - 0x10E4];
    int bytes_sent;
    char pad_12C4[0x12D8 - 0x12C4];
    unsigned short num_players;
    char pad_12DA[0x14E0 - 0x12DA];
    ErrorLogger* error_logger;

    int player_connected(int player);
    long FastSend(unsigned long to, void* data, unsigned long size, int param_4, int param_5);
};
#endif // COM_HAND_TU_CONTEXT


long TCommunications_Handler::FastSend(unsigned long to, void* data, unsigned long size, int param_4, int param_5) {
    unsigned long start;
    long hr;
    unsigned long elapsed;
    int recipients;
    unsigned int i;

    if (to == local_dcoid) {
        debug_log_write(debug_log, S_SEND_SELF);
        return E_FAIL;
    }
    if (local_dcoid == 0) {
        debug_log_write(debug_log, S_BAD_DCOID);
        return E_FAIL;
    }

    start = debug_timeGetTime(S_COM_HAND_CPP, 0x4CA);
    hr = ((DirectPlayVtbl*)*(void**)direct_play)->Send(direct_play, local_dcoid, to, 0, data, size);
    elapsed = debug_timeGetTime(S_COM_HAND_CPP, 0x4D3) - start;
    if (elapsed > 0x32) {
        debug_log_write_int(debug_log, S_SLOW_FASTSEND, elapsed);
    }

    recipients = (int)to;
    if (recipients == 0) {
        recipients = 0;
        for (i = 1; i <= num_players; ++i) {
            if (player_connected(i) != 0 && i != my_player) {
                ++recipients;
            }
        }
    } else {
        recipients = 1;
    }

    bytes_sent += recipients * size;

    if (hr == E_INVALIDARG) {
        debug_log_write(debug_log, S_INVALIDARG);
        return hr;
    }
    if (hr != 0) {
        error_logger->log(hr, S_FASTSEND_FAIL);
    }
    return hr;
}
