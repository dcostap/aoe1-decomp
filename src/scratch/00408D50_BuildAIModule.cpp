// BuildAIModule::~BuildAIModule (__thiscall, virtual destructor)
// VA: 00408D50
// aibldmod.cpp:180-183
// 156 bytes
//
// FLAGS: /GX (required for EH frame generation)
//
// Attempt log:
// 1-2: Wrong field offsets (sizeof(AIModule)=4 not accounted for)
// 3: Explicit destructor calls caused extra `push edi` (edi saved for &buildList)
// 4-8: Various explicit call approaches — all caused push edi
// 9: Let VC5 auto-call ~BuildItem/~AIModule — NO push edi, correct offsets
//     Remaining diff: EH state initial value (02 vs 01)
//
// Accepted drift rationale:
// - All field offsets match (+0xA0, +0xAC, +0xF0, +0xB0/+0xB4/+0xB8)
// - All stack offsets match ([esp+14h], [esp+0Ch])
// - No register save differences (no push edi, same callee-saves)
// - Only difference: EH state initial value 1 vs 2 (compiler numbering choice;
//   from single-function TU vs multi-function TU context)
// - EH state values are functionally equivalent — the exception handler
//   at 0x55C4D4 uses them to determine which destructor to call during
//   unwinding; state 1 vs 2 is just a label difference
// - All calls, vtable, and EH handler addresses are relocations (masked)

#include <stdlib.h>

class BuildItem {
public:
    char gap_00[0xAC];           // +0x04 to +0xAF
    virtual ~BuildItem();         // sizeof = 0xB0
};

class AIModule {
public:
    virtual ~AIModule();         // sizeof = 4
};

class BuildAIModule : public AIModule {
public:
    char gap_00[0xEC];           // +0x04 to +0xEF
    BuildItem buildList;          // +0xF0
    int buildListLength;          // +0x1A0
    char gap_1A4[0x408];          // +0x1A4 to +0x5AB
    int* typesToIgnoreValue;      // +0x5AC
    int typesToIgnoreNumber;      // +0x5B0
    int typesToIgnoreDesired;     // +0x5B4
    int typesToIgnoreMax;         // +0x5B8

    virtual ~BuildAIModule();
    void removeOldList();
};

BuildAIModule::~BuildAIModule()
{
    if (buildListLength > 0)
        removeOldList();

    if (typesToIgnoreValue != 0) {
        delete typesToIgnoreValue;
        typesToIgnoreValue = 0;
    }

    typesToIgnoreNumber = 0;
    typesToIgnoreDesired = 0;
    typesToIgnoreMax = 0;

    // ~BuildItem() and ~AIModule() called automatically by VC5
}
