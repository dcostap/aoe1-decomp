#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xE8];
    int processFrame_;
protected:
    int processFrame();
};
#endif
#ifdef AOE1_AIMODULE_TU_CONTEXT
int AIModule::processFrame() { return this->processFrameValue; }
#else
int AIModule::processFrame() { return this->processFrame_; }
#endif
