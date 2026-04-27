// 00431810 AllocateQueue
// 464 bytes, __thiscall, RGE_Communications_Queue method
// probe 1: /GX EH, alloc new MsgQueue array, copy old entries, free old

void __cdecl operator delete(void* ptr);
void* __cdecl operator new(unsigned int size);
void __cdecl eh_vector_constructor_iterator(void* pBlock, unsigned int elemSize, unsigned int elemCount, void* ctor, void* dtor);
void __cdecl eh_vector_destructor_iterator(void* pBlock, unsigned int elemSize, unsigned int elemCount, void* dtor);

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

void* MsgQueue_ctor_addr = (void*)0x431F60;
void* MsgQueue_dtor_addr = (void*)0x431F80;

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

    int AllocateQueue(unsigned int param_1);
};

int RGE_Communications_Queue::AllocateQueue(unsigned int param_1) {
    if (param_1 < MaxQSize) return 0;

    unsigned int count = param_1 + 1;
    unsigned int* header = (unsigned int*)operator new(count * 0x1C + 4);
    if (header == 0) return 0;

    *header = count;
    MsgQueue* newQueue = (MsgQueue*)(header + 1);

    eh_vector_constructor_iterator(newQueue, 0x1C, count, MsgQueue_ctor_addr, MsgQueue_dtor_addr);

    if (Queue != 0) {
        for (int i = 0; i <= MaxQSize; i++) {
            if (Queue[i].field_14 != 0) {
                newQueue[i].ControlCommand = Queue[i].ControlCommand;
                newQueue[i].ExecTurn = Queue[i].ExecTurn;
                newQueue[i].Code = Queue[i].Code;
                newQueue[i].DataSize = Queue[i].DataSize;

                void* newData = operator new(Queue[i].DataSize + 1);
                newQueue[i].Data = newData;
                if (newData != 0) {
                    unsigned char* src = (unsigned char*)Queue[i].Data;
                    unsigned char* dst = (unsigned char*)newData;
                    unsigned long bytes = Queue[i].DataSize;
                    unsigned long dwords = bytes / 4;
                    unsigned long remainder = bytes % 4;
                    unsigned int* sd = (unsigned int*)src;
                    unsigned int* dd = (unsigned int*)dst;
                    unsigned long k;
                    for (k = 0; k < dwords; k++) dd[k] = sd[k];
                    unsigned char* sc = (unsigned char*)sd + dwords * 4;
                    unsigned char* dc = (unsigned char*)dd + dwords * 4;
                    unsigned long m;
                    for (m = 0; m < remainder; m++) dc[m] = sc[m];
                }

                newQueue[i].From = Queue[i].From;
                newQueue[i].field_14 = Queue[i].field_14;
                newQueue[i].field_18 = Queue[i].field_18;
            }
        }

        eh_vector_destructor_iterator(Queue, 0x1C, *header, MsgQueue_dtor_addr);
        operator delete(header);
    }

    MaxQSize = param_1;
    Queue = newQueue;

    return 1;
}
