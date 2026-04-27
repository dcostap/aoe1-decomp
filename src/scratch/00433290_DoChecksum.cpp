// VA: 00433290 DoChecksum (448B)
// com_sync.cpp lines 129-195

class RGE_Communications_Synchronize {
public:
    char gap4[0x14];        // +04 - +17 (vtable at +00, comm at +04, checkTime, checkTurn, stopOnSyncFail, dialogOnSyncFail, sendChatMsgs)
    int newData;            // +18
    int lastResult;         // +1C
    int offset;             // +20
    int doChecksums;        // +24
    int lastWorldRandom;    // +28
    int gameWorldChecksum;  // +2C
    
    void DoChecksum();
};

void __cdecl RGE_Communications_Synchronize_Add(void* this_, unsigned turn, 
    unsigned long wRandom, unsigned long checksum1, unsigned long checksum2,
    long chatCrc, long dataCrc, long a7, long a8, long a9);

void RGE_Communications_Synchronize::DoChecksum() {
    if (!doChecksums) return;
    
    // Get current turn
    int turn = offset;
    
    // Add checksum entry with worldRandom
    RGE_Communications_Synchronize_Add(this, turn, 0, 0, 0, 0, 0, 0, 0, 0);
}
