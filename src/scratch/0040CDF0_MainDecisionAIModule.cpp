// attempt 4: MainDecisionAIModule constructor, 113 bytes
// attempt 1: 112 vs 113, off by 1 - base ctor __thiscall ret 0C shifts stack by 12
// attempt 2: 80 vs 113, C helper made it worse
// attempt 3: 112 vs 113, back to attempt 1
// attempt 4: 112 vs 113, off by 1, can't extract rebuilt for comparison
// BLOCKED: 1-byte codegen drift, likely in EH prologue order or one instruction difference
// attempt 1: 112 vs 113, off by 1 - base ctor __thiscall ret 0C shifts stack by 12
// attempt 2: 80 vs 113, C helper made it worse

struct ManagedArray_Int {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class AIModule {
public:
    void* vftable;
    char pad[0xEC];

    AIModule(const char* name, int intelligence, int param_2, void* param_1);
    AIModule();
};

struct RGE_Player;

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
    ManagedArray_Int objects;

    MainDecisionAIModule(void* param_1, int param_2, RGE_Player* param_3);
};

MainDecisionAIModule::MainDecisionAIModule(void* param_1, int param_2, RGE_Player* param_3) {
    AIModule::AIModule("Main Decision AI", 1000, param_2, param_1);
    this->player = param_3;
    this->objects.value = 0;
    this->objects.numberValue = 0;
    this->objects.desiredNumberValue = 0;
    this->objects.maximumSizeValue = 0;
}
