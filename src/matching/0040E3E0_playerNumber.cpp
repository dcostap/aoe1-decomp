class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0x48];
    int playerNumber_;

    int playerNumber() const;
};
int AIModule::playerNumber() const { return this->playerNumber_; }
