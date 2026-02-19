#pragma once
#include "common.h"
#include "MsgQueue.h"

struct RGE_Communications_Queue {
    RGE_Communications_Queue(int max_queue_size);
    ~RGE_Communications_Queue();

    int AllocateQueue(uint queue_size);
    uchar ExpectedNextSequence(ulong exec_turn, uint from_player);
    uint QueuedForTurn(ulong exec_turn);
    void FlushAll();
    uint FlushTurnRange(ulong start_turn, ulong end_turn);
    void FlushForPlayer(uint from_player);
    uint FlushForTurn(ulong turn);
    uint FlushThruTurn(ulong turn);
    int AddItem(ulong exec_turn, void* payload, ulong payload_size, uint from_player, uchar sequence, int control_command);
    void* GetNextItemSingle();
    void* GetNextItemOrdered(ulong current_turn);
    uchar GetNextSequence(ulong current_turn);
    void TestShowQueue();

    uint QueueDepth;
    uint HighQueueDepth;
    uint MaxQSize;
    char TBuff[255];
    ulong LastCurrentTurn;
    uchar Sequence;
    MsgQueue* Queue;
};
static_assert(sizeof(RGE_Communications_Queue) == 0x118, "Size mismatch");
