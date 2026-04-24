// Function: TribeBuildAIModule::addResearch
// VA: 004D5690
// Source: taibldmd.cpp
//
// STATUS: Cannot match exactly due to MSVC5 calling convention limitations
//
// ISSUE: The original uses __thiscall where 'this' is passed in ECX, but
// MSVC5 doesn't support __thiscall on extern functions. This causes the
// compiler to generate incorrect code that pushes 'this' to the stack.
//
// Original: mov ecx,esi; call 004085B0h  ; this in ECX
// Generated: push esi; call ...          ; this on stack
//
// This is the same toolchain limitation as 004B4770 getSettings.
// Function behavior is semantically correct but calling convention differs.
// Leaving in scratch due to this toolchain limitation.

class BuildItem;
class TribeMainDecisionAIModule;
class TribeTacticalAIModule;

// Use extern declarations from game_globals.h
extern BuildItem* __stdcall specificBuildListItem(void* this_, int param);
extern void __stdcall setInProgress(BuildItem* this_, int param);
extern void __stdcall setBuilt(BuildItem* this_, int param);
extern void __stdcall incrementNumberBuilds(BuildItem* this_);
extern void __stdcall detask(TribeMainDecisionAIModule* this_, int param);
extern void __stdcall updateNeededResources(TribeTacticalAIModule* this_);

class TribeTacticalAIModule {
public:
    char pad_000[0x1146C];
};

class TribeMainDecisionAIModule {
public:
    char pad_000[0x5BC];
    TribeTacticalAIModule tacticalAI;
};

class TribeBuildAIModule {
public:
    char pad_000[0x5BC];
    TribeMainDecisionAIModule* md;  // offset 0x5BC
    
    int addResearch(int param_1, int param_2, int param_3);
};

int TribeBuildAIModule::addResearch(int param_1, int param_2, int param_3) {
    // From decompiler output:
    // BuildItem *this_00 = BuildAIModule::specificBuildListItem((BuildAIModule *)this, param_3);
    // if (this_00 != (BuildItem *)0x0) {
    //     BuildItem::setInProgress(this_00, 0);
    //     BuildItem::setBuilt(this_00, 1);
    //     BuildItem::incrementNumberBuilds(this_00);
    // }
    // TribeMainDecisionAIModule::detask(this->md, param_2);
    // TribeTacticalAIModule::updateNeededResources(&this->md->tacticalAI);
    // return 1;
    
    // The issue is getting the compiler to use ECX for 'this' in method calls
    // MSVC5 won't generate mov ecx,[...] for extern functions
    BuildItem* this_00 = specificBuildListItem((BuildAIModule*)this, param_3);
    
    if (this_00 != 0) {
        setInProgress(this_00, 0);
        setBuilt(this_00, 1);
        incrementNumberBuilds(this_00);
    }
    
    detask(this->md, param_2);
    updateNeededResources(&this->md->tacticalAI);
    
    return 1;
}
