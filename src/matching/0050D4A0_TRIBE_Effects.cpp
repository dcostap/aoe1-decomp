class TRIBE_Effects {
public:
    void parent_destroy();
    void destroy();
};

void TRIBE_Effects::destroy() {
    this->parent_destroy();
}
