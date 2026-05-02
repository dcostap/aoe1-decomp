// VA: 004362B0 TDebuggingLog::LogFile (54 B)
// PDB source: Debuglog.cpp lines 71-79

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

    char* YesOrNo(int value);
    void LogFile(int value);
};

void __cdecl Log(TDebuggingLog* log, const char* format, const char* value);

void TDebuggingLog::LogFile(int value) {
    if (value != 0) {
        this->LogToFile = 1;
    } else {
        this->LogToFile = 0;
    }
    Log(this, "Logging to File %s", this->YesOrNo(value));
}
