class DiplomacyAIModule {
public:
    virtual ~DiplomacyAIModule();
    char gap_0[0xEC];
    int field_F0;
    void setMainDecisionAI(int v);
};

void DiplomacyAIModule::setMainDecisionAI(int v) { this->field_F0 = v; }
