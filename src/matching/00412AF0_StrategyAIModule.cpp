#ifndef AISTRMOD_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
    AIModule(char* name, int id, int param1, void* param2);
};

class StrategyAIModule : public AIModule {
public:
    StrategyAIModule(void* param1, int param2);
};
#endif

StrategyAIModule::StrategyAIModule(void* param1, int param2)
    : AIModule("Strategy AI", 0x3F0, param2, param1)
{
}
