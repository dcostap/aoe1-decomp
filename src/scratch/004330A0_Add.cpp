// VA: 004330A0 Add (209B)
// com_sync.cpp lines 44-62
// Parameters: (uint turn, ulong wRandom, ulong checksum1, ulong checksum2,
//              long chatCrc, long dataCrc, long a7, long a8, long a9)

class RGE_Communications_Synchronize {
public:
    char gap0[0x18];
    int newData;            // +18
    int lastResult;         // +1C
    int offset;             // +20
    int doChecksums;        // +24
    // checksum array at +30, entry stride 0x24
    
    int Add(unsigned turn, unsigned long wRandom, unsigned long checksum1,
            unsigned long checksum2, long chatCrc, long dataCrc,
            long a7, long a8, long a9);
};

unsigned __cdecl getTurn();
int __cdecl ValidateChecksums(void* this_);

int RGE_Communications_Synchronize::Add(unsigned turn, unsigned long wRandom, 
        unsigned long checksum1, unsigned long checksum2,
        long chatCrc, long dataCrc, long a7, long a8, long a9) {
    if (!doChecksums) return 0;
    
    int idx = offset + 1;
    if (idx > 0x36) idx = 0;
    offset = idx;
    
    // Store into checksumArray[idx].
    // struct { int playerNo; int wTurn; int checksum1; int checksum2;
    //          int chatCrc; int dataCrc; int a7; int a8; int a9; }
    int* entry = (int*)((char*)this + 0x30 + idx * 0x24);
    entry[0] = turn;        // WTurn
    entry[1] = wRandom;     // WorldRandom
    entry[2] = checksum1;   // Checksum1
    entry[3] = checksum2;   // Checksum2
    entry[4] = chatCrc;     // ChatCrc
    entry[5] = dataCrc;     // DataCrc
    entry[6] = a7;          // ?
    entry[7] = a8;          // ?
    entry[8] = a9;          // ?
    
    newData = 1;
    return ValidateChecksums(this);
}
