#ifndef TAICONMD_SHARED_CONTEXT
class ConstructionAIModule {
public:
    virtual ~ConstructionAIModule();
    ConstructionAIModule(int p1, int p2);
};

class TribeConstructionAIModule : public ConstructionAIModule {
public:
    char _pad[0x310];
    int mainDecisionAI;
    TribeConstructionAIModule(int p1, int p2);
};
#endif

TribeConstructionAIModule::TribeConstructionAIModule(int p1, int p2)
    : ConstructionAIModule(p1, p2), mainDecisionAI(0)
{
}
