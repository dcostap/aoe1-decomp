class AIModuleMessage;
class AIModule {
public:
    virtual int processMessage(AIModuleMessage *);
};
int AIModule::processMessage(AIModuleMessage *a) { return 0; }
