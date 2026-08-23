// VA: 004364B0 TDebuggingLog::OpenLog
// Debuglog.cpp lines 156-191

// attempt 1: natural implementation

#include <stdio.h>
#include <string.h>

#ifndef DEBUGLOG_CANONICAL_TU
class TDebuggingLog {
public:
    char gap_00[8];
    int LogToFile;
    int LogToOutput;
    char gap_10[8];
    int LogIsOpen;
    int LogError;
    unsigned long LogStartTickCount;
    char gap_24[0x70C];
    char Filename[256];

    void __cdecl Log(char* format, ...);
    void Time();
    void OpenLog();
};
#endif

unsigned long debug_timeGetTime(const char* file, int line);

FILE* logstream;

void TDebuggingLog::OpenLog() {
    if (!LogToFile) return;
    if (LogIsOpen && !LogError) return;
    
    LogStartTickCount = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Debuglog.cpp", 0xA3);
    
    for (int i = 1; i <= 25; i++) {
        char* filename = Filename;
        
        if (i == 1) {
            strcpy(Filename, "C:\\AOELOG.txt");
        } else {
            sprintf(Filename, "C:\\AOELOG%.2d.txt", i - 1);
        }
        
        logstream = fopen(Filename, "wt");
        
        if (logstream != 0) {
            LogIsOpen = 1;
            Log("Log file %s is opened", Filename);
            Time();
            return;
        }
    }
    
    LogError = 1;
    LogIsOpen = 0;
}
