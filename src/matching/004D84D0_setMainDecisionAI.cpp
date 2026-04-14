class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char gap_0[0xFC];
    int field_100;
    void setMainDecisionAI(int v);
};

void TribeInformationAIModule::setMainDecisionAI(int v) { this->field_100 = v; }
