// VA: 004806D0 RGE_TimeSinceLastCall::GetElapsedFirstCall
// PDB source: RGE_TSLC.cpp
// Returns time since first call as "%02ld:%02ld:%02ld"

#include <stdio.h>

extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);

class RGE_TimeSinceLastCall {
public:
    char TBuff[0x100];
    unsigned long lowTSLC;
    unsigned long highTSLC;
    unsigned long TSLC;
    unsigned long aTSLC[100];
    char gap_29C_29F[4];
    int Offset;
    unsigned long LastCall;         // +0x2A4
    unsigned long FirstCall;        // +0x2A8
    unsigned long Now;              // +0x2AC

    char* GetElapsedFirstCall();
};

char* RGE_TimeSinceLastCall::GetElapsedFirstCall()
{
    unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp", 0xB5);
    unsigned long elapsed = (now - FirstCall) / 1000;

    Now = now;

    unsigned long hours = 0;
    unsigned long minutes = 0;

    if (elapsed > 59) {
        minutes = elapsed / 60;
        elapsed = elapsed - minutes * 60;
        if (minutes > 59) {
            hours = minutes / 60;
            minutes = minutes - hours * 60;
        }
    }

    sprintf(TBuff, "%02ld:%02ld:%02ld", hours, minutes, elapsed);

    return TBuff;
}
