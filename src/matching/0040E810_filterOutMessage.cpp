#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModuleMessage;
class AIModule {
protected:
    virtual int filterOutMessage(AIModuleMessage *);
};
#endif
int AIModule::filterOutMessage(AIModuleMessage *a) { return 0; }
