class ConstructionAIModule {
public:
    virtual ~ConstructionAIModule();
    char gap_0[0x2FC];
    float field_300;
    float yReferencePoint();
};

float ConstructionAIModule::yReferencePoint() { return this->field_300; }
