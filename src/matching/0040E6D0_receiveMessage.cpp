#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModuleMessage;
class AIModule {
public:
    void receiveMessage(AIModuleMessage *);
};
#endif
void AIModule::receiveMessage(AIModuleMessage *a) {}
