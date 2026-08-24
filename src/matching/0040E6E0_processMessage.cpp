#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModuleMessage;
class AIModule {
public:
    virtual int processMessage(AIModuleMessage *);
};
#endif
int AIModule::processMessage(AIModuleMessage *a) { return 0; }
