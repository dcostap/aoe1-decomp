// 0040BEC0 DiplomacyAIModule::DiplomacyAIModule (86 bytes)
// Source: aidipmod.cpp lines 26-33
//
// Attempt log:
// Previous attempts (from pre-existing scratch): 80/86 bytes, 6 short = vtable store
// This probe: proper virtual base class to force vtable store

#include "..\..\include\game_globals.h"

class MainDecisionAIModule;

// AIModule stub: size 0xF0 with vptr
class AIModule {
public:
    virtual ~AIModule() {}
    virtual void dummy1() {}
    char _gap_04[0xEC];

    AIModule(const char* name, unsigned long help_id, int param1, int param2);
};

class DiplomacyAIModule : public AIModule {
public:
    MainDecisionAIModule* md;            // +0xF0
    int dislikeTable[10];                // +0xF4
    int likeTable[10];                   // +0x11C
    unsigned char changeableTable[10];   // +0x144

    DiplomacyAIModule(int param1, int param2);
};

DiplomacyAIModule::DiplomacyAIModule(int param1, int param2)
    : AIModule("Diplomacy AI", 0x3EB, param2, param1)
{
    this->md = 0;
    for (int i = 0; i <= 9; i++) {
        this->dislikeTable[i] = 49;
        this->likeTable[i] = 49;
        this->changeableTable[i] = 1;
    }
}
