class AIModule {
public:
    virtual ~AIModule();
    char gap_04[4];
    int idNumber_;

    int idNumber() const;
};
int AIModule::idNumber() const { return this->idNumber_; }
