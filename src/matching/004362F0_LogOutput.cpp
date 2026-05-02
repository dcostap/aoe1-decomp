// VA: 004362F0 TDebuggingLog::LogOutput (54 B)
// PDB source: Debuglog.cpp lines 82-90

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
    void LogOutput(int value);
};

void __cdecl Log(TDebuggingLog* log, const char* format, const char* value);

void TDebuggingLog::LogOutput(int value) {
    if (value != 0) {
        this->LogToOutput = 1;
    } else {
        this->LogToOutput = 0;
    }
    Log(this, "Logging to OUTPUT %s", this->YesOrNo(value));
}
