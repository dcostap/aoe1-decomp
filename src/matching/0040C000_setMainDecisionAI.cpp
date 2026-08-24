class MainDecisionAIModule;

#ifndef AOE1_AIDIPMOD_TU_CONTEXT
class DiplomacyAIModule {
public:
    virtual ~DiplomacyAIModule();
    char gap_0[0xEC];
    MainDecisionAIModule* md;
    void setMainDecisionAI(MainDecisionAIModule* v);
};
#endif

void DiplomacyAIModule::setMainDecisionAI(MainDecisionAIModule* v) { this->md = v; }
