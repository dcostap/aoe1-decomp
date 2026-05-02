// VA: 00429F80 TCommunications_Handler::ClearAllSerialNumbers (70B)
// PDB source: Com_hand.cpp lines 3146-3158
// tried pointer-end and explicit loop-counter forms
// best result matches 68/70 bytes: only remaining drift is VC5 hoisting `xor edi,edi` two bytes earlier, before the first zero stores, instead of after the fourth store as in the original

void Log(void* log, char* text);

class TCommunications_Handler {
public:
    char gap_00[0x12D8];
    unsigned short MaxGamePlayers;
    char gap_12DA[2];
    char gap_12DC[0x108];
    unsigned int LastSerialRequestedTX[10];

    void ClearAllSerialNumbers();
};

void TCommunications_Handler::ClearAllSerialNumbers() {
    unsigned int* p;
    unsigned int i;

    Log(*(void**)0x62C4FC, (char*)0x581E58);
    i = 0;
    p = this->LastSerialRequestedTX;
    do {
        p[0x51] = 0;
        p[0] = 0;
        p[0xA] = 0;
        p[0x14] = 0;
        p[0x1E] = 0;
        i = i + 1;
        p = p + 1;
    } while (i <= this->MaxGamePlayers);
}
