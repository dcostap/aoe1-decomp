#ifndef AOE1_AIMDMOD_TU_CONTEXT_H
class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    int canPerformAction(int p0, int p1);
};
#endif

int MainDecisionAIModule::canPerformAction(int p0, int p1) { return 0; }
