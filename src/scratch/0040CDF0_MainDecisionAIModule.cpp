// VA: 0040CDF0 MainDecisionAIModule::MainDecisionAIModule (113 B)
// PDB source: aimdmod.cpp lines 34-35
// FLAGS: /GX
//
// Status: STUCK — same VC5 EH prologue family mismatch as ~MainDecisionAIModule (0040D020).
//
// Original uses FS-first SEH prologue (`mov eax,[fs:0]` before `push -1`) with
// interleaved parameter load before `mov [fs:0],esp`. Our VC5 uses push-first
// prologue with extra saved-this slot. Same root cause as the sibling destructor.
// No accepted_drift: 75% positional diff, broad prologue/frame mismatch.

struct ManagedArray_Int {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class RGE_Player {};

class AIModule {
public:
    char gap_04[0xEC];
    AIModule(char* name, int id, int player_number, void* owner);
    virtual ~AIModule();
};

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
    ManagedArray_Int objects;

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
