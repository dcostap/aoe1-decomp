#ifndef TAIBLDMD_SHARED_CONTEXT
class BuildAIModule {
public:
    virtual ~BuildAIModule();
};

class TribeBuildAIModule : public BuildAIModule {
public:
    virtual ~TribeBuildAIModule();
};
#endif

TribeBuildAIModule::~TribeBuildAIModule() {
}
