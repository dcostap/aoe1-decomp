class TribeRangedUnitAIModule {
public:
    void parent_destroy();
    void destroy();
};

void TribeRangedUnitAIModule::destroy() {
    this->parent_destroy();
}
