#ifndef TAIBLDMD_SHARED_CONTEXT
class BuildAIModule {
public:
    virtual ~BuildAIModule();
    BuildAIModule(int p1, int p2);
};

class TribeBuildAIModule : public BuildAIModule {
public:
    char _pad[0x5B8];
    void* md;
    TribeBuildAIModule(int p1, int p2);
};
#endif

TribeBuildAIModule::TribeBuildAIModule(int p1, int p2)
    : BuildAIModule(p1, p2), md(0)
{
}
