// 00432FF0 RGE_Communications_Synchronize ctor
// com_sync.cpp:23-27, 125 bytes
// FLAGS: default
//
// Fixed: loop base starts at +0x38 (not +0x30) with store order matching
// original: base[-1], [0], [1], [2], [3], [4], [5], [6], then base[-2]
// (PlayerNo) last, advancing by 9 dwords (0x24 bytes) per iteration.
// The previous code started at +0x30 and stored 9 consecutive dwords.

#ifndef COM_SYNC_TU_CONTEXT
class TCommunications_Handler {
    // COM handler
};

class TDebuggingLog {
public:
    void Log(const char* fmt, ...);
};

extern TDebuggingLog* L;

class RGE_Communications_Synchronize {
public:
    TCommunications_Handler* Comm;       // +00
    unsigned long CheckTime;             // +04 = 1000
    unsigned long CheckTurn;             // +08 = 10
    int StopOnSyncFail;                  // +0C = 1
    int DialogOnSyncFail;                // +10 = 0
    int SendChatMsgs;                    // +14 = 0
    int NewData;                         // +18 = 0
    int LastResult;                      // +1C = 1
    unsigned int Offset;                 // +20 = 0
    int DoChecksums;                     // +24 = 1
    unsigned long LastWorldRandom;       // +28 = 0
    unsigned long GameWorldChecksum;     // +2C = 0
    struct CHECKSUMARRAY {
        int PlayerNo;
        unsigned long WTime;
        unsigned long WTurn;
        long cs1;
        long cs2;
        long cs3;
        long cs4;
        long cs5;
        unsigned long Random;
    };
    CHECKSUMARRAY Check[0x37];
    
    RGE_Communications_Synchronize(TCommunications_Handler* handler);
    
    int Add(int turn, int wRandom, int checksum1, int checksum2, int chatCrc, int dataCrc);
    int ValidateChecksums();
};
#endif

RGE_Communications_Synchronize::RGE_Communications_Synchronize(TCommunications_Handler* handler) {
    Comm = handler;
    CheckTime = 1000;
    CheckTurn = 10;
    
    L->Log("Check turn = %d", 10);
    
    StopOnSyncFail = 1;
    DoChecksums = 1;
    LastResult = 1;
    NewData = 0;
    Offset = 0;
    LastWorldRandom = 0;
    GameWorldChecksum = 0;
    SendChatMsgs = 0;
    DialogOnSyncFail = 0;
    
    unsigned long* base = &this->Check[0].WTurn;
    int i;
    for (i = 0; i < 0x37; i++) {
        base[-1] = 0;
        base[0] = 0;
        base[1] = 0;
        base[2] = 0;
        base[3] = 0;
        base[4] = 0;
        base[5] = 0;
        base[6] = 0;
        base[-2] = 0;
        base += 9;
    }
}
