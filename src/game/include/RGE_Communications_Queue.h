#pragma once
#include "common.h"

struct RGE_Communications_Queue {
    uint QueueDepth;
    uint HighQueueDepth;
    uint MaxQSize;
    char TBuff[255];
    ulong LastCurrentTurn;
    uchar Sequence;
    MsgQueue* Queue;
};
static_assert(sizeof(RGE_Communications_Queue) == 0x118, "Size mismatch");
