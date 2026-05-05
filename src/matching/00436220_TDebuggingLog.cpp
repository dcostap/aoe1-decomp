// VA: 00436220 TDebuggingLog::TDebuggingLog
// Debuglog.cpp lines 45-62

// attempt 1: natural constructor
// 123/123 bytes exact size match, 47 diff bytes
// Remaining: strcpy inline instruction alignment differs slightly
// Store order + struct layout corrected. Left in scratch.

#include <string.h>

class TDebuggingLog {
public:
    char gap_00[8];             // +0x00..+0x07 (vtable? + unknown)
    int LogToFile;              // +0x08
    int LogToOutput;            // +0x0C
    char gap_10[8];             // +0x10..+0x17
    int LogIsOpen;              // +0x18
    int LogError;               // +0x1C
    unsigned long LogStartTickCount; // +0x20
    char gap_24[0x70C];         // +0x24..+0x72F (buffer for logs?)
    char Filename[256];         // +0x730

    void LogSequence(int param);
    void LogTimestamp(int param);
    void LogDateTimestamp(int param);
    void FlushToDisk(int param);
    void OpenLog();
    void Time();

    TDebuggingLog();
};

extern int logstream;
extern void __cdecl Log(TDebuggingLog* self, const char* text);

TDebuggingLog::TDebuggingLog() {
    LogToFile = 0;
    LogToOutput = 0;
    LogError = 0;
    LogIsOpen = 0;
    LogSequence(0);
    LogTimestamp(0);
    LogDateTimestamp(0);
    FlushToDisk(0);
    OpenLog();
    Log(this, "===Logging===");
    Time();
    strcpy(Filename, "C:\\APPLOGERR.TXT");
}
