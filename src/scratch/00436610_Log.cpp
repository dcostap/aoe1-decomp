// VA: 00436610 TDebuggingLog::Log
// Debuglog.cpp lines 216-296
//
// Attempt log:
// - Baseline kept the old decompiler-shaped formatting model; it had a 0x148
//   frame and the wrong ctime/output/file call set.
// - Reconstructed the period Debuglog.cpp field ownership and the natural
//   four-prefix variadic formatting sequence from the original call sites.
// - The first natural reconstruction reached the exact 0x8C frame and all 12
//   calls; its remaining structural gap was the timestamp expression lifetime
//   and compiler-local prefix placement.
// - Hoisting the elapsed expression recovered the original FPU branch shape;
//   the remaining stack windows indicate that ltime must be allowed to reuse
//   the first date-prefix word.
// - The oracle carries one TBuff pointer in EBX from the varargs call through
//   the final sprintf; keep that ordinary array pointer as a local.
// - A declaration-order lab (all 24 permutations) emitted one codegen group;
//   making ltime block-local instead recovered all four date/prefix stack
//   displacements and the original 500-byte extent.
// - Best current check: 14 differing bytes, all 12 calls/relocations aligned;
//   remaining mismatch is the original 0x8C frame versus rebuilt 0x88 and its
//   resulting prologue/stack displacement bytes. Left in scratch at budget.
// - The exact 0041A100 varargs donor uses the direct parameter-home address;
//   both direct-cast spellings were codegen duplicates here.
// - Swapping the two anonymous prefix roles preserved sequence-then-">"
//   output and reduced the best diff from 14 to 12 bytes. Declaration order
//   did not change that result.
// - Hoisting ltime made the 0x8C frame exact but caused a 503-byte structural
//   drift; the explicit dead-prefix-word model was also a duplicate. Restored
//   the natural block-local ltime candidate.
// - Hoisting long ltime immediately before the prefix arrays reproduced the
//   0x8C frame but expanded the body to 503 bytes and 310 differing bytes;
//   restored the block-local candidate.
// - Moving prefix declarations to function entry was a codegen duplicate.
// - Top-level ltime, packed/recorded ltime-plus-prefix storage, and an
//   explicit qword frame record all kept a 503-byte structural drift or
//   enlarged the frame; none preserved the clean 500-byte body.
// - A 28-byte prefix-size probe shrank the frame to 0x7C and widened the
//   mismatch; restored the 32-byte arrays. Current best remains diff 12,
//   with all calls aligned and only stack/local topology unresolved.

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

extern FILE* logstream;
extern "C" unsigned long (__stdcall* const GetTickCount)(void);
extern "C" void (__stdcall* const OutputDebugStringA)(const char*);

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
    char s2[32];
    char s3[32];
    char s4[32];
    char s1[32];

    float fTicksElapsed =
        ((float)ticks - (float)this->LogStartTickCount) * 0.001f;

    s1[4] = s2[4] = s3[4] = s4[4] = 0;

    if (this->Timestamp != 0) {
        sprintf(s1 + 4, "%.2f |", (double)fTicksElapsed);
    }

    if (this->DateTimestamp != 0) {
        long ltime;
        time(&ltime);
        strncat(s2 + 4, ctime(&ltime), 20);
        strcat(s2 + 4, " |");
    }

    if (this->Sequence != 0) {
        sprintf(s4 + 4, "%ld |", this->SeqNo);
    }

    strcpy(s3 + 4, ">");
    sprintf(this->osbuf, "%s%s%s%s%s\n", s1 + 4, s2 + 4, s4 + 4,
            s3 + 4, buffer);

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
