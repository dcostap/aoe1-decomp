class TribeBuildAIModule {
public:
    virtual ~TribeBuildAIModule();
    char gap_0[0x5B8];
    int field_5BC;
    void setMainDecisionAI(int v);
};

void TribeBuildAIModule::setMainDecisionAI(int v) { this->field_5BC = v; }
