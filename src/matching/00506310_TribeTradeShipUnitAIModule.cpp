class TribeTradeShipUnitAIModule {
public:
    void parent_destroy();
    void destroy();
};

void TribeTradeShipUnitAIModule::destroy() {
    this->parent_destroy();
}
