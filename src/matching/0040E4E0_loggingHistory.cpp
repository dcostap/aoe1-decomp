class AIModule {
public:
    virtual ~AIModule();
    char gap_04[148];
    int loggingHistory_;

    virtual int loggingHistory() const;
};
int AIModule::loggingHistory() const { return this->loggingHistory_; }
