#ifndef AOE1_AIMDMOD_TU_CONTEXT_H
class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_0[0xF4];
    int field_F8;
    int numberObjects();
};
#endif

int MainDecisionAIModule::numberObjects() { return this->objects.numberValue; }
