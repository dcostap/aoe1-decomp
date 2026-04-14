class ConstructionAIModule {
public:
    virtual ~ConstructionAIModule();
    char gap_0[0x1F4];
    char field_1F8[1];
    char* constructionPlanName();
};

char* ConstructionAIModule::constructionPlanName() { return this->field_1F8; }
