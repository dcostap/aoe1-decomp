// 00431BF0 AddItem
// 275 bytes, __thiscall, RGE_Communications_Queue method
// Attempt log:
// - baseline decompiler-shaped reconstruction had a 0x20-byte MsgQueue and
//   scalar copy loops (335 bytes, 39.50% shape).
// - corrected MsgQueue to the proven 0x1C-byte layout and used VC5 memcpy;
//   restored Code/SeqNo/Size/ControlCommand widths and store order.
// - separate scan/index locals, a persistent this alias, and indexed/scoped
//   queue-slot variants were diagnostic probes; they changed the register basin.
// - Exact reconstruction: direct this/member use with one index i, a natural
//   top-tested Size-pointer walk, and index-left comparisons.  VC5 uses the
//   proven [Queue + i*0x1C + Size] cursor and spills i in the incoming push-ecx
//   home across the copy, matching all 275 bytes.

#include <string.h>

#ifndef COM_Q_CONTEXT
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
#endif

int RGE_Communications_Queue::AddItem(unsigned long param_1, void* param_2, unsigned long param_3, unsigned int param_4, unsigned char param_5, int param_6) {
    unsigned int i = 0;
    unsigned int* size_cursor = &this->Queue->Size;

    while (*size_cursor != 0) {
        if (i >= this->MaxQSize) break;
        size_cursor = size_cursor + 7;
        i = i + 1;
    }

    if (i >= this->MaxQSize) {
        if (!this->AllocateQueue(this->MaxQSize + 0x14)) return 0;
        i = i + 1;
    }

    unsigned int high_depth = this->HighQueueDepth;
    if (i > this->HighQueueDepth) {
        high_depth = i;
    }

    MsgQueue* slot = this->Queue + i;
    this->HighQueueDepth = high_depth;

    char* message = (char*)operator new(param_3 + 1);
    slot->msgptr = message;

    if (message != 0) {
        memcpy(message, param_2, param_3);
    }

    this->Queue[i].Size = param_3;
    this->Queue[i].SeqNo = param_5;
    this->Queue[i].ExecTurn = param_1;
    this->Queue[i].From = param_4;
    this->Queue[i].Code = (unsigned int)param_5 + param_4 * 1000;
    this->Queue[i].ControlCommand = param_6;
    this->QueueDepth = i;

    return 1;
}
