// attempt 3: ~MainDecisionAIModule, 112 bytes
// attempt 1: extra push ecx, stub call before base dtor, EH order wrong
// attempt 2: 64 vs 112, no EH frame with C helper
// attempt 3: 112=112 size match but mismatch at byte 0 (EH prologue order differs)
// BLOCKED: VC5 EH prologue order differs; original does mov eax,[fs:0] first, rebuilt pushes first
// attempt 1: extra push ecx, stub call before base dtor
// attempt 2: 64 vs 112, no EH frame with C helper
// tried: adding virtual dtor to base to force vtable reset

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

    virtual ~AIModule();
};

class MainDecisionAIModule : public AIModule {
public:
    int* player;
    ManagedArray_Int objects;

    virtual ~MainDecisionAIModule();
};

void operator_delete(void* ptr);

MainDecisionAIModule::~MainDecisionAIModule() {
    if (this->objects.value != 0) {
        operator_delete(this->objects.value);
        this->objects.value = 0;
    }
    this->objects.numberValue = 0;
    this->objects.desiredNumberValue = 0;
    this->objects.maximumSizeValue = 0;
}
