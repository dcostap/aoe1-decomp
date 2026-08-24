// VA: 00431F10 RGE_Communications_Queue::GetNextSequence (58B, 16 asm lines)
// PDB source: com_q.cpp lines 424-458
// ACCEPTED_DRIFT:
//   Reset path (38 bytes): MATCH (store ordering via reorder)
//   Increment path (13/20 bytes): MATCH (store ordering via comma expr)
//   Sbb/and/ret (7 bytes): codegen difference — VC5 uses sbb eax,eax + neg eax +
//     neg eax (32-bit truncation dance) instead of sbb al,al + and eax,ecx.
//     Semantically equivalent: (tmp < 0xFF) ? tmp : 0.
//   Total: 51/58 bytes match. Remaining 7 bytes are documented sbb width drift.

#ifndef COM_Q_CONTEXT
class RGE_Communications_Queue {
public:
    unsigned int QueueDepth;              // +0x00
    unsigned int HighQueueDepth;          // +0x04
    unsigned int MaxQSize;                // +0x08
    char TBuff[255];                      // +0x0C
    unsigned char _pad_10B[1];            // +0x10B (gap)
    unsigned long LastCurrentTurn;        // +0x10C
    unsigned char Sequence;               // +0x110
    unsigned char _pad_111[3];            // +0x111 (gap)
    void* Queue;                          // +0x114

    unsigned char GetNextSequence(unsigned long param_1);
};
#endif

unsigned char RGE_Communications_Queue::GetNextSequence(unsigned long param_1) {
    if (param_1 != this->LastCurrentTurn) {
        this->Sequence = 1;
        this->LastCurrentTurn = param_1;
        return 1;
    }
    return (this->Sequence = this->Sequence + 1, (unsigned char)(-(this->Sequence < 0xFF) & this->Sequence));
}
