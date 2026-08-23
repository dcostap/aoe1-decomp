class Base_StrategyAIModule {
public:
    virtual ~Base_StrategyAIModule();
};

class StrategyAIModule : public Base_StrategyAIModule {
public:
    virtual ~StrategyAIModule();
};

StrategyAIModule::~StrategyAIModule() {
}
