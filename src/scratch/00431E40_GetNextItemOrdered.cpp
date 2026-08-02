// 00431E40 GetNextItemOrdered
// 193 bytes, __thiscall, RGE_Communications_Queue method
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
// Best unresolved reconstruction: canonical 0x1C MsgQueue layout and proven
// byte-offset scan are exact structurally through the first candidate compare;
// remaining drift is a two-byte candidate-address/register expression plus the
// resulting branch alignment and parameter compare coloring.

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

extern void* DAT_0062cf38;

void* RGE_Communications_Queue::GetNextItemOrdered(unsigned long param_1) {
    unsigned int bestControlCommand = 0xFFFFFFFF;
    unsigned int i = 0;
    int bestIndex = -1;

    int idx = 0;
    do {
        MsgQueue* item = (MsgQueue*)((char*)Queue + idx);

        if (item->Code != 0 && item->Size != 0) {
            if (item->ExecTurn < param_1) {
                TestShowQueue();
            }

            unsigned int code = *(unsigned int*)((char*)Queue + idx);
            if (code < bestControlCommand &&
                *(unsigned int*)((char*)Queue + idx + 4) == param_1) {
                bestControlCommand = code;
                bestIndex = i;
            }
        }

        i++;
        idx += 0x1C;
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
