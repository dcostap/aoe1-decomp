class AIModuleMessage;

class AIModule {
public:
    virtual int filterOutMessage(AIModuleMessage *);
};

class ResourceAIModule : public AIModule {
public:
    virtual int filterOutMessage(AIModuleMessage *message);
};

int ResourceAIModule::filterOutMessage(AIModuleMessage *message) {
    return AIModule::filterOutMessage(message);
}
