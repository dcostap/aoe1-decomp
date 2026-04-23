class MainDecisionAIModule {
public:
    virtual int objectGroupThatCanPerformAction(int action);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    int objectGroupThatCanPerformAction(int action);
};

int TribeMainDecisionAIModule::objectGroupThatCanPerformAction(int action) {
    switch (action) {
    case 0x25a:
    case 0x25d:
    case 0x261:
    case 0x265:
        return 4;
    case 0x26b:
    case 0x26c:
        return 3;
    default:
        return MainDecisionAIModule::objectGroupThatCanPerformAction(action);
    }
}
