class ResearchAIModule {
public:
    virtual ~ResearchAIModule();
    char gap_0[0xEC];
    int field_F0;
    void setMainDecisionAI(int v);
};

void ResearchAIModule::setMainDecisionAI(int v) { this->field_F0 = v; }
