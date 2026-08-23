#ifndef AOE1_DEBUGLOG_CONTEXT_H
#define AOE1_DEBUGLOG_CONTEXT_H

// Canonical Debuglog.cpp class surface from the PDB type dump.
// Size: 0x7B0. The owner wrappers use this declaration for all module owners.
class TDebuggingLog {
public:
    int Timestamp;                         // +0x00
    int DateTimestamp;                     // +0x04
    int LogToFile;                          // +0x08
    int LogToOutput;                        // +0x0C
    int Sequence;                           // +0x10
    int Flush;                              // +0x14
    int LogIsOpen;                          // +0x18
    int LogError;                           // +0x1C
    unsigned long LogStartTickCount;        // +0x20
    unsigned long SeqNo;                    // +0x24
    char TBuff[800];                         // +0x28
    char osbuf[1000];                       // +0x348
    char Filename[128];                     // +0x730

    TDebuggingLog();
    ~TDebuggingLog();
    void __cdecl Log(char* format, ...);
    void LogFile(int value);
    void LogOutput(int value);
    void LogTimestamp(int value);
    void LogDateTimestamp(int value);
    void Time(void);
    void FlushToDisk(int value);
    void LogSequence(int value);
    void OpenLog(void);
    void FlushLog(void);
    void CloseLog(void);

protected:
    char* YesOrNo(int value);
};

typedef char verify_debuglog_TDebuggingLog_size[
    (sizeof(TDebuggingLog) == 0x7B0) ? 1 : -1];

extern "C" unsigned long (__stdcall* const GetTickCount)(void);
extern "C" void (__stdcall* const OutputDebugStringA)(const char*);

#endif
