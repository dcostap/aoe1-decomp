// VA: 004363A0 TDebuggingLog::Time
// Debuglog.cpp lines 114-129

// attempt 1-3: natural implementation
// 132/132 bytes exact size, 10 diff bytes
// Remaining: inverted branch (je vs jne) for timeinfo NULL check // VC5 codegen basin issue

#include <time.h>

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

    void Log(const char* format, ...);
    void Time();
};

unsigned long debug_timeGetTime(const char* file, int line);

void TDebuggingLog::Time() {
    unsigned long ticks = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Debuglog.cpp", 0x78);
    time_t ltime;
    time(&ltime);
    struct tm* timeinfo = localtime(&ltime);
    
    float elapsed = (float)(ticks - LogStartTickCount) * 0.001f;
    
    const char* timestr;
    if (timeinfo != 0) {
        timestr = asctime(timeinfo);
    } else {
        timestr = "?";
    }
    Log(">>>TIME>>>  %s   [%7.1f sec. elapsed]", timestr, (double)elapsed);
}
