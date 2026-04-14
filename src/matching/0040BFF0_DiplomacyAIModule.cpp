class Base_DiplomacyAIModule {
public:
    virtual ~Base_DiplomacyAIModule();
};

class DiplomacyAIModule : public Base_DiplomacyAIModule {
public:
    virtual ~DiplomacyAIModule();
};

DiplomacyAIModule::~DiplomacyAIModule() {
}
