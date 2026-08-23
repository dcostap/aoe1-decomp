#ifndef TAIBLDMD_SHARED_CONTEXT
class BuildAIModule {
public:
    virtual ~BuildAIModule();
    BuildAIModule(void* p1, int p2);
};

class TribeBuildAIModule : public BuildAIModule {
public:
    char _pad[0x5B8];
    void* md;
    TribeBuildAIModule(void* p1, int p2);
};
#endif

TribeBuildAIModule::TribeBuildAIModule(void* p1, int p2)
    : BuildAIModule(p1, p2), md(0)
{
}
