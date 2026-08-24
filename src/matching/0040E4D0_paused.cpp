#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
    char gap_04[144];
    int paused_;

    int paused() const;
};
#endif
#ifdef AOE1_AIMODULE_TU_CONTEXT
int AIModule::paused() const { return this->pausedValue; }
#else
int AIModule::paused() const { return this->paused_; }
#endif
