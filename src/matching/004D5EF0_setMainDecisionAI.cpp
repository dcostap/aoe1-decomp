class TribeConstructionAIModule {
public:
    virtual ~TribeConstructionAIModule();
    char gap_0[0x310];
    int field_314;
    void setMainDecisionAI(int v);
};

void TribeConstructionAIModule::setMainDecisionAI(int v) { this->field_314 = v; }
