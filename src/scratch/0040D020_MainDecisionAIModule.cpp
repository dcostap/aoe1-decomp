// 0040D020 MainDecisionAIModule::~MainDecisionAIModule (aimdmod.cpp:57-58, 112B)
// BLOCKED: VC5-version SEH/vtordisp layout differences (3 issues):
//
// 1. EH PROLOGUE ORDER: original does `mov eax,[fs:0]; push -1; push handler; push eax; mov [fs:0],esp`.
//    Our VC5 does `push -1; push handler; mov eax,[fs:0]; push eax; mov [fs:0],esp; push ecx`.
//    The extra `push ecx` is for the SEH handler's per-frame context slot.
//
// 2. VTORDISP GAP: Our VC5 inserts a 4-byte vtordisp field between the base class
//    (AIModule) and the derived class's first data member (objects), at offset +0xF4.
//    The 1998 build has objects directly at +0xF4 (sizeof AIModule). Our VC5 places
//    objects at +0xF8, shifting all field offsets by 4.
//
// 3. DERIVED FIELD COUNT: The original ManagedArray_Int has 4 ints (value + 3 fields),
//    zeroing only the 3 fields after value (numberValue, desiredNumberValue,
//    maximumSizeValue). Our VC5 also zeros maximumSizeValue (4th zero) but the
//    shifted vtordisp offset cascades through everything.
//
// All logic, control flow, and memory effects are correct. The differences are
// pure VC5-version EH infrastructure (SEH frame format + vtordisp insertion).

#include <new.h>

class AIModule {
public:
    void* vftable;         // +0x00
    char pad[0xF0];        // sizeof = 0xF4 (target)

    virtual ~AIModule();
};

class MainDecisionAIModule : public AIModule {
public:
    // vtordisp gap at +0xF4 (4 bytes in our VC5, absent in 1998 build)
    int* objects_value;           // +0xF4 target (+0xF8 with vtordisp)
    int objects_numberValue;      // +0xF8 target (+0xFC with vtordisp)
    int objects_desiredNumberValue; // +0xFC target (+0x100 with vtordisp)
    int objects_maximumSizeValue;    // +0x100 target (+0x104 with vtordisp)

    virtual ~MainDecisionAIModule();
};

extern void __cdecl operator_delete(void* p);

MainDecisionAIModule::~MainDecisionAIModule() {
    if (this->objects_value != 0) {
        operator_delete(this->objects_value);
        this->objects_value = 0;
    }
    this->objects_numberValue = 0;
    this->objects_desiredNumberValue = 0;
    this->objects_maximumSizeValue = 0;
}
