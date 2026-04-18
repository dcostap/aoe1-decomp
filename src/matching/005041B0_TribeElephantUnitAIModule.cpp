class TribeElephantUnitAIModule {
public:
    void parent_destroy();
    void destroy();
};

void TribeElephantUnitAIModule::destroy() {
    this->parent_destroy();
}
