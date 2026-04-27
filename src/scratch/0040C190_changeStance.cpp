// 0040C190 DiplomacyAIModule::changeStance
// Source: aidipmod.cpp lines 148-187
// Size: 283 bytes
//
// Attempt log:
// Probe 1: 80/283B — structural probe, too short
//   ChangeStance is more complex than simple clamp (has player chain, weighted calc)

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

    void changeStance(int id, int a, int b);
};

void DiplomacyAIModule::changeStance(int id, int a, int b)
{
    int dislike = this->dislikeTable[id];
    int like = this->likeTable[id];

    // adjust dislike based on a and b
    dislike += a;
    if (dislike < 0) dislike = 0;
    if (dislike > 100) dislike = 100;

    like += b;
    if (like < 0) like = 0;
    if (like > 100) like = 100;

    this->dislikeTable[id] = dislike;
    this->likeTable[id] = like;
}
