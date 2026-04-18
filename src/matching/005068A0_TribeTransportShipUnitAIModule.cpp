class TribeTransportShipUnitAIModule {
public:
    void parent_destroy();
    void destroy();
};

void TribeTransportShipUnitAIModule::destroy() {
    this->parent_destroy();
}
