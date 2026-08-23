#ifndef AICONMOD_CANONICAL_TU
class ConstructionAIModule {
public:
    virtual ~ConstructionAIModule();
    char gap_0[0x2F8];
    float xReferencePointValue;
    float xReferencePoint();
};
#endif

float ConstructionAIModule::xReferencePoint() {
    return this->xReferencePointValue;
}
