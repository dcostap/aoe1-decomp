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

DiplomacyAIModule::~DiplomacyAIModule() {
}
