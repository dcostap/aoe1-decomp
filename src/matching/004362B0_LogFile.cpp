// VA: 004362B0 TDebuggingLog::LogFile (54 B)
// PDB source: Debuglog.cpp lines 71-79

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
    void __cdecl Log(char* format, ...);
    void LogFile(int value);
};
#endif

void TDebuggingLog::LogFile(int value) {
    if (value != 0) {
        this->LogToFile = 1;
    } else {
        this->LogToFile = 0;
    }
    this->Log("Logging to File %s", this->YesOrNo(value));
}
