#ifndef TAICONMD_SHARED_CONTEXT
class TribeMainDecisionAIModule;
class TribeConstructionAIModule {
public:
    virtual ~TribeConstructionAIModule();
    char gap_0[0x310];
    TribeMainDecisionAIModule* md;
    void setMainDecisionAI(TribeMainDecisionAIModule* v);
};
#endif

void TribeConstructionAIModule::setMainDecisionAI(TribeMainDecisionAIModule* v) { this->md = v; }
