class AIModule {
public:
    virtual ~AIModule();
    char gap_04[140];
    int running_;

    int running() const;
};
int AIModule::running() const { return this->running_; }
