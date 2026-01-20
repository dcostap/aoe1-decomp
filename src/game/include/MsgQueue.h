#pragma once
#include "common.h"

struct MsgQueue {
    ulong Code;
    ulong ExecTurn;
    uchar SeqNo;
    char* msgptr;
    uint From;
    uint Size;
    int ControlCommand;
};
static_assert(sizeof(MsgQueue) == 0x1C, "Size mismatch");
