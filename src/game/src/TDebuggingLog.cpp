#include <windows.h>
#include "../include/TDebuggingLog.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")

static FILE* logstream = NULL;

TDebuggingLog::TDebuggingLog() {
    this->LogToFile = 0;
    this->LogToOutput = 0;
    this->LogError = 0;
    this->LogIsOpen = 0;
    this->Sequence = 0;
    this->Flush = 0;
    this->Timestamp = 0;
    this->DateTimestamp = 0;
    this->LogStartTickCount = 0;
    this->SeqNo = 0;

    this->LogSequence(0);
    this->LogTimestamp(0);
    this->LogDateTimestamp(0);
    this->FlushToDisk(0);

    this->OpenLog();
    this->Log("===Logging===");
    this->Time();

    strcpy(this->Filename, "C:\\APPLOGERR.TXT");
}

TDebuggingLog::~TDebuggingLog() {
    this->CloseLog();
}

void TDebuggingLog::LogFile(int enable) {
    this->LogToFile = (enable != 0);
    this->Log("Logging to File %s", this->YesOrNo(enable));
}

void TDebuggingLog::LogOutput(int enable) {
    this->LogToOutput = (enable != 0);
    this->Log("Logging to OUTPUT %s", this->YesOrNo(enable));
}

void TDebuggingLog::LogTimestamp(int enable) {
    this->Timestamp = (enable != 0);
    this->Log("Timestamp milliseconds %s", this->YesOrNo(enable));
}

void TDebuggingLog::LogDateTimestamp(int enable) {
    this->DateTimestamp = (enable != 0);
    this->Log("Date & Time stamp%s", this->YesOrNo(enable));
}

void TDebuggingLog::LogSequence(int enable) {
    if (enable) {
        this->Sequence = 1;
        this->SeqNo = 0;
    } else {
        this->Sequence = 0;
    }
    this->Log("Sequence numbering%s", this->YesOrNo(enable));
}

void TDebuggingLog::FlushToDisk(int enable) {
    this->Flush = (enable != 0);
    this->Log("Flush queue each message %s", this->YesOrNo(enable));
}

const char* TDebuggingLog::YesOrNo(int val) {
    return val ? " is now ACTIVE." : " has been deactivated.";
}

void TDebuggingLog::OpenLog() {
    if (!this->LogToFile) return;
    if (this->LogIsOpen && this->LogError) return;

    this->LogStartTickCount = GetTickCount();

    char path[128];
    for (int i = 1; i <= 25; ++i) {
        if (i == 1) {
            strcpy(path, "C:\\AOELOG.txt");
        } else {
            sprintf(path, "C:\\AOELOG%.2d.txt", i - 1);
        }

        logstream = fopen(path, "wt");
        if (logstream) {
            this->LogIsOpen = 1;
            strcpy(this->Filename, path);
            this->Log("Log file %s is opened", this->Filename);
            this->Time();
            return;
        }
    }

    this->LogError = 1;
    this->LogIsOpen = 0;
}

void TDebuggingLog::CloseLog() {
    if (this->LogToFile) {
        if (this->Filename[0]) {
            this->Log("Closing debug log file '%s'.", this->Filename);
        }
        this->Time();
        this->Log("Log file is closed");
        if (logstream) {
            fclose(logstream);
            logstream = NULL;
        }
        this->LogIsOpen = 0;
    }
}

void TDebuggingLog::FlushLog() {
    if (this->LogToFile && logstream) {
        fflush(logstream);
    }
}

void TDebuggingLog::Time() {
    DWORD ticks = GetTickCount();
    time_t now = time(NULL);
    struct tm* t = localtime(&now);

    float elapsed = (float)(ticks - this->LogStartTickCount) / 1000.0f;
    const char* time_str = t ? asctime(t) : "?";
    
    // Trim newline from asctime
    char temp_time[64];
    if (t) {
        strcpy(temp_time, asctime(t));
        char* nl = strchr(temp_time, '\n');
        if (nl) *nl = '\0';
    } else {
        strcpy(temp_time, "?");
    }

    this->Log(">>>TIME>>>  %s   [%7.1f sec. elapsed]", temp_time, elapsed);
}

void TDebuggingLog::Log(const char* format, ...) {
    if (!this->LogToFile && !this->LogToOutput) return;
    if (this->LogError) return;

    if (!this->LogIsOpen && this->LogToFile) {
        this->OpenLog();
    }

    if (this->LogToFile && !this->LogIsOpen) {
        this->LogError = 1;
        return;
    }

    va_list args;
    va_start(args, format);
    vsprintf(this->TBuff, format, args);
    va_end(args);

    this->SeqNo++;

    char time_buf[32] = "";
    char date_buf[64] = ""; // Increased size for ctime
    char seq_buf[32] = "";

    if (this->Timestamp) {
        sprintf(time_buf, "%.2f |", (float)(GetTickCount() - this->LogStartTickCount) / 1000.0f);
    }

    if (this->DateTimestamp) {
        time_t now = time(NULL);
        char* ct = ctime(&now);
        if (ct) {
            strncpy(date_buf, ct, 24);
            date_buf[24] = '\0';
            strcat(date_buf, " | ");
        }
    }

    if (this->Sequence) {
        sprintf(seq_buf, "%ld |", this->SeqNo);
    }

    sprintf(this->osbuf, "%s%s%s%s\n", time_buf, date_buf, seq_buf, this->TBuff);

    if (this->LogToOutput) {
        OutputDebugStringA(this->osbuf);
    }

    if (this->LogToFile && logstream) {
        fputs(this->osbuf, logstream);
        if (this->Flush) {
            fflush(logstream);
        }
    }
}
