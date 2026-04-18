class TribeRangedUnitAIModule2 {
public:
    void parent_destroy();
    void destroy();
};

void TribeRangedUnitAIModule2::destroy() {
    this->parent_destroy();
}
