#ifndef AITRDMOD_CONTEXT_H
class MainDecisionAIModule;
class AIModule {
public:
    virtual ~AIModule();
    AIModule(char* name, int id, int param1, void* param2);
};

class TradeAIModule : public AIModule {
public:
    char _pad[0xEC];
    MainDecisionAIModule* md;
    TradeAIModule(int param1, int param2);
};
#endif

TradeAIModule::TradeAIModule(int param1, int param2)
    : AIModule("Trade AI", 0x3F2, param1, 0), md(0)
{
}
