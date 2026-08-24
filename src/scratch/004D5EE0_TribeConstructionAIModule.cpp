#ifndef TAICONMD_SHARED_CONTEXT
class Base_TribeConstructionAIModule {
public:
    virtual ~Base_TribeConstructionAIModule();
};

class TribeConstructionAIModule : public Base_TribeConstructionAIModule {
public:
    virtual ~TribeConstructionAIModule();
};
#endif

TribeConstructionAIModule::~TribeConstructionAIModule() {
}
