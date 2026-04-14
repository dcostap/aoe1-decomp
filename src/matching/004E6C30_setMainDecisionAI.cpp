class TribeResourceAIModule {
public:
    virtual ~TribeResourceAIModule();
    char gap_0[0xEC];
    int field_F0;
    void setMainDecisionAI(int v);
};

void TribeResourceAIModule::setMainDecisionAI(int v) { this->field_F0 = v; }
