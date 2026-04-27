// 0040C5B0 DiplomacyAIModule::mostLiked
// Source: aidipmod.cpp lines 338-362
// Size: 169 bytes
//
// Attempt log:
// Probe 1: 144/169B — structural probe, pointer chain + virtual dispatch basin

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

    int mostLiked(int param1, int param2);
    int isEnemy(int id);
};

int DiplomacyAIModule::mostLiked(int param1, int param2)
{
    int num_players = *(short*)(*(int*)(*(int*)(*(int*)((char*)this + 0xF0) + 0xF0) + 0x3C) + 0x3C);
    int result = -1;
    int highest = -1;
    for (int i = 1; i < num_players; i++) {
        // Skip self
        int self_id = *(short*)(*(int*)(*(int*)((char*)this + 0xF0) + 0x3C) + 0x4A);
        if (i == self_id)
            continue;

        int val = this->likeTable[i];
        if (param1 > 0 && param2 == i && isEnemy(i))
            continue;

        if (val > highest) {
            highest = val;
            result = i;
        }
    }
    return result;
}
