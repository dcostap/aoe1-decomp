#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeMainDecisionAIModule;
#endif

#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char gap_0[0xFC];
    int field_100;
    void setMainDecisionAI(TribeMainDecisionAIModule* v);
};
#endif

#endif
void TribeInformationAIModule::setMainDecisionAI(TribeMainDecisionAIModule* v) {
    this->field_100 = (int)v;
}
