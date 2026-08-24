#ifndef AOE1_AIDIPMOD_TU_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class DiplomacyAIModule : public AIModule {
public:
    virtual ~DiplomacyAIModule();
};
#endif

// BINARY NOTE: The destructor stores the DiplomacyAIModule vtable, then tail-jumps to AIModule::~AIModule.
// Grouped validation: aidipmod.cpp emits MATCH for 0040BFF0 and generated 0040BF20.
DiplomacyAIModule::~DiplomacyAIModule() {
}
