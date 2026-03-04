#pragma once
#include "common.h"

struct MsgQueue {
    MsgQueue();
    ~MsgQueue();
    void* vector_deleting_destructor(uint param_1);

    ulong Code;
    ulong ExecTurn;
    uchar SeqNo;
    char* msgptr;
    uint From;
    uint Size;
    int ControlCommand;
};
static_assert(sizeof(MsgQueue) == 0x1C, "Size mismatch");
