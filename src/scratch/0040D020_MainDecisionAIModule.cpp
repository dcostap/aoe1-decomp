// 0040D020 MainDecisionAIModule::~MainDecisionAIModule (aimdmod.cpp:57-58, 112B)
// FLAGS: /GX
//
// Status: STUCK — VC5 EH prologue family mismatch.
//
// Blocker: The 1998 build uses an FS-first SEH prologue (mov eax,[fs:0]; push -1;
// push handler; push eax) with no saved-this slot. Our VC5 uses a push-first
// prologue (push -1; push handler; mov eax,[fs:0]; push eax; push ecx) with an
// extra saved-this slot. This shifts all stack offsets and cleanup (`add esp,0Ch`
// vs `add esp,10h`). The prologue format is controlled by VC5's internal compiler
// version/architecture, not by source or flag choices.
//
// Best result: __declspec(novtable) on derived class removes the vtable store
// (edit diff 18.75%, positional 64.29%). Without novtable: edit diff 37.5%.
// Edit diff is misleading because resync shifts prologue misalignment into the
// tail - the actual instruction-level differences are in the first 30 bytes
// (prologue format) and the last 3 bytes (stack cleanup). The function body
// (null check, delete call, zero stores, base destructor call) matches perfectly.
//
// Attempt log:
// - Pre-existing: 15+ variants across virtual/non-virtual, explicit base dtor,
//   delete expression vs operator_delete, ManagedArrayInt body, manual vtable,
//   flag probes /Oa/Ob0/G5. All use the push-first EH prologue.
// - 2026-05-12 (this pass):
//   V1: __declspec(novtable) on derived class (edit 18.75%, best so far)
//   V2: Non-novtable virtual destructor (edit 37.5%, worse)
//   Both use push-first EH prologue, both stuck.
//
// No accepted_drift: the prologue format diff shifts stack offsets throughout,
// and 64% positional diff is too broad. The body is correct but the frame is wrong.

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

class __declspec(novtable) MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
    int* objects_value;
    int objects_numberValue;
    int objects_desiredNumberValue;
    int objects_maximumSizeValue;

    ~MainDecisionAIModule();
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
