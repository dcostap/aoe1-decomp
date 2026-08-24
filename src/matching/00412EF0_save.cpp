#ifndef AITRDMOD_CONTEXT_H
class TradeAIModule {
public:
    virtual ~TradeAIModule();
    int save(int p0);
};
#endif

int TradeAIModule::save(int p0) { return 1; }
