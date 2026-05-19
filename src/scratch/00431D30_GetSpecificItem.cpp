// 00431D30 RGE_Communications_Queue::GetSpecificItem (156B)
// com_q.cpp:298-323
// Default flags

extern int g_queue_data;

struct MsgQueueEntry {
    int Code;           // +0
    int ExecTurn;       // +4
    unsigned char SeqNo; // +8
    char pad_09[3];     // +9..+B
    char* msgptr;       // +0xC
    int From;           // +0x10
    int Size;           // +0x14
    int ControlCommand; // +0x18
}; // total = 0x1C

class RGE_Communications_Queue {
public:
    char gap_00[4];
    int HighQueueDepth;     // +4
    char gap_08[0x10C];     // +8 to +0x113
    MsgQueueEntry* Queue;   // +0x114

    void* GetSpecificItem(unsigned int param_1, unsigned long param_2, unsigned char param_3, unsigned int* param_4);
};

void* RGE_Communications_Queue::GetSpecificItem(unsigned int param_1, unsigned long param_2, unsigned char param_3, unsigned int* param_4)
{
    int targetCode = param_1 * 1000 + param_3;

    int idx = 0;
    MsgQueueEntry* entry = Queue;

    while (1) {
        if (entry->Code == targetCode && entry->ExecTurn == param_2)
            goto found;
        idx++;
        entry++;
        if (idx > HighQueueDepth)
            return 0;
    }

found:
    *param_4 = entry->Size;
    g_queue_data = (int)entry->msgptr;
    entry->msgptr = 0;

    entry->Code = 0;
    entry->ExecTurn = 0;
    entry->SeqNo = 0;
    entry->From = 0;
    entry->Size = 0;
    entry->ControlCommand = 0;

    return (void*)g_queue_data;
}
