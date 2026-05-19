// TCommunications_Handler::ForceNameChange
// VA: 0042F190
// Com_hand.cpp:6844-6854
// Attempt log:
// try 1: natural DPNAME + local "TEMPORARY_NAME" buffer with cdecl log and stdcall COM vcall; compiler initialized buffer before log.
// try 2: move Log before local string initialization; optimizer still hoisted local stores before call.
// try 3: make name buffer volatile to pin stores after Log; no change.
// try 4: declare Log variadic like project-local logging surface; no change.
// try 5: add missing DAT_005832bc/c4 globals and read non-const global string chunks after Log; still hoisted.
// try 6: cast name global reads through volatile pointers; still hoisted.
// try 7: put Log in comma expression feeding first name store; optimizer still schedules local name/DPNAME setup before log.
// tried transient /Od flag: body 130 bytes with EBP/debug basin, not useful; removed flag.
// GIVEUP: behavior surface understood (Log, build DPNAME with TEMPORARY_NAME, DirectPlay SetPlayerName). Remaining blocker is VC5 scheduling/stack-overlap shape: original calls Log first, delays cdecl cleanup, then initializes overlapping local string/DPNAME slots; rebuilt under /O2 keeps same 0x30 frame and final COM call but hoists local initialization before Log and compacts to 128 bytes. Not proposing accepted_drift because call/order and stack-write schedule differ broadly.

#include "../../include/game_globals.h"

extern void* L;
extern "C" void __cdecl Log(void* log, char* text, ...);

struct DPNAME {
    unsigned long dwSize;
    unsigned long dwFlags;
    char* lpszShortName;
    char* lpszLongName;
};

struct IDirectPlayVtbl {
    void* gap[0x78 / 4];
    long (__stdcall* SetPlayerName)(void* self, void* player, DPNAME* name, unsigned long flags);
};

struct IDirectPlay {
    IDirectPlayVtbl* vtbl;
};

class TCommunications_Handler {
public:
    void ForceNameChange(void);
};

void TCommunications_Handler::ForceNameChange(void) {
    volatile char test[32];
    DPNAME dpn;

    *(int*)&test[0] = (Log(L, "Force Name Change"), *(volatile unsigned int*)&DAT_005832bc);
    *(int*)&test[4] = *(volatile unsigned int*)&DAT_005832c0;
    *(int*)&test[8] = *(volatile unsigned int*)&DAT_005832c4;
    *(short*)&test[12] = *(volatile unsigned short*)&DAT_005832c8;
    test[14] = *(volatile unsigned char*)&DAT_005832ca;

    dpn.dwSize = 0x10;
    dpn.dwFlags = 0;
    dpn.lpszShortName = 0;
    dpn.lpszLongName = (char*)test;

    ((IDirectPlay*)DAT_0062c5ec)->vtbl->SetPlayerName((IDirectPlay*)DAT_0062c5ec, (void*)DAT_0062cf04, &dpn, 2);
}
