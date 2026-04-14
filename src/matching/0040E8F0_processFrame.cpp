class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xE8];
    int processFrame_;
protected:
    int processFrame();
};
int AIModule::processFrame() { return this->processFrame_; }
