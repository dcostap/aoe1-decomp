#pragma once
#include "common.h"

class TDebuggingLog {
public:
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

    TDebuggingLog();
    ~TDebuggingLog();
    void LogFile(int enable);
    void LogOutput(int enable);
    void LogTimestamp(int enable);
    void LogDateTimestamp(int enable);
    void LogSequence(int enable);
    void FlushToDisk(int enable);
    void OpenLog();
    void CloseLog();
    void FlushLog();
    void Time();
    void Log(const char* format, ...);
    const char* YesOrNo(int val);
};
static_assert(sizeof(TDebuggingLog) == 0x7B0, "Size mismatch");
