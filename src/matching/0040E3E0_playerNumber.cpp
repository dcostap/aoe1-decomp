#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0x48];
    int playerNumber_;

    int playerNumber() const;
};
#endif
#ifdef AOE1_AIMODULE_TU_CONTEXT
int AIModule::playerNumber() const { return this->playerNumberValue; }
#else
int AIModule::playerNumber() const { return this->playerNumber_; }
#endif
