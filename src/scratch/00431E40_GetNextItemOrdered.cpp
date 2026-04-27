// 00431E40 GetNextItemOrdered
// 193 bytes, __thiscall, RGE_Communications_Queue method
// probe 1: find smallest ControlCommand matching ExecTurn==param_1, return Data

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

    unsigned int SendMsg;
    void TestShowQueue();

    void* GetNextItemOrdered(unsigned long param_1);
};

extern unsigned int g_queue_data;

void* RGE_Communications_Queue::GetNextItemOrdered(unsigned long param_1) {
    unsigned int bestControlCommand = 0xFFFFFFFF;
    unsigned int i = 0;
    int bestIndex = -1;

    for (int idx = 0; i <= HighQueueDepth; i++, idx += 0x1C) {
        MsgQueue* mq = Queue + i;

        if (mq->ControlCommand == 0) continue;
        if (mq->field_14 == 0) continue;

        if (mq->ExecTurn < param_1) {
            TestShowQueue();
        }

        if (mq->ControlCommand < bestControlCommand && mq->ExecTurn == param_1) {
            bestControlCommand = mq->ControlCommand;
            bestIndex = i;
        }
    }

    if (bestIndex == -1) return 0;

    g_queue_data = (unsigned int)Queue[bestIndex].Data;
    Queue[bestIndex].Data = 0;

    MsgQueue* mq = Queue + bestIndex;
    mq->ControlCommand = 0;
    mq->ExecTurn = 0;
    mq->Code = 0;
    mq->DataSize = 0;
    mq->field_14 = 0;
    mq->field_18 = 0;

    return (void*)g_queue_data;
}
