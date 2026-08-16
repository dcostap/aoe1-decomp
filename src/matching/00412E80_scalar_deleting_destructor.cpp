class TradeAIModule {
public:
    ~TradeAIModule();
    void *scalar_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

void *TradeAIModule::scalar_deleting_destructor(unsigned int param_1) {
    this->~TradeAIModule();
    if ((param_1 & 1) != 0) {
        operator_delete(this);
    }
    return this;
}
