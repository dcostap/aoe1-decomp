// 0040D020 MainDecisionAIModule::~MainDecisionAIModule (aimdmod.cpp:57-58, 112B)
// FLAGS: /GX
//
// BLOCKED: behavior and real data offsets are understood, but this target is in
// a different VC5 EH/prologue frame family than the local compiler emits for
// the same natural destructor. Best source below has correct object layout
// (AIModule size 0xF0, player at +0xF0, objects at +0xF4) and correct field
// effects, but rebuilt starts with `push -1; push handler; mov eax,fs:[0]` plus
// an extra saved-this EH context slot. Original starts `mov eax,fs:[0]; push -1;
// push handler; push eax` and has no saved-this slot, so stack-state offsets and
// epilogue remain shifted even after field offsets are fixed.
//
// Attempt log:
// 1. Original scratch with explicit vftable in AIModule made base size 0xF4 and
//    shifted objects to +0xF8; broad mismatch.
// 2. Switched to natural AIModule layout matching 00411940 style (no explicit
//    vftable field; real AIModule data fields) plus player at +0xF0. This fixes
//    object field offsets to +0xF4/+0xF8/+0xFC/+0x100 and improves edit diff.
// 3. Tried `delete objects_value` instead of null-checked operator_delete; worse
//    call/null shape (unconditional delete path).
// 4. Tried explicit ManagedArrayInt member destructor; VC5 emitted a separate
//    destructor body/context and broad mismatch.
// 5. Tried non-virtual base / derived virtual combinations; introduced vtordisp
//    or this-adjust/base-null checks and shifted fields.
// 6. Tried manual vtable store plus explicit base destructor on a raw-layout
//    class; symbol/layout extraction was worse and did not reproduce original
//    EH prologue.
// 7. Tried /GX and non-/GX where applicable; no exact. /GX is required for the
//    destructor EH frame family, but local VC5 still uses the newer saved-this
//    context-slot prologue.
// 8. 2026-05-10 SpruceGlow Boss-assigned pass: revalidated current best, then tried
//    10 destructor-body variants: delete expression, pointer local, zero-before-delete,
//    explicit else, comma/chained zero stores, raw offsets, volatile pointer, shared zero
//    local, and unqualified member access. None addressed the first-byte EH prologue
//    family mismatch; body-level variants only perturb the already shifted frame/body.
//    Left in scratch; no accepted_drift suggestion because the mismatch is broad EH
//    prologue/context layout drift, not localized behavior-equivalent instruction choice.
// 8. 2026-05-10 StarryZephyr pass: rechecked baseline, tried non-virtual base/derived
//    destructor surface (improved edit diff slightly but shifted object fields to +0xF0
//    and still kept the wrong saved-this EH prologue), no-<new.h> include (no change),
//    no-/GX (wrong EH family), and flag probes /Oa, /Ob0, /G5 with /GX (no change).
//    Restored virtual layout and /GX flag; include removal was neutral and left out.

class AIModuleID {
public:
    void* vtable_ptr;
    int id;
    char name[64];
};

class AIModule {
public:
    AIModuleID idValue;
    int playerNumberValue;
    char playerNameValue[64];
    int runningValue;
    int pausedValue;
    int logHistoryValue;
    int logCommonHistoryValue;
    void* historyLogFile;
    char historyLogFilename[64];
    int intelligenceLevelValue;
    int priorityValue;
    int processFrameValue;

    virtual ~AIModule();
};

class RGE_Player {};

extern void __cdecl operator_delete(void* p);

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;              // +0xF0
    int* objects_value;              // +0xF4
    int objects_numberValue;         // +0xF8
    int objects_desiredNumberValue;  // +0xFC
    int objects_maximumSizeValue;    // +0x100

    virtual ~MainDecisionAIModule();
};

MainDecisionAIModule::~MainDecisionAIModule() {
    if (this->objects_value != 0) {
        operator_delete(this->objects_value);
        this->objects_value = 0;
    }
    this->objects_numberValue = 0;
    this->objects_desiredNumberValue = 0;
    this->objects_maximumSizeValue = 0;
}
