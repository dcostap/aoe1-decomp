// VA: 0040BF40 DiplomacyAIModule::DiplomacyAIModule (EH ctor)
// Source: aidipmod.cpp lines 40-47
// Size: 163 bytes, EH-framed (/GX) in the grouped aidipmod translation unit.
//
// The policy-valid natural constructor keeps VC5's derived-vptr initialization.
// The shipped bytes store that vptr later, so this owner is observed in the TU.
// Base size is 0xF0: vptr plus the 0xEC-byte base tail.

#include "..\..\include\game_globals.h"

class MainDecisionAIModule;

#ifndef AOE1_AIDIPMOD_TU_CONTEXT
class AIModule {
public:
    char _gap_04[0xEC];

    virtual ~AIModule() {}

    AIModule(const char* name, unsigned long help_id, int param1, int param2);
};

class DiplomacyAIModule : public AIModule {
public:
    MainDecisionAIModule* md;            // +0xF0
    int dislikeTable[10];                // +0xF4
    int likeTable[10];                   // +0x11C
    unsigned char changeableTable[10];   // +0x144

    DiplomacyAIModule(int param, int file_handle);
};
#endif

extern int __cdecl rge_read(int handle, void* buf, int size);

DiplomacyAIModule::DiplomacyAIModule(int param, int file_handle)
    : AIModule("Diplomacy AI", 0x3EB, param, 0)
{
    this->md = 0;
    unsigned char* cp = this->changeableTable;
    int* lp = this->likeTable;
    int count = 10;
    do {
        rge_read(file_handle, lp - 10, 4);
        rge_read(file_handle, lp, 4);
        rge_read(file_handle, cp, 1);
        lp++; cp++; count--;
    } while (count != 0);
}
