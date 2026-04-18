class TribeSoldierUnitAIModule {
public:
    void parent_destroy();
    void destroy();
};

void TribeSoldierUnitAIModule::destroy() {
    this->parent_destroy();
}
