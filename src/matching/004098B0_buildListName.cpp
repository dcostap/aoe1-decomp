class BuildAIModule {
public:
    virtual ~BuildAIModule();
    char gap_0[0x1A0];
    char field_1A4[1];
    char* buildListName();
};

char* BuildAIModule::buildListName() { return this->field_1A4; }
