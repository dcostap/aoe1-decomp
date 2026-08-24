#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    char gap_00[0xEC];
    int processFrameValue;

    void incrementProcessFrame();
};
#endif

void AIModule::incrementProcessFrame() {
    int frame;

    frame = this->processFrameValue + 1;
    this->processFrameValue = frame;
    if (frame == 0x7FFFFFFF) {
        this->processFrameValue = 0;
    }
}
