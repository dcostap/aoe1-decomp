class Base_TribeBuildAIModule {
public:
    virtual ~Base_TribeBuildAIModule();
};

class TribeBuildAIModule : public Base_TribeBuildAIModule {
public:
    virtual ~TribeBuildAIModule();
};

TribeBuildAIModule::~TribeBuildAIModule() {
}
