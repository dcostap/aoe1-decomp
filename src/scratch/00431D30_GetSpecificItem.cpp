// 00431D30 RGE_Communications_Queue::GetSpecificItem (156B)
// com_q.cpp:298-323
// Default flags

#include "../../include/game_globals.h"

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
    unsigned int HighQueueDepth; // +4
    char gap_08[0x10C];
    MsgQueueEntry* Queue;       // +0x114

    void* GetSpecificItem(unsigned int param_1, unsigned long param_2, unsigned char param_3, unsigned int* param_4);
};

void* RGE_Communications_Queue::GetSpecificItem(unsigned int param_1, unsigned long param_2, unsigned char param_3, unsigned int* param_4)
{
    unsigned int targetCode = param_1 * 1000 + param_3;

    unsigned int idx = 0;
    MsgQueueEntry* entry = Queue;

    while (1) {
        if (entry->Code == (int)targetCode && entry->ExecTurn == (int)param_2)
            goto found;
        idx++;
        entry++;
        if (idx > HighQueueDepth)
            return 0;
    }

found:
    *param_4 = Queue[idx].Size;
    DAT_0062cf3c = (unsigned int)Queue[idx].msgptr;
    Queue[idx].msgptr = 0;

    Queue[idx].Code = 0;
    Queue[idx].ExecTurn = 0;
    Queue[idx].SeqNo = 0;
    Queue[idx].From = 0;
    Queue[idx].Size = 0;
    Queue[idx].ControlCommand = 0;

    return (void*)DAT_0062cf3c;
}
