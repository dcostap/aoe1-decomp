// VA: 0040E520 AIModule::setLogCommonHistory
// aimodule.cpp lines 365-379
// Retry 2026-05-19/20 assigned pass:
// - Replaced approximate g_logActive/g_logFile stub with real commonHistoryLogFile flow, fopen/time/localtime/asctime, and logCommonHistory calls.
// - Natural source reaches 149/149 with only one byte different: initial `on == 0` branch target goes to the `test ecx` at close-file check instead of the redundant `test eax` immediately before it.
// - Tried splitting nested `if (on)`, explicit `if (on != 0) return`, and checking `this->logCommonHistoryValue == 0`; no change.
// ACCEPTED_DRIFT 2026-05-19: approved one-byte behavior-equivalent branch-target drift.
// Original `je 0040E596` executes `test eax,eax` where eax is already known zero,
// then falls to `test ecx`; rebuilt `je 0040E59A` skips only that redundant test
// and executes the same `test ecx` close-file path. Same state, calls, cleanup,
// global writes, and memory effects.

#include <stdio.h>
#include <time.h>

extern FILE* commonHistoryLogFile;
extern char emptyString[];

#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    char gap_00[0x9C];
    int logCommonHistoryValue;

    void logCommonHistory(char* fmt, ...);
    void setLogCommonHistory(int on);
};
#endif

void AIModule::setLogCommonHistory(int on)
{
    this->logCommonHistoryValue = on;
    FILE* f = commonHistoryLogFile;
    if (on != 0) {
        if (f == 0) {
            commonHistoryLogFile = fopen("c:\\aoeai.txt", "wa");
            time_t t;
            time(&t);
            this->logCommonHistory("Common AI History File Started %s", asctime(localtime(&t)));
            this->logCommonHistory(emptyString);
            return;
        }
    }
    if (this->logCommonHistoryValue == 0) {
        if (f != 0) {
            fclose(f);
            commonHistoryLogFile = 0;
        }
    }
}
