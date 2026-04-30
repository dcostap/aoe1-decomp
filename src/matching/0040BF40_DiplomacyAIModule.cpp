// VA: 0040BF40 DiplomacyAIModule::DiplomacyAIModule (EH ctor)
// Source: aidipmod.cpp lines 40-47
// Size: 163 bytes, EH-framed (/GX) — config/flags/0040BF40_DiplomacyAIModule.rsp
//
// Attempt log (18 probes):
// Probe 1-6: 22 diff bytes, register allocation basin
// Probe 7: SWAP local decl order (cp before lp) → 12 diff bytes!
//   Register allocation now matches original (esi=this, edi=0→fh, ebx=changeableTable, ebp=counter)
// Probes 8-17: volatile, casts, void* ctor param, virtual dtor, include context — none budged
// Probe 18: cast md assignment — same 12 bytes
//
// Remaining 12 bytes (7.4%): implicit vtable store (mov [this], vtable_addr) scheduled
// BEFORE md=0 in rebuilt, AFTER in original. Pure VC5 scheduling artifact.
// Both write to `this` at different offsets (+0x00 vs +0xF0) — semantically equivalent.
// 59 bytes identical before gap, 88 identical after.
// Parked in scratch per Boss direction.

#include "..\..\include\game_globals.h"

class MainDecisionAIModule;

class AIModule {
public:
    virtual ~AIModule() {}
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
