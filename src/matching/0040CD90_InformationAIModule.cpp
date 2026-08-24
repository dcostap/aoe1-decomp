#ifndef AIINFMOD_SHARED_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
    AIModule(char* name, int id, int param1, void* param2);
};

class InformationAIModule : public AIModule {
public:
    InformationAIModule(void* param1, int param2);
};
#endif

InformationAIModule::InformationAIModule(void* param1, int param2)
    : AIModule("InfAI", 0x3ED, param2, param1)
{
}
