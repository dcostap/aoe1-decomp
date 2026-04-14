class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0x8C];
    int running_;

    void stop();
};
void AIModule::stop() { this->running_ = 0; }
