class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0x8C];
    int running_;

    void start();
};
void AIModule::start() { this->running_ = 1; }
