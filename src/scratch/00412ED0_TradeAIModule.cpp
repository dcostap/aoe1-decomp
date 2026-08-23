class Base_TradeAIModule {
public:
    virtual ~Base_TradeAIModule();
};

class TradeAIModule : public Base_TradeAIModule {
public:
    virtual ~TradeAIModule();
};

TradeAIModule::~TradeAIModule() {
}
