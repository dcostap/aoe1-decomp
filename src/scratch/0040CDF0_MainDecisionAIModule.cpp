// VA: 0040CDF0 MainDecisionAIModule::MainDecisionAIModule (113 B)
// PDB source: aimdmod.cpp lines 34-35
// Flags: config/flags/0040CDF0_MainDecisionAIModule.rsp (default + /GX)
// Notes: LEFT IN SCRATCH. EH-framed constructor with base constructor call in
// initializer list. Critical findings so far:
// - Base constructor uses ret 10h (cleans 4 params: string, 1000, param_2, param_1)
// - Derived constructor uses ret 0Ch (cleans 3 params)
// - MainDecisionAIModule has vtable write (virtual functions)
// - EH frame set up via /GX: mov eax,[fs:0]; push -1; push handler; push eax;
//   mov [fs:0],esp ... mov [fs:0],ecx
// - Pushes esi AND edi (3 preserved regs)
// - Blockers: initializer list with trivial base ctor body skips EH frame;
//   adding virtual dtor adds deleting destructor wrapper and shifts codegen basin;
//   need exact combination of base class virtual + non-trivial constructor.
// Tried: initializer list, explicit body call, extern function pointer, virtual
// destructor, inline base ctor body, separate base ctor def.

struct ManagedArray_Int {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    void* player;               // +0xF0
    ManagedArray_Int objects;   // +0xF4

    MainDecisionAIModule(void* param_1, int param_2, void* param_3);
};

MainDecisionAIModule::MainDecisionAIModule(void* param_1, int param_2, void* param_3)
{
    this->player = param_3;
    this->objects.value = 0;
    this->objects.numberValue = 0;
    this->objects.desiredNumberValue = 0;
    this->objects.maximumSizeValue = 0;
}
