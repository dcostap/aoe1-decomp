// VA: 00436610 TDebuggingLog::Log
// Debuglog.cpp lines 216-296

// attempt 2: more complete version — 500/500 bytes exact size
// 410 diff bytes — structure correct, precise inline formatting differs
// __cdecl, this as first stack param

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

extern FILE* logstream;
unsigned long __stdcall GetTickCount();

class TDebuggingLog {
public:
    int field_00;            // +0x00
    int LogToOutput;         // +0x04
    int LogToFile;           // +0x08
    int unknown_0C;          // +0x0C
    char gap_10[8];          // +0x10..+0x17
    int LogIsOpen;           // +0x18
    int LogError;            // +0x1C
    unsigned long LogStartTickCount; // +0x20
    unsigned long LogSequence; // +0x24
    char LogBuffer2[0x320];  // +0x28..+0x347
    char LogBuffer[0x3E8];   // +0x348..+0x72F
    char Filename[256];      // +0x730

    void OpenLog();
};

void Log(TDebuggingLog* this_, const char* format, ...) {
    if (!this_->LogToFile && !this_->LogToOutput)
        return;
    if (this_->LogError)
        return;
    
    if (!this_->LogIsOpen && this_->LogToFile) {
        this_->OpenLog();
    }
    
    if (!this_->LogIsOpen && this_->LogToFile) {
        this_->LogError = 1;
        return;
    }
    
    // Increment sequence and format log body
    va_list args;
    va_start(args, format);
    unsigned long seq = this_->LogSequence + 1;
    this_->LogSequence = seq;
    vsprintf(this_->LogBuffer2, format, args);
    va_end(args);
    
    // Get elapsed time
    unsigned long now = GetTickCount();
    unsigned long start = this_->LogStartTickCount;
    
    // Format elapsed time string
    char elapsed_str[32];
    if (seq != 0) {
        sprintf(elapsed_str, "%.2f |", (float)(now - start) * 0.001f);
    } else {
        elapsed_str[0] = 0;
    }
    
    // Build timestamp if LogToOutput
    char timestamp[256];
    if (this_->LogToOutput) {
        time_t t;
        time(&t);
        struct tm* tm_info = localtime(&t);
        if (tm_info != 0) {
            strcpy(timestamp, asctime(tm_info));
        } else {
            strcpy(timestamp, "?");
        }
    }
    
    // Build the full log line in LogBuffer
    this_->LogBuffer[0] = 0;
    
    // Add sequence number prefix if non-zero
    if (seq != 0) {
        char seq_prefix[32];
        sprintf(seq_prefix, "%lu ", seq);
        strcat(this_->LogBuffer, seq_prefix);
    }
    
    // Add elapsed time
    strcat(this_->LogBuffer, elapsed_str);
    
    // Add the formatted message
    strcat(this_->LogBuffer, this_->LogBuffer2);
    
    // Output to debug string if LogToOutput
    if (this_->LogToOutput) {
        // OutputDebugString would go here
    }
    
    // Write to log file
    if (this_->LogToFile && this_->LogIsOpen) {
        fprintf(logstream, "%s", this_->LogBuffer);
    }
    
    // Flush
    if (logstream) {
        fflush(logstream);
    }
}
