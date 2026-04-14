class AIModule {
public:
    virtual ~AIModule();
    char gap_04[152];
    int loggingCommonHistory_;

    virtual int loggingCommonHistory() const;
};
int AIModule::loggingCommonHistory() const { return this->loggingCommonHistory_; }
