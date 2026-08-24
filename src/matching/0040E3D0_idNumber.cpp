#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
    char gap_04[4];
    int idNumber_;

    int idNumber() const;
};
#endif
#ifdef AOE1_AIMODULE_TU_CONTEXT
int AIModule::idNumber() const { return this->idValue.id; }
#else
int AIModule::idNumber() const { return this->idNumber_; }
#endif
