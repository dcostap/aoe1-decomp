class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char gap_0[0x200];
    int field_204;
    void setSaveLearnInformation(int v);
};

void TribeInformationAIModule::setSaveLearnInformation(int v) { this->field_204 = v; }
