#include <stdio.h>

extern FILE* logstream;

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

    void Time(void);
    void Log(char* format, ...);

    void CloseLog(void);
};
#endif

// compact debug-log closer first
// expected basin: one LogToFile guard, optional filename-message log, Time(), close-message log, fclose(logstream), then LogIsOpen = 0
// if this misses, the remaining gap is likely only the exact source spelling for the filename test / log call shape
void TDebuggingLog::CloseLog(void) {
    if (this->LogToFile != 0) {
        if (this->Filename != 0) {
            this->Log("Closing debug log file '%s'.", this->Filename);
        }
        this->Time();
        this->Log("Log file is closed");
        fclose(logstream);
        this->LogIsOpen = 0;
    }
}
