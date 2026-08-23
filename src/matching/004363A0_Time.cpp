// 004363A0 TDebuggingLog::Time
// Debuglog.cpp:114-129, 132 bytes
// FLAGS: default
//
// Fixed: swapped if/else arm order. Original checks `timeinfo == 0` so the
// "?" path is fall-through (branch-taken = asctime). The previous code had
// `if (timeinfo != 0)` which inverted the branch (je vs jne).

#include <time.h>

#ifndef DEBUGLOG_CANONICAL_TU
class TDebuggingLog {
public:
    char gap_00[8];
    int LogToFile;
    int LogToOutput;
    char gap_10[8];
    int LogIsOpen;
    int LogError;
    unsigned long LogStartTickCount; // +0x20
    char gap_24[0x70C];
    char Filename[256];

    void __cdecl Log(char* format, ...);
    void Time();
};
#endif

unsigned long debug_timeGetTime(const char* file, int line);

void TDebuggingLog::Time() {
    unsigned long ticks = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Debuglog.cpp", 0x78);
    time_t ltime;
    time(&ltime);
    struct tm* timeinfo = localtime(&ltime);
    
    float elapsed = (float)(ticks - LogStartTickCount) * 0.001f;
    
    const char* timestr;
    if (timeinfo == 0) {
        timestr = "?";
    } else {
        timestr = asctime(timeinfo);
    }
    Log(">>>TIME>>>  %s   [%7.1f sec. elapsed]", timestr, (double)elapsed);
}
