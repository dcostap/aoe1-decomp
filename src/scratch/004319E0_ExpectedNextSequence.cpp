// attempt 1: natural queue walk with the global sequence byte updated on each matching entry
// result: compiled to a smaller 80-byte body; VC5 picked a tighter pointer-walk basin than the original
// attempt 2: switch to the decompiler-style do/while with explicit offset and sequence locals
// attempt 3: exact body is still off by the final return basin; VC5 keeps shrinking it to a tighter byte-return shape
// left in scratch for now because the remaining mismatch is localized to the tail/register basin

extern unsigned char DAT_0062cf40;

class MsgQueueEntry {
public:
    unsigned long unk0;
    unsigned long ExecTurn; // +4
    unsigned long unk8;
    unsigned long unkC;
    unsigned long From; // +0x10
    unsigned long Size; // +0x14
    unsigned long unk18;
};

class RGE_Communications_Queue {
public:
    unsigned int QueueDepth;
    unsigned int HighQueueDepth;
    char gap_08[0x10C - 0x08];
    unsigned long LastCurrentTurn;
    unsigned char Sequence;
    char gap_111[3];
    MsgQueueEntry* Queue;

    unsigned char ExpectedNextSequence(unsigned long param_1, unsigned int param_2);
};

unsigned char RGE_Communications_Queue::ExpectedNextSequence(unsigned long param_1, unsigned int param_2) {
    unsigned char sequence;
    unsigned int iVar2;
    unsigned int uVar4;
    MsgQueueEntry* pMVar1;

    sequence = 1;
    uVar4 = 0;
    DAT_0062cf40 = 1;
    iVar2 = 0;
    do {
        pMVar1 = (MsgQueueEntry*)((char*)this->Queue + iVar2);
        if ((pMVar1->ExecTurn == param_1) && (pMVar1->From == param_2) && (pMVar1->Size != 0)) {
            sequence = sequence + 1;
            DAT_0062cf40 = sequence;
        }
        uVar4 = uVar4 + 1;
        iVar2 = iVar2 + 0x1C;
    } while (uVar4 <= this->HighQueueDepth);

    return DAT_0062cf40;
}
