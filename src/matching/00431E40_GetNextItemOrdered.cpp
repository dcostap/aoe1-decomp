// 00431E40 GetNextItemOrdered
// 193 bytes, __thiscall, RGE_Communications_Queue method
// MATCHED 2026-08-07 (orch-w17): natural Queue[i] array-indexed scan with
// direct this->Queue member indexing (GetNextItemSingle family, no cached
// Queue local). VC5 strength-reduces i*0x1C into the byte-offset register and
// materializes the candidate element pointer via lea, reproducing the original
// `mov edx,[esi+114h]; mov eax,[edx+edi]; lea ecx,[edx+edi]` candidate shape.
// All earlier raw byte-offset cursor spellings kept CSE-ing the Code and
// ExecTurn reads into one add-merged pointer register (2-byte drift).
// prior attempt log:
// probe 1: find smallest ControlCommand matching ExecTurn==param_1, return Data
// probe 2: corrected MsgQueue to the proven 0x1C-byte com_q.cpp layout and
// canonical member names; retained the natural indexed scan for this check.
// probe 3: use the binary-supported typed byte-offset cursor and reread Queue for the
// post-TestShowQueue candidate, matching the original's offset/index topology.
// probe 4: fresh typed candidate cursor did not recover the original LEA; reverted.
// probe 5/6/7/8: field-anchored, ABI-width, integer-address, and post-load cursor
// spellings were codegen duplicates; retained the simplest direct cursor form.
// probe 9: keeping the cursor live across TestShowQueue changed the prologue;
// reverted. Probe 10: a narrow volatile reread was also a codegen duplicate.

#ifndef COM_Q_CONTEXT
void __cdecl operator delete(void* ptr);
struct MsgQueue {
    unsigned int Code;
    unsigned int ExecTurn;
    unsigned char SeqNo;
    char pad_09[3];
    void* msgptr;
    unsigned int From;
    unsigned int Size;
    int ControlCommand;
};

class RGE_Communications_Queue {
public:
    unsigned int QueueDepth;
    unsigned int HighQueueDepth;
    unsigned int MaxQSize;
    char TBuff[255];
    unsigned char _pad_0[1];
    unsigned long LastCurrentTurn;
    unsigned char Sequence;
    unsigned char _pad_1[3];
    MsgQueue* Queue;

    unsigned int SendMsg;
    void TestShowQueue();

    void* GetNextItemOrdered(unsigned long param_1);
};
#endif

extern void* DAT_0062cf38;

void* RGE_Communications_Queue::GetNextItemOrdered(unsigned long param_1) {
    unsigned int bestControlCommand = 0xFFFFFFFF;
    unsigned int i = 0;
    int bestIndex = -1;

    do {
        if (Queue[i].Code != 0 && Queue[i].Size != 0) {
            if (Queue[i].ExecTurn < param_1) {
                TestShowQueue();
            }

            if (Queue[i].Code < bestControlCommand &&
                Queue[i].ExecTurn == param_1) {
                bestControlCommand = Queue[i].Code;
                bestIndex = i;
            }
        }

        i++;
    } while (i <= HighQueueDepth);

    if (bestIndex == -1) return 0;

    DAT_0062cf38 = Queue[bestIndex].msgptr;
    Queue[bestIndex].msgptr = 0;

    MsgQueue* mq = Queue + bestIndex;
    mq->Code = 0;
    mq->ExecTurn = 0;
    mq->SeqNo = 0;
    mq->From = 0;
    mq->Size = 0;
    mq->ControlCommand = 0;

    return DAT_0062cf38;
}
