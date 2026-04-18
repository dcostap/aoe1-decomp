class TribePriestUnitAIModule {
public:
    void parent_destroy();
    void destroy();
};

void TribePriestUnitAIModule::destroy() {
    this->parent_destroy();
}
