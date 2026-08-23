#ifndef AICONMOD_CANONICAL_TU
class ConstructionAIModule {
public:
    virtual ~ConstructionAIModule();
    char gap_0[0x1F4];
    char constructionPlanNameValue[0x101];
    char* constructionPlanName();
};
#endif

char* ConstructionAIModule::constructionPlanName() {
    return this->constructionPlanNameValue;
}
