#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModuleMessage;
class AIModule {
public:
    virtual void setCallbackMessage(AIModuleMessage *);
};
#endif
void AIModule::setCallbackMessage(AIModuleMessage *a) {}
