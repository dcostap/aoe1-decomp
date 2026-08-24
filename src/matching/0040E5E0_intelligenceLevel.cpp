#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
    char gap_04[224];
    int intelligenceLevel_;

    int intelligenceLevel() const;
};
#endif
#ifdef AOE1_AIMODULE_TU_CONTEXT
int AIModule::intelligenceLevel() const { return this->intelligenceLevelValue; }
#else
int AIModule::intelligenceLevel() const { return this->intelligenceLevel_; }
#endif
