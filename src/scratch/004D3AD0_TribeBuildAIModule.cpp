class BuildAIModule {
public:
    virtual ~BuildAIModule();
    BuildAIModule(int p1, int p2);
};

class TribeBuildAIModule : public BuildAIModule {
public:
    char _pad[0x5B8];
    int mainDecisionAI;
    TribeBuildAIModule(int p1, int p2);
};

TribeBuildAIModule::TribeBuildAIModule(int p1, int p2)
    : BuildAIModule(p1, p2), mainDecisionAI(0)
{
}
