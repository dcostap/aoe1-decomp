#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0x8C];
    int running_;

    void start();
};
#endif
#ifdef AOE1_AIMODULE_TU_CONTEXT
void AIModule::start() { this->runningValue = 1; }
#else
void AIModule::start() { this->running_ = 1; }
#endif
