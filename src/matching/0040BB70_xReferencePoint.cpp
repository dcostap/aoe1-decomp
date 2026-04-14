class ConstructionAIModule {
public:
    virtual ~ConstructionAIModule();
    char gap_0[0x2F8];
    float field_2FC;
    float xReferencePoint();
};

float ConstructionAIModule::xReferencePoint() { return this->field_2FC; }
