class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[0xEC];
    int mainDecisionAI_;

    void setMainDecisionAI(int);
};
void TribeTacticalAIModule::setMainDecisionAI(int val) { this->mainDecisionAI_ = val; }
