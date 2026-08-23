#ifndef TAIBLDMD_SHARED_CONTEXT
class TribeMainDecisionAIModule;
class TribeBuildAIModule {
public:
    virtual ~TribeBuildAIModule();
    char gap_0[0x5B8];
    TribeMainDecisionAIModule* md;
    void setMainDecisionAI(TribeMainDecisionAIModule* value);
};
#endif

void TribeBuildAIModule::setMainDecisionAI(TribeMainDecisionAIModule* value)
{
    this->md = value;
}
