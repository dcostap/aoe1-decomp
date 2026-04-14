class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0x4C];
    char playerName_[1];

    char * playerName();
};
char * AIModule::playerName() { return this->playerName_; }
