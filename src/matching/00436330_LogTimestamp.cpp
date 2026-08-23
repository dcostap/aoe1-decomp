// LogTimestamp (00436330) - TDebuggingLog::LogTimestamp
// Debuglog.cpp:93-100

#ifndef DEBUGLOG_CANONICAL_TU
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

protected:
    char* YesOrNo(int value);
public:
    void CloseLog();
    void FlushLog();
    void FlushToDisk(int value);
    void LogDateTimestamp(int value);
    void LogFile(int value);
    void LogOutput(int value);
    void LogSequence(int value);
    void LogTimestamp(int value);
    void __cdecl Log(char* format, ...);
    void OpenLog();
    void Time();
    TDebuggingLog();
    ~TDebuggingLog();
};
#endif

void TDebuggingLog::LogTimestamp(int value) {
    if (value != 0) {
        this->Timestamp = 1;
    } else {
        this->Timestamp = 0;
    }
    this->Log("Timestamp milliseconds %s", this->YesOrNo(this->Timestamp));
}
