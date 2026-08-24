#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
    char gap_04[152];
    int loggingCommonHistory_;

    virtual int loggingCommonHistory() const;
};
#endif
#ifdef AOE1_AIMODULE_TU_CONTEXT
int AIModule::loggingCommonHistory() const { return this->logCommonHistoryValue; }
#else
int AIModule::loggingCommonHistory() const { return this->loggingCommonHistory_; }
#endif
