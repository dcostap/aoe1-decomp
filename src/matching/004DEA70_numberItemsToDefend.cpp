#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char gap_0[0x148];
    int field_14C;
    int numberItemsToDefend();
};
#endif

#endif
int TribeInformationAIModule::numberItemsToDefend() {
    return this->itemsToDefend.numberValue;
}
