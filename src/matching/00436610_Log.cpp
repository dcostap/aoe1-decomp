// VA: 00436610 TDebuggingLog::Log
// Debuglog.cpp lines 216-296
//
// Exact reconstruction notes:
// - The function uses four 32-byte prefix arrays and one function-scope time.
// - PDB data records ltime at -132 and s2/s3/s4/s1 at -128/-96/-64/-32.
// - Keep ltime before the four
//   prefix arrays, but use each prefix array base as the effective string
//   buffer. The target zero-store order requires s4 before s3 in the chain.
// - Walkback made ltime block-local, restored old +4 buffer pointers, and
//   changed the zero order. Each change lost exactness.

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

extern FILE* logstream;
extern "C" unsigned long (__stdcall* const GetTickCount)(void);
extern "C" void (__stdcall* const OutputDebugStringA)(const char*);

#ifndef DEBUGLOG_CANONICAL_TU
class TDebuggingLog {
public:
    int Timestamp;                         // +0x00
    int DateTimestamp;                     // +0x04
    int LogToFile;                         // +0x08
    int LogToOutput;                       // +0x0C
    int Sequence;                          // +0x10
    int Flush;                             // +0x14
    int LogIsOpen;                         // +0x18
    int LogError;                          // +0x1C
    unsigned long LogStartTickCount;       // +0x20
    unsigned long SeqNo;                   // +0x24
    char TBuff[800];                        // +0x28
    char osbuf[1000];                       // +0x348
    char Filename[128];                    // +0x730

    void OpenLog();
    void __cdecl Log(char* format, ...);
};
#endif

void __cdecl TDebuggingLog::Log(char* format, ...)
{
    if ((this->LogToFile == 0 && this->LogToOutput == 0) ||
        this->LogError != 0) {
        return;
    }

    if (this->LogIsOpen == 0 && this->LogToFile != 0) {
        this->OpenLog();
    }

    if (this->LogIsOpen == 0 && this->LogToFile != 0) {
        this->LogError = 1;
        return;
    }

    char* buffer = this->TBuff;
    ++this->SeqNo;
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

    float fTicksElapsed =
        ((float)ticks - (float)this->LogStartTickCount) * 0.001f;

    s1[0] = s2[0] = s4[0] = s3[0] = 0;

    if (this->Timestamp != 0) {
        sprintf(s1, "%.2f |", (double)fTicksElapsed);
    }

    if (this->DateTimestamp != 0) {
        time(&ltime);
        strncat(s2, ctime(&ltime), 20);
        strcat(s2, " |");
    }

    if (this->Sequence != 0) {
        sprintf(s4, "%ld |", this->SeqNo);
    }

    strcpy(s3, ">");
    sprintf(this->osbuf, "%s%s%s%s%s\n", s1, s2, s4, s3, buffer);

    if (this->LogToOutput != 0) {
        OutputDebugStringA(this->osbuf);
    }

    if (this->LogToFile != 0 && this->LogIsOpen != 0) {
        fputs(this->osbuf, logstream);
        if (this->Flush != 0) {
            fflush(logstream);
        }
    }
}
