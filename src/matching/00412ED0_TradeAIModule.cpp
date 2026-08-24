#ifndef AITRDMOD_CONTEXT_H
class AIModule {
public:
    virtual ~AIModule();
};

class TradeAIModule : public AIModule {
public:
    virtual ~TradeAIModule();
};
#endif

TradeAIModule::~TradeAIModule() {
}
