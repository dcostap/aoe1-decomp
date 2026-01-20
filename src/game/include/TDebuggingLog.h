#pragma once
#include "common.h"

struct TDebuggingLog {
    int Timestamp;
    int DateTimestamp;
    int LogToFile;
    int LogToOutput;
    int Sequence;
    int Flush;
    int LogIsOpen;
    int LogError;
    ulong LogStartTickCount;
    ulong SeqNo;
    char TBuff[800];
    char osbuf[1000];
    char Filename[128];
};
static_assert(sizeof(TDebuggingLog) == 0x7B0, "Size mismatch");
