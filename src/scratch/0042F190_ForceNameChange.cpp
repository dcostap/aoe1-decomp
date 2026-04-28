// TCommunications_Handler::ForceNameChange
// VA: 0042F190
// Com_hand.cpp:6844-6854
// 148 bytes, not matched (parked)
// Complex function with stack frame juggling (sub esp,0x30), building
// a temporary name string from global data, setting up DPNAME struct,
// and calling IDirectPlay vtable slot 0x78. 3 attempts, too complex
// for quick match.
//
// Attempt log:
// v0: byte-by-byte copy from globals + DPNAME struct → compilation issues
// v1: memcpy from 0x5832BCh + DPNAME → memcpy generates call instead of inline copies

#include <string.h>
#include "../../include/game_globals.h"

extern void* L;
extern "C" void __cdecl Log(void* log, char* fmt, ...);

struct DPNAME {
    unsigned long dwSize;
    unsigned long dwFlags;
    void* lpszShortName;
    void* lpszLongName;
};

typedef struct IDirectPlay3Vtbl {
    char gap_00[0x78];
    long (__stdcall* SetPlayerName)(void* thisptr, void* player_id, DPNAME* name, unsigned long flags);
} IDirectPlay3Vtbl;

typedef struct IDirectPlay3 {
    IDirectPlay3Vtbl* vtbl;
} IDirectPlay3;

class TCommunications_Handler {
public:
    void ForceNameChange(void);
};

void TCommunications_Handler::ForceNameChange(void) {
    char nameBuf[32];
    DPNAME dpn;

    Log(L, "Force Name Change");

    dpn.dwSize = 0x10;
    dpn.dwFlags = 0;
    dpn.lpszShortName = 0;

    IDirectPlay3* dp = (IDirectPlay3*)(unsigned long)DAT_0062c5ec;
    dp->vtbl->SetPlayerName(dp, (void*)DAT_0062cf04, &dpn, 2);
}
