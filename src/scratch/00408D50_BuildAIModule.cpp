// BuildAIModule::~BuildAIModule
// VA: 00408D50
// aibldmod.cpp:180-183
// 156 bytes, virtual destructor, needs /GX for EH
// Not matched (parked) — EH frame layout sensitive to sizeof(BuildItem)
// and vtable offset calculations. 176B vs expected 156 (20 over).

#include "../../include/game_globals.h"

class BuildItem {
public:
    char gap[0xAC];  // Total sizeof = 0xB0 = 0xAC + 4 (vptr at +0x00)
    virtual ~BuildItem();
};

class AIModule {
public:
    virtual ~AIModule();
};

class BuildAIModule : public AIModule {
public:
    char gap_00[0xF0];
    BuildItem buildList;             // +0xF0, sizeof=0xB0
    int buildListLength;             // +0x1A0
    char gap_1A4[0x5AC - 0x1A4];
    int* typesToIgnoreValue;         // +0x5AC
    int typesToIgnoreNumber;         // +0x5B0
    int typesToIgnoreDesired;        // +0x5B4
    int typesToIgnoreMax;            // +0x5B8

    virtual ~BuildAIModule();
    void removeOldList(void);
};

BuildAIModule::~BuildAIModule() {
    *(void**)this = (void*)0x56E738;

    if (this->buildListLength > 0)
        removeOldList();

    if (this->typesToIgnoreValue != 0) {
        delete this->typesToIgnoreValue;
        this->typesToIgnoreValue = 0;
    }

    this->typesToIgnoreNumber = 0;
    this->typesToIgnoreDesired = 0;
    this->typesToIgnoreMax = 0;

    this->buildList.~BuildItem();
    ((AIModule*)this)->~AIModule();
}
