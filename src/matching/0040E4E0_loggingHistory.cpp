#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
    char gap_04[148];
    int loggingHistory_;

    virtual int loggingHistory() const;
};
#endif
#ifdef AOE1_AIMODULE_TU_CONTEXT
int AIModule::loggingHistory() const { return this->logHistoryValue; }
#else
int AIModule::loggingHistory() const { return this->loggingHistory_; }
#endif
