class TribeBuildingUnitAIModule {
public:
    void parent_destroy();
    void destroy();
};

void TribeBuildingUnitAIModule::destroy() {
    this->parent_destroy();
}
