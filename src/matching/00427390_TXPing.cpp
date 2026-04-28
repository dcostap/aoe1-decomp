struct PingTxBuf {
    char type;
    char pad_01[3];
    unsigned long time;
    unsigned long turn;
};

class TDebuggingLog {
public:
    static void Log(TDebuggingLog* log, const char* format, ...);
};

class TCommunications_Handler;

extern unsigned long debug_timeGetTime(const char* file, int line);
extern TDebuggingLog* L;
extern const char s_Com_hand_cpp[];

// Global TX ping buffer at 62CEF8
extern PingTxBuf g_PingTxBuf;

class TCommunications_Handler {
public:
    char gap_00[0x10C8];
    unsigned int current_turn;    // +0x10C8
    char gap_10CC[0x20C];         // +0x10CC to +0x12D7
    unsigned short MaxGamePlayers; // +0x12D8
    char gap_12DA[0xBA];          // +0x12DA to +0x1393
    long LastTXPing[1];           // +0x1394 (array base)
    char gap_1398[0x1CC];         // +0x1398 to +0x1563
    long dcoID[1];                // +0x1564 (array base - PlayerOptions.dcoID)

    long FastSend(long dcoID, void* buf, long size, long a, long b);

    int TXPing(unsigned int param_1);
};

int TCommunications_Handler::TXPing(unsigned int param_1) {
    unsigned long t = debug_timeGetTime(s_Com_hand_cpp, 0x470);
    unsigned int id = param_1;
    unsigned long dco;

    g_PingTxBuf.type = '1';
    g_PingTxBuf.time = t;
    g_PingTxBuf.turn = this->current_turn;

    if (id == 0) {
        unsigned int i = 1;
        if (this->MaxGamePlayers >= 1) {
            do {
                this->LastTXPing[i] = t;
                i++;
            } while (i <= this->MaxGamePlayers);
        }
        dco = 0;
    } else {
        this->LastTXPing[id] = t;
        dco = this->dcoID[id];
    }

    TDebuggingLog::Log(L, "  >TX PING #%d (%d)", id, 0x0C);

    long result = this->FastSend(dco, &g_PingTxBuf, 0x0C, 0, 0);

    return (result == 0) ? 1 : 0;
}

// Stubs
void TDebuggingLog::Log(TDebuggingLog* log, const char* format, ...) {}
long TCommunications_Handler::FastSend(long dcoID, void* buf, long size, long a, long b) { return 0; }
