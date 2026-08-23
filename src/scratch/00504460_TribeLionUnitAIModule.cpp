class TribeLionUnitAIModule {
public:
    void parent_destroy();
    void destroy();
};

void TribeLionUnitAIModule::destroy() {
    this->parent_destroy();
}
