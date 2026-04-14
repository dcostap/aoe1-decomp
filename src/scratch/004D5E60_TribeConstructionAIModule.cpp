class ConstructionAIModule {
public:
    virtual ~ConstructionAIModule();
    ConstructionAIModule(void* p1, int p2);
};

class TribeConstructionAIModule : public ConstructionAIModule {
public:
    char _pad[0x310];
    int mainDecisionAI;
    TribeConstructionAIModule(void* p1, int p2);
};

TribeConstructionAIModule::TribeConstructionAIModule(void* p1, int p2)
    : ConstructionAIModule(p1, p2), mainDecisionAI(0)
{
}
