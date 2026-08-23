#ifndef AICONMOD_CANONICAL_TU
class ConstructionAIModule {
public:
    virtual ~ConstructionAIModule();
    char gap_0[0x2FC];
    float yReferencePointValue;
    float yReferencePoint();
};
#endif

float ConstructionAIModule::yReferencePoint() {
    return this->yReferencePointValue;
}
