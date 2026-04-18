class TribeHuntedAnimalUnitAIModule {
public:
    void parent_destroy();
    void destroy();
};

void TribeHuntedAnimalUnitAIModule::destroy() {
    this->parent_destroy();
}
