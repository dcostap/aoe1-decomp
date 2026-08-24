#ifndef AOE1_AIEMOMOD_TU_CONTEXT
class MainDecisionAIModule;
class EmotionalAIModule {
public:
    virtual ~EmotionalAIModule();
    char gap_0[0xEC];
    MainDecisionAIModule* md;
    void setMainDecisionAI(MainDecisionAIModule* v);
};
#endif

void EmotionalAIModule::setMainDecisionAI(MainDecisionAIModule* v) { this->md = v; }
