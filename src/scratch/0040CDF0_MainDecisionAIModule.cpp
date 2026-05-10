// VA: 0040CDF0 MainDecisionAIModule::MainDecisionAIModule (113 B)
// PDB source: aimdmod.cpp lines 34-35
// FLAGS: /GX
//
// LEFT IN SCRATCH. Behavior, base-ctor call, field offsets, and vtable restore are
// understood, but the original is in an EH-framed constructor basin that this local
// source surface has not reproduced. Original starts with `mov eax, fs:[0]; push -1;
// push handler; push eax`, installs FS before the base AIModule ctor call, restores FS
// at the tail, and has no compiler-emitted deleting-destructor code inside the 113-byte
// window. Natural source with a declared virtual base/derived surface emits a plain
// non-EH constructor and then a scalar deleting destructor in the same COMDAT/window.
// Manual/raw-layout source can get the field offsets and vtable store but remains a
// short non-EH constructor. No accepted_drift suggestion: prologue/EH/tail and compared
// window are broadly different.
//
// Attempt log:
// 1. Original scratch without a base class only emitted the derived member stores and
//    was too short (no base call/EH/vtable context).
// 2. Natural `: AIModule("Main Decision AI", 1000, param_2, param_1)` restores the
//    base ctor call and argument order but still emits no EH frame.
// 3. Base/derived virtual destructor declarations make VC5 emit vtable stores, but also
//    emit scalar/vector deleting destructor support in the same object; ctor remains
//    non-EH. Adjusting AIModule padding to 0xEC fixes player/objects offsets.
// 4. Defining the derived destructor in this TU, declaring virtual non-dtor functions,
//    manual vtable store, explicit body base call, non-virtual base plus virtual derived,
//    local/member objects with declared destructors, and try/catch-body variants did not
//    produce the original EH prologue.
// 5. Function-try-block syntax is rejected by this VC5 mode. /GX is required by the
//    original-style family but not sufficient from this reduced local surface.
// 6. 2026-05-10 StarryZephyr pass: rechecked baseline, tried replacing virtual
//    destructors with a virtual dummy method (removes deleting destructor but shrinks
//    ctor to 80 bytes/no EH), __declspec(novtable) on base/derived (also 80 bytes),
//    an empty try/catch in the body (optimized/no change), and /GR- with /GX (no
//    change). Restored natural virtual-dtor source and /GX.

struct ManagedArray_Int {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class RGE_Player {};

class AIModule {
public:
    char gap_04[0xEC]; // vptr + 0xEC = 0xF0 total base size when virtual
    AIModule(char* name, int id, int player_number, void* owner);
    virtual ~AIModule();
};

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;          // +0xF0
    ManagedArray_Int objects;    // +0xF4

    MainDecisionAIModule(void* param_1, int param_2, RGE_Player* param_3);
};

MainDecisionAIModule::MainDecisionAIModule(void* param_1, int param_2, RGE_Player* param_3)
    : AIModule("Main Decision AI", 1000, param_2, param_1)
{
    this->player = param_3;
    this->objects.value = 0;
    this->objects.numberValue = 0;
    this->objects.desiredNumberValue = 0;
    this->objects.maximumSizeValue = 0;
}
