struct MSGFORMAT_CHECKSUM {
    unsigned long WorldTime;      // +0x00
    unsigned long WorldTurn;      // +0x04
    unsigned int Random;          // +0x08
    long cs1;                     // +0x0C
    long cs2;                     // +0x10
    long cs3;                     // +0x14
    long cs4;                     // +0x18
    long cs5;                     // +0x1C
    unsigned long PingInitiated;  // +0x20
};

#if !defined(COM_HAND_TU_CONTEXT)
class TDebuggingLog {
public:
    static void Log(TDebuggingLog* log, const char* format, int size);
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Comm_Error {
public:
    void ShowReturn(long result, const char* name);
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x10C8];
    unsigned int current_turn;   // +0x10C8
    char gap_10CC[0x414];        // +0x10CC to +0x14DF
    class RGE_Comm_Error* Err;   // +0x14E0

    long CommOut(long a, long b, void* buf, long size, long flags);

    long SendChecksumMessage(unsigned long param_1, unsigned int param_2,
                             long param_3, long param_4, long param_5,
                             long param_6, long param_7);
};
#endif // COM_HAND_TU_CONTEXT


// Constants from EXE
#if !defined(COM_HAND_TU_CONTEXT)
extern unsigned long debug_timeGetTime(const char* file, int line);
#endif // COM_HAND_TU_CONTEXT

// Pointer to the global debug log (at 0x62C4FCh)
#if !defined(COM_HAND_TU_CONTEXT)
extern TDebuggingLog* L;
#endif // COM_HAND_TU_CONTEXT

// String constants from the EXE binary
extern const char s_Com_hand_cpp[];
extern const char s_TX_CKSUM[];
extern const char s_SendChecksum[];

long TCommunications_Handler::SendChecksumMessage(
    unsigned long param_1, unsigned int param_2,
    long param_3, long param_4, long param_5,
    long param_6, long param_7)
{
    MSGFORMAT_CHECKSUM cs;

    cs.WorldTime = param_1;
    cs.WorldTurn = this->current_turn;
    cs.cs1 = param_3;
    cs.cs2 = param_4;
    cs.cs3 = param_5;
    cs.cs4 = param_6;
    cs.cs5 = param_7;
    cs.Random = param_2;

    cs.PingInitiated = debug_timeGetTime(s_Com_hand_cpp, 0xBC0);

    TDebuggingLog::Log(L, "  >TX CKSUM (%d)", 0x24);

    long result = this->CommOut(0, 0x4D, &cs, 0x24, 0);

    this->Err->ShowReturn(result, s_SendChecksum);

    return result;
}
