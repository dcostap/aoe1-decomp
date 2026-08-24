#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
    char gap_04[228];
    int priority_;

    int priority() const;
};
#endif
#ifdef AOE1_AIMODULE_TU_CONTEXT
int AIModule::priority() const { return this->priorityValue; }
#else
int AIModule::priority() const { return this->priority_; }
#endif
