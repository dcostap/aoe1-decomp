// 0040BF40 DiplomacyAIModule::DiplomacyAIModule (EH load ctor)
// Source: aidipmod.cpp lines 40-47
// Size: 163 bytes, EH-framed (/GX)
//
// Attempt log:
// Probe 1: 163/163B, 13.5% diff, register allocation basin
//   Correct loop body but esi vs ebx register choice for this
// Left in scratch: codegen basin

#include "..\..\include\game_globals.h"

class MainDecisionAIModule;

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

    DiplomacyAIModule(int param, int file_handle);
};

extern int __cdecl rge_read(int handle, void* buf, int size);

DiplomacyAIModule::DiplomacyAIModule(int param, int file_handle)
    : AIModule("Diplomacy AI", 0x3EB, param, 0)
{
    this->md = 0;
    int count = 10;
    int* lp = this->likeTable;
    unsigned char* cp = this->changeableTable;
    do {
        rge_read(file_handle, lp - 10, 4);
        rge_read(file_handle, lp, 4);
        rge_read(file_handle, cp, 1);
        lp++; cp++; count--;
    } while (count != 0);
}
