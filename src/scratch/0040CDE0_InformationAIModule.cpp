#ifndef AIINFMOD_SHARED_CONTEXT
class Base_InformationAIModule {
public:
    virtual ~Base_InformationAIModule();
};

class InformationAIModule : public Base_InformationAIModule {
public:
    virtual ~InformationAIModule();
};
#endif

InformationAIModule::~InformationAIModule() {
}
