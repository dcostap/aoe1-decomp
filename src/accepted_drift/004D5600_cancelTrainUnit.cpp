// TribeBuildAIModule::cancelTrainUnit
// VA: 004D5600
// PDB: taibldmd.cpp:1405-1432
// Retry 2026-05-19/20 assigned pass:
// - Replaced fake fastcall helper wrappers with natural member/virtual declarations; improved from 36.8056% positional to 1.3889%.
// - Correct thiscall surfaces for specificBuildListItem/setInProgress fixed missing pushes and call layout.
// - Tried manual vtable function-pointer call in invalid-item arm: worsened by dropping ECX setup and adding padding; rolled back.
// - Tried self local for invalid-item virtual call and /Ob0, /G5 flag probes: no change; flags removed.
// ACCEPTED_DRIFT 2026-05-19: approved localized behavior-equivalent vtable-register drift.
// Only two bytes differ in the invalid-item vcall: original loads the same vtable
// pointer from `this` into EDX and calls [edx+40h], rebuilt uses EAX and calls
// [eax+40h]. Same object, ECX=this, virtual slot, calls, stack cleanup, return,
// and memory effects; all other bytes match after relocation masking.

#ifndef TAIBLDMD_SHARED_CONTEXT
#include "../../include/game_globals.h"

class BuildItem {
public:
    int uniqueID();
    void setInProgress(int val);
};

class TribeBuildAIModule {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();

    char gap_04[0x5BC - 4];
    void* md;

    void logCommonHistory(char* fmt, ...);
    BuildItem* specificBuildListItem(int id);
    int cancelTrainUnit(int param_1, int param_2, int param_3, int param_4);
};
#endif

int TribeBuildAIModule::cancelTrainUnit(int param_1, int param_2, int param_3, int param_4)
{
    int type_id = *(int*)(*(int*)(*(int*)((char*)this->md + 0x0F0) + 0x3C) + 4);
    this->logCommonHistory("Canceling training (WT=%ld) for item of type %ld", type_id, param_2, param_3);

    BuildItem* item = this->specificBuildListItem(param_4);
    if (item) {
        this->logCommonHistory("  Setting build item #%d in progress to FALSE", item->uniqueID());
        item->setInProgress(0);
#ifdef TAIBLDMD_SHARED_CONTEXT
        this->displayBuildList();
#else
        this->v40();
#endif
        return 1;
    }

    this->logCommonHistory("  ERROR!  Invalid build item.");
    TribeBuildAIModule* self = this;
#ifdef TAIBLDMD_SHARED_CONTEXT
    self->displayBuildList();
#else
    self->v40();
#endif
    return 1;
}
