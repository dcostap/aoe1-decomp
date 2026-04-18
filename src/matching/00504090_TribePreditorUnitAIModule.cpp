class TribePreditorUnitAIModule {
public:
    void parent_destroy();
    void destroy();
};

void TribePreditorUnitAIModule::destroy() {
    this->parent_destroy();
}
