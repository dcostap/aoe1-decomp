// 00431BF0 AddItem
// 275 bytes, __thiscall, RGE_Communications_Queue method
// probe 1: find empty slot, grow if needed, alloc+copy data, set fields

void __cdecl operator delete(void* ptr);
void* __cdecl operator new(unsigned int size);

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

    int AllocateQueue(unsigned int newSize);

    int AddItem(unsigned long param_1, void* param_2, unsigned long param_3, unsigned int param_4, unsigned char param_5, int param_6);
};

int RGE_Communications_Queue::AddItem(unsigned long param_1, void* param_2, unsigned long param_3, unsigned int param_4, unsigned char param_5, int param_6) {
    unsigned int i = 0;

    // Search for empty slot (field_14 == 0 means empty)
    if (Queue[0].field_14 != 0) {
        for (i = 1; i < MaxQSize; i++) {
            if (Queue[i].field_14 == 0) break;
        }
    }

    // Grow queue if full
    if (i >= MaxQSize) {
        if (!AllocateQueue(MaxQSize + 0x14)) return 0;
        i++;
    }

    // Update HighQueueDepth
    if (i > HighQueueDepth) HighQueueDepth = i;

    // Allocate memory for data (param_3 + 1)
    void* data = operator new(param_3 + 1);
    Queue[i].Data = data;

    if (data != 0) {
        unsigned long bytes = param_3;
        unsigned long dwords = bytes / 4;
        unsigned long remainder = bytes % 4;
        unsigned int* dst = (unsigned int*)data;
        unsigned int* src = (unsigned int*)param_2;
        unsigned long k;
        for (k = 0; k < dwords; k++) dst[k] = src[k];
        unsigned char* cdst = (unsigned char*)dst + dwords * 4;
        unsigned char* csrc = (unsigned char*)src + dwords * 4;
        unsigned long m;
        for (m = 0; m < remainder; m++) cdst[m] = csrc[m];
    }

    Queue[i].DataSize = param_3;
    Queue[i].Code = param_4 * 1000 + param_5;
    Queue[i].ExecTurn = param_1;
    Queue[i].From = param_4;
    Queue[i].field_14 = param_3;
    Queue[i].ControlCommand = param_6;
    QueueDepth = i;

    return 1;
}
