// 00431B10 FlushForPlayer
// 185 bytes, __thiscall, RGE_Communications_Queue method
// probe 2: use direct Log call pattern

class TDebuggingLog {
public:
    void Log(const char* format, ...);
};

extern TDebuggingLog* L;
void __cdecl operator delete(void* ptr);

struct MsgQueue {
    unsigned int ControlCommand;
    unsigned int ExecTurn;
    unsigned char Code;
    char gap_09[3];
    unsigned int DataSize;
    void* Data;
    unsigned int From;
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

    void FlushForPlayer(unsigned int param_1);
};

void RGE_Communications_Queue::FlushForPlayer(unsigned int param_1) {
    L->Log("Flushing queue for player %d", param_1);

    unsigned int i = 0;

    for (int edi = 0; i <= HighQueueDepth; i++, edi += 0x1C) {
        MsgQueue* mq = Queue + i;
        if (mq->From != param_1) continue;
        if (mq->field_14 == 0) continue;

        L->Log("Remove Q #%d Seq=%d ToExecute %ld From P#%d Size=%d CtrlCmd=%d",
            i, mq->Code, mq->ExecTurn, param_1, mq->field_14, mq->field_18, mq->ControlCommand);

        mq->ControlCommand = 0;
        mq->ExecTurn = 0;
        mq->Code = 0;
        mq->DataSize = 0;
        mq->field_14 = 0;
        mq->field_18 = 0;

        if (mq->Data != 0) {
            operator delete(mq->Data);
        }
        mq->Data = 0;
    }
}
