class TradeAIModule {
public:
    virtual ~TradeAIModule();
    char gap_0[0xEC];
    int field_F0;
    void setMainDecisionAI(int v);
};

void TradeAIModule::setMainDecisionAI(int v) { this->field_F0 = v; }
