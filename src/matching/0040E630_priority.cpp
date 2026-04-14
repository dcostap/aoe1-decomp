class AIModule {
public:
    virtual ~AIModule();
    char gap_04[228];
    int priority_;

    int priority() const;
};
int AIModule::priority() const { return this->priority_; }
