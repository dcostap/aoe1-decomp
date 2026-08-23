#include <stdio.h>

extern FILE* logstream;

// Exact-finish: the prior SomeClass owner emitted the same instructions but
// failed the qualified-owner check. The PDB owner is TDebuggingLog::FlushLog.
#ifndef DEBUGLOG_CANONICAL_TU
class TDebuggingLog {
public:
    void FlushLog();
    char gap_00[0x08];
    int LogToFile;
};
#endif
void TDebuggingLog::FlushLog() {
    if (this->LogToFile) {
        fflush(logstream);
    }
}
