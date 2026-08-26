#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0x4C];
    char playerName_[1];

    char * playerName() const;
};
#endif
#ifdef AOE1_AIMODULE_TU_CONTEXT
char* AIModule::playerName() const { return (char*)this->playerNameValue; }
#else
char * AIModule::playerName() const { return (char*)this->playerName_; }
#endif
