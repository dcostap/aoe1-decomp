class AIModule {
public:
    virtual ~AIModule();
    AIModule(char* name, int id, int param1, void* param2);
};

class TacticalAIModule : public AIModule {
public:
    TacticalAIModule(void* param1, int param2);
};

TacticalAIModule::TacticalAIModule(void* param1, int param2)
    : AIModule("TacAI", 0x3F1, param2, param1)
{
}
