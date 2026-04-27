// 0040C4D0 DiplomacyAIModule::mostHated
// Source: aidipmod.cpp lines 296-333
// Size: 222 bytes
//
// Attempt log:
// Probe 1: 176/222B — structural probe, pointer chain + virtual dispatch basin

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

    int mostHated(int param1, int param2, int param3, int param4);
    int isAlly(int id);
    int isEnemy(int id);
};

int DiplomacyAIModule::mostHated(int param1, int param2, int param3, int param4)
{
    int num_players = *(short*)(*(int*)(*(int*)(*(int*)((char*)this + 0xF0) + 0xF0) + 0x3C) + 0x3C);
    int result = -1;
    int highest = -1;
    for (int i = 1; i < num_players; i++) {
        // Skip self
        int self_id = *(short*)(*(int*)(*(int*)((char*)this + 0xF0) + 0x3C) + 0x4A);
        if (i == self_id)
            continue;

        int val = this->dislikeTable[i];
        if (param1 > 0 && param2 == i && isAlly(i))
            continue;

        val -= this->likeTable[i];
        if (param4 > 1) {
            val /= param4;
        }

        if (val > highest) {
            highest = val;
            result = i;
        }
    }
    return result;
}
