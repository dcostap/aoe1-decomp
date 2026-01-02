#pragma once
#include "../common.h"

class RGE_Communications_Synchronize {
public:
    ulong CheckTime;                         // 0x4
    ulong CheckTurn;                         // 0x8
    int StopOnSyncFail;                      // 0xC
    int DialogOnSyncFail;                    // 0x10
    int SendChatMsgs;                        // 0x14
    int NewData;                             // 0x18
    int LastResult;                          // 0x1C
    uint Offset;                             // 0x20
    int DoChecksums;                         // 0x24
    ulong LastWorldRandom;                   // 0x28
    ulong GameWorldChecksum;                 // 0x2C
    CHECKSUMARRAY Check[55];                 // 0x30

    RGE_Communications_Synchronize(TCommunications_Handler* param_1);
    virtual ~RGE_Communications_Synchronize();
    virtual int Add(uint param_1, ulong param_2, ulong param_3, ulong param_4, long param_5, long param_6, long param_7, long param_8, long param_9);
    virtual int ValidateChecksums(uint param_1, ulong param_2, ulong param_3, ulong param_4, long param_5, long param_6, long param_7, long param_8, long param_9);
    virtual ulong DoChecksum(ulong param_1);
    virtual void SetLastWorldRandom(ulong param_1);
    virtual void LogChecksums(uint param_1, ulong param_2, ulong param_3, long param_4, long param_5, long param_6, long param_7, long param_8, ulong param_9);
    virtual void EnableSyncChecking(int param_1);
    virtual void SetStopOnFail(int param_1);
    virtual void SetDialogOnFail(int param_1);
    virtual void SendChatMsgsAtChecksum(int param_1);
    virtual int IsPlayerOutOfSync(uint param_1, ulong param_2);
};

static_assert(sizeof(RGE_Communications_Synchronize) == 0x7EC, "RGE_Communications_Synchronize Size Mismatch");
static_assert(offsetof(RGE_Communications_Synchronize, Check) == 0x30, "RGE_Communications_Synchronize Offset Mismatch");

