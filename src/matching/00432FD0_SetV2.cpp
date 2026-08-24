class TDebuggingLog;

extern TDebuggingLog* L;
extern "C" void __cdecl Log(TDebuggingLog* log, const char* format, unsigned long value);

#include "../../include/com_spd_context.h"

void RGE_Communications_Speed::SetV2(unsigned long value) {
    Log(L, "Speed set V2=%d", value);
}
