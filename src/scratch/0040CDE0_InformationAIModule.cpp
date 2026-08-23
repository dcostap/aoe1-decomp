class Base_InformationAIModule {
public:
    virtual ~Base_InformationAIModule();
};

class InformationAIModule : public Base_InformationAIModule {
public:
    virtual ~InformationAIModule();
};

InformationAIModule::~InformationAIModule() {
}
