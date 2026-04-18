class TRIBE_Diamond_Map_View {
public:
    void parent_destroy();
    void destroy();
};

void TRIBE_Diamond_Map_View::destroy() {
    this->parent_destroy();
}
