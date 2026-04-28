// 00432FF0 RGE_Communications_Synchronize ctor
// com_sync.cpp:23-27, 125 bytes
// FLAGS: default
//
// Fixed: loop base starts at +0x38 (not +0x30) with store order matching
// original: base[-1], [0], [1], [2], [3], [4], [5], [6], then base[-2]
// (PlayerNo) last, advancing by 9 dwords (0x24 bytes) per iteration.
// The previous code started at +0x30 and stored 9 consecutive dwords.

class TCommunications_Handler {
    // COM handler
};

class TDebuggingLog {
public:
    void Log(const char* fmt, ...);
};

extern TDebuggingLog* g_debuggingLog;

class RGE_Communications_Synchronize {
public:
    TCommunications_Handler* comm;       // +00
    int checkTime;                       // +04 = 1000
    int checkTurn;                       // +08 = 10
    int stopOnSyncFail;                  // +0C = 1
    int dialogOnSyncFail;                // +10 = 0
    int sendChatMsgs;                    // +14 = 0
    int newData;                         // +18 = 0
    int lastResult;                      // +1C = 1
    int offset;                          // +20 = 0
    int doChecksums;                     // +24 = 1
    int lastWorldRandom;                 // +28 = 0
    int gameWorldChecksum;              // +2C = 0
    int field_30;                        // +30 = 0 (covered by first entry's [eax-8][eax-4])
    // Checksum array[55] starts at +0x38, each entry 9 ints (0x24 bytes)
    // Entry layout: PlayerNo[-2], WTurn[-1], dword[0..6]
    
    RGE_Communications_Synchronize(TCommunications_Handler* handler);
    
    int Add(int turn, int wRandom, int checksum1, int checksum2, int chatCrc, int dataCrc);
    int ValidateChecksums();
};

RGE_Communications_Synchronize::RGE_Communications_Synchronize(TCommunications_Handler* handler) {
    comm = handler;
    checkTime = 1000;
    checkTurn = 10;
    
    g_debuggingLog->Log("Check turn = %d", 10);
    
    stopOnSyncFail = 1;
    doChecksums = 1;
    lastResult = 1;
    newData = 0;
    offset = 0;
    lastWorldRandom = 0;
    gameWorldChecksum = 0;
    sendChatMsgs = 0;
    dialogOnSyncFail = 0;
    
    // Zero out the checksum array (0x37 entries x 9 dwords = 0x24 bytes each)
    int* base = (int*)((char*)this + 0x38);
    int i;
    for (i = 0; i < 0x37; i++) {
        base[-1] = 0;  // WTurn-like
        base[0] = 0;
        base[1] = 0;
        base[2] = 0;
        base[3] = 0;
        base[4] = 0;
        base[5] = 0;
        base[6] = 0;
        base[-2] = 0;  // PlayerNo
        base += 9;
    }
}
