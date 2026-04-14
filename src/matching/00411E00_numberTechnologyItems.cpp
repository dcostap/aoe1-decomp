class ResearchAIModule {
public:
    virtual ~ResearchAIModule();
    char gap_0[0x144];
    int field_148;
    int numberTechnologyItems();
};

int ResearchAIModule::numberTechnologyItems() { return this->field_148; }
