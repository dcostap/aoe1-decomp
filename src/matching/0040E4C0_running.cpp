#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
    char gap_04[140];
    int running_;

    int running() const;
};
#endif
#ifdef AOE1_AIMODULE_TU_CONTEXT
int AIModule::running() const { return this->runningValue; }
#else
int AIModule::running() const { return this->running_; }
#endif
