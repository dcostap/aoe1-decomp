#pragma once
#include "common.h"
#include "CHECKSUMARRAY.h"

struct RGE_Communications_Synchronize {
    RGE_Communications_Synchronize(TCommunications_Handler* comm);
    ~RGE_Communications_Synchronize();

    int Add(uint player_no, ulong world_time, ulong comm_turn, ulong random, long cs1, long cs2, long cs3, long cs4,
            long cs5);
    ulong DoChecksum(ulong comm_turn);
    void SetLastWorldRandom(ulong v);
    void LogChecksums(uint player_no, ulong world_time, ulong comm_turn, long cs1, long cs2, long cs3, long cs4, long cs5,
                      ulong random);
    void EnableSyncChecking(int enable);
    void SetStopOnFail(int stop);
    void SetDialogOnFail(int dialog);
    void SendChatMsgsAtChecksum(int enable);
    int IsPlayerOutOfSync(uint player_no, ulong comm_turn);

    int ValidateChecksums(uint player_no, ulong world_time, ulong comm_turn, ulong random, long cs1, long cs2, long cs3, long cs4,
                          long cs5);

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
