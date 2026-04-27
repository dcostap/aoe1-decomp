// VA: 00432FF0 RGE_Communications_Synchronize ctor (125B)
// com_sync.cpp lines 23-27

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
    int field_30;                        // +30 = 0
    // Checksum array[55] starts at +0x34
    // each entry 0x24 bytes: PlayerNo + 8 dwords
    
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
    
    // Zero out the checksum array (0x37 entries x 0x24 bytes each)
    int* base = (int*)((char*)this + 0x30);
    int i;
    for (i = 0; i < 0x37; i++) {
        base[0] = 0;  // field at -8 from base (PlayerNo-like)
        base[1] = 0;  // field at -4 (WTurn-like)
        base[2] = 0;  // WTurn at base+0
        base[3] = 0;  // field at +4
        base[4] = 0;  // field at +8
        base[5] = 0;  // field at +0C
        base[6] = 0;  // field at +10
        base[7] = 0;  // field at +14
        base[8] = 0;  // field at +18
        base += 9;    // 9 dwords per entry
    }
}
