class AIModule {
public:
    char gap_00[0xEC];
    int processFrameValue;

    void incrementProcessFrame();
};

void AIModule::incrementProcessFrame() {
    int frame;

    frame = this->processFrameValue + 1;
    this->processFrameValue = frame;
    if (frame == 0x7FFFFFFF) {
        this->processFrameValue = 0;
    }
}
