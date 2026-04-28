// TCommunications_Handler::SetSelfPlayer
// VA: 00428A70
// Com_hand.cpp:2303-2323
// 156 bytes, not matched (parked)
// Scans this->dcoID[] array for self DCOID (DAT_0062cf04).
// Uses pointer-advancement (esi += 4) loop. Logs results.
//
// Attempt log (3 variants):
// v0: goto-based fall-through (fail_load/fail_log labels) → 208B, 6-byte near jb
// v1: while(i <= MaxGamePlayers) + local self_id → 100B diff
// v2: too many variants, parking
//
// Remaining diff: variadic Log function calls complicate codegen.
// Pointer-advancement loop pattern hard to replicate from array-indexed C.

#include "../../include/game_globals.h"

extern void* L;
extern "C" void __cdecl Log(void* log, char* fmt, ...);

extern unsigned int DAT_0062cf04;

class TCommunications_Handler {
public:
    char gap_00[0x10E0];
    int Me;                     // +0x10E0
    char gap_10E4[0x12D8 - 0x10E4];
    unsigned short MaxGamePlayers;  // +0x12D8
    char gap_12DA[0x1568 - 0x12DA];
    int dcoID[1];              // +0x1568, variable length

    void SetSelfPlayer(void);
    void NotifyWindowParam(int msg, int param);
};

void TCommunications_Handler::SetSelfPlayer(void) {
    int i;
    int* ptr;

    i = 1;
    ptr = this->dcoID;

    while (i <= this->MaxGamePlayers) {
        Log(L, "Check dcoID %d to Me %d ?", *ptr, (int)DAT_0062cf04);
        if (*ptr == (int)DAT_0062cf04) {
            Log(L, "Match! - ID set.");
            this->Me = i;
            NotifyWindowParam(0x17B8, i);
            return;
        }
        i++;
        ptr++;
    }

    Log(L, "SET SELF failed.  We are DCOID=%d", (int)DAT_0062cf04);
}
