#pragma once
#include "common.h"

class MsgQueue {
public:
    ulong Code;                              // 0x0
    ulong ExecTurn;                          // 0x4
    uchar SeqNo;                             // 0x8
    char* msgptr;                            // 0xC
    uint From;                               // 0x10
    uint Size;                               // 0x14
    int ControlCommand;                      // 0x18

    MsgQueue();
    ~MsgQueue();
};

static_assert(sizeof(MsgQueue) == 0x1C, "MsgQueue Size Mismatch");

class RGE_Communications_Queue {
public:
    uint QueueDepth;                         // 0x0
    uint HighQueueDepth;                     // 0x4
    uint MaxQSize;                           // 0x8
    char TBuff[255];                         // 0xC
    ulong LastCurrentTurn;                   // 0x10C
    uchar Sequence;                          // 0x110
    MsgQueue* Queue;                         // 0x114

    RGE_Communications_Queue(int param_1);
    ~RGE_Communications_Queue();
    int AllocateQueue(uint param_1);
    uchar ExpectedNextSequence(ulong param_1, uint param_2);
    uint QueuedForTurn(ulong param_1);
    void FlushAll();
    uint FlushTurnRange(ulong param_1, ulong param_2);
    void FlushForPlayer(uint param_1);
    uint FlushForTurn(ulong param_1);
    uint FlushThruTurn(ulong param_1);
    int AddItem(ulong param_1, void* param_2, ulong param_3, uint param_4, uchar param_5, int param_6);
    uint GetQueueDepth();
    uint GetHighQueueDepth();
    void* GetSpecificItem(uint param_1, ulong param_2, uchar param_3, uint* param_4);
    void* GetNextItemSingle();
    void* GetNextItemOrdered(ulong param_1);
    uchar GetNextSequence(ulong param_1);
    void TestShowQueue();
};

static_assert(sizeof(RGE_Communications_Queue) == 0x118, "RGE_Communications_Queue Size Mismatch");

