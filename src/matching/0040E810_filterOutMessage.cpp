class AIModuleMessage;
class AIModule {
protected:
    virtual int filterOutMessage(AIModuleMessage *);
};
int AIModule::filterOutMessage(AIModuleMessage *a) { return 0; }
