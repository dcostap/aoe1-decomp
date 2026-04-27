// 00431D30 GetSpecificItem
// 156 bytes, __thiscall, RGE_Communications_Queue method
// probe 1: search queue by Code and ExecTurn, return Data pointer

void __cdecl operator delete(void* ptr);

struct MsgQueue {
    unsigned int ControlCommand;
    unsigned int ExecTurn;
    unsigned char Code;
    char gap_09[3];
    unsigned int DataSize;
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

    void* GetSpecificItem(unsigned int param_1, unsigned long param_2, unsigned char param_3, unsigned int* param_4);
};

extern unsigned int g_queue_data;

void* RGE_Communications_Queue::GetSpecificItem(unsigned int param_1, unsigned long param_2, unsigned char param_3, unsigned int* param_4) {
    unsigned int i = 0;
    MsgQueue* mq = Queue;

    unsigned int targetCode = param_1 * 1000 + param_3;

    while (mq->ControlCommand != targetCode || mq->ExecTurn != param_2) {
        i++;
        mq++;
        if (i > HighQueueDepth) return 0;
    }

    *param_4 = mq->field_14;
    g_queue_data = (unsigned int)mq->Data;
    mq->Data = 0;

    mq->ControlCommand = 0;
    mq->ExecTurn = 0;
    mq->Code = 0;
    mq->DataSize = 0;
    mq->field_10 = 0;
    mq->field_14 = 0;
    mq->field_18 = 0;

    return (void*)g_queue_data;
}
