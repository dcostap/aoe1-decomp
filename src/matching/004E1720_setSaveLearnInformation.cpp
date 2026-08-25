#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char gap_0[0x200];
    int field_204;
    void setSaveLearnInformation(int v);
};
#endif

#endif
void TribeInformationAIModule::setSaveLearnInformation(int v) { this->field_204 = v; }
