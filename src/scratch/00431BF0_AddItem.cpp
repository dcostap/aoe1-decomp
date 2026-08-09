// 00431BF0 AddItem
// 275 bytes, __thiscall, RGE_Communications_Queue method
// Attempt log:
// - baseline decompiler-shaped reconstruction had a 0x20-byte MsgQueue and
//   scalar copy loops (335 bytes, 39.50% shape).
// - corrected MsgQueue to the proven 0x1C-byte layout and used VC5 memcpy;
//   restored Code/SeqNo/Size/ControlCommand widths and store order.
// - a persistent index local reproduced the original push-ecx home and frame
//   size; same-TU this alias was a codegen duplicate.
// - binary-supported Size-pointer scan, separate scan/index values, scoped
//   queue slot, and local_4 post-growth indexing were tried in sequence.
//   The final reconstruction preserves the observed pointer cursor, growth,
//   copy, and metadata ownership; no exact match after the 10-probe budget.
// - Main-agent audit replaced decompiler-local names with descriptive queue,
//   cursor, depth, and message roles; emitted code and metrics are unchanged.

#include <string.h>

void __cdecl operator delete(void* ptr);
void* __cdecl operator new(unsigned int size);

struct MsgQueue {
    unsigned int Code;
    unsigned int ExecTurn;
    unsigned char SeqNo;
    char gap_09[3];
    char* msgptr;
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

    int AllocateQueue(unsigned int newSize);

    int AddItem(unsigned long param_1, void* param_2, unsigned long param_3, unsigned int param_4, unsigned char param_5, int param_6);
};

int RGE_Communications_Queue::AddItem(unsigned long param_1, void* param_2, unsigned long param_3, unsigned int param_4, unsigned char param_5, int param_6) {
    RGE_Communications_Queue* queue = this;
    unsigned int i = 0;
    unsigned int local_4 = 0;
    unsigned int* size_cursor = &queue->Queue->Size;
    int* next_size;

    local_4 = i;
    if (*size_cursor != 0) {
        do {
            local_4 = i;
            if (queue->MaxQSize <= i) break;
            next_size = (int*)(size_cursor + 7);
            size_cursor = size_cursor + 7;
            i = i + 1;
            local_4 = i;
        } while (*next_size != 0);
    }

    if (queue->MaxQSize <= local_4) {
        if (!queue->AllocateQueue(queue->MaxQSize + 0x14)) return 0;
        local_4 = local_4 + 1;
    }

    unsigned int high_depth = queue->HighQueueDepth;
    if (queue->HighQueueDepth < local_4) {
        high_depth = local_4;
    }

    MsgQueue* slot = queue->Queue + local_4;
    queue->HighQueueDepth = high_depth;

    char* message = (char*)operator new(param_3 + 1);
    slot->msgptr = message;

    if (message != 0) {
        memcpy(message, param_2, param_3);
    }

    queue->Queue[local_4].Size = param_3;
    queue->Queue[local_4].SeqNo = param_5;
    queue->Queue[local_4].ExecTurn = param_1;
    queue->Queue[local_4].From = param_4;
    queue->Queue[local_4].Code = (unsigned int)param_5 + param_4 * 1000;
    queue->Queue[local_4].ControlCommand = param_6;
    queue->QueueDepth = local_4;

    return 1;
}
