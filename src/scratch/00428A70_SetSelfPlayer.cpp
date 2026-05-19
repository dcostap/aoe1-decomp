// TCommunications_Handler::SetSelfPlayer (__thiscall)
// VA: 00428A70
// Com_hand.cpp:2303-2323
// 156 bytes
//
// Attempt 7: Use volatile pointer for selfDcoID to prevent hoisting.

#include <stdlib.h>

extern volatile int selfDcoID;        // volatile prevents hoisting
extern void* L;

extern void __cdecl Log(void* log, const char* fmt, ...);

class TCommunications_Handler {
public:
    char gap_00[0x10E0];
    int mePlayerNum;                        // +0x10E0
    char gap_10E4[0x12D8 - 0x10E4];
    unsigned short maxGamePlayers;          // +0x12D8
    char gap_12DA[0x1568 - 0x12DA];
    int dcoID[1];                          // +0x1568

    void SetSelfPlayer();
    void NotifyWindowParam(int msg, int param);
};

void TCommunications_Handler::SetSelfPlayer()
{
    int i = 1;
    int* p = this->dcoID;

    while ((unsigned int)i <= (unsigned int)this->maxGamePlayers) {
        Log(L, "Check dcoID %d to Me %d ?", *p, selfDcoID);

        if (*p == selfDcoID) {
            Log(L, "Match! - ID set.");
            this->mePlayerNum = i;
            NotifyWindowParam(0x17B8, i);
            return;
        }

        i++;
        p++;
    }

    Log(L, "SET SELF failed.  We are DCOID=%d", selfDcoID);
}
