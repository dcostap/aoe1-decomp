class AIModule {
public:
    virtual ~AIModule();
    void logCommonHistory(char* format, ...);
};

class MainDecisionAIModule : public AIModule {
public:
    virtual int objectGroupThatCanPerformAction(int action);
};

int MainDecisionAIModule::objectGroupThatCanPerformAction(int action) {
    this->logCommonHistory("ERROR!  %d is an unrecognized action id.", action);
    return -1;
}
