#ifndef AOE1_COM_Q_CONTEXT_H
#define AOE1_COM_Q_CONTEXT_H

// Authentic shared surface for com_q.cpp.
// The executable stores QueueDepth at +0 and Queue at +0x114.

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* ptr);
extern "C" void __stdcall eh_vector_destructor_iterator(
    void* ptr, unsigned int size, int count, void (*destructor)(void*));

class MsgQueue {
public:
    unsigned int Code;
    unsigned int ExecTurn;
    unsigned char SeqNo;
    char gap_09[3];
    union {
        char* msgptr;
        void* Data;
    };
    union {
        unsigned int From;
        unsigned int field_10;
    };
    union {
        unsigned int Size;
        unsigned int field_14;
    };
    union {
        int ControlCommand;
        unsigned int field_18;
    };

    MsgQueue();
    ~MsgQueue();
};

typedef MsgQueue MsgQueueEntry;

extern void* DAT_0062cf34;
extern void* DAT_0062cf38;
extern unsigned int DAT_0062cf3c;
extern int DAT_0062cf40;

class TDebuggingLog {
public:
    void Log(const char* format, ...);
};

#define L (*(TDebuggingLog**)0x62C4FC)

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

    RGE_Communications_Queue(int param_1);
    ~RGE_Communications_Queue();

    int AllocateQueue(unsigned int param_1);
    unsigned char ExpectedNextSequence(unsigned long turn, unsigned int from);
    unsigned int QueuedForTurn(unsigned long turn);
    void FlushAll();
    unsigned int FlushTurnRange(unsigned long first, unsigned long last);
    void FlushForPlayer(unsigned int player);
    unsigned int FlushForTurn(unsigned long turn);
    unsigned int FlushThruTurn(unsigned long turn);
    int AddItem(unsigned long turn, void* data, unsigned long size,
                unsigned int from, unsigned char sequence, int control);
    int GetQueueDepth();
    int GetHighQueueDepth();
    void* GetSpecificItem(unsigned int player, unsigned long turn,
                          unsigned char sequence, unsigned int* size);
    void* GetNextItemSingle();
    void* GetNextItemOrdered(unsigned long turn);
    unsigned char GetNextSequence(unsigned long turn);
    void TestShowQueue();
};

#endif
