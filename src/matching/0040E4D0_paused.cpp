class AIModule {
public:
    virtual ~AIModule();
    char gap_04[144];
    int paused_;

    int paused() const;
};
int AIModule::paused() const { return this->paused_; }
