#pragma once
#include "../common.h"

class TDebuggingLog       {
public:
    int Timestamp;                           // 0x0
    int DateTimestamp;                       // 0x4
    int LogToFile;                           // 0x8
    int LogToOutput;                         // 0xC
    int Sequence;                            // 0x10
    int Flush;                               // 0x14
    int LogIsOpen;                           // 0x18
    int LogError;                            // 0x1C
    ulong LogStartTickCount;                 // 0x20
    ulong SeqNo;                             // 0x24
    char TBuff[800];                         // 0x28
    char osbuf[1000];                        // 0x348
    char Filename[128];                      // 0x730

    TDebuggingLog();

    // --- Non-Virtual Destructor ---
    ~TDebuggingLog() noexcept(false);
    // --- Non-Virtual Members ---
    void LogFile(int param_1);
    void LogOutput(int param_1);
    void LogTimestamp(int param_1);
    void LogDateTimestamp(int param_1);
    void Time();
    void FlushToDisk(int param_1);
    void LogSequence(int param_1);
    void OpenLog();
    void FlushLog();
    void CloseLog();
    void Log(char* param_1);
    char* YesOrNo(int param_1);
};

static_assert(sizeof(TDebuggingLog) == 0x7B0, "TDebuggingLog Size Mismatch");
static_assert(offsetof(TDebuggingLog, Filename) == 0x730, "TDebuggingLog Offset Mismatch");

