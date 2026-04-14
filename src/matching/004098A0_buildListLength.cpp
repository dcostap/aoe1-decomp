class BuildAIModule {
public:
    virtual ~BuildAIModule();
    char gap_0[0x19C];
    int field_1A0;
    int buildListLength();
};

int BuildAIModule::buildListLength() { return this->field_1A0; }
