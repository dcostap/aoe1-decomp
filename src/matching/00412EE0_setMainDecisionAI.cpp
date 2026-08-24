#ifndef AITRDMOD_CONTEXT_H
class MainDecisionAIModule;
class TradeAIModule {
public:
    virtual ~TradeAIModule();
    char gap_0[0xEC];
    MainDecisionAIModule* md;
    void setMainDecisionAI(MainDecisionAIModule* v);
};
#endif

void TradeAIModule::setMainDecisionAI(MainDecisionAIModule* v) { this->md = v; }
