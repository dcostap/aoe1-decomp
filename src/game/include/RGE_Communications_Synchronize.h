#pragma once
#include "common.h"
#include "CHECKSUMARRAY.h"

struct RGE_Communications_Synchronize {
    TCommunications_Handler* Comm;
    ulong CheckTime;
    ulong CheckTurn;
    int StopOnSyncFail;
    int DialogOnSyncFail;
    int SendChatMsgs;
    int NewData;
    int LastResult;
    uint Offset;
    int DoChecksums;
    ulong LastWorldRandom;
    ulong GameWorldChecksum;
    CHECKSUMARRAY Check[55];
};
static_assert(sizeof(RGE_Communications_Synchronize) == 0x7EC, "Size mismatch");
