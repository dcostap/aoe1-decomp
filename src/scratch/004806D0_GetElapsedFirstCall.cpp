// VA: 004806D0 RGE_TimeSinceLastCall::GetElapsedFirstCall
// PDB source: RGE_TSLC.cpp
// Returns time since first call as "%02ld:%02ld:%02ld"
// Retry 2026-05-19/20 assigned pass:
// - Revalidated inherited source: size-gated at 144B vs configured 150B.
// - Moved Now store before elapsed calculation: still size-gated.
// - Tried /G5 flag and register hour/minute locals: still size-gated; flag removed.
// - Switched minute/hour division to signed long casts: reached exact 150B, but still MISMATCH 24.0000% positional / 10.6667% edit. This fixed signed `imul` / `sar` division family but left setup/register allocation drift: original zeroes EBX/ESI before debug_timeGetTime and keeps elapsed in ECX; rebuilt delays zeroing and briefly uses ESI for FirstCall.
// STOP per Boss request: leaving in scratch. No accepted_drift proposed; remaining drift is broad early scheduling/register allocation, not localized.

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
    Now = now;
    unsigned long elapsed = (now - FirstCall) / 1000;

    long hours = 0;
    long minutes = 0;

    if (elapsed > 59) {
        minutes = (long)elapsed / 60;
        elapsed = elapsed - minutes * 60;
        if (minutes > 59) {
            hours = minutes / 60;
            minutes = minutes - hours * 60;
        }
    }

    sprintf(TBuff, "%02ld:%02ld:%02ld", hours, minutes, elapsed);

    return TBuff;
}
