class TribeFishingShipUnitAIModule {
public:
    void parent_destroy();
    void destroy();
};

void TribeFishingShipUnitAIModule::destroy() {
    this->parent_destroy();
}
