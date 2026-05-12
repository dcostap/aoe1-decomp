// VA: 0040C100 DiplomacyAIModule::stance
// Source: aidipmod.cpp lines 110-138
// 134 bytes, 48 asm
// __thiscall, returns int: __thiscall(int player_id, int type)
//
// BLOCKER: Persistent codegen-family mismatch. All approaches produce 134/134
// same-size output but with fundamentally different register allocation and
// control flow. Not eligible for accepted_drift.
//
// Attempt log:
// 1: switch dispatch, direct param use, no locals — 134/134, 93% diff, ESI=player_id
// 2: nested ifs (no &&) — same ESI prologue, 93% diff
// 3: early returns — same ESI prologue, 93% diff
// 4: goto err pattern for branch polarity — 79% diff, ESI still in prologue
// 5: proper struct member access for bounds chain — 79% diff, still ESI
// 6: char* pointer chain for bounds — 79% diff, still ESI
// 7: if (result < 0) return 0; for case 1 clamp — no effect on clamp (still branchless)
//
// Persistent structural differences:
// 1. Player_id register: original uses EAX; rebuilt uses ESI (prologue: mov eax,[esp+4]; 
//    push esi vs push esi; mov esi,[esp+8])
// 2. Bound chain register: original reuses EDX throughout; rebuilt uses alternating 
//    EAX/EDX due to different intermediate struct types
// 3. Type dispatch register: original uses EDX; rebuilt uses EAX
// 4. Case 1 result clamp: original uses branch (jns; xor eax,eax); rebuilt uses 
//    branchless (mov eax,0; sets al; dec eax; and eax,ecx)
// 5. All table lookups: original uses eax*4; rebuilt uses esi*4 (symmetric EAX↔ESI swap)
// 6. Error handler: original places at end of function (shared); rebuilt may inline early

#include "..\..\include\game_globals.h"

class MainDecisionAIModule;

class AIModule {
public:
    virtual ~AIModule() {}
    virtual void dummy1() {}
    char _gap_04[0xEC];
};

class DiplomacyAIModule : public AIModule {
public:
    MainDecisionAIModule* md;            // +0xF0
    int dislikeTable[10];                // +0xF4
    int likeTable[10];                   // +0x11C
    unsigned char changeableTable[10];   // +0x144

    int stance(int player_id, int type);
};

int DiplomacyAIModule::stance(int player_id, int type)
{
    if (player_id <= 0) {
        goto err;
    }
    {
        char* p = (char*)this->md;
        p = *(char**)(p + 0xF0);
        p = *(char**)(p + 0x3C);
        int bound = *(short*)(p + 0x3C);
        if (player_id >= bound) {
            goto err;
        }
    }
    switch (type) {
    case 0:
        return this->dislikeTable[player_id];
    case 1: {
        int dislike_diff = 0x31 - this->dislikeTable[player_id];
        if (dislike_diff < 0) {
            dislike_diff = -dislike_diff;
        }
        int like_diff = 0x31 - this->likeTable[player_id];
        if (like_diff < 0) {
            like_diff = -like_diff;
        }
        int result = 100 - dislike_diff - like_diff;
        if (result < 0) {
            return 0;
        }
        return result;
    }
    case 2:
        return this->likeTable[player_id];
    }
err:
    return -1;
}
