class ResearchAIModule {
public:
    virtual ~ResearchAIModule();
    char gap_0[0x148];
    char field_14C[1];
    char* technologyTreeName();
};

char* ResearchAIModule::technologyTreeName() { return this->field_14C; }
