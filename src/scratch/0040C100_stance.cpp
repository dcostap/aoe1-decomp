// 0040C100 DiplomacyAIModule::stance
// Source: aidipmod.cpp lines 110-138
// Size: 134 bytes
// Attempt log:
// - Prior source 134/134B but broad diff: VC5 used ESI for player_id and branchless clamp for result.
// - 2026-05-10 StarryZephyr pass: rewrote dispatch as switch on type, which matched original decrement-chain dispatch and
//   improved edit equal bytes but still preserved player_id in ESI and used branchless negative clamp. `abs()` worsened codegen.
//   No accepted_drift: prologue/index register, table loads, and return/clamp control flow still broad.

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
    MainDecisionAIModule* md;
    int dislikeTable[10];
    int likeTable[10];
    unsigned char changeableTable[10];

    int stance(int player_id, int type);
};

int DiplomacyAIModule::stance(int player_id, int type)
{
    int id = player_id;
    if (id > 0 && id < *(short*)(*(int*)(*(int*)(*(int*)((char*)this + 0xF0) + 0xF0) + 0x3C) + 0x3C)) {
        switch (type) {
        case 0:
            return this->dislikeTable[id];
        case 1:
        {
            int dislike_diff = 0x31 - this->dislikeTable[id];
            if (dislike_diff < 0)
                dislike_diff = -dislike_diff;

            int like_diff = 0x31 - this->likeTable[id];
            if (like_diff < 0)
                like_diff = -like_diff;

            int result = 0x64 - dislike_diff - like_diff;
            if (result >= 0)
                return result;
            return 0;
        }
        case 2:
            return this->likeTable[id];
        }
    }
    return -1;
}
