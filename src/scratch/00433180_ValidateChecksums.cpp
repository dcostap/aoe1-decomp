// VA: 00433180 ValidateChecksums (259B)
// com_sync.cpp lines 74-125
// Parameters: (ulong playerMask, ulong a2, long a3, long a4, long a5,
//              long a6, long a7, long a8, long a9) - ret 24h

class RGE_Communications_Synchronize {
public:
    char gap0[0x18];
    int newData;            // +18
    int lastResult;         // +1C
    int offset;             // +20
    
    int ValidateChecksums(unsigned long playerMask, unsigned long a2, 
            long a3, long a4, long a5, long a6, long a7, long a8, long a9);
};

int RGE_Communications_Synchronize::ValidateChecksums(unsigned long playerMask, 
        unsigned long a2, long a3, long a4, long a5, long a6, 
        long a7, long a8, long a9) {
    if (!newData) {
        return lastResult;
    }
    
    newData = 0;
    lastResult = 0;
    
    // Loop through entries and check sync
    int i;
    for (i = 0; i < offset; i++) {
        // Compare checksums
        // ...
    }
    
    return lastResult;
}
