#ifndef AITRDMOD_CONTEXT_H
class AIModule {
public:
    virtual ~AIModule();
    AIModule(char* name, int id, int player, void* ptr);
};

class TradeAIModule : public AIModule {
public:
    char gap_04[0xEC];
    int md;

    TradeAIModule(void* ptr, int player);
};
#endif

TradeAIModule::TradeAIModule(void* ptr, int player)
    : AIModule("Trade AI", 0x3F2, player, ptr), md(0) {
}
