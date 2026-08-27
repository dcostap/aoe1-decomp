#include "../include/debuglog.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

extern "C" unsigned long (__stdcall* const GetTickCount)(void);
extern "C" void (__stdcall* const OutputDebugStringA)(const char*);

unsigned long __cdecl debug_timeGetTime(const char* file, int line);

FILE* logstream;

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
    Log("===Logging===");
    Time();
    strcpy(Filename, "C:\\APPLOGERR.TXT");
}

TDebuggingLog::~TDebuggingLog() {
    CloseLog();
}

void TDebuggingLog::LogFile(int value) {
    if (value != 0) {
        LogToFile = 1;
    } else {
        LogToFile = 0;
    }
    Log("Logging to File %s", YesOrNo(value));
}

void TDebuggingLog::LogOutput(int value) {
    if (value != 0) {
        LogToOutput = 1;
    } else {
        LogToOutput = 0;
    }
    Log("Logging to OUTPUT %s", YesOrNo(value));
}

void TDebuggingLog::LogTimestamp(int value) {
    if (value != 0) {
        Timestamp = 1;
    } else {
        Timestamp = 0;
    }
    Log("Timestamp milliseconds %s", YesOrNo(Timestamp));
}

void TDebuggingLog::LogDateTimestamp(int value) {
    if (value != 0) {
        DateTimestamp = 1;
    } else {
        DateTimestamp = 0;
    }
    Log("Date & Time stamp%s", YesOrNo(Timestamp));
}

void TDebuggingLog::Time() {
    unsigned long ticks = debug_timeGetTime(
        "C:\\msdev\\work\\age1_x1\\Debuglog.cpp", 0x78);
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

void TDebuggingLog::FlushToDisk(int value) {
    if (value != 0) {
        Flush = 1;
    } else {
        Flush = 0;
    }
    Log("Flush queue each message %s", YesOrNo(Flush));
}

void TDebuggingLog::LogSequence(int value) {
    if (value != 0) {
        Sequence = 1;
        SeqNo = 0;
    } else {
        Sequence = 0;
    }
    Log("Sequence numbering%s", YesOrNo(Sequence));
}

void TDebuggingLog::OpenLog() {
    if (!LogToFile) {
        return;
    }
    if (LogIsOpen && !LogError) {
        return;
    }

    LogStartTickCount = debug_timeGetTime(
        "C:\\msdev\\work\\age1_x1\\Debuglog.cpp", 0xA3);

    for (int i = 1; i <= 25; i++) {
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

void TDebuggingLog::FlushLog() {
    if (LogToFile) {
        fflush(logstream);
    }
}

void TDebuggingLog::CloseLog() {
    if (LogToFile != 0) {
        if (Filename != 0) {
            Log("Closing debug log file '%s'.", Filename);
        }
        Time();
        Log("Log file is closed");
        fclose(logstream);
        LogIsOpen = 0;
    }
}

void __cdecl TDebuggingLog::Log(char* format, ...) {
    if ((LogToFile == 0 && LogToOutput == 0) || LogError != 0) {
        return;
    }

    if (LogIsOpen == 0 && LogToFile != 0) {
        OpenLog();
    }

    if (LogIsOpen == 0 && LogToFile != 0) {
        LogError = 1;
        return;
    }

    char* buffer = TBuff;
    ++SeqNo;
    va_list args;
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);

    unsigned long ticks = GetTickCount();
    long ltime;
    char s2[32];
    char s3[32];
    char s4[32];
    char s1[32];

    float elapsed = ((float)ticks - (float)LogStartTickCount) * 0.001f;

    s1[0] = s2[0] = s4[0] = s3[0] = 0;

    if (Timestamp != 0) {
        sprintf(s1, "%.2f |", (double)elapsed);
    }

    if (DateTimestamp != 0) {
        time(&ltime);
        strncat(s2, ctime(&ltime), 20);
        strcat(s2, " |");
    }

    if (Sequence != 0) {
        sprintf(s4, "%ld |", SeqNo);
    }

    strcpy(s3, ">");
    sprintf(osbuf, "%s%s%s%s%s\n", s1, s2, s4, s3, buffer);

    if (LogToOutput != 0) {
        OutputDebugStringA(osbuf);
    }

    if (LogToFile != 0 && LogIsOpen != 0) {
        fputs(osbuf, logstream);
        if (Flush != 0) {
            fflush(logstream);
        }
    }
}

char* TDebuggingLog::YesOrNo(int value) {
    if (value != 0) {
        return " is now ACTIVE.";
    }
    return " has been deactivated.";
}
