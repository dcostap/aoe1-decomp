// VA: 00429F80 TCommunications_Handler::ClearAllSerialNumbers (70B)
// PDB source: Com_hand.cpp lines 3146-3158
// Match note: pointer-walk form stayed in the near-miss basin with `xor edi,edi`
// hoisted before the zero stores; variant_lab showed the exact basin is the
// natural direct-index form over LastSerialRequestedTX with an unsigned loop index.

#if !defined(COM_HAND_TU_CONTEXT)
void Log(void* log, char* text);
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x12D8];
    unsigned short MaxGamePlayers;
    char gap_12DA[2];
    char gap_12DC[0x108];
    unsigned int LastSerialRequestedTX[10];

    void ClearAllSerialNumbers();
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::ClearAllSerialNumbers() {
    unsigned int i;

    Log(*(void**)0x62C4FC, (char*)0x581E58);
    i = 0;
    do {
        this->LastSerialRequestedTX[i + 0x51] = 0;
        this->LastSerialRequestedTX[i] = 0;
        this->LastSerialRequestedTX[i + 0xA] = 0;
        this->LastSerialRequestedTX[i + 0x14] = 0;
        this->LastSerialRequestedTX[i + 0x1E] = 0;
        i = i + 1;
    } while (i <= this->MaxGamePlayers);
}
