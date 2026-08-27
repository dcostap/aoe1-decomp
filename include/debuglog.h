#ifndef AOE1_DEBUGLOG_H
#define AOE1_DEBUGLOG_H

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
    unsigned long LogStartTickCount;
    unsigned long SeqNo;
    char TBuff[800];
    char osbuf[1000];
    char Filename[128];

    TDebuggingLog();
    ~TDebuggingLog();
    void __cdecl Log(char* format, ...);
    void LogFile(int value);
    void LogOutput(int value);
    void LogTimestamp(int value);
    void LogDateTimestamp(int value);
    void Time();
    void FlushToDisk(int value);
    void LogSequence(int value);
    void OpenLog();
    void FlushLog();
    void CloseLog();

protected:
    char* YesOrNo(int value);
};

typedef char debuglog_TDebuggingLog_size_check[
    (sizeof(TDebuggingLog) == 0x7B0) ? 1 : -1];

#endif
