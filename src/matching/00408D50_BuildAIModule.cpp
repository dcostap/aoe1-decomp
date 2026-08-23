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
// 2026-05-19 assigned retry:
// 10: saved typesToIgnoreValue local; no codegen change.
// 11: delete[] and explicit operator delete call; no codegen change; restored delete.
// 12: novtable/manual vptr store worsened vptr scheduling and positional diff; rolled back.
// 13: `0 < buildListLength` no change; `>= 1` worsened branch/codegen; rolled back.
// 14: zero-field store order reversed worsened edit diff; rolled back.
// 15: flag probes /O2 /GX and /Ob0 no change; /O1 much worse; restored /O2 /Oy /GX.
// 16: inverted empty delete if/else no change; rolled back.
// 17: non-virtual BuildItem destructor worsened offsets/codegen; rolled back.
//
// ACCEPTED_DRIFT DENIED by review: remaining mismatch is EH state numbering plus an omitted redundant state store before delete; this is cleanup/unwind-state topology, not safe localized register/layout drift. Leave in scratch.
// Retry 2026-05-20 assigned pass: modeled typesToIgnore as a real destructible ManagedArray_Int member with inline destructor and removed manual cleanup from BuildAIModule::~BuildAIModule. This gave VC5 the missing destructible subobject, producing EH states 2 -> 1 -> 0 -> -1 and inlining the delete/zero cleanup exactly. MATCH.
// Former accepted drift rationale (kept as evidence, not accepted):
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
#include "../../include/aibldmod_context.h"

#ifndef AIBLDMOD_SHARED_CONTEXT
class BuildItem {
public:
    char gap_00[0xAC];           // +0x04 to +0xAF
    virtual ~BuildItem();         // sizeof = 0xB0
};

class ManagedArray_Int {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
    ~ManagedArray_Int() {
        if (value != 0) {
            delete value;
            value = 0;
        }
        numberValue = 0;
        desiredNumberValue = 0;
        maximumSizeValue = 0;
    }
};

class AIModule {
public:
    virtual ~AIModule();         // sizeof = 4
};

class BuildAIModule : public AIModule {
public:
    char gap_00[0xEC];           // +0x04 to +0xEF
    BuildItem buildList;          // +0xF0
    int buildListLengthValue;     // +0x1A0
    char gap_1A4[0x408];          // +0x1A4 to +0x5AB
    ManagedArray_Int typesToIgnore; // +0x5AC

    virtual ~BuildAIModule();
    void removeOldList();
};
#endif

BuildAIModule::~BuildAIModule()
{
    if (buildListLengthValue > 0)
        removeOldList();

    // typesToIgnore, ~BuildItem() and ~AIModule() called automatically by VC5
}
