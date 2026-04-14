class Base_TacticalAIModule {
public:
    virtual ~Base_TacticalAIModule();
};

class TacticalAIModule : public Base_TacticalAIModule {
public:
    virtual ~TacticalAIModule();
};

TacticalAIModule::~TacticalAIModule() {
}
