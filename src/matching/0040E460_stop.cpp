#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0x8C];
    int running_;

    void stop();
};
#endif
#ifdef AOE1_AIMODULE_TU_CONTEXT
void AIModule::stop() { this->runningValue = 0; }
#else
void AIModule::stop() { this->running_ = 0; }
#endif
