#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
    char gap_04[224];
    int intelligenceLevel_;

    int setIntelligenceLevel(int param_1);
};
#endif

int AIModule::setIntelligenceLevel(int param_1) {
#ifdef AOE1_AIMODULE_TU_CONTEXT
    this->intelligenceLevelValue = param_1;
    if (param_1 < 1) {
        this->intelligenceLevelValue = 1;
        return 0;
    }
    if (param_1 > 10) {
        this->intelligenceLevelValue = 10;
        return 0;
    }
    return 1;
#else
    this->intelligenceLevel_ = param_1;
    if (param_1 < 1) {
        this->intelligenceLevel_ = 1;
        return 0;
    }
    if (param_1 > 10) {
        this->intelligenceLevel_ = 10;
        return 0;
    }
    return 1;
#endif
}
