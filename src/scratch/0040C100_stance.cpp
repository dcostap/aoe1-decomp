// 0040C100 DiplomacyAIModule::stance
// Source: aidipmod.cpp lines 110-138
// Size: 134 bytes
//
// Attempt log:
// Probe 1: 134/134B, 78% diff — codegen basin
//   Register allocation, switch style, branchless vs branched return differ

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
    if (player_id <= 0)
        return -1;

    // Bounds check: this->md->field_F0->field_3C->player_count (short at +0x3C)
    {
        int a = *(int*)((char*)this + 0xF0);
        int b = *(int*)(a + 0xF0);
        int c = *(int*)(b + 0x3C);
        short count = *(short*)(c + 0x3C);
        if (player_id >= count)
            return -1;
    }

    if (type == 0) {
        return this->dislikeTable[player_id];
    } else if (type == 1) {
        int dislike = this->dislikeTable[player_id];
        int dislike_diff = 0x31 - dislike;
        if (dislike_diff < 0) dislike_diff = -dislike_diff;

        int like = this->likeTable[player_id];
        int like_diff = 0x31 - like;
        if (like_diff < 0) like_diff = -like_diff;

        int result = 0x64 - dislike_diff - like_diff;
        if (result >= 0)
            return result;
        return 0;
    } else if (type == 2) {
        return this->likeTable[player_id];
    }
    return -1;
}
