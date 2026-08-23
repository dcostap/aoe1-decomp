#ifndef TAITACMD_SHARED_CONTEXT
class TribeMainDecisionAIModule;
class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[0xEC];
    TribeMainDecisionAIModule* md;

    void setMainDecisionAI(TribeMainDecisionAIModule*);
};
#endif
void TribeTacticalAIModule::setMainDecisionAI(TribeMainDecisionAIModule* val) { this->md = val; }
