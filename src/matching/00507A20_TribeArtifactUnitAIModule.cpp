class TribeArtifactUnitAIModule {
public:
    void parent_destroy();
    void destroy();
};

void TribeArtifactUnitAIModule::destroy() {
    this->parent_destroy();
}
