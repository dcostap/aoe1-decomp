// VA: 0040BF40 DiplomacyAIModule::DiplomacyAIModule (EH ctor)
// Source: aidipmod.cpp lines 40-47
// Size: 163 bytes, EH-framed (/GX) in the grouped aidipmod translation unit.
//
// BINARY NOTE: A natural md member initializer preserves the shipped vptr/store order.
// Exact-finish: a body assignment reproduced the 12-byte scheduling mismatch.
// The body-assignment walkback failed; no manual vptr write is used.
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
    : AIModule("Diplomacy AI", 0x3EB, param, 0), md(0)
{
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
