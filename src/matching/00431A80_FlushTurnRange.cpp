// 00431A80 FlushTurnRange
// 143 bytes, __thiscall, RGE_Communications_Queue method
// probe 1: natural loop through Queue array, clear items in turn range
// MATCHED 2026-05-19: MsgQueue is 0x1C bytes (no DataSize field; Data at +0x0C).
// Use direct Queue byte-offset expressions for execTurn/mq to get load-base/lea shape,
// and spell range miss as `execTurn < param_1 || execTurn > param_2` for cmp/jb.

#ifndef COM_Q_CONTEXT
void __cdecl operator delete(void* ptr);
struct MsgQueue {
    unsigned int ControlCommand;
    unsigned int ExecTurn;
    unsigned char Code;
    char gap_09[3];
    void* Data;
    unsigned int field_10;
    unsigned int field_14;
    unsigned int field_18;
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

    unsigned int FlushTurnRange(unsigned long param_1, unsigned long param_2);
};
#endif

unsigned int RGE_Communications_Queue::FlushTurnRange(unsigned long param_1, unsigned long param_2) {
    unsigned int i = 0;
    unsigned int local_4 = 0;

    for (int edi = 0; local_4 <= HighQueueDepth; local_4++, edi += 0x1C) {
#ifdef COM_Q_CONTEXT
        // BINARY NOTE: Keep a reference to Queue. VC5 then uses Queue as the SIB base.
        MsgQueue*& queue = Queue;
        unsigned int execTurn = *(unsigned int*)((char*)queue + edi + 4);
        MsgQueue* mq = (MsgQueue*)((char*)queue + edi);
#else
        unsigned int execTurn = *(unsigned int*)((char*)Queue + edi + 4);
        MsgQueue* mq = (MsgQueue*)((char*)Queue + edi);
#endif

        if (((execTurn < param_1) || (execTurn > param_2)) &&
            !((param_1 == 0) && (param_2 == 0))) {
            continue;
        }

        i++;
#ifdef COM_Q_CONTEXT
        if (mq->Size <= 0) continue;

        mq->Code = 0;
        mq->ExecTurn = 0;
        mq->SeqNo = 0;
        mq->From = 0;
        mq->Size = 0;
        mq->ControlCommand = 0;

        if (mq->msgptr != 0) {
            operator delete(mq->msgptr);
        }
        mq->msgptr = 0;
#else
        if (mq->field_14 <= 0) continue;

        mq->ControlCommand = 0;
        mq->ExecTurn = 0;
        mq->Code = 0;
        mq->field_10 = 0;
        mq->field_14 = 0;
        mq->field_18 = 0;

        if (mq->Data != 0) {
            operator delete(mq->Data);
        }
        mq->Data = 0;
#endif
    }

    return i;
}
