class AIModuleMessage;
class AIModule {
public:
    virtual void setCallbackMessage(AIModuleMessage *);
};
void AIModule::setCallbackMessage(AIModuleMessage *a) {}
