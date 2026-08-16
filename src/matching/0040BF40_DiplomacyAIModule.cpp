// VA: 0040BF40 DiplomacyAIModule::DiplomacyAIModule (EH ctor)
// Source: aidipmod.cpp lines 40-47
// Size: 163 bytes, EH-framed (/GX) — config/flags/0040BF40_DiplomacyAIModule.rsp
//
// The original writes the derived vptr after md=0 and the file-handle reload.
// VC5's normal derived-vptr initialization writes it before md=0.
// novtable plus this proven explicit store preserves the original order.
// Base size is 0xF0: vptr plus the 0xEC-byte base tail.
// Exact check: 163/163 bytes, owner symbol matched, direct calls matched.

#include "..\..\include\game_globals.h"

class MainDecisionAIModule;

class __declspec(novtable) AIModule {
public:
    char _gap_04[0xEC];

    virtual ~AIModule() {}

    AIModule(const char* name, unsigned long help_id, int param1, int param2);
};

class __declspec(novtable) DiplomacyAIModule : public AIModule {
public:
    MainDecisionAIModule* md;            // +0xF0
    int dislikeTable[10];                // +0xF4
    int likeTable[10];                   // +0x11C
    unsigned char changeableTable[10];   // +0x144

    DiplomacyAIModule(int param, int file_handle);
};

extern int __cdecl rge_read(int handle, void* buf, int size);
extern void* DiplomacyAIModule_vtable;

DiplomacyAIModule::DiplomacyAIModule(int param, int file_handle)
    : AIModule("Diplomacy AI", 0x3EB, param, 0)
{
    this->md = 0;
    *(void**)this = &DiplomacyAIModule_vtable;
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
