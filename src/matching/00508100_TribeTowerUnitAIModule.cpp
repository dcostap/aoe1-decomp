class TribeTowerUnitAIModule {
public:
    void parent_destroy();
    void destroy();
};

void TribeTowerUnitAIModule::destroy() {
    this->parent_destroy();
}
