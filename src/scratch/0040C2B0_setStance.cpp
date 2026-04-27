// 0040C2B0 DiplomacyAIModule::setStance
// Source: aidipmod.cpp lines 193-227
// Size: 252 bytes
//
// Attempt log:
// Probe 1: 48/252B — structural probe, too short
//   setStance is more complex than 3 field stores

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

    void setStance(int id, int dislike, int like);
};

void DiplomacyAIModule::setStance(int id, int dislike, int like)
{
    this->dislikeTable[id] = dislike;
    this->likeTable[id] = like;
    this->changeableTable[id] = 1;
}
