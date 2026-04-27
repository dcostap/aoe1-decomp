// VA: 00433AD0 IsPlayerOutOfSync (610B)
// com_sync.cpp

class RGE_Communications_Synchronize {
public:
    char gap4[0x14];
    int newData;            // +18
    int lastResult;         // +1C
    int offset;             // +20
    int doChecksums;        // +24
    int lastWorldRandom;    // +28
    int gameWorldChecksum;  // +2C
    char gap30[0x860];
    // array at +30
    
    int IsPlayerOutOfSync();
};

extern int* rge_base_game;

int RGE_Communications_Synchronize::IsPlayerOutOfSync() {
    if (!doChecksums) return 0;
    
    // Validate checksums for each entry in the offset range
    int i;
    for (i = 0; i < offset; i++) {
        int* entry = (int*)((char*)this + 0x30 + i * 0x24);
        int worldRandom = entry[1];
        int checksum = entry[2];
        // Compare against expected
        if (lastWorldRandom != worldRandom) continue;
        if (gameWorldChecksum != checksum) {
            // Out of sync
            return 1;
        }
    }
    
    return 0;
}
