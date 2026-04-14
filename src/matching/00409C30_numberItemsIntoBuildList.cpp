class BuildAIModule {
public:
    virtual ~BuildAIModule();
    char gap_0[0x5A4];
    int field_5A8;
    int numberItemsIntoBuildList();
};

int BuildAIModule::numberItemsIntoBuildList() { return this->field_5A8; }
