class AIModule {
public:
    virtual ~AIModule();
    AIModule(char* name, int id, int param1, void* param2);
};

class TradeAIModule : public AIModule {
public:
    char _pad[0xEC];
    int fieldF0;
    TradeAIModule(int param1, int param2);
};

TradeAIModule::TradeAIModule(int param1, int param2)
    : AIModule("TradeAI", 0x3F2, param1, 0), fieldF0(0)
{
}
