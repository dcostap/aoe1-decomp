class TribeCivilianUnitAIModule {
public:
    void parent_destroy();
    void destroy();
};

void TribeCivilianUnitAIModule::destroy() {
    this->parent_destroy();
}
