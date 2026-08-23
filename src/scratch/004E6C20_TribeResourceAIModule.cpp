class Base_TribeResourceAIModule {
public:
    virtual ~Base_TribeResourceAIModule();
};

class TribeResourceAIModule : public Base_TribeResourceAIModule {
public:
    virtual ~TribeResourceAIModule();
};

TribeResourceAIModule::~TribeResourceAIModule() {
}
