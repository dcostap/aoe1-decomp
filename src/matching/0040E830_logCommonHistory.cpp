// VA: 0040E830 AIModule::logCommonHistory
// aimodule.cpp lines 964-985
// Fresh 2026-05-19: real varargs common-history logging implementation.

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

class AIModule {
public:
    char gap_00[0x0c];
    char name[0x40];
    int playerID; // +0x4c

    void logCommonHistory(char* fmt, ...);
};

void AIModule::logCommonHistory(char* fmt, ...)
{
    char textOut[1024];

    if (*(int*)0x57F9FC != -1 && *(int*)0x57F9FC != this->playerID) {
        return;
    }
    if (*(FILE**)0x592A44 == 0) {
        return;
    }

    va_list args;
    va_start(args, fmt);
    vsprintf(textOut, fmt, args);
    va_end(args);

    if (strlen(textOut) != 0) {
        fprintf(*(FILE**)0x592A44, "P#%d %s: %s\n", this->playerID, this->name, textOut);
    } else {
        fprintf(*(FILE**)0x592A44, "P#%d\n", this->playerID);
    }
    fflush(*(FILE**)0x592A44);
}
