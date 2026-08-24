#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0x4C];
    char playerName_[1];

    char * playerName();
};
#endif
#ifdef AOE1_AIMODULE_TU_CONTEXT
char* AIModule::playerName() { return this->playerNameValue; }
#else
char * AIModule::playerName() { return this->playerName_; }
#endif
