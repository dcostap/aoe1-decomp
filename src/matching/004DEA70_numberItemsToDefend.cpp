class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char gap_0[0x148];
    int field_14C;
    int numberItemsToDefend();
};

int TribeInformationAIModule::numberItemsToDefend() { return this->field_14C; }
