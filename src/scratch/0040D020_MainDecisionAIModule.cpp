// 0040D020 MainDecisionAIModule::~MainDecisionAIModule (aimdmod.cpp:57-58, 112B)
// FLAGS: /GX
//
// Attempt log (2026-05-19):
// 10+ probes attempted. Best result: non-virtual stubs + delete expression + /GX.
// Edit diff 18.75%, positional diff 64.29%. Field offsets correct.
//
// Remaining mismatch (18.75% edit / 64.29% positional):
// The EH prologue format is structurally different:
//   Original: FS-first 3-slot (mov eax,[fs:0]; push -1; push handler; push eax)
//   Rebuilt:  push-first 4-slot (push -1; push handler; mov eax,[fs:0]; push eax; push ecx)
// VC5's /GX always emits push-first (4-slot with saved-this). The 1998 build's
// compiler emitted FS-first (3-slot, no saved-this). This is a compiler-version
// internal EH model difference.
//
// Body (null check, delete, zero stores, base dtor call) is behaviorally correct.
// Stack frame offsets differ by 4 due to saved-this slot.
// Tail cleanup: add esp 0Ch vs add esp 10h.
// Missing vtable store (suppressed by non-virtual stub pattern).
//
// accepted_drift not applicable: stack cleanup and frame layout are structurally
// different per AGENTS.md rules.
// GIVEUP: exact match blocked by compiler EH model difference.

#include <stdlib.h>

class AIModule {
public:
    char gap_00[0xF0];
    ~AIModule();
};

class MainDecisionAIModule : public AIModule {
public:
    char pad_F0[4];
    int* objects_value;
    int objects_numberValue;
    int objects_desiredNumberValue;
    int objects_maximumSizeValue;
    ~MainDecisionAIModule();
};

MainDecisionAIModule::~MainDecisionAIModule() {
    if (this->objects_value != 0) {
        delete this->objects_value;
        this->objects_value = 0;
    }
    this->objects_numberValue = 0;
    this->objects_desiredNumberValue = 0;
    this->objects_maximumSizeValue = 0;
}
